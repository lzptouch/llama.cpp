// 文件: common.h
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/common/common.h
// 描述: 通用工具函数和辅助功能定义
// 作用: 为整个项目提供通用的工具函数、数据结构和辅助功能
// 包含: 时间测量、CPU参数、采样参数、模型参数等通用组件

#pragma once

#include "ggml-opt.h"
#include "llama-cpp.h"

#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include <map>

#if defined(_WIN32) && !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0A00
#endif

#ifdef _WIN32
#define DIRECTORY_SEPARATOR '\\'
#else
#define DIRECTORY_SEPARATOR '/'
#endif // _WIN32

#define die(msg)          do { fputs("error: " msg "\n", stderr);                exit(1); } while (0)
#define die_fmt(fmt, ...) do { fprintf(stderr, "error: " fmt "\n", __VA_ARGS__); exit(1); } while (0)

#define print_build_info() do {                                                                     \
    fprintf(stderr, "%s: build = %d (%s)\n",      __func__, LLAMA_BUILD_NUMBER, LLAMA_COMMIT);      \
    fprintf(stderr, "%s: built with %s for %s\n", __func__, LLAMA_COMPILER, LLAMA_BUILD_TARGET);    \
} while(0)

// 结构体: common_time_meas
// 描述: 时间测量工具结构体
// 作用: 用于测量代码执行时间，自动累加时间到指定变量
// 成员:
//   - t_start_us: 开始时间（微秒）
//   - t_acc: 累加时间的引用
struct common_time_meas {
    // 构造函数: common_time_meas
    // 描述: 初始化时间测量
    // 参数:
    //   - t_acc: 用于累加时间的变量引用
    //   - disable: 是否禁用时间测量
    common_time_meas(int64_t & t_acc, bool disable = false);
    
    // 析构函数: ~common_time_meas
    // 描述: 结束时间测量并累加时间
    ~common_time_meas();

    const int64_t t_start_us; // 开始时间（微秒）
    int64_t & t_acc;          // 累加时间的引用
};

// 结构体: common_adapter_lora_info
// 描述: LoRA适配器信息结构体
// 作用: 存储LoRA适配器的配置信息和指针
// 成员:
//   - path: LoRA适配器文件路径
//   - scale: LoRA适配器缩放因子
//   - task_name: 任务名称
//   - prompt_prefix: 提示前缀
//   - ptr: LoRA适配器指针
struct common_adapter_lora_info {
    std::string path;           // LoRA适配器文件路径
    float scale;                // LoRA适配器缩放因子

    std::string task_name;      // 任务名称
    std::string prompt_prefix;  // 提示前缀

    struct llama_adapter_lora * ptr; // LoRA适配器指针
};

using llama_tokens = std::vector<llama_token>;

// build info
extern int LLAMA_BUILD_NUMBER;
extern const char * LLAMA_COMMIT;
extern const char * LLAMA_COMPILER;
extern const char * LLAMA_BUILD_TARGET;

const static std::string build_info("b" + std::to_string(LLAMA_BUILD_NUMBER) + "-" + LLAMA_COMMIT);

// 结构体: common_control_vector_load_info
// 描述: 控制向量加载信息结构体
// 作用: 存储控制向量的加载信息
// 成员:
//   - path: 控制向量文件路径
//   - scale: 控制向量缩放因子
struct common_control_vector_load_info;

//
// CPU utils
//

// 结构体: cpu_params
// 描述: CPU参数结构体
// 作用: 存储CPU相关的配置参数
// 成员:
//   - n_threads: 线程数
//   - cpumask: CPU亲和性掩码
//   - mask_valid: 掩码是否有效
//   - priority: 调度优先级
//   - strict_cpu: 是否使用严格的CPU放置
//   - poll: 轮询（忙等待）级别
struct cpu_params {
    int      n_threads                   = -1;     // 线程数
    bool     cpumask[GGML_MAX_N_THREADS] = {false}; // CPU亲和性掩码
    bool     mask_valid                  = false;   // 默认: 任何CPU
    enum ggml_sched_priority  priority   = GGML_SCHED_PRIO_NORMAL;  // 调度优先级: (0 - 正常, 1 - 中等, 2 - 高, 3 - 实时)
    bool     strict_cpu                  = false;   // 使用严格的CPU放置
    uint32_t poll                        = 50;      // 轮询（忙等待）级别 (0 - 无轮询, 100 - 主要轮询)
};

// 函数: cpu_get_num_physical_cores
// 描述: 获取物理CPU核心数
// 参数: 无
// 返回: 物理CPU核心数
int32_t cpu_get_num_physical_cores();

// 函数: cpu_get_num_math
// 描述: 获取数学核心数
// 参数: 无
// 返回: 数学核心数
int32_t cpu_get_num_math();

//
// Common params
//

enum llama_example {
    LLAMA_EXAMPLE_BATCHED,
    LLAMA_EXAMPLE_DEBUG,
    LLAMA_EXAMPLE_COMMON,
    LLAMA_EXAMPLE_SPECULATIVE,
    LLAMA_EXAMPLE_COMPLETION,
    LLAMA_EXAMPLE_CLI,
    LLAMA_EXAMPLE_EMBEDDING,
    LLAMA_EXAMPLE_PERPLEXITY,
    LLAMA_EXAMPLE_RETRIEVAL,
    LLAMA_EXAMPLE_PASSKEY,
    LLAMA_EXAMPLE_IMATRIX,
    LLAMA_EXAMPLE_BENCH,
    LLAMA_EXAMPLE_SERVER,
    LLAMA_EXAMPLE_CVECTOR_GENERATOR,
    LLAMA_EXAMPLE_EXPORT_LORA,
    LLAMA_EXAMPLE_MTMD,
    LLAMA_EXAMPLE_LOOKUP,
    LLAMA_EXAMPLE_PARALLEL,
    LLAMA_EXAMPLE_TTS,
    LLAMA_EXAMPLE_DIFFUSION,
    LLAMA_EXAMPLE_FINETUNE,
    LLAMA_EXAMPLE_FIT_PARAMS,

    LLAMA_EXAMPLE_COUNT,
};

enum common_sampler_type {
    COMMON_SAMPLER_TYPE_NONE        = 0,
    COMMON_SAMPLER_TYPE_DRY         = 1,
    COMMON_SAMPLER_TYPE_TOP_K       = 2,
    COMMON_SAMPLER_TYPE_TOP_P       = 3,
    COMMON_SAMPLER_TYPE_MIN_P       = 4,
  //COMMON_SAMPLER_TYPE_TFS_Z       = 5,
    COMMON_SAMPLER_TYPE_TYPICAL_P   = 6,
    COMMON_SAMPLER_TYPE_TEMPERATURE = 7,
    COMMON_SAMPLER_TYPE_XTC         = 8,
    COMMON_SAMPLER_TYPE_INFILL      = 9,
    COMMON_SAMPLER_TYPE_PENALTIES   = 10,
    COMMON_SAMPLER_TYPE_TOP_N_SIGMA = 11,
    COMMON_SAMPLER_TYPE_ADAPTIVE_P  = 12,
};

// dimensionality reduction methods, used by cvector-generator
enum dimre_method {
    DIMRE_METHOD_PCA,
    DIMRE_METHOD_MEAN,
};

enum common_conversation_mode {
    COMMON_CONVERSATION_MODE_DISABLED = 0,
    COMMON_CONVERSATION_MODE_ENABLED  = 1,
    COMMON_CONVERSATION_MODE_AUTO     = 2,
};

enum common_grammar_trigger_type {
    COMMON_GRAMMAR_TRIGGER_TYPE_TOKEN,
    COMMON_GRAMMAR_TRIGGER_TYPE_WORD,
    COMMON_GRAMMAR_TRIGGER_TYPE_PATTERN,
    COMMON_GRAMMAR_TRIGGER_TYPE_PATTERN_FULL,
};

// 结构体: common_grammar_trigger
// 描述: 语法触发器结构体
// 作用: 存储语法触发器的类型、值和令牌
// 成员:
//   - type: 触发器类型
//   - value: 触发器值
//   - token: 触发器令牌
struct common_grammar_trigger {
    common_grammar_trigger_type type; // 触发器类型
    std::string value;                // 触发器值
    llama_token token = LLAMA_TOKEN_NULL; // 触发器令牌
};

