#pragma once

#include "llama.h"
#include "llama-arch.h"
#include "llama-graph.h"
#include "llama-hparams.h"
#include "llama-memory.h"
#include "llama-vocab.h"

#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// 类: llama_cparams
// 描述: llama_cparams类提供相关功能
// 用途: 用于处理llama_cparams相关的操作
// 类: llama_cparams
// 描述: llama_cparams类提供相关功能
// 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
struct llama_cparams;
// 类: llama_ubatch
// 描述: llama_ubatch类提供相关功能
// 用途: 用于处理llama_ubatch相关的操作
// 类: llama_ubatch
// 描述: llama_ubatch类提供相关功能
// 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
struct llama_ubatch;
// 类: llama_model_loader
// 描述: llama_model_loader类提供相关功能
// 用途: 用于处理llama_model_loader相关的操作
// 类: llama_model_loader
// 描述: llama_model_loader类提供相关功能
// 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
struct llama_model_loader;

// available models
enum llm_type {
    LLM_TYPE_UNKNOWN,
    LLM_TYPE_14M,
    LLM_TYPE_17M,
    LLM_TYPE_22M,
    LLM_TYPE_33M,
    LLM_TYPE_47M,
    LLM_TYPE_60M,
    LLM_TYPE_70M,
    LLM_TYPE_80M,
    LLM_TYPE_109M,
    LLM_TYPE_137M,
    LLM_TYPE_140M,
    LLM_TYPE_149M,
    LLM_TYPE_160M,
    LLM_TYPE_190M,
    LLM_TYPE_220M,
    LLM_TYPE_250M,
    LLM_TYPE_256M,
    LLM_TYPE_270M,
    LLM_TYPE_335M,
    LLM_TYPE_350M,
    LLM_TYPE_360M,
    LLM_TYPE_395M,
    LLM_TYPE_410M,
    LLM_TYPE_450M,
    LLM_TYPE_475M,
    LLM_TYPE_558M,
    LLM_TYPE_700M,
    LLM_TYPE_770M,
    LLM_TYPE_780M,
    LLM_TYPE_950M,
    LLM_TYPE_0_3B,
    LLM_TYPE_0_5B,
    LLM_TYPE_0_6B,
    LLM_TYPE_1B,
    LLM_TYPE_1_2B,
    LLM_TYPE_1_3B,
    LLM_TYPE_1_4B,
    LLM_TYPE_1_5B,
    LLM_TYPE_1_6B,
    LLM_TYPE_1_7B,
    LLM_TYPE_1_8B,
    LLM_TYPE_2B,
    LLM_TYPE_2_6B,
    LLM_TYPE_2_8B,
    LLM_TYPE_2_9B,
    LLM_TYPE_3B,
    LLM_TYPE_4B,
    LLM_TYPE_6B,
    LLM_TYPE_6_9B,
    LLM_TYPE_7B,
    LLM_TYPE_8B,
    LLM_TYPE_9B,
    LLM_TYPE_11B,
    LLM_TYPE_12B,
    LLM_TYPE_13B,
    LLM_TYPE_14B,
    LLM_TYPE_15B,
    LLM_TYPE_16B,
    LLM_TYPE_20B,
    LLM_TYPE_26B,
    LLM_TYPE_27B,
    LLM_TYPE_30B,
    LLM_TYPE_32B,
    LLM_TYPE_34B,
    LLM_TYPE_35B,
    LLM_TYPE_36B,
    LLM_TYPE_40B,
    LLM_TYPE_65B,
    LLM_TYPE_70B,
    LLM_TYPE_120B,
    LLM_TYPE_142B,
    LLM_TYPE_236B,
    LLM_TYPE_290B,
    LLM_TYPE_314B,
    LLM_TYPE_405B,
    LLM_TYPE_671B,
    LLM_TYPE_SMALL,
    LLM_TYPE_MEDIUM,
    LLM_TYPE_LARGE,
    LLM_TYPE_XL,
    LLM_TYPE_A1_7B,
    LLM_TYPE_A2_7B,
    LLM_TYPE_8x7B,
    LLM_TYPE_8x22B,
    LLM_TYPE_16x12B,
    LLM_TYPE_16x3_8B,
    LLM_TYPE_10B_128x3_66B,
    LLM_TYPE_57B_A14B,
    LLM_TYPE_17B_16E, // llama4 Scout
    LLM_TYPE_17B_128E, // llama4 Maverick
    LLM_TYPE_A13B,
    LLM_TYPE_7B_A1B,
    LLM_TYPE_8B_A1B, // lfm2moe
    LLM_TYPE_16B_A1B,
    LLM_TYPE_21B_A3B, // Ernie MoE small
    LLM_TYPE_24B_A2B, // lfm2moe
    LLM_TYPE_30B_A3B,
    LLM_TYPE_31B_A3_5B,
    LLM_TYPE_35B_A3B, // Qwen3.5
    LLM_TYPE_48B_A3B, // Kimi Linear
    LLM_TYPE_80B_A3B, // Qwen3 Next
    LLM_TYPE_100B_A6B,
    LLM_TYPE_102B_A12B, // Solar-Open
    LLM_TYPE_106B_A12B, // GLM-4.5-Air
    LLM_TYPE_196B_A11B, // Step3.5-Flash
    LLM_TYPE_230B_A10B, // Minimax M2
    LLM_TYPE_235B_A22B,
    LLM_TYPE_300B_A47B, // Ernie MoE big
    LLM_TYPE_310B_A15B, // /MiMo-V2-Flash
    LLM_TYPE_355B_A32B, // GLM-4.5
    LLM_TYPE_744B_A40B, // GLM-5
    LLM_TYPE_E2B,
    LLM_TYPE_E4B,
};

