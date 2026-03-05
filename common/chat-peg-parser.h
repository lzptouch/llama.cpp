#pragma once

#include "chat.h"
#include "peg-parser.h"

// 类: common_chat_peg_builder
// 描述: common_chat_peg_builder类提供相关功能
// 用途: 用于处理common_chat_peg_builder相关的操作
// 类: common_chat_peg_builder
// 描述: common_chat_peg_builder类提供相关功能
// 用途: 用于处理common_chat_peg_builder相关的操作
class common_chat_peg_builder : public common_peg_parser_builder {
  public:
    static constexpr const char * REASONING_BLOCK = "reasoning-block";
    static constexpr const char * REASONING = "reasoning";
    static constexpr const char * CONTENT = "content";

    // 函数: reasoning_block
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: reasoning_block
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser reasoning_block(const common_peg_parser & p) { return tag(REASONING_BLOCK, p); }
    // 函数: reasoning
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: reasoning
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser reasoning(const common_peg_parser & p) { return tag(REASONING, p); }
    // 函数: content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser content(const common_peg_parser & p) { return tag(CONTENT, p); }
};

// 函数: build_chat_peg_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
// 函数: build_chat_peg_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
inline common_peg_arena build_chat_peg_parser(const std::function<common_peg_parser(common_chat_peg_builder & builder)> & fn) {
    common_chat_peg_builder builder;
    builder.set_root(fn(builder));
    return builder.build();
}

// 类: common_chat_peg_mapper
// 描述: common_chat_peg_mapper类提供相关功能
// 用途: 用于处理common_chat_peg_mapper相关的操作
// 类: common_chat_peg_mapper
// 描述: common_chat_peg_mapper类提供相关功能
// 用途: 用于处理common_chat_peg_mapper相关的操作
class common_chat_peg_mapper {
  public:
    common_chat_msg & result;

    common_chat_peg_mapper(common_chat_msg & msg) : result(msg) {}

    // 函数: from_ast
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: from_ast
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void from_ast(const common_peg_ast_arena & arena, const common_peg_parse_result & result);
    // 函数: map
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: map
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void map(const common_peg_ast_node & node);
};

// 类: common_chat_peg_native_builder
// 描述: common_chat_peg_native_builder类提供相关功能
// 用途: 用于处理common_chat_peg_native_builder相关的操作
// 类: common_chat_peg_native_builder
// 描述: common_chat_peg_native_builder类提供相关功能
// 用途: 用于处理common_chat_peg_native_builder相关的操作
class common_chat_peg_native_builder : public common_chat_peg_builder {
  public:
    static constexpr const char * TOOL = "tool";
    static constexpr const char * TOOL_OPEN = "tool-open";
    static constexpr const char * TOOL_CLOSE = "tool-close";
    static constexpr const char * TOOL_ID = "tool-id";
    static constexpr const char * TOOL_NAME = "tool-name";
    static constexpr const char * TOOL_ARGS = "tool-args";

    // 函数: tool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool(const common_peg_parser & p) { return tag(TOOL, p); }
    // 函数: tool_open
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_open
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_open(const common_peg_parser & p) { return atomic(tag(TOOL_OPEN, p)); }
    // 函数: tool_close
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_close
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_close(const common_peg_parser & p) { return atomic(tag(TOOL_CLOSE, p)); }
    // 函数: tool_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_id(const common_peg_parser & p) { return atomic(tag(TOOL_ID, p)); }
    // 函数: tool_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_name(const common_peg_parser & p) { return atomic(tag(TOOL_NAME, p)); }
    // 函数: tool_args
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_args
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_args(const common_peg_parser & p) { return tag(TOOL_ARGS, p); }
};

// 类: common_chat_peg_native_mapper
// 描述: common_chat_peg_native_mapper类提供相关功能
// 用途: 用于处理common_chat_peg_native_mapper相关的操作
// 类: common_chat_peg_native_mapper
// 描述: common_chat_peg_native_mapper类提供相关功能
// 用途: 用于处理common_chat_peg_native_mapper相关的操作
class common_chat_peg_native_mapper : public common_chat_peg_mapper {
    common_chat_tool_call * current_tool;

  public:
    common_chat_peg_native_mapper(common_chat_msg & msg) : common_chat_peg_mapper(msg) {}