enum common_params_sampling_config : uint64_t {
    COMMON_PARAMS_SAMPLING_CONFIG_SAMPLERS        = 1 << 0,
    COMMON_PARAMS_SAMPLING_CONFIG_TOP_K           = 1 << 1,
    COMMON_PARAMS_SAMPLING_CONFIG_TOP_P           = 1 << 2,
    COMMON_PARAMS_SAMPLING_CONFIG_MIN_P           = 1 << 3,
    COMMON_PARAMS_SAMPLING_CONFIG_XTC_PROBABILITY = 1 << 4,
    COMMON_PARAMS_SAMPLING_CONFIG_XTC_THRESHOLD   = 1 << 5,
    COMMON_PARAMS_SAMPLING_CONFIG_TEMP            = 1 << 6,
    COMMON_PARAMS_SAMPLING_CONFIG_PENALTY_LAST_N  = 1 << 7,
    COMMON_PARAMS_SAMPLING_CONFIG_PENALTY_REPEAT  = 1 << 8,
    COMMON_PARAMS_SAMPLING_CONFIG_MIROSTAT        = 1 << 9,
    COMMON_PARAMS_SAMPLING_CONFIG_MIROSTAT_TAU    = 1 << 10,
    COMMON_PARAMS_SAMPLING_CONFIG_MIROSTAT_ETA    = 1 << 11,
};

enum common_speculative_type {
    COMMON_SPECULATIVE_TYPE_NONE,          // no speculative decoding
    COMMON_SPECULATIVE_TYPE_DRAFT,         // draft model
    COMMON_SPECULATIVE_TYPE_EAGLE3,        // eagle draft model
    COMMON_SPECULATIVE_TYPE_NGRAM_SIMPLE,  // simple self-speculative decoding
    COMMON_SPECULATIVE_TYPE_NGRAM_MAP_K,   // self-speculative decoding with n-gram keys only
    COMMON_SPECULATIVE_TYPE_NGRAM_MAP_K4V, // self-speculative decoding with n-gram keys and 4 m-gram values
    COMMON_SPECULATIVE_TYPE_NGRAM_MOD,
    COMMON_SPECULATIVE_TYPE_NGRAM_CACHE,   // self-speculative decoding with 3-level n-gram cache
    COMMON_SPECULATIVE_TYPE_COUNT          // number of types, unknown type
};

// sampling parameters
// 结构体: common_params_sampling
// 描述: 采样参数结构体
// 作用: 存储模型采样相关的配置参数
// 成员:
//   - seed: 随机种子
//   - n_prev: 要记住的前一个令牌数量
//   - n_probs: 输出前n个概率的令牌数
//   - min_keep: 采样器应返回的最小令牌数
//   - top_k: 顶部k个令牌
//   - top_p: 顶部p概率
//   - min_p: 最小p概率
//   - xtc_probability: XTC概率
//   - xtc_threshold: XTC阈值
//   - typ_p: 典型p值
//   - temp: 温度
//   - dynatemp_range: 动态温度范围
//   - dynatemp_exponent: 动态温度指数
//   - penalty_last_n: 惩罚的最后n个令牌
//   - penalty_repeat: 重复惩罚
//   - penalty_freq: 频率惩罚
//   - penalty_present: 存在惩罚
//   - dry_multiplier: DRY重复惩罚乘数
//   - dry_base: DRY重复惩罚基数
//   - dry_allowed_length: 允许的重复长度
//   - dry_penalty_last_n: DRY惩罚的最后n个令牌
//   - adaptive_target: 自适应目标概率
//   - adaptive_decay: 自适应衰减
//   - mirostat: Mirostat模式
//   - top_n_sigma: 顶部n sigma
//   - mirostat_tau: Mirostat目标熵
//   - mirostat_eta: Mirostat学习率
//   - ignore_eos: 是否忽略EOS令牌
//   - no_perf: 是否禁用性能指标
//   - timing_per_token: 是否按令牌计时
//   - user_sampling_config: 用户指定的采样器位域
//   - dry_sequence_breakers: DRY序列断路器
//   - samplers: 采样器列表
//   - grammar: 约束采样的BNF类语法
//   - grammar_lazy: 是否使用惰性语法
//   - grammar_triggers: 语法触发器
//   - preserved_tokens: 保留的令牌
//   - logit_bias: 应用的logit偏差
//   - logit_bias_eog: EOG令牌的预计算logit偏差
//   - backend_sampling: 是否使用后端采样
struct common_params_sampling {
    uint32_t seed = LLAMA_DEFAULT_SEED; // 用于初始化llama_sampler的种子

    int32_t n_prev             = 64;     // 要记住的前一个令牌数量
    int32_t n_probs            = 0;      // 如果大于0，输出前n_probs个令牌的概率
    int32_t min_keep           = 0;      // 0 = 禁用，否则采样器应返回至少min_keep个令牌
    int32_t top_k              = 40;     // <= 0 使用词汇表大小
    float   top_p              = 0.95f;  // 1.0 = 禁用
    float   min_p              = 0.05f;  // 0.0 = 禁用
    float   xtc_probability    = 0.00f;  // 0.0 = 禁用
    float   xtc_threshold      = 0.10f;  // > 0.5 禁用XTC
    float   typ_p              = 1.00f;  // typical_p, 1.0 = 禁用
    float   temp               = 0.80f;  // <= 0.0 贪婪采样，0.0 不输出概率
    float   dynatemp_range     = 0.00f;  // 0.0 = 禁用
    float   dynatemp_exponent  = 1.00f;  // 控制动态温度采样器中熵如何映射到温度
    int32_t penalty_last_n     = 64;     // 要惩罚的最后n个令牌 (0 = 禁用惩罚, -1 = 上下文大小)
    float   penalty_repeat     = 1.00f;  // 1.0 = 禁用
    float   penalty_freq       = 0.00f;  // 0.0 = 禁用
    float   penalty_present    = 0.00f;  // 0.0 = 禁用
    float   dry_multiplier     = 0.0f;   // 0.0 = 禁用; DRY重复惩罚，用于扩展重复的令牌
    float   dry_base           = 1.75f;  // 0.0 = 禁用; multiplier * base ^ (令牌前序列长度 - 允许长度)
    int32_t dry_allowed_length = 2;      // 超过此长度的重复会受到惩罚
    int32_t dry_penalty_last_n = -1;     // 扫描重复的令牌数 (0 = 禁用惩罚, -1 = 上下文大小)
    float   adaptive_target    = -1.0f;  // 选择接近此概率的令牌 (有效范围 0.0 到 1.0; 负值 = 禁用)
    float   adaptive_decay     = 0.90f;  // 自适应的EMA衰减; 历史 ≈ 1/(1-decay) 令牌 (0.0 - 0.99)
    int32_t mirostat           = 0;      // 0 = 禁用, 1 = mirostat, 2 = mirostat 2.0
    float   top_n_sigma        = -1.00f; // -1.0 = 禁用
    float   mirostat_tau       = 5.00f;  // 目标熵
    float   mirostat_eta       = 0.10f;  // 学习率
    bool    ignore_eos         = false;  // 是否忽略EOS令牌
    bool    no_perf            = false;  // 禁用性能指标
    bool    timing_per_token   = false;  // 是否按令牌计时

    uint64_t user_sampling_config = 0; // 跟踪用户指定采样器的位域

    std::vector<std::string> dry_sequence_breakers = {"\n", ":", "\"", "*"};     // DRY的默认序列断路器

    std::vector<enum common_sampler_type> samplers = {
        COMMON_SAMPLER_TYPE_PENALTIES,
        COMMON_SAMPLER_TYPE_DRY,
        COMMON_SAMPLER_TYPE_TOP_N_SIGMA,
        COMMON_SAMPLER_TYPE_TOP_K,
        COMMON_SAMPLER_TYPE_TYPICAL_P,
        COMMON_SAMPLER_TYPE_TOP_P,
        COMMON_SAMPLER_TYPE_MIN_P,
        COMMON_SAMPLER_TYPE_XTC,
        COMMON_SAMPLER_TYPE_TEMPERATURE,
    };