// 函数: llama_rope_scaling_type_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_rope_scaling_type_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string llama_rope_scaling_type_name(llama_rope_scaling_type rope_scaling_type);

// 类: llama_layer_posnet
// 描述: llama_layer_posnet类提供相关功能
// 用途: 用于处理llama_layer_posnet相关的操作
// 类: llama_layer_posnet
// 描述: llama_layer_posnet类提供相关功能
// 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
struct llama_layer_posnet {
    // resnet
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm1   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm1_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * conv1   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * conv1_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm2   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm2_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * conv2   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * conv2_b = nullptr;

    // attention
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_q   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_q_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_k   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_k_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_v   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_v_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_o   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_o_b = nullptr;

    // normalize
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm_b = nullptr;
};

// 类: llama_layer_convnext
// 描述: llama_layer_convnext类提供相关功能
// 用途: 用于处理llama_layer_convnext相关的操作
// 类: llama_layer_convnext
// 描述: llama_layer_convnext类提供相关功能
// 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
struct llama_layer_convnext {
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * dw   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * dw_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * norm_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * pw1   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * pw1_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * pw2   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * pw2_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * gamma = nullptr;
};

// 类: llama_layer_shortconv
// 描述: llama_layer_shortconv类提供相关功能
// 用途: 用于处理llama_layer_shortconv相关的操作
// 类: llama_layer_shortconv
// 描述: llama_layer_shortconv类提供相关功能
// 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
struct llama_layer_shortconv {
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * in_proj  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * conv     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * out_proj = nullptr;
};

// 类: llama_layer_nextn
// 描述: llama_layer_nextn类提供相关功能
// 用途: 用于处理llama_layer_nextn相关的操作
// 类: llama_layer_nextn
// 描述: llama_layer_nextn类提供相关功能
// 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
struct llama_layer_nextn {
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * eh_proj          = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * embed_tokens     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * enorm            = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * hnorm            = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * shared_head_head = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * shared_head_norm = nullptr;
};

