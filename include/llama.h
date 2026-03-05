// ============================================================================
// 文件: llama.h
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/include/llama.h
// 描述: llama.cpp 核心头文件，定义了项目的主要数据结构和接口
// 作用: 为整个项目提供统一的 API 接口，包括模型加载、推理、采样等核心功能
// ============================================================================

#ifndef LLAMA_H
#define LLAMA_H

#include "ggml.h"
#include "ggml-cpu.h"
#include "ggml-backend.h"
#include "ggml-opt.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef LLAMA_SHARED
#    if defined(_WIN32) && !defined(__MINGW32__)
#        ifdef LLAMA_BUILD
#            define LLAMA_API __declspec(dllexport)
#        else
#            define LLAMA_API __declspec(dllimport)
#        endif
#    else
#        define LLAMA_API __attribute__ ((visibility ("default")))
#    endif
#else
#    define LLAMA_API
#endif

#ifdef __GNUC__
#    define DEPRECATED(func, hint) func __attribute__((deprecated(hint)))
#elif defined(_MSC_VER)
#    define DEPRECATED(func, hint) __declspec(deprecated(hint)) func
#else
#    define DEPRECATED(func, hint) func
#endif

#define LLAMA_DEFAULT_SEED 0xFFFFFFFF

#define LLAMA_TOKEN_NULL -1

#define LLAMA_FILE_MAGIC_GGLA 0x67676c61u // 'ggla'
#define LLAMA_FILE_MAGIC_GGSN 0x6767736eu // 'ggsn'
#define LLAMA_FILE_MAGIC_GGSQ 0x67677371u // 'ggsq'

#define LLAMA_SESSION_MAGIC   LLAMA_FILE_MAGIC_GGSN
#define LLAMA_SESSION_VERSION 9

#define LLAMA_STATE_SEQ_MAGIC   LLAMA_FILE_MAGIC_GGSQ
#define LLAMA_STATE_SEQ_VERSION 2

