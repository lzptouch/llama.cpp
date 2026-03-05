#pragma once

#include <nlohmann/json_fwd.hpp>

#include <memory>
#include <unordered_map>
#include <string>
#include <string_view>
#include <functional>
#include <vector>
#include <variant>

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
struct common_grammar_builder;

// 类: common_peg_parser_builder
// 描述: common_peg_parser_builder类提供相关功能
// 用途: 用于处理common_peg_parser_builder相关的操作
// 类: common_peg_parser_builder
// 描述: common_peg_parser_builder类提供相关功能
// 用途: 用于处理common_peg_parser_builder相关的操作
class common_peg_parser_builder;

using common_peg_parser_id = size_t;
constexpr common_peg_parser_id COMMON_PEG_INVALID_PARSER_ID = static_cast<common_peg_parser_id>(-1);

using common_peg_ast_id = size_t;
constexpr common_peg_ast_id COMMON_PEG_INVALID_AST_ID = static_cast<common_peg_ast_id>(-1);

// Lightweight wrapper around common_peg_parser_id for convenience
// 类: common_peg_parser
// 描述: common_peg_parser类提供相关功能
// 用途: 用于处理common_peg_parser相关的操作
// 类: common_peg_parser
// 描述: common_peg_parser类提供相关功能
// 用途: 用于处理common_peg_parser相关的操作
class common_peg_parser {
    common_peg_parser_id id_;
    common_peg_parser_builder & builder_;

  public:
    common_peg_parser(const common_peg_parser & other) : id_(other.id_), builder_(other.builder_) {}
    common_peg_parser(common_peg_parser_id id, common_peg_parser_builder & builder) : id_(id), builder_(builder) {}

    common_peg_parser & operator=(const common_peg_parser & other);
    common_peg_parser & operator+=(const common_peg_parser & other);
    common_peg_parser & operator|=(const common_peg_parser & other);

    // 函数: common_peg_parser_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: common_peg_parser_id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    operator common_peg_parser_id() const { return id_; }
    // 函数: id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: id
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser_id id() const { return id_; }

    common_peg_parser_builder & builder() const { return builder_; }

    // Creates a sequence
    common_peg_parser operator+(const common_peg_parser & other) const;

    // Creates a sequence separated by spaces.
    common_peg_parser operator<<(const common_peg_parser & other) const;

    // Creates a choice
    common_peg_parser operator|(const common_peg_parser & other) const;

    common_peg_parser operator+(const char * str) const;
    common_peg_parser operator+(const std::string & str) const;
    common_peg_parser operator<<(const char * str) const;
    common_peg_parser operator<<(const std::string & str) const;
    common_peg_parser operator|(const char * str) const;
    common_peg_parser operator|(const std::string & str) const;
};

common_peg_parser operator+(const char * str, const common_peg_parser & p);
common_peg_parser operator+(const std::string & str, const common_peg_parser & p);
common_peg_parser operator<<(const char * str, const common_peg_parser & p);
common_peg_parser operator<<(const std::string & str, const common_peg_parser & p);
common_peg_parser operator|(const char * str, const common_peg_parser & p);
common_peg_parser operator|(const std::string & str, const common_peg_parser & p);

enum common_peg_parse_result_type {
    COMMON_PEG_PARSE_RESULT_FAIL            = 0,
    COMMON_PEG_PARSE_RESULT_SUCCESS         = 1,
    COMMON_PEG_PARSE_RESULT_NEED_MORE_INPUT = 2,
};

// 函数: common_peg_parse_result_type_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_peg_parse_result_type_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
const char * common_peg_parse_result_type_name(common_peg_parse_result_type type);

// 类: common_peg_ast_node
// 描述: common_peg_ast_node类提供相关功能
// 用途: 用于处理common_peg_ast_node相关的操作
// 类: common_peg_ast_node
// 描述: common_peg_ast_node类提供相关功能
// 用途: 用于处理common_peg_ast_node相关的操作
    // 结构体: common_peg_ast_node
    // 描述: common_peg_ast_node结构体提供相关功能
    // 用途: 用于处理common_peg_ast_node相关的操作
    // 结构体: common_peg_ast_node
    // 描述: common_peg_ast_node结构体提供相关功能
    // 用途: 用于处理common_peg_ast_node相关的操作
    // 结构体: common_peg_ast_node
    // 描述: common_peg_ast_node结构体提供相关功能
    // 用途: 用于处理common_peg_ast_node相关的操作
    // 结构体: common_peg_ast_node
    // 描述: common_peg_ast_node结构体提供相关功能
    // 用途: 用于处理common_peg_ast_node相关的操作
struct common_peg_ast_node {
    common_peg_ast_id id;
    std::string rule;
    std::string tag;
    size_t start;
    size_t end;
    std::string_view text;
    std::vector<common_peg_ast_id> children;

    bool is_partial = false;
};

// 类: common_peg_parse_result
// 描述: common_peg_parse_result类提供相关功能
// 用途: 用于处理common_peg_parse_result相关的操作
// 类: common_peg_parse_result
// 描述: common_peg_parse_result类提供相关功能
// 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
struct common_peg_parse_result;

using common_peg_ast_visitor = std::function<void(const common_peg_ast_node & node)>;

