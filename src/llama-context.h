#pragma once

#include "llama.h"
#include "llama-cparams.h"
#include "llama-graph.h"
#include "llama-adapter.h"
#include "llama-impl.h"

#include "ggml-cpp.h"
#include "ggml-opt.h"

#include <map>
#include <vector>

// 类: llama_model
// 描述: llama_model类提供相关功能
// 用途: 用于处理llama_model相关的操作
// 类: llama_model
// 描述: llama_model类提供相关功能
// 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
    // 结构体: llama_model
    // 描述: llama_model结构体提供相关功能
    // 用途: 用于处理llama_model相关的操作
struct llama_model;
// 类: llama_batch_allocr
// 描述: llama_batch_allocr类提供相关功能
// 用途: 用于处理llama_batch_allocr相关的操作
// 类: llama_batch_allocr
// 描述: llama_batch_allocr类提供相关功能
// 用途: 用于处理llama_batch_allocr相关的操作
class llama_batch_allocr;

// 类: llama_io_read_i
// 描述: llama_io_read_i类提供相关功能
// 用途: 用于处理llama_io_read_i相关的操作
// 类: llama_io_read_i
// 描述: llama_io_read_i类提供相关功能
// 用途: 用于处理llama_io_read_i相关的操作
class llama_io_read_i;
// 类: llama_io_write_i
// 描述: llama_io_write_i类提供相关功能
// 用途: 用于处理llama_io_write_i相关的操作
// 类: llama_io_write_i
// 描述: llama_io_write_i类提供相关功能
// 用途: 用于处理llama_io_write_i相关的操作
class llama_io_write_i;

// "memory" as in abstract memory for the context
// 类: llama_memory_i
// 描述: llama_memory_i类提供相关功能
// 用途: 用于处理llama_memory_i相关的操作
// 类: llama_memory_i
// 描述: llama_memory_i类提供相关功能
// 用途: 用于处理llama_memory_i相关的操作
    // 结构体: llama_memory_i
    // 描述: llama_memory_i结构体提供相关功能
    // 用途: 用于处理llama_memory_i相关的操作
    // 结构体: llama_memory_i
    // 描述: llama_memory_i结构体提供相关功能
    // 用途: 用于处理llama_memory_i相关的操作
    // 结构体: llama_memory_i
    // 描述: llama_memory_i结构体提供相关功能
    // 用途: 用于处理llama_memory_i相关的操作
    // 结构体: llama_memory_i
    // 描述: llama_memory_i结构体提供相关功能
    // 用途: 用于处理llama_memory_i相关的操作
struct llama_memory_i;
// 类: llama_memory_context_i
// 描述: llama_memory_context_i类提供相关功能
// 用途: 用于处理llama_memory_context_i相关的操作
// 类: llama_memory_context_i
// 描述: llama_memory_context_i类提供相关功能
// 用途: 用于处理llama_memory_context_i相关的操作
    // 结构体: llama_memory_context_i
    // 描述: llama_memory_context_i结构体提供相关功能
    // 用途: 用于处理llama_memory_context_i相关的操作
    // 结构体: llama_memory_context_i
    // 描述: llama_memory_context_i结构体提供相关功能
    // 用途: 用于处理llama_memory_context_i相关的操作
    // 结构体: llama_memory_context_i
    // 描述: llama_memory_context_i结构体提供相关功能
    // 用途: 用于处理llama_memory_context_i相关的操作
    // 结构体: llama_memory_context_i
    // 描述: llama_memory_context_i结构体提供相关功能
    // 用途: 用于处理llama_memory_context_i相关的操作
struct llama_memory_context_i;

