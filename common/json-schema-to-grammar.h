#pragma once

#include <nlohmann/json_fwd.hpp>

#include <functional>
#include <memory>
#include <string>

std::string json_schema_to_grammar(const nlohmann::ordered_json & schema,
                                   bool force_gbnf = false);

// 类: common_schema_converter
// 描述: common_schema_converter类提供相关功能
// 用途: 用于处理common_schema_converter相关的操作
// 类: common_schema_converter
// 描述: common_schema_converter类提供相关功能
// 用途: 用于处理common_schema_converter相关的操作
class common_schema_converter;

// Probes a JSON schema to extract information about its structure and type constraints.
// 类: common_schema_info
// 描述: common_schema_info类提供相关功能
// 用途: 用于处理common_schema_info相关的操作
// 类: common_schema_info
// 描述: common_schema_info类提供相关功能
// 用途: 用于处理common_schema_info相关的操作
class common_schema_info {
    std::unique_ptr<common_schema_converter> impl_;

  public:
    common_schema_info();
    ~common_schema_info();

    common_schema_info(const common_schema_info &) = delete;
    common_schema_info & operator=(const common_schema_info &) = delete;
    common_schema_info(common_schema_info &&) noexcept;
    common_schema_info & operator=(common_schema_info &&) noexcept;

    // 函数: resolve_refs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: resolve_refs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void resolve_refs(nlohmann::ordered_json & schema);
    // 函数: resolves_to_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: resolves_to_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool resolves_to_string(const nlohmann::ordered_json & schema);
};

// 类: common_grammar_builder
// 描述: common_grammar_builder类提供相关功能
// 用途: 用于处理common_grammar_builder相关的操作
// 类: common_grammar_builder
// 描述: common_grammar_builder类提供相关功能
// 用途: 用于处理common_grammar_builder相关的操作
    // 结构体: common_grammar_builder
    // 描述: common_grammar_builder结构体提供相关功能
    // 用途: 用于处理common_grammar_builder相关的操作
    // 结构体: common_grammar_builder
    // 描述: common_grammar_builder结构体提供相关功能
    // 用途: 用于处理common_grammar_builder相关的操作
    // 结构体: common_grammar_builder
    // 描述: common_grammar_builder结构体提供相关功能
    // 用途: 用于处理common_grammar_builder相关的操作
    // 结构体: common_grammar_builder
    // 描述: common_grammar_builder结构体提供相关功能
    // 用途: 用于处理common_grammar_builder相关的操作
struct common_grammar_builder {
    std::function<std::string(const std::string &, const std::string &)> add_rule;
    std::function<std::string(const std::string &, const nlohmann::ordered_json &)> add_schema;
    std::function<void(nlohmann::ordered_json &)> resolve_refs;
};

// 类: common_grammar_options
// 描述: common_grammar_options类提供相关功能
// 用途: 用于处理common_grammar_options相关的操作
// 类: common_grammar_options
// 描述: common_grammar_options类提供相关功能
// 用途: 用于处理common_grammar_options相关的操作
    // 结构体: common_grammar_options
    // 描述: common_grammar_options结构体提供相关功能
    // 用途: 用于处理common_grammar_options相关的操作
    // 结构体: common_grammar_options
    // 描述: common_grammar_options结构体提供相关功能
    // 用途: 用于处理common_grammar_options相关的操作
    // 结构体: common_grammar_options
    // 描述: common_grammar_options结构体提供相关功能
    // 用途: 用于处理common_grammar_options相关的操作
    // 结构体: common_grammar_options
    // 描述: common_grammar_options结构体提供相关功能
    // 用途: 用于处理common_grammar_options相关的操作
struct common_grammar_options {
    bool dotall = false;
};

// 函数: gbnf_format_literal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: gbnf_format_literal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string gbnf_format_literal(const std::string & literal);

// 函数: build_grammar
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
// 函数: build_grammar
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
std::string build_grammar(const std::function<void(const common_grammar_builder &)> & cb, const common_grammar_options & options = {});
