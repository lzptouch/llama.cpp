#pragma once

#include <regex>
#include <string>

enum common_regex_match_type {
    COMMON_REGEX_MATCH_TYPE_NONE,
    COMMON_REGEX_MATCH_TYPE_PARTIAL,
    COMMON_REGEX_MATCH_TYPE_FULL,
};

// 类: common_string_range
// 描述: common_string_range类提供相关功能
// 用途: 用于处理common_string_range相关的操作
// 类: common_string_range
// 描述: common_string_range类提供相关功能
// 用途: 用于处理common_string_range相关的操作
    // 结构体: common_string_range
    // 描述: common_string_range结构体提供相关功能
    // 用途: 用于处理common_string_range相关的操作
    // 结构体: common_string_range
    // 描述: common_string_range结构体提供相关功能
    // 用途: 用于处理common_string_range相关的操作
    // 结构体: common_string_range
    // 描述: common_string_range结构体提供相关功能
    // 用途: 用于处理common_string_range相关的操作
    // 结构体: common_string_range
    // 描述: common_string_range结构体提供相关功能
    // 用途: 用于处理common_string_range相关的操作
struct common_string_range {
    size_t begin;
    size_t end;
    common_string_range(size_t begin, size_t end) : begin(begin), end(end) {
        if (begin > end) {
            throw std::runtime_error("Invalid range");
        }
    }
    // prevent default ctor
    common_string_range() = delete;
    // 函数: empty
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: empty
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool empty() const {
        return begin == end;
    }
    bool operator==(const common_string_range & other) const {
        return begin == other.begin && end == other.end;
    }
};

// 类: common_regex_match
// 描述: common_regex_match类提供相关功能
// 用途: 用于处理common_regex_match相关的操作
// 类: common_regex_match
// 描述: common_regex_match类提供相关功能
// 用途: 用于处理common_regex_match相关的操作
    // 结构体: common_regex_match
    // 描述: common_regex_match结构体提供相关功能
    // 用途: 用于处理common_regex_match相关的操作
    // 结构体: common_regex_match
    // 描述: common_regex_match结构体提供相关功能
    // 用途: 用于处理common_regex_match相关的操作
    // 结构体: common_regex_match
    // 描述: common_regex_match结构体提供相关功能
    // 用途: 用于处理common_regex_match相关的操作
    // 结构体: common_regex_match
    // 描述: common_regex_match结构体提供相关功能
    // 用途: 用于处理common_regex_match相关的操作
struct common_regex_match {
    common_regex_match_type type = COMMON_REGEX_MATCH_TYPE_NONE;
    std::vector<common_string_range> groups;

    bool operator==(const common_regex_match & other) const {
        return type == other.type && groups == other.groups;
    }
    bool operator!=(const common_regex_match & other) const {
        return !(*this == other);
    }
};

// 类: common_regex
// 描述: common_regex类提供相关功能
// 用途: 用于处理common_regex相关的操作
// 类: common_regex
// 描述: common_regex类提供相关功能
// 用途: 用于处理common_regex相关的操作
class common_regex {
    std::string pattern;
    std::regex rx;
    std::regex rx_reversed_partial;

  public:
    // 函数: common_regex
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: common_regex
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit common_regex(const std::string & pattern);

    // 函数: search
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: search
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_regex_match search(const std::string & input, size_t pos, bool as_match = false) const;

    const std::string & str() const { return pattern; }
};

// For testing only (pretty print of failures).
// 函数: regex_to_reversed_partial_regex
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: regex_to_reversed_partial_regex
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string regex_to_reversed_partial_regex(const std::string & pattern);