// "memory" as in physical memory for a buffer type, in bytes
// 类: llama_memory_breakdown_data
// 描述: llama_memory_breakdown_data类提供相关功能
// 用途: 用于处理llama_memory_breakdown_data相关的操作
// 类: llama_memory_breakdown_data
// 描述: llama_memory_breakdown_data类提供相关功能
// 用途: 用于处理llama_memory_breakdown_data相关的操作
    // 结构体: llama_memory_breakdown_data
    // 描述: llama_memory_breakdown_data结构体提供相关功能
    // 用途: 用于处理llama_memory_breakdown_data相关的操作
    // 结构体: llama_memory_breakdown_data
    // 描述: llama_memory_breakdown_data结构体提供相关功能
    // 用途: 用于处理llama_memory_breakdown_data相关的操作
    // 结构体: llama_memory_breakdown_data
    // 描述: llama_memory_breakdown_data结构体提供相关功能
    // 用途: 用于处理llama_memory_breakdown_data相关的操作
    // 结构体: llama_memory_breakdown_data
    // 描述: llama_memory_breakdown_data结构体提供相关功能
    // 用途: 用于处理llama_memory_breakdown_data相关的操作
struct llama_memory_breakdown_data {
    size_t model   = 0; // memory allocated for the model
    size_t context = 0; // memory allocated for the context
    size_t compute = 0; // memory allocated for temporary compute buffers

    // 函数: total
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: total
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t total() const {
        return model + context + compute;
    }
};

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
struct llama_context {
    // init scheduler and compute buffers, reserve worst-case graphs
    llama_context(
            const llama_model & model,
                  llama_context_params params);

    ~llama_context();

    // reserve a new backend scheduler (if needed)
    // for example, when:
    //   - changing loras
    //   - changing samplers
    //   - changing attention type
    //   - etc.
    // 函数: sched_reserve
    // 描述: 预留: 预留资源或空间
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: sched_reserve
    // 描述: 预留: 预留资源或空间
    // 参数: 无参数
    // 返回: 无返回值
    void sched_reserve();

    // 函数: synchronize
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: synchronize
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void synchronize();

    const llama_model   & get_model()   const;
    const llama_cparams & get_cparams() const;

    // 函数: get_sched
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sched
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_backend_sched_t get_sched() const;

    // 函数: n_ctx
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_ctx
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_ctx()     const;
    // 函数: n_ctx_seq
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_ctx_seq
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_ctx_seq() const;
    // 函数: n_batch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_batch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_batch()   const;
    // 函数: n_ubatch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_ubatch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_ubatch()  const;
    // 函数: n_seq_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_seq_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_seq_max() const;

    // 函数: n_threads
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_threads
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_threads()       const;
    // 函数: n_threads_batch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: n_threads_batch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t n_threads_batch() const;

    // 函数: get_memory
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_memory
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_memory_t get_memory() const;

    // return true if the memory was updated
    // 函数: memory_update
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: memory_update
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    bool memory_update(bool optimize);

    enum llama_pooling_type pooling_type() const;

    // 函数: get_logits
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_logits
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float * get_logits();
    // 函数: get_logits_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_logits_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float * get_logits_ith(int32_t i);

    // 函数: get_embeddings
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_embeddings
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float * get_embeddings();
    // 函数: get_embeddings_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_embeddings_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float * get_embeddings_ith(int32_t i);
    // 函数: get_embeddings_seq
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_embeddings_seq
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float * get_embeddings_seq(llama_seq_id seq_id);

    // 函数: get_sampled_tokens
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_tokens
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_token * get_sampled_tokens() const;
    // 函数: get_sampled_token_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_token_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_token   get_sampled_token_ith(int32_t idx);

    // 函数: get_sampled_logits_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_logits_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float * get_sampled_logits_ith(int32_t idx);
    // 函数: get_sampled_logits_count
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_logits_count
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    size_t  get_sampled_logits_count(int32_t idx);

    // 函数: get_sampled_probs_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_probs_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    float * get_sampled_probs_ith(int32_t idx);
    // 函数: get_sampled_probs_count
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_probs_count
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    size_t  get_sampled_probs_count(int32_t idx);

    // 函数: get_sampled_candidates_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_candidates_ith
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    const llama_token * get_sampled_candidates_ith(int32_t idx);
    // 函数: get_sampled_candidates_count
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_sampled_candidates_count
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    size_t get_sampled_candidates_count(int32_t idx);

    void attach_threadpool(
            ggml_threadpool_t threadpool,
            ggml_threadpool_t threadpool_batch);

    // 函数: detach_threadpool
    // 描述: 分离: 分离已附加的资源或回调
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: detach_threadpool
    // 描述: 分离: 分离已附加的资源或回调
    // 参数: 无参数
    // 返回: 无返回值
    void detach_threadpool();

