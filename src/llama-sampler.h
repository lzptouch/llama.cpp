#pragma once

#include "llama.h"

#include <vector>

// 类: llama_vocab
// 描述: llama_vocab类提供相关功能
// 用途: 用于处理llama_vocab相关的操作
// 类: llama_vocab
// 描述: llama_vocab类提供相关功能
// 用途: 用于处理llama_vocab相关的操作
    // 结构体: llama_vocab
    // 描述: llama_vocab结构体提供相关功能
    // 用途: 用于处理llama_vocab相关的操作
    // 结构体: llama_vocab
    // 描述: llama_vocab结构体提供相关功能
    // 用途: 用于处理llama_vocab相关的操作
    // 结构体: llama_vocab
    // 描述: llama_vocab结构体提供相关功能
    // 用途: 用于处理llama_vocab相关的操作
    // 结构体: llama_vocab
    // 描述: llama_vocab结构体提供相关功能
    // 用途: 用于处理llama_vocab相关的操作
struct llama_vocab;
// 类: llama_grammar
// 描述: llama_grammar类提供相关功能
// 用途: 用于处理llama_grammar相关的操作
// 类: llama_grammar
// 描述: llama_grammar类提供相关功能
// 用途: 用于处理llama_grammar相关的操作
    // 结构体: llama_grammar
    // 描述: llama_grammar结构体提供相关功能
    // 用途: 用于处理llama_grammar相关的操作
    // 结构体: llama_grammar
    // 描述: llama_grammar结构体提供相关功能
    // 用途: 用于处理llama_grammar相关的操作
    // 结构体: llama_grammar
    // 描述: llama_grammar结构体提供相关功能
    // 用途: 用于处理llama_grammar相关的操作
    // 结构体: llama_grammar
    // 描述: llama_grammar结构体提供相关功能
    // 用途: 用于处理llama_grammar相关的操作
struct llama_grammar;

// sampler chain

// 类: llama_sampler_chain
// 描述: llama_sampler_chain类提供相关功能
// 用途: 用于处理llama_sampler_chain相关的操作
// 类: llama_sampler_chain
// 描述: llama_sampler_chain类提供相关功能
// 用途: 用于处理llama_sampler_chain相关的操作
    // 结构体: llama_sampler_chain
    // 描述: llama_sampler_chain结构体提供相关功能
    // 用途: 用于处理llama_sampler_chain相关的操作
    // 结构体: llama_sampler_chain
    // 描述: llama_sampler_chain结构体提供相关功能
    // 用途: 用于处理llama_sampler_chain相关的操作
    // 结构体: llama_sampler_chain
    // 描述: llama_sampler_chain结构体提供相关功能
    // 用途: 用于处理llama_sampler_chain相关的操作
    // 结构体: llama_sampler_chain
    // 描述: llama_sampler_chain结构体提供相关功能
    // 用途: 用于处理llama_sampler_chain相关的操作
struct llama_sampler_chain {
    llama_sampler_chain_params params;

    // has .backend_init() been called?
    bool is_init = false;

    // 类: info
    // 描述: info类提供相关功能
    // 用途: 用于处理info相关的操作
    // 类: info
    // 描述: info类提供相关功能
    // 用途: 用于处理info相关的操作
    // 结构体: info
    // 描述: info结构体提供相关功能
    // 用途: 用于处理info相关的操作
    // 结构体: info
    // 描述: info结构体提供相关功能
    // 用途: 用于处理info相关的操作
    // 结构体: info
    // 描述: info结构体提供相关功能
    // 用途: 用于处理info相关的操作
    // 结构体: info
    // 描述: info结构体提供相关功能
    // 用途: 用于处理info相关的操作
    struct info {
        bool is_backend;

        llama_sampler * ptr;
    };

    std::vector<info> samplers;

    // pre-allocated buffer for llama_sampler_sample to avoid repeated allocations
    std::vector<llama_token_data> cur;

    // timing

    mutable int64_t t_sample_us;

    mutable int32_t n_sample;
};

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
struct llama_sampler * llama_sampler_init_dry_testing(
        int32_t context_size,
        float   dry_multiplier,
        float   dry_base,
        int32_t dry_allowed_length,
        int32_t dry_penalty_last_n,
        const std::vector<std::vector<llama_token>> & seq_breakers);
