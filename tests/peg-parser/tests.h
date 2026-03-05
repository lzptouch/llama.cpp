#pragma once

// Common includes for all test files
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "../testing.h"
#include "peg-parser.h"
#include "chat-peg-parser.h"
#include "simple-tokenize.h"

// 类: bench_tool_call
// 描述: bench_tool_call类提供相关功能
// 用途: 用于处理bench_tool_call相关的操作
// 类: bench_tool_call
// 描述: bench_tool_call类提供相关功能
// 用途: 用于处理bench_tool_call相关的操作
    // 结构体: bench_tool_call
    // 描述: bench_tool_call结构体提供相关功能
    // 用途: 用于处理bench_tool_call相关的操作
    // 结构体: bench_tool_call
    // 描述: bench_tool_call结构体提供相关功能
    // 用途: 用于处理bench_tool_call相关的操作
    // 结构体: bench_tool_call
    // 描述: bench_tool_call结构体提供相关功能
    // 用途: 用于处理bench_tool_call相关的操作
    // 结构体: bench_tool_call
    // 描述: bench_tool_call结构体提供相关功能
    // 用途: 用于处理bench_tool_call相关的操作
struct bench_tool_call {
    std::string            id;
    std::string            name;
    nlohmann::ordered_json args;
};

// Test function declarations
// 函数: test_basic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: test_basic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void test_basic(testing &t);
// 函数: test_json_parser
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: test_json_parser
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void test_json_parser(testing &t);
// 函数: test_gbnf_generation
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: test_gbnf_generation
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void test_gbnf_generation(testing &t);
// 函数: test_unicode
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: test_unicode
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void test_unicode(testing &t);
// 函数: test_json_serialization
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: test_json_serialization
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void test_json_serialization(testing &t);
