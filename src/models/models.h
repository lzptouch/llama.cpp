// ============================================================================
// 文件: models.h
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/src/models/models.h
// 描述: 模型构建器基类和模型实现声明
// 作用: 定义各种模型的构建器类，用于构建计算图
// 包含: 基础构建器类和各种模型的构建器声明
// ============================================================================

#pragma once

#include "llama-model.h"
#include "llama-graph.h"

// note: almost all graphs require atleast sqrtf, so include cmath globally
#include <cmath>

//
// base classes
//

// 结构体: llm_build_mamba_base
// 描述: Mamba模型构建器基类
// 作用: 提供Mamba模型层的构建功能
// 继承: llm_graph_context
struct llm_build_mamba_base : public llm_graph_context {
    // 构造函数: llm_build_mamba_base
    // 描述: 初始化Mamba构建器基类
    // 参数:
    //   - params: 图参数
    llm_build_mamba_base(const llm_graph_params & params);

    virtual ~llm_build_mamba_base() = default;

    // 函数: build_mamba_layer
    // 描述: 构建Mamba层
    // 参数:
    //   - inp: 图输入
    //   - cur: 当前张量
    //   - model: 模型
    //   - ubatch: 微批处理
    //   - il: 层索引
    // 返回: 输出张量
    ggml_tensor * build_mamba_layer(llm_graph_input_rs * inp, ggml_tensor * cur, const llama_model & model, const llama_ubatch & ubatch, int il);
    
    // 函数: build_mamba2_layer
    // 描述: 构建Mamba2层
    // 参数:
    //   - inp: 图输入
    //   - cur: 当前张量
    //   - model: 模型
    //   - ubatch: 微批处理
    //   - il: 层索引
    // 返回: 输出张量
    ggml_tensor * build_mamba2_layer(llm_graph_input_rs * inp, ggml_tensor * cur, const llama_model & model, const llama_ubatch & ubatch, int il) const;

};

// 结构体: llm_build_delta_net_base
// 描述: Delta Net模型构建器基类
// 作用: 提供Delta Net模型的构建功能
// 继承: llm_graph_context
struct llm_build_delta_net_base : public llm_graph_context {
    // 构造函数: llm_build_delta_net_base
    // 描述: 初始化Delta Net构建器基类
    // 参数:
    //   - params: 图参数
    llm_build_delta_net_base(const llm_graph_params & params);

    virtual ~llm_build_delta_net_base() = default;

    // 函数: build_delta_net_chunking
    // 描述: 构建Delta Net分块处理
    // 参数:
    //   - q: 查询张量
    //   - k: 键张量
    //   - v: 值张量
    //   - g: 门控张量
    //   - b: 偏置张量
    //   - s: 状态张量
    //   - il: 层索引
    // 返回: 输出张量和新状态张量
    std::pair<ggml_tensor *, ggml_tensor *> build_delta_net_chunking(
                ggml_tensor * q,
                ggml_tensor * k,
                ggml_tensor * v,
                ggml_tensor * g,
                ggml_tensor * b,
                ggml_tensor * s,
                        int   il);

    // 函数: build_delta_net_autoregressive
    // 描述: 构建Delta Net自回归处理
    // 参数:
    //   - q: 查询张量
    //   - k: 键张量
    //   - v: 值张量
    //   - g: 门控张量
    //   - b: 偏置张量
    //   - s: 状态张量
    //   - il: 层索引
    // 返回: 输出张量和新状态张量
    std::pair<ggml_tensor *, ggml_tensor *> build_delta_net_autoregressive(
                ggml_tensor * q,
                ggml_tensor * k,
                ggml_tensor * v,
                ggml_tensor * g,
                ggml_tensor * b,
                ggml_tensor * s,
                int           il);
};

// 结构体: llm_build_rwkv6_base
// 描述: RWKV6模型构建器基类
// 作用: 提供RWKV6模型的构建功能
// 继承: llm_graph_context
struct llm_build_rwkv6_base : public llm_graph_context {
    const llama_model & model; // 模型引用

    // 构造函数: llm_build_rwkv6_base
    // 描述: 初始化RWKV6构建器基类
    // 参数:
    //   - model: 模型
    //   - params: 图参数
    llm_build_rwkv6_base(const llama_model & model, const llm_graph_params & params);

    virtual ~llm_build_rwkv6_base() = default;

    // 函数: build_rwkv6_channel_mix
    // 描述: 构建RWKV6通道混合
    // 参数:
    //   - layer: 层
    //   - cur: 当前张量
    //   - x_prev: 前一个张量
    //   - arch: 架构
    // 返回: 输出张量
    ggml_tensor * build_rwkv6_channel_mix(const llama_layer * layer,
                                          ggml_tensor *       cur,
                                          ggml_tensor *       x_prev,
                                          llm_arch            arch) const;

    // 函数: build_rwkv6_time_mix
    // 描述: 构建RWKV6时间混合
    // 参数:
    //   - inp: 图输入
    //   - cur: 当前张量
    //   - x_prev: 前一个张量
    //   - ubatch: 微批处理
    //   - il: 层索引
    // 返回: 输出张量
    ggml_tensor * build_rwkv6_time_mix(llm_graph_input_rs * inp,
                                       ggml_tensor *        cur,
                                       ggml_tensor *        x_prev,
                                       const llama_ubatch & ubatch,
                                       int                  il) const;
};

// Base class for RWKV7-related models
// 类: llm_build_rwkv7_base
// 描述: llm_build_rwkv7_base类提供相关功能
// 用途: 用于处理llm_build_rwkv7_base相关的操作
// 类: llm_build_rwkv7_base
// 描述: llm_build_rwkv7_base类提供相关功能
// 用途: 用于处理llm_build_rwkv7_base相关的操作
    // 结构体: llm_build_rwkv7_base
    // 描述: llm_build_rwkv7_base结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7_base相关的操作
    // 结构体: llm_build_rwkv7_base
    // 描述: llm_build_rwkv7_base结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7_base相关的操作
    // 结构体: llm_build_rwkv7_base
    // 描述: llm_build_rwkv7_base结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7_base相关的操作
    // 结构体: llm_build_rwkv7_base
    // 描述: llm_build_rwkv7_base结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7_base相关的操作
struct llm_build_rwkv7_base : public llm_graph_context {
    const llama_model & model;

    llm_build_rwkv7_base(const llama_model & model, const llm_graph_params & params);

    virtual ~llm_build_rwkv7_base() = default;

    // RWKV7-specific graph building methods
    ggml_tensor * build_rwkv7_channel_mix(const llama_layer * layer,
                                          ggml_tensor *       cur,
                                          ggml_tensor *       x_prev,
                                          llm_arch            arch) const;
    ggml_tensor * build_rwkv7_time_mix(llm_graph_input_rs * inp,
                                       ggml_tensor *        cur,
                                       ggml_tensor *        x_prev,
                                       ggml_tensor *&       first_layer_value,
                                       const llama_ubatch & ubatch,
                                       int                  il) const;
};

//
// models
//

// 类: llm_build_afmoe
// 描述: llm_build_afmoe类提供相关功能
// 用途: 用于处理llm_build_afmoe相关的操作
// 类: llm_build_afmoe
// 描述: llm_build_afmoe类提供相关功能
// 用途: 用于处理llm_build_afmoe相关的操作
    // 结构体: llm_build_afmoe
    // 描述: llm_build_afmoe结构体提供相关功能
    // 用途: 用于处理llm_build_afmoe相关的操作
    // 结构体: llm_build_afmoe
    // 描述: llm_build_afmoe结构体提供相关功能
    // 用途: 用于处理llm_build_afmoe相关的操作
    // 结构体: llm_build_afmoe
    // 描述: llm_build_afmoe结构体提供相关功能
    // 用途: 用于处理llm_build_afmoe相关的操作
    // 结构体: llm_build_afmoe
    // 描述: llm_build_afmoe结构体提供相关功能
    // 用途: 用于处理llm_build_afmoe相关的操作
