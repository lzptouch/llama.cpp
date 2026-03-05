#pragma once

#include "llama-batch.h"
#include "llama-graph.h"
#include "llama-kv-cache.h"
#include "llama-memory.h"
#include "llama-memory-recurrent.h"

#include <memory>
#include <vector>

//
// llama_memory_hybrid
//

// utilizes instances of llama_memory_recurrent and llama_kv_cache to
//   support models where each layer may be either attention-based or recurrent

// 类: llama_memory_hybrid
// 描述: llama_memory_hybrid类提供相关功能
// 用途: 用于处理llama_memory_hybrid相关的操作
// 类: llama_memory_hybrid
// 描述: llama_memory_hybrid类提供相关功能
// 用途: 用于处理llama_memory_hybrid相关的操作
class llama_memory_hybrid : public llama_memory_i {
public:
    llama_memory_hybrid(
        const llama_model & model,
                            /* attn */
                ggml_type   type_k,
                ggml_type   type_v,
                     bool   v_trans,
                 uint32_t   kv_size,
                 uint32_t   n_pad,
                 uint32_t   n_swa,
           llama_swa_type   swa_type,
                            /* recurrent */
                ggml_type   type_r,
                ggml_type   type_s,
                 uint32_t   rs_size,
                            /* common */
                 uint32_t   n_seq_max,
                     bool   offload,
                     bool   unified,
                            /* layer filters */
    const layer_filter_cb & filter_attn = nullptr,
    const layer_filter_cb & filter_recr = nullptr);

    ~llama_memory_hybrid() = default;

    //
    // llama_memory_i
    //

    llama_memory_context_ptr init_batch(
            llama_batch_allocr & balloc,
            uint32_t n_ubatch,
            bool embd_all) override;

    // 函数: init_full
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init_full
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    llama_memory_context_ptr init_full() override;

    // 函数: init_update
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init_update
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    llama_memory_context_ptr init_update(llama_context * lctx, bool optimize) override;

    // 函数: get_can_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_can_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_can_shift() const override;

    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    void clear(bool data) override;

    // 函数: seq_rm
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_rm
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool seq_rm  (llama_seq_id seq_id,                              llama_pos p0, llama_pos p1) override;
    // 函数: seq_cp
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_cp
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void seq_cp  (llama_seq_id seq_id_src, llama_seq_id seq_id_dst, llama_pos p0, llama_pos p1) override;
    // 函数: seq_keep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_keep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void seq_keep(llama_seq_id seq_id)                                                          override;
    // 函数: seq_add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void seq_add (llama_seq_id seq_id,                              llama_pos p0, llama_pos p1, llama_pos shift) override;
    // 函数: seq_div
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_div
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void seq_div (llama_seq_id seq_id,                              llama_pos p0, llama_pos p1, int d) override;

    // 函数: seq_pos_min
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_pos_min
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_pos seq_pos_min(llama_seq_id seq_id) const override;
    // 函数: seq_pos_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_pos_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_pos seq_pos_max(llama_seq_id seq_id) const override;

    std::map<ggml_backend_buffer_type_t, size_t> memory_breakdown() const override;

    // state write/load

    // 函数: state_write
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_write
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void state_write(llama_io_write_i & io, llama_seq_id seq_id = -1, llama_state_seq_flags flags = 0) const override;
    // 函数: state_read
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_read
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void state_read (llama_io_read_i  & io, llama_seq_id seq_id = -1, llama_state_seq_flags flags = 0)       override;

    //
    // llama_memory_hybrid specific API
    //

    // 函数: get_mem_attn
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_mem_attn
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_kv_cache * get_mem_attn() const;
    // 函数: get_mem_recr
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_mem_recr
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_memory_recurrent * get_mem_recr() const;

private:
    const llama_hparams & hparams;

    const std::unique_ptr<llama_kv_cache> mem_attn;
    const std::unique_ptr<llama_memory_recurrent> mem_recr;
};

// 类: llama_memory_hybrid_context
// 描述: llama_memory_hybrid_context类提供相关功能
// 用途: 用于处理llama_memory_hybrid_context相关的操作
// 类: llama_memory_hybrid_context
// 描述: llama_memory_hybrid_context类提供相关功能
// 用途: 用于处理llama_memory_hybrid_context相关的操作
class llama_memory_hybrid_context : public llama_memory_context_i {
public:
    using slot_info_vec_t = llama_kv_cache::slot_info_vec_t;

    // init failure
    // 函数: llama_memory_hybrid_context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: llama_memory_hybrid_context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit llama_memory_hybrid_context(llama_memory_status status);

    // init full
    // 函数: llama_memory_hybrid_context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: llama_memory_hybrid_context
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    explicit llama_memory_hybrid_context(llama_memory_hybrid * mem);

    // init update
    explicit llama_memory_hybrid_context(
        llama_memory_hybrid * mem,
              llama_context * lctx,
                       bool   optimize);

    // init success
    llama_memory_hybrid_context(
              llama_memory_hybrid * mem,
                  slot_info_vec_t   sinfos_attn,
        std::vector<llama_ubatch>   ubatches);

    ~llama_memory_hybrid_context() = default;

    // 函数: next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool next()  override;
    // 函数: apply
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: apply
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool apply() override;

    // 函数: get_status
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_status
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_memory_status  get_status() const override;
    const llama_ubatch & get_ubatch() const override;

    //
    // llama_memory_hybrid_context
    //

    // 函数: get_attn
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_attn
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    const llama_kv_cache_context * get_attn() const;
    // 函数: get_recr
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_recr
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    const llama_memory_recurrent_context * get_recr() const;

private:
    // the index of the next ubatch to process
    size_t i_next = 0;

    std::vector<llama_ubatch> ubatches;

    const llama_memory_context_ptr ctx_attn;
    const llama_memory_context_ptr ctx_recr;

    const llama_memory_status status;
};