    std::string                         grammar; // 约束采样的可选BNF类语法
    bool                                grammar_lazy = false; // 是否使用惰性语法
    std::vector<common_grammar_trigger> grammar_triggers; // 可选触发器（用于惰性语法）
    std::set<llama_token>               preserved_tokens; // 保留的令牌

    std::vector<llama_logit_bias> logit_bias;     // 要应用的logit偏差
    std::vector<llama_logit_bias> logit_bias_eog; // EOG令牌的预计算logit偏差

    bool backend_sampling = false; // 是否使用后端采样

    // 函数: has_logit_bias
    // 描述: 检查是否有logit偏差
    // 参数: 无
    // 返回: 如果有logit偏差则返回true
    bool has_logit_bias() const {
        return !logit_bias.empty();
    }

    // 函数: print
    // 描述: 将参数打印到字符串
    // 参数: 无
    // 返回: 包含参数的字符串
    std::string print() const;
};

// 结构体: common_params_model
// 描述: 模型参数结构体
// 作用: 存储模型相关的配置参数
// 成员:
//   - path: 模型本地路径
//   - url: 模型下载URL
//   - hf_repo: Hugging Face仓库
//   - hf_file: Hugging Face文件
//   - docker_repo: Docker仓库
//   - name: 模型名称，格式为 <user>/<model>[:<tag>] (标签可选)
struct common_params_model {
    std::string path        = ""; // 模型本地路径                                       // NOLINT
    std::string url         = ""; // 模型下载URL                                  // NOLINT
    std::string hf_repo     = ""; // HF仓库                                                // NOLINT
    std::string hf_file     = ""; // HF文件                                                // NOLINT
    std::string docker_repo = ""; // Docker仓库                                            // NOLINT
    std::string name        = ""; // 格式为 <user>/<model>[:<tag>] (标签可选)     // NOLINT
};

// 结构体: common_ngram_mod
// 描述: ngram修改器结构体
// 作用: 用于ngram-based的推测解码
struct common_ngram_mod;

// 结构体: common_params_speculative
// 描述: 推测解码参数结构体
// 作用: 存储推测解码相关的配置参数
// 成员:
//   - type: 推测解码类型
//   - n_max: 推测解码期间要起草的最大令牌数
//   - n_min: 用于推测解码的最小草稿令牌数
//   - p_split: 推测解码分裂概率
//   - p_min: 最小推测解码概率（贪婪）
//   - ngram_size_n: 查找的ngram大小
//   - ngram_size_m: 推测令牌的mgram大小
//   - ngram_min_hits: mgram被提议所需的ngram/mgram查找的最小命中数
//   - ngram_mod: ngram修改器
//   - lookup_cache_static: 用于查找解码的静态ngram缓存文件路径
//   - lookup_cache_dynamic: 用于查找解码的动态ngram缓存文件路径
//   - mparams_dft: 草稿模型参数
//   - model_dft: 可由多个推测上下文共享的llama_model
//   - cparams_dft: 草稿llama_context的参数
//   - n_ctx: 草稿上下文大小
//   - n_gpu_layers: 存储在VRAM中的草稿模型层数
//   - cache_type_k: K的KV缓存数据类型
//   - cache_type_v: V的KV缓存数据类型
//   - cpuparams: CPU参数
//   - cpuparams_batch: 批处理CPU参数
//   - devices: 用于卸载的设备
//   - replacements: 主模型到推测模型的替换
//   - tensor_buft_overrides: 张量缓冲区类型覆盖
struct common_params_speculative {
    common_speculative_type type = COMMON_SPECULATIVE_TYPE_NONE; // 推测解码类型

    // 通用推测解码参数

    int32_t n_max   = 16; // 推测解码期间要起草的最大令牌数
    int32_t n_min   = 0; // 用于推测解码的最小草稿令牌数
    float   p_split = 0.1f; // 推测解码分裂概率
    float   p_min   = 0.75f; // 最小推测解码概率（贪婪）

    // 基于ngram的推测解码

    uint16_t ngram_size_n     = 12; // 查找的ngram大小
    uint16_t ngram_size_m     = 48; // 推测令牌的mgram大小
    uint16_t ngram_min_hits   =  1; // mgram被提议所需的ngram/mgram查找的最小命中数

    std::shared_ptr<common_ngram_mod> ngram_mod; // ngram修改器

    std::string lookup_cache_static;  // 用于查找解码的静态ngram缓存文件路径           // NOLINT
    std::string lookup_cache_dynamic; // 用于查找解码的动态ngram缓存文件路径          // NOLINT

    // 草稿模型推测解码

    struct common_params_model mparams_dft; // 草稿模型参数

    llama_model * model_dft = nullptr; // 可由多个推测上下文共享的llama_model

    llama_context_params cparams_dft; // 草稿llama_context的参数

    int32_t n_ctx        = 0;  // 草稿上下文大小
    int32_t n_gpu_layers = -1; // 存储在VRAM中的草稿模型层数 (-1 - 使用默认值)

    ggml_type cache_type_k = GGML_TYPE_F16; // K的KV缓存数据类型
    ggml_type cache_type_v = GGML_TYPE_F16; // V的KV缓存数据类型

    struct cpu_params cpuparams; // CPU参数
    struct cpu_params cpuparams_batch; // 批处理CPU参数

    std::vector<ggml_backend_dev_t> devices; // 用于卸载的设备

    std::vector<std::pair<std::string, std::string>> replacements; // 主模型到推测模型的替换
    std::vector<llama_model_tensor_buft_override> tensor_buft_overrides; // 张量缓冲区类型覆盖

    // 函数: has_dft
    // 描述: 检查是否有草稿模型
    // 参数: 无
    // 返回: 如果有草稿模型则返回true
    bool has_dft() const {
        return !mparams_dft.path.empty() || !mparams_dft.hf_repo.empty();
    }
};

// 结构体: common_params_vocoder
// 描述: 声码器参数结构体
// 作用: 存储声码器相关的配置参数
// 成员:
//   - model: 声码器模型参数
//   - speaker_file: 说话人文件路径
//   - use_guide_tokens: 是否启用引导令牌以提高TTS准确性
struct common_params_vocoder {
    struct common_params_model model; // 声码器模型参数

    std::string speaker_file = ""; // 说话人文件路径                                      // NOLINT

    bool use_guide_tokens = false; // 启用引导令牌以提高TTS准确性            // NOLINT
};

// 结构体: common_params_diffusion
// 描述: 扩散模型参数结构体
// 作用: 存储扩散模型相关的配置参数
// 成员:
//   - steps: 扩散步数
//   - visual_mode: 是否使用视觉模式
//   - eps: 时间步的epsilon值
//   - block_length: 生成的块长度
//   - algorithm: 算法类型，默认: low-confidence
//   - alg_temp: 算法温度
//   - cfg_scale: 无分类器引导尺度
//   - add_gumbel_noise: 如果temp > 0.0，是否向logits添加gumbel噪声
struct common_params_diffusion {
    int32_t steps         = 128;      // 扩散步数
    bool    visual_mode   = false;    // 是否使用视觉模式

    float   eps           = 0;        // 时间步的epsilon值
    int32_t block_length  = 0;        // 生成的块长度

    int32_t algorithm     = 4;        // 默认算法: low-confidence
    float   alg_temp      = 0.0f;     // 算法温度

    float   cfg_scale     = 0;        // 无分类器引导尺度
    bool    add_gumbel_noise = false; // 如果temp > 0.0，是否向logits添加gumbel噪声
};

// reasoning API response format (not to be confused as chat template's reasoning format)
// only used by server
enum common_reasoning_format {
    COMMON_REASONING_FORMAT_NONE,
    COMMON_REASONING_FORMAT_AUTO,            // Same as deepseek, using `message.reasoning_content`
    COMMON_REASONING_FORMAT_DEEPSEEK_LEGACY, // Extract thinking tag contents and return as `message.reasoning_content`, or leave inline in <think> tags in stream mode
    COMMON_REASONING_FORMAT_DEEPSEEK,        // Extract thinking tag contents and return as `message.reasoning_content`, including in streaming deltas.
    // do not extend this enum unless you absolutely have to
    // in most cases, use COMMON_REASONING_FORMAT_AUTO
    // see: https://github.com/ggml-org/llama.cpp/pull/15408
};


