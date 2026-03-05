#pragma once

#include "llama.h"
#include "common.h"

// 类: common_speculative
// 描述: common_speculative类提供相关功能
// 用途: 用于处理common_speculative相关的操作
// 类: common_speculative
// 描述: common_speculative类提供相关功能
// 用途: 用于处理common_speculative相关的操作
    // 结构体: common_speculative
    // 描述: common_speculative结构体提供相关功能
    // 用途: 用于处理common_speculative相关的操作
    // 结构体: common_speculative
    // 描述: common_speculative结构体提供相关功能
    // 用途: 用于处理common_speculative相关的操作
    // 结构体: common_speculative
    // 描述: common_speculative结构体提供相关功能
    // 用途: 用于处理common_speculative相关的操作
    // 结构体: common_speculative
    // 描述: common_speculative结构体提供相关功能
    // 用途: 用于处理common_speculative相关的操作
struct common_speculative;

// comma separated list of all types
// 函数: common_speculative_type_name_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_speculative_type_name_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string common_speculative_type_name_str();

// convert string to type
enum common_speculative_type common_speculative_type_from_name(const std::string & name);

// convert type to string
// 函数: common_speculative_type_to_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_speculative_type_to_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string common_speculative_type_to_str(enum common_speculative_type type);

// check if the llama_context is compatible for speculative decoding
// note: clears the memory of the context
// 函数: common_speculative_is_compat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_speculative_is_compat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool common_speculative_is_compat(llama_context * ctx_tgt);

common_speculative * common_speculative_init(
        common_params_speculative & params,
        llama_context             * ctx_tgt);

// 函数: common_speculative_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: common_speculative_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void common_speculative_free(common_speculative * spec);

// optionally call once at the beginning of a new generation
// 函数: common_speculative_begin
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_speculative_begin
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_speculative_begin(common_speculative * spec, const llama_tokens & prompt);

// sample up to n_draft tokens and add them to the batch using the draft model
llama_tokens common_speculative_draft(
                     common_speculative * spec,
        const common_params_speculative & params,
                     const llama_tokens & prompt,
                            llama_token   id_last);

// informs the speculative decoder that n_accepted tokens were accepted by the target model
// 函数: common_speculative_accept
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_speculative_accept
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_speculative_accept(common_speculative * spec, uint16_t n_accepted);

// print statistics about the speculative decoding
// 函数: common_speculative_print_stats
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_speculative_print_stats
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_speculative_print_stats(const common_speculative * spec);
