#pragma once

#ifndef __cplusplus
#error "This header is for C++ only"
#endif

#include <memory>

#include "llama.h"

// 类: llama_model_deleter
// 描述: llama_model_deleter类提供相关功能
// 用途: 用于处理llama_model_deleter相关的操作
// 类: llama_model_deleter
// 描述: llama_model_deleter类提供相关功能
// 用途: 用于处理llama_model_deleter相关的操作
    // 结构体: llama_model_deleter
    // 描述: llama_model_deleter结构体提供相关功能
    // 用途: 用于处理llama_model_deleter相关的操作
    // 结构体: llama_model_deleter
    // 描述: llama_model_deleter结构体提供相关功能
    // 用途: 用于处理llama_model_deleter相关的操作
    // 结构体: llama_model_deleter
    // 描述: llama_model_deleter结构体提供相关功能
    // 用途: 用于处理llama_model_deleter相关的操作
    // 结构体: llama_model_deleter
    // 描述: llama_model_deleter结构体提供相关功能
    // 用途: 用于处理llama_model_deleter相关的操作
    // 结构体: llama_model_deleter
    // 描述: llama_model_deleter结构体提供相关功能
    // 用途: 用于处理llama_model_deleter相关的操作
    // 结构体: llama_model_deleter
    // 描述: llama_model_deleter结构体提供相关功能
    // 用途: 用于处理llama_model_deleter相关的操作
struct llama_model_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(llama_model * model) { llama_model_free(model); }
};

// 类: llama_context_deleter
// 描述: llama_context_deleter类提供相关功能
// 用途: 用于处理llama_context_deleter相关的操作
// 类: llama_context_deleter
// 描述: llama_context_deleter类提供相关功能
// 用途: 用于处理llama_context_deleter相关的操作
    // 结构体: llama_context_deleter
    // 描述: llama_context_deleter结构体提供相关功能
    // 用途: 用于处理llama_context_deleter相关的操作
    // 结构体: llama_context_deleter
    // 描述: llama_context_deleter结构体提供相关功能
    // 用途: 用于处理llama_context_deleter相关的操作
    // 结构体: llama_context_deleter
    // 描述: llama_context_deleter结构体提供相关功能
    // 用途: 用于处理llama_context_deleter相关的操作
    // 结构体: llama_context_deleter
    // 描述: llama_context_deleter结构体提供相关功能
    // 用途: 用于处理llama_context_deleter相关的操作
    // 结构体: llama_context_deleter
    // 描述: llama_context_deleter结构体提供相关功能
    // 用途: 用于处理llama_context_deleter相关的操作
    // 结构体: llama_context_deleter
    // 描述: llama_context_deleter结构体提供相关功能
    // 用途: 用于处理llama_context_deleter相关的操作
struct llama_context_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(llama_context * context) { llama_free(context); }
};

// 类: llama_sampler_deleter
// 描述: llama_sampler_deleter类提供相关功能
// 用途: 用于处理llama_sampler_deleter相关的操作
// 类: llama_sampler_deleter
// 描述: llama_sampler_deleter类提供相关功能
// 用途: 用于处理llama_sampler_deleter相关的操作
    // 结构体: llama_sampler_deleter
    // 描述: llama_sampler_deleter结构体提供相关功能
    // 用途: 用于处理llama_sampler_deleter相关的操作
    // 结构体: llama_sampler_deleter
    // 描述: llama_sampler_deleter结构体提供相关功能
    // 用途: 用于处理llama_sampler_deleter相关的操作
    // 结构体: llama_sampler_deleter
    // 描述: llama_sampler_deleter结构体提供相关功能
    // 用途: 用于处理llama_sampler_deleter相关的操作
    // 结构体: llama_sampler_deleter
    // 描述: llama_sampler_deleter结构体提供相关功能
    // 用途: 用于处理llama_sampler_deleter相关的操作
    // 结构体: llama_sampler_deleter
    // 描述: llama_sampler_deleter结构体提供相关功能
    // 用途: 用于处理llama_sampler_deleter相关的操作
    // 结构体: llama_sampler_deleter
    // 描述: llama_sampler_deleter结构体提供相关功能
    // 用途: 用于处理llama_sampler_deleter相关的操作
struct llama_sampler_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(llama_sampler * sampler) { llama_sampler_free(sampler); }
};

// 类: llama_adapter_lora_deleter
// 描述: llama_adapter_lora_deleter类提供相关功能
// 用途: 用于处理llama_adapter_lora_deleter相关的操作
// 类: llama_adapter_lora_deleter
// 描述: llama_adapter_lora_deleter类提供相关功能
// 用途: 用于处理llama_adapter_lora_deleter相关的操作
    // 结构体: llama_adapter_lora_deleter
    // 描述: llama_adapter_lora_deleter结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_deleter相关的操作
    // 结构体: llama_adapter_lora_deleter
    // 描述: llama_adapter_lora_deleter结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_deleter相关的操作
    // 结构体: llama_adapter_lora_deleter
    // 描述: llama_adapter_lora_deleter结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_deleter相关的操作
    // 结构体: llama_adapter_lora_deleter
    // 描述: llama_adapter_lora_deleter结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_deleter相关的操作
    // 结构体: llama_adapter_lora_deleter
    // 描述: llama_adapter_lora_deleter结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_deleter相关的操作
    // 结构体: llama_adapter_lora_deleter
    // 描述: llama_adapter_lora_deleter结构体提供相关功能
    // 用途: 用于处理llama_adapter_lora_deleter相关的操作
struct llama_adapter_lora_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(llama_adapter_lora *) {
        // llama_adapter_lora_free is deprecated
    }
};

typedef std::unique_ptr<llama_model, llama_model_deleter> llama_model_ptr;
typedef std::unique_ptr<llama_context, llama_context_deleter> llama_context_ptr;
typedef std::unique_ptr<llama_sampler, llama_sampler_deleter> llama_sampler_ptr;
typedef std::unique_ptr<llama_adapter_lora, llama_adapter_lora_deleter> llama_adapter_lora_ptr;