    // 函数: set_n_threads
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_n_threads
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_n_threads(int32_t n_threads, int32_t n_threads_batch);

    // 函数: set_abort_callback
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_abort_callback
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_abort_callback(bool (*abort_callback)(void * data), void * abort_callback_data);

    // 函数: set_embeddings
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_embeddings
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_embeddings (bool value);
    // 函数: set_causal_attn
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_causal_attn
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_causal_attn(bool value);
    // 函数: set_warmup
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_warmup
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_warmup(bool value);

    // 函数: set_adapters_lora
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_adapters_lora
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_adapters_lora(llama_adapter_lora ** adapters, size_t n_adapters, float * scales);

    // 函数: adapters_lora_are_same
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: adapters_lora_are_same
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool adapters_lora_are_same(llama_adapter_lora ** adapters, size_t n_adapters, float * scales);

    bool set_adapter_cvec(
            const float * data,
                 size_t   len,
                int32_t   n_embd,
                int32_t   il_start,
                int32_t   il_end);

    // process a single ubatch with a specific graph type
    // if memory_context is provided, it will be applied first to the context's memory
    // ret contains the status of the graph computation
    // returns nullptr only if ret != GGML_STATUS_SUCCESS
    llm_graph_result * process_ubatch(
                const llama_ubatch & ubatch,
                    llm_graph_type   gtype,
            llama_memory_context_i * mctx,
                       ggml_status & ret);

    // 函数: encode
    // 描述: 编码: 将输入数据编码为内部表示
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: encode
    // 描述: 编码: 将输入数据编码为内部表示
    // 参数: 无参数
    // 返回: 无返回值
    int encode(const llama_batch & batch_inp);
    // 函数: decode
    // 描述: 解码: 解码数据或生成输出结果
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: decode
    // 描述: 解码: 解码数据或生成输出结果
    // 参数: 无参数
    // 返回: 无返回值
    int decode(const llama_batch & batch_inp);

    //
    // state save/load
    //

    // 函数: state_get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_get_size();
    // 函数: state_get_data
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_get_data
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_get_data(      uint8_t * dst, size_t size);
    // 函数: state_set_data
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_set_data
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_set_data(const uint8_t * src, size_t size);

    // 函数: state_seq_get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_seq_get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_seq_get_size(llama_seq_id seq_id, llama_state_seq_flags flags);
    // 函数: state_seq_get_data
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_seq_get_data
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_seq_get_data(llama_seq_id seq_id,       uint8_t * dst, size_t size, llama_state_seq_flags flags);
    // 函数: state_seq_set_data
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_seq_set_data
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_seq_set_data(llama_seq_id seq_id, const uint8_t * src, size_t size, llama_state_seq_flags flags);

    bool state_load_file(
            const char * filepath,
           llama_token * tokens_out,
                size_t   n_token_capacity,
                size_t * n_token_count_out);

    bool state_save_file(
            const char * filepath,
     const llama_token * tokens,
                size_t   n_token_count);

    size_t state_seq_load_file(
          llama_seq_id   seq_id,
            const char * filepath,
           llama_token * tokens_out,
                size_t   n_token_capacity,
                size_t * n_token_count_out);

    size_t state_seq_save_file(
          llama_seq_id   seq_id,
            const char * filepath,
     const llama_token * tokens,
                size_t   n_token_count);

    //
    // perf
    //

    // 函数: perf_get_data
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: perf_get_data
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    llama_perf_context_data perf_get_data() const;
    // 函数: perf_reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: perf_reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    void perf_reset();

    std::map<ggml_backend_buffer_type_t, llama_memory_breakdown_data> memory_breakdown() const;

    //
    // training
    //

    // 函数: opt_init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: opt_init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 无参数
    // 返回: 无返回值
    void opt_init(struct llama_model * model, struct llama_opt_params lopt_params);

    // TODO: more flexible combinations of logical/physical batch size and context size
    void opt_epoch(
            ggml_opt_dataset_t      dataset,
            ggml_opt_result_t       result_train,
            ggml_opt_result_t       result_eval,
            int64_t                 idata_split,
            ggml_opt_epoch_callback callback_train,
            ggml_opt_epoch_callback callback_eval);