// 类: common_peg_ast_arena
// 描述: common_peg_ast_arena类提供相关功能
// 用途: 用于处理common_peg_ast_arena相关的操作
// 类: common_peg_ast_arena
// 描述: common_peg_ast_arena类提供相关功能
// 用途: 用于处理common_peg_ast_arena相关的操作
class common_peg_ast_arena {
    std::vector<common_peg_ast_node> nodes_;
  public:
    common_peg_ast_id add_node(
        const std::string & rule,
        const std::string & tag,
        size_t start,
        size_t end,
        std::string_view text,
        std::vector<common_peg_ast_id> children,
        bool is_partial = false
    ) {
        common_peg_ast_id id = nodes_.size();
        nodes_.push_back({id, rule, tag, start, end, text, std::move(children), is_partial});
        return id;
    }

    const common_peg_ast_node & get(common_peg_ast_id id) const { return nodes_.at(id); }

    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size() const { return nodes_.size(); }

    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    void clear() { nodes_.clear(); }

    // 函数: visit
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: visit
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void visit(common_peg_ast_id id, const common_peg_ast_visitor & visitor) const;
    // 函数: visit
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: visit
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void visit(const common_peg_parse_result & result, const common_peg_ast_visitor & visitor) const;
};

// 类: common_peg_parse_result
// 描述: common_peg_parse_result类提供相关功能
// 用途: 用于处理common_peg_parse_result相关的操作
// 类: common_peg_parse_result
// 描述: common_peg_parse_result类提供相关功能
// 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
    // 结构体: common_peg_parse_result
    // 描述: common_peg_parse_result结构体提供相关功能
    // 用途: 用于处理common_peg_parse_result相关的操作
struct common_peg_parse_result {
    common_peg_parse_result_type type = COMMON_PEG_PARSE_RESULT_FAIL;
    size_t start = 0;
    size_t end = 0;

    std::vector<common_peg_ast_id> nodes;

    common_peg_parse_result() = default;

    common_peg_parse_result(common_peg_parse_result_type type, size_t start)
        : type(type), start(start), end(start) {}

    common_peg_parse_result(common_peg_parse_result_type type, size_t start, size_t end)
        : type(type), start(start), end(end) {}

    common_peg_parse_result(common_peg_parse_result_type type, size_t start, size_t end, std::vector<common_peg_ast_id> nodes)
        : type(type), start(start), end(end), nodes(std::move(nodes)) {}

    // 函数: fail
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: fail
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool fail() const { return type == COMMON_PEG_PARSE_RESULT_FAIL; }
    // 函数: need_more_input
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: need_more_input
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool need_more_input() const { return type == COMMON_PEG_PARSE_RESULT_NEED_MORE_INPUT; }
    // 函数: success
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: success
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool success() const { return type == COMMON_PEG_PARSE_RESULT_SUCCESS; }
};

// 类: common_peg_parse_context
// 描述: common_peg_parse_context类提供相关功能
// 用途: 用于处理common_peg_parse_context相关的操作
// 类: common_peg_parse_context
// 描述: common_peg_parse_context类提供相关功能
// 用途: 用于处理common_peg_parse_context相关的操作
    // 结构体: common_peg_parse_context
    // 描述: common_peg_parse_context结构体提供相关功能
    // 用途: 用于处理common_peg_parse_context相关的操作
    // 结构体: common_peg_parse_context
    // 描述: common_peg_parse_context结构体提供相关功能
    // 用途: 用于处理common_peg_parse_context相关的操作
    // 结构体: common_peg_parse_context
    // 描述: common_peg_parse_context结构体提供相关功能
    // 用途: 用于处理common_peg_parse_context相关的操作
    // 结构体: common_peg_parse_context
    // 描述: common_peg_parse_context结构体提供相关功能
    // 用途: 用于处理common_peg_parse_context相关的操作
struct common_peg_parse_context {
    std::string input;
    bool is_partial;
    common_peg_ast_arena ast;

    int parse_depth;

    common_peg_parse_context()
        : is_partial(false), parse_depth(0) {}

    common_peg_parse_context(const std::string & input)
        : input(input), is_partial(false), parse_depth(0) {}

    common_peg_parse_context(const std::string & input, bool is_partial)
        : input(input), is_partial(is_partial), parse_depth(0) {}
};

// 类: common_peg_arena
// 描述: common_peg_arena类提供相关功能
// 用途: 用于处理common_peg_arena相关的操作
// 类: common_peg_arena
// 描述: common_peg_arena类提供相关功能
// 用途: 用于处理common_peg_arena相关的操作
class common_peg_arena;

// Parser variants
// 类: common_peg_epsilon_parser
// 描述: common_peg_epsilon_parser类提供相关功能
// 用途: 用于处理common_peg_epsilon_parser相关的操作
// 类: common_peg_epsilon_parser
// 描述: common_peg_epsilon_parser类提供相关功能
// 用途: 用于处理common_peg_epsilon_parser相关的操作
    // 结构体: common_peg_epsilon_parser
    // 描述: common_peg_epsilon_parser结构体提供相关功能
    // 用途: 用于处理common_peg_epsilon_parser相关的操作
    // 结构体: common_peg_epsilon_parser
    // 描述: common_peg_epsilon_parser结构体提供相关功能
    // 用途: 用于处理common_peg_epsilon_parser相关的操作
    // 结构体: common_peg_epsilon_parser
    // 描述: common_peg_epsilon_parser结构体提供相关功能
    // 用途: 用于处理common_peg_epsilon_parser相关的操作
    // 结构体: common_peg_epsilon_parser
    // 描述: common_peg_epsilon_parser结构体提供相关功能
    // 用途: 用于处理common_peg_epsilon_parser相关的操作
