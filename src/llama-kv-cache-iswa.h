#pragma once

#include "llama-kv-cache.h"

#include <vector>

//
// llama_kv_cache_iswa
//

// utilizes two instances of llama_kv_cache
//   the first instance is for the non-SWA layers of the model and the second instance is for the SWA layers

// 类: llama_kv_cache_iswa
// 描述: llama_kv_cache_iswa类提供相关功能
// 用途: 用于处理llama_kv_cache_iswa相关的操作
// 类: llama_kv_cache_iswa
// 描述: llama_kv_cache_iswa类提供相关功能
// 用途: 用于处理llama_kv_cache_iswa相关的操作
class llama_kv_cache_iswa : public llama_memory_i {
public:
    llama_kv_cache_iswa(
            const llama_model & model,
                    ggml_type   type_k,
                    ggml_type   type_v,
                         bool   v_trans,
                         bool   offload,
                         bool   swa_full,
                         bool   unified,
                     uint32_t   kv_size,
                     uint32_t   n_seq_max,
                     uint32_t   n_ubatch,
                     uint32_t   n_pad,
        const layer_filter_cb & filter,
        const  layer_reuse_cb & reuse);

    ~llama_kv_cache_iswa() = default;

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
    void state_read (llama_io_read_i  & io, llama_seq_id seq_id = -1, llama_state_seq_flags flags = 0) override;

    //
    // llama_kv_cache_iswa specific API
    //

    // 函数: get_base
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_base
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_kv_cache * get_base() const;
    // 函数: get_swa
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_swa
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    llama_kv_cache * get_swa () const;

private:
    const llama_hparams & hparams;

    const bool unified;

    std::unique_ptr<llama_kv_cache> kv_base;
    std::unique_ptr<llama_kv_cache> kv_swa;
};

// 类: llama_kv_cache_iswa_context
// 描述: llama_kv_cache_iswa_context类提供相关功能
// 用途: 用于处理llama_kv_cache_iswa_context相关的操作
// 类: llama_kv_cache_iswa_context
// 描述: llama_kv_cache_iswa_context类提供相关功能
// 用途: 用于处理llama_kv_cache_iswa_context相关的操作
class llama_kv_cache_iswa_context : public llama_memory_context_i {
public:
    using slot_info_vec_t = llama_kv_cache::slot_info_vec_t;

    // used for errors
    llama_kv_cache_iswa_context(llama_memory_status status);

    // used to create a full-cache context
    llama_kv_cache_iswa_context(
            llama_kv_cache_iswa * kv);

    // used to create an update context
    llama_kv_cache_iswa_context(
            llama_kv_cache_iswa * kv,
            llama_context * lctx,
            bool optimize);

    // used to create a batch processing context from a batch
    llama_kv_cache_iswa_context(
            llama_kv_cache_iswa * kv,
            slot_info_vec_t sinfos_base,
            slot_info_vec_t sinfos_swa,
            std::vector<llama_ubatch> ubatches);

    virtual ~llama_kv_cache_iswa_context();

    //
    // llama_memory_context_i
    //

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
    // llama_kv_cache_iswa_context specific API
    //

    // 函数: get_base
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_base
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    const llama_kv_cache_context * get_base() const;
    // 函数: get_swa
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_swa
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    const llama_kv_cache_context * get_swa()  const;

private:
    //llama_kv_cache_iswa * kv;

    // the index of the next ubatch to process
    size_t i_next = 0;

    std::vector<llama_ubatch> ubatches;

    const llama_memory_context_ptr ctx_base;
    const llama_memory_context_ptr ctx_swa;

    const llama_memory_status status;
};
