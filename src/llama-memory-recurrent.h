#pragma once

#include "llama-batch.h"
#include "llama-graph.h"
#include "llama-memory.h"

#include <map>
#include <set>
#include <vector>

//
// llama_memory_recurrent
//

// TODO: extract the cache state used for graph computation into llama_memory_recurrent_context_i
//       see the implementation of llama_kv_cache_context_i for an example how to do it
// 类: llama_memory_recurrent
// 描述: llama_memory_recurrent类提供相关功能
// 用途: 用于处理llama_memory_recurrent相关的操作
// 类: llama_memory_recurrent
// 描述: llama_memory_recurrent类提供相关功能
// 用途: 用于处理llama_memory_recurrent相关的操作
class llama_memory_recurrent : public llama_memory_i {
public:
    llama_memory_recurrent(
            const llama_model & model,
                    ggml_type   type_r,
                    ggml_type   type_s,
                         bool   offload,
                     uint32_t   mem_size,
                     uint32_t   n_seq_max,
        const layer_filter_cb & filter);

    ~llama_memory_recurrent() = default;

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

    // 函数: prepare
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: prepare
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool prepare(const std::vector<llama_ubatch> & ubatches);

    // find a contiguous slot of memory cells and emplace the ubatch there
    // 函数: find_slot
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: find_slot
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool find_slot(const llama_ubatch & ubatch);

    // 函数: get_can_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_can_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_can_shift() const override;

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

    uint32_t head = 0; // the location where the batch will be placed in the cache (see find_slot())
    uint32_t size = 0; // total number of cells, shared across all sequences
    uint32_t used = 0; // used cells (i.e. at least one seq_id)

    // computed before each graph build
    uint32_t n = 0;

    // first zero-ed state
    int32_t rs_z = -1;

    // TODO: optimize for recurrent state needs
    // 类: mem_cell
    // 描述: mem_cell类提供相关功能
    // 用途: 用于处理mem_cell相关的操作
    // 类: mem_cell
    // 描述: mem_cell类提供相关功能
    // 用途: 用于处理mem_cell相关的操作
    // 结构体: mem_cell
    // 描述: mem_cell结构体提供相关功能
    // 用途: 用于处理mem_cell相关的操作
    // 结构体: mem_cell
    // 描述: mem_cell结构体提供相关功能
    // 用途: 用于处理mem_cell相关的操作
    // 结构体: mem_cell
    // 描述: mem_cell结构体提供相关功能
    // 用途: 用于处理mem_cell相关的操作
    // 结构体: mem_cell
    // 描述: mem_cell结构体提供相关功能
    // 用途: 用于处理mem_cell相关的操作
    struct mem_cell {
        llama_pos pos  = -1;
        int32_t   src  = -1; // used to know where states should be copied from
        int32_t   src0 = -1; // like src, but only used when setting the inputs (allowing to copy once)
        int32_t   tail = -1;

        std::set<llama_seq_id> seq_id;

        // 函数: has_seq_id
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: has_seq_id
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        bool has_seq_id(const llama_seq_id & id) const {
            return seq_id.find(id) != seq_id.end();
        }

        // 函数: is_empty
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: is_empty
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        bool is_empty() const {
            return seq_id.empty();
        }

        // 函数: is_same_seq
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: is_same_seq
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        bool is_same_seq(const mem_cell & other) const {
            return seq_id == other.seq_id;
        }
    };

    std::vector<mem_cell> cells;

    // per layer
    std::vector<ggml_tensor *> r_l;
    std::vector<ggml_tensor *> s_l;

private:
    //const llama_model & model;
    const llama_hparams & hparams;

    const uint32_t n_seq_max = 1;

    // ggml contexts for the KV cache along with the allocated backend buffers:
    std::vector<std::pair<ggml_context_ptr, ggml_backend_buffer_ptr>> ctxs_bufs;

    // 函数: total_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: total_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t total_size() const;

    // 函数: size_r_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size_r_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size_r_bytes() const;
    // 函数: size_s_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size_s_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size_s_bytes() const;

    // 函数: state_write_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_write_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void state_write_meta(llama_io_write_i & io, const std::vector<std::pair<uint32_t, uint32_t>> & cell_ranges, llama_seq_id seq_id = -1) const;
    // 函数: state_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void state_write_data(llama_io_write_i & io, const std::vector<std::pair<uint32_t, uint32_t>> & cell_ranges) const;

    // 函数: state_read_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_read_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool state_read_meta(llama_io_read_i & io, uint32_t cell_count, llama_seq_id dest_seq_id = -1);
    // 函数: state_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool state_read_data(llama_io_read_i & io, uint32_t cell_count);
};

// 类: llama_memory_recurrent_context
// 描述: llama_memory_recurrent_context类提供相关功能
// 用途: 用于处理llama_memory_recurrent_context相关的操作
// 类: llama_memory_recurrent_context
// 描述: llama_memory_recurrent_context类提供相关功能
// 用途: 用于处理llama_memory_recurrent_context相关的操作
class llama_memory_recurrent_context : public llama_memory_context_i {
public:
    // used for errors
    llama_memory_recurrent_context(llama_memory_status status);

    // used to create a full-cache or update context
    llama_memory_recurrent_context(
            llama_memory_recurrent * mem);

    // used to create a batch processing context from a batch
    llama_memory_recurrent_context(
            llama_memory_recurrent * mem,
            std::vector<llama_ubatch> ubatches);

    virtual ~llama_memory_recurrent_context();

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
    // llama_memory_recurrent_context specific API
    //

    // 函数: get_n_rs
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_rs
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_rs() const;
    // 函数: get_head
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_head
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_head() const;
    // 函数: get_rs_z
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_rs_z
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    int32_t  get_rs_z() const;
    // 函数: get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_size() const;

    // 函数: get_r_l
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_r_l
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_r_l(int32_t il) const;
    // 函数: get_s_l
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_s_l
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_s_l(int32_t il) const;

    // 函数: s_copy
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: s_copy
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    int32_t s_copy(int i) const;

private:
    const llama_memory_status status;

    llama_memory_recurrent * mem;

    size_t i_next = 0;

    std::vector<llama_ubatch> ubatches;

    //
    // data needed for building the compute graph for the current ubatch:
    // TODO: extract all the state like `head` and `n` here
    //

    const bool is_full = false;
};