struct common_peg_epsilon_parser {};

// 类: common_peg_start_parser
// 描述: common_peg_start_parser类提供相关功能
// 用途: 用于处理common_peg_start_parser相关的操作
// 类: common_peg_start_parser
// 描述: common_peg_start_parser类提供相关功能
// 用途: 用于处理common_peg_start_parser相关的操作
    // 结构体: common_peg_start_parser
    // 描述: common_peg_start_parser结构体提供相关功能
    // 用途: 用于处理common_peg_start_parser相关的操作
    // 结构体: common_peg_start_parser
    // 描述: common_peg_start_parser结构体提供相关功能
    // 用途: 用于处理common_peg_start_parser相关的操作
    // 结构体: common_peg_start_parser
    // 描述: common_peg_start_parser结构体提供相关功能
    // 用途: 用于处理common_peg_start_parser相关的操作
    // 结构体: common_peg_start_parser
    // 描述: common_peg_start_parser结构体提供相关功能
    // 用途: 用于处理common_peg_start_parser相关的操作
struct common_peg_start_parser {};

// 类: common_peg_end_parser
// 描述: common_peg_end_parser类提供相关功能
// 用途: 用于处理common_peg_end_parser相关的操作
// 类: common_peg_end_parser
// 描述: common_peg_end_parser类提供相关功能
// 用途: 用于处理common_peg_end_parser相关的操作
    // 结构体: common_peg_end_parser
    // 描述: common_peg_end_parser结构体提供相关功能
    // 用途: 用于处理common_peg_end_parser相关的操作
    // 结构体: common_peg_end_parser
    // 描述: common_peg_end_parser结构体提供相关功能
    // 用途: 用于处理common_peg_end_parser相关的操作
    // 结构体: common_peg_end_parser
    // 描述: common_peg_end_parser结构体提供相关功能
    // 用途: 用于处理common_peg_end_parser相关的操作
    // 结构体: common_peg_end_parser
    // 描述: common_peg_end_parser结构体提供相关功能
    // 用途: 用于处理common_peg_end_parser相关的操作
struct common_peg_end_parser {};

// 类: common_peg_literal_parser
// 描述: common_peg_literal_parser类提供相关功能
// 用途: 用于处理common_peg_literal_parser相关的操作
// 类: common_peg_literal_parser
// 描述: common_peg_literal_parser类提供相关功能
// 用途: 用于处理common_peg_literal_parser相关的操作
    // 结构体: common_peg_literal_parser
    // 描述: common_peg_literal_parser结构体提供相关功能
    // 用途: 用于处理common_peg_literal_parser相关的操作
    // 结构体: common_peg_literal_parser
    // 描述: common_peg_literal_parser结构体提供相关功能
    // 用途: 用于处理common_peg_literal_parser相关的操作
    // 结构体: common_peg_literal_parser
    // 描述: common_peg_literal_parser结构体提供相关功能
    // 用途: 用于处理common_peg_literal_parser相关的操作
    // 结构体: common_peg_literal_parser
    // 描述: common_peg_literal_parser结构体提供相关功能
    // 用途: 用于处理common_peg_literal_parser相关的操作
struct common_peg_literal_parser {
    std::string literal;
};

// 类: common_peg_sequence_parser
// 描述: common_peg_sequence_parser类提供相关功能
// 用途: 用于处理common_peg_sequence_parser相关的操作
// 类: common_peg_sequence_parser
// 描述: common_peg_sequence_parser类提供相关功能
// 用途: 用于处理common_peg_sequence_parser相关的操作
    // 结构体: common_peg_sequence_parser
    // 描述: common_peg_sequence_parser结构体提供相关功能
    // 用途: 用于处理common_peg_sequence_parser相关的操作
    // 结构体: common_peg_sequence_parser
    // 描述: common_peg_sequence_parser结构体提供相关功能
    // 用途: 用于处理common_peg_sequence_parser相关的操作
    // 结构体: common_peg_sequence_parser
    // 描述: common_peg_sequence_parser结构体提供相关功能
    // 用途: 用于处理common_peg_sequence_parser相关的操作
    // 结构体: common_peg_sequence_parser
    // 描述: common_peg_sequence_parser结构体提供相关功能
    // 用途: 用于处理common_peg_sequence_parser相关的操作
struct common_peg_sequence_parser {
    std::vector<common_peg_parser_id> children;
};

// 类: common_peg_choice_parser
// 描述: common_peg_choice_parser类提供相关功能
// 用途: 用于处理common_peg_choice_parser相关的操作
// 类: common_peg_choice_parser
// 描述: common_peg_choice_parser类提供相关功能
// 用途: 用于处理common_peg_choice_parser相关的操作
    // 结构体: common_peg_choice_parser
    // 描述: common_peg_choice_parser结构体提供相关功能
    // 用途: 用于处理common_peg_choice_parser相关的操作
    // 结构体: common_peg_choice_parser
    // 描述: common_peg_choice_parser结构体提供相关功能
    // 用途: 用于处理common_peg_choice_parser相关的操作
    // 结构体: common_peg_choice_parser
    // 描述: common_peg_choice_parser结构体提供相关功能
    // 用途: 用于处理common_peg_choice_parser相关的操作
    // 结构体: common_peg_choice_parser
    // 描述: common_peg_choice_parser结构体提供相关功能
    // 用途: 用于处理common_peg_choice_parser相关的操作
