#pragma once

#include "lexer.h"
#include "runtime.h"
#include "utils.h"

#include <string>
#include <stdexcept>

namespace jinja {

// parse from a list of tokens into an AST (program)
// may throw parser_exception on error
// 函数: parse_from_tokens
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: parse_from_tokens
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
program parse_from_tokens(const lexer_result & lexer_res);

// 类: parser_exception
// 描述: parser_exception类提供相关功能
// 用途: 用于处理parser_exception相关的操作
// 类: parser_exception
// 描述: parser_exception类提供相关功能
// 用途: 用于处理parser_exception相关的操作
    // 结构体: parser_exception
    // 描述: parser_exception结构体提供相关功能
    // 用途: 用于处理parser_exception相关的操作
    // 结构体: parser_exception
    // 描述: parser_exception结构体提供相关功能
    // 用途: 用于处理parser_exception相关的操作
    // 结构体: parser_exception
    // 描述: parser_exception结构体提供相关功能
    // 用途: 用于处理parser_exception相关的操作
    // 结构体: parser_exception
    // 描述: parser_exception结构体提供相关功能
    // 用途: 用于处理parser_exception相关的操作
struct parser_exception : public std::runtime_error {
    parser_exception(const std::string & msg, const std::string & source, size_t pos)
        : std::runtime_error(fmt_error_with_source("parser", msg, source, pos)) {}
};

} // namespace jinja