// 结构体: lr_opt
// 描述: 学习率优化器参数结构体
// 作用: 存储和管理学习率优化相关的参数
// 成员:
//   - lr0: 初始学习率
//   - lr_min: 最小学习率
//   - decay_epochs: 学习率衰减的轮数
//   - scale_epoch: 轮数缩放因子
//   - wd: 权重衰减
//   - epochs: 训练轮数
//   - epoch: 当前轮数
struct lr_opt {
    float    lr0          = 1e-5; // learning rate at first epoch
    float    lr_min       = -1;
    float    decay_epochs = -1;   // if >0, the learning rate starts at lr0 and decays to lr_min after this many epochs
    float    scale_epoch  = 0;
    float    wd           = 0;
    unsigned epochs       = 2;

    unsigned epoch; // set by optimizer outer (epochs) loop
    // learning rate decay - constant LR per epoch only for now
    // 函数: get_lr
    // 描述: 获取学习率
    // 参数: e - 轮数
    // 返回: 计算得到的学习率
    float get_lr(float e) const;
    // 函数: get_lr
    // 描述: 获取当前轮数的学习率
    // 参数: 无
    // 返回: 当前轮数的学习率
    float get_lr() const { return get_lr(epoch); }
    // must call after arg parse, before get_lr
    // 函数: init
    // 描述: 初始化学习率优化器
    // 参数: 无
    // 返回: 无
    void init();
};

// 类: ggml_opt_optimizer_params
// 描述: ggml_opt_optimizer_params类提供相关功能
// 用途: 用于处理ggml_opt_optimizer_params相关的操作
// 类: ggml_opt_optimizer_params
// 描述: ggml_opt_optimizer_params类提供相关功能
// 用途: 用于处理ggml_opt_optimizer_params相关的操作
    // 结构体: ggml_opt_optimizer_params
    // 描述: ggml_opt_optimizer_params结构体提供相关功能
    // 用途: 用于处理ggml_opt_optimizer_params相关的操作
    // 结构体: ggml_opt_optimizer_params
    // 描述: ggml_opt_optimizer_params结构体提供相关功能
    // 用途: 用于处理ggml_opt_optimizer_params相关的操作
    // 结构体: ggml_opt_optimizer_params
    // 描述: ggml_opt_optimizer_params结构体提供相关功能
    // 用途: 用于处理ggml_opt_optimizer_params相关的操作
    // 结构体: ggml_opt_optimizer_params
    // 描述: ggml_opt_optimizer_params结构体提供相关功能
    // 用途: 用于处理ggml_opt_optimizer_params相关的操作
struct ggml_opt_optimizer_params common_opt_lr_pars(void * userdata);

// 类: common_params
// 描述: common_params类提供相关功能
// 用途: 用于处理common_params相关的操作
// 类: common_params
// 描述: common_params类提供相关功能
// 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
struct common_params {
    int32_t n_predict             =    -1; // max. number of new tokens to predict, -1 == no limit
    int32_t n_ctx                 =     0; // context size, 0 == context the model was trained with
    int32_t n_batch               =  2048; // logical batch size for prompt processing (must be >=32 to use BLAS)
    int32_t n_ubatch              =   512; // physical batch size for prompt processing (must be >=32 to use BLAS)
    int32_t n_keep                =     0; // number of tokens to keep from initial prompt
    int32_t n_chunks              =    -1; // max number of chunks to process (-1 = unlimited)
    int32_t n_parallel            =     1; // number of parallel sequences to decode
    int32_t n_sequences           =     1; // number of sequences to decode
    int32_t grp_attn_n            =     1; // group-attention factor
    int32_t grp_attn_w            =   512; // group-attention width
    int32_t n_print               =    -1; // print token count every n tokens (-1 = disabled)
    float   rope_freq_base        =  0.0f; // RoPE base frequency
    float   rope_freq_scale       =  0.0f; // RoPE frequency scaling factor
    float   yarn_ext_factor       = -1.0f; // YaRN extrapolation mix factor
    float   yarn_attn_factor      = -1.0f; // YaRN magnitude scaling factor
    float   yarn_beta_fast        = -1.0f; // YaRN low correction dim
    float   yarn_beta_slow        = -1.0f; // YaRN high correction dim
    int32_t yarn_orig_ctx         =     0; // YaRN original context length

    // offload params
    std::vector<ggml_backend_dev_t> devices; // devices to use for offloading

    int32_t n_gpu_layers       = -1;   // number of layers to store in VRAM, -1 is auto, <= -2 is all
    int32_t main_gpu           = 0;    // the GPU that is used for scratch and small tensors
    float   tensor_split[128]  = {0};  // how split tensors should be distributed across GPUs
    bool    fit_params         = true; // whether to fit unset model/context parameters to free device memory
    int32_t fit_params_min_ctx = 4096; // minimum context size to set when trying to reduce memory use

    // margin per device in bytes for fitting parameters to free memory:
    std::vector<size_t> fit_params_target = std::vector<size_t>(llama_max_devices(), 1024 * 1024*1024);

    enum llama_split_mode split_mode = LLAMA_SPLIT_MODE_LAYER; // how to split the model across GPUs

    // 类: cpu_params
    // 描述: cpu_params类提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 类: cpu_params
    // 描述: cpu_params类提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    struct cpu_params cpuparams;
    // 类: cpu_params
    // 描述: cpu_params类提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 类: cpu_params
    // 描述: cpu_params类提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    // 结构体: cpu_params
    // 描述: cpu_params结构体提供相关功能
    // 用途: 用于处理cpu_params相关的操作
    struct cpu_params cpuparams_batch;

    ggml_backend_sched_eval_callback cb_eval = nullptr;
    void * cb_eval_user_data                 = nullptr;

    ggml_numa_strategy numa = GGML_NUMA_STRATEGY_DISABLED;

    enum llama_rope_scaling_type rope_scaling_type = LLAMA_ROPE_SCALING_TYPE_UNSPECIFIED;
    enum llama_pooling_type      pooling_type      = LLAMA_POOLING_TYPE_UNSPECIFIED; // pooling type for embeddings
    enum llama_attention_type    attention_type    = LLAMA_ATTENTION_TYPE_UNSPECIFIED; // attention type for embeddings
    enum llama_flash_attn_type   flash_attn_type   = LLAMA_FLASH_ATTN_TYPE_AUTO; // whether to use Flash Attention