// 类: llama_layer
// 描述: llama_layer类提供相关功能
// 用途: 用于处理llama_layer相关的操作
// 类: llama_layer
// 描述: llama_layer类提供相关功能
// 用途: 用于处理llama_layer相关的操作
    // 结构体: llama_layer
    // 描述: llama_layer结构体提供相关功能
    // 用途: 用于处理llama_layer相关的操作
    // 结构体: llama_layer
    // 描述: llama_layer结构体提供相关功能
    // 用途: 用于处理llama_layer相关的操作
    // 结构体: llama_layer
    // 描述: llama_layer结构体提供相关功能
    // 用途: 用于处理llama_layer相关的操作
    // 结构体: llama_layer
    // 描述: llama_layer结构体提供相关功能
    // 用途: 用于处理llama_layer相关的操作
struct llama_layer {
    // normalization
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm_b     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm_2     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm_2_b   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_q_norm     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_q_norm_b   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_k_norm     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_k_norm_b   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_out_norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_out_norm_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_q_a_norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_kv_a_norm  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_sub_norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_post_norm  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_sub_norm    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm_cross = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_norm_enc   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_norm        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_dt_norm     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_b_norm      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_c_norm      = nullptr;

    // attention
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wq        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wk        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wv        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wo        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wqkv      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wq_a      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wq_b      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wkv_a_mqa = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wkv_b     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wk_b      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wv_b      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wq_cross  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wk_cross  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wv_cross  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wo_cross  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wq_enc    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wk_enc    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wv_enc    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wo_enc    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wqkv_gate = nullptr;

    // attention bias
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * bq   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * bk   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * bv   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * bo   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * bqkv = nullptr;

    // relative position bias
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_rel_b       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_rel_b_enc   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_rel_b_cross = nullptr;

    // normalization
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_norm         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_norm_b       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_post_norm    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * layer_out_norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * layer_out_norm_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_norm_exps    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_norm_enc     = nullptr;

    // ff
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate     = nullptr; // w1
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down     = nullptr; // w2
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up       = nullptr; // w3
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_enc = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down_enc = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up_enc   = nullptr;

    // ff MoE
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_inp      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_exps     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down_exps     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up_exps       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_up_exps  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_inp_b    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_exps_b   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down_exps_b   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up_exps_b     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_up_exps_b = nullptr;

    // ff shared expert (shexp)
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_inp_shexp = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_shexp     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down_shexp     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up_shexp       = nullptr;

    // ff adjugate experts (chexps)
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_chexps     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down_chexps     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up_chexps       = nullptr;

    // ff bias
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down_b = nullptr; // b2
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up_b   = nullptr; // b3
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_act    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_exp_probs_b = nullptr;

    // mamba proj
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_in  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_x   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_dt  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_out = nullptr;

    // mamba
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_conv1d = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_a      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_d      = nullptr;

    // mamba bias
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_conv1d_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_dt_b     = nullptr;

    // qwen3next
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_beta_alpha = nullptr;

    // qwen3.5
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_alpha = nullptr;

    // rwkv
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_w1         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_w2         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_lerp_x     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_lerp_w     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_lerp_k     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_lerp_v     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_lerp_r     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_lerp_g     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_lerp_fused = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_first        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_decay        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_decay_w1     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_decay_w2     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_key          = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_key_b        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_value        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_value_b      = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_receptance   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_receptance_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_gate         = nullptr;

    // rwkv7
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_w0         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_a0         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_a1         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_a2         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_v0         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_v1         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_v2         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_g1         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_g2         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_k_k        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_k_a        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_r_k        = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_ln     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_ln_b   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * time_mix_output = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * channel_mix_lerp_k = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * channel_mix_lerp_r = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * channel_mix_key        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * channel_mix_receptance = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * channel_mix_value      = nullptr;

    // long rope factors
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * rope_long  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * rope_short = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * rope_freqs = nullptr;

    // bitnet scale
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wq_scale       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wk_scale       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wv_scale       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * wo_scale       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_gate_scale = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_up_scale   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_down_scale = nullptr;

