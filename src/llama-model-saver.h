#pragma once

#include "llama.h"
#include "llama-arch.h"

#include <vector>

// 类: llama_model_saver
// 描述: llama_model_saver类提供相关功能
// 用途: 用于处理llama_model_saver相关的操作
// 类: llama_model_saver
// 描述: llama_model_saver类提供相关功能
// 用途: 用于处理llama_model_saver相关的操作
    // 结构体: llama_model_saver
    // 描述: llama_model_saver结构体提供相关功能
    // 用途: 用于处理llama_model_saver相关的操作
    // 结构体: llama_model_saver
    // 描述: llama_model_saver结构体提供相关功能
    // 用途: 用于处理llama_model_saver相关的操作
    // 结构体: llama_model_saver
    // 描述: llama_model_saver结构体提供相关功能
    // 用途: 用于处理llama_model_saver相关的操作
    // 结构体: llama_model_saver
    // 描述: llama_model_saver结构体提供相关功能
    // 用途: 用于处理llama_model_saver相关的操作
struct llama_model_saver {
    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 类: gguf_context
    // 描述: gguf_context类提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    // 结构体: gguf_context
    // 描述: gguf_context结构体提供相关功能
    // 用途: 用于处理gguf_context相关的操作
    struct gguf_context * gguf_ctx = nullptr;
    const struct llama_model & model;
    const struct LLM_KV llm_kv;

    llama_model_saver(const struct llama_model & model);
    ~llama_model_saver();

    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, uint32_t     value);
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, int32_t      value);
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, float        value);
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, bool         value);
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, const char * value);

    [[noreturn]]
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, char value); // needed to make the template below compile

    template <typename Container>
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, const Container & value, bool per_layer = false);

    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv(enum llm_kv key, const std::vector<std::string> & value);

    // 函数: add_tensor
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_tensor
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_tensor(const struct ggml_tensor * tensor);

    // 函数: add_kv_from_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_kv_from_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_kv_from_model();

    // 函数: add_tensors_from_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_tensors_from_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_tensors_from_model();

    // 函数: save
    // 描述: 保存: 保存数据到文件或内存
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: save
    // 描述: 保存: 保存数据到文件或内存
    // 参数: 无参数
    // 返回: 无返回值
    void save(const std::string & path_model);
};