    void opt_epoch_iter(
            ggml_opt_dataset_t               dataset,
            ggml_opt_result_t                result,
            const std::vector<llama_token> & tokens,
            const std::vector<llama_token> & labels_sparse,
            llama_batch                    & batch,
            ggml_opt_epoch_callback          callback,
            bool                             train,
            int64_t                          idata_in_loop,
            int64_t                          ndata_in_loop,
            int64_t                          t_loop_start);

private:
    //
    // output
    //

    // Make sure enough space is available for outputs.
    // Returns max number of outputs for which space was reserved.
    // 函数: output_reserve
    // 描述: 预留: 预留资源或空间
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: output_reserve
    // 描述: 预留: 预留资源或空间
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t output_reserve(int32_t n_outputs);

    // 函数: output_reorder
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: output_reorder
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void output_reorder();

    // map the output row index `i` to batch index
    // 函数: output_resolve_row
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: output_resolve_row
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    int64_t output_resolve_row(int32_t i) const;

    //
    // graph
    //

public:
    // 函数: graph_max_nodes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: graph_max_nodes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    uint32_t graph_max_nodes(uint32_t n_tokens) const;

    // can reuse the llm_graph_result instance of the context (for example to update a memory module)
    // 函数: get_gf_res_reserve
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_gf_res_reserve
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llm_graph_result * get_gf_res_reserve() const;

    // returns the result of ggml_backend_sched_graph_compute_async execution
    // 函数: graph_compute
    // 描述: 计算: 执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: graph_compute
    // 描述: 计算: 执行计算操作
    // 参数: 无参数
    // 返回: 无返回值
    ggml_status graph_compute(ggml_cgraph * gf, bool batched);

    // reserve a graph with a dummy ubatch of the specified size
    ggml_cgraph * graph_reserve(
        uint32_t n_tokens, uint32_t n_seqs, uint32_t n_outputs, const llama_memory_context_i * mctx, bool split_only = false, size_t * sizes = nullptr);

    // 函数: set_sampler
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_sampler
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    bool set_sampler(llama_seq_id seq_id, llama_sampler * sampler);

private:
    llm_graph_params graph_params(
                        llm_graph_result * res,
                      const llama_ubatch & ubatch,
            const llama_memory_context_i * mctx,
                          llm_graph_type   gtype) const;

    // 函数: graph_get_cb
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: graph_get_cb
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数
    // 返回: 无返回值
    llm_graph_cb graph_get_cb() const;

    // TODO: read/write lora adapters and cvec
    // 函数: state_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_write_data(llama_io_write_i & io);
    // 函数: state_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_read_data (llama_io_read_i  & io);

    // 函数: state_seq_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_seq_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_seq_write_data(llama_io_write_i & io, llama_seq_id seq_id, llama_state_seq_flags flags);
    // 函数: state_seq_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_seq_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t state_seq_read_data (llama_io_read_i  & io, llama_seq_id seq_id, llama_state_seq_flags flags);

    //
    // members
    //

    const llama_model & model;

    llama_cparams cparams;

    llama_adapter_cvec_ptr  cvec;
    llama_adapter_loras_ptr loras;

    llama_cross cross; // TODO: tmp for handling cross-attention - need something better probably

    std::unique_ptr<llama_memory_i> memory;

    // decode output (2-dimensional array: [n_outputs][n_vocab])
    buffer_view<float> logits = {nullptr, 0};

    // embeddings output (2-dimensional array: [n_outputs][n_embd])
    // populated only when pooling_type == LLAMA_POOLING_TYPE_NONE
    buffer_view<float> embd = {nullptr, 0};

    // 类: sampling_info
    // 描述: sampling_info类提供相关功能
    // 用途: 用于处理sampling_info相关的操作
    // 类: sampling_info
    // 描述: sampling_info类提供相关功能
    // 用途: 用于处理sampling_info相关的操作
    // 结构体: sampling_info
    // 描述: sampling_info结构体提供相关功能
    // 用途: 用于处理sampling_info相关的操作
    // 结构体: sampling_info
    // 描述: sampling_info结构体提供相关功能
    // 用途: 用于处理sampling_info相关的操作
    // 结构体: sampling_info
    // 描述: sampling_info结构体提供相关功能
    // 用途: 用于处理sampling_info相关的操作
    // 结构体: sampling_info
    // 描述: sampling_info结构体提供相关功能
    // 用途: 用于处理sampling_info相关的操作
    struct sampling_info {
        // !samplers.empty() to check if any samplers are active
        std::map<llama_seq_id, llama_sampler *> samplers;

