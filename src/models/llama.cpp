// ============================================================================
// 文件: llama.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/src/models/llama.cpp
// 描述: Llama 模型计算图构建实现
// 作用: 实现了 Llama 模型的计算图构建，包括注意力层、前馈网络等核心组件
// ============================================================================

#include "models.h"

// 模板类: llm_build_llama
// 描述: Llama 模型计算图构建类
// 参数: embed - 是否仅构建嵌入部分
// 构造函数: 构建 Llama 模型的计算图
// 参数:
//   - model: Llama 模型实例
//   - params: 计算图参数
// 作用: 构建 Llama 模型的完整计算图，包括嵌入层、注意力层、前馈网络等

// 构造函数实现
template <bool embed>
llm_build_llama<embed>::llm_build_llama(const llama_model & model, const llm_graph_params & params) : llm_graph_context(params) {
    // 获取每个头的嵌入维度
    const int64_t n_embd_head = hparams.n_embd_head_v;

    // 断言验证：确保头维度一致
    GGML_ASSERT(n_embd_head == hparams.n_embd_head_k);
    GGML_ASSERT(n_embd_head == hparams.n_rot);

    // 定义张量指针
    ggml_tensor * cur;     // 当前张量
    ggml_tensor * inpL;     // 层输入张量

    // 构建词嵌入输入
    inpL = build_inp_embd(model.tok_embd);

    // 构建位置嵌入输入
    ggml_tensor * inp_pos = build_inp_pos();

    // 根据模板参数选择注意力输入类型
    using inp_attn_type = std::conditional_t<embed, llm_graph_input_attn_no_cache, llm_graph_input_attn_kv>;

    inp_attn_type * inp_attn = nullptr;
    
    // 根据模板参数构建注意力输入
    if constexpr (embed) {
        // 仅嵌入模式：构建无缓存的注意力输入
        inp_attn = build_attn_inp_no_cache();
    } else {
        // 完整模式：构建带 KV 缓存的注意力输入
        inp_attn = build_attn_inp_kv();
    }

    // 计算 QK 缩放因子
    const float kq_scale = hparams.f_attention_scale == 0.0f ? 1.0f/sqrtf(float(n_embd_head)) : hparams.f_attention_scale;

    // 构建输出 ID 输入
    ggml_tensor * inp_out_ids = build_inp_out_ids();

    // 遍历每一层
    for (int il = 0; il < n_layer; ++il) {
        // 保存当前层的输入，用于残差连接
        ggml_tensor * inpSA = inpL;

        // 注意力层归一化
        cur = build_norm(inpL,
                model.layers[il].attn_norm, NULL,
                LLM_NORM_RMS, il);
        cb(cur, "attn_norm", il);

        // 自注意力机制
        {
            // 获取 Llama 3 的 RoPE 频率因子；对于 Llama 2 和其他模型可能返回 nullptr
            ggml_tensor * rope_factors = model.get_rope_factors(cparams, il);

            // 计算 Q、K、V 并应用 RoPE
            ggml_tensor * Qcur = build_lora_mm(model.layers[il].wq, cur); // 查询（Query）
            cb(Qcur, "Qcur", il);
            if (model.layers[il].bq) {
                Qcur = ggml_add(ctx0, Qcur, model.layers[il].bq); // 添加偏置
                cb(Qcur, "Qcur", il);
            }
            
            ggml_tensor * Kcur = build_lora_mm(model.layers[il].wk, cur); // 键（Key）
            cb(Kcur, "Kcur", il);
            if (model.layers[il].bk) {
                Kcur = ggml_add(ctx0, Kcur, model.layers[il].bk); // 添加偏置
                cb(Kcur, "Kcur", il);
            }
            
            ggml_tensor * Vcur = build_lora_mm(model.layers[il].wv, cur); // 值（Value）
            cb(Vcur, "Vcur", il);
            if (model.layers[il].bv) {
                Vcur = ggml_add(ctx0, Vcur, model.layers[il].bv); // 添加偏置
                cb(Vcur, "Vcur", il);
            }
            
            // 重塑张量形状，适应注意力计算
            Qcur = ggml_reshape_3d(ctx0, Qcur, n_embd_head, n_head,    n_tokens);
            Kcur = ggml_reshape_3d(ctx0, Kcur, n_embd_head, n_head_kv, n_tokens);
            Vcur = ggml_reshape_3d(ctx0, Vcur, n_embd_head, n_head_kv, n_tokens);

            // 应用 RoPE（旋转位置编码）
            Qcur = ggml_rope_ext(
                    ctx0, Qcur, inp_pos, rope_factors,
                    n_rot, rope_type, n_ctx_orig, freq_base, freq_scale,
                    ext_factor, attn_factor, beta_fast, beta_slow
                    );

            Kcur = ggml_rope_ext(
                    ctx0, Kcur, inp_pos, rope_factors,
                    n_rot, rope_type, n_ctx_orig, freq_base, freq_scale,
                    ext_factor, attn_factor, beta_fast, beta_slow
                    );

            cb(Qcur, "Qcur", il);
            cb(Kcur, "Kcur", il);
            cb(Vcur, "Vcur", il);

            // 应用 QK 归一化（Llama 4）
            if (hparams.use_kq_norm) {
                Qcur = ggml_rms_norm(ctx0, Qcur, hparams.f_norm_rms_eps);
                Kcur = ggml_rms_norm(ctx0, Kcur, hparams.f_norm_rms_eps);
                cb(Qcur, "Qcur_normed", il);
                cb(Kcur, "Kcur_normed", il);
            }
            
            // 构建注意力计算
            cur = build_attn(inp_attn,
                    model.layers[il].wo, model.layers[il].bo, // 输出权重和偏置
                    Qcur, Kcur, Vcur, nullptr, nullptr, nullptr, kq_scale, il);
            cb(cur, "attn_out", il);
        }
        
        // 处理最后一层的输出 ID
        if (il == n_layer - 1 && inp_out_ids) {
            cur   = ggml_get_rows(ctx0,   cur, inp_out_ids);
            inpSA = ggml_get_rows(ctx0, inpSA, inp_out_ids);
        }
        
        // 残差连接：注意力输出 + 原始输入
        ggml_tensor * ffn_inp = ggml_add(ctx0, cur, inpSA);
        cb(ffn_inp, "ffn_inp", il);

        // 前馈网络（非 MoE 版本）
        if (model.layers[il].ffn_gate_inp == nullptr) {
            // 前馈网络归一化
            cur = build_norm(ffn_inp,
                    model.layers[il].ffn_norm, NULL,
                    LLM_NORM_RMS, il);
            cb(cur, "ffn_norm", il);

            // 构建前馈网络
            cur = build_ffn(cur,
                    model.layers[il].ffn_up,   model.layers[il].ffn_up_b,   NULL,
                    model.layers[il].ffn_gate, model.layers[il].ffn_gate_b, NULL,
                    model.layers[il].ffn_down, model.layers[il].ffn_down_b, NULL,
                    NULL,
                    LLM_FFN_SILU, LLM_FFN_PAR, il);
            cb(cur, "ffn_out", il);
        } else {
            // MoE（混合专家）分支
            // 前馈网络归一化
            cur = build_norm(ffn_inp,
                    model.layers[il].ffn_norm, NULL,
                    LLM_NORM_RMS, il);
            cb(cur, "ffn_norm", il);

            // 构建 MoE 前馈网络
            cur = build_moe_ffn(cur,
                    model.layers[il].ffn_gate_inp,
                    model.layers[il].ffn_up_exps,
                    model.layers[il].ffn_gate_exps,
                    model.layers[il].ffn_down_exps,
                    nullptr,
                    n_expert, n_expert_used,
                    LLM_FFN_SILU, true,
                    false, 0.0,
                    LLAMA_EXPERT_GATING_FUNC_TYPE_SOFTMAX,
                    il);
            cb(cur, "ffn_moe_out", il);
        }
        
        // 残差连接：前馈网络输出 + 前馈网络输入
        cur = ggml_add(ctx0, cur, ffn_inp);
        cb(cur, "ffn_out", il);

        // 构建上下文向量
        cur = build_cvec(cur, il);
        cb(cur, "l_out", il);

        // 更新下一层的输入
        inpL = cur;
    }
    
    // 最终输出
    cur = inpL;

    // 最终归一化
    cur = build_norm(cur,
            model.output_norm, NULL,
            LLM_NORM_RMS, -1);

    cb(cur, "result_norm", -1);
    res->t_embd = cur; // 设置嵌入输出

    // 非嵌入模式：构建语言模型头
    if constexpr (!embed) {
        // lm_head
        cur = build_lora_mm(model.output, cur);

        cb(cur, "result_output", -1);
        res->t_logits = cur; // 设置对数概率输出
    }

    // 构建前向计算图
    ggml_build_forward_expand(gf, cur);
}

template struct llm_build_llama<false>;
template struct llm_build_llama<true>;
