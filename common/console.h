// Console functions

#pragma once

#include "common.h"

#include <string>

enum display_type {
    DISPLAY_TYPE_RESET = 0,
    DISPLAY_TYPE_INFO,
    DISPLAY_TYPE_PROMPT,
    DISPLAY_TYPE_REASONING,
    DISPLAY_TYPE_USER_INPUT,
    DISPLAY_TYPE_ERROR
};

namespace console {
    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    void init(bool use_simple_io, bool use_advanced_display);
    // 函数: cleanup
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cleanup
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void cleanup();
    // 函数: set_display
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_display
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_display(display_type display);
    // 函数: readline
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: readline
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool readline(std::string & line, bool multiline_input);

    namespace spinner {
        // 函数: start
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: start
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        void start();
        // 函数: stop
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: stop
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        void stop();
    }

    // note: the logging API below output directly to stdout
    // it can negatively impact performance if used on inference thread
    // only use in in a dedicated CLI thread
    // for logging in inference thread, use log.h instead

    LLAMA_COMMON_ATTRIBUTE_FORMAT(1, 2)
    // 函数: log
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: log
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void log(const char * fmt, ...);

    LLAMA_COMMON_ATTRIBUTE_FORMAT(1, 2)
    // 函数: error
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: error
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void error(const char * fmt, ...);

    // 函数: flush
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: flush
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void flush();
}