struct common_peg_choice_parser {
    std::vector<common_peg_parser_id> children;
};

// 类: common_peg_repetition_parser
// 描述: common_peg_repetition_parser类提供相关功能
// 用途: 用于处理common_peg_repetition_parser相关的操作
// 类: common_peg_repetition_parser
// 描述: common_peg_repetition_parser类提供相关功能
// 用途: 用于处理common_peg_repetition_parser相关的操作
    // 结构体: common_peg_repetition_parser
    // 描述: common_peg_repetition_parser结构体提供相关功能
    // 用途: 用于处理common_peg_repetition_parser相关的操作
    // 结构体: common_peg_repetition_parser
    // 描述: common_peg_repetition_parser结构体提供相关功能
    // 用途: 用于处理common_peg_repetition_parser相关的操作
    // 结构体: common_peg_repetition_parser
    // 描述: common_peg_repetition_parser结构体提供相关功能
    // 用途: 用于处理common_peg_repetition_parser相关的操作
    // 结构体: common_peg_repetition_parser
    // 描述: common_peg_repetition_parser结构体提供相关功能
    // 用途: 用于处理common_peg_repetition_parser相关的操作
struct common_peg_repetition_parser {
    common_peg_parser_id child;
    int min_count;
    int max_count;  // -1 for unbounded
};

// 类: common_peg_and_parser
// 描述: common_peg_and_parser类提供相关功能
// 用途: 用于处理common_peg_and_parser相关的操作
// 类: common_peg_and_parser
// 描述: common_peg_and_parser类提供相关功能
// 用途: 用于处理common_peg_and_parser相关的操作
    // 结构体: common_peg_and_parser
    // 描述: common_peg_and_parser结构体提供相关功能
    // 用途: 用于处理common_peg_and_parser相关的操作
    // 结构体: common_peg_and_parser
    // 描述: common_peg_and_parser结构体提供相关功能
    // 用途: 用于处理common_peg_and_parser相关的操作
    // 结构体: common_peg_and_parser
    // 描述: common_peg_and_parser结构体提供相关功能
    // 用途: 用于处理common_peg_and_parser相关的操作
    // 结构体: common_peg_and_parser
    // 描述: common_peg_and_parser结构体提供相关功能
    // 用途: 用于处理common_peg_and_parser相关的操作
struct common_peg_and_parser {
    common_peg_parser_id child;
};

// 类: common_peg_not_parser
// 描述: common_peg_not_parser类提供相关功能
// 用途: 用于处理common_peg_not_parser相关的操作
// 类: common_peg_not_parser
// 描述: common_peg_not_parser类提供相关功能
// 用途: 用于处理common_peg_not_parser相关的操作
    // 结构体: common_peg_not_parser
    // 描述: common_peg_not_parser结构体提供相关功能
    // 用途: 用于处理common_peg_not_parser相关的操作
    // 结构体: common_peg_not_parser
    // 描述: common_peg_not_parser结构体提供相关功能
    // 用途: 用于处理common_peg_not_parser相关的操作
    // 结构体: common_peg_not_parser
    // 描述: common_peg_not_parser结构体提供相关功能
    // 用途: 用于处理common_peg_not_parser相关的操作
    // 结构体: common_peg_not_parser
    // 描述: common_peg_not_parser结构体提供相关功能
    // 用途: 用于处理common_peg_not_parser相关的操作
struct common_peg_not_parser {
    common_peg_parser_id child;
};

// 类: common_peg_any_parser
// 描述: common_peg_any_parser类提供相关功能
// 用途: 用于处理common_peg_any_parser相关的操作
// 类: common_peg_any_parser
// 描述: common_peg_any_parser类提供相关功能
// 用途: 用于处理common_peg_any_parser相关的操作
    // 结构体: common_peg_any_parser
    // 描述: common_peg_any_parser结构体提供相关功能
    // 用途: 用于处理common_peg_any_parser相关的操作
    // 结构体: common_peg_any_parser
    // 描述: common_peg_any_parser结构体提供相关功能
    // 用途: 用于处理common_peg_any_parser相关的操作
    // 结构体: common_peg_any_parser
    // 描述: common_peg_any_parser结构体提供相关功能
    // 用途: 用于处理common_peg_any_parser相关的操作
    // 结构体: common_peg_any_parser
    // 描述: common_peg_any_parser结构体提供相关功能
    // 用途: 用于处理common_peg_any_parser相关的操作
struct common_peg_any_parser {};

// 类: common_peg_space_parser
// 描述: common_peg_space_parser类提供相关功能
// 用途: 用于处理common_peg_space_parser相关的操作
// 类: common_peg_space_parser
// 描述: common_peg_space_parser类提供相关功能
// 用途: 用于处理common_peg_space_parser相关的操作
    // 结构体: common_peg_space_parser
    // 描述: common_peg_space_parser结构体提供相关功能
    // 用途: 用于处理common_peg_space_parser相关的操作
    // 结构体: common_peg_space_parser
    // 描述: common_peg_space_parser结构体提供相关功能
    // 用途: 用于处理common_peg_space_parser相关的操作
    // 结构体: common_peg_space_parser
    // 描述: common_peg_space_parser结构体提供相关功能
    // 用途: 用于处理common_peg_space_parser相关的操作
    // 结构体: common_peg_space_parser
    // 描述: common_peg_space_parser结构体提供相关功能
    // 用途: 用于处理common_peg_space_parser相关的操作
