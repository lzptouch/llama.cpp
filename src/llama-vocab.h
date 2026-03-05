#pragma once

#include "llama.h"

#include <string>
#include <vector>
#include <memory>

// pre-tokenization types
enum llama_vocab_pre_type {
    LLAMA_VOCAB_PRE_TYPE_DEFAULT         = 0,
    LLAMA_VOCAB_PRE_TYPE_LLAMA3          = 1,
    LLAMA_VOCAB_PRE_TYPE_DEEPSEEK_LLM    = 2,
    LLAMA_VOCAB_PRE_TYPE_DEEPSEEK_CODER  = 3,
    LLAMA_VOCAB_PRE_TYPE_FALCON          = 4,
    LLAMA_VOCAB_PRE_TYPE_MPT             = 5,
    LLAMA_VOCAB_PRE_TYPE_STARCODER       = 6,
    LLAMA_VOCAB_PRE_TYPE_GPT2            = 7,
    LLAMA_VOCAB_PRE_TYPE_REFACT          = 8,
    LLAMA_VOCAB_PRE_TYPE_COMMAND_R       = 9,
    LLAMA_VOCAB_PRE_TYPE_STABLELM2       = 10,
    LLAMA_VOCAB_PRE_TYPE_QWEN2           = 11,
    LLAMA_VOCAB_PRE_TYPE_OLMO            = 12,
    LLAMA_VOCAB_PRE_TYPE_DBRX            = 13,
    LLAMA_VOCAB_PRE_TYPE_SMAUG           = 14,
    LLAMA_VOCAB_PRE_TYPE_PORO            = 15,
    LLAMA_VOCAB_PRE_TYPE_CHATGLM3        = 16,
    LLAMA_VOCAB_PRE_TYPE_CHATGLM4        = 17,
    LLAMA_VOCAB_PRE_TYPE_VIKING          = 18,
    LLAMA_VOCAB_PRE_TYPE_JAIS            = 19,
    LLAMA_VOCAB_PRE_TYPE_TEKKEN          = 20,
    LLAMA_VOCAB_PRE_TYPE_SMOLLM          = 21,
    LLAMA_VOCAB_PRE_TYPE_CODESHELL       = 22,
    LLAMA_VOCAB_PRE_TYPE_BLOOM           = 23,
    LLAMA_VOCAB_PRE_TYPE_GPT3_FINNISH    = 24,
    LLAMA_VOCAB_PRE_TYPE_EXAONE          = 25,
    LLAMA_VOCAB_PRE_TYPE_CHAMELEON       = 26,
    LLAMA_VOCAB_PRE_TYPE_MINERVA         = 27,
    LLAMA_VOCAB_PRE_TYPE_DEEPSEEK3_LLM   = 28,
    LLAMA_VOCAB_PRE_TYPE_GPT4O           = 29,
    LLAMA_VOCAB_PRE_TYPE_SUPERBPE        = 30,
    LLAMA_VOCAB_PRE_TYPE_TRILLION        = 31,
    LLAMA_VOCAB_PRE_TYPE_BAILINGMOE      = 32,
    LLAMA_VOCAB_PRE_TYPE_LLAMA4          = 33,
    LLAMA_VOCAB_PRE_TYPE_PIXTRAL         = 34,
    LLAMA_VOCAB_PRE_TYPE_SEED_CODER      = 35,
    LLAMA_VOCAB_PRE_TYPE_HUNYUAN         = 36,
    LLAMA_VOCAB_PRE_TYPE_KIMI_K2         = 37,
    LLAMA_VOCAB_PRE_TYPE_HUNYUAN_DENSE   = 38,
    LLAMA_VOCAB_PRE_TYPE_GROK_2          = 39,
    LLAMA_VOCAB_PRE_TYPE_GRANITE_DOCLING = 40,
    LLAMA_VOCAB_PRE_TYPE_MINIMAX_M2      = 41,
    LLAMA_VOCAB_PRE_TYPE_AFMOE           = 42,
    LLAMA_VOCAB_PRE_TYPE_SOLAR_OPEN      = 43,
    LLAMA_VOCAB_PRE_TYPE_YOUTU           = 44,
    LLAMA_VOCAB_PRE_TYPE_EXAONE_MOE      = 45,
    LLAMA_VOCAB_PRE_TYPE_QWEN35          = 46,
    LLAMA_VOCAB_PRE_TYPE_TINY_AYA        = 47,
    LLAMA_VOCAB_PRE_TYPE_JOYAI_LLM       = 48,
    LLAMA_VOCAB_PRE_TYPE_JAIS2           = 49,
};

