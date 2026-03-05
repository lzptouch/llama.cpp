#pragma once

#include <optional>
#include <string>
#include <vector>

#include "utils.h"

namespace jinja {

// allow differentiate between user input strings and template strings
// transformations should handle this information as follows:
// - one-to-one (e.g., uppercase, lowercase): preserve is_input flag
// - one-to-many (e.g., strip): if input string is marked as is_input, all resulting parts should be marked as is_input
// - many-to-one (e.g., concat): if ALL input parts are marked as is_input, resulting part should be marked as is_input
// 类: string_part
// 描述: string_part类提供相关功能
// 用途: 用于处理string_part相关的操作
// 类: string_part
// 描述: string_part类提供相关功能
// 用途: 用于处理string_part相关的操作
    // 结构体: string_part
    // 描述: string_part结构体提供相关功能
    // 用途: 用于处理string_part相关的操作
    // 结构体: string_part
    // 描述: string_part结构体提供相关功能
    // 用途: 用于处理string_part相关的操作
    // 结构体: string_part
    // 描述: string_part结构体提供相关功能
    // 用途: 用于处理string_part相关的操作
    // 结构体: string_part
    // 描述: string_part结构体提供相关功能
    // 用途: 用于处理string_part相关的操作
struct string_part {
    bool is_input = false; // may skip parsing special tokens if true
    std::string val;

    // 函数: is_uppercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_uppercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_uppercase() const;
    // 函数: is_lowercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_lowercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_lowercase() const;
};

// 类: string
// 描述: string类提供相关功能
// 用途: 用于处理string相关的操作
// 类: string
// 描述: string类提供相关功能
// 用途: 用于处理string相关的操作
    // 结构体: string
    // 描述: string结构体提供相关功能
    // 用途: 用于处理string相关的操作
    // 结构体: string
    // 描述: string结构体提供相关功能
    // 用途: 用于处理string相关的操作
    // 结构体: string
    // 描述: string结构体提供相关功能
    // 用途: 用于处理string相关的操作
    // 结构体: string
    // 描述: string结构体提供相关功能
    // 用途: 用于处理string相关的操作
struct string {
    std::vector<string_part> parts;
    string() = default;
    string(const std::string & v, bool user_input = false) {
        parts.push_back({user_input, v});
    }
    string(int v) {
        parts.push_back({false, std::to_string(v)});
    }
    string(double v) {
        parts.push_back({false, std::to_string(v)});
    }

    // mark all parts as user input
    // 函数: mark_input
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: mark_input
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void mark_input();

    // 函数: str
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: str
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string str() const;
    // 函数: length
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: length
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t length() const;
    // 函数: hash_update
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: hash_update
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    void hash_update(hasher & hash) const noexcept;
    // 函数: all_parts_are_input
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: all_parts_are_input
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool all_parts_are_input() const;
    // 函数: is_uppercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_uppercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_uppercase() const;
    // 函数: is_lowercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_lowercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_lowercase() const;

    // mark this string as input if other has ALL parts as input
    // 函数: mark_input_based_on
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: mark_input_based_on
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void mark_input_based_on(const string & other);

    // 函数: append
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: append
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    string append(const string & other);

    // in-place transformations

    // 函数: uppercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: uppercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    string uppercase();
    // 函数: lowercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: lowercase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    string lowercase();
    // 函数: capitalize
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: capitalize
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    string capitalize();
    // 函数: titlecase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: titlecase
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    string titlecase();
    // 函数: strip
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: strip
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    string strip(bool left, bool right, std::optional<const std::string_view> chars = std::nullopt);
};

} // namespace jinja