    // 类: common_params_sampling
    // 描述: common_params_sampling类提供相关功能
    // 用途: 用于处理common_params_sampling相关的操作
    // 类: common_params_sampling
    // 描述: common_params_sampling类提供相关功能
    // 用途: 用于处理common_params_sampling相关的操作
    // 结构体: common_params_sampling
    // 描述: common_params_sampling结构体提供相关功能
    // 用途: 用于处理common_params_sampling相关的操作
    // 结构体: common_params_sampling
    // 描述: common_params_sampling结构体提供相关功能
    // 用途: 用于处理common_params_sampling相关的操作
    // 结构体: common_params_sampling
    // 描述: common_params_sampling结构体提供相关功能
    // 用途: 用于处理common_params_sampling相关的操作
    // 结构体: common_params_sampling
    // 描述: common_params_sampling结构体提供相关功能
    // 用途: 用于处理common_params_sampling相关的操作
    struct common_params_sampling    sampling;
    // 类: common_params_speculative
    // 描述: common_params_speculative类提供相关功能
    // 用途: 用于处理common_params_speculative相关的操作
    // 类: common_params_speculative
    // 描述: common_params_speculative类提供相关功能
    // 用途: 用于处理common_params_speculative相关的操作
    // 结构体: common_params_speculative
    // 描述: common_params_speculative结构体提供相关功能
    // 用途: 用于处理common_params_speculative相关的操作
    // 结构体: common_params_speculative
    // 描述: common_params_speculative结构体提供相关功能
    // 用途: 用于处理common_params_speculative相关的操作
    // 结构体: common_params_speculative
    // 描述: common_params_speculative结构体提供相关功能
    // 用途: 用于处理common_params_speculative相关的操作
    // 结构体: common_params_speculative
    // 描述: common_params_speculative结构体提供相关功能
    // 用途: 用于处理common_params_speculative相关的操作
    struct common_params_speculative speculative;
    // 类: common_params_vocoder
    // 描述: common_params_vocoder类提供相关功能
    // 用途: 用于处理common_params_vocoder相关的操作
    // 类: common_params_vocoder
    // 描述: common_params_vocoder类提供相关功能
    // 用途: 用于处理common_params_vocoder相关的操作
    // 结构体: common_params_vocoder
    // 描述: common_params_vocoder结构体提供相关功能
    // 用途: 用于处理common_params_vocoder相关的操作
    // 结构体: common_params_vocoder
    // 描述: common_params_vocoder结构体提供相关功能
    // 用途: 用于处理common_params_vocoder相关的操作
    // 结构体: common_params_vocoder
    // 描述: common_params_vocoder结构体提供相关功能
    // 用途: 用于处理common_params_vocoder相关的操作
    // 结构体: common_params_vocoder
    // 描述: common_params_vocoder结构体提供相关功能
    // 用途: 用于处理common_params_vocoder相关的操作
    struct common_params_vocoder     vocoder;
    // 类: common_params_diffusion
    // 描述: common_params_diffusion类提供相关功能
    // 用途: 用于处理common_params_diffusion相关的操作
    // 类: common_params_diffusion
    // 描述: common_params_diffusion类提供相关功能
    // 用途: 用于处理common_params_diffusion相关的操作
    // 结构体: common_params_diffusion
    // 描述: common_params_diffusion结构体提供相关功能
    // 用途: 用于处理common_params_diffusion相关的操作
    // 结构体: common_params_diffusion
    // 描述: common_params_diffusion结构体提供相关功能
    // 用途: 用于处理common_params_diffusion相关的操作
    // 结构体: common_params_diffusion
    // 描述: common_params_diffusion结构体提供相关功能
    // 用途: 用于处理common_params_diffusion相关的操作
    // 结构体: common_params_diffusion
    // 描述: common_params_diffusion结构体提供相关功能
    // 用途: 用于处理common_params_diffusion相关的操作
    struct common_params_diffusion   diffusion;

    // 类: common_params_model
    // 描述: common_params_model类提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 类: common_params_model
    // 描述: common_params_model类提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    struct common_params_model model;

    std::set<std::string> model_alias;     // model aliases                                                 // NOLINT
    std::set<std::string> model_tags;      // model tags (informational, not used for routing)              // NOLINT
    std::string hf_token             = ""; // HF token                                                      // NOLINT
    std::string prompt               = "";                                                                  // NOLINT
    std::string system_prompt        = "";                                                                  // NOLINT
    std::string prompt_file          = ""; // store the external prompt file name                           // NOLINT
    std::string path_prompt_cache    = ""; // path to file for saving/loading prompt eval state             // NOLINT
    std::string input_prefix         = ""; // string to prefix user inputs with                             // NOLINT
    std::string input_suffix         = ""; // string to suffix user inputs with                             // NOLINT
    std::string logits_file          = ""; // file for saving *all* logits                                  // NOLINT

    // llama-debug specific options
    std::string logits_output_dir = "data"; // directory for saving logits output files                     // NOLINT
    bool        save_logits       = false;  // whether to save logits to files                              // NOLINT
    std::vector<std::string> tensor_filter; // filter tensor names for debug output (regex)                 // NOLINT

    std::vector<std::string> in_files;   // all input files
    std::vector<std::string> antiprompt; // strings upon which more user input is prompted (a.k.a. reverse prompts)
    std::vector<llama_model_kv_override> kv_overrides;
    std::vector<llama_model_tensor_buft_override> tensor_buft_overrides;

    bool lora_init_without_apply = false; // only load lora to memory, but do not apply it to ctx (user can manually apply lora later using llama_adapter_lora_apply)
    std::vector<common_adapter_lora_info> lora_adapters; // lora adapter path with user defined scale

    std::vector<common_control_vector_load_info> control_vectors; // control vector with user defined scale

    int32_t verbosity                  = 3;  // LOG_LEVEL_INFO
    int32_t control_vector_layer_start = -1; // layer range for control vector
    int32_t control_vector_layer_end   = -1; // layer range for control vector
    bool    offline                    = false;

    int32_t ppl_stride      = 0;     // stride for perplexity calculations. If left at 0, the pre-existing approach will be used.
    int32_t ppl_output_type = 0;     // = 0 -> ppl output is as usual, = 1 -> ppl output is num_tokens, ppl, one per line
                                     //                                       (which is more convenient to use for plotting)
                                     //
    bool   hellaswag        = false; // compute HellaSwag score over random tasks from datafile supplied in prompt
    size_t hellaswag_tasks  = 400;   // number of tasks to use when computing the HellaSwag score

    bool   winogrande       = false; // compute Winogrande score over random tasks from datafile supplied in prompt
    size_t winogrande_tasks = 0;     // number of tasks to use when computing the Winogrande score. If 0, all tasks will be computed

    bool   multiple_choice  = false;  // compute TruthfulQA score over random tasks from datafile supplied in prompt
    size_t multiple_choice_tasks = 0; // number of tasks to use when computing the TruthfulQA score. If 0, all tasks will be computed

    bool   kl_divergence    = false; // compute KL divergence

    bool usage             = false; // print usage
    bool completion        = false; // print source-able completion script
    bool use_color         = false; // use color to distinguish generations and inputs
    bool special           = false; // enable special token output
    bool interactive       = false; // interactive mode
    bool interactive_first = false; // wait for user input immediately
    bool prompt_cache_all  = false; // save user input and generations to prompt cache
    bool prompt_cache_ro   = false; // open the prompt cache read-only and do not update it

    bool escape            = true;  // escape "\n", "\r", "\t", "\'", "\"", and "\\"
    bool multiline_input   = false; // reverse the usage of `\`
    bool simple_io         = false; // improves compatibility with subprocesses and limited consoles
    bool cont_batching     = true;  // insert new sequences for decoding on-the-fly
    bool no_perf           = false; // disable performance metrics
    bool show_timings      = true;  // show timing information on CLI
    bool ctx_shift         = false; // context shift on infinite text generation
    bool swa_full          = false; // use full-size SWA cache (https://github.com/ggml-org/llama.cpp/pull/13194#issuecomment-2868343055)
    bool kv_unified        = false; // enable unified KV cache

    bool input_prefix_bos  = false; // prefix BOS to user inputs, preceding input_prefix
    bool use_mmap          = true;  // enable mmap to use filesystem cache
    bool use_direct_io     = false; // read from disk without buffering
    bool use_mlock         = false; // use mlock to keep model in memory
    bool verbose_prompt    = false; // print prompt tokens before generation
    bool display_prompt    = true;  // print prompt before generation
    bool no_kv_offload     = false; // disable KV offloading
    bool warmup            = true;  // warmup run
    bool check_tensors     = false; // validate tensor data
    bool no_op_offload     = false; // globally disable offload host tensor operations to device
    bool no_extra_bufts    = false; // disable extra buffer types (used for weight repacking)
    bool no_host           = false; // bypass host buffer allowing extra buffers to be used

    bool single_turn       = false; // single turn chat conversation

    ggml_type cache_type_k = GGML_TYPE_F16; // KV cache data type for the K
    ggml_type cache_type_v = GGML_TYPE_F16; // KV cache data type for the V

    common_conversation_mode conversation_mode = COMMON_CONVERSATION_MODE_AUTO;

    // multimodal models (see tools/mtmd)
    // 类: common_params_model
    // 描述: common_params_model类提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 类: common_params_model
    // 描述: common_params_model类提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    struct common_params_model mmproj;
    bool mmproj_use_gpu = true;     // use GPU for multimodal model
    bool no_mmproj = false;         // explicitly disable multimodal model
    std::vector<std::string> image; // path to image file(s)
    int image_min_tokens = -1;
    int image_max_tokens = -1;

