#pragma once

#include "llama.h"

#include "common.h"

#include <string>
#include <vector>

// common_sampler extends llama_sampler with additional functionality:
//
//  - grammar support
//  - custom sampler logic based on the parameters
//  - history of the last accepted tokens
//  - performance metrics
//
// This goal is to have a common implementation of the sampling logic shared across the examples.
// For example, depending on the temperature, the sampling chain can be very simple (greedy) or more
// complex (top-k, top-p, etc).
//
// Another example is related to the grammar. In general, the grammar constraints applied on the full
// vocabulary can be very taxing. To improve performance, the grammar can be applied only to the sampled
// token in order to verify if it fits the grammar. And only if the token doesn't fit the grammar, the
// grammar constraints are applied to the full vocabulary and the token is resampled.
//
// The common_sampler also maintains a container with the last accepted tokens. In the future, this can
// be moved into the core llama library.
//
// For convenience, the common_sampler also maintains a container with the current candidate tokens.
// This can be used to access the probabilities of the rest of the non-sampled tokens.
//
// TODO: measure grammar performance
//

// 类: common_sampler
// 描述: common_sampler类提供相关功能
// 用途: 用于处理common_sampler相关的操作
// 类: common_sampler
// 描述: common_sampler类提供相关功能
// 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
struct common_sampler;

// llama_sampler API overloads

// note: can mutate params in some cases
// 类: common_sampler
// 描述: common_sampler类提供相关功能
// 用途: 用于处理common_sampler相关的操作
// 类: common_sampler
// 描述: common_sampler类提供相关功能
// 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
struct common_sampler * common_sampler_init(const struct llama_model * model, struct common_params_sampling & params);

// 函数: common_sampler_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void common_sampler_free(struct common_sampler * gsmpl);

// if accept_grammar is true, the token is accepted both by the sampling chain and the grammar
// 函数: common_sampler_accept
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_accept
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
void                    common_sampler_accept(struct common_sampler * gsmpl, llama_token token, bool accept_grammar);
// 函数: common_sampler_reset
// 描述: 重置: 重置对象或状态到初始值
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_reset
// 描述: 重置: 重置对象或状态到初始值
// 参数: 无参数
// 返回: 无返回值
void                    common_sampler_reset (struct common_sampler * gsmpl);
// 类: common_sampler
// 描述: common_sampler类提供相关功能
// 用途: 用于处理common_sampler相关的操作
// 类: common_sampler
// 描述: common_sampler类提供相关功能
// 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
    // 结构体: common_sampler
    // 描述: common_sampler结构体提供相关功能
    // 用途: 用于处理common_sampler相关的操作
struct common_sampler * common_sampler_clone (struct common_sampler * gsmpl);

// arguments can be nullptr to skip printing
// 函数: common_perf_print
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_perf_print
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void common_perf_print(const struct llama_context * ctx, const struct common_sampler * gsmpl);

// get the underlying llama_sampler_chain
// 类: llama_sampler
// 描述: llama_sampler类提供相关功能
// 用途: 用于处理llama_sampler相关的操作
// 类: llama_sampler
// 描述: llama_sampler类提供相关功能
// 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
struct llama_sampler * common_sampler_get(const struct common_sampler * gsmpl);

// extended sampling implementation:
//
// - set logits
// - apply the configured sampler chain
// - check if the token fits the grammar (if any)
// - if not: resample by first applying the grammar constraints and then sampling again (slower path)
//
// if grammar_first is true, the grammar is applied before the samplers (slower)
// useful in cases where all the resulting candidates (not just the sampled one) must fit the grammar
//
// 函数: common_sampler_sample
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_sample
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
llama_token common_sampler_sample(struct common_sampler * gsmpl, struct llama_context * ctx, int idx, bool grammar_first = false);

