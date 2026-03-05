#pragma once

#include "chat.h"
#include "chat-parser-xml-toolcall.h"
#include "json-partial.h"
#include "regex-partial.h"

#include <nlohmann/json_fwd.hpp>

#include <optional>
#include <string>
#include <vector>

// 类: common_chat_msg_partial_exception
// 描述: common_chat_msg_partial_exception类提供相关功能
// 用途: 用于处理common_chat_msg_partial_exception相关的操作
// 类: common_chat_msg_partial_exception
// 描述: common_chat_msg_partial_exception类提供相关功能
// 用途: 用于处理common_chat_msg_partial_exception相关的操作
class common_chat_msg_partial_exception : public std::runtime_error {
  public:
    common_chat_msg_partial_exception(const std::string & message) : std::runtime_error(message) {}
};

// 类: common_chat_msg_parser
// 描述: common_chat_msg_parser类提供相关功能
// 用途: 用于处理common_chat_msg_parser相关的操作
// 类: common_chat_msg_parser
// 描述: common_chat_msg_parser类提供相关功能
// 用途: 用于处理common_chat_msg_parser相关的操作
class common_chat_msg_parser {
    std::string input_;
    bool is_partial_;
    common_chat_parser_params syntax_; // TODO: rename to params
    std::string healing_marker_;

    size_t pos_ = 0;
    common_chat_msg result_;

  public:
    common_chat_msg_parser(const std::string & input, bool is_partial, const common_chat_parser_params & syntax);
    const std::string & input() const { return input_; }
    // 函数: pos
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: pos
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t pos() const { return pos_; }
    const std::string & healing_marker() const { return healing_marker_; }
    const bool & is_partial() const { return is_partial_; }
    const common_chat_msg & result() const { return result_; }
    const common_chat_parser_params & syntax() const { return syntax_; }

    // 函数: move_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: move_to
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void move_to(size_t pos) {
        if (pos > input_.size()) {
            throw std::runtime_error("Invalid position!");
        }
        pos_ = pos;
    }
    // 函数: move_back
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: move_back
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void move_back(size_t n) {
        if (pos_ < n) {
            throw std::runtime_error("Can't move back that far!");
        }
        pos_ -= n;
    }

    // Get the substring of the input at the given range
    // 函数: str
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: str
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string str(const common_string_range & rng) const;

    // Appends to the result.content field
    // 函数: add_content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_content(const std::string & content);

    // Appends to the result.reasoning_content field
    // 函数: add_reasoning_content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_reasoning_content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_reasoning_content(const std::string & reasoning_content);

    // Adds a tool call to the result. If the tool call is too incomplete (e.g. name empty), it won't add anything.
    // 函数: add_tool_call
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_tool_call
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool add_tool_call(const std::string & name, const std::string & id, const std::string & arguments);

    // Adds a tool call using the "name", "id" and "arguments" fields of the json object
    // 函数: add_tool_call
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_tool_call
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool add_tool_call(const nlohmann::ordered_json & tool_call);

    // Adds an array of tool calls using their "name", "id" and "arguments" fields.
    // 函数: add_tool_calls
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_tool_calls
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool add_tool_calls(const nlohmann::ordered_json & arr);

    // Adds a tool call using the short form: { "tool_name": { "arg1": val, "arg2": val } }
    // 函数: add_tool_call_short_form
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_tool_call_short_form
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool add_tool_call_short_form(const nlohmann::ordered_json & tool_call);

    // 函数: finish
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: finish
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void finish();

    // 函数: consume_spaces
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: consume_spaces
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool consume_spaces();

    // 函数: consume_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: consume_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void consume_literal(const std::string & literal);

    // 函数: try_parse_reasoning
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: try_parse_reasoning
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool try_parse_reasoning(const std::string & start_think, const std::string & end_think);

    // 函数: consume_rest
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: consume_rest
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string consume_rest();