    // 函数: map
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: map
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void map(const common_peg_ast_node & node) override;
};

// 函数: build_chat_peg_native_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
// 函数: build_chat_peg_native_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
inline common_peg_arena build_chat_peg_native_parser(const std::function<common_peg_parser(common_chat_peg_native_builder & builder)> & fn) {
    common_chat_peg_native_builder builder;
    builder.set_root(fn(builder));
    return builder.build();
}

// 类: common_chat_peg_constructed_builder
// 描述: common_chat_peg_constructed_builder类提供相关功能
// 用途: 用于处理common_chat_peg_constructed_builder相关的操作
// 类: common_chat_peg_constructed_builder
// 描述: common_chat_peg_constructed_builder类提供相关功能
// 用途: 用于处理common_chat_peg_constructed_builder相关的操作
class common_chat_peg_constructed_builder : public common_chat_peg_builder {
  public:
    static constexpr const char * TOOL = "tool";
    static constexpr const char * TOOL_OPEN = "tool-open";
    static constexpr const char * TOOL_CLOSE = "tool-close";
    static constexpr const char * TOOL_NAME = "tool-name";
    static constexpr const char * TOOL_ARG = "tool-arg";
    static constexpr const char * TOOL_ARG_OPEN = "tool-arg-open";
    static constexpr const char * TOOL_ARG_CLOSE = "tool-arg-close";
    static constexpr const char * TOOL_ARG_NAME = "tool-arg-name";
    static constexpr const char * TOOL_ARG_STRING_VALUE = "tool-arg-string-value";
    static constexpr const char * TOOL_ARG_JSON_VALUE = "tool-arg-json-value";

    // 函数: tool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool(const common_peg_parser & p) { return tag(TOOL, p); }
    // 函数: tool_open
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_open
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_open(const common_peg_parser & p) { return atomic(tag(TOOL_OPEN, p)); }
    // 函数: tool_close
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_close
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_close(const common_peg_parser & p) { return atomic(tag(TOOL_CLOSE, p)); }
    // 函数: tool_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_name(const common_peg_parser & p) { return atomic(tag(TOOL_NAME, p)); }
    // 函数: tool_arg
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_arg
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_arg(const common_peg_parser & p) { return tag(TOOL_ARG, p); }
    // 函数: tool_arg_open
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_arg_open
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_arg_open(const common_peg_parser & p) { return atomic(tag(TOOL_ARG_OPEN, p)); }
    // 函数: tool_arg_close
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_arg_close
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_arg_close(const common_peg_parser & p) { return atomic(tag(TOOL_ARG_CLOSE, p)); }
    // 函数: tool_arg_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_arg_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_arg_name(const common_peg_parser & p) { return atomic(tag(TOOL_ARG_NAME, p)); }
    // 函数: tool_arg_string_value
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_arg_string_value
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_arg_string_value(const common_peg_parser & p) { return tag(TOOL_ARG_STRING_VALUE, p); }
    // 函数: tool_arg_json_value
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tool_arg_json_value
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tool_arg_json_value(const common_peg_parser & p) { return tag(TOOL_ARG_JSON_VALUE, p); }
};

// 类: common_chat_peg_constructed_mapper
// 描述: common_chat_peg_constructed_mapper类提供相关功能
// 用途: 用于处理common_chat_peg_constructed_mapper相关的操作
// 类: common_chat_peg_constructed_mapper
// 描述: common_chat_peg_constructed_mapper类提供相关功能
// 用途: 用于处理common_chat_peg_constructed_mapper相关的操作
class common_chat_peg_constructed_mapper : public common_chat_peg_mapper {
    common_chat_tool_call * current_tool;
    int arg_count = 0;
    bool needs_closing_quote = false;

  public:
    common_chat_peg_constructed_mapper(common_chat_msg & msg) : common_chat_peg_mapper(msg) {}

    // 函数: map
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: map
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void map(const common_peg_ast_node & node) override;
};

// 函数: build_chat_peg_constructed_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
// 函数: build_chat_peg_constructed_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
inline common_peg_arena build_chat_peg_constructed_parser(const std::function<common_peg_parser(common_chat_peg_constructed_builder & builder)> & fn) {
    common_chat_peg_constructed_builder builder;
    builder.set_root(fn(builder));
    return builder.build();
}
