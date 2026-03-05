#pragma once

#include "lexer.h"
#include "value.h"

#include <cassert>
#include <ctime>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#define JJ_DEBUG(msg, ...)  do { if (g_jinja_debug) printf("%s:%-3d : " msg "\n", FILENAME, __LINE__, __VA_ARGS__); } while (0)

extern bool g_jinja_debug;

namespace jinja {

// 类: statement
// 描述: statement类提供相关功能
// 用途: 用于处理statement相关的操作
// 类: statement
// 描述: statement类提供相关功能
// 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
struct statement;
using statement_ptr = std::unique_ptr<statement>;
using statements = std::vector<statement_ptr>;

// Helpers for dynamic casting and type checking
template<typename T>
// 类: extract_pointee_unique
// 描述: extract_pointee_unique类提供相关功能
// 用途: 用于处理extract_pointee_unique相关的操作
// 类: extract_pointee_unique
// 描述: extract_pointee_unique类提供相关功能
// 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
struct extract_pointee_unique {
    using type = T;
};
template<typename U>
// 类: extract_pointee_unique
// 描述: extract_pointee_unique类提供相关功能
// 用途: 用于处理extract_pointee_unique相关的操作
// 类: extract_pointee_unique
// 描述: extract_pointee_unique类提供相关功能
// 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
    // 结构体: extract_pointee_unique
    // 描述: extract_pointee_unique结构体提供相关功能
    // 用途: 用于处理extract_pointee_unique相关的操作
struct extract_pointee_unique<std::unique_ptr<U>> {
    using type = U;
};
template<typename T>
// 函数: is_stmt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: is_stmt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool is_stmt(const statement_ptr & ptr) {
    return dynamic_cast<const T*>(ptr.get()) != nullptr;
}
template<typename T>
// 函数: cast_stmt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: cast_stmt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
T * cast_stmt(statement_ptr & ptr) {
    return dynamic_cast<T*>(ptr.get());
}
template<typename T>
// 函数: cast_stmt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: cast_stmt
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
const T * cast_stmt(const statement_ptr & ptr) {
    return dynamic_cast<const T*>(ptr.get());
}
// End Helpers


// not thread-safe
// 函数: enable_debug
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: enable_debug
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void enable_debug(bool enable);

// 类: context
// 描述: context类提供相关功能
// 用途: 用于处理context相关的操作
// 类: context
// 描述: context类提供相关功能
// 用途: 用于处理context相关的操作
    // 结构体: context
    // 描述: context结构体提供相关功能
    // 用途: 用于处理context相关的操作
    // 结构体: context
    // 描述: context结构体提供相关功能
    // 用途: 用于处理context相关的操作
    // 结构体: context
    // 描述: context结构体提供相关功能
    // 用途: 用于处理context相关的操作
    // 结构体: context
    // 描述: context结构体提供相关功能
    // 用途: 用于处理context相关的操作
struct context {
    std::shared_ptr<std::string> src; // for debugging; use shared_ptr to avoid copying on scope creation
    std::time_t current_time; // for functions that need current time

    bool is_get_stats = false; // whether to collect stats

    // src is optional, used for error reporting
    context(std::string src = "") : src(std::make_shared<std::string>(std::move(src))) {
        env = mk_val<value_object>();
        env->has_builtins = false; // context object has no builtins
        env->insert("true",  mk_val<value_bool>(true));
        env->insert("True",  mk_val<value_bool>(true));
        env->insert("false", mk_val<value_bool>(false));
        env->insert("False", mk_val<value_bool>(false));
        env->insert("none",  mk_val<value_none>());
        env->insert("None",  mk_val<value_none>());
        current_time = std::time(nullptr);
    }
    ~context() = default;

    context(const context & parent) : context() {
        // inherit variables (for example, when entering a new scope)
        auto & pvar = parent.env->as_ordered_object();
        for (const auto & pair : pvar) {
            set_val(pair.first, pair.second);
        }
        current_time = parent.current_time;
        is_get_stats = parent.is_get_stats;
        src = parent.src;
    }

    // 函数: get_val
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_val
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    value get_val(const std::string & name) {
        value default_val = mk_val<value_undefined>(name);
        return env->at(name, default_val);
    }

    // 函数: set_val
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_val
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_val(const std::string & name, const value & val) {
        env->insert(name, val);
    }

    // 函数: set_val
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_val
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_val(const value & name, const value & val) {
        env->insert(name, val);
    }

    // 函数: print_vars
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: print_vars
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void print_vars() const {
        printf("Context Variables:\n%s\n", value_to_json(env, 2).c_str());
    }

private:
    value_object env;
};

/**
 * Base class for all nodes in the AST.
 */
// 类: statement
// 描述: statement类提供相关功能
// 用途: 用于处理statement相关的操作
// 类: statement
// 描述: statement类提供相关功能
// 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
    // 结构体: statement
    // 描述: statement结构体提供相关功能
    // 用途: 用于处理statement相关的操作
struct statement {
    size_t pos; // position in source, for debugging
    virtual ~statement() = default;
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual std::string type() const { return "Statement"; }
    // execute_impl must be overridden by derived classes
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual value execute_impl(context &) { throw std::runtime_error("cannot exec " + type()); }
    // execute is the public method to execute a statement with error handling
    // 函数: execute
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute(context &);
};

// Type Checking Utilities

template<typename T>
// 函数: chk_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: chk_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void chk_type(const statement_ptr & ptr) {
    if (!ptr) return; // Allow null for optional fields
    assert(dynamic_cast<T *>(ptr.get()) != nullptr);
}

