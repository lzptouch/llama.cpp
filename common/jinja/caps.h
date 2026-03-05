#pragma once

#include "runtime.h"

#include <string>
#include <map>

namespace jinja {

// 类: caps
// 描述: caps类提供相关功能
// 用途: 用于处理caps相关的操作
// 类: caps
// 描述: caps类提供相关功能
// 用途: 用于处理caps相关的操作
    // 结构体: caps
    // 描述: caps结构体提供相关功能
    // 用途: 用于处理caps相关的操作
    // 结构体: caps
    // 描述: caps结构体提供相关功能
    // 用途: 用于处理caps相关的操作
    // 结构体: caps
    // 描述: caps结构体提供相关功能
    // 用途: 用于处理caps相关的操作
    // 结构体: caps
    // 描述: caps结构体提供相关功能
    // 用途: 用于处理caps相关的操作
struct caps {
    bool supports_tools = true;
    bool supports_tool_calls = true;
    bool supports_system_role = true;
    bool supports_parallel_tool_calls = true;
    bool supports_preserve_reasoning = false; // support assistant message with reasoning_content

    // one of the 2 content capabilities must be true
    bool supports_string_content = true;
    bool supports_typed_content = false;

    // for reporting on server
    std::map<std::string, bool> to_map() const;

    // for debugging
    // 函数: to_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: to_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string to_string() const;
};

// 函数: caps_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: caps_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
caps caps_get(jinja::program & prog);

} // namespace jinja