// 类: LLM_KV
// 描述: LLM_KV类提供相关功能
// 用途: 用于处理llm_kv相关的操作
// 类: LLM_KV
// 描述: LLM_KV类提供相关功能
// 用途: 用于处理llm_kv相关的操作
    // 结构体: LLM_KV
    // 描述: LLM_KV结构体提供相关功能
    // 用途: 用于处理LLM_KV相关的操作
    // 结构体: LLM_KV
    // 描述: LLM_KV结构体提供相关功能
    // 用途: 用于处理LLM_KV相关的操作
    // 结构体: LLM_KV
    // 描述: LLM_KV结构体提供相关功能
    // 用途: 用于处理LLM_KV相关的操作
    // 结构体: LLM_KV
    // 描述: LLM_KV结构体提供相关功能
    // 用途: 用于处理LLM_KV相关的操作
struct LLM_KV;
// 类: llama_model_loader
// 描述: llama_model_loader类提供相关功能
// 用途: 用于处理llama_model_loader相关的操作
// 类: llama_model_loader
// 描述: llama_model_loader类提供相关功能
// 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
    // 结构体: llama_model_loader
    // 描述: llama_model_loader结构体提供相关功能
    // 用途: 用于处理llama_model_loader相关的操作
struct llama_model_loader;

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
struct llama_vocab {
    // 类: token_data
    // 描述: token_data类提供相关功能
    // 用途: 用于处理token_data相关的操作
    // 类: token_data
    // 描述: token_data类提供相关功能
    // 用途: 用于处理token_data相关的操作
    // 结构体: token_data
    // 描述: token_data结构体提供相关功能
    // 用途: 用于处理token_data相关的操作
    // 结构体: token_data
    // 描述: token_data结构体提供相关功能
    // 用途: 用于处理token_data相关的操作
    // 结构体: token_data
    // 描述: token_data结构体提供相关功能
    // 用途: 用于处理token_data相关的操作
    // 结构体: token_data
    // 描述: token_data结构体提供相关功能
    // 用途: 用于处理token_data相关的操作
    struct token_data {
        std::string      text;
        float            score;
        llama_token_attr attr;
    };

    llama_vocab();
    ~llama_vocab();

    // 函数: load
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load(llama_model_loader & ml, const LLM_KV & kv);

    // 函数: get_tokenizer_model
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_tokenizer_model
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    std::string get_tokenizer_model() const;
    // 函数: get_tokenizer_pre
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_tokenizer_pre
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    std::string get_tokenizer_pre() const;

    enum llama_vocab_type     get_type()     const;
    enum llama_vocab_pre_type get_pre_type() const;

    // 函数: n_tokens
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_tokens
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_tokens() const;
    // 函数: n_token_types
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_token_types
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_token_types() const;

    // 函数: type_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: type_name
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string type_name() const;

    // 函数: is_normal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_normal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_normal      (llama_token id) const;
    // 函数: is_unknown
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_unknown
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_unknown     (llama_token id) const;
    // 函数: is_control
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_control
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_control     (llama_token id) const;
    // 函数: is_byte
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_byte
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_byte        (llama_token id) const;
    // 函数: is_user_defined
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_user_defined
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_user_defined(llama_token id) const;
    // 函数: is_unused
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_unused
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_unused      (llama_token id) const;
    // 函数: is_eog
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_eog
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_eog         (llama_token id) const;

    // 函数: token_to_byte
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_to_byte
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint8_t     token_to_byte(llama_token id) const;
    // 函数: byte_to_token
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: byte_to_token
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token byte_to_token(uint8_t ch)     const;