        buffer_view<float>       logits     = {nullptr, 0};
        buffer_view<llama_token> sampled    = {nullptr, 0};
        buffer_view<float>       probs      = {nullptr, 0};
        buffer_view<llama_token> candidates = {nullptr, 0};

        std::vector<uint32_t> logits_count;
        std::vector<uint32_t> probs_count;
        std::vector<uint32_t> candidates_count;

        // optimization
        std::vector<llama_token> token_ids_full_vocab;
    };

    sampling_info sampling;

    // sequence embeddings output (map of [n_embd] vectors)
    // populated only when pooling_type != LLAMA_POOLING_TYPE_NONE
    std::map<llama_seq_id, std::vector<float>> embd_seq;

    // reuse the batch_allocr to avoid unnecessary memory allocations
    std::unique_ptr<llama_batch_allocr> balloc;

    uint32_t n_outputs = 0; // number of actually-used outputs in the current ubatch or last logical batch

    std::vector<int32_t> output_ids; // map batch token positions to ids of the logits and embd buffers

    // 类: swap_info
    // 描述: swap_info类提供相关功能
    // 用途: 用于处理swap_info相关的操作
    // 类: swap_info
    // 描述: swap_info类提供相关功能
    // 用途: 用于处理swap_info相关的操作
    // 结构体: swap_info
    // 描述: swap_info结构体提供相关功能
    // 用途: 用于处理swap_info相关的操作
    // 结构体: swap_info
    // 描述: swap_info结构体提供相关功能
    // 用途: 用于处理swap_info相关的操作
    // 结构体: swap_info
    // 描述: swap_info结构体提供相关功能
    // 用途: 用于处理swap_info相关的操作
    // 结构体: swap_info
    // 描述: swap_info结构体提供相关功能
    // 用途: 用于处理swap_info相关的操作
    struct swap_info {
        uint32_t i0;
        uint32_t i1;
    };

    std::vector<swap_info> output_swaps;

    ggml_backend_sched_ptr sched;

    bool sched_need_reserve = true;

    ggml_backend_t backend_cpu = nullptr;
    std::vector<ggml_backend_ptr> backends;

    // training
    ggml_opt_context_t opt_ctx = nullptr;

    ggml_threadpool_t threadpool       = nullptr;
    ggml_threadpool_t threadpool_batch = nullptr;

    ggml_abort_callback abort_callback      = nullptr;
    void *              abort_callback_data = nullptr;

    std::vector<std::pair<ggml_backend_t, ggml_backend_set_n_threads_t>> set_n_threads_fns;

    // pointers and buffer types used for the compute buffer of each backend
    std::vector<ggml_backend_t>             backend_ptrs;
    std::vector<ggml_backend_buffer_type_t> backend_buft;
    std::vector<size_t>                     backend_buf_exp_size; // expected buffer sizes

    llm_graph_result_ptr gf_res_prev;
    llm_graph_result_ptr gf_res_reserve;

    // host buffer for the model output (logits and embeddings)
    ggml_backend_buffer_ptr buf_output;

    bool has_evaluated_once = false;

    // env: LLAMA_GRAPH_REUSE_DISABLE
    bool graph_reuse_disable = false;

    // perf
    mutable int64_t t_start_us  = 0;
    mutable int64_t t_load_us   = 0;
    mutable int64_t t_p_eval_us = 0;
    mutable int64_t t_eval_us   = 0;

    mutable int64_t t_compute_start_us = 0;
    mutable int64_t n_queued_tokens    = 0;

    mutable int32_t n_p_eval = 0; // number of tokens in eval calls for the prompt (with batch size > 1)
    mutable int32_t n_eval   = 0; // number of eval calls

    mutable int32_t n_reused = 0; // number of times the previous graph was reused
};