template<typename T, typename U>
// 函数: chk_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: chk_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void chk_type(const statement_ptr & ptr) {
    if (!ptr) return;
    assert(dynamic_cast<T *>(ptr.get()) != nullptr || dynamic_cast<U *>(ptr.get()) != nullptr);
}

// Base Types

/**
 * Expressions will result in a value at runtime (unlike statements).
 */
// 类: expression
// 描述: expression类提供相关功能
// 用途: 用于处理expression相关的操作
// 类: expression
// 描述: expression类提供相关功能
// 用途: 用于处理expression相关的操作
    // 结构体: expression
    // 描述: expression结构体提供相关功能
    // 用途: 用于处理expression相关的操作
    // 结构体: expression
    // 描述: expression结构体提供相关功能
    // 用途: 用于处理expression相关的操作
    // 结构体: expression
    // 描述: expression结构体提供相关功能
    // 用途: 用于处理expression相关的操作
    // 结构体: expression
    // 描述: expression结构体提供相关功能
    // 用途: 用于处理expression相关的操作
struct expression : public statement {
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Expression"; }
};

// Statements

// 类: program
// 描述: program类提供相关功能
// 用途: 用于处理program相关的操作
// 类: program
// 描述: program类提供相关功能
// 用途: 用于处理program相关的操作
    // 结构体: program
    // 描述: program结构体提供相关功能
    // 用途: 用于处理program相关的操作
    // 结构体: program
    // 描述: program结构体提供相关功能
    // 用途: 用于处理program相关的操作
    // 结构体: program
    // 描述: program结构体提供相关功能
    // 用途: 用于处理program相关的操作
    // 结构体: program
    // 描述: program结构体提供相关功能
    // 用途: 用于处理program相关的操作
struct program : public statement {
    statements body;

    program() = default;
    // 函数: program
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: program
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit program(statements && body) : body(std::move(body)) {}
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Program"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        throw std::runtime_error("Cannot execute program directly, use jinja::runtime instead");
    }
};

// 类: if_statement
// 描述: if_statement类提供相关功能
// 用途: 用于处理if_statement相关的操作
// 类: if_statement
// 描述: if_statement类提供相关功能
// 用途: 用于处理if_statement相关的操作
    // 结构体: if_statement
    // 描述: if_statement结构体提供相关功能
    // 用途: 用于处理if_statement相关的操作
    // 结构体: if_statement
    // 描述: if_statement结构体提供相关功能
    // 用途: 用于处理if_statement相关的操作
    // 结构体: if_statement
    // 描述: if_statement结构体提供相关功能
    // 用途: 用于处理if_statement相关的操作
    // 结构体: if_statement
    // 描述: if_statement结构体提供相关功能
    // 用途: 用于处理if_statement相关的操作
struct if_statement : public statement {
    statement_ptr test;
    statements body;
    statements alternate;

    if_statement(statement_ptr && test, statements && body, statements && alternate)
        : test(std::move(test)), body(std::move(body)), alternate(std::move(alternate)) {
        chk_type<expression>(this->test);
    }

    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "If"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: identifier
// 描述: identifier类提供相关功能
// 用途: 用于处理identifier相关的操作
// 类: identifier
// 描述: identifier类提供相关功能
// 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
struct identifier;
// 类: tuple_literal
// 描述: tuple_literal类提供相关功能
// 用途: 用于处理tuple_literal相关的操作
// 类: tuple_literal
// 描述: tuple_literal类提供相关功能
// 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
struct tuple_literal;

/**
 * Loop over each item in a sequence
 * https://jinja.palletsprojects.com/en/3.0.x/templates/#for
 */
// 类: for_statement
// 描述: for_statement类提供相关功能
// 用途: 用于处理for_statement相关的操作
// 类: for_statement
// 描述: for_statement类提供相关功能
// 用途: 用于处理for_statement相关的操作
    // 结构体: for_statement
    // 描述: for_statement结构体提供相关功能
    // 用途: 用于处理for_statement相关的操作
    // 结构体: for_statement
    // 描述: for_statement结构体提供相关功能
    // 用途: 用于处理for_statement相关的操作
    // 结构体: for_statement
    // 描述: for_statement结构体提供相关功能
    // 用途: 用于处理for_statement相关的操作
    // 结构体: for_statement
    // 描述: for_statement结构体提供相关功能
    // 用途: 用于处理for_statement相关的操作
struct for_statement : public statement {
    statement_ptr loopvar; // Identifier | TupleLiteral
    statement_ptr iterable;
    statements body;
    statements default_block; // if no iteration took place

    for_statement(statement_ptr && loopvar, statement_ptr && iterable, statements && body, statements && default_block)
        : loopvar(std::move(loopvar)), iterable(std::move(iterable)),
          body(std::move(body)), default_block(std::move(default_block)) {
        chk_type<identifier, tuple_literal>(this->loopvar);
        chk_type<expression>(this->iterable);
    }

    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "For"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: break_statement
// 描述: break_statement类提供相关功能
// 用途: 用于处理break_statement相关的操作
// 类: break_statement
// 描述: break_statement类提供相关功能
// 用途: 用于处理break_statement相关的操作
    // 结构体: break_statement
    // 描述: break_statement结构体提供相关功能
    // 用途: 用于处理break_statement相关的操作
    // 结构体: break_statement
    // 描述: break_statement结构体提供相关功能
    // 用途: 用于处理break_statement相关的操作
    // 结构体: break_statement
    // 描述: break_statement结构体提供相关功能
    // 用途: 用于处理break_statement相关的操作
    // 结构体: break_statement
    // 描述: break_statement结构体提供相关功能
    // 用途: 用于处理break_statement相关的操作
struct break_statement : public statement {
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Break"; }