    // 函数: text_to_token
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: text_to_token
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token text_to_token(const std::string & text) const;

    const token_data & get_token_data(llama_token id) const;

    // 函数: token_get_text
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_get_text
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    const char *     token_get_text (llama_token id) const;
    // 函数: token_get_score
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_get_score
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    float            token_get_score(llama_token id) const;
    // 函数: token_get_attr
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_get_attr
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    llama_token_attr token_get_attr (llama_token id) const;

    // 函数: token_bos
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_bos
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_bos() const;
    // 函数: token_eos
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_eos
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_eos() const;
    // 函数: token_eot
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_eot
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_eot() const;
    // 函数: token_eom
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_eom
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_eom() const;
    // 函数: token_unk
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_unk
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_unk() const;
    // 函数: token_sep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_sep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_sep() const;
    // 函数: token_nl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_nl
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_nl () const;
    // 函数: token_pad
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_pad
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_pad() const;
    // 函数: token_mask
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_mask
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_mask() const;

    // 函数: token_prefix
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_prefix
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_prefix() const;
    // 函数: token_middle
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_middle
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_middle() const;
    // 函数: token_suffix
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_suffix
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_suffix() const;

    // 函数: token_fim_pre
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_fim_pre
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_fim_pre() const;
    // 函数: token_fim_suf
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_fim_suf
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_fim_suf() const;
    // 函数: token_fim_mid
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_fim_mid
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_fim_mid() const;
    // 函数: token_fim_pad
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_fim_pad
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_fim_pad() const;
    // 函数: token_fim_rep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_fim_rep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_fim_rep() const;
    // 函数: token_fim_sep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: token_fim_sep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_token token_fim_sep() const;

    // 函数: get_add_space_prefix
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_add_space_prefix
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_add_space_prefix          () const;
    // 函数: get_add_bos
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_add_bos
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_add_bos                   () const;
    // 函数: get_add_eos
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_add_eos
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_add_eos                   () const;
    // 函数: get_add_sep
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_add_sep
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_add_sep                   () const;
    // 函数: get_ignore_merges
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_ignore_merges
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_ignore_merges             () const;
    // 函数: get_clean_spaces
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_clean_spaces
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_clean_spaces              () const;
    // 函数: get_remove_extra_whitespaces
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_remove_extra_whitespaces
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_remove_extra_whitespaces  () const;
    // 函数: get_escape_whitespaces
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_escape_whitespaces
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_escape_whitespaces        () const;
    // 函数: get_treat_whitespace_as_suffix
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_treat_whitespace_as_suffix
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_treat_whitespace_as_suffix() const;

    // 函数: max_token_len
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: max_token_len
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    int max_token_len() const;

    // 函数: find_bpe_rank
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: find_bpe_rank
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    int find_bpe_rank(const std::string & token_left, const std::string & token_right) const;
    std::vector<std::string> get_bpe_merges() const;

    std::vector<char> get_precompiled_charsmap() const;

    int32_t tokenize(
                   const char * text,
                      int32_t   text_len,
                  llama_token * tokens,
                      int32_t   n_tokens_max,
                         bool   add_special,
                         bool   parse_special) const;

    std::vector<llama_token> tokenize(
            const std::string & raw_text,
                         bool   add_special,
                         bool   parse_special = false) const;

    // does not write null-terminator to buf
    int32_t token_to_piece(
                  llama_token   token,
                         char * buf,
                      int32_t   length,
                      int32_t   lstrip,
                         bool   special) const;

    // use cached data
    const std::string & token_to_piece(llama_token token) const;

    int32_t detokenize(
            const llama_token * tokens,
                      int32_t   n_tokens,
                         char * text,
                      int32_t   text_len_max,
                         bool   remove_special,
                         bool   unparse_special) const;

    std::string detokenize(
            const std::vector<llama_token> & tokens,
                                      bool   special) const;

    // 函数: print_info
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: print_info
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void print_info() const;

private:
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 类: impl
    // 描述: impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    // 结构体: impl
    // 描述: impl结构体提供相关功能
    // 用途: 用于处理impl相关的操作
    struct impl;
    std::unique_ptr<impl> pimpl;
};
