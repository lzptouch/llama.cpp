#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

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
struct ggml_tensor;

// 类: llama_io_write_i
// 描述: llama_io_write_i类提供相关功能
// 用途: 用于处理llama_io_write_i相关的操作
// 类: llama_io_write_i
// 描述: llama_io_write_i类提供相关功能
// 用途: 用于处理llama_io_write_i相关的操作
class llama_io_write_i {
public:
    llama_io_write_i() = default;
    virtual ~llama_io_write_i() = default;

    // 函数: write
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: write
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void write(const void * src, size_t size) = 0;
    // 函数: write_tensor
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: write_tensor
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void write_tensor(const ggml_tensor * tensor, size_t offset, size_t size) = 0;

    // bytes written so far
    // 函数: n_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual size_t n_bytes() = 0;

    // 函数: write_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: write_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void write_string(const std::string & str);
};

// 类: llama_io_read_i
// 描述: llama_io_read_i类提供相关功能
// 用途: 用于处理llama_io_read_i相关的操作
// 类: llama_io_read_i
// 描述: llama_io_read_i类提供相关功能
// 用途: 用于处理llama_io_read_i相关的操作
class llama_io_read_i {
public:
    llama_io_read_i() = default;
    virtual ~llama_io_read_i() = default;

    // 函数: read
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual const uint8_t * read(size_t size) = 0;
    // 函数: read_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void read_to(void * dst, size_t size) = 0;

    // bytes read so far
    // 函数: n_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual size_t n_bytes() = 0;

    // 函数: read_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: read_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void read_string(std::string & str);
};