    // 类: signal
    // 描述: signal类提供相关功能
    // 用途: 用于处理signal相关的操作
    // 类: signal
    // 描述: signal类提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    struct signal : public std::exception {
        const char* what() const noexcept override {
            return "Break statement executed";
        }
    };

    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        throw break_statement::signal();
    }
};

// 类: continue_statement
// 描述: continue_statement类提供相关功能
// 用途: 用于处理continue_statement相关的操作
// 类: continue_statement
// 描述: continue_statement类提供相关功能
// 用途: 用于处理continue_statement相关的操作
    // 结构体: continue_statement
    // 描述: continue_statement结构体提供相关功能
    // 用途: 用于处理continue_statement相关的操作
    // 结构体: continue_statement
    // 描述: continue_statement结构体提供相关功能
    // 用途: 用于处理continue_statement相关的操作
    // 结构体: continue_statement
    // 描述: continue_statement结构体提供相关功能
    // 用途: 用于处理continue_statement相关的操作
    // 结构体: continue_statement
    // 描述: continue_statement结构体提供相关功能
    // 用途: 用于处理continue_statement相关的操作
struct continue_statement : public statement {
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Continue"; }

    // 类: signal
    // 描述: signal类提供相关功能
    // 用途: 用于处理signal相关的操作
    // 类: signal
    // 描述: signal类提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    // 结构体: signal
    // 描述: signal结构体提供相关功能
    // 用途: 用于处理signal相关的操作
    struct signal : public std::exception {
        const char* what() const noexcept override {
            return "Continue statement executed";
        }
    };

    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        throw continue_statement::signal();
    }
};

// do nothing
// 类: noop_statement
// 描述: noop_statement类提供相关功能
// 用途: 用于处理noop_statement相关的操作
// 类: noop_statement
// 描述: noop_statement类提供相关功能
// 用途: 用于处理noop_statement相关的操作
    // 结构体: noop_statement
    // 描述: noop_statement结构体提供相关功能
    // 用途: 用于处理noop_statement相关的操作
    // 结构体: noop_statement
    // 描述: noop_statement结构体提供相关功能
    // 用途: 用于处理noop_statement相关的操作
    // 结构体: noop_statement
    // 描述: noop_statement结构体提供相关功能
    // 用途: 用于处理noop_statement相关的操作
    // 结构体: noop_statement
    // 描述: noop_statement结构体提供相关功能
    // 用途: 用于处理noop_statement相关的操作
struct noop_statement : public statement {
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Noop"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        return mk_val<value_undefined>();
    }
};

// 类: set_statement
// 描述: set_statement类提供相关功能
// 用途: 用于处理set_statement相关的操作
// 类: set_statement
// 描述: set_statement类提供相关功能
// 用途: 用于处理set_statement相关的操作
    // 结构体: set_statement
    // 描述: set_statement结构体提供相关功能
    // 用途: 用于处理set_statement相关的操作
    // 结构体: set_statement
    // 描述: set_statement结构体提供相关功能
    // 用途: 用于处理set_statement相关的操作
    // 结构体: set_statement
    // 描述: set_statement结构体提供相关功能
    // 用途: 用于处理set_statement相关的操作
    // 结构体: set_statement
    // 描述: set_statement结构体提供相关功能
    // 用途: 用于处理set_statement相关的操作
struct set_statement : public statement {
    statement_ptr assignee;
    statement_ptr val;
    statements body;

    set_statement(statement_ptr && assignee, statement_ptr && value, statements && body)
        : assignee(std::move(assignee)), val(std::move(value)), body(std::move(body)) {
        chk_type<expression>(this->assignee);
        chk_type<expression>(this->val);
    }

    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Set"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: macro_statement
// 描述: macro_statement类提供相关功能
// 用途: 用于处理macro_statement相关的操作
// 类: macro_statement
// 描述: macro_statement类提供相关功能
// 用途: 用于处理macro_statement相关的操作
    // 结构体: macro_statement
    // 描述: macro_statement结构体提供相关功能
    // 用途: 用于处理macro_statement相关的操作
    // 结构体: macro_statement
    // 描述: macro_statement结构体提供相关功能
    // 用途: 用于处理macro_statement相关的操作
    // 结构体: macro_statement
    // 描述: macro_statement结构体提供相关功能
    // 用途: 用于处理macro_statement相关的操作
    // 结构体: macro_statement
    // 描述: macro_statement结构体提供相关功能
    // 用途: 用于处理macro_statement相关的操作
struct macro_statement : public statement {
    statement_ptr name;
    statements args;
    statements body;