struct common_peg_space_parser {};

// 类: common_peg_chars_parser
// 描述: common_peg_chars_parser类提供相关功能
// 用途: 用于处理common_peg_chars_parser相关的操作
// 类: common_peg_chars_parser
// 描述: common_peg_chars_parser类提供相关功能
// 用途: 用于处理common_peg_chars_parser相关的操作
    // 结构体: common_peg_chars_parser
    // 描述: common_peg_chars_parser结构体提供相关功能
    // 用途: 用于处理common_peg_chars_parser相关的操作
    // 结构体: common_peg_chars_parser
    // 描述: common_peg_chars_parser结构体提供相关功能
    // 用途: 用于处理common_peg_chars_parser相关的操作
    // 结构体: common_peg_chars_parser
    // 描述: common_peg_chars_parser结构体提供相关功能
    // 用途: 用于处理common_peg_chars_parser相关的操作
    // 结构体: common_peg_chars_parser
    // 描述: common_peg_chars_parser结构体提供相关功能
    // 用途: 用于处理common_peg_chars_parser相关的操作
struct common_peg_chars_parser {
    // 类: char_range
    // 描述: char_range类提供相关功能
    // 用途: 用于处理char_range相关的操作
    // 类: char_range
    // 描述: char_range类提供相关功能
    // 用途: 用于处理char_range相关的操作
    // 结构体: char_range
    // 描述: char_range结构体提供相关功能
    // 用途: 用于处理char_range相关的操作
    // 结构体: char_range
    // 描述: char_range结构体提供相关功能
    // 用途: 用于处理char_range相关的操作
    // 结构体: char_range
    // 描述: char_range结构体提供相关功能
    // 用途: 用于处理char_range相关的操作
    // 结构体: char_range
    // 描述: char_range结构体提供相关功能
    // 用途: 用于处理char_range相关的操作
    struct char_range {
        uint32_t start;
        uint32_t end;
        // 函数: contains
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: contains
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        bool contains(uint32_t codepoint) const { return codepoint >= start && codepoint <= end; }
    };

    std::string pattern;
    std::vector<char_range> ranges;
    bool negated;
    int min_count;
    int max_count;  // -1 for unbounded
};

// 类: common_peg_json_string_parser
// 描述: common_peg_json_string_parser类提供相关功能
// 用途: 用于处理common_peg_json_string_parser相关的操作
// 类: common_peg_json_string_parser
// 描述: common_peg_json_string_parser类提供相关功能
// 用途: 用于处理common_peg_json_string_parser相关的操作
    // 结构体: common_peg_json_string_parser
    // 描述: common_peg_json_string_parser结构体提供相关功能
    // 用途: 用于处理common_peg_json_string_parser相关的操作
    // 结构体: common_peg_json_string_parser
    // 描述: common_peg_json_string_parser结构体提供相关功能
    // 用途: 用于处理common_peg_json_string_parser相关的操作
    // 结构体: common_peg_json_string_parser
    // 描述: common_peg_json_string_parser结构体提供相关功能
    // 用途: 用于处理common_peg_json_string_parser相关的操作
    // 结构体: common_peg_json_string_parser
    // 描述: common_peg_json_string_parser结构体提供相关功能
    // 用途: 用于处理common_peg_json_string_parser相关的操作
struct common_peg_json_string_parser {};

// 类: common_peg_until_parser
// 描述: common_peg_until_parser类提供相关功能
// 用途: 用于处理common_peg_until_parser相关的操作
// 类: common_peg_until_parser
// 描述: common_peg_until_parser类提供相关功能
// 用途: 用于处理common_peg_until_parser相关的操作
    // 结构体: common_peg_until_parser
    // 描述: common_peg_until_parser结构体提供相关功能
    // 用途: 用于处理common_peg_until_parser相关的操作
    // 结构体: common_peg_until_parser
    // 描述: common_peg_until_parser结构体提供相关功能
    // 用途: 用于处理common_peg_until_parser相关的操作
    // 结构体: common_peg_until_parser
    // 描述: common_peg_until_parser结构体提供相关功能
    // 用途: 用于处理common_peg_until_parser相关的操作
    // 结构体: common_peg_until_parser
    // 描述: common_peg_until_parser结构体提供相关功能
    // 用途: 用于处理common_peg_until_parser相关的操作
struct common_peg_until_parser {
    std::vector<std::string> delimiters;
};

// 类: common_peg_schema_parser
// 描述: common_peg_schema_parser类提供相关功能
// 用途: 用于处理common_peg_schema_parser相关的操作
// 类: common_peg_schema_parser
// 描述: common_peg_schema_parser类提供相关功能
// 用途: 用于处理common_peg_schema_parser相关的操作
    // 结构体: common_peg_schema_parser
    // 描述: common_peg_schema_parser结构体提供相关功能
    // 用途: 用于处理common_peg_schema_parser相关的操作
    // 结构体: common_peg_schema_parser
    // 描述: common_peg_schema_parser结构体提供相关功能
    // 用途: 用于处理common_peg_schema_parser相关的操作
    // 结构体: common_peg_schema_parser
    // 描述: common_peg_schema_parser结构体提供相关功能
    // 用途: 用于处理common_peg_schema_parser相关的操作
    // 结构体: common_peg_schema_parser
    // 描述: common_peg_schema_parser结构体提供相关功能
    // 用途: 用于处理common_peg_schema_parser相关的操作
