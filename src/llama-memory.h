#pragma once

#include "llama.h"

#include <map>
#include <memory>
#include <functional>

// 类: llama_ubatch
// 描述: llama_ubatch类提供相关功能
// 用途: 用于处理llama_ubatch相关的操作
// 类: llama_ubatch
// 描述: llama_ubatch类提供相关功能
// 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
    // 结构体: llama_ubatch
    // 描述: llama_ubatch结构体提供相关功能
    // 用途: 用于处理llama_ubatch相关的操作
struct llama_ubatch;

// 类: llama_batch_allocr
// 描述: llama_batch_allocr类提供相关功能
// 用途: 用于处理llama_batch_allocr相关的操作
// 类: llama_batch_allocr
// 描述: llama_batch_allocr类提供相关功能
// 用途: 用于处理llama_batch_allocr相关的操作
class llama_batch_allocr;

// 类: llama_io_write_i
// 描述: llama_io_write_i类提供相关功能
// 用途: 用于处理llama_io_write_i相关的操作
// 类: llama_io_write_i
// 描述: llama_io_write_i类提供相关功能
// 用途: 用于处理llama_io_write_i相关的操作
class llama_io_write_i;
// 类: llama_io_read_i
// 描述: llama_io_read_i类提供相关功能
// 用途: 用于处理llama_io_read_i相关的操作
// 类: llama_io_read_i
// 描述: llama_io_read_i类提供相关功能
// 用途: 用于处理llama_io_read_i相关的操作
class llama_io_read_i;

// 类: llama_memory_params
// 描述: llama_memory_params类提供相关功能
// 用途: 用于处理llama_memory_params相关的操作
// 类: llama_memory_params
// 描述: llama_memory_params类提供相关功能
// 用途: 用于处理llama_memory_params相关的操作
    // 结构体: llama_memory_params
    // 描述: llama_memory_params结构体提供相关功能
    // 用途: 用于处理llama_memory_params相关的操作
    // 结构体: llama_memory_params
    // 描述: llama_memory_params结构体提供相关功能
    // 用途: 用于处理llama_memory_params相关的操作
    // 结构体: llama_memory_params
    // 描述: llama_memory_params结构体提供相关功能
    // 用途: 用于处理llama_memory_params相关的操作
    // 结构体: llama_memory_params
    // 描述: llama_memory_params结构体提供相关功能
    // 用途: 用于处理llama_memory_params相关的操作
struct llama_memory_params {
    // kv cache
    ggml_type type_k;
    ggml_type type_v;

    // use full-size SWA cache
    bool swa_full;
};

enum llama_memory_status {
    LLAMA_MEMORY_STATUS_SUCCESS = 0,
    LLAMA_MEMORY_STATUS_NO_UPDATE,
    LLAMA_MEMORY_STATUS_FAILED_PREPARE,
    LLAMA_MEMORY_STATUS_FAILED_COMPUTE,
};

// helper function for combining the status of two memory contexts
// useful for implementing hybrid memory types (e.g. iSWA)
// 函数: llama_memory_status_combine
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_memory_status_combine
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
llama_memory_status llama_memory_status_combine(llama_memory_status s0, llama_memory_status s1);

// helper function for checking if a memory status indicates a failure
// 函数: llama_memory_status_is_fail
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: llama_memory_status_is_fail
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool llama_memory_status_is_fail(llama_memory_status status);

// the interface for managing the memory context during batch processing
// this interface is implemented per memory type. see:
//   - llama_kv_cache_context
//   - llama_kv_cache_iswa_context
//   ...
//
// the only method that should mutate the memory and the memory context is llama_memory_i::apply()
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
struct llama_memory_context_i {
    virtual ~llama_memory_context_i() = default;

    // consume the current ubatch from the context and proceed to the next one
    // return false if we are done
    // 函数: next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: next
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual bool next() = 0;

    // apply the memory state for the current ubatch to the memory object
    // return false on failure
    // 函数: apply
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: apply
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual bool apply() = 0;

    // get the current ubatch
    virtual const llama_ubatch & get_ubatch() const = 0;

    // get the status of the memory context - used for error handling and checking if any updates would be applied
    // 函数: get_status
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_status
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    virtual llama_memory_status get_status() const = 0;
};

using llama_memory_context_ptr = std::unique_ptr<llama_memory_context_i>;

// general concept of LLM memory
// the KV cache is a type of LLM memory, but there can be other types
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
struct llama_memory_i {
    // this callback is used to filter out layers that should not be included in the cache
    using layer_filter_cb = std::function<bool(int32_t il)>;

    // this callback is used to specify which layers should reuse memory from other layers
    // return negative value to indicate that the layer il should not reuse memory
    using layer_reuse_cb = std::function<int32_t(int32_t il)>;

    virtual ~llama_memory_i() = default;

    // split the input batch into a set of ubatches and verify that they can fit into the cache
    // return a context object containing the ubatches and memory state required to process them
    // check the llama_memory_context_i::get_status() for the result
    virtual llama_memory_context_ptr init_batch(
            llama_batch_allocr & balloc,
            uint32_t n_ubatch,
            bool embd_all) = 0;

    // simulate full cache, used for allocating worst-case compute buffers
    // 函数: init_full
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init_full
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    virtual llama_memory_context_ptr init_full() = 0;

    // prepare for any pending memory updates, such as shifts, copies, etc.
    // status == LLAMA_MEMORY_STATUS_NO_UPDATE if there is nothing to update
    // 函数: init_update
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init_update
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    virtual llama_memory_context_ptr init_update(llama_context * lctx, bool optimize) = 0;

    // getters
    // 函数: get_can_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_can_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    virtual bool get_can_shift() const = 0;

    //
    // ops
    //

    // if data == true, the data buffers will also be cleared together with the metadata
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    virtual void clear(bool data) = 0;

    // 函数: seq_rm
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_rm
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual bool seq_rm  (llama_seq_id seq_id,                              llama_pos p0, llama_pos p1) = 0;
    // 函数: seq_cp
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_cp
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void seq_cp  (llama_seq_id seq_id_src, llama_seq_id seq_id_dst, llama_pos p0, llama_pos p1) = 0;
    // 函数: seq_keep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_keep
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void seq_keep(llama_seq_id seq_id) = 0;
    // 函数: seq_add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void seq_add (llama_seq_id seq_id,                              llama_pos p0, llama_pos p1, llama_pos shift) = 0;
    // 函数: seq_div
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_div
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void seq_div (llama_seq_id seq_id,                              llama_pos p0, llama_pos p1, int d) = 0;

    // 函数: seq_pos_min
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_pos_min
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual llama_pos seq_pos_min(llama_seq_id seq_id) const = 0;
    // 函数: seq_pos_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_pos_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual llama_pos seq_pos_max(llama_seq_id seq_id) const = 0;

    virtual std::map<ggml_backend_buffer_type_t, size_t> memory_breakdown() const = 0;

    //
    // state write/read
    //

    // 函数: state_write
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_write
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void state_write(llama_io_write_i & io, llama_seq_id seq_id = -1, llama_state_seq_flags flags = 0) const = 0;
    // 函数: state_read
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_read
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    virtual void state_read (llama_io_read_i  & io, llama_seq_id seq_id = -1, llama_state_seq_flags flags = 0) = 0;
};

using llama_memory_ptr = std::unique_ptr<llama_memory_i>;