    macro_statement(statement_ptr && name, statements && args, statements && body)
        : name(std::move(name)), args(std::move(args)), body(std::move(body)) {
        chk_type<identifier>(this->name);
        for (const auto& arg : this->args) chk_type<expression>(arg);
    }

    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Macro"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: comment_statement
// 描述: comment_statement类提供相关功能
// 用途: 用于处理comment_statement相关的操作
// 类: comment_statement
// 描述: comment_statement类提供相关功能
// 用途: 用于处理comment_statement相关的操作
    // 结构体: comment_statement
    // 描述: comment_statement结构体提供相关功能
    // 用途: 用于处理comment_statement相关的操作
    // 结构体: comment_statement
    // 描述: comment_statement结构体提供相关功能
    // 用途: 用于处理comment_statement相关的操作
    // 结构体: comment_statement
    // 描述: comment_statement结构体提供相关功能
    // 用途: 用于处理comment_statement相关的操作
    // 结构体: comment_statement
    // 描述: comment_statement结构体提供相关功能
    // 用途: 用于处理comment_statement相关的操作
struct comment_statement : public statement {
    std::string val;
    // 函数: comment_statement
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: comment_statement
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit comment_statement(const std::string & v) : val(v) {}
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Comment"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        return mk_val<value_undefined>();
    }
};

// Expressions

// 类: member_expression
// 描述: member_expression类提供相关功能
// 用途: 用于处理member_expression相关的操作
// 类: member_expression
// 描述: member_expression类提供相关功能
// 用途: 用于处理member_expression相关的操作
    // 结构体: member_expression
    // 描述: member_expression结构体提供相关功能
    // 用途: 用于处理member_expression相关的操作
    // 结构体: member_expression
    // 描述: member_expression结构体提供相关功能
    // 用途: 用于处理member_expression相关的操作
    // 结构体: member_expression
    // 描述: member_expression结构体提供相关功能
    // 用途: 用于处理member_expression相关的操作
    // 结构体: member_expression
    // 描述: member_expression结构体提供相关功能
    // 用途: 用于处理member_expression相关的操作
struct member_expression : public expression {
    statement_ptr object;
    statement_ptr property;
    bool computed; // true if obj[expr] and false if obj.prop