struct llm_build_afmoe : public llm_graph_context {
    llm_build_afmoe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_apertus
// 描述: llm_build_apertus类提供相关功能
// 用途: 用于处理llm_build_apertus相关的操作
// 类: llm_build_apertus
// 描述: llm_build_apertus类提供相关功能
// 用途: 用于处理llm_build_apertus相关的操作
    // 结构体: llm_build_apertus
    // 描述: llm_build_apertus结构体提供相关功能
    // 用途: 用于处理llm_build_apertus相关的操作
    // 结构体: llm_build_apertus
    // 描述: llm_build_apertus结构体提供相关功能
    // 用途: 用于处理llm_build_apertus相关的操作
    // 结构体: llm_build_apertus
    // 描述: llm_build_apertus结构体提供相关功能
    // 用途: 用于处理llm_build_apertus相关的操作
    // 结构体: llm_build_apertus
    // 描述: llm_build_apertus结构体提供相关功能
    // 用途: 用于处理llm_build_apertus相关的操作
struct llm_build_apertus : public llm_graph_context {
    llm_build_apertus(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_arcee
// 描述: llm_build_arcee类提供相关功能
// 用途: 用于处理llm_build_arcee相关的操作
// 类: llm_build_arcee
// 描述: llm_build_arcee类提供相关功能
// 用途: 用于处理llm_build_arcee相关的操作
    // 结构体: llm_build_arcee
    // 描述: llm_build_arcee结构体提供相关功能
    // 用途: 用于处理llm_build_arcee相关的操作
    // 结构体: llm_build_arcee
    // 描述: llm_build_arcee结构体提供相关功能
    // 用途: 用于处理llm_build_arcee相关的操作
    // 结构体: llm_build_arcee
    // 描述: llm_build_arcee结构体提供相关功能
    // 用途: 用于处理llm_build_arcee相关的操作
    // 结构体: llm_build_arcee
    // 描述: llm_build_arcee结构体提供相关功能
    // 用途: 用于处理llm_build_arcee相关的操作
struct llm_build_arcee : public llm_graph_context {
    llm_build_arcee(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_arctic
// 描述: llm_build_arctic类提供相关功能
// 用途: 用于处理llm_build_arctic相关的操作
// 类: llm_build_arctic
// 描述: llm_build_arctic类提供相关功能
// 用途: 用于处理llm_build_arctic相关的操作
    // 结构体: llm_build_arctic
    // 描述: llm_build_arctic结构体提供相关功能
    // 用途: 用于处理llm_build_arctic相关的操作
    // 结构体: llm_build_arctic
    // 描述: llm_build_arctic结构体提供相关功能
    // 用途: 用于处理llm_build_arctic相关的操作
    // 结构体: llm_build_arctic
    // 描述: llm_build_arctic结构体提供相关功能
    // 用途: 用于处理llm_build_arctic相关的操作
    // 结构体: llm_build_arctic
    // 描述: llm_build_arctic结构体提供相关功能
    // 用途: 用于处理llm_build_arctic相关的操作
struct llm_build_arctic : public llm_graph_context {
    llm_build_arctic(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_arwkv7
// 描述: llm_build_arwkv7类提供相关功能
// 用途: 用于处理llm_build_arwkv7相关的操作
// 类: llm_build_arwkv7
// 描述: llm_build_arwkv7类提供相关功能
// 用途: 用于处理llm_build_arwkv7相关的操作
    // 结构体: llm_build_arwkv7
    // 描述: llm_build_arwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_arwkv7相关的操作
    // 结构体: llm_build_arwkv7
    // 描述: llm_build_arwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_arwkv7相关的操作
    // 结构体: llm_build_arwkv7
    // 描述: llm_build_arwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_arwkv7相关的操作
    // 结构体: llm_build_arwkv7
    // 描述: llm_build_arwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_arwkv7相关的操作
struct llm_build_arwkv7 : public llm_build_rwkv7_base {
    llm_build_arwkv7(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_baichuan
// 描述: llm_build_baichuan类提供相关功能
// 用途: 用于处理llm_build_baichuan相关的操作
// 类: llm_build_baichuan
// 描述: llm_build_baichuan类提供相关功能
// 用途: 用于处理llm_build_baichuan相关的操作
    // 结构体: llm_build_baichuan
    // 描述: llm_build_baichuan结构体提供相关功能
    // 用途: 用于处理llm_build_baichuan相关的操作
    // 结构体: llm_build_baichuan
    // 描述: llm_build_baichuan结构体提供相关功能
    // 用途: 用于处理llm_build_baichuan相关的操作
    // 结构体: llm_build_baichuan
    // 描述: llm_build_baichuan结构体提供相关功能
    // 用途: 用于处理llm_build_baichuan相关的操作
    // 结构体: llm_build_baichuan
    // 描述: llm_build_baichuan结构体提供相关功能
    // 用途: 用于处理llm_build_baichuan相关的操作
struct llm_build_baichuan : public llm_graph_context {
    llm_build_baichuan(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_bailingmoe2
// 描述: llm_build_bailingmoe2类提供相关功能
// 用途: 用于处理llm_build_bailingmoe2相关的操作
// 类: llm_build_bailingmoe2
// 描述: llm_build_bailingmoe2类提供相关功能
// 用途: 用于处理llm_build_bailingmoe2相关的操作
    // 结构体: llm_build_bailingmoe2
    // 描述: llm_build_bailingmoe2结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe2相关的操作
    // 结构体: llm_build_bailingmoe2
    // 描述: llm_build_bailingmoe2结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe2相关的操作
    // 结构体: llm_build_bailingmoe2
    // 描述: llm_build_bailingmoe2结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe2相关的操作
    // 结构体: llm_build_bailingmoe2
    // 描述: llm_build_bailingmoe2结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe2相关的操作
struct llm_build_bailingmoe2 : public llm_graph_context {
    llm_build_bailingmoe2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_bailingmoe
// 描述: llm_build_bailingmoe类提供相关功能
// 用途: 用于处理llm_build_bailingmoe相关的操作
// 类: llm_build_bailingmoe
// 描述: llm_build_bailingmoe类提供相关功能
// 用途: 用于处理llm_build_bailingmoe相关的操作
    // 结构体: llm_build_bailingmoe
    // 描述: llm_build_bailingmoe结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe相关的操作
    // 结构体: llm_build_bailingmoe
    // 描述: llm_build_bailingmoe结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe相关的操作
    // 结构体: llm_build_bailingmoe
    // 描述: llm_build_bailingmoe结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe相关的操作
    // 结构体: llm_build_bailingmoe
    // 描述: llm_build_bailingmoe结构体提供相关功能
    // 用途: 用于处理llm_build_bailingmoe相关的操作
struct llm_build_bailingmoe : public llm_graph_context {
    llm_build_bailingmoe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_bert
// 描述: llm_build_bert类提供相关功能
// 用途: 用于处理llm_build_bert相关的操作
// 类: llm_build_bert
// 描述: llm_build_bert类提供相关功能
// 用途: 用于处理llm_build_bert相关的操作
    // 结构体: llm_build_bert
    // 描述: llm_build_bert结构体提供相关功能
    // 用途: 用于处理llm_build_bert相关的操作
    // 结构体: llm_build_bert
    // 描述: llm_build_bert结构体提供相关功能
    // 用途: 用于处理llm_build_bert相关的操作
    // 结构体: llm_build_bert
    // 描述: llm_build_bert结构体提供相关功能
    // 用途: 用于处理llm_build_bert相关的操作
    // 结构体: llm_build_bert
    // 描述: llm_build_bert结构体提供相关功能
    // 用途: 用于处理llm_build_bert相关的操作
struct llm_build_bert : public llm_graph_context {
    llm_build_bert(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_bitnet
// 描述: llm_build_bitnet类提供相关功能
// 用途: 用于处理llm_build_bitnet相关的操作
// 类: llm_build_bitnet
// 描述: llm_build_bitnet类提供相关功能
// 用途: 用于处理llm_build_bitnet相关的操作
    // 结构体: llm_build_bitnet
    // 描述: llm_build_bitnet结构体提供相关功能
    // 用途: 用于处理llm_build_bitnet相关的操作
    // 结构体: llm_build_bitnet
    // 描述: llm_build_bitnet结构体提供相关功能
    // 用途: 用于处理llm_build_bitnet相关的操作
    // 结构体: llm_build_bitnet
    // 描述: llm_build_bitnet结构体提供相关功能
    // 用途: 用于处理llm_build_bitnet相关的操作
    // 结构体: llm_build_bitnet
    // 描述: llm_build_bitnet结构体提供相关功能
    // 用途: 用于处理llm_build_bitnet相关的操作
struct llm_build_bitnet : public llm_graph_context {
    llm_build_bitnet(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_bloom
// 描述: llm_build_bloom类提供相关功能
// 用途: 用于处理llm_build_bloom相关的操作
// 类: llm_build_bloom
// 描述: llm_build_bloom类提供相关功能
// 用途: 用于处理llm_build_bloom相关的操作
    // 结构体: llm_build_bloom
    // 描述: llm_build_bloom结构体提供相关功能
    // 用途: 用于处理llm_build_bloom相关的操作
    // 结构体: llm_build_bloom
    // 描述: llm_build_bloom结构体提供相关功能
    // 用途: 用于处理llm_build_bloom相关的操作
    // 结构体: llm_build_bloom
    // 描述: llm_build_bloom结构体提供相关功能
    // 用途: 用于处理llm_build_bloom相关的操作
    // 结构体: llm_build_bloom
    // 描述: llm_build_bloom结构体提供相关功能
    // 用途: 用于处理llm_build_bloom相关的操作
struct llm_build_bloom : public llm_graph_context {
    llm_build_bloom(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_chameleon
// 描述: llm_build_chameleon类提供相关功能
// 用途: 用于处理llm_build_chameleon相关的操作
// 类: llm_build_chameleon
// 描述: llm_build_chameleon类提供相关功能
// 用途: 用于处理llm_build_chameleon相关的操作
    // 结构体: llm_build_chameleon
    // 描述: llm_build_chameleon结构体提供相关功能
    // 用途: 用于处理llm_build_chameleon相关的操作
    // 结构体: llm_build_chameleon
    // 描述: llm_build_chameleon结构体提供相关功能
    // 用途: 用于处理llm_build_chameleon相关的操作
    // 结构体: llm_build_chameleon
    // 描述: llm_build_chameleon结构体提供相关功能
    // 用途: 用于处理llm_build_chameleon相关的操作
    // 结构体: llm_build_chameleon
    // 描述: llm_build_chameleon结构体提供相关功能
    // 用途: 用于处理llm_build_chameleon相关的操作
struct llm_build_chameleon : public llm_graph_context {
    llm_build_chameleon(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_chatglm
// 描述: llm_build_chatglm类提供相关功能
// 用途: 用于处理llm_build_chatglm相关的操作
// 类: llm_build_chatglm
// 描述: llm_build_chatglm类提供相关功能
// 用途: 用于处理llm_build_chatglm相关的操作
    // 结构体: llm_build_chatglm
    // 描述: llm_build_chatglm结构体提供相关功能
    // 用途: 用于处理llm_build_chatglm相关的操作
    // 结构体: llm_build_chatglm
    // 描述: llm_build_chatglm结构体提供相关功能
    // 用途: 用于处理llm_build_chatglm相关的操作
    // 结构体: llm_build_chatglm
    // 描述: llm_build_chatglm结构体提供相关功能
    // 用途: 用于处理llm_build_chatglm相关的操作
    // 结构体: llm_build_chatglm
    // 描述: llm_build_chatglm结构体提供相关功能
    // 用途: 用于处理llm_build_chatglm相关的操作
struct llm_build_chatglm : public llm_graph_context {
    llm_build_chatglm(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_codeshell
// 描述: llm_build_codeshell类提供相关功能
// 用途: 用于处理llm_build_codeshell相关的操作
// 类: llm_build_codeshell
// 描述: llm_build_codeshell类提供相关功能
// 用途: 用于处理llm_build_codeshell相关的操作
    // 结构体: llm_build_codeshell
    // 描述: llm_build_codeshell结构体提供相关功能
    // 用途: 用于处理llm_build_codeshell相关的操作
    // 结构体: llm_build_codeshell
    // 描述: llm_build_codeshell结构体提供相关功能
    // 用途: 用于处理llm_build_codeshell相关的操作
    // 结构体: llm_build_codeshell
    // 描述: llm_build_codeshell结构体提供相关功能
    // 用途: 用于处理llm_build_codeshell相关的操作
    // 结构体: llm_build_codeshell
    // 描述: llm_build_codeshell结构体提供相关功能
    // 用途: 用于处理llm_build_codeshell相关的操作
struct llm_build_codeshell : public llm_graph_context {
    llm_build_codeshell(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_cogvlm
// 描述: llm_build_cogvlm类提供相关功能
// 用途: 用于处理llm_build_cogvlm相关的操作
// 类: llm_build_cogvlm
// 描述: llm_build_cogvlm类提供相关功能
// 用途: 用于处理llm_build_cogvlm相关的操作
    // 结构体: llm_build_cogvlm
    // 描述: llm_build_cogvlm结构体提供相关功能
    // 用途: 用于处理llm_build_cogvlm相关的操作
    // 结构体: llm_build_cogvlm
    // 描述: llm_build_cogvlm结构体提供相关功能
    // 用途: 用于处理llm_build_cogvlm相关的操作
    // 结构体: llm_build_cogvlm
    // 描述: llm_build_cogvlm结构体提供相关功能
    // 用途: 用于处理llm_build_cogvlm相关的操作
    // 结构体: llm_build_cogvlm
    // 描述: llm_build_cogvlm结构体提供相关功能
    // 用途: 用于处理llm_build_cogvlm相关的操作
struct llm_build_cogvlm : public llm_graph_context {
    llm_build_cogvlm(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_cohere2_iswa
// 描述: llm_build_cohere2_iswa类提供相关功能
// 用途: 用于处理llm_build_cohere2_iswa相关的操作
// 类: llm_build_cohere2_iswa
// 描述: llm_build_cohere2_iswa类提供相关功能
// 用途: 用于处理llm_build_cohere2_iswa相关的操作
    // 结构体: llm_build_cohere2_iswa
    // 描述: llm_build_cohere2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_cohere2_iswa相关的操作
    // 结构体: llm_build_cohere2_iswa
    // 描述: llm_build_cohere2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_cohere2_iswa相关的操作
    // 结构体: llm_build_cohere2_iswa
    // 描述: llm_build_cohere2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_cohere2_iswa相关的操作
    // 结构体: llm_build_cohere2_iswa
    // 描述: llm_build_cohere2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_cohere2_iswa相关的操作
struct llm_build_cohere2_iswa : public llm_graph_context {
    llm_build_cohere2_iswa(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_command_r
// 描述: llm_build_command_r类提供相关功能
// 用途: 用于处理llm_build_command_r相关的操作
// 类: llm_build_command_r
// 描述: llm_build_command_r类提供相关功能
// 用途: 用于处理llm_build_command_r相关的操作
    // 结构体: llm_build_command_r
    // 描述: llm_build_command_r结构体提供相关功能
    // 用途: 用于处理llm_build_command_r相关的操作
    // 结构体: llm_build_command_r
    // 描述: llm_build_command_r结构体提供相关功能
    // 用途: 用于处理llm_build_command_r相关的操作
    // 结构体: llm_build_command_r
    // 描述: llm_build_command_r结构体提供相关功能
    // 用途: 用于处理llm_build_command_r相关的操作
    // 结构体: llm_build_command_r
    // 描述: llm_build_command_r结构体提供相关功能
    // 用途: 用于处理llm_build_command_r相关的操作
struct llm_build_command_r : public llm_graph_context {
    llm_build_command_r(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_dbrx
// 描述: llm_build_dbrx类提供相关功能
// 用途: 用于处理llm_build_dbrx相关的操作
// 类: llm_build_dbrx
// 描述: llm_build_dbrx类提供相关功能
// 用途: 用于处理llm_build_dbrx相关的操作
    // 结构体: llm_build_dbrx
    // 描述: llm_build_dbrx结构体提供相关功能
    // 用途: 用于处理llm_build_dbrx相关的操作
    // 结构体: llm_build_dbrx
    // 描述: llm_build_dbrx结构体提供相关功能
    // 用途: 用于处理llm_build_dbrx相关的操作
    // 结构体: llm_build_dbrx
    // 描述: llm_build_dbrx结构体提供相关功能
    // 用途: 用于处理llm_build_dbrx相关的操作
    // 结构体: llm_build_dbrx
    // 描述: llm_build_dbrx结构体提供相关功能
    // 用途: 用于处理llm_build_dbrx相关的操作
struct llm_build_dbrx : public llm_graph_context {
    llm_build_dbrx(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_deci
// 描述: llm_build_deci类提供相关功能
// 用途: 用于处理llm_build_deci相关的操作
// 类: llm_build_deci
// 描述: llm_build_deci类提供相关功能
// 用途: 用于处理llm_build_deci相关的操作
    // 结构体: llm_build_deci
    // 描述: llm_build_deci结构体提供相关功能
    // 用途: 用于处理llm_build_deci相关的操作
    // 结构体: llm_build_deci
    // 描述: llm_build_deci结构体提供相关功能
    // 用途: 用于处理llm_build_deci相关的操作
    // 结构体: llm_build_deci
    // 描述: llm_build_deci结构体提供相关功能
    // 用途: 用于处理llm_build_deci相关的操作
    // 结构体: llm_build_deci
    // 描述: llm_build_deci结构体提供相关功能
    // 用途: 用于处理llm_build_deci相关的操作
struct llm_build_deci : public llm_graph_context {
    llm_build_deci(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_deepseek2
// 描述: llm_build_deepseek2类提供相关功能
// 用途: 用于处理llm_build_deepseek2相关的操作
// 类: llm_build_deepseek2
// 描述: llm_build_deepseek2类提供相关功能
// 用途: 用于处理llm_build_deepseek2相关的操作
    // 结构体: llm_build_deepseek2
    // 描述: llm_build_deepseek2结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek2相关的操作
    // 结构体: llm_build_deepseek2
    // 描述: llm_build_deepseek2结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek2相关的操作
    // 结构体: llm_build_deepseek2
    // 描述: llm_build_deepseek2结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek2相关的操作
    // 结构体: llm_build_deepseek2
    // 描述: llm_build_deepseek2结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek2相关的操作
struct llm_build_deepseek2 : public llm_graph_context {
    llm_build_deepseek2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_deepseek
// 描述: llm_build_deepseek类提供相关功能
// 用途: 用于处理llm_build_deepseek相关的操作
// 类: llm_build_deepseek
// 描述: llm_build_deepseek类提供相关功能
// 用途: 用于处理llm_build_deepseek相关的操作
    // 结构体: llm_build_deepseek
    // 描述: llm_build_deepseek结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek相关的操作
    // 结构体: llm_build_deepseek
    // 描述: llm_build_deepseek结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek相关的操作
    // 结构体: llm_build_deepseek
    // 描述: llm_build_deepseek结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek相关的操作
    // 结构体: llm_build_deepseek
    // 描述: llm_build_deepseek结构体提供相关功能
    // 用途: 用于处理llm_build_deepseek相关的操作
struct llm_build_deepseek : public llm_graph_context {
    llm_build_deepseek(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_dots1
// 描述: llm_build_dots1类提供相关功能
// 用途: 用于处理llm_build_dots1相关的操作
// 类: llm_build_dots1
// 描述: llm_build_dots1类提供相关功能
// 用途: 用于处理llm_build_dots1相关的操作
    // 结构体: llm_build_dots1
    // 描述: llm_build_dots1结构体提供相关功能
    // 用途: 用于处理llm_build_dots1相关的操作
    // 结构体: llm_build_dots1
    // 描述: llm_build_dots1结构体提供相关功能
    // 用途: 用于处理llm_build_dots1相关的操作
    // 结构体: llm_build_dots1
    // 描述: llm_build_dots1结构体提供相关功能
    // 用途: 用于处理llm_build_dots1相关的操作
    // 结构体: llm_build_dots1
    // 描述: llm_build_dots1结构体提供相关功能
    // 用途: 用于处理llm_build_dots1相关的操作
struct llm_build_dots1 : public llm_graph_context {
    llm_build_dots1(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_dream
// 描述: llm_build_dream类提供相关功能
// 用途: 用于处理llm_build_dream相关的操作
// 类: llm_build_dream
// 描述: llm_build_dream类提供相关功能
// 用途: 用于处理llm_build_dream相关的操作
    // 结构体: llm_build_dream
    // 描述: llm_build_dream结构体提供相关功能
    // 用途: 用于处理llm_build_dream相关的操作
    // 结构体: llm_build_dream
    // 描述: llm_build_dream结构体提供相关功能
    // 用途: 用于处理llm_build_dream相关的操作
    // 结构体: llm_build_dream
    // 描述: llm_build_dream结构体提供相关功能
    // 用途: 用于处理llm_build_dream相关的操作
    // 结构体: llm_build_dream
    // 描述: llm_build_dream结构体提供相关功能
    // 用途: 用于处理llm_build_dream相关的操作
struct llm_build_dream : public llm_graph_context {
    llm_build_dream(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_ernie4_5
// 描述: llm_build_ernie4_5类提供相关功能
// 用途: 用于处理llm_build_ernie4_5相关的操作
// 类: llm_build_ernie4_5
// 描述: llm_build_ernie4_5类提供相关功能
// 用途: 用于处理llm_build_ernie4_5相关的操作
    // 结构体: llm_build_ernie4_5
    // 描述: llm_build_ernie4_5结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5相关的操作
    // 结构体: llm_build_ernie4_5
    // 描述: llm_build_ernie4_5结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5相关的操作
    // 结构体: llm_build_ernie4_5
    // 描述: llm_build_ernie4_5结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5相关的操作
    // 结构体: llm_build_ernie4_5
    // 描述: llm_build_ernie4_5结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5相关的操作
struct llm_build_ernie4_5 : public llm_graph_context {
    llm_build_ernie4_5(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_ernie4_5_moe
// 描述: llm_build_ernie4_5_moe类提供相关功能
// 用途: 用于处理llm_build_ernie4_5_moe相关的操作
// 类: llm_build_ernie4_5_moe
// 描述: llm_build_ernie4_5_moe类提供相关功能
// 用途: 用于处理llm_build_ernie4_5_moe相关的操作
    // 结构体: llm_build_ernie4_5_moe
    // 描述: llm_build_ernie4_5_moe结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5_moe相关的操作
    // 结构体: llm_build_ernie4_5_moe
    // 描述: llm_build_ernie4_5_moe结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5_moe相关的操作
    // 结构体: llm_build_ernie4_5_moe
    // 描述: llm_build_ernie4_5_moe结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5_moe相关的操作
    // 结构体: llm_build_ernie4_5_moe
    // 描述: llm_build_ernie4_5_moe结构体提供相关功能
    // 用途: 用于处理llm_build_ernie4_5_moe相关的操作
struct llm_build_ernie4_5_moe : public llm_graph_context {
    llm_build_ernie4_5_moe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_paddleocr
// 描述: llm_build_paddleocr类提供相关功能
// 用途: 用于处理llm_build_paddleocr相关的操作
// 类: llm_build_paddleocr
// 描述: llm_build_paddleocr类提供相关功能
// 用途: 用于处理llm_build_paddleocr相关的操作
    // 结构体: llm_build_paddleocr
    // 描述: llm_build_paddleocr结构体提供相关功能
    // 用途: 用于处理llm_build_paddleocr相关的操作
    // 结构体: llm_build_paddleocr
    // 描述: llm_build_paddleocr结构体提供相关功能
    // 用途: 用于处理llm_build_paddleocr相关的操作
    // 结构体: llm_build_paddleocr
    // 描述: llm_build_paddleocr结构体提供相关功能
    // 用途: 用于处理llm_build_paddleocr相关的操作
    // 结构体: llm_build_paddleocr
    // 描述: llm_build_paddleocr结构体提供相关功能
    // 用途: 用于处理llm_build_paddleocr相关的操作
struct llm_build_paddleocr : public llm_graph_context {
    llm_build_paddleocr(const llama_model & model, const llm_graph_params & params);
};

template <bool iswa>
// 类: llm_build_exaone4
// 描述: llm_build_exaone4类提供相关功能
// 用途: 用于处理llm_build_exaone4相关的操作
// 类: llm_build_exaone4
// 描述: llm_build_exaone4类提供相关功能
// 用途: 用于处理llm_build_exaone4相关的操作
    // 结构体: llm_build_exaone4
    // 描述: llm_build_exaone4结构体提供相关功能
    // 用途: 用于处理llm_build_exaone4相关的操作
    // 结构体: llm_build_exaone4
    // 描述: llm_build_exaone4结构体提供相关功能
    // 用途: 用于处理llm_build_exaone4相关的操作
    // 结构体: llm_build_exaone4
    // 描述: llm_build_exaone4结构体提供相关功能
    // 用途: 用于处理llm_build_exaone4相关的操作
    // 结构体: llm_build_exaone4
    // 描述: llm_build_exaone4结构体提供相关功能
    // 用途: 用于处理llm_build_exaone4相关的操作
struct llm_build_exaone4 : public llm_graph_context {
    llm_build_exaone4(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_exaone
// 描述: llm_build_exaone类提供相关功能
// 用途: 用于处理llm_build_exaone相关的操作
// 类: llm_build_exaone
// 描述: llm_build_exaone类提供相关功能
// 用途: 用于处理llm_build_exaone相关的操作
    // 结构体: llm_build_exaone
    // 描述: llm_build_exaone结构体提供相关功能
    // 用途: 用于处理llm_build_exaone相关的操作
    // 结构体: llm_build_exaone
    // 描述: llm_build_exaone结构体提供相关功能
    // 用途: 用于处理llm_build_exaone相关的操作
    // 结构体: llm_build_exaone
    // 描述: llm_build_exaone结构体提供相关功能
    // 用途: 用于处理llm_build_exaone相关的操作
    // 结构体: llm_build_exaone
    // 描述: llm_build_exaone结构体提供相关功能
    // 用途: 用于处理llm_build_exaone相关的操作
struct llm_build_exaone : public llm_graph_context {
    llm_build_exaone(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_exaone_moe
// 描述: llm_build_exaone_moe类提供相关功能
// 用途: 用于处理llm_build_exaone_moe相关的操作
// 类: llm_build_exaone_moe
// 描述: llm_build_exaone_moe类提供相关功能
// 用途: 用于处理llm_build_exaone_moe相关的操作
    // 结构体: llm_build_exaone_moe
    // 描述: llm_build_exaone_moe结构体提供相关功能
    // 用途: 用于处理llm_build_exaone_moe相关的操作
    // 结构体: llm_build_exaone_moe
    // 描述: llm_build_exaone_moe结构体提供相关功能
    // 用途: 用于处理llm_build_exaone_moe相关的操作
    // 结构体: llm_build_exaone_moe
    // 描述: llm_build_exaone_moe结构体提供相关功能
    // 用途: 用于处理llm_build_exaone_moe相关的操作
    // 结构体: llm_build_exaone_moe
    // 描述: llm_build_exaone_moe结构体提供相关功能
    // 用途: 用于处理llm_build_exaone_moe相关的操作
struct llm_build_exaone_moe : public llm_graph_context {
    llm_build_exaone_moe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_falcon
// 描述: llm_build_falcon类提供相关功能
// 用途: 用于处理llm_build_falcon相关的操作
// 类: llm_build_falcon
// 描述: llm_build_falcon类提供相关功能
// 用途: 用于处理llm_build_falcon相关的操作
    // 结构体: llm_build_falcon
    // 描述: llm_build_falcon结构体提供相关功能
    // 用途: 用于处理llm_build_falcon相关的操作
    // 结构体: llm_build_falcon
    // 描述: llm_build_falcon结构体提供相关功能
    // 用途: 用于处理llm_build_falcon相关的操作
    // 结构体: llm_build_falcon
    // 描述: llm_build_falcon结构体提供相关功能
    // 用途: 用于处理llm_build_falcon相关的操作
    // 结构体: llm_build_falcon
    // 描述: llm_build_falcon结构体提供相关功能
    // 用途: 用于处理llm_build_falcon相关的操作
struct llm_build_falcon : public llm_graph_context {
    llm_build_falcon(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_falcon_h1
// 描述: llm_build_falcon_h1类提供相关功能
// 用途: 用于处理llm_build_falcon_h1相关的操作
// 类: llm_build_falcon_h1
// 描述: llm_build_falcon_h1类提供相关功能
// 用途: 用于处理llm_build_falcon_h1相关的操作
    // 结构体: llm_build_falcon_h1
    // 描述: llm_build_falcon_h1结构体提供相关功能
    // 用途: 用于处理llm_build_falcon_h1相关的操作
    // 结构体: llm_build_falcon_h1
    // 描述: llm_build_falcon_h1结构体提供相关功能
    // 用途: 用于处理llm_build_falcon_h1相关的操作
    // 结构体: llm_build_falcon_h1
    // 描述: llm_build_falcon_h1结构体提供相关功能
    // 用途: 用于处理llm_build_falcon_h1相关的操作
    // 结构体: llm_build_falcon_h1
    // 描述: llm_build_falcon_h1结构体提供相关功能
    // 用途: 用于处理llm_build_falcon_h1相关的操作
struct llm_build_falcon_h1 : public llm_build_mamba_base {
    llm_build_falcon_h1(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_gemma2_iswa
// 描述: llm_build_gemma2_iswa类提供相关功能
// 用途: 用于处理llm_build_gemma2_iswa相关的操作
// 类: llm_build_gemma2_iswa
// 描述: llm_build_gemma2_iswa类提供相关功能
// 用途: 用于处理llm_build_gemma2_iswa相关的操作
    // 结构体: llm_build_gemma2_iswa
    // 描述: llm_build_gemma2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma2_iswa相关的操作
    // 结构体: llm_build_gemma2_iswa
    // 描述: llm_build_gemma2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma2_iswa相关的操作
    // 结构体: llm_build_gemma2_iswa
    // 描述: llm_build_gemma2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma2_iswa相关的操作
    // 结构体: llm_build_gemma2_iswa
    // 描述: llm_build_gemma2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma2_iswa相关的操作
struct llm_build_gemma2_iswa : public llm_graph_context {
    llm_build_gemma2_iswa(const llama_model & model, const llm_graph_params & params);
};

template <bool iswa>
// 类: llm_build_gemma3
// 描述: llm_build_gemma3类提供相关功能
// 用途: 用于处理llm_build_gemma3相关的操作
// 类: llm_build_gemma3
// 描述: llm_build_gemma3类提供相关功能
// 用途: 用于处理llm_build_gemma3相关的操作
    // 结构体: llm_build_gemma3
    // 描述: llm_build_gemma3结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3相关的操作
    // 结构体: llm_build_gemma3
    // 描述: llm_build_gemma3结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3相关的操作
    // 结构体: llm_build_gemma3
    // 描述: llm_build_gemma3结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3相关的操作
    // 结构体: llm_build_gemma3
    // 描述: llm_build_gemma3结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3相关的操作
struct llm_build_gemma3 : public llm_graph_context {
    llm_build_gemma3(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_gemma3n_iswa
// 描述: llm_build_gemma3n_iswa类提供相关功能
// 用途: 用于处理llm_build_gemma3n_iswa相关的操作
// 类: llm_build_gemma3n_iswa
// 描述: llm_build_gemma3n_iswa类提供相关功能
// 用途: 用于处理llm_build_gemma3n_iswa相关的操作
    // 结构体: llm_build_gemma3n_iswa
    // 描述: llm_build_gemma3n_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3n_iswa相关的操作
    // 结构体: llm_build_gemma3n_iswa
    // 描述: llm_build_gemma3n_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3n_iswa相关的操作
    // 结构体: llm_build_gemma3n_iswa
    // 描述: llm_build_gemma3n_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3n_iswa相关的操作
    // 结构体: llm_build_gemma3n_iswa
    // 描述: llm_build_gemma3n_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_gemma3n_iswa相关的操作
struct llm_build_gemma3n_iswa : public llm_graph_context {
    const llama_model & model;

    const int64_t n_embd_head;
    const int64_t n_embd_altup;
    const int64_t n_altup;
    const int     i_altup_act;
    const int     n_layer_sparsity = 10; // number of layers using activation sparsity
    const float   f_sparsity_std_mul = 1.6448533535003662f; // std_multiplier = normal_dist.icdf(0.95)

    llm_build_gemma3n_iswa(const llama_model & model, const llm_graph_params & params);
    // 函数: calc_magnitude
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: calc_magnitude
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * calc_magnitude(ggml_tensor * x);
    // 函数: view_2d_slice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: view_2d_slice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * view_2d_slice(ggml_tensor * x, int idx);
    // 函数: get_per_layer_inputs
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_per_layer_inputs
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_per_layer_inputs();
    // 函数: project_per_layer_inputs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: project_per_layer_inputs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * project_per_layer_inputs(ggml_tensor * inputs_embeds, ggml_tensor * inp_per_layer);
    // 函数: gaussian_topk
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: gaussian_topk
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * gaussian_topk(ggml_tensor * x);
    // 函数: altup_compute_router_modalities
    // 描述: 计算: 执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: altup_compute_router_modalities
    // 描述: 计算: 执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * altup_compute_router_modalities(ggml_tensor * x, int il);
    // 函数: altup_predict
    // 描述: 预测: 进行预测计算
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: altup_predict
    // 描述: 预测: 进行预测计算
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * altup_predict(ggml_tensor * cur, int il);
    // 函数: laurel
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: laurel
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * laurel(ggml_tensor * cur, int il);
    // 函数: altup_correct
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: altup_correct
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * altup_correct(ggml_tensor * predictions, ggml_tensor * activated, int il);
};

// 类: llm_build_gemma_embedding
// 描述: llm_build_gemma_embedding类提供相关功能
// 用途: 用于处理llm_build_gemma_embedding相关的操作
// 类: llm_build_gemma_embedding
// 描述: llm_build_gemma_embedding类提供相关功能
// 用途: 用于处理llm_build_gemma_embedding相关的操作
    // 结构体: llm_build_gemma_embedding
    // 描述: llm_build_gemma_embedding结构体提供相关功能
    // 用途: 用于处理llm_build_gemma_embedding相关的操作
    // 结构体: llm_build_gemma_embedding
    // 描述: llm_build_gemma_embedding结构体提供相关功能
    // 用途: 用于处理llm_build_gemma_embedding相关的操作
    // 结构体: llm_build_gemma_embedding
    // 描述: llm_build_gemma_embedding结构体提供相关功能
    // 用途: 用于处理llm_build_gemma_embedding相关的操作
    // 结构体: llm_build_gemma_embedding
    // 描述: llm_build_gemma_embedding结构体提供相关功能
    // 用途: 用于处理llm_build_gemma_embedding相关的操作
struct llm_build_gemma_embedding : public llm_graph_context {
    llm_build_gemma_embedding(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_gemma
// 描述: llm_build_gemma类提供相关功能
// 用途: 用于处理llm_build_gemma相关的操作
// 类: llm_build_gemma
// 描述: llm_build_gemma类提供相关功能
// 用途: 用于处理llm_build_gemma相关的操作
    // 结构体: llm_build_gemma
    // 描述: llm_build_gemma结构体提供相关功能
    // 用途: 用于处理llm_build_gemma相关的操作
    // 结构体: llm_build_gemma
    // 描述: llm_build_gemma结构体提供相关功能
    // 用途: 用于处理llm_build_gemma相关的操作
    // 结构体: llm_build_gemma
    // 描述: llm_build_gemma结构体提供相关功能
    // 用途: 用于处理llm_build_gemma相关的操作
    // 结构体: llm_build_gemma
    // 描述: llm_build_gemma结构体提供相关功能
    // 用途: 用于处理llm_build_gemma相关的操作
struct llm_build_gemma : public llm_graph_context {
    llm_build_gemma(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_glm4
// 描述: llm_build_glm4类提供相关功能
// 用途: 用于处理llm_build_glm4相关的操作
// 类: llm_build_glm4
// 描述: llm_build_glm4类提供相关功能
// 用途: 用于处理llm_build_glm4相关的操作
    // 结构体: llm_build_glm4
    // 描述: llm_build_glm4结构体提供相关功能
    // 用途: 用于处理llm_build_glm4相关的操作
    // 结构体: llm_build_glm4
    // 描述: llm_build_glm4结构体提供相关功能
    // 用途: 用于处理llm_build_glm4相关的操作
    // 结构体: llm_build_glm4
    // 描述: llm_build_glm4结构体提供相关功能
    // 用途: 用于处理llm_build_glm4相关的操作
    // 结构体: llm_build_glm4
    // 描述: llm_build_glm4结构体提供相关功能
    // 用途: 用于处理llm_build_glm4相关的操作
struct llm_build_glm4 : public llm_graph_context {
    llm_build_glm4(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_glm4_moe
// 描述: llm_build_glm4_moe类提供相关功能
// 用途: 用于处理llm_build_glm4_moe相关的操作
// 类: llm_build_glm4_moe
// 描述: llm_build_glm4_moe类提供相关功能
// 用途: 用于处理llm_build_glm4_moe相关的操作
    // 结构体: llm_build_glm4_moe
    // 描述: llm_build_glm4_moe结构体提供相关功能
    // 用途: 用于处理llm_build_glm4_moe相关的操作
    // 结构体: llm_build_glm4_moe
    // 描述: llm_build_glm4_moe结构体提供相关功能
    // 用途: 用于处理llm_build_glm4_moe相关的操作
    // 结构体: llm_build_glm4_moe
    // 描述: llm_build_glm4_moe结构体提供相关功能
    // 用途: 用于处理llm_build_glm4_moe相关的操作
    // 结构体: llm_build_glm4_moe
    // 描述: llm_build_glm4_moe结构体提供相关功能
    // 用途: 用于处理llm_build_glm4_moe相关的操作
struct llm_build_glm4_moe : public llm_graph_context {
    llm_build_glm4_moe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_gpt2
// 描述: llm_build_gpt2类提供相关功能
// 用途: 用于处理llm_build_gpt2相关的操作
// 类: llm_build_gpt2
// 描述: llm_build_gpt2类提供相关功能
// 用途: 用于处理llm_build_gpt2相关的操作
    // 结构体: llm_build_gpt2
    // 描述: llm_build_gpt2结构体提供相关功能
    // 用途: 用于处理llm_build_gpt2相关的操作
    // 结构体: llm_build_gpt2
    // 描述: llm_build_gpt2结构体提供相关功能
    // 用途: 用于处理llm_build_gpt2相关的操作
    // 结构体: llm_build_gpt2
    // 描述: llm_build_gpt2结构体提供相关功能
    // 用途: 用于处理llm_build_gpt2相关的操作
    // 结构体: llm_build_gpt2
    // 描述: llm_build_gpt2结构体提供相关功能
    // 用途: 用于处理llm_build_gpt2相关的操作
struct llm_build_gpt2 : public llm_graph_context {
    llm_build_gpt2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_gptneox
// 描述: llm_build_gptneox类提供相关功能
// 用途: 用于处理llm_build_gptneox相关的操作
// 类: llm_build_gptneox
// 描述: llm_build_gptneox类提供相关功能
// 用途: 用于处理llm_build_gptneox相关的操作
    // 结构体: llm_build_gptneox
    // 描述: llm_build_gptneox结构体提供相关功能
    // 用途: 用于处理llm_build_gptneox相关的操作
    // 结构体: llm_build_gptneox
    // 描述: llm_build_gptneox结构体提供相关功能
    // 用途: 用于处理llm_build_gptneox相关的操作
    // 结构体: llm_build_gptneox
    // 描述: llm_build_gptneox结构体提供相关功能
    // 用途: 用于处理llm_build_gptneox相关的操作
    // 结构体: llm_build_gptneox
    // 描述: llm_build_gptneox结构体提供相关功能
    // 用途: 用于处理llm_build_gptneox相关的操作
struct llm_build_gptneox : public llm_graph_context {
    llm_build_gptneox(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_granite
// 描述: llm_build_granite类提供相关功能
// 用途: 用于处理llm_build_granite相关的操作
// 类: llm_build_granite
// 描述: llm_build_granite类提供相关功能
// 用途: 用于处理llm_build_granite相关的操作
    // 结构体: llm_build_granite
    // 描述: llm_build_granite结构体提供相关功能
    // 用途: 用于处理llm_build_granite相关的操作
    // 结构体: llm_build_granite
    // 描述: llm_build_granite结构体提供相关功能
    // 用途: 用于处理llm_build_granite相关的操作
    // 结构体: llm_build_granite
    // 描述: llm_build_granite结构体提供相关功能
    // 用途: 用于处理llm_build_granite相关的操作
    // 结构体: llm_build_granite
    // 描述: llm_build_granite结构体提供相关功能
    // 用途: 用于处理llm_build_granite相关的操作
struct llm_build_granite : public llm_graph_context {
    llm_build_granite(const llama_model & model, const llm_graph_params & params);

private:
    ggml_tensor * build_attention_layer(
              ggml_tensor             * cur,
              ggml_tensor             * inp_pos,
              llm_graph_input_attn_kv * inp_attn,
        const llama_model             & model,
        const int64_t                 n_embd_head,
        const int                     il);

    ggml_tensor * build_layer_ffn(
              ggml_tensor       * cur,
              ggml_tensor       * inpSA,
        const llama_model       & model,
        const int                 il);
};

// 类: llm_build_granite_hybrid
// 描述: llm_build_granite_hybrid类提供相关功能
// 用途: 用于处理llm_build_granite_hybrid相关的操作
// 类: llm_build_granite_hybrid
// 描述: llm_build_granite_hybrid类提供相关功能
// 用途: 用于处理llm_build_granite_hybrid相关的操作
    // 结构体: llm_build_granite_hybrid
    // 描述: llm_build_granite_hybrid结构体提供相关功能
    // 用途: 用于处理llm_build_granite_hybrid相关的操作
    // 结构体: llm_build_granite_hybrid
    // 描述: llm_build_granite_hybrid结构体提供相关功能
    // 用途: 用于处理llm_build_granite_hybrid相关的操作
    // 结构体: llm_build_granite_hybrid
    // 描述: llm_build_granite_hybrid结构体提供相关功能
    // 用途: 用于处理llm_build_granite_hybrid相关的操作
    // 结构体: llm_build_granite_hybrid
    // 描述: llm_build_granite_hybrid结构体提供相关功能
    // 用途: 用于处理llm_build_granite_hybrid相关的操作
struct llm_build_granite_hybrid : public llm_build_mamba_base {
    llm_build_granite_hybrid(const llama_model & model, const llm_graph_params & params);
    // 函数: build_layer_ffn
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_layer_ffn
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * build_layer_ffn(ggml_tensor * cur, ggml_tensor * inpSA, const llama_model & model, const int il);
    ggml_tensor * build_attention_layer(ggml_tensor * cur, ggml_tensor * inp_pos, llm_graph_input_attn_kv * inp_attn,
        const llama_model & model,const int64_t n_embd_head, const int il);
};

// 类: llm_build_grok
// 描述: llm_build_grok类提供相关功能
// 用途: 用于处理llm_build_grok相关的操作
// 类: llm_build_grok
// 描述: llm_build_grok类提供相关功能
// 用途: 用于处理llm_build_grok相关的操作
    // 结构体: llm_build_grok
    // 描述: llm_build_grok结构体提供相关功能
    // 用途: 用于处理llm_build_grok相关的操作
    // 结构体: llm_build_grok
    // 描述: llm_build_grok结构体提供相关功能
    // 用途: 用于处理llm_build_grok相关的操作
    // 结构体: llm_build_grok
    // 描述: llm_build_grok结构体提供相关功能
    // 用途: 用于处理llm_build_grok相关的操作
    // 结构体: llm_build_grok
    // 描述: llm_build_grok结构体提供相关功能
    // 用途: 用于处理llm_build_grok相关的操作
struct llm_build_grok : public llm_graph_context {
    llm_build_grok(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_grovemoe
// 描述: llm_build_grovemoe类提供相关功能
// 用途: 用于处理llm_build_grovemoe相关的操作
// 类: llm_build_grovemoe
// 描述: llm_build_grovemoe类提供相关功能
// 用途: 用于处理llm_build_grovemoe相关的操作
    // 结构体: llm_build_grovemoe
    // 描述: llm_build_grovemoe结构体提供相关功能
    // 用途: 用于处理llm_build_grovemoe相关的操作
    // 结构体: llm_build_grovemoe
    // 描述: llm_build_grovemoe结构体提供相关功能
    // 用途: 用于处理llm_build_grovemoe相关的操作
    // 结构体: llm_build_grovemoe
    // 描述: llm_build_grovemoe结构体提供相关功能
    // 用途: 用于处理llm_build_grovemoe相关的操作
    // 结构体: llm_build_grovemoe
    // 描述: llm_build_grovemoe结构体提供相关功能
    // 用途: 用于处理llm_build_grovemoe相关的操作
struct llm_build_grovemoe : public llm_graph_context {
    llm_build_grovemoe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_hunyuan_dense
// 描述: llm_build_hunyuan_dense类提供相关功能
// 用途: 用于处理llm_build_hunyuan_dense相关的操作
// 类: llm_build_hunyuan_dense
// 描述: llm_build_hunyuan_dense类提供相关功能
// 用途: 用于处理llm_build_hunyuan_dense相关的操作
    // 结构体: llm_build_hunyuan_dense
    // 描述: llm_build_hunyuan_dense结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_dense相关的操作
    // 结构体: llm_build_hunyuan_dense
    // 描述: llm_build_hunyuan_dense结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_dense相关的操作
    // 结构体: llm_build_hunyuan_dense
    // 描述: llm_build_hunyuan_dense结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_dense相关的操作
    // 结构体: llm_build_hunyuan_dense
    // 描述: llm_build_hunyuan_dense结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_dense相关的操作
struct llm_build_hunyuan_dense : public llm_graph_context {
    llm_build_hunyuan_dense(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_hunyuan_moe
// 描述: llm_build_hunyuan_moe类提供相关功能
// 用途: 用于处理llm_build_hunyuan_moe相关的操作
// 类: llm_build_hunyuan_moe
// 描述: llm_build_hunyuan_moe类提供相关功能
// 用途: 用于处理llm_build_hunyuan_moe相关的操作
    // 结构体: llm_build_hunyuan_moe
    // 描述: llm_build_hunyuan_moe结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_moe相关的操作
    // 结构体: llm_build_hunyuan_moe
    // 描述: llm_build_hunyuan_moe结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_moe相关的操作
    // 结构体: llm_build_hunyuan_moe
    // 描述: llm_build_hunyuan_moe结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_moe相关的操作
    // 结构体: llm_build_hunyuan_moe
    // 描述: llm_build_hunyuan_moe结构体提供相关功能
    // 用途: 用于处理llm_build_hunyuan_moe相关的操作
struct llm_build_hunyuan_moe : public llm_graph_context {
    llm_build_hunyuan_moe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_internlm2
// 描述: llm_build_internlm2类提供相关功能
// 用途: 用于处理llm_build_internlm2相关的操作
// 类: llm_build_internlm2
// 描述: llm_build_internlm2类提供相关功能
// 用途: 用于处理llm_build_internlm2相关的操作
    // 结构体: llm_build_internlm2
    // 描述: llm_build_internlm2结构体提供相关功能
    // 用途: 用于处理llm_build_internlm2相关的操作
    // 结构体: llm_build_internlm2
    // 描述: llm_build_internlm2结构体提供相关功能
    // 用途: 用于处理llm_build_internlm2相关的操作
    // 结构体: llm_build_internlm2
    // 描述: llm_build_internlm2结构体提供相关功能
    // 用途: 用于处理llm_build_internlm2相关的操作
    // 结构体: llm_build_internlm2
    // 描述: llm_build_internlm2结构体提供相关功能
    // 用途: 用于处理llm_build_internlm2相关的操作
struct llm_build_internlm2 : public llm_graph_context {
    llm_build_internlm2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_jais
// 描述: llm_build_jais类提供相关功能
// 用途: 用于处理llm_build_jais相关的操作
// 类: llm_build_jais
// 描述: llm_build_jais类提供相关功能
// 用途: 用于处理llm_build_jais相关的操作
    // 结构体: llm_build_jais
    // 描述: llm_build_jais结构体提供相关功能
    // 用途: 用于处理llm_build_jais相关的操作
    // 结构体: llm_build_jais
    // 描述: llm_build_jais结构体提供相关功能
    // 用途: 用于处理llm_build_jais相关的操作
    // 结构体: llm_build_jais
    // 描述: llm_build_jais结构体提供相关功能
    // 用途: 用于处理llm_build_jais相关的操作
    // 结构体: llm_build_jais
    // 描述: llm_build_jais结构体提供相关功能
    // 用途: 用于处理llm_build_jais相关的操作
struct llm_build_jais : public llm_graph_context {
    llm_build_jais(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_jais2
// 描述: llm_build_jais2类提供相关功能
// 用途: 用于处理llm_build_jais2相关的操作
// 类: llm_build_jais2
// 描述: llm_build_jais2类提供相关功能
// 用途: 用于处理llm_build_jais2相关的操作
    // 结构体: llm_build_jais2
    // 描述: llm_build_jais2结构体提供相关功能
    // 用途: 用于处理llm_build_jais2相关的操作
    // 结构体: llm_build_jais2
    // 描述: llm_build_jais2结构体提供相关功能
    // 用途: 用于处理llm_build_jais2相关的操作
    // 结构体: llm_build_jais2
    // 描述: llm_build_jais2结构体提供相关功能
    // 用途: 用于处理llm_build_jais2相关的操作
    // 结构体: llm_build_jais2
    // 描述: llm_build_jais2结构体提供相关功能
    // 用途: 用于处理llm_build_jais2相关的操作
struct llm_build_jais2 : public llm_graph_context {
    llm_build_jais2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_jamba
// 描述: llm_build_jamba类提供相关功能
// 用途: 用于处理llm_build_jamba相关的操作
// 类: llm_build_jamba
// 描述: llm_build_jamba类提供相关功能
// 用途: 用于处理llm_build_jamba相关的操作
    // 结构体: llm_build_jamba
    // 描述: llm_build_jamba结构体提供相关功能
    // 用途: 用于处理llm_build_jamba相关的操作
    // 结构体: llm_build_jamba
    // 描述: llm_build_jamba结构体提供相关功能
    // 用途: 用于处理llm_build_jamba相关的操作
    // 结构体: llm_build_jamba
    // 描述: llm_build_jamba结构体提供相关功能
    // 用途: 用于处理llm_build_jamba相关的操作
    // 结构体: llm_build_jamba
    // 描述: llm_build_jamba结构体提供相关功能
    // 用途: 用于处理llm_build_jamba相关的操作
struct llm_build_jamba : public llm_build_mamba_base {
    llm_build_jamba(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_kimi_linear
// 描述: llm_build_kimi_linear类提供相关功能
// 用途: 用于处理llm_build_kimi_linear相关的操作
// 类: llm_build_kimi_linear
// 描述: llm_build_kimi_linear类提供相关功能
// 用途: 用于处理llm_build_kimi_linear相关的操作
    // 结构体: llm_build_kimi_linear
    // 描述: llm_build_kimi_linear结构体提供相关功能
    // 用途: 用于处理llm_build_kimi_linear相关的操作
    // 结构体: llm_build_kimi_linear
    // 描述: llm_build_kimi_linear结构体提供相关功能
    // 用途: 用于处理llm_build_kimi_linear相关的操作
    // 结构体: llm_build_kimi_linear
    // 描述: llm_build_kimi_linear结构体提供相关功能
    // 用途: 用于处理llm_build_kimi_linear相关的操作
    // 结构体: llm_build_kimi_linear
    // 描述: llm_build_kimi_linear结构体提供相关功能
    // 用途: 用于处理llm_build_kimi_linear相关的操作
struct llm_build_kimi_linear : public llm_build_delta_net_base {
    llm_build_kimi_linear(const llama_model & model, const llm_graph_params & params);

    std::pair<ggml_tensor *, ggml_tensor *> build_kda_autoregressive(
                ggml_tensor * q,
                ggml_tensor * k,
                ggml_tensor * v,
                ggml_tensor * gk,
                ggml_tensor * beta,
                ggml_tensor * state,
                        int   il);

    std::pair<ggml_tensor *, ggml_tensor *> build_kda_chunking(
                ggml_tensor * q,
                ggml_tensor * k,
                ggml_tensor * v,
                ggml_tensor * gk,
                ggml_tensor * beta,
                ggml_tensor * state,
                ggml_tensor * causal_mask,
                ggml_tensor * identity,
                ggml_tensor * diag_mask,
                        int   il);

    const llama_model & model;
};

template <bool iswa>
// 类: llm_build_lfm2
// 描述: llm_build_lfm2类提供相关功能
// 用途: 用于处理llm_build_lfm2相关的操作
// 类: llm_build_lfm2
// 描述: llm_build_lfm2类提供相关功能
// 用途: 用于处理llm_build_lfm2相关的操作
    // 结构体: llm_build_lfm2
    // 描述: llm_build_lfm2结构体提供相关功能
    // 用途: 用于处理llm_build_lfm2相关的操作
    // 结构体: llm_build_lfm2
    // 描述: llm_build_lfm2结构体提供相关功能
    // 用途: 用于处理llm_build_lfm2相关的操作
    // 结构体: llm_build_lfm2
    // 描述: llm_build_lfm2结构体提供相关功能
    // 用途: 用于处理llm_build_lfm2相关的操作
    // 结构体: llm_build_lfm2
    // 描述: llm_build_lfm2结构体提供相关功能
    // 用途: 用于处理llm_build_lfm2相关的操作
struct llm_build_lfm2 : public llm_graph_context {
    llm_build_lfm2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_llada
// 描述: llm_build_llada类提供相关功能
// 用途: 用于处理llm_build_llada相关的操作
// 类: llm_build_llada
// 描述: llm_build_llada类提供相关功能
// 用途: 用于处理llm_build_llada相关的操作
    // 结构体: llm_build_llada
    // 描述: llm_build_llada结构体提供相关功能
    // 用途: 用于处理llm_build_llada相关的操作
    // 结构体: llm_build_llada
    // 描述: llm_build_llada结构体提供相关功能
    // 用途: 用于处理llm_build_llada相关的操作
    // 结构体: llm_build_llada
    // 描述: llm_build_llada结构体提供相关功能
    // 用途: 用于处理llm_build_llada相关的操作
    // 结构体: llm_build_llada
    // 描述: llm_build_llada结构体提供相关功能
    // 用途: 用于处理llm_build_llada相关的操作
struct llm_build_llada : public llm_graph_context {
    llm_build_llada(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_llada_moe
// 描述: llm_build_llada_moe类提供相关功能
// 用途: 用于处理llm_build_llada_moe相关的操作
// 类: llm_build_llada_moe
// 描述: llm_build_llada_moe类提供相关功能
// 用途: 用于处理llm_build_llada_moe相关的操作
    // 结构体: llm_build_llada_moe
    // 描述: llm_build_llada_moe结构体提供相关功能
    // 用途: 用于处理llm_build_llada_moe相关的操作
    // 结构体: llm_build_llada_moe
    // 描述: llm_build_llada_moe结构体提供相关功能
    // 用途: 用于处理llm_build_llada_moe相关的操作
    // 结构体: llm_build_llada_moe
    // 描述: llm_build_llada_moe结构体提供相关功能
    // 用途: 用于处理llm_build_llada_moe相关的操作
    // 结构体: llm_build_llada_moe
    // 描述: llm_build_llada_moe结构体提供相关功能
    // 用途: 用于处理llm_build_llada_moe相关的操作
struct llm_build_llada_moe : public llm_graph_context {
    llm_build_llada_moe(const llama_model & model, const llm_graph_params & params);
};

template <bool embed>
// 类: llm_build_llama
// 描述: llm_build_llama类提供相关功能
// 用途: 用于处理llm_build_llama相关的操作
// 类: llm_build_llama
// 描述: llm_build_llama类提供相关功能
// 用途: 用于处理llm_build_llama相关的操作
    // 结构体: llm_build_llama
    // 描述: llm_build_llama结构体提供相关功能
    // 用途: 用于处理llm_build_llama相关的操作
    // 结构体: llm_build_llama
    // 描述: llm_build_llama结构体提供相关功能
    // 用途: 用于处理llm_build_llama相关的操作
    // 结构体: llm_build_llama
    // 描述: llm_build_llama结构体提供相关功能
    // 用途: 用于处理llm_build_llama相关的操作
    // 结构体: llm_build_llama
    // 描述: llm_build_llama结构体提供相关功能
    // 用途: 用于处理llm_build_llama相关的操作
struct llm_build_llama : public llm_graph_context {
    llm_build_llama(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_llama_iswa
// 描述: llm_build_llama_iswa类提供相关功能
// 用途: 用于处理llm_build_llama_iswa相关的操作
// 类: llm_build_llama_iswa
// 描述: llm_build_llama_iswa类提供相关功能
// 用途: 用于处理llm_build_llama_iswa相关的操作
    // 结构体: llm_build_llama_iswa
    // 描述: llm_build_llama_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_llama_iswa相关的操作
    // 结构体: llm_build_llama_iswa
    // 描述: llm_build_llama_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_llama_iswa相关的操作
    // 结构体: llm_build_llama_iswa
    // 描述: llm_build_llama_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_llama_iswa相关的操作
    // 结构体: llm_build_llama_iswa
    // 描述: llm_build_llama_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_llama_iswa相关的操作
struct llm_build_llama_iswa : public llm_graph_context {
    llm_build_llama_iswa(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_maincoder
// 描述: llm_build_maincoder类提供相关功能
// 用途: 用于处理llm_build_maincoder相关的操作
// 类: llm_build_maincoder
// 描述: llm_build_maincoder类提供相关功能
// 用途: 用于处理llm_build_maincoder相关的操作
    // 结构体: llm_build_maincoder
    // 描述: llm_build_maincoder结构体提供相关功能
    // 用途: 用于处理llm_build_maincoder相关的操作
    // 结构体: llm_build_maincoder
    // 描述: llm_build_maincoder结构体提供相关功能
    // 用途: 用于处理llm_build_maincoder相关的操作
    // 结构体: llm_build_maincoder
    // 描述: llm_build_maincoder结构体提供相关功能
    // 用途: 用于处理llm_build_maincoder相关的操作
    // 结构体: llm_build_maincoder
    // 描述: llm_build_maincoder结构体提供相关功能
    // 用途: 用于处理llm_build_maincoder相关的操作
struct llm_build_maincoder : public llm_graph_context {
    llm_build_maincoder(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_mamba
// 描述: llm_build_mamba类提供相关功能
// 用途: 用于处理llm_build_mamba相关的操作
// 类: llm_build_mamba
// 描述: llm_build_mamba类提供相关功能
// 用途: 用于处理llm_build_mamba相关的操作
    // 结构体: llm_build_mamba
    // 描述: llm_build_mamba结构体提供相关功能
    // 用途: 用于处理llm_build_mamba相关的操作
    // 结构体: llm_build_mamba
    // 描述: llm_build_mamba结构体提供相关功能
    // 用途: 用于处理llm_build_mamba相关的操作
    // 结构体: llm_build_mamba
    // 描述: llm_build_mamba结构体提供相关功能
    // 用途: 用于处理llm_build_mamba相关的操作
    // 结构体: llm_build_mamba
    // 描述: llm_build_mamba结构体提供相关功能
    // 用途: 用于处理llm_build_mamba相关的操作
struct llm_build_mamba : public llm_build_mamba_base {
    llm_build_mamba(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_mimo2_iswa
// 描述: llm_build_mimo2_iswa类提供相关功能
// 用途: 用于处理llm_build_mimo2_iswa相关的操作
// 类: llm_build_mimo2_iswa
// 描述: llm_build_mimo2_iswa类提供相关功能
// 用途: 用于处理llm_build_mimo2_iswa相关的操作
    // 结构体: llm_build_mimo2_iswa
    // 描述: llm_build_mimo2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_mimo2_iswa相关的操作
    // 结构体: llm_build_mimo2_iswa
    // 描述: llm_build_mimo2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_mimo2_iswa相关的操作
    // 结构体: llm_build_mimo2_iswa
    // 描述: llm_build_mimo2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_mimo2_iswa相关的操作
    // 结构体: llm_build_mimo2_iswa
    // 描述: llm_build_mimo2_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_mimo2_iswa相关的操作
struct llm_build_mimo2_iswa : public llm_graph_context {
    llm_build_mimo2_iswa(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_minicpm3
// 描述: llm_build_minicpm3类提供相关功能
// 用途: 用于处理llm_build_minicpm3相关的操作
// 类: llm_build_minicpm3
// 描述: llm_build_minicpm3类提供相关功能
// 用途: 用于处理llm_build_minicpm3相关的操作
    // 结构体: llm_build_minicpm3
    // 描述: llm_build_minicpm3结构体提供相关功能
    // 用途: 用于处理llm_build_minicpm3相关的操作
    // 结构体: llm_build_minicpm3
    // 描述: llm_build_minicpm3结构体提供相关功能
    // 用途: 用于处理llm_build_minicpm3相关的操作
    // 结构体: llm_build_minicpm3
    // 描述: llm_build_minicpm3结构体提供相关功能
    // 用途: 用于处理llm_build_minicpm3相关的操作
    // 结构体: llm_build_minicpm3
    // 描述: llm_build_minicpm3结构体提供相关功能
    // 用途: 用于处理llm_build_minicpm3相关的操作
struct llm_build_minicpm3 : public llm_graph_context {
    llm_build_minicpm3(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_minimax_m2
// 描述: llm_build_minimax_m2类提供相关功能
// 用途: 用于处理llm_build_minimax_m2相关的操作
// 类: llm_build_minimax_m2
// 描述: llm_build_minimax_m2类提供相关功能
// 用途: 用于处理llm_build_minimax_m2相关的操作
    // 结构体: llm_build_minimax_m2
    // 描述: llm_build_minimax_m2结构体提供相关功能
    // 用途: 用于处理llm_build_minimax_m2相关的操作
    // 结构体: llm_build_minimax_m2
    // 描述: llm_build_minimax_m2结构体提供相关功能
    // 用途: 用于处理llm_build_minimax_m2相关的操作
    // 结构体: llm_build_minimax_m2
    // 描述: llm_build_minimax_m2结构体提供相关功能
    // 用途: 用于处理llm_build_minimax_m2相关的操作
    // 结构体: llm_build_minimax_m2
    // 描述: llm_build_minimax_m2结构体提供相关功能
    // 用途: 用于处理llm_build_minimax_m2相关的操作
struct llm_build_minimax_m2 : public llm_graph_context {
    llm_build_minimax_m2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_mistral3
// 描述: llm_build_mistral3类提供相关功能
// 用途: 用于处理llm_build_mistral3相关的操作
// 类: llm_build_mistral3
// 描述: llm_build_mistral3类提供相关功能
// 用途: 用于处理llm_build_mistral3相关的操作
    // 结构体: llm_build_mistral3
    // 描述: llm_build_mistral3结构体提供相关功能
    // 用途: 用于处理llm_build_mistral3相关的操作
    // 结构体: llm_build_mistral3
    // 描述: llm_build_mistral3结构体提供相关功能
    // 用途: 用于处理llm_build_mistral3相关的操作
    // 结构体: llm_build_mistral3
    // 描述: llm_build_mistral3结构体提供相关功能
    // 用途: 用于处理llm_build_mistral3相关的操作
    // 结构体: llm_build_mistral3
    // 描述: llm_build_mistral3结构体提供相关功能
    // 用途: 用于处理llm_build_mistral3相关的操作
struct llm_build_mistral3 : public llm_graph_context {
    llm_build_mistral3(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_modern_bert
// 描述: llm_build_modern_bert类提供相关功能
// 用途: 用于处理llm_build_modern_bert相关的操作
// 类: llm_build_modern_bert
// 描述: llm_build_modern_bert类提供相关功能
// 用途: 用于处理llm_build_modern_bert相关的操作
    // 结构体: llm_build_modern_bert
    // 描述: llm_build_modern_bert结构体提供相关功能
    // 用途: 用于处理llm_build_modern_bert相关的操作
    // 结构体: llm_build_modern_bert
    // 描述: llm_build_modern_bert结构体提供相关功能
    // 用途: 用于处理llm_build_modern_bert相关的操作
    // 结构体: llm_build_modern_bert
    // 描述: llm_build_modern_bert结构体提供相关功能
    // 用途: 用于处理llm_build_modern_bert相关的操作
    // 结构体: llm_build_modern_bert
    // 描述: llm_build_modern_bert结构体提供相关功能
    // 用途: 用于处理llm_build_modern_bert相关的操作
struct llm_build_modern_bert : public llm_graph_context {
    llm_build_modern_bert(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_mpt
// 描述: llm_build_mpt类提供相关功能
// 用途: 用于处理llm_build_mpt相关的操作
// 类: llm_build_mpt
// 描述: llm_build_mpt类提供相关功能
// 用途: 用于处理llm_build_mpt相关的操作
    // 结构体: llm_build_mpt
    // 描述: llm_build_mpt结构体提供相关功能
    // 用途: 用于处理llm_build_mpt相关的操作
    // 结构体: llm_build_mpt
    // 描述: llm_build_mpt结构体提供相关功能
    // 用途: 用于处理llm_build_mpt相关的操作
    // 结构体: llm_build_mpt
    // 描述: llm_build_mpt结构体提供相关功能
    // 用途: 用于处理llm_build_mpt相关的操作
    // 结构体: llm_build_mpt
    // 描述: llm_build_mpt结构体提供相关功能
    // 用途: 用于处理llm_build_mpt相关的操作
struct llm_build_mpt : public llm_graph_context {
    llm_build_mpt(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_nemotron
// 描述: llm_build_nemotron类提供相关功能
// 用途: 用于处理llm_build_nemotron相关的操作
// 类: llm_build_nemotron
// 描述: llm_build_nemotron类提供相关功能
// 用途: 用于处理llm_build_nemotron相关的操作
    // 结构体: llm_build_nemotron
    // 描述: llm_build_nemotron结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron相关的操作
    // 结构体: llm_build_nemotron
    // 描述: llm_build_nemotron结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron相关的操作
    // 结构体: llm_build_nemotron
    // 描述: llm_build_nemotron结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron相关的操作
    // 结构体: llm_build_nemotron
    // 描述: llm_build_nemotron结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron相关的操作
struct llm_build_nemotron : public llm_graph_context {
    llm_build_nemotron(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_nemotron_h
// 描述: llm_build_nemotron_h类提供相关功能
// 用途: 用于处理llm_build_nemotron_h相关的操作
// 类: llm_build_nemotron_h
// 描述: llm_build_nemotron_h类提供相关功能
// 用途: 用于处理llm_build_nemotron_h相关的操作
    // 结构体: llm_build_nemotron_h
    // 描述: llm_build_nemotron_h结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron_h相关的操作
    // 结构体: llm_build_nemotron_h
    // 描述: llm_build_nemotron_h结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron_h相关的操作
    // 结构体: llm_build_nemotron_h
    // 描述: llm_build_nemotron_h结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron_h相关的操作
    // 结构体: llm_build_nemotron_h
    // 描述: llm_build_nemotron_h结构体提供相关功能
    // 用途: 用于处理llm_build_nemotron_h相关的操作
struct llm_build_nemotron_h : public llm_build_mamba_base {
    llm_build_nemotron_h(const llama_model & model, const llm_graph_params & params);
    // 函数: build_ffn_layer
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_ffn_layer
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * build_ffn_layer(ggml_tensor * cur, const llama_model & model, int il);
    ggml_tensor * build_attention_layer(ggml_tensor * cur, llm_graph_input_attn_kv * inp_attn,
        const llama_model & model, int64_t n_embd_head, int il);
};

// 类: llm_build_neo_bert
// 描述: llm_build_neo_bert类提供相关功能
// 用途: 用于处理llm_build_neo_bert相关的操作
// 类: llm_build_neo_bert
// 描述: llm_build_neo_bert类提供相关功能
// 用途: 用于处理llm_build_neo_bert相关的操作
    // 结构体: llm_build_neo_bert
    // 描述: llm_build_neo_bert结构体提供相关功能
    // 用途: 用于处理llm_build_neo_bert相关的操作
    // 结构体: llm_build_neo_bert
    // 描述: llm_build_neo_bert结构体提供相关功能
    // 用途: 用于处理llm_build_neo_bert相关的操作
    // 结构体: llm_build_neo_bert
    // 描述: llm_build_neo_bert结构体提供相关功能
    // 用途: 用于处理llm_build_neo_bert相关的操作
    // 结构体: llm_build_neo_bert
    // 描述: llm_build_neo_bert结构体提供相关功能
    // 用途: 用于处理llm_build_neo_bert相关的操作
struct llm_build_neo_bert : public llm_graph_context {
    llm_build_neo_bert(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_eurobert
// 描述: llm_build_eurobert类提供相关功能
// 用途: 用于处理llm_build_eurobert相关的操作
// 类: llm_build_eurobert
// 描述: llm_build_eurobert类提供相关功能
// 用途: 用于处理llm_build_eurobert相关的操作
    // 结构体: llm_build_eurobert
    // 描述: llm_build_eurobert结构体提供相关功能
    // 用途: 用于处理llm_build_eurobert相关的操作
    // 结构体: llm_build_eurobert
    // 描述: llm_build_eurobert结构体提供相关功能
    // 用途: 用于处理llm_build_eurobert相关的操作
    // 结构体: llm_build_eurobert
    // 描述: llm_build_eurobert结构体提供相关功能
    // 用途: 用于处理llm_build_eurobert相关的操作
    // 结构体: llm_build_eurobert
    // 描述: llm_build_eurobert结构体提供相关功能
    // 用途: 用于处理llm_build_eurobert相关的操作
struct llm_build_eurobert : public llm_graph_context {
    llm_build_eurobert(const llama_model & model, const llm_graph_params & params);
};

template <bool iswa>
// 类: llm_build_olmo2
// 描述: llm_build_olmo2类提供相关功能
// 用途: 用于处理llm_build_olmo2相关的操作
// 类: llm_build_olmo2
// 描述: llm_build_olmo2类提供相关功能
// 用途: 用于处理llm_build_olmo2相关的操作
    // 结构体: llm_build_olmo2
    // 描述: llm_build_olmo2结构体提供相关功能
    // 用途: 用于处理llm_build_olmo2相关的操作
    // 结构体: llm_build_olmo2
    // 描述: llm_build_olmo2结构体提供相关功能
    // 用途: 用于处理llm_build_olmo2相关的操作
    // 结构体: llm_build_olmo2
    // 描述: llm_build_olmo2结构体提供相关功能
    // 用途: 用于处理llm_build_olmo2相关的操作
    // 结构体: llm_build_olmo2
    // 描述: llm_build_olmo2结构体提供相关功能
    // 用途: 用于处理llm_build_olmo2相关的操作
struct llm_build_olmo2 : public llm_graph_context {
    llm_build_olmo2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_olmoe
// 描述: llm_build_olmoe类提供相关功能
// 用途: 用于处理llm_build_olmoe相关的操作
// 类: llm_build_olmoe
// 描述: llm_build_olmoe类提供相关功能
// 用途: 用于处理llm_build_olmoe相关的操作
    // 结构体: llm_build_olmoe
    // 描述: llm_build_olmoe结构体提供相关功能
    // 用途: 用于处理llm_build_olmoe相关的操作
    // 结构体: llm_build_olmoe
    // 描述: llm_build_olmoe结构体提供相关功能
    // 用途: 用于处理llm_build_olmoe相关的操作
    // 结构体: llm_build_olmoe
    // 描述: llm_build_olmoe结构体提供相关功能
    // 用途: 用于处理llm_build_olmoe相关的操作
    // 结构体: llm_build_olmoe
    // 描述: llm_build_olmoe结构体提供相关功能
    // 用途: 用于处理llm_build_olmoe相关的操作
struct llm_build_olmoe : public llm_graph_context {
    llm_build_olmoe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_olmo
// 描述: llm_build_olmo类提供相关功能
// 用途: 用于处理llm_build_olmo相关的操作
// 类: llm_build_olmo
// 描述: llm_build_olmo类提供相关功能
// 用途: 用于处理llm_build_olmo相关的操作
    // 结构体: llm_build_olmo
    // 描述: llm_build_olmo结构体提供相关功能
    // 用途: 用于处理llm_build_olmo相关的操作
    // 结构体: llm_build_olmo
    // 描述: llm_build_olmo结构体提供相关功能
    // 用途: 用于处理llm_build_olmo相关的操作
    // 结构体: llm_build_olmo
    // 描述: llm_build_olmo结构体提供相关功能
    // 用途: 用于处理llm_build_olmo相关的操作
    // 结构体: llm_build_olmo
    // 描述: llm_build_olmo结构体提供相关功能
    // 用途: 用于处理llm_build_olmo相关的操作
struct llm_build_olmo : public llm_graph_context {
    llm_build_olmo(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_openai_moe_iswa
// 描述: llm_build_openai_moe_iswa类提供相关功能
// 用途: 用于处理llm_build_openai_moe_iswa相关的操作
// 类: llm_build_openai_moe_iswa
// 描述: llm_build_openai_moe_iswa类提供相关功能
// 用途: 用于处理llm_build_openai_moe_iswa相关的操作
    // 结构体: llm_build_openai_moe_iswa
    // 描述: llm_build_openai_moe_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_openai_moe_iswa相关的操作
    // 结构体: llm_build_openai_moe_iswa
    // 描述: llm_build_openai_moe_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_openai_moe_iswa相关的操作
    // 结构体: llm_build_openai_moe_iswa
    // 描述: llm_build_openai_moe_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_openai_moe_iswa相关的操作
    // 结构体: llm_build_openai_moe_iswa
    // 描述: llm_build_openai_moe_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_openai_moe_iswa相关的操作
struct llm_build_openai_moe_iswa : public llm_graph_context {
    llm_build_openai_moe_iswa(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_openelm
// 描述: llm_build_openelm类提供相关功能
// 用途: 用于处理llm_build_openelm相关的操作
// 类: llm_build_openelm
// 描述: llm_build_openelm类提供相关功能
// 用途: 用于处理llm_build_openelm相关的操作
    // 结构体: llm_build_openelm
    // 描述: llm_build_openelm结构体提供相关功能
    // 用途: 用于处理llm_build_openelm相关的操作
    // 结构体: llm_build_openelm
    // 描述: llm_build_openelm结构体提供相关功能
    // 用途: 用于处理llm_build_openelm相关的操作
    // 结构体: llm_build_openelm
    // 描述: llm_build_openelm结构体提供相关功能
    // 用途: 用于处理llm_build_openelm相关的操作
    // 结构体: llm_build_openelm
    // 描述: llm_build_openelm结构体提供相关功能
    // 用途: 用于处理llm_build_openelm相关的操作
struct llm_build_openelm : public llm_graph_context {
    llm_build_openelm(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_orion
// 描述: llm_build_orion类提供相关功能
// 用途: 用于处理llm_build_orion相关的操作
// 类: llm_build_orion
// 描述: llm_build_orion类提供相关功能
// 用途: 用于处理llm_build_orion相关的操作
    // 结构体: llm_build_orion
    // 描述: llm_build_orion结构体提供相关功能
    // 用途: 用于处理llm_build_orion相关的操作
    // 结构体: llm_build_orion
    // 描述: llm_build_orion结构体提供相关功能
    // 用途: 用于处理llm_build_orion相关的操作
    // 结构体: llm_build_orion
    // 描述: llm_build_orion结构体提供相关功能
    // 用途: 用于处理llm_build_orion相关的操作
    // 结构体: llm_build_orion
    // 描述: llm_build_orion结构体提供相关功能
    // 用途: 用于处理llm_build_orion相关的操作
struct llm_build_orion : public llm_graph_context {
    llm_build_orion(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_pangu_embedded
// 描述: llm_build_pangu_embedded类提供相关功能
// 用途: 用于处理llm_build_pangu_embedded相关的操作
// 类: llm_build_pangu_embedded
// 描述: llm_build_pangu_embedded类提供相关功能
// 用途: 用于处理llm_build_pangu_embedded相关的操作
    // 结构体: llm_build_pangu_embedded
    // 描述: llm_build_pangu_embedded结构体提供相关功能
    // 用途: 用于处理llm_build_pangu_embedded相关的操作
    // 结构体: llm_build_pangu_embedded
    // 描述: llm_build_pangu_embedded结构体提供相关功能
    // 用途: 用于处理llm_build_pangu_embedded相关的操作
    // 结构体: llm_build_pangu_embedded
    // 描述: llm_build_pangu_embedded结构体提供相关功能
    // 用途: 用于处理llm_build_pangu_embedded相关的操作
    // 结构体: llm_build_pangu_embedded
    // 描述: llm_build_pangu_embedded结构体提供相关功能
    // 用途: 用于处理llm_build_pangu_embedded相关的操作
struct llm_build_pangu_embedded : public llm_graph_context {
    llm_build_pangu_embedded(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_phi2
// 描述: llm_build_phi2类提供相关功能
// 用途: 用于处理llm_build_phi2相关的操作
// 类: llm_build_phi2
// 描述: llm_build_phi2类提供相关功能
// 用途: 用于处理llm_build_phi2相关的操作
    // 结构体: llm_build_phi2
    // 描述: llm_build_phi2结构体提供相关功能
    // 用途: 用于处理llm_build_phi2相关的操作
    // 结构体: llm_build_phi2
    // 描述: llm_build_phi2结构体提供相关功能
    // 用途: 用于处理llm_build_phi2相关的操作
    // 结构体: llm_build_phi2
    // 描述: llm_build_phi2结构体提供相关功能
    // 用途: 用于处理llm_build_phi2相关的操作
    // 结构体: llm_build_phi2
    // 描述: llm_build_phi2结构体提供相关功能
    // 用途: 用于处理llm_build_phi2相关的操作
struct llm_build_phi2 : public llm_graph_context {
    llm_build_phi2(const llama_model & model, const llm_graph_params & params);
};

template<bool iswa>
// 类: llm_build_phi3
// 描述: llm_build_phi3类提供相关功能
// 用途: 用于处理llm_build_phi3相关的操作
// 类: llm_build_phi3
// 描述: llm_build_phi3类提供相关功能
// 用途: 用于处理llm_build_phi3相关的操作
    // 结构体: llm_build_phi3
    // 描述: llm_build_phi3结构体提供相关功能
    // 用途: 用于处理llm_build_phi3相关的操作
    // 结构体: llm_build_phi3
    // 描述: llm_build_phi3结构体提供相关功能
    // 用途: 用于处理llm_build_phi3相关的操作
    // 结构体: llm_build_phi3
    // 描述: llm_build_phi3结构体提供相关功能
    // 用途: 用于处理llm_build_phi3相关的操作
    // 结构体: llm_build_phi3
    // 描述: llm_build_phi3结构体提供相关功能
    // 用途: 用于处理llm_build_phi3相关的操作
struct llm_build_phi3 : public llm_graph_context {
    llm_build_phi3(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_plamo2
// 描述: llm_build_plamo2类提供相关功能
// 用途: 用于处理llm_build_plamo2相关的操作
// 类: llm_build_plamo2
// 描述: llm_build_plamo2类提供相关功能
// 用途: 用于处理llm_build_plamo2相关的操作
    // 结构体: llm_build_plamo2
    // 描述: llm_build_plamo2结构体提供相关功能
    // 用途: 用于处理llm_build_plamo2相关的操作
    // 结构体: llm_build_plamo2
    // 描述: llm_build_plamo2结构体提供相关功能
    // 用途: 用于处理llm_build_plamo2相关的操作
    // 结构体: llm_build_plamo2
    // 描述: llm_build_plamo2结构体提供相关功能
    // 用途: 用于处理llm_build_plamo2相关的操作
    // 结构体: llm_build_plamo2
    // 描述: llm_build_plamo2结构体提供相关功能
    // 用途: 用于处理llm_build_plamo2相关的操作
struct llm_build_plamo2 : public llm_build_mamba_base {
    llm_build_plamo2(const llama_model & model, const llm_graph_params & params);
    private:
        // 函数: build_plamo2_mamba_layer
        // 描述: 构建: 构建数据结构或对象
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: build_plamo2_mamba_layer
        // 描述: 构建: 构建数据结构或对象
        // 参数: 无参数
        // 返回: 无返回值
        ggml_tensor * build_plamo2_mamba_layer(llm_graph_input_rs * inp, ggml_tensor * cur, const llama_model & model, const llama_ubatch & ubatch, int il);
        ggml_tensor * build_plamo2_attn_layer(llm_graph_input_attn_kv * inp, ggml_tensor * inp_pos, ggml_tensor * cur,
                                                const llama_model & model, int il);
};

// 类: llm_build_plamo
// 描述: llm_build_plamo类提供相关功能
// 用途: 用于处理llm_build_plamo相关的操作
// 类: llm_build_plamo
// 描述: llm_build_plamo类提供相关功能
// 用途: 用于处理llm_build_plamo相关的操作
    // 结构体: llm_build_plamo
    // 描述: llm_build_plamo结构体提供相关功能
    // 用途: 用于处理llm_build_plamo相关的操作
    // 结构体: llm_build_plamo
    // 描述: llm_build_plamo结构体提供相关功能
    // 用途: 用于处理llm_build_plamo相关的操作
    // 结构体: llm_build_plamo
    // 描述: llm_build_plamo结构体提供相关功能
    // 用途: 用于处理llm_build_plamo相关的操作
    // 结构体: llm_build_plamo
    // 描述: llm_build_plamo结构体提供相关功能
    // 用途: 用于处理llm_build_plamo相关的操作
struct llm_build_plamo : public llm_graph_context {
    llm_build_plamo(const llama_model & model, const llm_graph_params & params);
};

template <bool iswa>
// 类: llm_build_plamo3
// 描述: llm_build_plamo3类提供相关功能
// 用途: 用于处理llm_build_plamo3相关的操作
// 类: llm_build_plamo3
// 描述: llm_build_plamo3类提供相关功能
// 用途: 用于处理llm_build_plamo3相关的操作
    // 结构体: llm_build_plamo3
    // 描述: llm_build_plamo3结构体提供相关功能
    // 用途: 用于处理llm_build_plamo3相关的操作
    // 结构体: llm_build_plamo3
    // 描述: llm_build_plamo3结构体提供相关功能
    // 用途: 用于处理llm_build_plamo3相关的操作
    // 结构体: llm_build_plamo3
    // 描述: llm_build_plamo3结构体提供相关功能
    // 用途: 用于处理llm_build_plamo3相关的操作
    // 结构体: llm_build_plamo3
    // 描述: llm_build_plamo3结构体提供相关功能
    // 用途: 用于处理llm_build_plamo3相关的操作
struct llm_build_plamo3 : public llm_graph_context {
    llm_build_plamo3(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_plm
// 描述: llm_build_plm类提供相关功能
// 用途: 用于处理llm_build_plm相关的操作
// 类: llm_build_plm
// 描述: llm_build_plm类提供相关功能
// 用途: 用于处理llm_build_plm相关的操作
    // 结构体: llm_build_plm
    // 描述: llm_build_plm结构体提供相关功能
    // 用途: 用于处理llm_build_plm相关的操作
    // 结构体: llm_build_plm
    // 描述: llm_build_plm结构体提供相关功能
    // 用途: 用于处理llm_build_plm相关的操作
    // 结构体: llm_build_plm
    // 描述: llm_build_plm结构体提供相关功能
    // 用途: 用于处理llm_build_plm相关的操作
    // 结构体: llm_build_plm
    // 描述: llm_build_plm结构体提供相关功能
    // 用途: 用于处理llm_build_plm相关的操作
struct llm_build_plm : public llm_graph_context {
    llm_build_plm(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen2
// 描述: llm_build_qwen2类提供相关功能
// 用途: 用于处理llm_build_qwen2相关的操作
// 类: llm_build_qwen2
// 描述: llm_build_qwen2类提供相关功能
// 用途: 用于处理llm_build_qwen2相关的操作
    // 结构体: llm_build_qwen2
    // 描述: llm_build_qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2相关的操作
    // 结构体: llm_build_qwen2
    // 描述: llm_build_qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2相关的操作
    // 结构体: llm_build_qwen2
    // 描述: llm_build_qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2相关的操作
    // 结构体: llm_build_qwen2
    // 描述: llm_build_qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2相关的操作
struct llm_build_qwen2 : public llm_graph_context {
    llm_build_qwen2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen2moe
// 描述: llm_build_qwen2moe类提供相关功能
// 用途: 用于处理llm_build_qwen2moe相关的操作
// 类: llm_build_qwen2moe
// 描述: llm_build_qwen2moe类提供相关功能
// 用途: 用于处理llm_build_qwen2moe相关的操作
    // 结构体: llm_build_qwen2moe
    // 描述: llm_build_qwen2moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2moe相关的操作
    // 结构体: llm_build_qwen2moe
    // 描述: llm_build_qwen2moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2moe相关的操作
    // 结构体: llm_build_qwen2moe
    // 描述: llm_build_qwen2moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2moe相关的操作
    // 结构体: llm_build_qwen2moe
    // 描述: llm_build_qwen2moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2moe相关的操作
struct llm_build_qwen2moe : public llm_graph_context {
    llm_build_qwen2moe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen2vl
// 描述: llm_build_qwen2vl类提供相关功能
// 用途: 用于处理llm_build_qwen2vl相关的操作
// 类: llm_build_qwen2vl
// 描述: llm_build_qwen2vl类提供相关功能
// 用途: 用于处理llm_build_qwen2vl相关的操作
    // 结构体: llm_build_qwen2vl
    // 描述: llm_build_qwen2vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2vl相关的操作
    // 结构体: llm_build_qwen2vl
    // 描述: llm_build_qwen2vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2vl相关的操作
    // 结构体: llm_build_qwen2vl
    // 描述: llm_build_qwen2vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2vl相关的操作
    // 结构体: llm_build_qwen2vl
    // 描述: llm_build_qwen2vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen2vl相关的操作
struct llm_build_qwen2vl : public llm_graph_context {
    llm_build_qwen2vl(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen3
// 描述: llm_build_qwen3类提供相关功能
// 用途: 用于处理llm_build_qwen3相关的操作
// 类: llm_build_qwen3
// 描述: llm_build_qwen3类提供相关功能
// 用途: 用于处理llm_build_qwen3相关的操作
    // 结构体: llm_build_qwen3
    // 描述: llm_build_qwen3结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3相关的操作
    // 结构体: llm_build_qwen3
    // 描述: llm_build_qwen3结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3相关的操作
    // 结构体: llm_build_qwen3
    // 描述: llm_build_qwen3结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3相关的操作
    // 结构体: llm_build_qwen3
    // 描述: llm_build_qwen3结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3相关的操作
struct llm_build_qwen3 : public llm_graph_context {
    llm_build_qwen3(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen3moe
// 描述: llm_build_qwen3moe类提供相关功能
// 用途: 用于处理llm_build_qwen3moe相关的操作
// 类: llm_build_qwen3moe
// 描述: llm_build_qwen3moe类提供相关功能
// 用途: 用于处理llm_build_qwen3moe相关的操作
    // 结构体: llm_build_qwen3moe
    // 描述: llm_build_qwen3moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3moe相关的操作
    // 结构体: llm_build_qwen3moe
    // 描述: llm_build_qwen3moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3moe相关的操作
    // 结构体: llm_build_qwen3moe
    // 描述: llm_build_qwen3moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3moe相关的操作
    // 结构体: llm_build_qwen3moe
    // 描述: llm_build_qwen3moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3moe相关的操作
struct llm_build_qwen3moe : public llm_graph_context {
    llm_build_qwen3moe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen3vl
// 描述: llm_build_qwen3vl类提供相关功能
// 用途: 用于处理llm_build_qwen3vl相关的操作
// 类: llm_build_qwen3vl
// 描述: llm_build_qwen3vl类提供相关功能
// 用途: 用于处理llm_build_qwen3vl相关的操作
    // 结构体: llm_build_qwen3vl
    // 描述: llm_build_qwen3vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vl相关的操作
    // 结构体: llm_build_qwen3vl
    // 描述: llm_build_qwen3vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vl相关的操作
    // 结构体: llm_build_qwen3vl
    // 描述: llm_build_qwen3vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vl相关的操作
    // 结构体: llm_build_qwen3vl
    // 描述: llm_build_qwen3vl结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vl相关的操作
struct llm_build_qwen3vl : public llm_graph_context {
    llm_build_qwen3vl(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen3vlmoe
// 描述: llm_build_qwen3vlmoe类提供相关功能
// 用途: 用于处理llm_build_qwen3vlmoe相关的操作
// 类: llm_build_qwen3vlmoe
// 描述: llm_build_qwen3vlmoe类提供相关功能
// 用途: 用于处理llm_build_qwen3vlmoe相关的操作
    // 结构体: llm_build_qwen3vlmoe
    // 描述: llm_build_qwen3vlmoe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vlmoe相关的操作
    // 结构体: llm_build_qwen3vlmoe
    // 描述: llm_build_qwen3vlmoe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vlmoe相关的操作
    // 结构体: llm_build_qwen3vlmoe
    // 描述: llm_build_qwen3vlmoe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vlmoe相关的操作
    // 结构体: llm_build_qwen3vlmoe
    // 描述: llm_build_qwen3vlmoe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3vlmoe相关的操作
struct llm_build_qwen3vlmoe : public llm_graph_context {
    llm_build_qwen3vlmoe(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_qwen3next
// 描述: llm_build_qwen3next类提供相关功能
// 用途: 用于处理llm_build_qwen3next相关的操作
// 类: llm_build_qwen3next
// 描述: llm_build_qwen3next类提供相关功能
// 用途: 用于处理llm_build_qwen3next相关的操作
    // 结构体: llm_build_qwen3next
    // 描述: llm_build_qwen3next结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3next相关的操作
    // 结构体: llm_build_qwen3next
    // 描述: llm_build_qwen3next结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3next相关的操作
    // 结构体: llm_build_qwen3next
    // 描述: llm_build_qwen3next结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3next相关的操作
    // 结构体: llm_build_qwen3next
    // 描述: llm_build_qwen3next结构体提供相关功能
    // 用途: 用于处理llm_build_qwen3next相关的操作
struct llm_build_qwen3next : public llm_build_delta_net_base {
    llm_build_qwen3next(const llama_model & model, const llm_graph_params & params);
private:
    ggml_tensor * build_layer_attn(
    llm_graph_input_attn_kv * inp_attn,
                ggml_tensor * cur,
                ggml_tensor * inp_pos,
                        int   il);

    ggml_tensor * build_layer_attn_linear(
         llm_graph_input_rs * inp,
                ggml_tensor * cur,
                        int   il);

    ggml_tensor * build_layer_ffn(
                ggml_tensor * cur,
                        int   il);

    ggml_tensor * build_norm_gated(
                ggml_tensor * input,
                ggml_tensor * weights,
                ggml_tensor * gate,
                        int   layer);

    // returns pair of qkv, z
    std::pair<ggml_tensor *, ggml_tensor *> build_qkvz(
                ggml_tensor * input,
                        int   il);

    const llama_model & model;
};

// 类: llm_build_qwen35
// 描述: llm_build_qwen35类提供相关功能
// 用途: 用于处理llm_build_qwen35相关的操作
// 类: llm_build_qwen35
// 描述: llm_build_qwen35类提供相关功能
// 用途: 用于处理llm_build_qwen35相关的操作
    // 结构体: llm_build_qwen35
    // 描述: llm_build_qwen35结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35相关的操作
    // 结构体: llm_build_qwen35
    // 描述: llm_build_qwen35结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35相关的操作
    // 结构体: llm_build_qwen35
    // 描述: llm_build_qwen35结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35相关的操作
    // 结构体: llm_build_qwen35
    // 描述: llm_build_qwen35结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35相关的操作
struct llm_build_qwen35 : public llm_build_delta_net_base {
    llm_build_qwen35(const llama_model & model, const llm_graph_params & params);
private:
    ggml_tensor * build_layer_attn(
    llm_graph_input_attn_kv * inp_attn,
                ggml_tensor * cur,
                ggml_tensor * inp_pos,
                        int * sections,
                        int   il);

    ggml_tensor * build_layer_attn_linear(
         llm_graph_input_rs * inp,
                ggml_tensor * cur,
                        int   il);

    ggml_tensor * build_layer_ffn(
                ggml_tensor * cur,
                        int   il);

    ggml_tensor * build_norm_gated(
                ggml_tensor * input,
                ggml_tensor * weights,
                ggml_tensor * gate,
                        int   layer);

    // returns pair of qkv, z
    std::pair<ggml_tensor *, ggml_tensor *> build_qkvz(
                ggml_tensor * input,
                        int   il);

    const llama_model & model;
};

// TODO: derive llm_build_delta_net_base instead
// 类: llm_build_qwen35moe
// 描述: llm_build_qwen35moe类提供相关功能
// 用途: 用于处理llm_build_qwen35moe相关的操作
// 类: llm_build_qwen35moe
// 描述: llm_build_qwen35moe类提供相关功能
// 用途: 用于处理llm_build_qwen35moe相关的操作
    // 结构体: llm_build_qwen35moe
    // 描述: llm_build_qwen35moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35moe相关的操作
    // 结构体: llm_build_qwen35moe
    // 描述: llm_build_qwen35moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35moe相关的操作
    // 结构体: llm_build_qwen35moe
    // 描述: llm_build_qwen35moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35moe相关的操作
    // 结构体: llm_build_qwen35moe
    // 描述: llm_build_qwen35moe结构体提供相关功能
    // 用途: 用于处理llm_build_qwen35moe相关的操作
struct llm_build_qwen35moe : public llm_build_delta_net_base {
    llm_build_qwen35moe(const llama_model & model, const llm_graph_params & params);
private:
    ggml_tensor * build_layer_attn(
    llm_graph_input_attn_kv * inp_attn,
                ggml_tensor * cur,
                ggml_tensor * inp_pos,
                        int * sections,
                        int   il);

    ggml_tensor * build_layer_attn_linear(
         llm_graph_input_rs * inp,
                ggml_tensor * cur,
                        int   il);

    ggml_tensor * build_layer_ffn(
                ggml_tensor * cur,
                        int   il);

    ggml_tensor * build_norm_gated(
                ggml_tensor * input,
                ggml_tensor * weights,
                ggml_tensor * gate,
                        int   layer);

    // returns pair of qkv, z
    std::pair<ggml_tensor *, ggml_tensor *> build_qkvz(
                ggml_tensor * input,
                        int   il);

    const llama_model & model;
};

// 类: llm_build_qwen
// 描述: llm_build_qwen类提供相关功能
// 用途: 用于处理llm_build_qwen相关的操作
// 类: llm_build_qwen
// 描述: llm_build_qwen类提供相关功能
// 用途: 用于处理llm_build_qwen相关的操作
    // 结构体: llm_build_qwen
    // 描述: llm_build_qwen结构体提供相关功能
    // 用途: 用于处理llm_build_qwen相关的操作
    // 结构体: llm_build_qwen
    // 描述: llm_build_qwen结构体提供相关功能
    // 用途: 用于处理llm_build_qwen相关的操作
    // 结构体: llm_build_qwen
    // 描述: llm_build_qwen结构体提供相关功能
    // 用途: 用于处理llm_build_qwen相关的操作
    // 结构体: llm_build_qwen
    // 描述: llm_build_qwen结构体提供相关功能
    // 用途: 用于处理llm_build_qwen相关的操作
struct llm_build_qwen : public llm_graph_context {
    llm_build_qwen(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_refact
// 描述: llm_build_refact类提供相关功能
// 用途: 用于处理llm_build_refact相关的操作
// 类: llm_build_refact
// 描述: llm_build_refact类提供相关功能
// 用途: 用于处理llm_build_refact相关的操作
    // 结构体: llm_build_refact
    // 描述: llm_build_refact结构体提供相关功能
    // 用途: 用于处理llm_build_refact相关的操作
    // 结构体: llm_build_refact
    // 描述: llm_build_refact结构体提供相关功能
    // 用途: 用于处理llm_build_refact相关的操作
    // 结构体: llm_build_refact
    // 描述: llm_build_refact结构体提供相关功能
    // 用途: 用于处理llm_build_refact相关的操作
    // 结构体: llm_build_refact
    // 描述: llm_build_refact结构体提供相关功能
    // 用途: 用于处理llm_build_refact相关的操作
struct llm_build_refact : public llm_graph_context {
    llm_build_refact(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_rnd1
// 描述: llm_build_rnd1类提供相关功能
// 用途: 用于处理llm_build_rnd1相关的操作
// 类: llm_build_rnd1
// 描述: llm_build_rnd1类提供相关功能
// 用途: 用于处理llm_build_rnd1相关的操作
    // 结构体: llm_build_rnd1
    // 描述: llm_build_rnd1结构体提供相关功能
    // 用途: 用于处理llm_build_rnd1相关的操作
    // 结构体: llm_build_rnd1
    // 描述: llm_build_rnd1结构体提供相关功能
    // 用途: 用于处理llm_build_rnd1相关的操作
    // 结构体: llm_build_rnd1
    // 描述: llm_build_rnd1结构体提供相关功能
    // 用途: 用于处理llm_build_rnd1相关的操作
    // 结构体: llm_build_rnd1
    // 描述: llm_build_rnd1结构体提供相关功能
    // 用途: 用于处理llm_build_rnd1相关的操作
struct llm_build_rnd1 : public llm_graph_context {
    llm_build_rnd1(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_rwkv6
// 描述: llm_build_rwkv6类提供相关功能
// 用途: 用于处理llm_build_rwkv6相关的操作
// 类: llm_build_rwkv6
// 描述: llm_build_rwkv6类提供相关功能
// 用途: 用于处理llm_build_rwkv6相关的操作
    // 结构体: llm_build_rwkv6
    // 描述: llm_build_rwkv6结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6相关的操作
    // 结构体: llm_build_rwkv6
    // 描述: llm_build_rwkv6结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6相关的操作
    // 结构体: llm_build_rwkv6
    // 描述: llm_build_rwkv6结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6相关的操作
    // 结构体: llm_build_rwkv6
    // 描述: llm_build_rwkv6结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6相关的操作
struct llm_build_rwkv6 : public llm_build_rwkv6_base {
    llm_build_rwkv6(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_rwkv6qwen2
// 描述: llm_build_rwkv6qwen2类提供相关功能
// 用途: 用于处理llm_build_rwkv6qwen2相关的操作
// 类: llm_build_rwkv6qwen2
// 描述: llm_build_rwkv6qwen2类提供相关功能
// 用途: 用于处理llm_build_rwkv6qwen2相关的操作
    // 结构体: llm_build_rwkv6qwen2
    // 描述: llm_build_rwkv6qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6qwen2相关的操作
    // 结构体: llm_build_rwkv6qwen2
    // 描述: llm_build_rwkv6qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6qwen2相关的操作
    // 结构体: llm_build_rwkv6qwen2
    // 描述: llm_build_rwkv6qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6qwen2相关的操作
    // 结构体: llm_build_rwkv6qwen2
    // 描述: llm_build_rwkv6qwen2结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv6qwen2相关的操作
struct llm_build_rwkv6qwen2 : public llm_build_rwkv6_base {
    llm_build_rwkv6qwen2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_rwkv7
// 描述: llm_build_rwkv7类提供相关功能
// 用途: 用于处理llm_build_rwkv7相关的操作
// 类: llm_build_rwkv7
// 描述: llm_build_rwkv7类提供相关功能
// 用途: 用于处理llm_build_rwkv7相关的操作
    // 结构体: llm_build_rwkv7
    // 描述: llm_build_rwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7相关的操作
    // 结构体: llm_build_rwkv7
    // 描述: llm_build_rwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7相关的操作
    // 结构体: llm_build_rwkv7
    // 描述: llm_build_rwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7相关的操作
    // 结构体: llm_build_rwkv7
    // 描述: llm_build_rwkv7结构体提供相关功能
    // 用途: 用于处理llm_build_rwkv7相关的操作
struct llm_build_rwkv7 : public llm_build_rwkv7_base {
    llm_build_rwkv7(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_seed_oss
// 描述: llm_build_seed_oss类提供相关功能
// 用途: 用于处理llm_build_seed_oss相关的操作
// 类: llm_build_seed_oss
// 描述: llm_build_seed_oss类提供相关功能
// 用途: 用于处理llm_build_seed_oss相关的操作
    // 结构体: llm_build_seed_oss
    // 描述: llm_build_seed_oss结构体提供相关功能
    // 用途: 用于处理llm_build_seed_oss相关的操作
    // 结构体: llm_build_seed_oss
    // 描述: llm_build_seed_oss结构体提供相关功能
    // 用途: 用于处理llm_build_seed_oss相关的操作
    // 结构体: llm_build_seed_oss
    // 描述: llm_build_seed_oss结构体提供相关功能
    // 用途: 用于处理llm_build_seed_oss相关的操作
    // 结构体: llm_build_seed_oss
    // 描述: llm_build_seed_oss结构体提供相关功能
    // 用途: 用于处理llm_build_seed_oss相关的操作
struct llm_build_seed_oss : public llm_graph_context {
    llm_build_seed_oss(const llama_model & model, const llm_graph_params & params);
};

template <bool iswa>
// 类: llm_build_smallthinker
// 描述: llm_build_smallthinker类提供相关功能
// 用途: 用于处理llm_build_smallthinker相关的操作
// 类: llm_build_smallthinker
// 描述: llm_build_smallthinker类提供相关功能
// 用途: 用于处理llm_build_smallthinker相关的操作
    // 结构体: llm_build_smallthinker
    // 描述: llm_build_smallthinker结构体提供相关功能
    // 用途: 用于处理llm_build_smallthinker相关的操作
    // 结构体: llm_build_smallthinker
    // 描述: llm_build_smallthinker结构体提供相关功能
    // 用途: 用于处理llm_build_smallthinker相关的操作
    // 结构体: llm_build_smallthinker
    // 描述: llm_build_smallthinker结构体提供相关功能
    // 用途: 用于处理llm_build_smallthinker相关的操作
    // 结构体: llm_build_smallthinker
    // 描述: llm_build_smallthinker结构体提供相关功能
    // 用途: 用于处理llm_build_smallthinker相关的操作
struct llm_build_smallthinker : public llm_graph_context {
    llm_build_smallthinker(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_smollm3
// 描述: llm_build_smollm3类提供相关功能
// 用途: 用于处理llm_build_smollm3相关的操作
// 类: llm_build_smollm3
// 描述: llm_build_smollm3类提供相关功能
// 用途: 用于处理llm_build_smollm3相关的操作
    // 结构体: llm_build_smollm3
    // 描述: llm_build_smollm3结构体提供相关功能
    // 用途: 用于处理llm_build_smollm3相关的操作
    // 结构体: llm_build_smollm3
    // 描述: llm_build_smollm3结构体提供相关功能
    // 用途: 用于处理llm_build_smollm3相关的操作
    // 结构体: llm_build_smollm3
    // 描述: llm_build_smollm3结构体提供相关功能
    // 用途: 用于处理llm_build_smollm3相关的操作
    // 结构体: llm_build_smollm3
    // 描述: llm_build_smollm3结构体提供相关功能
    // 用途: 用于处理llm_build_smollm3相关的操作
struct llm_build_smollm3 : public llm_graph_context {
    llm_build_smollm3(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_stablelm
// 描述: llm_build_stablelm类提供相关功能
// 用途: 用于处理llm_build_stablelm相关的操作
// 类: llm_build_stablelm
// 描述: llm_build_stablelm类提供相关功能
// 用途: 用于处理llm_build_stablelm相关的操作
    // 结构体: llm_build_stablelm
    // 描述: llm_build_stablelm结构体提供相关功能
    // 用途: 用于处理llm_build_stablelm相关的操作
    // 结构体: llm_build_stablelm
    // 描述: llm_build_stablelm结构体提供相关功能
    // 用途: 用于处理llm_build_stablelm相关的操作
    // 结构体: llm_build_stablelm
    // 描述: llm_build_stablelm结构体提供相关功能
    // 用途: 用于处理llm_build_stablelm相关的操作
    // 结构体: llm_build_stablelm
    // 描述: llm_build_stablelm结构体提供相关功能
    // 用途: 用于处理llm_build_stablelm相关的操作
struct llm_build_stablelm : public llm_graph_context {
    llm_build_stablelm(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_starcoder2
// 描述: llm_build_starcoder2类提供相关功能
// 用途: 用于处理llm_build_starcoder2相关的操作
// 类: llm_build_starcoder2
// 描述: llm_build_starcoder2类提供相关功能
// 用途: 用于处理llm_build_starcoder2相关的操作
    // 结构体: llm_build_starcoder2
    // 描述: llm_build_starcoder2结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder2相关的操作
    // 结构体: llm_build_starcoder2
    // 描述: llm_build_starcoder2结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder2相关的操作
    // 结构体: llm_build_starcoder2
    // 描述: llm_build_starcoder2结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder2相关的操作
    // 结构体: llm_build_starcoder2
    // 描述: llm_build_starcoder2结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder2相关的操作
struct llm_build_starcoder2 : public llm_graph_context {
    llm_build_starcoder2(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_starcoder
// 描述: llm_build_starcoder类提供相关功能
// 用途: 用于处理llm_build_starcoder相关的操作
// 类: llm_build_starcoder
// 描述: llm_build_starcoder类提供相关功能
// 用途: 用于处理llm_build_starcoder相关的操作
    // 结构体: llm_build_starcoder
    // 描述: llm_build_starcoder结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder相关的操作
    // 结构体: llm_build_starcoder
    // 描述: llm_build_starcoder结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder相关的操作
    // 结构体: llm_build_starcoder
    // 描述: llm_build_starcoder结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder相关的操作
    // 结构体: llm_build_starcoder
    // 描述: llm_build_starcoder结构体提供相关功能
    // 用途: 用于处理llm_build_starcoder相关的操作
struct llm_build_starcoder : public llm_graph_context {
    llm_build_starcoder(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_step35_iswa
// 描述: llm_build_step35_iswa类提供相关功能
// 用途: 用于处理llm_build_step35_iswa相关的操作
// 类: llm_build_step35_iswa
// 描述: llm_build_step35_iswa类提供相关功能
// 用途: 用于处理llm_build_step35_iswa相关的操作
    // 结构体: llm_build_step35_iswa
    // 描述: llm_build_step35_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_step35_iswa相关的操作
    // 结构体: llm_build_step35_iswa
    // 描述: llm_build_step35_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_step35_iswa相关的操作
    // 结构体: llm_build_step35_iswa
    // 描述: llm_build_step35_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_step35_iswa相关的操作
    // 结构体: llm_build_step35_iswa
    // 描述: llm_build_step35_iswa结构体提供相关功能
    // 用途: 用于处理llm_build_step35_iswa相关的操作
struct llm_build_step35_iswa : public llm_graph_context {
    llm_build_step35_iswa(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_t5_dec
// 描述: llm_build_t5_dec类提供相关功能
// 用途: 用于处理llm_build_t5_dec相关的操作
// 类: llm_build_t5_dec
// 描述: llm_build_t5_dec类提供相关功能
// 用途: 用于处理llm_build_t5_dec相关的操作
    // 结构体: llm_build_t5_dec
    // 描述: llm_build_t5_dec结构体提供相关功能
    // 用途: 用于处理llm_build_t5_dec相关的操作
    // 结构体: llm_build_t5_dec
    // 描述: llm_build_t5_dec结构体提供相关功能
    // 用途: 用于处理llm_build_t5_dec相关的操作
    // 结构体: llm_build_t5_dec
    // 描述: llm_build_t5_dec结构体提供相关功能
    // 用途: 用于处理llm_build_t5_dec相关的操作
    // 结构体: llm_build_t5_dec
    // 描述: llm_build_t5_dec结构体提供相关功能
    // 用途: 用于处理llm_build_t5_dec相关的操作
struct llm_build_t5_dec : public llm_graph_context {
    llm_build_t5_dec(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_t5_enc
// 描述: llm_build_t5_enc类提供相关功能
// 用途: 用于处理llm_build_t5_enc相关的操作
// 类: llm_build_t5_enc
// 描述: llm_build_t5_enc类提供相关功能
// 用途: 用于处理llm_build_t5_enc相关的操作
    // 结构体: llm_build_t5_enc
    // 描述: llm_build_t5_enc结构体提供相关功能
    // 用途: 用于处理llm_build_t5_enc相关的操作
    // 结构体: llm_build_t5_enc
    // 描述: llm_build_t5_enc结构体提供相关功能
    // 用途: 用于处理llm_build_t5_enc相关的操作
    // 结构体: llm_build_t5_enc
    // 描述: llm_build_t5_enc结构体提供相关功能
    // 用途: 用于处理llm_build_t5_enc相关的操作
    // 结构体: llm_build_t5_enc
    // 描述: llm_build_t5_enc结构体提供相关功能
    // 用途: 用于处理llm_build_t5_enc相关的操作
struct llm_build_t5_enc : public llm_graph_context {
    llm_build_t5_enc(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_wavtokenizer_dec
// 描述: llm_build_wavtokenizer_dec类提供相关功能
// 用途: 用于处理llm_build_wavtokenizer_dec相关的操作
// 类: llm_build_wavtokenizer_dec
// 描述: llm_build_wavtokenizer_dec类提供相关功能
// 用途: 用于处理llm_build_wavtokenizer_dec相关的操作
    // 结构体: llm_build_wavtokenizer_dec
    // 描述: llm_build_wavtokenizer_dec结构体提供相关功能
    // 用途: 用于处理llm_build_wavtokenizer_dec相关的操作
    // 结构体: llm_build_wavtokenizer_dec
    // 描述: llm_build_wavtokenizer_dec结构体提供相关功能
    // 用途: 用于处理llm_build_wavtokenizer_dec相关的操作
    // 结构体: llm_build_wavtokenizer_dec
    // 描述: llm_build_wavtokenizer_dec结构体提供相关功能
    // 用途: 用于处理llm_build_wavtokenizer_dec相关的操作
    // 结构体: llm_build_wavtokenizer_dec
    // 描述: llm_build_wavtokenizer_dec结构体提供相关功能
    // 用途: 用于处理llm_build_wavtokenizer_dec相关的操作
struct llm_build_wavtokenizer_dec : public llm_graph_context {
    llm_build_wavtokenizer_dec(const llama_model & model, const llm_graph_params & params);
};

// 类: llm_build_xverse
// 描述: llm_build_xverse类提供相关功能
// 用途: 用于处理llm_build_xverse相关的操作
// 类: llm_build_xverse
// 描述: llm_build_xverse类提供相关功能
// 用途: 用于处理llm_build_xverse相关的操作
    // 结构体: llm_build_xverse
    // 描述: llm_build_xverse结构体提供相关功能
    // 用途: 用于处理llm_build_xverse相关的操作
    // 结构体: llm_build_xverse
    // 描述: llm_build_xverse结构体提供相关功能
    // 用途: 用于处理llm_build_xverse相关的操作
    // 结构体: llm_build_xverse
    // 描述: llm_build_xverse结构体提供相关功能
    // 用途: 用于处理llm_build_xverse相关的操作
    // 结构体: llm_build_xverse
    // 描述: llm_build_xverse结构体提供相关功能
    // 用途: 用于处理llm_build_xverse相关的操作
struct llm_build_xverse : public llm_graph_context {
    llm_build_xverse(const llama_model & model, const llm_graph_params & params);
};