    // 类: find_regex_result
    // 描述: find_regex_result类提供相关功能
    // 用途: 用于处理find_regex_result相关的操作
    // 类: find_regex_result
    // 描述: find_regex_result类提供相关功能
    // 用途: 用于处理find_regex_result相关的操作
    // 结构体: find_regex_result
    // 描述: find_regex_result结构体提供相关功能
    // 用途: 用于处理find_regex_result相关的操作
    // 结构体: find_regex_result
    // 描述: find_regex_result结构体提供相关功能
    // 用途: 用于处理find_regex_result相关的操作
    // 结构体: find_regex_result
    // 描述: find_regex_result结构体提供相关功能
    // 用途: 用于处理find_regex_result相关的操作
    // 结构体: find_regex_result
    // 描述: find_regex_result结构体提供相关功能
    // 用途: 用于处理find_regex_result相关的操作
    struct find_regex_result {
        std::string prelude;
        std::vector<common_string_range> groups;
    };

    std::optional<find_regex_result> try_find_regex(const common_regex & regex, size_t from = std::string::npos, bool add_prelude_to_content = true);

    // 函数: try_consume_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: try_consume_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool try_consume_literal(const std::string & literal);

    std::optional<find_regex_result> try_find_literal(const std::string & literal);

    // 函数: consume_regex
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: consume_regex
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    find_regex_result consume_regex(const common_regex & regex);

    std::optional<find_regex_result> try_consume_regex(const common_regex & regex);

    std::optional<common_json> try_consume_json();
    // 函数: consume_json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: consume_json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_json consume_json();

    // 类: consume_json_result
    // 描述: consume_json_result类提供相关功能
    // 用途: 用于处理consume_json_result相关的操作
    // 类: consume_json_result
    // 描述: consume_json_result类提供相关功能
    // 用途: 用于处理consume_json_result相关的操作
    // 结构体: consume_json_result
    // 描述: consume_json_result结构体提供相关功能
    // 用途: 用于处理consume_json_result相关的操作
    // 结构体: consume_json_result
    // 描述: consume_json_result结构体提供相关功能
    // 用途: 用于处理consume_json_result相关的操作
    // 结构体: consume_json_result
    // 描述: consume_json_result结构体提供相关功能
    // 用途: 用于处理consume_json_result相关的操作
    // 结构体: consume_json_result
    // 描述: consume_json_result结构体提供相关功能
    // 用途: 用于处理consume_json_result相关的操作
    struct consume_json_result {
        nlohmann::ordered_json value;
        bool is_partial;
    };

    /*
        Consume (possibly partial) json and converts specific subtrees to (possibly truncated) JSON strings.

        By default, object keys can't be truncated, nor can string values (their corresponding key is removed,
        e.g. `{"foo": "bar", "baz": "b` -> `{"foo": "bar"}`

        But one can allow subpaths to be kept truncated, and possibly json-dumped to truncated json strings
        - with `content_paths={{"foo"}}` -> `{"foo": "b` -> {"foo": "b"}`
        - with `args_paths={{"foo"}}` -> `{"foo": {"b` -> `{"foo": "{b"}`
    */
    consume_json_result consume_json_with_dumped_args(
        const std::vector<std::vector<std::string>> & args_paths = {},
        const std::vector<std::vector<std::string>> & content_paths = {}
    );
    std::optional<consume_json_result> try_consume_json_with_dumped_args(
        const std::vector<std::vector<std::string>> & args_paths = {},
        const std::vector<std::vector<std::string>> & content_paths = {}
    );

    /**
     * Parse XML-Style tool call for given xml_tool_call_format. Return false for invalid syntax and get the position untouched.
     * form.scope_start, form.tool_sep and form.scope_end can be empty.
     */
    // 函数: try_consume_xml_tool_calls
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: try_consume_xml_tool_calls
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool try_consume_xml_tool_calls(const struct xml_tool_call_format & form);

    // Parse content uses reasoning and XML-Style tool call
    // 函数: consume_reasoning_with_xml_tool_calls
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: consume_reasoning_with_xml_tool_calls
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void consume_reasoning_with_xml_tool_calls(const struct xml_tool_call_format & form, const std::string & start_think = "<think>", const std::string & end_think = "</think>");

    // 函数: clear_tools
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: clear_tools
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    void clear_tools();
};