#ifdef __cplusplus
extern "C" {
#endif

    //
    // C interface
    //
    // TODO: show sample usage
    //

    // 结构体: llama_vocab
    // 描述: 词表结构，用于处理模型的分词和词汇管理
    // 作用: 提供词汇的编码和解码功能，是模型与文本交互的桥梁
    struct llama_vocab;
    
    // 结构体: llama_model
    // 描述: 模型结构，包含模型的权重、配置和状态
    // 作用: 存储模型的核心数据，是模型加载和推理的基础
    struct llama_model;
    
    // 结构体: llama_context
    // 描述: 上下文结构，包含推理过程中的状态和缓存
    // 作用: 管理模型推理的上下文环境，包括KV缓存、线程池等
    struct llama_context;
    
    // 结构体: llama_sampler
    // 描述: 采样器结构，用于从模型输出中生成token
    // 作用: 实现不同的采样策略，如贪婪采样、top-k采样等
    struct llama_sampler;

    typedef struct llama_memory_i * llama_memory_t;

    typedef int32_t llama_pos;    // 位置类型，用于表示token在序列中的位置
    typedef int32_t llama_token;  // token类型，用于表示模型的词汇单元
    typedef int32_t llama_seq_id; // 序列ID类型，用于标识不同的推理序列

    // 枚举: llama_vocab_type
    // 描述: 词表类型枚举，定义了不同模型使用的分词器类型
    // 作用: 用于区分不同模型的分词策略，确保正确的文本编码和解码
    enum llama_vocab_type {
        LLAMA_VOCAB_TYPE_NONE   = 0, // 无词表的模型
        LLAMA_VOCAB_TYPE_SPM    = 1, // LLaMA分词器，基于字节级BPE，带有字节回退
        LLAMA_VOCAB_TYPE_BPE    = 2, // GPT-2分词器，基于字节级BPE
        LLAMA_VOCAB_TYPE_WPM    = 3, // BERT分词器，基于WordPiece
        LLAMA_VOCAB_TYPE_UGM    = 4, // T5分词器，基于Unigram
        LLAMA_VOCAB_TYPE_RWKV   = 5, // RWKV分词器，基于贪婪分词
        LLAMA_VOCAB_TYPE_PLAMO2 = 6, // PLaMo-2分词器，基于Aho-Corasick和动态规划
    };

    // 枚举: llama_rope_type
    // 描述: RoPE（旋转位置编码）类型枚举
    // 作用: 用于指定模型使用的位置编码方式，影响模型对序列位置的理解
    enum llama_rope_type {
        LLAMA_ROPE_TYPE_NONE   = -1, // 无RoPE编码
        LLAMA_ROPE_TYPE_NORM   = 0,  // 标准RoPE编码
        LLAMA_ROPE_TYPE_NEOX   = GGML_ROPE_TYPE_NEOX,  // GPT-NeoX风格的RoPE
        LLAMA_ROPE_TYPE_MROPE  = GGML_ROPE_TYPE_MROPE, // 改进的RoPE
        LLAMA_ROPE_TYPE_IMROPE = GGML_ROPE_TYPE_IMROPE, // 改进的RoPE变体
        LLAMA_ROPE_TYPE_VISION = GGML_ROPE_TYPE_VISION, // 视觉模型专用RoPE
    };

    // 枚举: llama_token_type
    // 描述: token类型枚举
    // 作用: 用于标识不同类型的token，如正常token、控制token等
    // 注意: 待GGUF文件支持per token属性后将被移除
    enum llama_token_type { 
        LLAMA_TOKEN_TYPE_UNDEFINED    = 0, // 未定义类型
        LLAMA_TOKEN_TYPE_NORMAL       = 1, // 正常token
        LLAMA_TOKEN_TYPE_UNKNOWN      = 2, // 未知token
        LLAMA_TOKEN_TYPE_CONTROL      = 3, // 控制token
        LLAMA_TOKEN_TYPE_USER_DEFINED = 4, // 用户定义token
        LLAMA_TOKEN_TYPE_UNUSED       = 5, // 未使用token
        LLAMA_TOKEN_TYPE_BYTE         = 6, // 字节token
    };

    // 枚举: llama_token_attr
    // 描述: token属性枚举，使用位掩码表示
    // 作用: 用于描述token的各种属性，如是否为控制token、是否已归一化等
    enum llama_token_attr {
        LLAMA_TOKEN_ATTR_UNDEFINED    = 0,      // 未定义属性
        LLAMA_TOKEN_ATTR_UNKNOWN      = 1 << 0, // 未知token
        LLAMA_TOKEN_ATTR_UNUSED       = 1 << 1, // 未使用token
        LLAMA_TOKEN_ATTR_NORMAL       = 1 << 2, // 正常token
        LLAMA_TOKEN_ATTR_CONTROL      = 1 << 3, // 控制token
        LLAMA_TOKEN_ATTR_USER_DEFINED = 1 << 4, // 用户定义token
        LLAMA_TOKEN_ATTR_BYTE         = 1 << 5, // 字节token
        LLAMA_TOKEN_ATTR_NORMALIZED   = 1 << 6, // 已归一化token
        LLAMA_TOKEN_ATTR_LSTRIP       = 1 << 7, // 左侧空格token
        LLAMA_TOKEN_ATTR_RSTRIP       = 1 << 8, // 右侧空格token
        LLAMA_TOKEN_ATTR_SINGLE_WORD  = 1 << 9, // 单字token
    };

    // 枚举: llama_ftype
    // 描述: 模型文件类型枚举，定义了不同的模型量化格式
    // 作用: 用于指定模型的量化方式，影响模型的大小和推理性能
    enum llama_ftype {
        LLAMA_FTYPE_ALL_F32              = 0,  // 全32位浮点数
        LLAMA_FTYPE_MOSTLY_F16           = 1,  // 主要使用16位浮点数（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q4_0          = 2,  // 主要使用4位量化（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q4_1          = 3,  // 主要使用4位量化变体（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q8_0          = 7,  // 主要使用8位量化（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q5_0          = 8,  // 主要使用5位量化（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q5_1          = 9,  // 主要使用5位量化变体（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q2_K          = 10, // 主要使用K量化2位（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q3_K_S        = 11, // 主要使用K量化3位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q3_K_M        = 12, // 主要使用K量化3位中版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q3_K_L        = 13, // 主要使用K量化3位大版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q4_K_S        = 14, // 主要使用K量化4位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q4_K_M        = 15, // 主要使用K量化4位中版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q5_K_S        = 16, // 主要使用K量化5位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q5_K_M        = 17, // 主要使用K量化5位中版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q6_K          = 18, // 主要使用K量化6位（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ2_XXS       = 19, // 主要使用IQ量化2位超小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ2_XS        = 20, // 主要使用IQ量化2位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_Q2_K_S        = 21, // 主要使用K量化2位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ3_XS        = 22, // 主要使用IQ量化3位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ3_XXS       = 23, // 主要使用IQ量化3位超小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ1_S         = 24, // 主要使用IQ量化1位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ4_NL        = 25, // 主要使用IQ量化4位无长尾版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ3_S         = 26, // 主要使用IQ量化3位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ3_M         = 27, // 主要使用IQ量化3位中版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ2_S         = 28, // 主要使用IQ量化2位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ2_M         = 29, // 主要使用IQ量化2位中版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ4_XS        = 30, // 主要使用IQ量化4位小版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_IQ1_M         = 31, // 主要使用IQ量化1位中版本（除1D张量外）
        LLAMA_FTYPE_MOSTLY_BF16          = 32, // 主要使用BF16格式（除1D张量外）
        LLAMA_FTYPE_MOSTLY_TQ1_0         = 36, // 主要使用TQ量化1位（除1D张量外）
        LLAMA_FTYPE_MOSTLY_TQ2_0         = 37, // 主要使用TQ量化2位（除1D张量外）
        LLAMA_FTYPE_MOSTLY_MXFP4_MOE     = 38, // 主要使用MXFP4格式（除1D张量外）

        LLAMA_FTYPE_GUESSED = 1024, // 模型文件中未指定
    };

    // 枚举: llama_rope_scaling_type
    // 描述: RoPE缩放类型枚举
    // 作用: 用于指定模型在处理长序列时的RoPE缩放策略
    enum llama_rope_scaling_type {
        LLAMA_ROPE_SCALING_TYPE_UNSPECIFIED = -1, // 未指定
        LLAMA_ROPE_SCALING_TYPE_NONE        = 0,  // 无缩放
        LLAMA_ROPE_SCALING_TYPE_LINEAR      = 1,  // 线性缩放
        LLAMA_ROPE_SCALING_TYPE_YARN        = 2,  // YaRN缩放
        LLAMA_ROPE_SCALING_TYPE_LONGROPE    = 3,  // LongRoPE缩放
        LLAMA_ROPE_SCALING_TYPE_MAX_VALUE   = LLAMA_ROPE_SCALING_TYPE_LONGROPE, // 最大值
    };

    // 枚举: llama_pooling_type
    // 描述: 池化类型枚举
    // 作用: 用于指定嵌入结果的池化方式
    enum llama_pooling_type {
        LLAMA_POOLING_TYPE_UNSPECIFIED = -1, // 未指定
        LLAMA_POOLING_TYPE_NONE = 0,         // 无池化
        LLAMA_POOLING_TYPE_MEAN = 1,         // 均值池化
        LLAMA_POOLING_TYPE_CLS  = 2,         // CLS标记池化
        LLAMA_POOLING_TYPE_LAST = 3,         // 最后一个标记池化
        LLAMA_POOLING_TYPE_RANK = 4,         // 用于重排序模型，将分类头附加到图上
    };

    // 枚举: llama_attention_type
    // 描述: 注意力类型枚举
    // 作用: 用于指定模型使用的注意力机制类型
    enum llama_attention_type {
        LLAMA_ATTENTION_TYPE_UNSPECIFIED = -1, // 未指定
        LLAMA_ATTENTION_TYPE_CAUSAL      = 0,  // 因果注意力
        LLAMA_ATTENTION_TYPE_NON_CAUSAL  = 1,  // 非因果注意力
    };

    // 枚举: llama_flash_attn_type
    // 描述: Flash Attention类型枚举
    // 作用: 用于指定是否启用Flash Attention优化
    enum llama_flash_attn_type {
        LLAMA_FLASH_ATTN_TYPE_AUTO     = -1, // 自动选择
        LLAMA_FLASH_ATTN_TYPE_DISABLED = 0,  // 禁用
        LLAMA_FLASH_ATTN_TYPE_ENABLED  = 1,  // 启用
    };

    // 函数: llama_flash_attn_type_name
    // 描述: 获取Flash Attention类型的名称
    // 参数:
    //   - flash_attn_type: Flash Attention类型枚举值
    // 返回: 类型名称的字符串指针
    LLAMA_API const char * llama_flash_attn_type_name(enum llama_flash_attn_type flash_attn_type);

    // 枚举: llama_split_mode
    // 描述: 模型拆分模式枚举
    // 作用: 用于指定模型如何在多个GPU之间拆分
    enum llama_split_mode {
        LLAMA_SPLIT_MODE_NONE  = 0, // 单GPU
        LLAMA_SPLIT_MODE_LAYER = 1, // 跨GPU拆分层和KV缓存
        LLAMA_SPLIT_MODE_ROW   = 2, // 跨GPU拆分层和KV缓存，支持张量并行
    };

    // 结构体: llama_token_data
    // 描述: token数据结构，包含token的ID、对数概率和概率
    // 作用: 用于存储和处理模型输出的token信息
    typedef struct llama_token_data {
        llama_token id; // token ID
        float logit;    // token的对数概率
        float p;        // token的概率
    } llama_token_data;

    // 结构体: llama_token_data_array
    // 描述: token数据数组结构，包含多个token数据
    // 作用: 用于批量处理token数据，是采样器的输入和输出
    typedef struct llama_token_data_array {
        llama_token_data * data;    // token数据数组指针
        size_t size;                // 数组大小
        int64_t selected;           // 选中的token在数组中的索引
        bool sorted;                // 数据是否已排序
    } llama_token_data_array;

    // 类型定义: llama_progress_callback
    // 描述: 进度回调函数类型
    // 作用: 用于在模型加载等操作中报告进度
    // 参数:
    //   - progress: 进度值，范围0.0-1.0
    //   - user_data: 用户数据指针
    // 返回: 布尔值，表示是否继续操作
    typedef bool (*llama_progress_callback)(float progress, void * user_data);

    // 结构体: llama_batch
    // 描述: 批处理输入数据结构，用于llama_encode/llama_decode
    // 作用: 可以包含一个或多个序列的输入数据
    // 注意: 提供的数组（token、embd、pos等）必须有n_tokens大小
    typedef struct llama_batch {
        int32_t n_tokens;           // token数量

        llama_token  *  token;      // token ID数组（当embd为NULL时使用）
        float        *  embd;       // token嵌入数组（当token为NULL时使用）
        llama_pos    *  pos;        // token在序列中的位置数组
        int32_t      *  n_seq_id;   // 每个token所属的序列ID数量
        llama_seq_id ** seq_id;     // 每个token所属的序列ID数组
        int8_t       *  logits;     // 是否输出logits和/或嵌入（0表示不输出）
    } llama_batch;

    // 枚举: llama_model_kv_override_type
    // 描述: 模型键值覆盖类型枚举
    // 作用: 用于指定模型元数据覆盖的值类型
    enum llama_model_kv_override_type {
        LLAMA_KV_OVERRIDE_TYPE_INT,    // 整数类型
        LLAMA_KV_OVERRIDE_TYPE_FLOAT,  // 浮点数类型
        LLAMA_KV_OVERRIDE_TYPE_BOOL,   // 布尔类型
        LLAMA_KV_OVERRIDE_TYPE_STR,    // 字符串类型
    };

    // 枚举: llama_model_meta_key
    // 描述: 模型元数据键枚举
    // 作用: 用于指定模型的元数据键，如采样参数等
    enum llama_model_meta_key {
        LLAMA_MODEL_META_KEY_SAMPLING_SEQUENCE,      // 采样序列
        LLAMA_MODEL_META_KEY_SAMPLING_TOP_K,         // 采样top-k参数
        LLAMA_MODEL_META_KEY_SAMPLING_TOP_P,         // 采样top-p参数
        LLAMA_MODEL_META_KEY_SAMPLING_MIN_P,         // 采样min-p参数
        LLAMA_MODEL_META_KEY_SAMPLING_XTC_PROBABILITY, // 采样XTC概率
        LLAMA_MODEL_META_KEY_SAMPLING_XTC_THRESHOLD,   // 采样XTC阈值
        LLAMA_MODEL_META_KEY_SAMPLING_TEMP,          // 采样温度
        LLAMA_MODEL_META_KEY_SAMPLING_PENALTY_LAST_N,  // 采样重复惩罚最近N个token
        LLAMA_MODEL_META_KEY_SAMPLING_PENALTY_REPEAT,  // 采样重复惩罚
        LLAMA_MODEL_META_KEY_SAMPLING_MIROSTAT,       // 采样Mirostat
        LLAMA_MODEL_META_KEY_SAMPLING_MIROSTAT_TAU,   // 采样Mirostat tau参数
        LLAMA_MODEL_META_KEY_SAMPLING_MIROSTAT_ETA,   // 采样Mirostat eta参数
    };

    // 结构体: llama_model_kv_override
    // 描述: 模型键值覆盖结构
    // 作用: 用于覆盖模型的元数据键值对
    struct llama_model_kv_override {
        enum llama_model_kv_override_type tag; // 值类型标签

        char key[128]; // 键名

        union {
            int64_t val_i64;   // 整数值
            double  val_f64;   // 浮点数值
            bool    val_bool;  // 布尔值
            char    val_str[128]; // 字符串值
        };
    };

    // 结构体: llama_model_tensor_buft_override
    // 描述: 模型张量缓冲区类型覆盖结构
    // 作用: 用于为匹配模式的张量指定缓冲区类型
    struct llama_model_tensor_buft_override {
        const char * pattern;               // 张量名称模式
        ggml_backend_buffer_type_t buft;    // 缓冲区类型
    };

    // 结构体: llama_model_params
    // 描述: 模型参数结构，包含模型加载和配置的各种参数
    // 作用: 用于控制模型的加载方式、设备分配、内存使用等
    struct llama_model_params {
        ggml_backend_dev_t * devices; // 用于卸载的设备列表（NULL表示使用所有可用设备）

        const struct llama_model_tensor_buft_override * tensor_buft_overrides; // 用于匹配模式的张量的缓冲区类型列表

        int32_t n_gpu_layers; // 存储在VRAM中的层数，负值表示所有层
        enum llama_split_mode split_mode; // 如何在多个GPU之间拆分布模型

        int32_t main_gpu; // 当split_mode为LLAMA_SPLIT_MODE_NONE时，用于整个模型的GPU

        const float * tensor_split; // 模型（层或行）卸载到每个GPU的比例，大小：llama_max_devices()

        llama_progress_callback progress_callback; // 进度回调函数，传入0.0-1.0之间的进度值
        void * progress_callback_user_data; // 传递给进度回调的上下文指针

        const struct llama_model_kv_override * kv_overrides; // 模型元数据的键值对覆盖

        // 布尔值参数（放在一起以避免复制时的对齐问题）
        bool vocab_only;      // 只加载词汇表，不加载权重
        bool use_mmap;        // 如果可能，使用mmap
        bool use_direct_io;   // 使用直接IO，当支持时优先于use_mmap
        bool use_mlock;       // 强制系统将模型保持在RAM中
        bool check_tensors;   // 验证模型张量数据
        bool use_extra_bufts; // 使用额外的缓冲区类型（用于权重重新打包）
        bool no_host;         // 绕过主机缓冲区，允许使用额外的缓冲区
        bool no_alloc;        // 只加载元数据并模拟内存分配
    };

    // 结构体: llama_sampler_seq_config
    // 描述: 采样器序列配置结构
    // 作用: 用于为特定序列配置采样器
    struct llama_sampler_seq_config {
        llama_seq_id           seq_id;  // 序列ID
        struct llama_sampler * sampler; // 采样器指针
    };

    // 结构体: llama_context_params
    // 描述: 上下文参数结构，包含模型推理的各种配置参数
    // 作用: 用于控制模型推理的上下文大小、批处理大小、线程数等
    // 注意: 更改标记为[EXPERIMENTAL]的参数的默认值可能会在某些配置中导致崩溃或不正确的结果
    struct llama_context_params {
        uint32_t n_ctx;             // 文本上下文大小，0表示使用模型默认值
        uint32_t n_batch;           // 可以提交给llama_decode的逻辑最大批处理大小
        uint32_t n_ubatch;          // 物理最大批处理大小
        uint32_t n_seq_max;         // 最大序列数（即循环模型的不同状态）
        int32_t  n_threads;         // 用于生成的线程数
        int32_t  n_threads_batch;   // 用于批处理的线程数

        enum llama_rope_scaling_type rope_scaling_type; // RoPE缩放类型
        enum llama_pooling_type      pooling_type;      // 是否按序列ID池化（求和）嵌入结果
        enum llama_attention_type    attention_type;    // 用于嵌入的注意力类型
        enum llama_flash_attn_type   flash_attn_type;   // 何时启用Flash Attention

        float    rope_freq_base;   // RoPE基础频率，0表示使用模型默认值
        float    rope_freq_scale;  // RoPE频率缩放因子，0表示使用模型默认值
        float    yarn_ext_factor;  // YaRN外推混合因子，负值表示使用模型默认值
        float    yarn_attn_factor; // YaRN幅度缩放因子
        float    yarn_beta_fast;   // YaRN低校正维度
        float    yarn_beta_slow;   // YaRN高校正维度
        uint32_t yarn_orig_ctx;    // YaRN原始上下文大小
        float    defrag_thold;     // [已弃用] 如果空洞/大小 > 阈值，则碎片整理KV缓存，<= 0表示禁用（默认）

        ggml_backend_sched_eval_callback cb_eval; // 评估回调
        void * cb_eval_user_data;                // 评估回调用户数据

        enum ggml_type type_k; // K缓存的数据类型 [EXPERIMENTAL]
        enum ggml_type type_v; // V缓存的数据类型 [EXPERIMENTAL]

        ggml_abort_callback abort_callback;    // 中止回调
        void *              abort_callback_data; // 中止回调数据

        // 布尔值参数（放在一起并在结构末尾以避免复制时的对齐问题）
        bool embeddings;  // 如果为true，提取嵌入（与logits一起）
        bool offload_kqv; // 将KQV操作（包括KV缓存）卸载到GPU
        bool no_perf;     // 测量性能时间
        bool op_offload;  // 将主机张量操作卸载到设备
        bool swa_full;    // 使用全尺寸SWA缓存
        bool kv_unified;  // 在计算注意力时使用跨输入序列的统一缓冲区

        // [EXPERIMENTAL]
        // 后端采样器链配置（确保调用者保持采样器链活动）
        // 注意：采样器必须是采样器链（即使用llama_sampler_chain_init）
        struct llama_sampler_seq_config * samplers; // 采样器配置数组
        size_t                            n_samplers; // 采样器配置数量
    };

    // 结构体: llama_model_quantize_params
    // 描述: 模型量化参数结构
    // 作用: 用于控制模型量化的过程和结果
    typedef struct llama_model_quantize_params {
        int32_t nthread;                      // 用于量化的线程数，如果<=0将使用std::thread::hardware_concurrency()
        enum llama_ftype ftype;               // 量化到这个llama_ftype
        enum ggml_type output_tensor_type;    // 输出张量类型
        enum ggml_type token_embedding_type;  // token嵌入张量类型
        bool allow_requantize;                // 允许量化非f32/f16张量
        bool quantize_output_tensor;          // 量化output.weight
        bool only_copy;                       // 只复制张量 - 忽略ftype、allow_requantize和quantize_output_tensor
        bool pure;                            // 将所有张量量化为默认类型
        bool keep_split;                      // 量化到相同数量的分片
        bool dry_run;                         // 计算并显示最终量化大小，不执行量化
        void * imatrix;                       // 重要性矩阵数据指针
        void * kv_overrides;                  // 包含覆盖的向量指针
        void * tensor_types;                  // 包含张量类型的向量指针
        void * prune_layers;                  // 包含要剪枝的层索引的向量指针
    } llama_model_quantize_params;

    // 结构体: llama_logit_bias
    // 描述: logit偏置结构
    // 作用: 用于为特定token添加偏置，影响其生成概率
    typedef struct llama_logit_bias {
        llama_token token; // token ID
        float bias;        // 偏置值
    } llama_logit_bias;

    // 结构体: llama_sampler_chain_params
    // 描述: 采样器链参数结构
    // 作用: 用于配置采样器链的行为
    typedef struct llama_sampler_chain_params {
        bool no_perf; // 是否测量性能时间
    } llama_sampler_chain_params;

    // 结构体: llama_chat_message
    // 描述: 聊天消息结构
    // 作用: 用于聊天模板中的消息表示
    typedef struct llama_chat_message {
        const char * role;    // 消息角色
        const char * content; // 消息内容
    } llama_chat_message;

    // 结构体: llama_adapter_lora
    // 描述: LoRA适配器结构
    // 作用: 用于实现模型的LoRA微调
    struct llama_adapter_lora;

    // Helpers for getting default parameters
    // TODO: update API to start accepting pointers to params structs (https://github.com/ggml-org/llama.cpp/discussions/9172)
    LLAMA_API struct llama_model_params          llama_model_default_params(void);
    LLAMA_API struct llama_context_params        llama_context_default_params(void);
    LLAMA_API struct llama_sampler_chain_params  llama_sampler_chain_default_params(void);
    LLAMA_API struct llama_model_quantize_params llama_model_quantize_default_params(void);

    // Initialize the llama + ggml backend
    // If numa is true, use NUMA optimizations
    // Call once at the start of the program
    // 函数: llama_backend_init
    // 描述: llama_backend_init函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_init
    // 描述: llama_backend_init函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_init
    // 描述: llama_backend_init函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_init
    // 描述: llama_backend_init函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_init
    // 描述: llama_backend_init函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_init
    // 描述: llama_backend_init函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API void llama_backend_init(void);

    // Call once at the end of the program - currently only used for MPI
    // 函数: llama_backend_free
    // 描述: llama_backend_free函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_free
    // 描述: llama_backend_free函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_free
    // 描述: llama_backend_free函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_free
    // 描述: llama_backend_free函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_free
    // 描述: llama_backend_free函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_backend_free
    // 描述: llama_backend_free函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API void llama_backend_free(void);

    //optional:
    // 函数: llama_numa_init
    // 描述: llama_numa_init函数提供相关功能
    // 参数: enum ggml_numa_strategy numa
    // 返回: 无返回值

    // 函数: llama_numa_init
    // 描述: llama_numa_init函数提供相关功能
    // 参数: enum ggml_numa_strategy numa
    // 返回: 无返回值

    // 函数: llama_numa_init
    // 描述: llama_numa_init函数提供相关功能
    // 参数: enum ggml_numa_strategy numa
    // 返回: 无返回值

    // 函数: llama_numa_init
    // 描述: llama_numa_init函数提供相关功能
    // 参数: enum ggml_numa_strategy numa
    // 返回: 无返回值

    // 函数: llama_numa_init
    // 描述: llama_numa_init函数提供相关功能
    // 参数: enum ggml_numa_strategy numa
    // 返回: 无返回值

    // 函数: llama_numa_init
    // 描述: llama_numa_init函数提供相关功能
    // 参数: enum ggml_numa_strategy numa
    // 返回: 无返回值

    LLAMA_API void llama_numa_init(enum ggml_numa_strategy numa);

    // Optional: an auto threadpool gets created in ggml if not passed explicitly
    // 函数: llama_attach_threadpool
    // 描述: llama_attach_threadpool函数提供相关功能
    // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, ggml_threadpool_t   threadpool, ggml_threadpool_t   threadpool_batch
    // 返回: 无返回值

    // 函数: llama_attach_threadpool
    // 描述: llama_attach_threadpool函数提供相关功能
    // 参数: // 函数: llama_detach_threadpool // 描述: llama_detach_threadpool函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  LLAMA_API void llama_detach_threadpool(struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_attach_threadpool
    // 描述: llama_attach_threadpool函数提供相关功能
    // 参数: DEPRECATED(LLAMA_API struct llama_model * llama_load_model_from_file( const char * path_model, // 类: llama_model_params // 描述: llama_model_params类提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 类: llama_model_params // 描述: llama_model_params类提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 结构体: llama_model_params // 描述: llama_model_params结构体提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 结构体: llama_model_params // 描述: llama_model_params结构体提供相关功能 // 用途: 用于处理llama_model_params相关的操作 struct llama_model_params   params
    // 返回: llama_model *类型返回值

    // 函数: llama_attach_threadpool
    // 描述: llama_attach_threadpool函数提供相关功能
    // 参数: "use llama_model_load_from_file instead"
    // 返回: 无返回值

    // 函数: llama_attach_threadpool
    // 描述: llama_attach_threadpool函数提供相关功能
    // 参数: // Load the model from a file // If the file is split into multiple parts, the file name must follow this pattern: <name>-%05d-of-%05d.gguf // If the split file name does not follow this pattern, use llama_model_load_from_splits LLAMA_API struct llama_model * llama_model_load_from_file( const char * path_model, // 类: llama_model_params // 描述: llama_model_params类提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 类: llama_model_params // 描述: llama_model_params类提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 结构体: llama_model_params // 描述: llama_model_params结构体提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 结构体: llama_model_params // 描述: llama_model_params结构体提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 结构体: llama_model_params // 描述: llama_model_params结构体提供相关功能 // 用途: 用于处理llama_model_params相关的操作 // 结构体: llama_model_params // 描述: llama_model_params结构体提供相关功能 // 用途: 用于处理llama_model_params相关的操作 struct llama_model_params   params
    // 返回: llama_model *类型返回值

    // 函数: llama_attach_threadpool
    // 描述: llama_attach_threadpool函数提供相关功能
    // 参数: // Load the model from multiple splits (support custom naming scheme
    // 返回: 无返回值

    LLAMA_API void llama_attach_threadpool(
    // The paths must be in the correct order
    LLAMA_API struct llama_model * llama_model_load_from_splits(
                             const char ** paths,
                                 size_t    n_paths,
              // 类: llama_model_params
              // 描述: llama_model_params类提供相关功能
              // 用途: 用于处理llama_model_params相关的操作
              // 类: llama_model_params
              // 描述: llama_model_params类提供相关功能
              // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
              struct llama_model_params    params);

    // 函数: llama_model_save_to_file
    // 描述: llama_model_save_to_file函数提供相关功能
    // 参数: const struct llama_model * model, const char * path_model
    // 返回: 无返回值

    // 函数: llama_model_save_to_file
    // 描述: llama_model_save_to_file函数提供相关功能
    // 参数: DEPRECATED(LLAMA_API void llama_free_model(struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_save_to_file
    // 描述: llama_model_save_to_file函数提供相关功能
    // 参数: "use llama_model_free instead"
    // 返回: 无返回值

    // 函数: llama_model_save_to_file
    // 描述: llama_model_save_to_file函数提供相关功能
    // 参数: // 函数: llama_model_free // 描述: llama_model_free函数提供相关功能 // 参数: struct llama_model * model // 返回: 无返回值  // 函数: llama_model_free // 描述: llama_model_free函数提供相关功能 // 参数: struct llama_model * model // 返回: 无返回值  // 函数: llama_model_free // 描述: llama_model_free函数提供相关功能 // 参数: struct llama_model * model // 返回: 无返回值  LLAMA_API void llama_model_free(struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_save_to_file
    // 描述: llama_model_save_to_file函数提供相关功能
    // 参数: LLAMA_API struct llama_context * llama_init_from_model( // 类: llama_model // 描述: llama_model类提供相关功能 // 用途: 用于处理llama_model相关的操作 // 类: llama_model // 描述: llama_model类提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 struct llama_model * model, // 类: llama_context_params // 描述: llama_context_params类提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 类: llama_context_params // 描述: llama_context_params类提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 struct llama_context_params   params
    // 返回: llama_context *类型返回值

    // 函数: llama_model_save_to_file
    // 描述: llama_model_save_to_file函数提供相关功能
    // 参数: DEPRECATED(LLAMA_API struct llama_context * llama_new_context_with_model( // 类: llama_model // 描述: llama_model类提供相关功能 // 用途: 用于处理llama_model相关的操作 // 类: llama_model // 描述: llama_model类提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 struct llama_model * model, // 类: llama_context_params // 描述: llama_context_params类提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 类: llama_context_params // 描述: llama_context_params类提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 // 结构体: llama_context_params // 描述: llama_context_params结构体提供相关功能 // 用途: 用于处理llama_context_params相关的操作 struct llama_context_params   params
    // 返回: llama_context *类型返回值

    LLAMA_API void llama_model_save_to_file(
            "use llama_init_from_model instead");

    // Frees all allocated memory
    // 函数: llama_free
    // 描述: llama_free函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_free
    // 描述: llama_free函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_free
    // 描述: llama_free函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_free
    // 描述: llama_free函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_free
    // 描述: llama_free函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_free
    // 描述: llama_free函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API void llama_free(struct llama_context * ctx);

    enum llama_params_fit_status {
        LLAMA_PARAMS_FIT_STATUS_SUCCESS = 0, // found allocations that are projected to fit
        LLAMA_PARAMS_FIT_STATUS_FAILURE = 1, // could not find allocations that are projected to fit
        LLAMA_PARAMS_FIT_STATUS_ERROR   = 2, // a hard error occurred, e.g. because no model could be found at the specified path
    };

    // fits mparams and cparams to free device memory (assumes system memory is unlimited)
    //   - returns true if the parameters could be successfully modified to fit device memory
    //   - this function is NOT thread safe because it modifies the global llama logger state
    //   - only parameters that have the same value as in llama_default_model_params are modified
    //     with the exception of the context size which is modified if and only if equal to 0
    LLAMA_API enum llama_params_fit_status llama_params_fit(
                                   const char   * path_model,
                    // 类: llama_model_params
                    // 描述: llama_model_params类提供相关功能
                    // 用途: 用于处理llama_model_params相关的操作
                    // 类: llama_model_params
                    // 描述: llama_model_params类提供相关功能
                    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
    // 结构体: llama_model_params
    // 描述: llama_model_params结构体提供相关功能
    // 用途: 用于处理llama_model_params相关的操作
                    struct llama_model_params   * mparams,
                    // 类: llama_context_params
                    // 描述: llama_context_params类提供相关功能
                    // 用途: 用于处理llama_context_params相关的操作
                    // 类: llama_context_params
                    // 描述: llama_context_params类提供相关功能
                    // 用途: 用于处理llama_context_params相关的操作
    // 结构体: llama_context_params
    // 描述: llama_context_params结构体提供相关功能
    // 用途: 用于处理llama_context_params相关的操作
    // 结构体: llama_context_params
    // 描述: llama_context_params结构体提供相关功能
    // 用途: 用于处理llama_context_params相关的操作
    // 结构体: llama_context_params
    // 描述: llama_context_params结构体提供相关功能
    // 用途: 用于处理llama_context_params相关的操作
    // 结构体: llama_context_params
    // 描述: llama_context_params结构体提供相关功能
    // 用途: 用于处理llama_context_params相关的操作
    // 结构体: llama_context_params
    // 描述: llama_context_params结构体提供相关功能
    // 用途: 用于处理llama_context_params相关的操作
    // 结构体: llama_context_params
    // 描述: llama_context_params结构体提供相关功能
    // 用途: 用于处理llama_context_params相关的操作
                    struct llama_context_params * cparams,
                                          float * tensor_split,          // writable buffer for tensor split, needs at least llama_max_devices elements
        // 类: llama_model_tensor_buft_override
        // 描述: llama_model_tensor_buft_override类提供相关功能
        // 用途: 用于处理llama_model_tensor_buft_override相关的操作
        // 类: llama_model_tensor_buft_override
        // 描述: llama_model_tensor_buft_override类提供相关功能
        // 用途: 用于处理llama_model_tensor_buft_override相关的操作
    // 结构体: llama_model_tensor_buft_override
    // 描述: llama_model_tensor_buft_override结构体提供相关功能
    // 用途: 用于处理llama_model_tensor_buft_override相关的操作
    // 结构体: llama_model_tensor_buft_override
    // 描述: llama_model_tensor_buft_override结构体提供相关功能
    // 用途: 用于处理llama_model_tensor_buft_override相关的操作
    // 结构体: llama_model_tensor_buft_override
    // 描述: llama_model_tensor_buft_override结构体提供相关功能
    // 用途: 用于处理llama_model_tensor_buft_override相关的操作
    // 结构体: llama_model_tensor_buft_override
    // 描述: llama_model_tensor_buft_override结构体提供相关功能
    // 用途: 用于处理llama_model_tensor_buft_override相关的操作
    // 结构体: llama_model_tensor_buft_override
    // 描述: llama_model_tensor_buft_override结构体提供相关功能
    // 用途: 用于处理llama_model_tensor_buft_override相关的操作
    // 结构体: llama_model_tensor_buft_override
    // 描述: llama_model_tensor_buft_override结构体提供相关功能
    // 用途: 用于处理llama_model_tensor_buft_override相关的操作
        struct llama_model_tensor_buft_override * tensor_buft_overrides, // writable buffer for overrides, needs at least llama_max_tensor_buft_overrides elements
                                         size_t * margins,               // margins of memory to leave per device in bytes
                                       uint32_t   n_ctx_min,             // minimum context size to set when trying to reduce memory use
                            enum ggml_log_level   log_level);            // minimum log level to print during fitting, lower levels go to debug log

    // 函数: llama_time_us
    // 描述: llama_time_us函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_time_us
    // 描述: llama_time_us函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_time_us
    // 描述: llama_time_us函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_time_us
    // 描述: llama_time_us函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_time_us
    // 描述: llama_time_us函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_time_us
    // 描述: llama_time_us函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API int64_t llama_time_us(void);

    // 函数: llama_max_devices
    // 描述: llama_max_devices函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_devices
    // 描述: llama_max_devices函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_devices
    // 描述: llama_max_devices函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_devices
    // 描述: llama_max_devices函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_devices
    // 描述: llama_max_devices函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_devices
    // 描述: llama_max_devices函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API size_t llama_max_devices(void);
    // 函数: llama_max_parallel_sequences
    // 描述: llama_max_parallel_sequences函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_parallel_sequences
    // 描述: llama_max_parallel_sequences函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_parallel_sequences
    // 描述: llama_max_parallel_sequences函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_parallel_sequences
    // 描述: llama_max_parallel_sequences函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_parallel_sequences
    // 描述: llama_max_parallel_sequences函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_parallel_sequences
    // 描述: llama_max_parallel_sequences函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API size_t llama_max_parallel_sequences(void);
    // 函数: llama_max_tensor_buft_overrides
    // 描述: llama_max_tensor_buft_overrides函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_tensor_buft_overrides
    // 描述: llama_max_tensor_buft_overrides函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_tensor_buft_overrides
    // 描述: llama_max_tensor_buft_overrides函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_tensor_buft_overrides
    // 描述: llama_max_tensor_buft_overrides函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_tensor_buft_overrides
    // 描述: llama_max_tensor_buft_overrides函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_max_tensor_buft_overrides
    // 描述: llama_max_tensor_buft_overrides函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API size_t llama_max_tensor_buft_overrides(void);

    // 函数: llama_supports_mmap
    // 描述: llama_supports_mmap函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mmap
    // 描述: llama_supports_mmap函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mmap
    // 描述: llama_supports_mmap函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mmap
    // 描述: llama_supports_mmap函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mmap
    // 描述: llama_supports_mmap函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mmap
    // 描述: llama_supports_mmap函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API bool llama_supports_mmap       (void);
    // 函数: llama_supports_mlock
    // 描述: llama_supports_mlock函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mlock
    // 描述: llama_supports_mlock函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mlock
    // 描述: llama_supports_mlock函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mlock
    // 描述: llama_supports_mlock函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mlock
    // 描述: llama_supports_mlock函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_mlock
    // 描述: llama_supports_mlock函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API bool llama_supports_mlock      (void);
    // 函数: llama_supports_gpu_offload
    // 描述: llama_supports_gpu_offload函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_gpu_offload
    // 描述: llama_supports_gpu_offload函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_gpu_offload
    // 描述: llama_supports_gpu_offload函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_gpu_offload
    // 描述: llama_supports_gpu_offload函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_gpu_offload
    // 描述: llama_supports_gpu_offload函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_gpu_offload
    // 描述: llama_supports_gpu_offload函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API bool llama_supports_gpu_offload(void);
    // 函数: llama_supports_rpc
    // 描述: llama_supports_rpc函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_rpc
    // 描述: llama_supports_rpc函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_rpc
    // 描述: llama_supports_rpc函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_rpc
    // 描述: llama_supports_rpc函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_rpc
    // 描述: llama_supports_rpc函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_supports_rpc
    // 描述: llama_supports_rpc函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API bool llama_supports_rpc        (void);

    // NOTE: After creating a llama_context, it is recommended to query the actual values using these functions
    //       In some cases the requested values via llama_context_params may differ from the actual values used by the context
    //       ref: https://github.com/ggml-org/llama.cpp/pull/17046#discussion_r2503085732
    // 函数: llama_n_ctx
    // 描述: llama_n_ctx函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx
    // 描述: llama_n_ctx函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx
    // 描述: llama_n_ctx函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx
    // 描述: llama_n_ctx函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx
    // 描述: llama_n_ctx函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx
    // 描述: llama_n_ctx函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API uint32_t llama_n_ctx      (const struct llama_context * ctx);
    // 函数: llama_n_ctx_seq
    // 描述: llama_n_ctx_seq函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx_seq
    // 描述: llama_n_ctx_seq函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx_seq
    // 描述: llama_n_ctx_seq函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx_seq
    // 描述: llama_n_ctx_seq函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx_seq
    // 描述: llama_n_ctx_seq函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ctx_seq
    // 描述: llama_n_ctx_seq函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API uint32_t llama_n_ctx_seq  (const struct llama_context * ctx);
    // 函数: llama_n_batch
    // 描述: llama_n_batch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_batch
    // 描述: llama_n_batch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_batch
    // 描述: llama_n_batch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_batch
    // 描述: llama_n_batch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_batch
    // 描述: llama_n_batch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_batch
    // 描述: llama_n_batch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API uint32_t llama_n_batch    (const struct llama_context * ctx);
    // 函数: llama_n_ubatch
    // 描述: llama_n_ubatch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ubatch
    // 描述: llama_n_ubatch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ubatch
    // 描述: llama_n_ubatch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ubatch
    // 描述: llama_n_ubatch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ubatch
    // 描述: llama_n_ubatch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_ubatch
    // 描述: llama_n_ubatch函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API uint32_t llama_n_ubatch   (const struct llama_context * ctx);
    // 函数: llama_n_seq_max
    // 描述: llama_n_seq_max函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_seq_max
    // 描述: llama_n_seq_max函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_seq_max
    // 描述: llama_n_seq_max函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_seq_max
    // 描述: llama_n_seq_max函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_seq_max
    // 描述: llama_n_seq_max函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_seq_max
    // 描述: llama_n_seq_max函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API uint32_t llama_n_seq_max  (const struct llama_context * ctx);

    DEPRECATED(LLAMA_API int32_t llama_n_ctx_train(const struct llama_model * model), "use llama_model_n_ctx_train instead");
    DEPRECATED(LLAMA_API int32_t llama_n_embd     (const struct llama_model * model), "use llama_model_n_embd instead");
    DEPRECATED(LLAMA_API int32_t llama_n_layer    (const struct llama_model * model), "use llama_model_n_layer instead");
    DEPRECATED(LLAMA_API int32_t llama_n_head     (const struct llama_model * model), "use llama_model_n_head instead");

    DEPRECATED(LLAMA_API int32_t llama_n_vocab    (const struct llama_vocab * vocab), "use llama_vocab_n_tokens instead");

    LLAMA_API const struct llama_model * llama_get_model   (const struct llama_context * ctx);
    // 函数: llama_memory_t
    // 描述: llama_memory_t函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: llama_memory_t类型返回值

    // 函数: llama_memory_t
    // 描述: llama_memory_t函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: llama_memory_t类型返回值

    // 函数: llama_memory_t
    // 描述: llama_memory_t函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: llama_memory_t类型返回值

    // 函数: llama_memory_t
    // 描述: llama_memory_t函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: llama_memory_t类型返回值

    // 函数: llama_memory_t
    // 描述: llama_memory_t函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: llama_memory_t类型返回值

    // 函数: llama_memory_t
    // 描述: llama_memory_t函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: llama_memory_t类型返回值

    LLAMA_API           llama_memory_t   llama_get_memory  (const struct llama_context * ctx);
    LLAMA_API  enum llama_pooling_type   llama_pooling_type(const struct llama_context * ctx); // TODO: rename to llama_get_pooling_type

    LLAMA_API const struct llama_vocab * llama_model_get_vocab(const struct llama_model * model);
    LLAMA_API enum llama_rope_type       llama_model_rope_type(const struct llama_model * model);

    // 函数: llama_model_n_ctx_train
    // 描述: llama_model_n_ctx_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_ctx_train
    // 描述: llama_model_n_ctx_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_ctx_train
    // 描述: llama_model_n_ctx_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_ctx_train
    // 描述: llama_model_n_ctx_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_ctx_train
    // 描述: llama_model_n_ctx_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_ctx_train
    // 描述: llama_model_n_ctx_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_ctx_train(const struct llama_model * model);
    // 函数: llama_model_n_embd
    // 描述: llama_model_n_embd函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd
    // 描述: llama_model_n_embd函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd
    // 描述: llama_model_n_embd函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd
    // 描述: llama_model_n_embd函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd
    // 描述: llama_model_n_embd函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd
    // 描述: llama_model_n_embd函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_embd     (const struct llama_model * model);
    // 函数: llama_model_n_embd_inp
    // 描述: llama_model_n_embd_inp函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_inp
    // 描述: llama_model_n_embd_inp函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_inp
    // 描述: llama_model_n_embd_inp函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_inp
    // 描述: llama_model_n_embd_inp函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_inp
    // 描述: llama_model_n_embd_inp函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_inp
    // 描述: llama_model_n_embd_inp函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_embd_inp (const struct llama_model * model);
    // 函数: llama_model_n_embd_out
    // 描述: llama_model_n_embd_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_out
    // 描述: llama_model_n_embd_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_out
    // 描述: llama_model_n_embd_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_out
    // 描述: llama_model_n_embd_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_out
    // 描述: llama_model_n_embd_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_embd_out
    // 描述: llama_model_n_embd_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_embd_out (const struct llama_model * model);
    // 函数: llama_model_n_layer
    // 描述: llama_model_n_layer函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_layer
    // 描述: llama_model_n_layer函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_layer
    // 描述: llama_model_n_layer函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_layer
    // 描述: llama_model_n_layer函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_layer
    // 描述: llama_model_n_layer函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_layer
    // 描述: llama_model_n_layer函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_layer    (const struct llama_model * model);
    // 函数: llama_model_n_head
    // 描述: llama_model_n_head函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head
    // 描述: llama_model_n_head函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head
    // 描述: llama_model_n_head函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head
    // 描述: llama_model_n_head函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head
    // 描述: llama_model_n_head函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head
    // 描述: llama_model_n_head函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_head     (const struct llama_model * model);
    // 函数: llama_model_n_head_kv
    // 描述: llama_model_n_head_kv函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head_kv
    // 描述: llama_model_n_head_kv函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head_kv
    // 描述: llama_model_n_head_kv函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head_kv
    // 描述: llama_model_n_head_kv函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head_kv
    // 描述: llama_model_n_head_kv函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_head_kv
    // 描述: llama_model_n_head_kv函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_head_kv  (const struct llama_model * model);
    // 函数: llama_model_n_swa
    // 描述: llama_model_n_swa函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_swa
    // 描述: llama_model_n_swa函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_swa
    // 描述: llama_model_n_swa函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_swa
    // 描述: llama_model_n_swa函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_swa
    // 描述: llama_model_n_swa函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_swa
    // 描述: llama_model_n_swa函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_n_swa      (const struct llama_model * model);

    // Get the model's RoPE frequency scaling factor
    // 函数: llama_model_rope_freq_scale_train
    // 描述: llama_model_rope_freq_scale_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_rope_freq_scale_train
    // 描述: llama_model_rope_freq_scale_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_rope_freq_scale_train
    // 描述: llama_model_rope_freq_scale_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_rope_freq_scale_train
    // 描述: llama_model_rope_freq_scale_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_rope_freq_scale_train
    // 描述: llama_model_rope_freq_scale_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_rope_freq_scale_train
    // 描述: llama_model_rope_freq_scale_train函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API float llama_model_rope_freq_scale_train(const struct llama_model * model);

    // Returns the number of classifier outputs (only valid for classifier models)
    // Undefined behavior for non-classifier models
    // 函数: llama_model_n_cls_out
    // 描述: llama_model_n_cls_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_cls_out
    // 描述: llama_model_n_cls_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_cls_out
    // 描述: llama_model_n_cls_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_cls_out
    // 描述: llama_model_n_cls_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_cls_out
    // 描述: llama_model_n_cls_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_cls_out
    // 描述: llama_model_n_cls_out函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API uint32_t llama_model_n_cls_out(const struct llama_model * model);

    // Returns label of classifier output by index (<n_cls_out). Returns nullptr if no label provided
    LLAMA_API const char * llama_model_cls_label(const struct llama_model * model, uint32_t i);

    LLAMA_API enum llama_vocab_type llama_vocab_type(const struct llama_vocab * vocab);

    // 函数: llama_vocab_n_tokens
    // 描述: llama_vocab_n_tokens函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_n_tokens
    // 描述: llama_vocab_n_tokens函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_n_tokens
    // 描述: llama_vocab_n_tokens函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_n_tokens
    // 描述: llama_vocab_n_tokens函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_n_tokens
    // 描述: llama_vocab_n_tokens函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_n_tokens
    // 描述: llama_vocab_n_tokens函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API int32_t llama_vocab_n_tokens(const struct llama_vocab * vocab);

    // Functions to access the model's GGUF metadata scalar values
    // - The functions return the length of the string on success, or -1 on failure
    // - The output string is always null-terminated and cleared on failure
    // - When retrieving a string, an extra byte must be allocated to account for the null terminator
    // - GGUF array values are not supported by these functions

    // Get metadata value as a string by key name
    // 函数: llama_model_meta_val_str
    // 描述: llama_model_meta_val_str函数提供相关功能
    // 参数: const struct llama_model * model, const char * key, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str
    // 描述: llama_model_meta_val_str函数提供相关功能
    // 参数: const struct llama_model * model, const char * key, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str
    // 描述: llama_model_meta_val_str函数提供相关功能
    // 参数: const struct llama_model * model, const char * key, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str
    // 描述: llama_model_meta_val_str函数提供相关功能
    // 参数: const struct llama_model * model, const char * key, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str
    // 描述: llama_model_meta_val_str函数提供相关功能
    // 参数: const struct llama_model * model, const char * key, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str
    // 描述: llama_model_meta_val_str函数提供相关功能
    // 参数: const struct llama_model * model, const char * key, char * buf, size_t buf_size
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_meta_val_str(const struct llama_model * model, const char * key, char * buf, size_t buf_size);

    // Get the number of metadata key/value pairs
    // 函数: llama_model_meta_count
    // 描述: llama_model_meta_count函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_meta_count
    // 描述: llama_model_meta_count函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_meta_count
    // 描述: llama_model_meta_count函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_meta_count
    // 描述: llama_model_meta_count函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_meta_count
    // 描述: llama_model_meta_count函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_meta_count
    // 描述: llama_model_meta_count函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_meta_count(const struct llama_model * model);

    // Get sampling metadata key name. Returns nullptr if the key is invalid
    LLAMA_API const char * llama_model_meta_key_str(enum llama_model_meta_key key);

    // Get metadata key name by index
    // 函数: llama_model_meta_key_by_index
    // 描述: llama_model_meta_key_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_key_by_index
    // 描述: llama_model_meta_key_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_key_by_index
    // 描述: llama_model_meta_key_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_key_by_index
    // 描述: llama_model_meta_key_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_key_by_index
    // 描述: llama_model_meta_key_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_key_by_index
    // 描述: llama_model_meta_key_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_meta_key_by_index(const struct llama_model * model, int32_t i, char * buf, size_t buf_size);

    // Get metadata value as a string by index
    // 函数: llama_model_meta_val_str_by_index
    // 描述: llama_model_meta_val_str_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str_by_index
    // 描述: llama_model_meta_val_str_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str_by_index
    // 描述: llama_model_meta_val_str_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str_by_index
    // 描述: llama_model_meta_val_str_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str_by_index
    // 描述: llama_model_meta_val_str_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_meta_val_str_by_index
    // 描述: llama_model_meta_val_str_by_index函数提供相关功能
    // 参数: const struct llama_model * model, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_meta_val_str_by_index(const struct llama_model * model, int32_t i, char * buf, size_t buf_size);

    // Get a string describing the model type
    // 函数: llama_model_desc
    // 描述: llama_model_desc函数提供相关功能
    // 参数: const struct llama_model * model, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_desc
    // 描述: llama_model_desc函数提供相关功能
    // 参数: const struct llama_model * model, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_desc
    // 描述: llama_model_desc函数提供相关功能
    // 参数: const struct llama_model * model, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_desc
    // 描述: llama_model_desc函数提供相关功能
    // 参数: const struct llama_model * model, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_desc
    // 描述: llama_model_desc函数提供相关功能
    // 参数: const struct llama_model * model, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_desc
    // 描述: llama_model_desc函数提供相关功能
    // 参数: const struct llama_model * model, char * buf, size_t buf_size
    // 返回: 无返回值

    LLAMA_API int32_t llama_model_desc(const struct llama_model * model, char * buf, size_t buf_size);

    // Returns the total size of all the tensors in the model in bytes
    // 函数: llama_model_size
    // 描述: llama_model_size函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_size
    // 描述: llama_model_size函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_size
    // 描述: llama_model_size函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_size
    // 描述: llama_model_size函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_size
    // 描述: llama_model_size函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_size
    // 描述: llama_model_size函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API uint64_t llama_model_size(const struct llama_model * model);

    // Get the default chat template. Returns nullptr if not available
    // If name is NULL, returns the default chat template
    LLAMA_API const char * llama_model_chat_template(const struct llama_model * model, const char * name);

    // Returns the total number of parameters in the model
    // 函数: llama_model_n_params
    // 描述: llama_model_n_params函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_params
    // 描述: llama_model_n_params函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_params
    // 描述: llama_model_n_params函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_params
    // 描述: llama_model_n_params函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_params
    // 描述: llama_model_n_params函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_n_params
    // 描述: llama_model_n_params函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API uint64_t llama_model_n_params(const struct llama_model * model);

    // Returns true if the model contains an encoder that requires llama_encode() call
    // 函数: llama_model_has_encoder
    // 描述: llama_model_has_encoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_encoder
    // 描述: llama_model_has_encoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_encoder
    // 描述: llama_model_has_encoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_encoder
    // 描述: llama_model_has_encoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_encoder
    // 描述: llama_model_has_encoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_encoder
    // 描述: llama_model_has_encoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API bool llama_model_has_encoder(const struct llama_model * model);

    // Returns true if the model contains a decoder that requires llama_decode() call
    // 函数: llama_model_has_decoder
    // 描述: llama_model_has_decoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_decoder
    // 描述: llama_model_has_decoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_decoder
    // 描述: llama_model_has_decoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_decoder
    // 描述: llama_model_has_decoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_decoder
    // 描述: llama_model_has_decoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_has_decoder
    // 描述: llama_model_has_decoder函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API bool llama_model_has_decoder(const struct llama_model * model);

    // For encoder-decoder models, this function returns id of the token that must be provided
    // to the decoder to start generating output sequence. For other models, it returns -1.
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API llama_token llama_model_decoder_start_token(const struct llama_model * model);

    // Returns true if the model is recurrent (like Mamba, RWKV, etc.)
    // 函数: llama_model_is_recurrent
    // 描述: llama_model_is_recurrent函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_recurrent
    // 描述: llama_model_is_recurrent函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_recurrent
    // 描述: llama_model_is_recurrent函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_recurrent
    // 描述: llama_model_is_recurrent函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_recurrent
    // 描述: llama_model_is_recurrent函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_recurrent
    // 描述: llama_model_is_recurrent函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API bool llama_model_is_recurrent(const struct llama_model * model);

    // Returns true if the model is hybrid (like Jamba, Granite, etc.)
    // 函数: llama_model_is_hybrid
    // 描述: llama_model_is_hybrid函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_hybrid
    // 描述: llama_model_is_hybrid函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_hybrid
    // 描述: llama_model_is_hybrid函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_hybrid
    // 描述: llama_model_is_hybrid函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_hybrid
    // 描述: llama_model_is_hybrid函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_hybrid
    // 描述: llama_model_is_hybrid函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API bool llama_model_is_hybrid(const struct llama_model * model);

    // Returns true if the model is diffusion-based (like LLaDA, Dream, etc.)
    // 函数: llama_model_is_diffusion
    // 描述: llama_model_is_diffusion函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_diffusion
    // 描述: llama_model_is_diffusion函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_diffusion
    // 描述: llama_model_is_diffusion函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_diffusion
    // 描述: llama_model_is_diffusion函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_diffusion
    // 描述: llama_model_is_diffusion函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    // 函数: llama_model_is_diffusion
    // 描述: llama_model_is_diffusion函数提供相关功能
    // 参数: const struct llama_model * model
    // 返回: 无返回值

    LLAMA_API bool llama_model_is_diffusion(const struct llama_model * model);

    // Returns 0 on success
    // 函数: llama_model_quantize
    // 描述: llama_model_quantize函数提供相关功能
    // 参数: const char * fname_inp, const char * fname_out, const llama_model_quantize_params * params
    // 返回: 无返回值

    // 函数: llama_model_quantize
    // 描述: llama_model_quantize函数提供相关功能
    // 参数: // // Adapters //  // Load a LoRA adapter from file // The adapter is valid as long as the associated model is not freed // All adapters must be loaded before context creation LLAMA_API struct llama_adapter_lora * llama_adapter_lora_init( // 类: llama_model // 描述: llama_model类提供相关功能 // 用途: 用于处理llama_model相关的操作 // 类: llama_model // 描述: llama_model类提供相关功能 // 用途: 用于处理llama_model相关的操作 // 结构体: llama_model // 描述: llama_model结构体提供相关功能 // 用途: 用于处理llama_model相关的操作 struct llama_model * model, const char * path_lora
    // 返回: llama_adapter_lora *类型返回值

    // 函数: llama_model_quantize
    // 描述: llama_model_quantize函数提供相关功能
    // 参数: // Functions to access the adapter's GGUF metadata scalar values // - The functions return the length of the string on success, or -1 on failure // - The output string is always null-terminated and cleared on failure // - When retrieving a string, an extra byte must be allocated to account for the null terminator // - GGUF array values are not supported by these functions  // Get metadata value as a string by key name // 函数: llama_adapter_meta_val_str // 描述: llama_adapter_meta_val_str函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, const char * key, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_val_str // 描述: llama_adapter_meta_val_str函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, const char * key, char * buf, size_t buf_size // 返回: 无返回值  LLAMA_API int32_t llama_adapter_meta_val_str(const struct llama_adapter_lora * adapter, const char * key, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_quantize
    // 描述: llama_model_quantize函数提供相关功能
    // 参数: // Get the number of metadata key/value pairs // 函数: llama_adapter_meta_count // 描述: llama_adapter_meta_count函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter // 返回: 无返回值  // 函数: llama_adapter_meta_count // 描述: llama_adapter_meta_count函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter // 返回: 无返回值  // 函数: llama_adapter_meta_count // 描述: llama_adapter_meta_count函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter // 返回: 无返回值  LLAMA_API int32_t llama_adapter_meta_count(const struct llama_adapter_lora * adapter
    // 返回: 无返回值

    // 函数: llama_model_quantize
    // 描述: llama_model_quantize函数提供相关功能
    // 参数: // Get metadata key name by index // 函数: llama_adapter_meta_key_by_index // 描述: llama_adapter_meta_key_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_key_by_index // 描述: llama_adapter_meta_key_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_key_by_index // 描述: llama_adapter_meta_key_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_key_by_index // 描述: llama_adapter_meta_key_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  LLAMA_API int32_t llama_adapter_meta_key_by_index(const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    // 函数: llama_model_quantize
    // 描述: llama_model_quantize函数提供相关功能
    // 参数: // Get metadata value as a string by index // 函数: llama_adapter_meta_val_str_by_index // 描述: llama_adapter_meta_val_str_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_val_str_by_index // 描述: llama_adapter_meta_val_str_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_val_str_by_index // 描述: llama_adapter_meta_val_str_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_val_str_by_index // 描述: llama_adapter_meta_val_str_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  // 函数: llama_adapter_meta_val_str_by_index // 描述: llama_adapter_meta_val_str_by_index函数提供相关功能 // 参数: const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size // 返回: 无返回值  LLAMA_API int32_t llama_adapter_meta_val_str_by_index(const struct llama_adapter_lora * adapter, int32_t i, char * buf, size_t buf_size
    // 返回: 无返回值

    LLAMA_API uint32_t llama_model_quantize(

    // Manually free a LoRA adapter
    // NOTE: loaded adapters will be free when the associated model is deleted
    // 函数: DEPRECATED
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: DEPRECATED
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    LLAMA_API DEPRECATED(void llama_adapter_lora_free(struct llama_adapter_lora * adapter),
            "adapters are now freed together with the associated model");

    // Get the invocation tokens if the current lora is an alora
    // 函数: llama_adapter_get_alora_n_invocation_tokens
    // 描述: llama_adapter_get_alora_n_invocation_tokens函数提供相关功能
    // 参数: const struct llama_adapter_lora * adapter
    // 返回: uint64_t类型返回值

    // 函数: llama_adapter_get_alora_n_invocation_tokens
    // 描述: llama_adapter_get_alora_n_invocation_tokens函数提供相关功能
    // 参数: const struct llama_adapter_lora * adapter
    // 返回: uint64_t类型返回值

    // 函数: llama_adapter_get_alora_n_invocation_tokens
    // 描述: llama_adapter_get_alora_n_invocation_tokens函数提供相关功能
    // 参数: const struct llama_adapter_lora * adapter
    // 返回: uint64_t类型返回值

    // 函数: llama_adapter_get_alora_n_invocation_tokens
    // 描述: llama_adapter_get_alora_n_invocation_tokens函数提供相关功能
    // 参数: const struct llama_adapter_lora * adapter
    // 返回: uint64_t类型返回值

    // 函数: llama_adapter_get_alora_n_invocation_tokens
    // 描述: llama_adapter_get_alora_n_invocation_tokens函数提供相关功能
    // 参数: const struct llama_adapter_lora * adapter
    // 返回: uint64_t类型返回值

    // 函数: llama_adapter_get_alora_n_invocation_tokens
    // 描述: llama_adapter_get_alora_n_invocation_tokens函数提供相关功能
    // 参数: const struct llama_adapter_lora * adapter
    // 返回: uint64_t类型返回值

    LLAMA_API uint64_t            llama_adapter_get_alora_n_invocation_tokens(const struct llama_adapter_lora * adapter);
    LLAMA_API const llama_token * llama_adapter_get_alora_invocation_tokens  (const struct llama_adapter_lora * adapter);

    // The following functions operate on a llama_context, hence the naming: llama_verb_...

    // Set LoRa adapters on the context. Will only modify if the adapters currently in context are different.
    // 函数: llama_set_adapters_lora
    // 描述: llama_set_adapters_lora函数提供相关功能
    // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, // 类: llama_adapter_lora // 描述: llama_adapter_lora类提供相关功能 // 用途: 用于处理llama_adapter_lora相关的操作 // 类: llama_adapter_lora // 描述: llama_adapter_lora类提供相关功能 // 用途: 用于处理llama_adapter_lora相关的操作 struct llama_adapter_lora ** adapters, size_t n_adapters, float * scales
    // 返回: 无返回值

    // 函数: llama_set_adapters_lora
    // 描述: llama_set_adapters_lora函数提供相关功能
    // 参数: // Apply a loaded control vector to a llama_context, or if data is NULL, clear // the currently loaded vector. // n_embd should be the size of a single layer's control, and data should point // to an n_embd x n_layers buffer starting from layer 1. // il_start and il_end are the layer range the vector should apply to (both inclusive
    // 返回: 无返回值

    // 函数: llama_set_adapters_lora
    // 描述: llama_set_adapters_lora函数提供相关功能
    // 参数: // See llama_control_vector_load in common to load a control vector. // 函数: llama_set_adapter_cvec // 描述: llama_set_adapter_cvec函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const float * data, size_t   len, int32_t   n_embd, int32_t   il_start, int32_t   il_end // 返回: 无返回值  // 函数: llama_set_adapter_cvec // 描述: llama_set_adapter_cvec函数提供相关功能 // 参数: // // Memory //  // Clear the memory contents // If data == true, the data buffers will also be cleared together with the metadata // 函数: llama_memory_clear // 描述: llama_memory_clear函数提供相关功能 // 参数: llama_memory_t mem, bool data // 返回: 无返回值  LLAMA_API void llama_memory_clear(  // Removes all tokens that belong to the specified sequence and have positions in [p0, p1 // 返回: 无返回值  LLAMA_API int32_t llama_set_adapter_cvec( // Returns false if a partial sequence cannot be removed. Removing a whole sequence never fails // seq_id < 0 : match any sequence // p0 < 0     : [0,  p1] // p1 < 0     : [p0, inf
    // 返回: 无返回值

    // 函数: llama_set_adapters_lora
    // 描述: llama_set_adapters_lora函数提供相关功能
    // 参数: // 函数: llama_memory_seq_rm // 描述: llama_memory_seq_rm函数提供相关功能 // 参数: llama_memory_t mem, llama_seq_id seq_id, llama_pos p0, llama_pos p1 // 返回: 无返回值  // 函数: llama_memory_seq_rm // 描述: llama_memory_seq_rm函数提供相关功能 // 参数: // Copy all tokens that belong to the specified sequence to another sequence // p0 < 0 : [0,  p1] // p1 < 0 : [p0, inf // 返回: 无返回值  // 函数: llama_memory_seq_rm // 描述: llama_memory_seq_rm函数提供相关功能 // 参数: // 函数: llama_memory_seq_cp // 描述: llama_memory_seq_cp函数提供相关功能 // 参数: llama_memory_t mem, llama_seq_id seq_id_src, llama_seq_id seq_id_dst, llama_pos p0, llama_pos p1 // 返回: 无返回值  // 函数: llama_memory_seq_cp // 描述: llama_memory_seq_cp函数提供相关功能 // 参数: // Removes all tokens that do not belong to the specified sequence // 函数: llama_memory_seq_keep // 描述: llama_memory_seq_keep函数提供相关功能 // 参数: llama_memory_t mem, llama_seq_id seq_id // 返回: 无返回值  LLAMA_API void llama_memory_seq_keep(  // Adds relative position "delta" to all tokens that belong to the specified sequence and have positions in [p0, p1 // 返回: 无返回值  LLAMA_API void llama_memory_seq_cp( // p0 < 0 : [0,  p1] // p1 < 0 : [p0, inf // 返回: 无返回值  LLAMA_API bool llama_memory_seq_rm( // 函数: llama_memory_seq_add // 描述: llama_memory_seq_add函数提供相关功能 // 参数: llama_memory_t mem, llama_seq_id seq_id, llama_pos p0, llama_pos p1, llama_pos delta // 返回: 无返回值  // 函数: llama_memory_seq_add // 描述: llama_memory_seq_add函数提供相关功能 // 参数: // Integer division of the positions by factor of `d > 1` // p0 < 0 : [0,  p1] // p1 < 0 : [p0, inf // 返回: 无返回值  // 函数: llama_memory_seq_add // 描述: llama_memory_seq_add函数提供相关功能 // 参数: // 函数: llama_memory_seq_div // 描述: llama_memory_seq_div函数提供相关功能 // 参数: llama_memory_t mem, llama_seq_id seq_id, llama_pos p0, llama_pos p1, int d // 返回: 无返回值  // 函数: llama_memory_seq_div // 描述: llama_memory_seq_div函数提供相关功能 // 参数: // Returns the smallest position present in the memory for the specified sequence // This is typically non-zero only for SWA caches // Note that all positions in the range [pos_min, pos_max] are guaranteed to be present in the memory // Return -1 if the sequence is empty // 函数: llama_pos // 描述: llama_pos函数提供相关功能 // 参数: llama_memory_t mem, llama_seq_id seq_id // 返回: 无返回值  LLAMA_API llama_pos llama_memory_seq_pos_min(  // Returns the largest position present in the memory for the specified sequence // Note that all positions in the range [pos_min, pos_max] are guaranteed to be present in the memory // Return -1 if the sequence is empty // 函数: llama_pos // 描述: llama_pos函数提供相关功能 // 参数: llama_memory_t mem, llama_seq_id seq_id // 返回: 无返回值  LLAMA_API llama_pos llama_memory_seq_pos_max(  // Check if the memory supports shifting // 函数: llama_memory_can_shift // 描述: llama_memory_can_shift函数提供相关功能 // 参数: llama_memory_t mem // 返回: 无返回值  LLAMA_API bool llama_memory_can_shift(llama_memory_t mem // 返回: 无返回值  LLAMA_API void llama_memory_seq_div(  // // State / sessions //  // Returns the *actual* size in bytes of the state // (logits, embedding and memory // 返回: 无返回值  LLAMA_API void llama_memory_seq_add( // Only use when saving the state, not when restoring it, otherwise the size may be too small. // 函数: llama_state_get_size // 描述: llama_state_get_size函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  // 函数: llama_state_get_size // 描述: llama_state_get_size函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  // 函数: llama_state_get_size // 描述: llama_state_get_size函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  LLAMA_API size_t llama_state_get_size(struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_set_adapters_lora
    // 描述: llama_set_adapters_lora函数提供相关功能
    // 参数: // 函数: DEPRECATED // 描述: 执行主要功能 // 参数: 无参数 // 返回: 无返回值 // 函数: DEPRECATED // 描述: 执行主要功能 // 参数: 无参数 // 返回: 无返回值 LLAMA_API DEPRECATED(size_t llama_get_state_size(struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_set_adapters_lora
    // 描述: llama_set_adapters_lora函数提供相关功能
    // 参数: "use llama_state_get_size instead"
    // 返回: 无返回值

    LLAMA_API int32_t llama_set_adapters_lora(

    // Copies the state to the specified destination address.
    // Destination needs to have allocated enough memory.
    // Returns the number of bytes copied
    // 函数: llama_state_get_data
    // 描述: llama_state_get_data函数提供相关功能
    // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, uint8_t * dst, size_t   size
    // 返回: 无返回值

    // 函数: llama_state_get_data
    // 描述: llama_state_get_data函数提供相关功能
    // 参数: LLAMA_API DEPRECATED(size_t llama_copy_state_data( // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 结构体: llama_context // 描述: llama_context结构体提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, uint8_t * dst
    // 返回: 无返回值

    // 函数: llama_state_get_data
    // 描述: llama_state_get_data函数提供相关功能
    // 参数: "use llama_state_get_data instead"
    // 返回: 无返回值

    // 函数: llama_state_get_data
    // 描述: llama_state_get_data函数提供相关功能
    // 参数: // Set the state reading from the specified address // Returns the number of bytes read // 函数: llama_state_set_data // 描述: llama_state_set_data函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const uint8_t * src, size_t   size // 返回: 无返回值  // 函数: llama_state_set_data // 描述: llama_state_set_data函数提供相关功能 // 参数: LLAMA_API DEPRECATED(size_t llama_set_state_data( // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 结构体: llama_context // 描述: llama_context结构体提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const uint8_t * src // 返回: 无返回值  // 函数: llama_state_set_data // 描述: llama_state_set_data函数提供相关功能 // 参数: "use llama_state_set_data instead" // 返回: 无返回值  LLAMA_API size_t llama_state_set_data(  // Save/load session file // 函数: llama_state_load_file // 描述: llama_state_load_file函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const char * path_session, llama_token * tokens_out, size_t   n_token_capacity, size_t * n_token_count_out // 返回: 无返回值  // 函数: llama_state_load_file // 描述: llama_state_load_file函数提供相关功能 // 参数: LLAMA_API DEPRECATED(bool llama_load_session_file( // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 结构体: llama_context // 描述: llama_context结构体提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const char * path_session, llama_token * tokens_out, size_t   n_token_capacity, size_t * n_token_count_out // 返回: 无返回值  // 函数: llama_state_load_file // 描述: llama_state_load_file函数提供相关功能 // 参数: "use llama_state_load_file instead" // 返回: 无返回值  LLAMA_API bool llama_state_load_file(  // 函数: llama_state_save_file // 描述: llama_state_save_file函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const char * path_session, const llama_token * tokens, size_t   n_token_count // 返回: 无返回值  // 函数: llama_state_save_file // 描述: llama_state_save_file函数提供相关功能 // 参数: LLAMA_API DEPRECATED(bool llama_save_session_file( // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 结构体: llama_context // 描述: llama_context结构体提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const char * path_session, const llama_token * tokens, size_t   n_token_count // 返回: 无返回值  // 函数: llama_state_save_file // 描述: llama_state_save_file函数提供相关功能 // 参数: "use llama_state_save_file instead" // 返回: 无返回值  LLAMA_API bool llama_state_save_file(  // Get the exact size needed to copy the state of a single sequence // 函数: llama_state_seq_get_size // 描述: llama_state_seq_get_size函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, llama_seq_id   seq_id // 返回: 无返回值  // 函数: llama_state_seq_get_size // 描述: llama_state_seq_get_size函数提供相关功能 // 参数: // Copy the state of a single sequence into the specified buffer // 函数: llama_state_seq_get_data // 描述: llama_state_seq_get_data函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, uint8_t * dst, size_t   size, llama_seq_id   seq_id // 返回: 无返回值  LLAMA_API size_t llama_state_seq_get_data(  // Copy the sequence data (originally copied with `llama_state_seq_get_data` // 返回: 无返回值  // 函数: llama_state_seq_get_size // 描述: llama_state_seq_get_size函数提供相关功能 // 参数: // Returns: //  - Positive: Ok //  - Zero: Failed to load // 函数: llama_state_seq_set_data // 描述: llama_state_seq_set_data函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const uint8_t * src, size_t   size, llama_seq_id   dest_seq_id // 返回: 无返回值  // 函数: llama_state_seq_set_data // 描述: llama_state_seq_set_data函数提供相关功能 // 参数: // 函数: llama_state_seq_save_file // 描述: llama_state_seq_save_file函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const char * filepath, llama_seq_id   seq_id, const llama_token * tokens, size_t   n_token_count // 返回: 无返回值  LLAMA_API size_t llama_state_seq_save_file(  // 函数: llama_state_seq_load_file // 描述: llama_state_seq_load_file函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const char * filepath, llama_seq_id   dest_seq_id, llama_token * tokens_out, size_t   n_token_capacity, size_t * n_token_count_out // 返回: 无返回值  LLAMA_API size_t llama_state_seq_load_file(  // for backwards-compat #define LLAMA_STATE_SEQ_FLAGS_SWA_ONLY 1  // work only with partial states, such as SWA KV cache or recurrent cache (e.g. Mamba // 返回: 无返回值  LLAMA_API size_t llama_state_seq_set_data( #define LLAMA_STATE_SEQ_FLAGS_PARTIAL_ONLY 1  typedef uint32_t llama_state_seq_flags;  // 函数: llama_state_seq_get_size_ext // 描述: llama_state_seq_get_size_ext函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, llama_seq_id   seq_id, llama_state_seq_flags   flags // 返回: 无返回值  // 函数: llama_state_seq_get_size_ext // 描述: llama_state_seq_get_size_ext函数提供相关功能 // 参数: // 函数: llama_state_seq_get_data_ext // 描述: llama_state_seq_get_data_ext函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, uint8_t * dst, size_t   size, llama_seq_id   seq_id, llama_state_seq_flags   flags // 返回: 无返回值  LLAMA_API size_t llama_state_seq_get_data_ext(  // 函数: llama_state_seq_set_data_ext // 描述: llama_state_seq_set_data_ext函数提供相关功能 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, const uint8_t * src, size_t   size, llama_seq_id   dest_seq_id, llama_state_seq_flags   flags // 返回: 无返回值  LLAMA_API size_t llama_state_seq_set_data_ext(  // // Decoding //  // Return batch for single sequence of tokens // The sequence ID will be fixed to 0 // The position of the tokens will be tracked automatically by llama_decode // // NOTE: this is a helper function to facilitate transition to the new batch API - avoid using it // LLAMA_API struct llama_batch llama_batch_get_one( llama_token * tokens, int32_t   n_tokens // 返回: 无返回值  LLAMA_API size_t llama_state_seq_get_size_ext(  // Allocates a batch of tokens on the heap that can hold a maximum of n_tokens // Each token can be assigned up to n_seq_max sequence ids // The batch has to be freed with llama_batch_free( // 返回: 无返回值  LLAMA_API size_t llama_state_seq_get_size( // If embd != 0, llama_batch.embd will be allocated with size of n_tokens * embd * sizeof(float
    // 返回: embd *类型返回值

    // 函数: llama_state_get_data
    // 描述: llama_state_get_data函数提供相关功能
    // 参数: // Otherwise, llama_batch.token will be allocated to store n_tokens llama_token // The rest of the llama_batch members are allocated with size n_tokens // All members are left uninitialized LLAMA_API struct llama_batch llama_batch_init( int32_t n_tokens, int32_t embd, int32_t n_seq_max
    // 返回: 无返回值

    // 函数: llama_state_get_data
    // 描述: llama_state_get_data函数提供相关功能
    // 参数: // Frees a batch of tokens allocated with llama_batch_init(
    // 返回: 无返回值

    LLAMA_API size_t llama_state_get_data(
    // 函数: llama_batch_free
    // 描述: llama_batch_free函数提供相关功能
    // 参数: struct llama_batch batch
    // 返回: 无返回值

    // 函数: llama_batch_free
    // 描述: llama_batch_free函数提供相关功能
    // 参数: struct llama_batch batch
    // 返回: 无返回值

    // 函数: llama_batch_free
    // 描述: llama_batch_free函数提供相关功能
    // 参数: struct llama_batch batch
    // 返回: 无返回值

    // 函数: llama_batch_free
    // 描述: llama_batch_free函数提供相关功能
    // 参数: struct llama_batch batch
    // 返回: 无返回值

    // 函数: llama_batch_free
    // 描述: llama_batch_free函数提供相关功能
    // 参数: struct llama_batch batch
    // 返回: 无返回值

    // 函数: llama_batch_free
    // 描述: llama_batch_free函数提供相关功能
    // 参数: struct llama_batch batch
    // 返回: 无返回值

    LLAMA_API void llama_batch_free(struct llama_batch batch);

    // Process a batch of tokens.
    // In contrast to llama_decode() - this call does not use KV cache.
    // For encode-decoder contexts, processes the batch using the encoder.
    // Can store the encoder output internally for later use by the decoder's cross-attention layers.
    //   0 - success
    // < 0 - error. the memory state is restored to the state before this call
    // 函数: llama_encode
    // 描述: 编码器函数，处理批次令牌而不使用KV缓存
    // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, // 类: llama_batch // 描述: llama_batch类提供相关功能 // 用途: 用于处理llama_batch相关的操作 // 类: llama_batch // 描述: llama_batch类提供相关功能 // 用途: 用于处理llama_batch相关的操作 struct llama_batch   batch
    // 返回: 无返回值

    // 函数: llama_encode
    // 描述: 编码器函数，处理批次令牌而不使用KV缓存
    // 参数: // Process a batch of tokens. // Requires the context to have a memory. // For encode-decoder contexts, processes the batch using the decoder. // Positive return values does not mean a fatal error, but rather a warning. // Upon fatal-error or abort, the ubatches that managed to be been processed will remain in the memory state of the context //   To handle this correctly, query the memory state using llama_memory_seq_pos_min() and llama_memory_seq_pos_max(
    // 返回: 无返回值

    // 函数: llama_encode
    // 描述: 编码器函数，处理批次令牌而不使用KV缓存
    // 参数: // Upon other return values, the memory state is restored to the state before this call //    0 - success //    1 - could not find a KV slot for the batch (try reducing the size of the batch or increase the context
    // 返回: 无返回值

    // 函数: llama_encode
    // 描述: 编码器函数，处理批次令牌而不使用KV缓存
    // 参数: //    2 - aborted     (processed ubatches will remain in the context's memory
    // 返回: 无返回值

    // 函数: llama_encode
    // 描述: 编码器函数，处理批次令牌而不使用KV缓存
    // 参数: //   -1 - invalid input batch // < -1 - fatal error (processed ubatches will remain in the context's memory
    // 返回: 无返回值

    // 函数: llama_encode
    // 描述: 编码器函数，处理批次令牌而不使用KV缓存
    // 参数: // 函数: llama_decode // 描述: 解码器函数，处理批次令牌并使用KV缓存 // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context * ctx, // 类: llama_batch // 描述: llama_batch类提供相关功能 // 用途: 用于处理llama_batch相关的操作 // 类: llama_batch // 描述: llama_batch类提供相关功能 // 用途: 用于处理llama_batch相关的操作 struct llama_batch   batch // 返回: 无返回值  // 函数: llama_decode // 描述: 解码器函数，处理批次令牌并使用KV缓存 // 参数: // Set the number of threads used for decoding // n_threads is the number of threads used for generation (single token // 返回: 无返回值  // 函数: llama_decode // 描述: 解码器函数，处理批次令牌并使用KV缓存 // 参数: // n_threads_batch is the number of threads used for prompt and batch processing (multiple tokens // 返回: 无返回值  // 函数: llama_decode // 描述: 解码器函数，处理批次令牌并使用KV缓存 // 参数: // 函数: llama_set_n_threads // 描述: llama_set_n_threads函数提供相关功能 // 参数: struct llama_context * ctx, int32_t n_threads, int32_t n_threads_batch // 返回: 无返回值  // 函数: llama_set_n_threads // 描述: llama_set_n_threads函数提供相关功能 // 参数: struct llama_context * ctx, int32_t n_threads, int32_t n_threads_batch // 返回: 无返回值  // 函数: llama_set_n_threads // 描述: llama_set_n_threads函数提供相关功能 // 参数: struct llama_context * ctx, int32_t n_threads, int32_t n_threads_batch // 返回: 无返回值  LLAMA_API void llama_set_n_threads(struct llama_context * ctx, int32_t n_threads, int32_t n_threads_batch // 返回: 无返回值  // 函数: llama_decode // 描述: 解码器函数，处理批次令牌并使用KV缓存 // 参数: // Get the number of threads used for generation of a single token. // 函数: llama_n_threads // 描述: llama_n_threads函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  // 函数: llama_n_threads // 描述: llama_n_threads函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  // 函数: llama_n_threads // 描述: llama_n_threads函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  // 函数: llama_n_threads // 描述: llama_n_threads函数提供相关功能 // 参数: struct llama_context * ctx // 返回: 无返回值  LLAMA_API int32_t llama_n_threads(struct llama_context * ctx // 返回: 无返回值  LLAMA_API int32_t llama_decode(  // Get the number of threads used for prompt and batch processing (multiple token
    // 返回: 无返回值

    LLAMA_API int32_t llama_encode(
    // 函数: llama_n_threads_batch
    // 描述: llama_n_threads_batch函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_threads_batch
    // 描述: llama_n_threads_batch函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_threads_batch
    // 描述: llama_n_threads_batch函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_threads_batch
    // 描述: llama_n_threads_batch函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_threads_batch
    // 描述: llama_n_threads_batch函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_n_threads_batch
    // 描述: llama_n_threads_batch函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API int32_t llama_n_threads_batch(struct llama_context * ctx);

    // Set whether the context outputs embeddings or not
    // TODO: rename to avoid confusion with llama_get_embeddings()
    // 函数: llama_set_embeddings
    // 描述: llama_set_embeddings函数提供相关功能
    // 参数: struct llama_context * ctx, bool embeddings
    // 返回: 无返回值

    // 函数: llama_set_embeddings
    // 描述: llama_set_embeddings函数提供相关功能
    // 参数: struct llama_context * ctx, bool embeddings
    // 返回: 无返回值

    // 函数: llama_set_embeddings
    // 描述: llama_set_embeddings函数提供相关功能
    // 参数: struct llama_context * ctx, bool embeddings
    // 返回: 无返回值

    // 函数: llama_set_embeddings
    // 描述: llama_set_embeddings函数提供相关功能
    // 参数: struct llama_context * ctx, bool embeddings
    // 返回: 无返回值

    // 函数: llama_set_embeddings
    // 描述: llama_set_embeddings函数提供相关功能
    // 参数: struct llama_context * ctx, bool embeddings
    // 返回: 无返回值

    // 函数: llama_set_embeddings
    // 描述: llama_set_embeddings函数提供相关功能
    // 参数: struct llama_context * ctx, bool embeddings
    // 返回: 无返回值

    LLAMA_API void llama_set_embeddings(struct llama_context * ctx, bool embeddings);

    // Set whether to use causal attention or not
    // If set to true, the model will only attend to the past tokens
    // 函数: llama_set_causal_attn
    // 描述: llama_set_causal_attn函数提供相关功能
    // 参数: struct llama_context * ctx, bool causal_attn
    // 返回: 无返回值

    // 函数: llama_set_causal_attn
    // 描述: llama_set_causal_attn函数提供相关功能
    // 参数: struct llama_context * ctx, bool causal_attn
    // 返回: 无返回值

    // 函数: llama_set_causal_attn
    // 描述: llama_set_causal_attn函数提供相关功能
    // 参数: struct llama_context * ctx, bool causal_attn
    // 返回: 无返回值

    // 函数: llama_set_causal_attn
    // 描述: llama_set_causal_attn函数提供相关功能
    // 参数: struct llama_context * ctx, bool causal_attn
    // 返回: 无返回值

    // 函数: llama_set_causal_attn
    // 描述: llama_set_causal_attn函数提供相关功能
    // 参数: struct llama_context * ctx, bool causal_attn
    // 返回: 无返回值

    // 函数: llama_set_causal_attn
    // 描述: llama_set_causal_attn函数提供相关功能
    // 参数: struct llama_context * ctx, bool causal_attn
    // 返回: 无返回值

    LLAMA_API void llama_set_causal_attn(struct llama_context * ctx, bool causal_attn);

    // Set whether the model is in warmup mode or not
    // If true, all model tensors are activated during llama_decode() to load and cache their weights.
    // 函数: llama_set_warmup
    // 描述: llama_set_warmup函数提供相关功能
    // 参数: struct llama_context * ctx, bool warmup
    // 返回: 无返回值

    // 函数: llama_set_warmup
    // 描述: llama_set_warmup函数提供相关功能
    // 参数: struct llama_context * ctx, bool warmup
    // 返回: 无返回值

    // 函数: llama_set_warmup
    // 描述: llama_set_warmup函数提供相关功能
    // 参数: struct llama_context * ctx, bool warmup
    // 返回: 无返回值

    // 函数: llama_set_warmup
    // 描述: llama_set_warmup函数提供相关功能
    // 参数: struct llama_context * ctx, bool warmup
    // 返回: 无返回值

    // 函数: llama_set_warmup
    // 描述: llama_set_warmup函数提供相关功能
    // 参数: struct llama_context * ctx, bool warmup
    // 返回: 无返回值

    // 函数: llama_set_warmup
    // 描述: llama_set_warmup函数提供相关功能
    // 参数: struct llama_context * ctx, bool warmup
    // 返回: 无返回值

    LLAMA_API void llama_set_warmup(struct llama_context * ctx, bool warmup);

    // Set abort callback
    // 函数: llama_set_abort_callback
    // 描述: llama_set_abort_callback函数提供相关功能
    // 参数: struct llama_context * ctx, ggml_abort_callback abort_callback, void * abort_callback_data
    // 返回: 无返回值

    // 函数: llama_set_abort_callback
    // 描述: llama_set_abort_callback函数提供相关功能
    // 参数: struct llama_context * ctx, ggml_abort_callback abort_callback, void * abort_callback_data
    // 返回: 无返回值

    // 函数: llama_set_abort_callback
    // 描述: llama_set_abort_callback函数提供相关功能
    // 参数: struct llama_context * ctx, ggml_abort_callback abort_callback, void * abort_callback_data
    // 返回: 无返回值

    // 函数: llama_set_abort_callback
    // 描述: llama_set_abort_callback函数提供相关功能
    // 参数: struct llama_context * ctx, ggml_abort_callback abort_callback, void * abort_callback_data
    // 返回: 无返回值

    // 函数: llama_set_abort_callback
    // 描述: llama_set_abort_callback函数提供相关功能
    // 参数: struct llama_context * ctx, ggml_abort_callback abort_callback, void * abort_callback_data
    // 返回: 无返回值

    // 函数: llama_set_abort_callback
    // 描述: llama_set_abort_callback函数提供相关功能
    // 参数: struct llama_context * ctx, ggml_abort_callback abort_callback, void * abort_callback_data
    // 返回: 无返回值

    LLAMA_API void llama_set_abort_callback(struct llama_context * ctx, ggml_abort_callback abort_callback, void * abort_callback_data);

    // Wait until all computations are finished
    // This is automatically done when using one of the functions below to obtain the computation results
    // and is not necessary to call it explicitly in most cases
    // 函数: llama_synchronize
    // 描述: llama_synchronize函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_synchronize
    // 描述: llama_synchronize函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_synchronize
    // 描述: llama_synchronize函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_synchronize
    // 描述: llama_synchronize函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_synchronize
    // 描述: llama_synchronize函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_synchronize
    // 描述: llama_synchronize函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API void llama_synchronize(struct llama_context * ctx);

    // Token logits obtained from the last call to llama_decode()
    // The logits for which llama_batch.logits[i] != 0 are stored contiguously
    // in the order they have appeared in the batch.
    // Rows: number of tokens for which llama_batch.logits[i] != 0
    // Cols: n_vocab
    // TODO: deprecate in favor of llama_get_logits_ith() (ref: https://github.com/ggml-org/llama.cpp/pull/14853#issuecomment-3113143522)
    LLAMA_API float * llama_get_logits(struct llama_context * ctx);

    // Logits for the ith token. For positive indices, Equivalent to:
    // llama_get_logits(ctx) + ctx->output_ids[i]*n_vocab
    // Negative indicies can be used to access logits in reverse order, -1 is the last logit.
    // returns NULL for invalid ids.
    LLAMA_API float * llama_get_logits_ith(struct llama_context * ctx, int32_t i);

    // Get all output token embeddings.
    // when pooling_type == LLAMA_POOLING_TYPE_NONE or when using a generative model,
    // the embeddings for which llama_batch.logits[i] != 0 are stored contiguously
    // in the order they have appeared in the batch.
    // shape: [n_outputs*n_embd]
    // Otherwise, returns NULL.
    // TODO: deprecate in favor of llama_get_embeddings_ith() (ref: https://github.com/ggml-org/llama.cpp/pull/14853#issuecomment-3113143522)
    LLAMA_API float * llama_get_embeddings(struct llama_context * ctx);

    // Get the embeddings for the ith token. For positive indices, Equivalent to:
    // llama_get_embeddings(ctx) + ctx->output_ids[i]*n_embd
    // Negative indicies can be used to access embeddings in reverse order, -1 is the last embedding.
    // shape: [n_embd] (1-dimensional)
    // returns NULL for invalid ids.
    LLAMA_API float * llama_get_embeddings_ith(struct llama_context * ctx, int32_t i);

    // Get the embeddings for a sequence id
    // Returns NULL if pooling_type is LLAMA_POOLING_TYPE_NONE
    // when pooling_type == LLAMA_POOLING_TYPE_RANK, returns float[n_cls_out] with the rank(s) of the sequence
    // otherwise: float[n_embd] (1-dimensional)
    LLAMA_API float * llama_get_embeddings_seq(struct llama_context * ctx, llama_seq_id seq_id);

    //
    // backend sampling API [EXPERIMENTAL]
    // note: use only if the llama_context was created with at least one llama_sampler_seq_config
    //

    // Get the backend sampled token for the ith token.
    // Returns LLAMA_TOKEN_NULL if no token was sampled.
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    LLAMA_API llama_token llama_get_sampled_token_ith(struct llama_context * ctx, int32_t i);

    // Get the backend sampled probabilites for the ith token
    // The index matches llama_get_sampled_token_ith().
    // Returns NULL if no probabilites were generated.
    LLAMA_API float *  llama_get_sampled_probs_ith      (struct llama_context * ctx, int32_t i);
    // 函数: llama_get_sampled_probs_count_ith
    // 描述: llama_get_sampled_probs_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_probs_count_ith
    // 描述: llama_get_sampled_probs_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_probs_count_ith
    // 描述: llama_get_sampled_probs_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_probs_count_ith
    // 描述: llama_get_sampled_probs_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_probs_count_ith
    // 描述: llama_get_sampled_probs_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_probs_count_ith
    // 描述: llama_get_sampled_probs_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    LLAMA_API uint32_t llama_get_sampled_probs_count_ith(struct llama_context * ctx, int32_t i);

    // Get the backend sampled logits for the ith token
    // Returns NULL if no logits were sampled.
    LLAMA_API float *  llama_get_sampled_logits_ith      (struct llama_context * ctx, int32_t i);
    // 函数: llama_get_sampled_logits_count_ith
    // 描述: llama_get_sampled_logits_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_logits_count_ith
    // 描述: llama_get_sampled_logits_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_logits_count_ith
    // 描述: llama_get_sampled_logits_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_logits_count_ith
    // 描述: llama_get_sampled_logits_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_logits_count_ith
    // 描述: llama_get_sampled_logits_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    // 函数: llama_get_sampled_logits_count_ith
    // 描述: llama_get_sampled_logits_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: 无返回值

    LLAMA_API uint32_t llama_get_sampled_logits_count_ith(struct llama_context * ctx, int32_t i);

    // Get the backend sampled candidates (token ids) for the ith token
    // These are needed to map probability/logit indices to vocab token ids.
    // Returns NULL if no candidates were sampled.
    LLAMA_API llama_token * llama_get_sampled_candidates_ith      (struct llama_context * ctx, int32_t i);
    // 函数: llama_get_sampled_candidates_count_ith
    // 描述: llama_get_sampled_candidates_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: uint32_t类型返回值

    // 函数: llama_get_sampled_candidates_count_ith
    // 描述: llama_get_sampled_candidates_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: uint32_t类型返回值

    // 函数: llama_get_sampled_candidates_count_ith
    // 描述: llama_get_sampled_candidates_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: uint32_t类型返回值

    // 函数: llama_get_sampled_candidates_count_ith
    // 描述: llama_get_sampled_candidates_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: uint32_t类型返回值

    // 函数: llama_get_sampled_candidates_count_ith
    // 描述: llama_get_sampled_candidates_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: uint32_t类型返回值

    // 函数: llama_get_sampled_candidates_count_ith
    // 描述: llama_get_sampled_candidates_count_ith函数提供相关功能
    // 参数: struct llama_context * ctx, int32_t i
    // 返回: uint32_t类型返回值

    LLAMA_API uint32_t      llama_get_sampled_candidates_count_ith(struct llama_context * ctx, int32_t i);

    //
    // Vocab
    //

    LLAMA_API const char * llama_vocab_get_text(const struct llama_vocab * vocab, llama_token token);

    // 函数: llama_vocab_get_score
    // 描述: llama_vocab_get_score函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_get_score
    // 描述: llama_vocab_get_score函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_get_score
    // 描述: llama_vocab_get_score函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_get_score
    // 描述: llama_vocab_get_score函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_get_score
    // 描述: llama_vocab_get_score函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_get_score
    // 描述: llama_vocab_get_score函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    LLAMA_API float llama_vocab_get_score(const struct llama_vocab * vocab, llama_token token);

    LLAMA_API enum llama_token_attr llama_vocab_get_attr(const struct llama_vocab * vocab, llama_token token);

    // Check if the token is supposed to end generation (end-of-generation, eg. EOS, EOT, etc.)
    // 函数: llama_vocab_is_eog
    // 描述: llama_vocab_is_eog函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_eog
    // 描述: llama_vocab_is_eog函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_eog
    // 描述: llama_vocab_is_eog函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_eog
    // 描述: llama_vocab_is_eog函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_eog
    // 描述: llama_vocab_is_eog函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_eog
    // 描述: llama_vocab_is_eog函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    LLAMA_API bool llama_vocab_is_eog(const struct llama_vocab * vocab, llama_token token);

    // Identify if Token Id is a control token or a render-able token
    // 函数: llama_vocab_is_control
    // 描述: llama_vocab_is_control函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_control
    // 描述: llama_vocab_is_control函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_control
    // 描述: llama_vocab_is_control函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_control
    // 描述: llama_vocab_is_control函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_control
    // 描述: llama_vocab_is_control函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    // 函数: llama_vocab_is_control
    // 描述: llama_vocab_is_control函数提供相关功能
    // 参数: const struct llama_vocab * vocab, llama_token token
    // 返回: 无返回值

    LLAMA_API bool llama_vocab_is_control(const struct llama_vocab * vocab, llama_token token);

    // Special tokens
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_bos(const struct llama_vocab * vocab); // beginning-of-sentence
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_eos(const struct llama_vocab * vocab); // end-of-sentence
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_eot(const struct llama_vocab * vocab); // end-of-turn
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_sep(const struct llama_vocab * vocab); // sentence separator
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_nl (const struct llama_vocab * vocab); // next-line
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_pad(const struct llama_vocab * vocab); // padding
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_mask(const struct llama_vocab * vocab); // mask

    // 函数: llama_vocab_get_add_bos
    // 描述: llama_vocab_get_add_bos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_bos
    // 描述: llama_vocab_get_add_bos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_bos
    // 描述: llama_vocab_get_add_bos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_bos
    // 描述: llama_vocab_get_add_bos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_bos
    // 描述: llama_vocab_get_add_bos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_bos
    // 描述: llama_vocab_get_add_bos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API bool llama_vocab_get_add_bos(const struct llama_vocab * vocab);
    // 函数: llama_vocab_get_add_eos
    // 描述: llama_vocab_get_add_eos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_eos
    // 描述: llama_vocab_get_add_eos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_eos
    // 描述: llama_vocab_get_add_eos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_eos
    // 描述: llama_vocab_get_add_eos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_eos
    // 描述: llama_vocab_get_add_eos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_eos
    // 描述: llama_vocab_get_add_eos函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API bool llama_vocab_get_add_eos(const struct llama_vocab * vocab);
    // 函数: llama_vocab_get_add_sep
    // 描述: llama_vocab_get_add_sep函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_sep
    // 描述: llama_vocab_get_add_sep函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_sep
    // 描述: llama_vocab_get_add_sep函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_sep
    // 描述: llama_vocab_get_add_sep函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_sep
    // 描述: llama_vocab_get_add_sep函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_vocab_get_add_sep
    // 描述: llama_vocab_get_add_sep函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API bool llama_vocab_get_add_sep(const struct llama_vocab * vocab);

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_fim_pre(const struct llama_vocab * vocab);
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_fim_suf(const struct llama_vocab * vocab);
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_fim_mid(const struct llama_vocab * vocab);
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_fim_pad(const struct llama_vocab * vocab);
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_fim_rep(const struct llama_vocab * vocab);
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: const struct llama_vocab * vocab
    // 返回: 无返回值

    LLAMA_API llama_token llama_vocab_fim_sep(const struct llama_vocab * vocab);

    DEPRECATED(LLAMA_API const char * llama_token_get_text(const struct llama_vocab * vocab, llama_token token), "use llama_vocab_get_text instead");
    DEPRECATED(LLAMA_API float llama_token_get_score(const struct llama_vocab * vocab, llama_token token), "use llama_vocab_get_score instead");
    DEPRECATED(LLAMA_API enum llama_token_attr llama_token_get_attr(const struct llama_vocab * vocab, llama_token token), "use llama_vocab_get_attr instead");
    DEPRECATED(LLAMA_API bool llama_token_is_eog(const struct llama_vocab * vocab, llama_token token), "use llama_vocab_is_eog instead");
    DEPRECATED(LLAMA_API bool llama_token_is_control(const struct llama_vocab * vocab, llama_token token), "use llama_vocab_is_control instead");
    DEPRECATED(LLAMA_API llama_token llama_token_bos(const struct llama_vocab * vocab), "use llama_vocab_bos instead");
    DEPRECATED(LLAMA_API llama_token llama_token_eos(const struct llama_vocab * vocab), "use llama_vocab_eos instead");
    DEPRECATED(LLAMA_API llama_token llama_token_eot(const struct llama_vocab * vocab), "use llama_vocab_eot instead");
    DEPRECATED(LLAMA_API llama_token llama_token_cls(const struct llama_vocab * vocab), "use llama_vocab_cls instead");
    DEPRECATED(LLAMA_API llama_token llama_token_sep(const struct llama_vocab * vocab), "use llama_vocab_sep instead");
    DEPRECATED(LLAMA_API llama_token llama_token_nl (const struct llama_vocab * vocab), "use llama_vocab_nl instead");
    DEPRECATED(LLAMA_API llama_token llama_token_pad(const struct llama_vocab * vocab), "use llama_vocab_pad instead");
    DEPRECATED(LLAMA_API bool llama_add_bos_token(const struct llama_vocab * vocab), "use llama_vocab_get_add_bos instead");
    DEPRECATED(LLAMA_API bool llama_add_eos_token(const struct llama_vocab * vocab), "use llama_vocab_get_add_eos instead");
    DEPRECATED(LLAMA_API llama_token llama_token_fim_pre(const struct llama_vocab * vocab), "use llama_vocab_fim_pre instead");
    DEPRECATED(LLAMA_API llama_token llama_token_fim_suf(const struct llama_vocab * vocab), "use llama_vocab_fim_suf instead");
    DEPRECATED(LLAMA_API llama_token llama_token_fim_mid(const struct llama_vocab * vocab), "use llama_vocab_fim_mid instead");
    DEPRECATED(LLAMA_API llama_token llama_token_fim_pad(const struct llama_vocab * vocab), "use llama_vocab_fim_pad instead");
    DEPRECATED(LLAMA_API llama_token llama_token_fim_rep(const struct llama_vocab * vocab), "use llama_vocab_fim_rep instead");
    DEPRECATED(LLAMA_API llama_token llama_token_fim_sep(const struct llama_vocab * vocab), "use llama_vocab_fim_sep instead");

    // CLS is equivalent to BOS
    DEPRECATED(LLAMA_API llama_token llama_vocab_cls(const struct llama_vocab * vocab), // classification
            "use llama_vocab_bos instead");

    //
    // Tokenization
    //
    // The API is thread-safe.
    //

    /// @details Convert the provided text into tokens.
    /// @param tokens The tokens pointer must be large enough to hold the resulting tokens.
    /// @return Returns the number of tokens on success, no more than n_tokens_max
    /// @return Returns a negative number on failure - the number of tokens that would have been returned
    /// @return Returns INT32_MIN on overflow (e.g., tokenization result size exceeds int32_t limit)
    /// @param add_special Allow to add BOS and EOS tokens if model is configured to do so.
    /// @param parse_special Allow tokenizing special and/or control tokens which otherwise are not exposed and treated
    ///                      as plaintext. Does not insert a leading space.
    // 函数: llama_tokenize
    // 描述: 将文本转换为令牌
    // 参数: const struct llama_vocab * vocab, const char * text, int32_t   text_len, llama_token * tokens, int32_t   n_tokens_max, bool   add_special, bool   parse_special
    // 返回: 无返回值

    // 函数: llama_tokenize
    // 描述: 将文本转换为令牌
    // 参数: // Token Id -> Piece. // Uses the vocabulary in the provided context. // Does not write null terminator to the buffer. // User can skip up to 'lstrip' leading spaces before copying (useful when encoding/decoding multiple tokens with 'add_space_prefix'
    // 返回: 无返回值

    // 函数: llama_tokenize
    // 描述: 将文本转换为令牌
    // 参数: // @param special If true, special tokens are rendered in the output. // 函数: llama_token_to_piece // 描述: llama_token_to_piece函数提供相关功能 // 参数: const struct llama_vocab * vocab, llama_token   token, char * buf, int32_t   length, int32_t   lstrip, bool   special // 返回: 无返回值  // 函数: llama_token_to_piece // 描述: llama_token_to_piece函数提供相关功能 // 参数: /// @details Convert the provided tokens into text (inverse of llama_tokenize(
    // 返回: 无返回值

    // 函数: llama_tokenize
    // 描述: 将文本转换为令牌
    // 参数: // 返回: 无返回值  // 函数: llama_token_to_piece // 描述: llama_token_to_piece函数提供相关功能 // 参数: /// @param text The char pointer must be large enough to hold the resulting text. /// @return Returns the number of chars/bytes on success, no more than text_len_max. /// @return Returns a negative number on failure - the number of chars/bytes that would have been returned. /// @param remove_special Allow to remove BOS and EOS tokens if model is configured to do so. /// @param unparse_special If true, special tokens are rendered in the output. // 函数: llama_detokenize // 描述: 将令牌转换回文本 // 参数: const struct llama_vocab * vocab, const llama_token * tokens, int32_t   n_tokens, char * text, int32_t   text_len_max, bool   remove_special, bool   unparse_special // 返回: 无返回值  // 函数: llama_detokenize // 描述: 将令牌转换回文本 // 参数: // // Chat templates //  /// Apply chat template. Inspired by hf apply_chat_template( // 返回: 无返回值  LLAMA_API int32_t llama_detokenize( /// /// NOTE: This function does not use a jinja parser. It only support a pre-defined list of template. See more: https://github.com/ggml-org/llama.cpp/wiki/Templates-supported-by-llama_chat_apply_template /// @param tmpl A Jinja template to use for this chat. /// @param chat Pointer to a list of multiple llama_chat_message /// @param n_msg Number of llama_chat_message in this chat /// @param add_ass Whether to end the prompt with the token(s // 返回: 无返回值  LLAMA_API int32_t llama_token_to_piece( /// @param buf A buffer to hold the output formatted prompt. The recommended alloc size is 2 * (total number of characters of all messages
    // 返回: 无返回值

    // 函数: llama_tokenize
    // 描述: 将文本转换为令牌
    // 参数: /// @param length The size of the allocated buffer /// @return The total number of bytes of the formatted prompt. If is it larger than the size of buffer, you may need to re-alloc it and then re-apply the template. // 函数: llama_chat_apply_template // 描述: 应用聊天模板 // 参数: const char * tmpl, const struct llama_chat_message * chat, size_t   n_msg, bool   add_ass, char * buf, int32_t   length // 返回: 无返回值  // 函数: llama_chat_apply_template // 描述: 应用聊天模板 // 参数: // Get list of built-in chat templates // 函数: llama_chat_builtin_templates // 描述: llama_chat_builtin_templates函数提供相关功能 // 参数: const char ** output, size_t len // 返回: 无返回值  LLAMA_API int32_t llama_chat_builtin_templates(const char ** output, size_t len // 返回: 无返回值  // 函数: llama_chat_apply_template // 描述: 应用聊天模板 // 参数: // // Sampling API // // Sample usage: // //    // prepare the sampling chain at the start //    auto sparams = llama_sampler_chain_default_params( // 返回: 无返回值  // 函数: llama_chat_apply_template // 描述: 应用聊天模板 // 参数: // //    llama_sampler * smpl = llama_sampler_chain_init(sparams // 返回: 无返回值  LLAMA_API int32_t llama_chat_apply_template( // //    llama_sampler_chain_add(smpl, llama_sampler_init_top_k(50)
    // 返回: 无返回值

    // 函数: llama_tokenize
    // 描述: 将文本转换为令牌
    // 参数: //    llama_sampler_chain_add(smpl, llama_sampler_init_top_p(0.9, 1)
    // 返回: 无返回值

    LLAMA_API int32_t llama_tokenize(
    //    llama_sampler_chain_add(smpl, llama_sampler_init_temp (0.8));
    //
    //    // typically, the chain should end with a sampler such as "greedy", "dist" or "mirostat"
    //    // this sampler will be responsible to select the actual token
    //    llama_sampler_chain_add(smpl, llama_sampler_init_dist(seed));
    //
    //    ...
    //
    //    // decoding loop:
    //    while (...) {
    //        ...
    //
    //        llama_decode(ctx, batch);
    //
    //        // sample from the logits of the last token in the batch
    //        const llama_token id = llama_sampler_sample(smpl, ctx, -1);
    //
    //        ...
    //    }
    //
    //    llama_sampler_free(smpl);
    //

    typedef void * llama_sampler_context_t;

    // 类: llama_sampler_data
    // 描述: llama_sampler_data类提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 类: llama_sampler_data
    // 描述: llama_sampler_data类提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    struct llama_sampler_data {
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
        struct ggml_tensor * logits;
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
        struct ggml_tensor * probs;
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
        struct ggml_tensor * sampled;
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
        struct ggml_tensor * candidates;
    };

    // user code can implement the interface below in order to create custom llama_sampler
    // 类: llama_sampler_i
    // 描述: llama_sampler_i类提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 类: llama_sampler_i
    // 描述: llama_sampler_i类提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    struct llama_sampler_i {
        const char *           (*name)  (const struct llama_sampler * smpl);                                 // can be NULL
        void                   (*accept)(      struct llama_sampler * smpl, llama_token token);              // can be NULL
        void                   (*apply) (      struct llama_sampler * smpl, llama_token_data_array * cur_p); // required
        void                   (*reset) (      struct llama_sampler * smpl);                                 // can be NULL
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
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
        struct llama_sampler * (*clone) (const struct llama_sampler * smpl);                                 // can be NULL if ctx is NULL
        void                   (*free)  (      struct llama_sampler * smpl);                                 // can be NULL if ctx is NULL

        // [EXPERIMENTAL]
        // backend sampling interface:

        // return true if the backend supports all ops needed by the sampler
        // note: call once per sampler
        bool (*backend_init)(struct llama_sampler * smpl, ggml_backend_buffer_type_t buft);

        // call after .backend_apply()
        void (*backend_accept)(
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
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
                struct llama_sampler * smpl,
                // 类: ggml_context
                // 描述: ggml_context类提供相关功能
                // 用途: 用于处理ggml_context相关的操作
                // 类: ggml_context
                // 描述: ggml_context类提供相关功能
                // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
                struct ggml_context  * ctx,
                // 类: ggml_cgraph
                // 描述: ggml_cgraph类提供相关功能
                // 用途: 用于处理ggml_cgraph相关的操作
                // 类: ggml_cgraph
                // 描述: ggml_cgraph类提供相关功能
                // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
                struct ggml_cgraph   * gf,
                // 类: ggml_tensor
                // 描述: ggml_tensor类提供相关功能
                // 用途: 用于处理ggml_tensor相关的操作
                // 类: ggml_tensor
                // 描述: ggml_tensor类提供相关功能
                // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
                struct ggml_tensor   * selected_token);

        // call after .backend_init()
        void (*backend_apply)(
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
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
                struct llama_sampler      * smpl,
                // 类: ggml_context
                // 描述: ggml_context类提供相关功能
                // 用途: 用于处理ggml_context相关的操作
                // 类: ggml_context
                // 描述: ggml_context类提供相关功能
                // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
    // 结构体: ggml_context
    // 描述: ggml_context结构体提供相关功能
    // 用途: 用于处理ggml_context相关的操作
                struct ggml_context       * ctx,
                // 类: ggml_cgraph
                // 描述: ggml_cgraph类提供相关功能
                // 用途: 用于处理ggml_cgraph相关的操作
                // 类: ggml_cgraph
                // 描述: ggml_cgraph类提供相关功能
                // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
    // 结构体: ggml_cgraph
    // 描述: ggml_cgraph结构体提供相关功能
    // 用途: 用于处理ggml_cgraph相关的操作
                struct ggml_cgraph        * gf,
                // 类: llama_sampler_data
                // 描述: llama_sampler_data类提供相关功能
                // 用途: 用于处理llama_sampler_data相关的操作
                // 类: llama_sampler_data
                // 描述: llama_sampler_data类提供相关功能
                // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
    // 结构体: llama_sampler_data
    // 描述: llama_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_sampler_data相关的操作
                struct llama_sampler_data * data);

        // called before graph execution to set inputs for the current ubatch
        void (*backend_set_input)(struct llama_sampler * smpl);
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
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    // 结构体: llama_sampler
    // 描述: llama_sampler结构体提供相关功能
    // 用途: 用于处理llama_sampler相关的操作
    struct llama_sampler {
        // 类: llama_sampler_i
        // 描述: llama_sampler_i类提供相关功能
        // 用途: 用于处理llama_sampler_i相关的操作
        // 类: llama_sampler_i
        // 描述: llama_sampler_i类提供相关功能
        // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
    // 结构体: llama_sampler_i
    // 描述: llama_sampler_i结构体提供相关功能
    // 用途: 用于处理llama_sampler_i相关的操作
        struct llama_sampler_i * iface;

        llama_sampler_context_t ctx;
    };

    // [EXPERIMENTAL]
    // attach a sampler to the context
    // note: prefer initializing the context with llama_context_params.samplers when possible
    // 函数: llama_set_sampler
    // 描述: llama_set_sampler函数提供相关功能
    // 参数: struct llama_context * ctx, llama_seq_id seq_id, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_set_sampler
    // 描述: llama_set_sampler函数提供相关功能
    // 参数: struct llama_context * ctx, llama_seq_id seq_id, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_set_sampler
    // 描述: llama_set_sampler函数提供相关功能
    // 参数: struct llama_context * ctx, llama_seq_id seq_id, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_set_sampler
    // 描述: llama_set_sampler函数提供相关功能
    // 参数: struct llama_context * ctx, llama_seq_id seq_id, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_set_sampler
    // 描述: llama_set_sampler函数提供相关功能
    // 参数: struct llama_context * ctx, llama_seq_id seq_id, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_set_sampler
    // 描述: llama_set_sampler函数提供相关功能
    // 参数: struct llama_context * ctx, llama_seq_id seq_id, struct llama_sampler * smpl
    // 返回: 无返回值

    LLAMA_API bool llama_set_sampler(struct llama_context * ctx, llama_seq_id seq_id, struct llama_sampler * smpl);

    // mirror of llama_sampler_i:
    LLAMA_API struct llama_sampler * llama_sampler_init  (      struct llama_sampler_i * iface, llama_sampler_context_t ctx);
    LLAMA_API const char *           llama_sampler_name  (const struct llama_sampler * smpl);
    // 函数: llama_sampler_accept
    // 描述: llama_sampler_accept函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token token
    // 返回: 无返回值

    // 函数: llama_sampler_accept
    // 描述: llama_sampler_accept函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token token
    // 返回: 无返回值

    // 函数: llama_sampler_accept
    // 描述: llama_sampler_accept函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token token
    // 返回: 无返回值

    // 函数: llama_sampler_accept
    // 描述: llama_sampler_accept函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token token
    // 返回: 无返回值

    // 函数: llama_sampler_accept
    // 描述: llama_sampler_accept函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token token
    // 返回: 无返回值

    // 函数: llama_sampler_accept
    // 描述: llama_sampler_accept函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token token
    // 返回: 无返回值

    LLAMA_API void                   llama_sampler_accept(      struct llama_sampler * smpl, llama_token token);
    // 函数: llama_sampler_apply
    // 描述: llama_sampler_apply函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token_data_array * cur_p
    // 返回: 无返回值

    // 函数: llama_sampler_apply
    // 描述: llama_sampler_apply函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token_data_array * cur_p
    // 返回: 无返回值

    // 函数: llama_sampler_apply
    // 描述: llama_sampler_apply函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token_data_array * cur_p
    // 返回: 无返回值

    // 函数: llama_sampler_apply
    // 描述: llama_sampler_apply函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token_data_array * cur_p
    // 返回: 无返回值

    // 函数: llama_sampler_apply
    // 描述: llama_sampler_apply函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token_data_array * cur_p
    // 返回: 无返回值

    // 函数: llama_sampler_apply
    // 描述: llama_sampler_apply函数提供相关功能
    // 参数: struct llama_sampler * smpl, llama_token_data_array * cur_p
    // 返回: 无返回值

    LLAMA_API void                   llama_sampler_apply (      struct llama_sampler * smpl, llama_token_data_array * cur_p);
    // 函数: llama_sampler_reset
    // 描述: llama_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_reset
    // 描述: llama_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_reset
    // 描述: llama_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_reset
    // 描述: llama_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_reset
    // 描述: llama_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_reset
    // 描述: llama_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    LLAMA_API void                   llama_sampler_reset (      struct llama_sampler * smpl);
    LLAMA_API struct llama_sampler * llama_sampler_clone (const struct llama_sampler * smpl);
    // important: do not free if the sampler has been added to a llama_sampler_chain (via llama_sampler_chain_add)
    // 函数: llama_sampler_free
    // 描述: 释放采样器资源
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_free
    // 描述: 释放采样器资源
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_free
    // 描述: 释放采样器资源
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_free
    // 描述: 释放采样器资源
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_free
    // 描述: 释放采样器资源
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_free
    // 描述: 释放采样器资源
    // 参数: struct llama_sampler * smpl
    // 返回: 无返回值

    LLAMA_API void                   llama_sampler_free  (      struct llama_sampler * smpl);

    // llama_sampler_chain
    // a type of llama_sampler that can chain multiple samplers one after another

    LLAMA_API struct llama_sampler * llama_sampler_chain_init(struct llama_sampler_chain_params params);

    // important: takes ownership of the sampler object and will free it when llama_sampler_free is called
    // 函数: llama_sampler_chain_add
    // 描述: llama_sampler_chain_add函数提供相关功能
    // 参数: struct llama_sampler * chain, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_chain_add
    // 描述: llama_sampler_chain_add函数提供相关功能
    // 参数: struct llama_sampler * chain, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_chain_add
    // 描述: llama_sampler_chain_add函数提供相关功能
    // 参数: struct llama_sampler * chain, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_chain_add
    // 描述: llama_sampler_chain_add函数提供相关功能
    // 参数: struct llama_sampler * chain, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_chain_add
    // 描述: llama_sampler_chain_add函数提供相关功能
    // 参数: struct llama_sampler * chain, struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_chain_add
    // 描述: llama_sampler_chain_add函数提供相关功能
    // 参数: struct llama_sampler * chain, struct llama_sampler * smpl
    // 返回: 无返回值

    LLAMA_API void                   llama_sampler_chain_add(      struct llama_sampler * chain, struct llama_sampler * smpl);

    // return NULL if:
    //   - the sampler is NULL
    //   - the sampler is not a llama_sampler_chain
    //   - the index is out of bounds, unless i == -1
    //   - if i == -1, returns the chain itself (can be used to check if the sampler is a chain)
    LLAMA_API struct llama_sampler * llama_sampler_chain_get(      struct llama_sampler * chain, int32_t i);

    // the total number of samplers in the chain
    // 函数: llama_sampler_chain_n
    // 描述: llama_sampler_chain_n函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: int类型返回值

    // 函数: llama_sampler_chain_n
    // 描述: llama_sampler_chain_n函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: int类型返回值

    // 函数: llama_sampler_chain_n
    // 描述: llama_sampler_chain_n函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: int类型返回值

    // 函数: llama_sampler_chain_n
    // 描述: llama_sampler_chain_n函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: int类型返回值

    // 函数: llama_sampler_chain_n
    // 描述: llama_sampler_chain_n函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: int类型返回值

    // 函数: llama_sampler_chain_n
    // 描述: llama_sampler_chain_n函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: int类型返回值

    LLAMA_API int                    llama_sampler_chain_n  (const struct llama_sampler * chain);

    // after removing a sampler, the chain will no longer own it, and it will not be freed when the chain is freed
    LLAMA_API struct llama_sampler * llama_sampler_chain_remove(   struct llama_sampler * chain, int32_t i);

    // available samplers:

    LLAMA_API struct llama_sampler * llama_sampler_init_greedy(void);

    /// seed == LLAMA_DEFAULT_SEED to use a random seed.
    LLAMA_API struct llama_sampler * llama_sampler_init_dist(uint32_t seed);

    /// @details Top-K sampling described in academic paper "The Curious Case of Neural Text Degeneration" https://arxiv.org/abs/1904.09751
    /// Setting k <= 0 makes this a noop
    LLAMA_API struct llama_sampler * llama_sampler_init_top_k      (int32_t k);

    /// @details Nucleus sampling described in academic paper "The Curious Case of Neural Text Degeneration" https://arxiv.org/abs/1904.09751
    LLAMA_API struct llama_sampler * llama_sampler_init_top_p      (float   p, size_t min_keep);

    /// @details Minimum P sampling as described in https://github.com/ggml-org/llama.cpp/pull/3841
    LLAMA_API struct llama_sampler * llama_sampler_init_min_p      (float   p, size_t min_keep);

    /// @details Locally Typical Sampling implementation described in the paper https://arxiv.org/abs/2202.00666.
    LLAMA_API struct llama_sampler * llama_sampler_init_typical    (float   p, size_t min_keep);

    /// #details Updates the logits l_i` = l_i/t. When t <= 0.0f, the maximum logit is kept at it's original value, the rest are set to -inf
    LLAMA_API struct llama_sampler * llama_sampler_init_temp       (float   t);

    /// @details Dynamic temperature implementation (a.k.a. entropy) described in the paper https://arxiv.org/abs/2309.02772.
    LLAMA_API struct llama_sampler * llama_sampler_init_temp_ext   (float   t, float   delta, float exponent);

    /// @details XTC sampler as described in https://github.com/oobabooga/text-generation-webui/pull/6335
    LLAMA_API struct llama_sampler * llama_sampler_init_xtc        (float   p, float   t,     size_t min_keep, uint32_t seed);

    /// @details Top n sigma sampling as described in academic paper "Top-nσ: Not All Logits Are You Need" https://arxiv.org/pdf/2411.07641
    LLAMA_API struct llama_sampler * llama_sampler_init_top_n_sigma(float   n);

    /// @details Mirostat 1.0 algorithm described in the paper https://arxiv.org/abs/2007.14966. Uses tokens instead of words.
    /// @param candidates A vector of `llama_token_data` containing the candidate tokens, their probabilities (p), and log-odds (logit) for the current position in the generated text.
    /// @param tau  The target cross-entropy (or surprise) value you want to achieve for the generated text. A higher value corresponds to more surprising or less predictable text, while a lower value corresponds to less surprising or more predictable text.
    /// @param eta The learning rate used to update `mu` based on the error between the target and observed surprisal of the sampled word. A larger learning rate will cause `mu` to be updated more quickly, while a smaller learning rate will result in slower updates.
    /// @param m The number of tokens considered in the estimation of `s_hat`. This is an arbitrary value that is used to calculate `s_hat`, which in turn helps to calculate the value of `k`. In the paper, they use `m = 100`, but you can experiment with different values to see how it affects the performance of the algorithm.
    /// @param mu Maximum cross-entropy. This value is initialized to be twice the target cross-entropy (`2 * tau`) and is updated in the algorithm based on the error between the target and observed surprisal.
    LLAMA_API struct llama_sampler * llama_sampler_init_mirostat(
                             int32_t   n_vocab,
                            uint32_t   seed,
                               float   tau,
                               float   eta,
                             int32_t   m);

    /// @details Mirostat 2.0 algorithm described in the paper https://arxiv.org/abs/2007.14966. Uses tokens instead of words.
    /// @param candidates A vector of `llama_token_data` containing the candidate tokens, their probabilities (p), and log-odds (logit) for the current position in the generated text.
    /// @param tau  The target cross-entropy (or surprise) value you want to achieve for the generated text. A higher value corresponds to more surprising or less predictable text, while a lower value corresponds to less surprising or more predictable text.
    /// @param eta The learning rate used to update `mu` based on the error between the target and observed surprisal of the sampled word. A larger learning rate will cause `mu` to be updated more quickly, while a smaller learning rate will result in slower updates.
    /// @param mu Maximum cross-entropy. This value is initialized to be twice the target cross-entropy (`2 * tau`) and is updated in the algorithm based on the error between the target and observed surprisal.
    LLAMA_API struct llama_sampler * llama_sampler_init_mirostat_v2(
                            uint32_t   seed,
                               float   tau,
                               float   eta);

    /// @details Intializes a GBNF grammar, see grammars/README.md for details.
    /// @param vocab The vocabulary that this grammar will be used with.
    /// @param grammar_str The production rules for the grammar, encoded as a string. Returns an empty grammar if empty. Returns NULL if parsing of grammar_str fails.
    /// @param grammar_root The name of the start symbol for the grammar.
    LLAMA_API struct llama_sampler * llama_sampler_init_grammar(
            const struct llama_vocab * vocab,
                          const char * grammar_str,
                          const char * grammar_root);

    DEPRECATED(LLAMA_API struct llama_sampler * llama_sampler_init_grammar_lazy(
            const struct llama_vocab * vocab,
                          const char * grammar_str,
                          const char * grammar_root,
                         const char ** trigger_words,
                                size_t num_trigger_words,
                   const llama_token * trigger_tokens,
                                size_t num_trigger_tokens),
        "use llama_sampler_init_grammar_lazy_patterns instead");


    /// @details Lazy grammar sampler, introduced in https://github.com/ggml-org/llama.cpp/pull/9639
    /// @param trigger_patterns A list of patterns that will trigger the grammar sampler. Pattern will be matched from the start of the generation output, and grammar sampler will be fed content starting from its first match group.
    /// @param trigger_tokens A list of tokens that will trigger the grammar sampler. Grammar sampler will be fed content starting from the trigger token included.
    LLAMA_API struct llama_sampler * llama_sampler_init_grammar_lazy_patterns(
        const struct llama_vocab * vocab,
                      const char * grammar_str,
                      const char * grammar_root,
                     const char ** trigger_patterns,
                            size_t num_trigger_patterns,
               const llama_token * trigger_tokens,
                            size_t num_trigger_tokens);


    /// NOTE: Avoid using on the full vocabulary as searching for repeated tokens can become slow. For example, apply top-k or top-p sampling first.
    LLAMA_API struct llama_sampler * llama_sampler_init_penalties(
                             int32_t   penalty_last_n,   // last n tokens to penalize (0 = disable penalty, -1 = context size)
                               float   penalty_repeat,   // 1.0 = disabled
                               float   penalty_freq,     // 0.0 = disabled
                               float   penalty_present); // 0.0 = disabled

    ///  @details DRY sampler, designed by p-e-w, as described in: https://github.com/oobabooga/text-generation-webui/pull/5677, porting Koboldcpp implementation authored by pi6am: https://github.com/LostRuins/koboldcpp/pull/982
    LLAMA_API struct llama_sampler * llama_sampler_init_dry(
            const struct llama_vocab *  vocab,
                             int32_t    n_ctx_train,
                               float    dry_multiplier,
                               float    dry_base,
                             int32_t    dry_allowed_length,
                             int32_t    dry_penalty_last_n,
                          const char ** seq_breakers,
                              size_t    num_breakers);

    /// adaptive-p: select tokens near a configurable target probability over time.
    ///
    /// the adaptive-p sampler transforms the token probability distribution to favor tokens
    /// that fall near a user-configurable probability target.
    ///
    /// internally, the sampler maintains an exponential moving average of the *ORIGINAL*
    /// probabilities of selected tokens at each sampling step. it uses this EMA to compute an
    /// adapted target probability at each sampling step, thus maintaining the desired target
    /// probability over time.
    ///
    /// adaptive-p selects a token ID rather than just mutating candidates, so it must be last
    /// in the sampler chain (like mirostat, dist, greedy).
    ///
    /// only mild truncation before this sampler is recommended. we suggest applying min-p
    /// before adaptive-p as the only other active sampler in the chain.
    ///
    /// @param target select tokens near this probability (valid range 0.0 to 1.0; negative = disabled)
    /// @param decay  EMA decay for adaptation; history ≈ 1/(1-decay) tokens (valid range 0.0 - 0.99)
    /// @param seed   RNG seed
    ///
    /// ref: https://github.com/ggml-org/llama.cpp/pull/17927
    ///
    LLAMA_API struct llama_sampler * llama_sampler_init_adaptive_p(
                               float   target,
                               float   decay,
                            uint32_t   seed);

    LLAMA_API struct llama_sampler * llama_sampler_init_logit_bias(
                             int32_t   n_vocab,
                             int32_t   n_logit_bias,
              const llama_logit_bias * logit_bias);

    // this sampler is meant to be used for fill-in-the-middle infilling
    // it's supposed to be used after top_k + top_p sampling
    //
    // 1. if the sum of the EOG probs times the number of candidates is higher than the sum of the other probs -> pick EOG
    // 2. combine probs of tokens that have the same prefix
    //
    // example:
    //
    // - before:
    //   "hel":   0.5
    //   "hell":  0.2
    //   "hello": 0.1
    //   "dummy": 0.1
    //
    // - after:
    //   "hel":   0.8
    //   "dummy": 0.1
    //
    // 3. discard non-EOG tokens with low prob
    // 4. if no tokens are left -> pick EOT
    //
    LLAMA_API struct llama_sampler * llama_sampler_init_infill(const struct llama_vocab * vocab);

    // Returns the seed used by the sampler if applicable, LLAMA_DEFAULT_SEED otherwise
    // 函数: llama_sampler_get_seed
    // 描述: llama_sampler_get_seed函数提供相关功能
    // 参数: const struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_get_seed
    // 描述: llama_sampler_get_seed函数提供相关功能
    // 参数: const struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_get_seed
    // 描述: llama_sampler_get_seed函数提供相关功能
    // 参数: const struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_get_seed
    // 描述: llama_sampler_get_seed函数提供相关功能
    // 参数: const struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_get_seed
    // 描述: llama_sampler_get_seed函数提供相关功能
    // 参数: const struct llama_sampler * smpl
    // 返回: 无返回值

    // 函数: llama_sampler_get_seed
    // 描述: llama_sampler_get_seed函数提供相关功能
    // 参数: const struct llama_sampler * smpl
    // 返回: 无返回值

    LLAMA_API uint32_t llama_sampler_get_seed(const struct llama_sampler * smpl);

    /// @details Sample and accept a token from the idx-th output of the last evaluation
    //
    // Shorthand for:
    //    const auto * logits = llama_get_logits_ith(ctx, idx);
    //    llama_token_data_array cur_p = { ... init from logits ... };
    //    llama_sampler_apply(smpl, &cur_p);
    //    auto token = cur_p.data[cur_p.selected].id;
    //    llama_sampler_accept(smpl, token);
    //    return token;
    // Returns the sampled token
    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_sampler * smpl, struct llama_context * ctx, int32_t idx
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_sampler * smpl, struct llama_context * ctx, int32_t idx
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_sampler * smpl, struct llama_context * ctx, int32_t idx
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_sampler * smpl, struct llama_context * ctx, int32_t idx
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_sampler * smpl, struct llama_context * ctx, int32_t idx
    // 返回: 无返回值

    // 函数: llama_token
    // 描述: llama_token函数提供相关功能
    // 参数: struct llama_sampler * smpl, struct llama_context * ctx, int32_t idx
    // 返回: 无返回值

    LLAMA_API llama_token llama_sampler_sample(struct llama_sampler * smpl, struct llama_context * ctx, int32_t idx);

    // TODO: extend in the future
    //LLAMA_API void llama_decode_with_sampler(struct llama_context * ctx, struct llama_sampler * smpl, struct llama_batch batch, ...);

    //
    // Model split
    //

    /// @details Build a split GGUF final path for this chunk.
    ///          llama_split_path(split_path, sizeof(split_path), "/models/ggml-model-q4_0", 2, 4) => split_path = "/models/ggml-model-q4_0-00002-of-00004.gguf"
    //  Returns the split_path length.
    // 函数: llama_split_path
    // 描述: llama_split_path函数提供相关功能
    // 参数: char * split_path, size_t maxlen, const char * path_prefix, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_path
    // 描述: llama_split_path函数提供相关功能
    // 参数: char * split_path, size_t maxlen, const char * path_prefix, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_path
    // 描述: llama_split_path函数提供相关功能
    // 参数: char * split_path, size_t maxlen, const char * path_prefix, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_path
    // 描述: llama_split_path函数提供相关功能
    // 参数: char * split_path, size_t maxlen, const char * path_prefix, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_path
    // 描述: llama_split_path函数提供相关功能
    // 参数: char * split_path, size_t maxlen, const char * path_prefix, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_path
    // 描述: llama_split_path函数提供相关功能
    // 参数: char * split_path, size_t maxlen, const char * path_prefix, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    LLAMA_API int32_t llama_split_path(char * split_path, size_t maxlen, const char * path_prefix, int32_t split_no, int32_t split_count);

    /// @details Extract the path prefix from the split_path if and only if the split_no and split_count match.
    ///          llama_split_prefix(split_prefix, 64, "/models/ggml-model-q4_0-00002-of-00004.gguf", 2, 4) => split_prefix = "/models/ggml-model-q4_0"
    //  Returns the split_prefix length.
    // 函数: llama_split_prefix
    // 描述: llama_split_prefix函数提供相关功能
    // 参数: char * split_prefix, size_t maxlen, const char * split_path, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_prefix
    // 描述: llama_split_prefix函数提供相关功能
    // 参数: char * split_prefix, size_t maxlen, const char * split_path, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_prefix
    // 描述: llama_split_prefix函数提供相关功能
    // 参数: char * split_prefix, size_t maxlen, const char * split_path, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_prefix
    // 描述: llama_split_prefix函数提供相关功能
    // 参数: char * split_prefix, size_t maxlen, const char * split_path, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_prefix
    // 描述: llama_split_prefix函数提供相关功能
    // 参数: char * split_prefix, size_t maxlen, const char * split_path, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    // 函数: llama_split_prefix
    // 描述: llama_split_prefix函数提供相关功能
    // 参数: char * split_prefix, size_t maxlen, const char * split_path, int32_t split_no, int32_t split_count
    // 返回: 无返回值

    LLAMA_API int32_t llama_split_prefix(char * split_prefix, size_t maxlen, const char * split_path, int32_t split_no, int32_t split_count);

    // Print system information
    LLAMA_API const char * llama_print_system_info(void);

    // Set callback for all future logging events.
    // If this is not called, or NULL is supplied, everything is output on stderr.
    // The logger state is global so these functions are NOT thread safe.
    // 函数: llama_log_get
    // 描述: llama_log_get函数提供相关功能
    // 参数: ggml_log_callback * log_callback, void ** user_data
    // 返回: 无返回值

    // 函数: llama_log_get
    // 描述: llama_log_get函数提供相关功能
    // 参数: ggml_log_callback * log_callback, void ** user_data
    // 返回: 无返回值

    // 函数: llama_log_get
    // 描述: llama_log_get函数提供相关功能
    // 参数: ggml_log_callback * log_callback, void ** user_data
    // 返回: 无返回值

    // 函数: llama_log_get
    // 描述: llama_log_get函数提供相关功能
    // 参数: ggml_log_callback * log_callback, void ** user_data
    // 返回: 无返回值

    // 函数: llama_log_get
    // 描述: llama_log_get函数提供相关功能
    // 参数: ggml_log_callback * log_callback, void ** user_data
    // 返回: 无返回值

    // 函数: llama_log_get
    // 描述: llama_log_get函数提供相关功能
    // 参数: ggml_log_callback * log_callback, void ** user_data
    // 返回: 无返回值

    LLAMA_API void llama_log_get(ggml_log_callback * log_callback, void ** user_data);
    // 函数: llama_log_set
    // 描述: llama_log_set函数提供相关功能
    // 参数: ggml_log_callback   log_callback, void *  user_data
    // 返回: 无返回值

    // 函数: llama_log_set
    // 描述: llama_log_set函数提供相关功能
    // 参数: ggml_log_callback   log_callback, void *  user_data
    // 返回: 无返回值

    // 函数: llama_log_set
    // 描述: llama_log_set函数提供相关功能
    // 参数: ggml_log_callback   log_callback, void *  user_data
    // 返回: 无返回值

    // 函数: llama_log_set
    // 描述: llama_log_set函数提供相关功能
    // 参数: ggml_log_callback   log_callback, void *  user_data
    // 返回: 无返回值

    // 函数: llama_log_set
    // 描述: llama_log_set函数提供相关功能
    // 参数: ggml_log_callback   log_callback, void *  user_data
    // 返回: 无返回值

    // 函数: llama_log_set
    // 描述: llama_log_set函数提供相关功能
    // 参数: ggml_log_callback   log_callback, void *  user_data
    // 返回: 无返回值

    LLAMA_API void llama_log_set(ggml_log_callback   log_callback, void *  user_data);

    //
    // Performance utils
    //
    // NOTE: Used by llama.cpp examples/tools, avoid using in third-party apps. Instead, do your own performance measurements.
    //

    // 类: llama_perf_context_data
    // 描述: llama_perf_context_data类提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    // 类: llama_perf_context_data
    // 描述: llama_perf_context_data类提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    // 结构体: llama_perf_context_data
    // 描述: llama_perf_context_data结构体提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    // 结构体: llama_perf_context_data
    // 描述: llama_perf_context_data结构体提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    // 结构体: llama_perf_context_data
    // 描述: llama_perf_context_data结构体提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    // 结构体: llama_perf_context_data
    // 描述: llama_perf_context_data结构体提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    // 结构体: llama_perf_context_data
    // 描述: llama_perf_context_data结构体提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    // 结构体: llama_perf_context_data
    // 描述: llama_perf_context_data结构体提供相关功能
    // 用途: 用于处理llama_perf_context_data相关的操作
    struct llama_perf_context_data {
        // ms == milliseconds
        double t_start_ms;  // absolute start time
        double t_load_ms;   // time needed for loading the model
        double t_p_eval_ms; // time needed for processing the prompt
        double t_eval_ms;   // time needed for generating tokens

        int32_t n_p_eval;   // number of prompt tokens
        int32_t n_eval;     // number of generated tokens
        int32_t n_reused;   // number of times a ggml compute graph had been reused
    };

    // 类: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data类提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    // 类: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data类提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    // 结构体: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    // 结构体: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    // 结构体: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    // 结构体: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    // 结构体: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    // 结构体: llama_perf_sampler_data
    // 描述: llama_perf_sampler_data结构体提供相关功能
    // 用途: 用于处理llama_perf_sampler_data相关的操作
    struct llama_perf_sampler_data {
        double t_sample_ms; // time needed for sampling in ms

        int32_t n_sample;   // number of sampled tokens
    };

    LLAMA_API struct llama_perf_context_data llama_perf_context      (const struct llama_context * ctx);
    // 函数: llama_perf_context_print
    // 描述: llama_perf_context_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_print
    // 描述: llama_perf_context_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_print
    // 描述: llama_perf_context_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_print
    // 描述: llama_perf_context_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_print
    // 描述: llama_perf_context_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_print
    // 描述: llama_perf_context_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API void                           llama_perf_context_print(const struct llama_context * ctx);
    // 函数: llama_perf_context_reset
    // 描述: llama_perf_context_reset函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_reset
    // 描述: llama_perf_context_reset函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_reset
    // 描述: llama_perf_context_reset函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_reset
    // 描述: llama_perf_context_reset函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_reset
    // 描述: llama_perf_context_reset函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_perf_context_reset
    // 描述: llama_perf_context_reset函数提供相关功能
    // 参数: struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API void                           llama_perf_context_reset(      struct llama_context * ctx);

    // NOTE: the following work only with samplers constructed via llama_sampler_chain_init
    LLAMA_API struct llama_perf_sampler_data llama_perf_sampler      (const struct llama_sampler * chain);
    // 函数: llama_perf_sampler_print
    // 描述: llama_perf_sampler_print函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_print
    // 描述: llama_perf_sampler_print函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_print
    // 描述: llama_perf_sampler_print函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_print
    // 描述: llama_perf_sampler_print函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_print
    // 描述: llama_perf_sampler_print函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_print
    // 描述: llama_perf_sampler_print函数提供相关功能
    // 参数: const struct llama_sampler * chain
    // 返回: 无返回值

    LLAMA_API void                           llama_perf_sampler_print(const struct llama_sampler * chain);
    // 函数: llama_perf_sampler_reset
    // 描述: llama_perf_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_reset
    // 描述: llama_perf_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_reset
    // 描述: llama_perf_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_reset
    // 描述: llama_perf_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_reset
    // 描述: llama_perf_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * chain
    // 返回: 无返回值

    // 函数: llama_perf_sampler_reset
    // 描述: llama_perf_sampler_reset函数提供相关功能
    // 参数: struct llama_sampler * chain
    // 返回: 无返回值

    LLAMA_API void                           llama_perf_sampler_reset(      struct llama_sampler * chain);

    // print a breakdown of per-device memory use via LLAMA_LOG:
    // 函数: llama_memory_breakdown_print
    // 描述: llama_memory_breakdown_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_memory_breakdown_print
    // 描述: llama_memory_breakdown_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_memory_breakdown_print
    // 描述: llama_memory_breakdown_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_memory_breakdown_print
    // 描述: llama_memory_breakdown_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_memory_breakdown_print
    // 描述: llama_memory_breakdown_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    // 函数: llama_memory_breakdown_print
    // 描述: llama_memory_breakdown_print函数提供相关功能
    // 参数: const struct llama_context * ctx
    // 返回: 无返回值

    LLAMA_API void llama_memory_breakdown_print(const struct llama_context * ctx);

    //
    // training
    //

    // function that returns whether or not a given tensor contains trainable parameters
    // 函数: bool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: bool
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    typedef bool (*llama_opt_param_filter)(const struct ggml_tensor * tensor, void * userdata);

    // always returns true
    // 函数: llama_opt_param_filter_all
    // 描述: llama_opt_param_filter_all函数提供相关功能
    // 参数: const struct ggml_tensor * tensor, void * userdata
    // 返回: 无返回值

    // 函数: llama_opt_param_filter_all
    // 描述: llama_opt_param_filter_all函数提供相关功能
    // 参数: const struct ggml_tensor * tensor, void * userdata
    // 返回: 无返回值

    // 函数: llama_opt_param_filter_all
    // 描述: llama_opt_param_filter_all函数提供相关功能
    // 参数: const struct ggml_tensor * tensor, void * userdata
    // 返回: 无返回值

    // 函数: llama_opt_param_filter_all
    // 描述: llama_opt_param_filter_all函数提供相关功能
    // 参数: const struct ggml_tensor * tensor, void * userdata
    // 返回: 无返回值

    // 函数: llama_opt_param_filter_all
    // 描述: llama_opt_param_filter_all函数提供相关功能
    // 参数: const struct ggml_tensor * tensor, void * userdata
    // 返回: 无返回值

    // 函数: llama_opt_param_filter_all
    // 描述: llama_opt_param_filter_all函数提供相关功能
    // 参数: const struct ggml_tensor * tensor, void * userdata
    // 返回: 无返回值

    LLAMA_API bool llama_opt_param_filter_all(const struct ggml_tensor * tensor, void * userdata);

    // 类: llama_opt_params
    // 描述: llama_opt_params类提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    // 类: llama_opt_params
    // 描述: llama_opt_params类提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    // 结构体: llama_opt_params
    // 描述: llama_opt_params结构体提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    // 结构体: llama_opt_params
    // 描述: llama_opt_params结构体提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    // 结构体: llama_opt_params
    // 描述: llama_opt_params结构体提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    // 结构体: llama_opt_params
    // 描述: llama_opt_params结构体提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    // 结构体: llama_opt_params
    // 描述: llama_opt_params结构体提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    // 结构体: llama_opt_params
    // 描述: llama_opt_params结构体提供相关功能
    // 用途: 用于处理llama_opt_params相关的操作
    struct llama_opt_params {
        uint32_t n_ctx_train; // assumed context size post training, use context size specified in llama_context if 0

        llama_opt_param_filter param_filter; // callback for determining which tensors contain trainable parameters
        void * param_filter_ud;              // userdata for determining which tensors contain trainable parameters

        ggml_opt_get_optimizer_params get_opt_pars; // callback for calculating optimizer parameters
        void * get_opt_pars_ud;                     // userdata for calculating optimizer parameters

        enum ggml_opt_optimizer_type optimizer_type;
    };

    // 函数: llama_opt_init
    // 描述: llama_opt_init函数提供相关功能
    // 参数: struct llama_context * lctx, struct llama_model * model, struct llama_opt_params lopt_params
    // 返回: 无返回值

    // 函数: llama_opt_init
    // 描述: llama_opt_init函数提供相关功能
    // 参数: struct llama_context * lctx, struct llama_model * model, struct llama_opt_params lopt_params
    // 返回: 无返回值

    // 函数: llama_opt_init
    // 描述: llama_opt_init函数提供相关功能
    // 参数: struct llama_context * lctx, struct llama_model * model, struct llama_opt_params lopt_params
    // 返回: 无返回值

    // 函数: llama_opt_init
    // 描述: llama_opt_init函数提供相关功能
    // 参数: struct llama_context * lctx, struct llama_model * model, struct llama_opt_params lopt_params
    // 返回: 无返回值

    // 函数: llama_opt_init
    // 描述: llama_opt_init函数提供相关功能
    // 参数: struct llama_context * lctx, struct llama_model * model, struct llama_opt_params lopt_params
    // 返回: 无返回值

    // 函数: llama_opt_init
    // 描述: llama_opt_init函数提供相关功能
    // 参数: struct llama_context * lctx, struct llama_model * model, struct llama_opt_params lopt_params
    // 返回: 无返回值

    LLAMA_API void llama_opt_init(struct llama_context * lctx, struct llama_model * model, struct llama_opt_params lopt_params);

    // 函数: llama_opt_epoch
    // 描述: llama_opt_epoch函数提供相关功能
    // 参数: // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 // 类: llama_context // 描述: llama_context类提供相关功能 // 用途: 用于处理llama_context相关的操作 struct llama_context    * lctx, ggml_opt_dataset_t        dataset, ggml_opt_result_t         result_train, ggml_opt_result_t         result_eval, int64_t                   idata_split, ggml_opt_epoch_callback   callback_train, ggml_opt_epoch_callback   callback_eval
    // 返回: 无返回值

    // 函数: llama_opt_epoch
    // 描述: llama_opt_epoch函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_opt_epoch
    // 描述: llama_opt_epoch函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_opt_epoch
    // 描述: llama_opt_epoch函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_opt_epoch
    // 描述: llama_opt_epoch函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    // 函数: llama_opt_epoch
    // 描述: llama_opt_epoch函数提供相关功能
    // 参数: 无参数
    // 返回: 无返回值

    LLAMA_API void llama_opt_epoch(