    member_expression(statement_ptr && object, statement_ptr && property, bool computed)
        : object(std::move(object)), property(std::move(property)), computed(computed) {
        chk_type<expression>(this->object);
        chk_type<expression>(this->property);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "MemberExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: call_expression
// 描述: call_expression类提供相关功能
// 用途: 用于处理call_expression相关的操作
// 类: call_expression
// 描述: call_expression类提供相关功能
// 用途: 用于处理call_expression相关的操作
    // 结构体: call_expression
    // 描述: call_expression结构体提供相关功能
    // 用途: 用于处理call_expression相关的操作
    // 结构体: call_expression
    // 描述: call_expression结构体提供相关功能
    // 用途: 用于处理call_expression相关的操作
    // 结构体: call_expression
    // 描述: call_expression结构体提供相关功能
    // 用途: 用于处理call_expression相关的操作
    // 结构体: call_expression
    // 描述: call_expression结构体提供相关功能
    // 用途: 用于处理call_expression相关的操作
struct call_expression : public expression {
    statement_ptr callee;
    statements args;

    call_expression(statement_ptr && callee, statements && args)
        : callee(std::move(callee)), args(std::move(args)) {
        chk_type<expression>(this->callee);
        for (const auto& arg : this->args) chk_type<expression>(arg);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "CallExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

/**
 * Represents a user-defined variable or symbol in the template.
 */
// 类: identifier
// 描述: identifier类提供相关功能
// 用途: 用于处理identifier相关的操作
// 类: identifier
// 描述: identifier类提供相关功能
// 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
    // 结构体: identifier
    // 描述: identifier结构体提供相关功能
    // 用途: 用于处理identifier相关的操作
struct identifier : public expression {
    std::string val;
    // 函数: identifier
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: identifier
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit identifier(const std::string & val) : val(val) {}
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Identifier"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// Literals

// 类: integer_literal
// 描述: integer_literal类提供相关功能
// 用途: 用于处理integer_literal相关的操作
// 类: integer_literal
// 描述: integer_literal类提供相关功能
// 用途: 用于处理integer_literal相关的操作
    // 结构体: integer_literal
    // 描述: integer_literal结构体提供相关功能
    // 用途: 用于处理integer_literal相关的操作
    // 结构体: integer_literal
    // 描述: integer_literal结构体提供相关功能
    // 用途: 用于处理integer_literal相关的操作
    // 结构体: integer_literal
    // 描述: integer_literal结构体提供相关功能
    // 用途: 用于处理integer_literal相关的操作
    // 结构体: integer_literal
    // 描述: integer_literal结构体提供相关功能
    // 用途: 用于处理integer_literal相关的操作
struct integer_literal : public expression {
    int64_t val;
    // 函数: integer_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: integer_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit integer_literal(int64_t val) : val(val) {}
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "IntegerLiteral"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        return mk_val<value_int>(val);
    }
};

// 类: float_literal
// 描述: float_literal类提供相关功能
// 用途: 用于处理float_literal相关的操作
// 类: float_literal
// 描述: float_literal类提供相关功能
// 用途: 用于处理float_literal相关的操作
    // 结构体: float_literal
    // 描述: float_literal结构体提供相关功能
    // 用途: 用于处理float_literal相关的操作
    // 结构体: float_literal
    // 描述: float_literal结构体提供相关功能
    // 用途: 用于处理float_literal相关的操作
    // 结构体: float_literal
    // 描述: float_literal结构体提供相关功能
    // 用途: 用于处理float_literal相关的操作
    // 结构体: float_literal
    // 描述: float_literal结构体提供相关功能
    // 用途: 用于处理float_literal相关的操作
struct float_literal : public expression {
    double val;
    // 函数: float_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: float_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit float_literal(double val) : val(val) {}
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "FloatLiteral"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        return mk_val<value_float>(val);
    }
};

// 类: string_literal
// 描述: string_literal类提供相关功能
// 用途: 用于处理string_literal相关的操作
// 类: string_literal
// 描述: string_literal类提供相关功能
// 用途: 用于处理string_literal相关的操作
    // 结构体: string_literal
    // 描述: string_literal结构体提供相关功能
    // 用途: 用于处理string_literal相关的操作
    // 结构体: string_literal
    // 描述: string_literal结构体提供相关功能
    // 用途: 用于处理string_literal相关的操作
    // 结构体: string_literal
    // 描述: string_literal结构体提供相关功能
    // 用途: 用于处理string_literal相关的操作
    // 结构体: string_literal
    // 描述: string_literal结构体提供相关功能
    // 用途: 用于处理string_literal相关的操作
struct string_literal : public expression {
    std::string val;
    // 函数: string_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: string_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit string_literal(const std::string & val) : val(val) {}
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "StringLiteral"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        return mk_val<value_string>(val);
    }
};

// 类: array_literal
// 描述: array_literal类提供相关功能
// 用途: 用于处理array_literal相关的操作
// 类: array_literal
// 描述: array_literal类提供相关功能
// 用途: 用于处理array_literal相关的操作
    // 结构体: array_literal
    // 描述: array_literal结构体提供相关功能
    // 用途: 用于处理array_literal相关的操作
    // 结构体: array_literal
    // 描述: array_literal结构体提供相关功能
    // 用途: 用于处理array_literal相关的操作
    // 结构体: array_literal
    // 描述: array_literal结构体提供相关功能
    // 用途: 用于处理array_literal相关的操作
    // 结构体: array_literal
    // 描述: array_literal结构体提供相关功能
    // 用途: 用于处理array_literal相关的操作
struct array_literal : public expression {
    statements val;
    // 函数: array_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: array_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit array_literal(statements && val) : val(std::move(val)) {
        for (const auto& item : this->val) chk_type<expression>(item);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "ArrayLiteral"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override {
        auto arr = mk_val<value_array>();
        for (const auto & item_stmt : val) {
            arr->push_back(item_stmt->execute(ctx));
        }
        return arr;
    }
};

// 类: tuple_literal
// 描述: tuple_literal类提供相关功能
// 用途: 用于处理tuple_literal相关的操作
// 类: tuple_literal
// 描述: tuple_literal类提供相关功能
// 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
    // 结构体: tuple_literal
    // 描述: tuple_literal结构体提供相关功能
    // 用途: 用于处理tuple_literal相关的操作
struct tuple_literal : public expression {
    statements val;
    // 函数: tuple_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: tuple_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit tuple_literal(statements && val) : val(std::move(val)) {
        for (const auto& item : this->val) chk_type<expression>(item);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "TupleLiteral"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override {
        auto arr = mk_val<value_array>();
        for (const auto & item_stmt : val) {
            arr->push_back(item_stmt->execute(ctx));
        }
        return mk_val<value_tuple>(std::move(arr->as_array()));
    }
};

// 类: object_literal
// 描述: object_literal类提供相关功能
// 用途: 用于处理object_literal相关的操作
// 类: object_literal
// 描述: object_literal类提供相关功能
// 用途: 用于处理object_literal相关的操作
    // 结构体: object_literal
    // 描述: object_literal结构体提供相关功能
    // 用途: 用于处理object_literal相关的操作
    // 结构体: object_literal
    // 描述: object_literal结构体提供相关功能
    // 用途: 用于处理object_literal相关的操作
    // 结构体: object_literal
    // 描述: object_literal结构体提供相关功能
    // 用途: 用于处理object_literal相关的操作
    // 结构体: object_literal
    // 描述: object_literal结构体提供相关功能
    // 用途: 用于处理object_literal相关的操作
struct object_literal : public expression {
    std::vector<std::pair<statement_ptr, statement_ptr>> val;
    // 函数: object_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: object_literal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit object_literal(std::vector<std::pair<statement_ptr, statement_ptr>> && val)
        : val(std::move(val)) {
        for (const auto & pair : this->val) {
            chk_type<expression>(pair.first);
            chk_type<expression>(pair.second);
        }
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "ObjectLiteral"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// Complex Expressions

/**
 * An operation with two sides, separated by an operator.
 * Note: Either side can be a Complex Expression, with order
 * of operations being determined by the operator.
 */
// 类: binary_expression
// 描述: binary_expression类提供相关功能
// 用途: 用于处理binary_expression相关的操作
// 类: binary_expression
// 描述: binary_expression类提供相关功能
// 用途: 用于处理binary_expression相关的操作
    // 结构体: binary_expression
    // 描述: binary_expression结构体提供相关功能
    // 用途: 用于处理binary_expression相关的操作
    // 结构体: binary_expression
    // 描述: binary_expression结构体提供相关功能
    // 用途: 用于处理binary_expression相关的操作
    // 结构体: binary_expression
    // 描述: binary_expression结构体提供相关功能
    // 用途: 用于处理binary_expression相关的操作
    // 结构体: binary_expression
    // 描述: binary_expression结构体提供相关功能
    // 用途: 用于处理binary_expression相关的操作
struct binary_expression : public expression {
    token op;
    statement_ptr left;
    statement_ptr right;

    binary_expression(token op, statement_ptr && left, statement_ptr && right)
        : op(std::move(op)), left(std::move(left)), right(std::move(right)) {
        chk_type<expression>(this->left);
        chk_type<expression>(this->right);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "BinaryExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

/**
 * An operation with two sides, separated by the | operator.
 * Operator precedence: https://github.com/pallets/jinja/issues/379#issuecomment-168076202
 */
// 类: filter_expression
// 描述: filter_expression类提供相关功能
// 用途: 用于处理filter_expression相关的操作
// 类: filter_expression
// 描述: filter_expression类提供相关功能
// 用途: 用于处理filter_expression相关的操作
    // 结构体: filter_expression
    // 描述: filter_expression结构体提供相关功能
    // 用途: 用于处理filter_expression相关的操作
    // 结构体: filter_expression
    // 描述: filter_expression结构体提供相关功能
    // 用途: 用于处理filter_expression相关的操作
    // 结构体: filter_expression
    // 描述: filter_expression结构体提供相关功能
    // 用途: 用于处理filter_expression相关的操作
    // 结构体: filter_expression
    // 描述: filter_expression结构体提供相关功能
    // 用途: 用于处理filter_expression相关的操作
struct filter_expression : public expression {
    // either an expression or a value is allowed
    statement_ptr operand;
    value_string val; // will be set by filter_statement

    statement_ptr filter;

    filter_expression(statement_ptr && operand, statement_ptr && filter)
        : operand(std::move(operand)), filter(std::move(filter)) {
        chk_type<expression>(this->operand);
        chk_type<identifier, call_expression>(this->filter);
    }

    filter_expression(value_string && val, statement_ptr && filter)
        : val(std::move(val)), filter(std::move(filter)) {
        chk_type<identifier, call_expression>(this->filter);
    }

    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "FilterExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: filter_statement
// 描述: filter_statement类提供相关功能
// 用途: 用于处理filter_statement相关的操作
// 类: filter_statement
// 描述: filter_statement类提供相关功能
// 用途: 用于处理filter_statement相关的操作
    // 结构体: filter_statement
    // 描述: filter_statement结构体提供相关功能
    // 用途: 用于处理filter_statement相关的操作
    // 结构体: filter_statement
    // 描述: filter_statement结构体提供相关功能
    // 用途: 用于处理filter_statement相关的操作
    // 结构体: filter_statement
    // 描述: filter_statement结构体提供相关功能
    // 用途: 用于处理filter_statement相关的操作
    // 结构体: filter_statement
    // 描述: filter_statement结构体提供相关功能
    // 用途: 用于处理filter_statement相关的操作
struct filter_statement : public statement {
    statement_ptr filter;
    statements body;

    filter_statement(statement_ptr && filter, statements && body)
        : filter(std::move(filter)), body(std::move(body)) {
        chk_type<identifier, call_expression>(this->filter);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "FilterStatement"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

/**
 * An operation which filters a sequence of objects by applying a test to each object,
 * and only selecting the objects with the test succeeding.
 *
 * It may also be used as a shortcut for a ternary operator.
 */
// 类: select_expression
// 描述: select_expression类提供相关功能
// 用途: 用于处理select_expression相关的操作
// 类: select_expression
// 描述: select_expression类提供相关功能
// 用途: 用于处理select_expression相关的操作
    // 结构体: select_expression
    // 描述: select_expression结构体提供相关功能
    // 用途: 用于处理select_expression相关的操作
    // 结构体: select_expression
    // 描述: select_expression结构体提供相关功能
    // 用途: 用于处理select_expression相关的操作
    // 结构体: select_expression
    // 描述: select_expression结构体提供相关功能
    // 用途: 用于处理select_expression相关的操作
    // 结构体: select_expression
    // 描述: select_expression结构体提供相关功能
    // 用途: 用于处理select_expression相关的操作
struct select_expression : public expression {
    statement_ptr lhs;
    statement_ptr test;

    select_expression(statement_ptr && lhs, statement_ptr && test)
        : lhs(std::move(lhs)), test(std::move(test)) {
        chk_type<expression>(this->lhs);
        chk_type<expression>(this->test);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "SelectExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override {
        auto predicate = test->execute_impl(ctx);
        if (!predicate->as_bool()) {
            return mk_val<value_undefined>();
        }
        return lhs->execute_impl(ctx);
    }
};

/**
 * An operation with two sides, separated by the "is" operator.
 * NOTE: "value is something" translates to function call "test_is_something(value)"
 */
// 类: test_expression
// 描述: test_expression类提供相关功能
// 用途: 用于处理test_expression相关的操作
// 类: test_expression
// 描述: test_expression类提供相关功能
// 用途: 用于处理test_expression相关的操作
    // 结构体: test_expression
    // 描述: test_expression结构体提供相关功能
    // 用途: 用于处理test_expression相关的操作
    // 结构体: test_expression
    // 描述: test_expression结构体提供相关功能
    // 用途: 用于处理test_expression相关的操作
    // 结构体: test_expression
    // 描述: test_expression结构体提供相关功能
    // 用途: 用于处理test_expression相关的操作
    // 结构体: test_expression
    // 描述: test_expression结构体提供相关功能
    // 用途: 用于处理test_expression相关的操作
struct test_expression : public expression {
    statement_ptr operand;
    bool negate;
    statement_ptr test;

    test_expression(statement_ptr && operand, bool negate, statement_ptr && test)
        : operand(std::move(operand)), negate(negate), test(std::move(test)) {
        chk_type<expression>(this->operand);
        chk_type<identifier, call_expression>(this->test);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "TestExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

/**
 * An operation with one side (operator on the left).
 */
// 类: unary_expression
// 描述: unary_expression类提供相关功能
// 用途: 用于处理unary_expression相关的操作
// 类: unary_expression
// 描述: unary_expression类提供相关功能
// 用途: 用于处理unary_expression相关的操作
    // 结构体: unary_expression
    // 描述: unary_expression结构体提供相关功能
    // 用途: 用于处理unary_expression相关的操作
    // 结构体: unary_expression
    // 描述: unary_expression结构体提供相关功能
    // 用途: 用于处理unary_expression相关的操作
    // 结构体: unary_expression
    // 描述: unary_expression结构体提供相关功能
    // 用途: 用于处理unary_expression相关的操作
    // 结构体: unary_expression
    // 描述: unary_expression结构体提供相关功能
    // 用途: 用于处理unary_expression相关的操作
struct unary_expression : public expression {
    token op;
    statement_ptr argument;

    unary_expression(token op, statement_ptr && argument)
        : op(std::move(op)), argument(std::move(argument)) {
        chk_type<expression>(this->argument);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "UnaryExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: slice_expression
// 描述: slice_expression类提供相关功能
// 用途: 用于处理slice_expression相关的操作
// 类: slice_expression
// 描述: slice_expression类提供相关功能
// 用途: 用于处理slice_expression相关的操作
    // 结构体: slice_expression
    // 描述: slice_expression结构体提供相关功能
    // 用途: 用于处理slice_expression相关的操作
    // 结构体: slice_expression
    // 描述: slice_expression结构体提供相关功能
    // 用途: 用于处理slice_expression相关的操作
    // 结构体: slice_expression
    // 描述: slice_expression结构体提供相关功能
    // 用途: 用于处理slice_expression相关的操作
    // 结构体: slice_expression
    // 描述: slice_expression结构体提供相关功能
    // 用途: 用于处理slice_expression相关的操作
struct slice_expression : public expression {
    statement_ptr start_expr;
    statement_ptr stop_expr;
    statement_ptr step_expr;

    slice_expression(statement_ptr && start_expr, statement_ptr && stop_expr, statement_ptr && step_expr)
        : start_expr(std::move(start_expr)), stop_expr(std::move(stop_expr)), step_expr(std::move(step_expr)) {
        chk_type<expression>(this->start_expr);
        chk_type<expression>(this->stop_expr);
        chk_type<expression>(this->step_expr);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "SliceExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context &) override {
        throw std::runtime_error("must be handled by MemberExpression");
    }
};

// 类: keyword_argument_expression
// 描述: keyword_argument_expression类提供相关功能
// 用途: 用于处理keyword_argument_expression相关的操作
// 类: keyword_argument_expression
// 描述: keyword_argument_expression类提供相关功能
// 用途: 用于处理keyword_argument_expression相关的操作
    // 结构体: keyword_argument_expression
    // 描述: keyword_argument_expression结构体提供相关功能
    // 用途: 用于处理keyword_argument_expression相关的操作
    // 结构体: keyword_argument_expression
    // 描述: keyword_argument_expression结构体提供相关功能
    // 用途: 用于处理keyword_argument_expression相关的操作
    // 结构体: keyword_argument_expression
    // 描述: keyword_argument_expression结构体提供相关功能
    // 用途: 用于处理keyword_argument_expression相关的操作
    // 结构体: keyword_argument_expression
    // 描述: keyword_argument_expression结构体提供相关功能
    // 用途: 用于处理keyword_argument_expression相关的操作
struct keyword_argument_expression : public expression {
    statement_ptr key;
    statement_ptr val;

    keyword_argument_expression(statement_ptr && key, statement_ptr && val)
        : key(std::move(key)), val(std::move(val)) {
        chk_type<identifier>(this->key);
        chk_type<expression>(this->val);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "KeywordArgumentExpression"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override;
};

// 类: spread_expression
// 描述: spread_expression类提供相关功能
// 用途: 用于处理spread_expression相关的操作
// 类: spread_expression
// 描述: spread_expression类提供相关功能
// 用途: 用于处理spread_expression相关的操作
    // 结构体: spread_expression
    // 描述: spread_expression结构体提供相关功能
    // 用途: 用于处理spread_expression相关的操作
    // 结构体: spread_expression
    // 描述: spread_expression结构体提供相关功能
    // 用途: 用于处理spread_expression相关的操作
    // 结构体: spread_expression
    // 描述: spread_expression结构体提供相关功能
    // 用途: 用于处理spread_expression相关的操作
    // 结构体: spread_expression
    // 描述: spread_expression结构体提供相关功能
    // 用途: 用于处理spread_expression相关的操作
struct spread_expression : public expression {
    statement_ptr argument;
    // 函数: spread_expression
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: spread_expression
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit spread_expression(statement_ptr && argument) : argument(std::move(argument)) {
        chk_type<expression>(this->argument);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "SpreadExpression"; }
};

// 类: call_statement
// 描述: call_statement类提供相关功能
// 用途: 用于处理call_statement相关的操作
// 类: call_statement
// 描述: call_statement类提供相关功能
// 用途: 用于处理call_statement相关的操作
    // 结构体: call_statement
    // 描述: call_statement结构体提供相关功能
    // 用途: 用于处理call_statement相关的操作
    // 结构体: call_statement
    // 描述: call_statement结构体提供相关功能
    // 用途: 用于处理call_statement相关的操作
    // 结构体: call_statement
    // 描述: call_statement结构体提供相关功能
    // 用途: 用于处理call_statement相关的操作
    // 结构体: call_statement
    // 描述: call_statement结构体提供相关功能
    // 用途: 用于处理call_statement相关的操作
struct call_statement : public statement {
    statement_ptr call;
    statements caller_args;
    statements body;

    call_statement(statement_ptr && call, statements && caller_args, statements && body)
        : call(std::move(call)), caller_args(std::move(caller_args)), body(std::move(body)) {
        chk_type<call_expression>(this->call);
        for (const auto & arg : this->caller_args) chk_type<expression>(arg);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "CallStatement"; }
};

// 类: ternary_expression
// 描述: ternary_expression类提供相关功能
// 用途: 用于处理ternary_expression相关的操作
// 类: ternary_expression
// 描述: ternary_expression类提供相关功能
// 用途: 用于处理ternary_expression相关的操作
    // 结构体: ternary_expression
    // 描述: ternary_expression结构体提供相关功能
    // 用途: 用于处理ternary_expression相关的操作
    // 结构体: ternary_expression
    // 描述: ternary_expression结构体提供相关功能
    // 用途: 用于处理ternary_expression相关的操作
    // 结构体: ternary_expression
    // 描述: ternary_expression结构体提供相关功能
    // 用途: 用于处理ternary_expression相关的操作
    // 结构体: ternary_expression
    // 描述: ternary_expression结构体提供相关功能
    // 用途: 用于处理ternary_expression相关的操作
struct ternary_expression : public expression {
    statement_ptr condition;
    statement_ptr true_expr;
    statement_ptr false_expr;

    ternary_expression(statement_ptr && condition, statement_ptr && true_expr, statement_ptr && false_expr)
        : condition(std::move(condition)), true_expr(std::move(true_expr)), false_expr(std::move(false_expr)) {
        chk_type<expression>(this->condition);
        chk_type<expression>(this->true_expr);
        chk_type<expression>(this->false_expr);
    }
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type() const override { return "Ternary"; }
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute_impl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value execute_impl(context & ctx) override {
        value cond_val = condition->execute(ctx);
        if (cond_val->as_bool()) {
            return true_expr->execute(ctx);
        } else {
            return false_expr->execute(ctx);
        }
    }
};

// 类: raised_exception
// 描述: raised_exception类提供相关功能
// 用途: 用于处理raised_exception相关的操作
// 类: raised_exception
// 描述: raised_exception类提供相关功能
// 用途: 用于处理raised_exception相关的操作
    // 结构体: raised_exception
    // 描述: raised_exception结构体提供相关功能
    // 用途: 用于处理raised_exception相关的操作
    // 结构体: raised_exception
    // 描述: raised_exception结构体提供相关功能
    // 用途: 用于处理raised_exception相关的操作
    // 结构体: raised_exception
    // 描述: raised_exception结构体提供相关功能
    // 用途: 用于处理raised_exception相关的操作
    // 结构体: raised_exception
    // 描述: raised_exception结构体提供相关功能
    // 用途: 用于处理raised_exception相关的操作
struct raised_exception : public std::exception {
    std::string message;
    raised_exception(const std::string & msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Used to rethrow exceptions with modified messages
// 类: rethrown_exception
// 描述: rethrown_exception类提供相关功能
// 用途: 用于处理rethrown_exception相关的操作
// 类: rethrown_exception
// 描述: rethrown_exception类提供相关功能
// 用途: 用于处理rethrown_exception相关的操作
    // 结构体: rethrown_exception
    // 描述: rethrown_exception结构体提供相关功能
    // 用途: 用于处理rethrown_exception相关的操作
    // 结构体: rethrown_exception
    // 描述: rethrown_exception结构体提供相关功能
    // 用途: 用于处理rethrown_exception相关的操作
    // 结构体: rethrown_exception
    // 描述: rethrown_exception结构体提供相关功能
    // 用途: 用于处理rethrown_exception相关的操作
    // 结构体: rethrown_exception
    // 描述: rethrown_exception结构体提供相关功能
    // 用途: 用于处理rethrown_exception相关的操作
struct rethrown_exception : public std::exception {
    std::string message;
    rethrown_exception(const std::string & msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

//////////////////////

// 函数: gather_string_parts_recursive
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: gather_string_parts_recursive
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static void gather_string_parts_recursive(const value & val, value_string & parts) {
    // TODO: probably allow print value_none as "None" string? currently this breaks some templates
    if (is_val<value_string>(val)) {
        const auto & str_val = cast_val<value_string>(val)->val_str;
        parts->val_str.append(str_val);
    } else if (is_val<value_int>(val) || is_val<value_float>(val) || is_val<value_bool>(val)) {
        std::string str_val = val->as_string().str();
        parts->val_str.append(str_val);
    } else if (is_val<value_array>(val)) {
        auto items = cast_val<value_array>(val)->as_array();
        for (const auto & item : items) {
            gather_string_parts_recursive(item, parts);
        }
    }
}

// 函数: render_string_parts
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: render_string_parts
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static std::string render_string_parts(const value_string & parts) {
    std::ostringstream oss;
    for (const auto & part : parts->val_str.parts) {
        oss << part.val;
    }
    return oss.str();
}

// 类: runtime
// 描述: runtime类提供相关功能
// 用途: 用于处理runtime相关的操作
// 类: runtime
// 描述: runtime类提供相关功能
// 用途: 用于处理runtime相关的操作
    // 结构体: runtime
    // 描述: runtime结构体提供相关功能
    // 用途: 用于处理runtime相关的操作
    // 结构体: runtime
    // 描述: runtime结构体提供相关功能
    // 用途: 用于处理runtime相关的操作
    // 结构体: runtime
    // 描述: runtime结构体提供相关功能
    // 用途: 用于处理runtime相关的操作
    // 结构体: runtime
    // 描述: runtime结构体提供相关功能
    // 用途: 用于处理runtime相关的操作
struct runtime {
    context & ctx;
    // 函数: runtime
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: runtime
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit runtime(context & ctx) : ctx(ctx) {}

    // 函数: execute
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: execute
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    value_array execute(const program & prog) {
        value_array results = mk_val<value_array>();
        for (const auto & stmt : prog.body) {
            value res = stmt->execute(ctx);
            results->push_back(std::move(res));
        }
        return results;
    }

    // 函数: gather_string_parts
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: gather_string_parts
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static value_string gather_string_parts(const value & val) {
        value_string parts = mk_val<value_string>();
        gather_string_parts_recursive(val, parts);
        // join consecutive parts with the same type
        auto & p = parts->val_str.parts;
        for (size_t i = 1; i < p.size(); ) {
            if (p[i].is_input == p[i - 1].is_input) {
                p[i - 1].val += p[i].val;
                p.erase(p.begin() + i);
            } else {
                i++;
            }
        }
        return parts;
    }
};

} // namespace jinja