struct common_peg_schema_parser {
    common_peg_parser_id child;
    std::string name;
    std::shared_ptr<nlohmann::ordered_json> schema;

    // Indicates if the GBNF should accept a raw string that matches the schema.
    bool raw;
};

// 类: common_peg_rule_parser
// 描述: common_peg_rule_parser类提供相关功能
// 用途: 用于处理common_peg_rule_parser相关的操作
// 类: common_peg_rule_parser
// 描述: common_peg_rule_parser类提供相关功能
// 用途: 用于处理common_peg_rule_parser相关的操作
    // 结构体: common_peg_rule_parser
    // 描述: common_peg_rule_parser结构体提供相关功能
    // 用途: 用于处理common_peg_rule_parser相关的操作
    // 结构体: common_peg_rule_parser
    // 描述: common_peg_rule_parser结构体提供相关功能
    // 用途: 用于处理common_peg_rule_parser相关的操作
    // 结构体: common_peg_rule_parser
    // 描述: common_peg_rule_parser结构体提供相关功能
    // 用途: 用于处理common_peg_rule_parser相关的操作
    // 结构体: common_peg_rule_parser
    // 描述: common_peg_rule_parser结构体提供相关功能
    // 用途: 用于处理common_peg_rule_parser相关的操作
struct common_peg_rule_parser {
    std::string name;
    common_peg_parser_id child;
    bool trigger;
};

// 类: common_peg_ref_parser
// 描述: common_peg_ref_parser类提供相关功能
// 用途: 用于处理common_peg_ref_parser相关的操作
// 类: common_peg_ref_parser
// 描述: common_peg_ref_parser类提供相关功能
// 用途: 用于处理common_peg_ref_parser相关的操作
    // 结构体: common_peg_ref_parser
    // 描述: common_peg_ref_parser结构体提供相关功能
    // 用途: 用于处理common_peg_ref_parser相关的操作
    // 结构体: common_peg_ref_parser
    // 描述: common_peg_ref_parser结构体提供相关功能
    // 用途: 用于处理common_peg_ref_parser相关的操作
    // 结构体: common_peg_ref_parser
    // 描述: common_peg_ref_parser结构体提供相关功能
    // 用途: 用于处理common_peg_ref_parser相关的操作
    // 结构体: common_peg_ref_parser
    // 描述: common_peg_ref_parser结构体提供相关功能
    // 用途: 用于处理common_peg_ref_parser相关的操作
struct common_peg_ref_parser {
    std::string name;
};

// 类: common_peg_atomic_parser
// 描述: common_peg_atomic_parser类提供相关功能
// 用途: 用于处理common_peg_atomic_parser相关的操作
// 类: common_peg_atomic_parser
// 描述: common_peg_atomic_parser类提供相关功能
// 用途: 用于处理common_peg_atomic_parser相关的操作
    // 结构体: common_peg_atomic_parser
    // 描述: common_peg_atomic_parser结构体提供相关功能
    // 用途: 用于处理common_peg_atomic_parser相关的操作
    // 结构体: common_peg_atomic_parser
    // 描述: common_peg_atomic_parser结构体提供相关功能
    // 用途: 用于处理common_peg_atomic_parser相关的操作
    // 结构体: common_peg_atomic_parser
    // 描述: common_peg_atomic_parser结构体提供相关功能
    // 用途: 用于处理common_peg_atomic_parser相关的操作
    // 结构体: common_peg_atomic_parser
    // 描述: common_peg_atomic_parser结构体提供相关功能
    // 用途: 用于处理common_peg_atomic_parser相关的操作
struct common_peg_atomic_parser {
    common_peg_parser_id child;
};

// 类: common_peg_tag_parser
// 描述: common_peg_tag_parser类提供相关功能
// 用途: 用于处理common_peg_tag_parser相关的操作
// 类: common_peg_tag_parser
// 描述: common_peg_tag_parser类提供相关功能
// 用途: 用于处理common_peg_tag_parser相关的操作
    // 结构体: common_peg_tag_parser
    // 描述: common_peg_tag_parser结构体提供相关功能
    // 用途: 用于处理common_peg_tag_parser相关的操作
    // 结构体: common_peg_tag_parser
    // 描述: common_peg_tag_parser结构体提供相关功能
    // 用途: 用于处理common_peg_tag_parser相关的操作
    // 结构体: common_peg_tag_parser
    // 描述: common_peg_tag_parser结构体提供相关功能
    // 用途: 用于处理common_peg_tag_parser相关的操作
    // 结构体: common_peg_tag_parser
    // 描述: common_peg_tag_parser结构体提供相关功能
    // 用途: 用于处理common_peg_tag_parser相关的操作
struct common_peg_tag_parser {
    common_peg_parser_id child;
    std::string tag;
};

// Variant holding all parser types
using common_peg_parser_variant = std::variant<
    common_peg_epsilon_parser,
    common_peg_start_parser,
    common_peg_end_parser,
    common_peg_literal_parser,
    common_peg_sequence_parser,
    common_peg_choice_parser,
    common_peg_repetition_parser,
    common_peg_and_parser,
    common_peg_not_parser,
    common_peg_any_parser,
    common_peg_space_parser,
    common_peg_chars_parser,
    common_peg_json_string_parser,
    common_peg_until_parser,
    common_peg_schema_parser,
    common_peg_rule_parser,
    common_peg_ref_parser,
    common_peg_atomic_parser,
    common_peg_tag_parser
>;

