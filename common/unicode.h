#pragma once

#include <cstdint>
#include <string_view>

// UTF-8 parsing utilities for streaming-aware unicode support

// 类: utf8_parse_result
// 描述: utf8_parse_result类提供相关功能
// 用途: 用于处理utf8_parse_result相关的操作
// 类: utf8_parse_result
// 描述: utf8_parse_result类提供相关功能
// 用途: 用于处理utf8_parse_result相关的操作
    // 结构体: utf8_parse_result
    // 描述: utf8_parse_result结构体提供相关功能
    // 用途: 用于处理utf8_parse_result相关的操作
    // 结构体: utf8_parse_result
    // 描述: utf8_parse_result结构体提供相关功能
    // 用途: 用于处理utf8_parse_result相关的操作
    // 结构体: utf8_parse_result
    // 描述: utf8_parse_result结构体提供相关功能
    // 用途: 用于处理utf8_parse_result相关的操作
    // 结构体: utf8_parse_result
    // 描述: utf8_parse_result结构体提供相关功能
    // 用途: 用于处理utf8_parse_result相关的操作
struct utf8_parse_result {
    uint32_t codepoint;      // Decoded codepoint (only valid if status == SUCCESS)
    size_t bytes_consumed;   // How many bytes this codepoint uses (1-4)
    enum status { SUCCESS, INCOMPLETE, INVALID } status;

    utf8_parse_result(enum status s, uint32_t cp = 0, size_t bytes = 0)
        : codepoint(cp), bytes_consumed(bytes), status(s) {}
};

// Determine the expected length of a UTF-8 sequence from its first byte
// Returns 0 for invalid first bytes
// 函数: utf8_sequence_length
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: utf8_sequence_length
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t utf8_sequence_length(unsigned char first_byte);

// Parse a single UTF-8 codepoint from input
// 函数: parse_utf8_codepoint
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: parse_utf8_codepoint
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
utf8_parse_result parse_utf8_codepoint(std::string_view input, size_t offset);
