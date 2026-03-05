#pragma once

#include "ggml.h" // for ggml_log_level

#include <string>
#include <vector>

#ifdef __GNUC__
#    if defined(__MINGW32__) && !defined(__clang__)
#        define LLAMA_ATTRIBUTE_FORMAT(...) __attribute__((format(gnu_printf, __VA_ARGS__)))
#    else
#        define LLAMA_ATTRIBUTE_FORMAT(...) __attribute__((format(printf, __VA_ARGS__)))
#    endif
#else
#    define LLAMA_ATTRIBUTE_FORMAT(...)
#endif

//
// logging
//

LLAMA_ATTRIBUTE_FORMAT(2, 3)
// 函数: llama_log_internal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_log_internal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void llama_log_internal        (ggml_log_level level, const char * format, ...);
// 函数: llama_log_callback_default
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_log_callback_default
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void llama_log_callback_default(ggml_log_level level, const char * text, void * user_data);

#define LLAMA_LOG(...)       llama_log_internal(GGML_LOG_LEVEL_NONE , __VA_ARGS__)
#define LLAMA_LOG_INFO(...)  llama_log_internal(GGML_LOG_LEVEL_INFO , __VA_ARGS__)
#define LLAMA_LOG_WARN(...)  llama_log_internal(GGML_LOG_LEVEL_WARN , __VA_ARGS__)
#define LLAMA_LOG_ERROR(...) llama_log_internal(GGML_LOG_LEVEL_ERROR, __VA_ARGS__)
#define LLAMA_LOG_DEBUG(...) llama_log_internal(GGML_LOG_LEVEL_DEBUG, __VA_ARGS__)
#define LLAMA_LOG_CONT(...)  llama_log_internal(GGML_LOG_LEVEL_CONT , __VA_ARGS__)

//
// helpers
//

template <typename T>
// 类: no_init
// 描述: no_init类提供相关功能
// 用途: 用于处理no_init相关的操作
// 类: no_init
// 描述: no_init类提供相关功能
// 用途: 用于处理no_init相关的操作
    // 结构体: no_init
    // 描述: no_init结构体提供相关功能
    // 用途: 用于处理no_init相关的操作
    // 结构体: no_init
    // 描述: no_init结构体提供相关功能
    // 用途: 用于处理no_init相关的操作
    // 结构体: no_init
    // 描述: no_init结构体提供相关功能
    // 用途: 用于处理no_init相关的操作
    // 结构体: no_init
    // 描述: no_init结构体提供相关功能
    // 用途: 用于处理no_init相关的操作
struct no_init {
    T value;
    no_init() = default;
};

// 类: time_meas
// 描述: time_meas类提供相关功能
// 用途: 用于处理time_meas相关的操作
// 类: time_meas
// 描述: time_meas类提供相关功能
// 用途: 用于处理time_meas相关的操作
    // 结构体: time_meas
    // 描述: time_meas结构体提供相关功能
    // 用途: 用于处理time_meas相关的操作
    // 结构体: time_meas
    // 描述: time_meas结构体提供相关功能
    // 用途: 用于处理time_meas相关的操作
    // 结构体: time_meas
    // 描述: time_meas结构体提供相关功能
    // 用途: 用于处理time_meas相关的操作
    // 结构体: time_meas
    // 描述: time_meas结构体提供相关功能
    // 用途: 用于处理time_meas相关的操作
struct time_meas {
    time_meas(int64_t & t_acc, bool disable = false);
    ~time_meas();

    const int64_t t_start_us;

    int64_t & t_acc;
};

template <typename T>
// 类: buffer_view
// 描述: buffer_view类提供相关功能
// 用途: 用于处理buffer_view相关的操作
// 类: buffer_view
// 描述: buffer_view类提供相关功能
// 用途: 用于处理buffer_view相关的操作
    // 结构体: buffer_view
    // 描述: buffer_view结构体提供相关功能
    // 用途: 用于处理buffer_view相关的操作
    // 结构体: buffer_view
    // 描述: buffer_view结构体提供相关功能
    // 用途: 用于处理buffer_view相关的操作
    // 结构体: buffer_view
    // 描述: buffer_view结构体提供相关功能
    // 用途: 用于处理buffer_view相关的操作
    // 结构体: buffer_view
    // 描述: buffer_view结构体提供相关功能
    // 用途: 用于处理buffer_view相关的操作
struct buffer_view {
    T * data;
    size_t size = 0;

    // 函数: has_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: has_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool has_data() const {
        return data && size > 0;
    }
};

// 函数: replace_all
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: replace_all
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void replace_all(std::string & s, const std::string & search, const std::string & replace);

// TODO: rename to llama_format ?
LLAMA_ATTRIBUTE_FORMAT(1, 2)
// 函数: format
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: format
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string format(const char * fmt, ...);

// 函数: llama_format_tensor_shape
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_format_tensor_shape
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string llama_format_tensor_shape(const std::vector<int64_t> & ne);
// 函数: llama_format_tensor_shape
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_format_tensor_shape
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string llama_format_tensor_shape(const struct ggml_tensor * t);

// 函数: gguf_kv_to_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: gguf_kv_to_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string gguf_kv_to_str(const struct gguf_context * ctx_gguf, int i);

#define LLAMA_TENSOR_NAME_FATTN "__fattn__"