    // finetune
    // 类: lr_opt
    // 描述: lr_opt类提供相关功能
    // 用途: 用于处理lr_opt相关的操作
    // 类: lr_opt
    // 描述: lr_opt类提供相关功能
    // 用途: 用于处理lr_opt相关的操作
    // 结构体: lr_opt
    // 描述: lr_opt结构体提供相关功能
    // 用途: 用于处理lr_opt相关的操作
    // 结构体: lr_opt
    // 描述: lr_opt结构体提供相关功能
    // 用途: 用于处理lr_opt相关的操作
    // 结构体: lr_opt
    // 描述: lr_opt结构体提供相关功能
    // 用途: 用于处理lr_opt相关的操作
    // 结构体: lr_opt
    // 描述: lr_opt结构体提供相关功能
    // 用途: 用于处理lr_opt相关的操作
    struct lr_opt lr;
    enum ggml_opt_optimizer_type optimizer = GGML_OPT_OPTIMIZER_TYPE_ADAMW;
    float val_split = 0.05f; // fraction of the data used for the validation set

    // embedding
    bool embedding         = false; // get only sentence embedding
    int32_t embd_normalize = 2;     // normalisation for embeddings (-1=none, 0=max absolute int16, 1=taxicab, 2=euclidean, >2=p-norm)
    std::string embd_out   = "";    // empty = default, "array" = [[],[]...], "json" = openai style, "json+" = same "json" + cosine similarity matrix
    std::string embd_sep   = "\n";  // separator of embeddings
    std::string cls_sep    = "\t";  // separator of classification sequences

    // server params
    int32_t port              = 8080;         // server listens on this network port
    int32_t timeout_read      = 600;          // http read timeout in seconds
    int32_t timeout_write     = timeout_read; // http write timeout in seconds
    int32_t n_threads_http    = -1;           // number of threads to process HTTP requests (TODO: support threadpool)
    int32_t n_cache_reuse     = 0;            // min chunk size to reuse from the cache via KV shifting
    bool    cache_prompt      = true;         // whether to enable prompt caching
    int32_t n_ctx_checkpoints = 8;            // max number of context checkpoints per slot
    int32_t cache_ram_mib     = 8192;         // -1 = no limit, 0 - disable, 1 = 1 MiB, etc.

    std::string hostname      = "127.0.0.1";
    std::string public_path   = "";                                                                         // NOLINT
    std::string api_prefix    = "";                                                                         // NOLINT
    std::string chat_template = "";                                                                         // NOLINT
    bool use_jinja = true;                                                                                  // NOLINT
    bool enable_chat_template = true;
    common_reasoning_format reasoning_format = COMMON_REASONING_FORMAT_DEEPSEEK;
    int reasoning_budget = -1;
    bool prefill_assistant = true; // if true, any trailing assistant message will be prefilled into the response
    int sleep_idle_seconds = -1;   // if >0, server will sleep after this many seconds of idle time

    std::vector<std::string> api_keys;

    std::string ssl_file_key  = "";                                                                         // NOLINT
    std::string ssl_file_cert = "";                                                                         // NOLINT

    std::map<std::string, std::string> default_template_kwargs;

    // webui configs
    bool webui = true;
    std::string webui_config_json;

    // "advanced" endpoints are disabled by default for better security
    bool endpoint_slots   = true;
    bool endpoint_props   = false; // only control POST requests, not GET
    bool endpoint_metrics = false;

    // router server configs
    std::string models_dir    = ""; // directory containing models for the router server
    std::string models_preset = ""; // directory containing model presets for the router server
    int models_max = 4;             // maximum number of models to load simultaneously
    bool models_autoload = true;    // automatically load models when requested via the router server

    bool log_json = false;

    std::string slot_save_path;
    std::string media_path; // path to directory for loading media files

    float slot_prompt_similarity = 0.1f;

    // batched-bench params
    bool is_pp_shared   = false;
    bool is_tg_separate = false;

    std::vector<int32_t> n_pp;
    std::vector<int32_t> n_tg;
    std::vector<int32_t> n_pl;

    // retrieval params
    std::vector<std::string> context_files; // context files to embed

    int32_t chunk_size = 64; // chunk size for context embedding

    std::string chunk_separator = "\n"; // chunk separator for context embedding

    // passkey params
    int32_t n_junk = 250; // number of times to repeat the junk text
    int32_t i_pos  = -1;  // position of the passkey in the junk text

    // imatrix params
    int32_t n_out_freq  = 10; // output the imatrix every n_out_freq iterations
    int32_t n_save_freq =  0; // save the imatrix every n_save_freq iterations
    int32_t i_chunk     =  0; // start processing from this chunk
    int8_t  imat_dat    =  0; // whether the legacy imatrix.dat format should be output (gguf <= 0 < dat)

    bool process_output  = false; // collect data for the output tensor
    bool compute_ppl     = true;  // whether to compute perplexity
    bool show_statistics = false; // show imatrix statistics per tensor
    bool parse_special   = false; // whether to parse special tokens during imatrix tokenization

    // cvector-generator params
    int n_pca_batch = 100;
    int n_pca_iterations = 1000;
    dimre_method cvector_dimre_method = DIMRE_METHOD_PCA;
    std::string cvector_positive_file = "tools/cvector-generator/positive.txt";
    std::string cvector_negative_file = "tools/cvector-generator/negative.txt";

    bool spm_infill = false; // suffix/prefix/middle pattern for infill

    // batched-bench params
    bool batched_bench_output_jsonl = false;

    // common params
    std::string out_file; // output filename for all example programs
    // optional callback for model loading progress and cancellation:
    // called with a progress value between 0.0 and 1.0.
    // return false from callback to abort model loading or true to continue
    llama_progress_callback load_progress_callback = NULL;
    void *                  load_progress_callback_user_data = NULL;
};

// call once at the start of a program if it uses libcommon
// initializes the logging system and prints info about the build
// 函数: common_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: common_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
void common_init();

// 函数: common_params_get_system_info
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: common_params_get_system_info
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
std::string common_params_get_system_info(const common_params & params);

// 函数: parse_cpu_range
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: parse_cpu_range
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool parse_cpu_range(const std::string & range, bool(&boolmask)[GGML_MAX_N_THREADS]);
// 函数: parse_cpu_mask
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: parse_cpu_mask
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool parse_cpu_mask(const std::string & mask, bool(&boolmask)[GGML_MAX_N_THREADS]);
// 函数: postprocess_cpu_params
// 描述: 处理: 处理输入数据或执行计算操作
// 参数: 无参数
// 返回: 无返回值
// 函数: postprocess_cpu_params
// 描述: 处理: 处理输入数据或执行计算操作
// 参数: 无参数
// 返回: 无返回值
void postprocess_cpu_params(cpu_params & cpuparams, const cpu_params * role_model = nullptr);
// 函数: set_process_priority
// 描述: 设置: 设置某个属性或配置
// 参数: 设置参数和值
// 返回: 无返回值
// 函数: set_process_priority
// 描述: 设置: 设置某个属性或配置
// 参数: 设置参数和值
// 返回: 无返回值
bool set_process_priority(enum ggml_sched_priority prio);

//
// String utils
//

#ifdef __GNUC__
#    if defined(__MINGW32__) && !defined(__clang__)
#        define LLAMA_COMMON_ATTRIBUTE_FORMAT(...) __attribute__((format(gnu_printf, __VA_ARGS__)))
#    else
#        define LLAMA_COMMON_ATTRIBUTE_FORMAT(...) __attribute__((format(printf, __VA_ARGS__)))
#    endif
#else
#    define LLAMA_COMMON_ATTRIBUTE_FORMAT(...)
#endif

LLAMA_COMMON_ATTRIBUTE_FORMAT(1, 2)
// 函数: string_format
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_format
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_format(const char * fmt, ...);

// 函数: string_strip
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_strip
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_strip(const std::string & str);
// 函数: string_get_sortable_timestamp
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: string_get_sortable_timestamp
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
std::string string_get_sortable_timestamp();

// 函数: string_join
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_join
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_join(const std::vector<std::string> & values, const std::string & separator);
std::vector<std::string> string_split(const std::string & str, const std::string & delimiter);
// 函数: string_repeat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_repeat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_repeat(const std::string & str, size_t n);

// 函数: string_replace_all
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_replace_all
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void string_replace_all(std::string & s, const std::string & search, const std::string & replace);

// 函数: regex_escape
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: regex_escape
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string regex_escape(const std::string & s);