    // altup & laurel
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * per_layer_inp_gate   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * per_layer_proj       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * per_layer_post_norm  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * altup_correct_coef   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * altup_correct_scale  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * altup_predict_coef   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * altup_router         = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * altup_router_norm    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * laurel_l             = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * laurel_r             = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * laurel_post_norm     = nullptr;

    // openai-moe
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * attn_sinks = nullptr;

    // cogvlm
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * visexp_attn_wqkv = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * visexp_attn_wo   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * visexp_ffn_gate  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * visexp_ffn_down  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * visexp_ffn_up    = nullptr;

    // xIELU activation parameters for Apertus
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_act_alpha_n = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_act_alpha_p = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_act_beta    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ffn_act_eps     = nullptr;

    // Kimi Linear KDA (using ssm_ prefix for consistency)
    // Note: ssm_dt_b already exists above (mamba bias), reused for Kimi dt_bias
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_q_conv = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_k_conv = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_v_conv = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_f_a    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_f_b    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_beta   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_g_a    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_g_b    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * ssm_o_norm = nullptr;

    // DSA (deepseek sparse attention)
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * indexer_k_norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * indexer_k_norm_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * indexer_proj     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * indexer_attn_k   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * indexer_attn_q_b = nullptr; // note: for lora a/b, not bias

    // 类: llama_layer_posnet
    // 描述: llama_layer_posnet类提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 类: llama_layer_posnet
    // 描述: llama_layer_posnet类提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    // 结构体: llama_layer_posnet
    // 描述: llama_layer_posnet结构体提供相关功能
    // 用途: 用于处理llama_layer_posnet相关的操作
    struct llama_layer_posnet posnet;

    // 类: llama_layer_convnext
    // 描述: llama_layer_convnext类提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 类: llama_layer_convnext
    // 描述: llama_layer_convnext类提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    // 结构体: llama_layer_convnext
    // 描述: llama_layer_convnext结构体提供相关功能
    // 用途: 用于处理llama_layer_convnext相关的操作
    struct llama_layer_convnext convnext;

    // 类: llama_layer_shortconv
    // 描述: llama_layer_shortconv类提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 类: llama_layer_shortconv
    // 描述: llama_layer_shortconv类提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    // 结构体: llama_layer_shortconv
    // 描述: llama_layer_shortconv结构体提供相关功能
    // 用途: 用于处理llama_layer_shortconv相关的操作
    struct llama_layer_shortconv shortconv;

    // 类: llama_layer_nextn
    // 描述: llama_layer_nextn类提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 类: llama_layer_nextn
    // 描述: llama_layer_nextn类提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    // 结构体: llama_layer_nextn
    // 描述: llama_layer_nextn结构体提供相关功能
    // 用途: 用于处理llama_layer_nextn相关的操作
    struct llama_layer_nextn nextn;
};

// 类: llama_model
// 描述: llama_model类提供相关功能
// 用途: 用于处理llama_model相关的操作
// 类: llama_model
// 描述: llama_model类提供相关功能
// 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
struct llama_model {
    llm_type type = LLM_TYPE_UNKNOWN;
    llm_arch arch = LLM_ARCH_UNKNOWN;

    std::string name = "n/a";

    llama_hparams hparams = {};
    llama_vocab   vocab;

    // for classifier models
    std::vector<std::string> classifier_labels;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * tok_embd   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * type_embd  = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * pos_embd   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * tok_norm   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * tok_norm_b = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * output_norm     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * output_norm_b   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * output          = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * output_b        = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * output_norm_enc = nullptr;

    // classifier
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * cls       = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * cls_b     = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * cls_out   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * cls_out_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * cls_norm  = nullptr;

    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * conv1d   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * conv1d_b = nullptr;

    // gemma3n altup
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * tok_embd_per_layer   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * altup_proj           = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * altup_unembd_proj    = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * per_layer_model_proj = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * per_layer_proj_norm  = nullptr;

    std::vector<llama_layer> layers;