// generalized version of common_sampler_sample
//
// will cross-reference the sampled tokens with a batch of draft tokens and accept those that match
// if the sampler disagrees at some point, we stop and return the accepted tokens up to now
//
//      common_sampler_sample_n(gsmpl, ctx, { idx }, {});
//
// is equivalent to
//
//      common_sampler_sample(gsmpl, ctx, idx);
//      common_sampler_accept(gsmpl, token, true);
//
// requires: idxs.size() == draft.size() + 1
//
// returns at least 1 token, up to idxs.size()
//
std::vector<llama_token> common_sampler_sample_and_accept_n(struct common_sampler * gsmpl, struct llama_context * ctx, const std::vector<int> & idxs, const llama_tokens & draft, bool grammar_first = false);

// assume idxs == [ 0, 1, 2, ..., draft.size() ]
std::vector<llama_token> common_sampler_sample_and_accept_n(struct common_sampler * gsmpl, struct llama_context * ctx, const llama_tokens & draft, bool grammar_first = false);

// 函数: common_sampler_get_seed
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_get_seed
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
uint32_t common_sampler_get_seed(const struct common_sampler * gsmpl);

// helpers

// access the internal list of current candidate tokens
// if do_sort == true, the candidates are guaranteed to be sorted afterwards (in descending order of probability)
// the .sorted flag of the result indicates whether the returned candidates are sorted
// 函数: common_sampler_get_candidates
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_get_candidates
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
llama_token_data_array * common_sampler_get_candidates(struct common_sampler * gsmpl, bool do_sort);

// get the last accepted token
// 函数: common_sampler_last
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_last
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
llama_token common_sampler_last(const struct common_sampler * gsmpl);

// print the sampler chain into a string
// 函数: common_sampler_print
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_print
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
std::string common_sampler_print(const struct common_sampler * gsmpl);

// get a string representation of the last accepted tokens
// 函数: common_sampler_prev_str
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_prev_str
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
std::string common_sampler_prev_str(common_sampler * gsmpl, llama_context * ctx, int n);

// 函数: common_sampler_type_to_chr
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_type_to_chr
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
char        common_sampler_type_to_chr(enum common_sampler_type cnstr);
// 函数: common_sampler_type_to_str
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
// 函数: common_sampler_type_to_str
// 描述: 采样: 从概率分布中采样
// 参数: 无参数
// 返回: 无返回值
std::string common_sampler_type_to_str(enum common_sampler_type cnstr);

std::vector<enum common_sampler_type> common_sampler_types_from_names(const std::vector<std::string> & names, bool allow_alt_names);
std::vector<enum common_sampler_type> common_sampler_types_from_chars(const std::string & chars);

llama_sampler * llama_sampler_init_llg(const llama_vocab * vocab,
                const char * grammar_kind, const char * grammar_data);

// 类: common_sampler_deleter
// 描述: common_sampler_deleter类提供相关功能
// 用途: 用于处理common_sampler_deleter相关的操作
// 类: common_sampler_deleter
// 描述: common_sampler_deleter类提供相关功能
// 用途: 用于处理common_sampler_deleter相关的操作
    // 结构体: common_sampler_deleter
    // 描述: common_sampler_deleter结构体提供相关功能
    // 用途: 用于处理common_sampler_deleter相关的操作
    // 结构体: common_sampler_deleter
    // 描述: common_sampler_deleter结构体提供相关功能
    // 用途: 用于处理common_sampler_deleter相关的操作
    // 结构体: common_sampler_deleter
    // 描述: common_sampler_deleter结构体提供相关功能
    // 用途: 用于处理common_sampler_deleter相关的操作
    // 结构体: common_sampler_deleter
    // 描述: common_sampler_deleter结构体提供相关功能
    // 用途: 用于处理common_sampler_deleter相关的操作
struct common_sampler_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(common_sampler * s) { common_sampler_free(s); }
};

typedef std::unique_ptr<common_sampler, common_sampler_deleter> common_sampler_ptr;