// 类: common_peg_arena
// 描述: common_peg_arena类提供相关功能
// 用途: 用于处理common_peg_arena相关的操作
// 类: common_peg_arena
// 描述: common_peg_arena类提供相关功能
// 用途: 用于处理common_peg_arena相关的操作
class common_peg_arena {
    std::vector<common_peg_parser_variant> parsers_;
    std::unordered_map<std::string, common_peg_parser_id> rules_;
    common_peg_parser_id root_ = COMMON_PEG_INVALID_PARSER_ID;

  public:
    const common_peg_parser_variant & get(common_peg_parser_id id) const { return parsers_.at(id); }
    common_peg_parser_variant & get(common_peg_parser_id id) { return parsers_.at(id); }

    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size() const { return parsers_.size(); }
    // 函数: empty
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: empty
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool empty() const { return parsers_.empty(); }

    // 函数: get_rule
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_rule
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    common_peg_parser_id get_rule(const std::string & name) const;
    // 函数: has_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: has_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool has_rule(const std::string & name) const { return rules_.find(name) != rules_.end(); }

    // 函数: root
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: root
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser_id root() const { return root_; }
    // 函数: set_root
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_root
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_root(common_peg_parser_id id) { root_ = id; }

    // 函数: parse
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: parse
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parse_result parse(common_peg_parse_context & ctx, size_t start = 0) const;
    // 函数: parse
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: parse
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parse_result parse(common_peg_parser_id id, common_peg_parse_context & ctx, size_t start) const;

    // 函数: resolve_refs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: resolve_refs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void resolve_refs();

    // 函数: build_grammar
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_grammar
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    void build_grammar(const common_grammar_builder & builder, bool lazy = false) const;

    // 函数: dump
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: dump
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string dump(common_peg_parser_id id) const;

    // 函数: to_json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: to_json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    nlohmann::json to_json() const;
    // 函数: from_json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: from_json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static common_peg_arena from_json(const nlohmann::json & j);

    // 函数: save
    // 描述: 保存: 保存数据到文件或内存
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: save
    // 描述: 保存: 保存数据到文件或内存
    // 参数: 无参数
    // 返回: 无返回值
    std::string save() const;
    // 函数: load
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load(const std::string & data);

    friend class common_peg_parser_builder;

  private:
    // 函数: add_parser
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_parser
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser_id add_parser(common_peg_parser_variant parser);
    // 函数: add_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_rule(const std::string & name, common_peg_parser_id id);

    // 函数: resolve_ref
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: resolve_ref
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser_id resolve_ref(common_peg_parser_id id);
};

// 类: common_peg_parser_builder
// 描述: common_peg_parser_builder类提供相关功能
// 用途: 用于处理common_peg_parser_builder相关的操作
// 类: common_peg_parser_builder
// 描述: common_peg_parser_builder类提供相关功能
// 用途: 用于处理common_peg_parser_builder相关的操作
class common_peg_parser_builder {
    common_peg_arena arena_;

    // 函数: wrap
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: wrap
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser wrap(common_peg_parser_id id) { return common_peg_parser(id, *this); }
    // 函数: add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser add(const common_peg_parser_variant & p) { return wrap(arena_.add_parser(p)); }

  public:
    common_peg_parser_builder();

    // Match nothing, always succeed.
    //   S -> ε
    // 函数: eps
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: eps
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser eps() { return add(common_peg_epsilon_parser{}); }

    // Matches the start of the input.
    //   S -> ^
    // 函数: start
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: start
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser start() { return add(common_peg_start_parser{}); }

    // Matches the end of the input.
    //   S -> $
    // 函数: end
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: end
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser end() { return add(common_peg_end_parser{}); }

    // Matches an exact literal string.
    //   S -> "hello"
    // 函数: literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser literal(const std::string & literal) { return add(common_peg_literal_parser{literal}); }

    // Matches a sequence of parsers in order, all must succeed.
    //   S -> A B C
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser sequence() { return add(common_peg_sequence_parser{}); }
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser sequence(const std::vector<common_peg_parser_id> & parsers);
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser sequence(const std::vector<common_peg_parser> & parsers);
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: sequence
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser sequence(std::initializer_list<common_peg_parser> parsers);

    // Matches the first parser that succeeds from a list of alternatives.
    //   S -> A | B | C
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser choice() { return add(common_peg_choice_parser{}); }
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser choice(const std::vector<common_peg_parser_id> & parsers);
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser choice(const std::vector<common_peg_parser> & parsers);
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: choice
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser choice(std::initializer_list<common_peg_parser> parsers);

    // Matches one or more repetitions of a parser.
    //   S -> A+
    // 函数: one_or_more
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: one_or_more
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser one_or_more(const common_peg_parser & p) { return repeat(p, 1, -1); }

    // Matches zero or more repetitions of a parser, always succeeds.
    //   S -> A*
    // 函数: zero_or_more
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: zero_or_more
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser zero_or_more(const common_peg_parser & p) { return repeat(p, 0, -1); }

    // Matches zero or one occurrence of a parser, always succeeds.
    //   S -> A?
    // 函数: optional
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: optional
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser optional(const common_peg_parser & p) { return repeat(p, 0, 1); }

    // Positive lookahead: succeeds if child parser succeeds, consumes no input.
    //   S -> &A
    // 函数: peek
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: peek
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser peek(const common_peg_parser & p) { return add(common_peg_and_parser{p}); }