template<class T>
static std::vector<T> string_split(const std::string & str, char delim) {
    static_assert(!std::is_same<T, std::string>::value, "Please use the specialized version for std::string");
    std::vector<T> values;
    // 函数: str_stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: str_stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::istringstream str_stream(str);
    std::string token;
    while (std::getline(str_stream, token, delim)) {
        T value;
        // 函数: token_stream
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: token_stream
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        std::istringstream token_stream(token);
        token_stream >> value;
        values.push_back(value);
    }
    return values;
}

template<>
inline std::vector<std::string> string_split<std::string>(const std::string & str, char delim)
{
    std::vector<std::string> parts;
    size_t begin_pos = 0;
    size_t delim_pos = str.find(delim);
    while (delim_pos != std::string::npos) {
        std::string part = str.substr(begin_pos, delim_pos - begin_pos);
        parts.emplace_back(part);
        begin_pos = delim_pos + 1;
        delim_pos = str.find(delim, begin_pos);
    }
    parts.emplace_back(str.substr(begin_pos));
    return parts;
}

// remove when moving to c++20
// 函数: string_starts_with
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_starts_with
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
inline bool string_starts_with(std::string_view str, std::string_view prefix) {
    return str.size() >= prefix.size() &&
           str.compare(0, prefix.size(), prefix) == 0;
}

