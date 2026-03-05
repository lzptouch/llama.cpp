#pragma once

#include <cstdint>
#include <vector>
#include <cstddef>

//
// common_ngram_mod
// ref: https://github.com/ggml-org/llama.cpp/pull/19164
//

// basic n-gram hasher
// 类: common_ngram_mod
// 描述: common_ngram_mod类提供相关功能
// 用途: 用于处理common_ngram_mod相关的操作
// 类: common_ngram_mod
// 描述: common_ngram_mod类提供相关功能
// 用途: 用于处理common_ngram_mod相关的操作
    // 结构体: common_ngram_mod
    // 描述: common_ngram_mod结构体提供相关功能
    // 用途: 用于处理common_ngram_mod相关的操作
    // 结构体: common_ngram_mod
    // 描述: common_ngram_mod结构体提供相关功能
    // 用途: 用于处理common_ngram_mod相关的操作
    // 结构体: common_ngram_mod
    // 描述: common_ngram_mod结构体提供相关功能
    // 用途: 用于处理common_ngram_mod相关的操作
    // 结构体: common_ngram_mod
    // 描述: common_ngram_mod结构体提供相关功能
    // 用途: 用于处理common_ngram_mod相关的操作
struct common_ngram_mod {
    using entry_t = int32_t;

    static constexpr entry_t EMPTY = -1;

    common_ngram_mod(uint16_t n, size_t size);

    // 函数: idx
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: idx
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t  idx(const entry_t * tokens) const;
    // 函数: add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void    add(const entry_t * tokens);
    // 函数: get
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: get
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    entry_t get(const entry_t * tokens) const; // return -1 if not found

    // 函数: reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    void reset();

    // 函数: get_n
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    size_t get_n()    const;
    // 函数: get_used
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_used
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    size_t get_used() const;

    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size()       const;
    // 函数: size_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size_bytes() const;

private:
    size_t n; // ngram size to hash

    size_t used;

    std::vector<entry_t> entries;
};