    //Dense linear projections for SentenceTransformers models like embeddinggemma
    // For Sentence Transformers models structure see
    // https://sbert.net/docs/sentence_transformer/usage/custom_models.html#structure-of-sentence-transformer-models
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * dense_2_out_layers   = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * dense_2_out_layers_b = nullptr;
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 类: ggml_tensor
    // 描述: ggml_tensor类提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    struct ggml_tensor * dense_3_out_layers   = nullptr;

    // gguf metadata
    std::unordered_map<std::string, std::string> gguf_kv;

    // list of devices used in this model
    std::vector<ggml_backend_dev_t> devices;

    // for quantize-stats only
    std::vector<std::pair<std::string, struct ggml_tensor *>> tensors_by_name;

    // for keeping track of associated LoRA adapters
    std::unordered_set<llama_adapter_lora *> loras;

    int64_t t_load_us  = 0;
    int64_t t_start_us = 0;

    // 函数: llama_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: llama_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit llama_model(const struct llama_model_params & params);
    ~llama_model();

    // 函数: load_stats
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_stats
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load_stats  (llama_model_loader & ml);
    // 函数: load_arch
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_arch
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load_arch   (llama_model_loader & ml);
    // 函数: load_hparams
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_hparams
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load_hparams(llama_model_loader & ml);
    // 函数: load_vocab
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_vocab
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load_vocab  (llama_model_loader & ml);
    // 函数: load_tensors
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_tensors
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    bool load_tensors(llama_model_loader & ml); // returns false if cancelled by progress_callback

    // 函数: arch_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: arch_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string arch_name() const;
    // 函数: type_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type_name() const;

    // 函数: desc
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: desc
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string desc() const;

    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size() const; // file size
    // 函数: n_tensors
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_tensors
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t n_tensors() const;
    // 函数: n_devices
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_devices
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t n_devices() const;

    // 函数: n_gpu_layers
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_gpu_layers
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_gpu_layers() const;
    // 函数: split_mode
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: split_mode
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_split_mode split_mode() const;

    std::map<ggml_backend_buffer_type_t, size_t> memory_breakdown() const;

    // total number of parameters in the model
    // 函数: n_elements
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_elements
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint64_t n_elements() const;

    // 函数: print_info
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: print_info
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void print_info() const;

    // 函数: dev_layer
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: dev_layer
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_backend_dev_t dev_layer(int il) const;
    // 函数: dev_output
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: dev_output
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_backend_dev_t dev_output() const;

    // 函数: select_buft
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: select_buft
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_backend_buffer_type_t select_buft(int il) const;

    // 函数: has_tensor_overrides
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: has_tensor_overrides
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool has_tensor_overrides() const;

    const struct ggml_tensor * get_tensor(const char * name) const;

    // 函数: get_rope_freq_base
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_rope_freq_base
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float get_rope_freq_base (const llama_cparams & cparams, int il) const;
    // 函数: get_rope_freq_scale
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_rope_freq_scale
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float get_rope_freq_scale(const llama_cparams & cparams, int il) const;

    // 函数: get_rope_factors
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_rope_factors
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_rope_factors(const llama_cparams & cparams, int il) const;

    // TODO: move this to new llm_arch_model_i interface
    // 函数: create_memory
    // 描述: 创建: 创建新的对象或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: create_memory
    // 描述: 创建: 创建新的对象或资源
    // 参数: 无参数
    // 返回: 无返回值
    llama_memory_i * create_memory(const llama_memory_params & params, const llama_cparams & cparams) const;

    // TODO: move this to new llm_arch_model_i interface
    // 函数: build_graph
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_graph
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    ggml_cgraph * build_graph(const llm_graph_params & params) const;

private:
    llama_model_params params;

    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    struct impl;
    std::unique_ptr<impl> pimpl;
};

// 函数: llm_type_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llm_type_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
const char * llm_type_name(llm_type type);

// For internal test use
// TODO: remove
const std::vector<std::pair<std::string, ggml_tensor *>> & llama_internal_get_tensor_map(const llama_model * model);