    // Negative lookahead: succeeds if child parser fails, consumes no input.
    //   S -> !A
    // 函数: negate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: negate
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser negate(const common_peg_parser & p) { return add(common_peg_not_parser{p}); }

    // Matches any single character.
    //   S -> .
    // 函数: any
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: any
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser any() { return add(common_peg_any_parser{}); }

    // Matches between min and max repetitions of characters from a character class.
    //   S -> [a-z]{m,n}
    //
    // Use -1 for max to represent unbounded repetition (equivalent to {m,})
    // 函数: chars
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: chars
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser chars(const std::string & classes, int min = 1, int max = -1);

    // Creates a lightweight reference to a named rule (resolved during build()).
    // Use this for forward references in recursive grammars.
    //   expr_ref -> expr
    // 函数: ref
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ref
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser ref(const std::string & name) { return add(common_peg_ref_parser{name}); }

    // Matches zero or more whitespace characters (space, tab, newline).
    //   S -> [ \t\n]*
    // 函数: space
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: space
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser space() { return add(common_peg_space_parser{}); }

    // Matches all characters until a delimiter is found (delimiter not consumed).
    //   S -> (!delim .)*
    // 函数: until
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: until
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser until(const std::string & delimiter) { return add(common_peg_until_parser{{delimiter}}); }

    // Matches all characters until one of the delimiters in the list is found (delimiter not consumed).
    //   S -> (!delim .)*
    // 函数: until_one_of
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: until_one_of
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser until_one_of(const std::vector<std::string> & delimiters) { return add(common_peg_until_parser{delimiters}); }

    // Matches everything
    //   S -> .*
    // 函数: rest
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: rest
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser rest() { return until_one_of({}); }

    // Matches between min and max repetitions of a parser (inclusive).
    //   S -> A{m,n}
    // Use -1 for max to represent unbounded repetition (equivalent to {m,})
    // 函数: repeat
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: repeat
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser repeat(const common_peg_parser & p, int min, int max) { return add(common_peg_repetition_parser{p, min,max}); }

    // Matches exactly n repetitions of a parser.
    //   S -> A{n}
    // 函数: repeat
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: repeat
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser repeat(const common_peg_parser & p, int n) { return repeat(p, n, n); }

    // Creates a complete JSON parser supporting objects, arrays, strings, numbers, booleans, and null.
    //   value -> object | array | string | number | true | false | null
    // 函数: json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json();
    // 函数: json_object
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_object
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_object();
    // 函数: json_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_string();
    // 函数: json_array
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_array
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_array();
    // 函数: json_number
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_number
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_number();
    // 函数: json_bool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_bool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_bool();
    // 函数: json_null
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_null
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_null();

    // Matches JSON string content without the surrounding quotes.
    // Useful for extracting content within a JSON string.
    // 函数: json_string_content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_string_content
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_string_content();

    // Matches a JSON object member with a key and associated parser as the
    // value.
    // 函数: json_member
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: json_member
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser json_member(const std::string & key, const common_peg_parser & p);

    // Wraps a parser with JSON schema metadata for grammar generation.
    // Used internally to convert JSON schemas to GBNF grammar rules.
    // 函数: schema
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: schema
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser schema(const common_peg_parser & p, const std::string & name, const nlohmann::ordered_json & schema, bool raw = false);

    // Creates a named rule, stores it in the grammar, and returns a ref.
    // If trigger=true, marks this rule as an entry point for lazy grammar generation.
    //   auto json = p.rule("json", json_obj | json_arr | ...)
    // 函数: rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser rule(const std::string & name, const common_peg_parser & p, bool trigger = false);

    // Creates a named rule using a builder function, and returns a ref.
    // If trigger=true, marks this rule as an entry point for lazy grammar generation.
    //   auto json = p.rule("json", [&]() { return json_object() | json_array() | ... })
    // 函数: rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser rule(const std::string & name, const std::function<common_peg_parser()> & builder, bool trigger = false);

    // Creates a trigger rule. When generating a lazy grammar from the parser,
    // only trigger rules and descendents are emitted.
    // 函数: trigger_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: trigger_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser trigger_rule(const std::string & name, const common_peg_parser & p) { return rule(name, p, true); }
    // 函数: trigger_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: trigger_rule
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser trigger_rule(const std::string & name, const std::function<common_peg_parser()> & builder) { return rule(name, builder, true); }

    // Creates an atomic parser. Atomic parsers do not create an AST node if
    // the child results in a partial parse, i.e. NEEDS_MORE_INPUT. This is
    // intended for situations where partial output is undesirable.
    // 函数: atomic
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: atomic
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser atomic(const common_peg_parser & p) { return add(common_peg_atomic_parser{p}); }

    // Tags create nodes in the generated AST for semantic purposes.
    // Unlike rules, you can tag multiple nodes with the same tag.
    // 函数: tag
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tag
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_parser tag(const std::string & tag, const common_peg_parser & p) { return add(common_peg_tag_parser{p.id(), tag}); }

    // 函数: set_root
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_root
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_root(const common_peg_parser & p);

    // 函数: build
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    common_peg_arena build();
};

// Helper function for building parsers
// 函数: build_peg_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
// 函数: build_peg_parser
// 描述: 构建: 构建数据结构或对象
// 参数: 无参数
// 返回: 无返回值
common_peg_arena build_peg_parser(const std::function<common_peg_parser(common_peg_parser_builder & builder)> & fn);