// remove when moving to c++20
// 函数: string_ends_with
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_ends_with
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
inline bool string_ends_with(std::string_view str, std::string_view suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

// 函数: string_remove_suffix
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_remove_suffix
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
inline bool string_remove_suffix(std::string & str, std::string_view suffix) {
    if (string_ends_with(str, suffix)) {
        str.resize(str.size() - suffix.size());
        return true;
    }
    return false;
}

// 函数: string_find_partial_stop
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_find_partial_stop
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
inline size_t string_find_partial_stop(std::string_view str, std::string_view stop) {
    if (!str.empty() && !stop.empty()) {
        const size_t max_len = std::min(str.size(), stop.size());
        const char last_char = str.back();
        for (size_t len = max_len; len > 0; --len) {
            if (stop[len - 1] == last_char) {
                if (string_ends_with(str, stop.substr(0, len))) {
                    return str.size() - len;
                }
            }
        }
    }
    return std::string::npos;
}

// 函数: string_parse_kv_override
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_parse_kv_override
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool string_parse_kv_override(const char * data, std::vector<llama_model_kv_override> & overrides);
// 函数: string_process_escapes
// 描述: 处理: 处理输入数据或执行计算操作
// 参数: 无参数
// 返回: 无返回值
// 函数: string_process_escapes
// 描述: 处理: 处理输入数据或执行计算操作
// 参数: 无参数
// 返回: 无返回值
void string_process_escapes(std::string & input);

// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_from(bool value);
// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_from(const std::vector<int> & values);
// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_from(const struct llama_context * ctx, const std::vector<llama_token> & tokens);
// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: string_from
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string string_from(const struct llama_context * ctx, const struct llama_batch & batch);

//
// Filesystem utils
//

// 函数: fs_validate_filename
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: fs_validate_filename
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool fs_validate_filename(const std::string & filename, bool allow_subdirs = false);
// 函数: fs_create_directory_with_parents
// 描述: 创建: 创建新的对象或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: fs_create_directory_with_parents
// 描述: 创建: 创建新的对象或资源
// 参数: 无参数
// 返回: 无返回值
bool fs_create_directory_with_parents(const std::string & path);
// 函数: fs_is_directory
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: fs_is_directory
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool fs_is_directory(const std::string & path);

// 函数: fs_get_cache_directory
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: fs_get_cache_directory
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
std::string fs_get_cache_directory();
// 函数: fs_get_cache_file
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: fs_get_cache_file
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
std::string fs_get_cache_file(const std::string & filename);

// 类: common_file_info
// 描述: common_file_info类提供相关功能
// 用途: 用于处理common_file_info相关的操作
// 类: common_file_info
// 描述: common_file_info类提供相关功能
// 用途: 用于处理common_file_info相关的操作
    // 结构体: common_file_info
    // 描述: common_file_info结构体提供相关功能
    // 用途: 用于处理common_file_info相关的操作
    // 结构体: common_file_info
    // 描述: common_file_info结构体提供相关功能
    // 用途: 用于处理common_file_info相关的操作
    // 结构体: common_file_info
    // 描述: common_file_info结构体提供相关功能
    // 用途: 用于处理common_file_info相关的操作
    // 结构体: common_file_info
    // 描述: common_file_info结构体提供相关功能
    // 用途: 用于处理common_file_info相关的操作
struct common_file_info {
    std::string path;
    std::string name;
    size_t      size = 0; // in bytes
    bool        is_dir = false;
};
std::vector<common_file_info> fs_list(const std::string & path, bool include_directories);

//
// TTY utils
//

// Auto-detect if colors can be enabled based on terminal and environment
// 函数: tty_can_use_colors
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: tty_can_use_colors
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool tty_can_use_colors();

//
// Model utils
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

// note: defines the model, context, samplers, ets. lifetimes
// 类: common_init_result
// 描述: common_init_result类提供相关功能
// 用途: 用于处理common_init_result相关的操作
// 类: common_init_result
// 描述: common_init_result类提供相关功能
// 用途: 用于处理common_init_result相关的操作
    // 结构体: common_init_result
    // 描述: common_init_result结构体提供相关功能
    // 用途: 用于处理common_init_result相关的操作
    // 结构体: common_init_result
    // 描述: common_init_result结构体提供相关功能
    // 用途: 用于处理common_init_result相关的操作
    // 结构体: common_init_result
    // 描述: common_init_result结构体提供相关功能
    // 用途: 用于处理common_init_result相关的操作
    // 结构体: common_init_result
    // 描述: common_init_result结构体提供相关功能
    // 用途: 用于处理common_init_result相关的操作
struct common_init_result {
    common_init_result(common_params & params);
    ~common_init_result();

    // 函数: model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_model * model();
    // 函数: context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_context * context();

    // 函数: sampler
    // 描述: 采样: 从概率分布中采样
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: sampler
    // 描述: 采样: 从概率分布中采样
    // 参数: 无参数
    // 返回: 无返回值
    common_sampler * sampler(llama_seq_id seq_id);
    // 函数: reset_samplers
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: reset_samplers
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    void reset_samplers();

    std::vector<llama_adapter_lora_ptr> & lora();

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

using common_init_result_ptr = std::unique_ptr<common_init_result>;

// 函数: common_init_from_params
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: common_init_from_params
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
common_init_result_ptr common_init_from_params(common_params & params);

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
struct llama_model_params     common_model_params_to_llama  (      common_params & params);
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
struct llama_context_params   common_context_params_to_llama(const common_params & params);
// 类: ggml_threadpool_params
// 描述: ggml_threadpool_params类提供相关功能
// 用途: 用于处理ggml_threadpool_params相关的操作
// 类: ggml_threadpool_params
// 描述: ggml_threadpool_params类提供相关功能
// 用途: 用于处理ggml_threadpool_params相关的操作
    // 结构体: ggml_threadpool_params
    // 描述: ggml_threadpool_params结构体提供相关功能
    // 用途: 用于处理ggml_threadpool_params相关的操作
    // 结构体: ggml_threadpool_params
    // 描述: ggml_threadpool_params结构体提供相关功能
    // 用途: 用于处理ggml_threadpool_params相关的操作
    // 结构体: ggml_threadpool_params
    // 描述: ggml_threadpool_params结构体提供相关功能
    // 用途: 用于处理ggml_threadpool_params相关的操作
    // 结构体: ggml_threadpool_params
    // 描述: ggml_threadpool_params结构体提供相关功能
    // 用途: 用于处理ggml_threadpool_params相关的操作
struct ggml_threadpool_params ggml_threadpool_params_from_cpu_params(const cpu_params & params);

// clear LoRA adapters from context, then apply new list of adapters
// 函数: common_set_adapter_lora
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: common_set_adapter_lora
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void common_set_adapter_lora(struct llama_context * ctx, std::vector<common_adapter_lora_info> & lora);

// 函数: get_model_endpoint
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
// 函数: get_model_endpoint
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
std::string                   get_model_endpoint();

//
// Batch utils
//

// 函数: common_batch_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: common_batch_clear
// 描述: 清空: 清空数据或资源
// 参数: 无参数
// 返回: 无返回值
void common_batch_clear(struct llama_batch & batch);

void common_batch_add(
                 // 类: llama_batch
                 // 描述: llama_batch类提供相关功能
                 // 用途: 用于处理llama_batch相关的操作
                 // 类: llama_batch
                 // 描述: llama_batch类提供相关功能
                 // 用途: 用于处理llama_batch相关的操作
    // 结构体: llama_batch
    // 描述: llama_batch结构体提供相关功能
    // 用途: 用于处理llama_batch相关的操作
    // 结构体: llama_batch
    // 描述: llama_batch结构体提供相关功能
    // 用途: 用于处理llama_batch相关的操作
    // 结构体: llama_batch
    // 描述: llama_batch结构体提供相关功能
    // 用途: 用于处理llama_batch相关的操作
    // 结构体: llama_batch
    // 描述: llama_batch结构体提供相关功能
    // 用途: 用于处理llama_batch相关的操作
                 struct llama_batch & batch,
                        llama_token   id,
                          llama_pos   pos,
    const std::vector<llama_seq_id> & seq_ids,
                               bool   logits);

// decodes a single batch of tokens for a prompt and manages session tokens
//
// Note: We save state before the last token so that we can replay it to ensure
// compatibility with all memory types. Recurrent/hybrid models cannot remove
// tokens from memory, so this approach works across all model architectures.
bool common_prompt_batch_decode(
              // 类: llama_context
              // 描述: llama_context类提供相关功能
              // 用途: 用于处理llama_context相关的操作
              // 类: llama_context
              // 描述: llama_context类提供相关功能
              // 用途: 用于处理llama_context相关的操作
    // 结构体: llama_context
    // 描述: llama_context结构体提供相关功能
    // 用途: 用于处理llama_context相关的操作
    // 结构体: llama_context
    // 描述: llama_context结构体提供相关功能
    // 用途: 用于处理llama_context相关的操作
    // 结构体: llama_context
    // 描述: llama_context结构体提供相关功能
    // 用途: 用于处理llama_context相关的操作
    // 结构体: llama_context
    // 描述: llama_context结构体提供相关功能
    // 用途: 用于处理llama_context相关的操作
              struct llama_context * ctx,
    const std::vector<llama_token> & embd,
                               int & n_past,
                               int   n_batch,
                  std::string_view   state_path,
                              bool   save_state);

// replays the last token after loading state to regenerate logits
// used after loading session state to ensure the sampling context has valid logits
// 函数: common_replay_last_token
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_replay_last_token
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool common_replay_last_token(struct llama_context * ctx, llama_token last_token, int32_t pos);

//
// Vocab utils
//

// tokenizes a string into a vector of tokens
// should work similar to Python's `tokenizer.encode`
std::vector<llama_token> common_tokenize(
  const struct llama_context * ctx,
           const std::string & text,
                        bool   add_special,
                        bool   parse_special = false);

std::vector<llama_token> common_tokenize(
    const struct llama_vocab * vocab,
           const std::string & text,
                        bool   add_special,
                        bool   parse_special = false);

// tokenizes a token into a piece, optionally renders special/control tokens
// should work similar to Python's `tokenizer.id_to_piece`
std::string common_token_to_piece(
        const struct llama_context * ctx,
                       llama_token   token,
                       bool          special = true);

std::string common_token_to_piece(
          const struct llama_vocab * vocab,
                       llama_token   token,
                       bool          special = true);

// detokenizes a vector of tokens into a string
// should work similar to Python's `tokenizer.decode`
// optionally renders special/control tokens
std::string common_detokenize(
            const struct llama_context * ctx,
        const std::vector<llama_token> & tokens,
                                  bool   special = true);

std::string common_detokenize(
              const struct llama_vocab * vocab,
        const std::vector<llama_token> & tokens,
                                  bool   special = true);

//
// Embedding utils
//

// TODO: repace embd_norm with an enum
// 函数: common_embd_normalize
// 描述: 归一化: 归一化数据
// 参数: 无参数
// 返回: 无返回值
// 函数: common_embd_normalize
// 描述: 归一化: 归一化数据
// 参数: 无参数
// 返回: 无返回值
void common_embd_normalize(const float * inp, float * out, int n, int embd_norm);

// 函数: common_embd_similarity_cos
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_embd_similarity_cos
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
float common_embd_similarity_cos(const float * embd1, const float * embd2, int n);

//
// Control vector utils
//

// 类: common_control_vector_data
// 描述: common_control_vector_data类提供相关功能
// 用途: 用于处理common_control_vector_data相关的操作
// 类: common_control_vector_data
// 描述: common_control_vector_data类提供相关功能
// 用途: 用于处理common_control_vector_data相关的操作
    // 结构体: common_control_vector_data
    // 描述: common_control_vector_data结构体提供相关功能
    // 用途: 用于处理common_control_vector_data相关的操作
    // 结构体: common_control_vector_data
    // 描述: common_control_vector_data结构体提供相关功能
    // 用途: 用于处理common_control_vector_data相关的操作
    // 结构体: common_control_vector_data
    // 描述: common_control_vector_data结构体提供相关功能
    // 用途: 用于处理common_control_vector_data相关的操作
    // 结构体: common_control_vector_data
    // 描述: common_control_vector_data结构体提供相关功能
    // 用途: 用于处理common_control_vector_data相关的操作
struct common_control_vector_data {
    int n_embd;

    // stores data for layers [1, n_layer] where n_layer = data.size() / n_embd
    std::vector<float> data;
};

// 类: common_control_vector_load_info
// 描述: common_control_vector_load_info类提供相关功能
// 用途: 用于处理common_control_vector_load_info相关的操作
// 类: common_control_vector_load_info
// 描述: common_control_vector_load_info类提供相关功能
// 用途: 用于处理common_control_vector_load_info相关的操作
    // 结构体: common_control_vector_load_info
    // 描述: common_control_vector_load_info结构体提供相关功能
    // 用途: 用于处理common_control_vector_load_info相关的操作
    // 结构体: common_control_vector_load_info
    // 描述: common_control_vector_load_info结构体提供相关功能
    // 用途: 用于处理common_control_vector_load_info相关的操作
    // 结构体: common_control_vector_load_info
    // 描述: common_control_vector_load_info结构体提供相关功能
    // 用途: 用于处理common_control_vector_load_info相关的操作
    // 结构体: common_control_vector_load_info
    // 描述: common_control_vector_load_info结构体提供相关功能
    // 用途: 用于处理common_control_vector_load_info相关的操作
struct common_control_vector_load_info {
    float strength;

    std::string fname;
};

// Load control vectors, scale each by strength, and add them together.
// On error, returns {-1, empty}
// 函数: common_control_vector_load
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: common_control_vector_load
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
common_control_vector_data common_control_vector_load(const std::vector<common_control_vector_load_info> & load_infos);

//
// Split utils
//

namespace {

const char * const LLM_KV_SPLIT_NO            = "split.no";
const char * const LLM_KV_SPLIT_COUNT         = "split.count";
const char * const LLM_KV_SPLIT_TENSORS_COUNT = "split.tensors.count";

}

//
// MoE utils
//

const char * const LLM_FFN_EXPS_REGEX = "\\.ffn_(up|down|gate)_(ch|)exps";

// 函数: llm_ffn_exps_block_regex
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llm_ffn_exps_block_regex
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
inline std::string llm_ffn_exps_block_regex(int idx) {
    return string_format("blk\\.%d%s", idx, LLM_FFN_EXPS_REGEX);
}

// 函数: llm_ffn_exps_cpu_override
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llm_ffn_exps_cpu_override
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
inline llama_model_tensor_buft_override llm_ffn_exps_cpu_override() {
    return { LLM_FFN_EXPS_REGEX, ggml_backend_cpu_buffer_type() };
}

//
// training utils
//

// 函数: common_opt_dataset_init
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: common_opt_dataset_init
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
ggml_opt_dataset_t common_opt_dataset_init(struct llama_context * ctx, const std::vector<llama_token> & tokens, int64_t stride);

// "adamw" or "sgd" (case insensitive)
enum ggml_opt_optimizer_type common_opt_get_optimizer(const char *);
