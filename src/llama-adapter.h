#pragma once

#include "llama.h"

#include "ggml-cpp.h"

#include <string>
#include <unordered_map>
#include <vector>

// TODO: pimpl

//
// llama_adapter_cvec
//

// 类: llama_adapter_cvec
// 描述: llama_adapter_cvec类提供相关功能
// 用途: 用于处理llama_adapter_cvec相关的操作
// 类: llama_adapter_cvec
// 描述: llama_adapter_cvec类提供相关功能
// 用途: 用于处理llama_adapter_cvec相关的操作
    // 结构体: llama_adapter_cvec
    // 描述: llama_adapter_cvec结构体提供相关功能
    // 用途: 用于处理llama_adapter_cvec相关的操作
    // 结构体: llama_adapter_cvec
    // 描述: llama_adapter_cvec结构体提供相关功能
    // 用途: 用于处理llama_adapter_cvec相关的操作
    // 结构体: llama_adapter_cvec
    // 描述: llama_adapter_cvec结构体提供相关功能
    // 用途: 用于处理llama_adapter_cvec相关的操作
    // 结构体: llama_adapter_cvec
    // 描述: llama_adapter_cvec结构体提供相关功能
    // 用途: 用于处理llama_adapter_cvec相关的操作
struct llama_adapter_cvec {
    // 函数: tensor_for
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tensor_for
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * tensor_for(int il) const;

    // 函数: apply_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: apply_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * apply_to(ggml_context * ctx, ggml_tensor * cur, int  il) const;

    bool apply(
            const llama_model & model,
            const float * data,
            size_t len,
            int32_t n_embd,
            int32_t il_start,
            int32_t il_end);

private:
    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    bool init(const llama_model & model);

    int32_t layer_start = -1;
    int32_t layer_end   = -1;

    std::vector<ggml_context_ptr> ctxs;
    std::vector<ggml_backend_buffer_ptr> bufs;

    std::vector<ggml_tensor *> tensors; // per layer
};

using llama_adapter_cvec_ptr = std::shared_ptr<llama_adapter_cvec>;

//
// llama_adapter_lora
//

// 类: llama_adapter_lora_weight
// 描述: llama_adapter_lora_weight类提供相关功能
// 用途: 用于处理llama_adapter_lora_weight相关的操作
// 类: llama_adapter_lora_weight
// 描述: llama_adapter_lora_weight类提供相关功能
// 用途: 用于处理llama_adapter_lora_weight相关的操作
    // 结构体: llama_adapter_lora_weight
    // 描述: llama_adapter_lora_weight结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_weight相关的操作
    // 结构体: llama_adapter_lora_weight
    // 描述: llama_adapter_lora_weight结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_weight相关的操作
    // 结构体: llama_adapter_lora_weight
    // 描述: llama_adapter_lora_weight结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_weight相关的操作
    // 结构体: llama_adapter_lora_weight
    // 描述: llama_adapter_lora_weight结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_weight相关的操作
struct llama_adapter_lora_weight {
    ggml_tensor * a = nullptr;
    ggml_tensor * b = nullptr;

    // get actual scale based on rank and alpha
    // 函数: get_scale
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_scale
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float get_scale(float alpha, float adapter_scale) const {
        const float rank  = (float) b->ne[0];
        const float scale = alpha ? adapter_scale * alpha / rank : adapter_scale;
        return scale;
    }

    llama_adapter_lora_weight() = default;
    llama_adapter_lora_weight(ggml_tensor * a, ggml_tensor * b) : a(a), b(b) {}
};

// 类: llama_adapter_lora
// 描述: llama_adapter_lora类提供相关功能
// 用途: 用于处理llama_adapter_lora相关的操作
// 类: llama_adapter_lora
// 描述: llama_adapter_lora类提供相关功能
// 用途: 用于处理llama_adapter_lora相关的操作
    // 结构体: llama_adapter_lora
    // 描述: llama_adapter_lora结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora相关的操作
    // 结构体: llama_adapter_lora
    // 描述: llama_adapter_lora结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora相关的操作
    // 结构体: llama_adapter_lora
    // 描述: llama_adapter_lora结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora相关的操作
    // 结构体: llama_adapter_lora
    // 描述: llama_adapter_lora结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora相关的操作
struct llama_adapter_lora {
    // map tensor name to lora_a_b
    std::unordered_map<std::string, llama_adapter_lora_weight> ab_map;

    std::vector<ggml_context_ptr> ctxs;
    std::vector<ggml_backend_buffer_ptr> bufs;

    float alpha;

    // gguf metadata
    std::unordered_map<std::string, std::string> gguf_kv;

    // activated lora (aLoRA)
    std::vector<llama_token> alora_invocation_tokens;

    llama_adapter_lora() = default;
    ~llama_adapter_lora() = default;

    // 函数: get_weight
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_weight
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_adapter_lora_weight * get_weight(ggml_tensor * w);

    // 函数: get_n_nodes
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_nodes
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_nodes() const {
        return ab_map.size() * 6u; // a, b, scale, add, 2 x mul_mat
    }
};

using llama_adapter_loras = std::unordered_map<llama_adapter_lora *, float>;
using llama_adapter_loras_ptr = std::unique_ptr<llama_adapter_loras>;
