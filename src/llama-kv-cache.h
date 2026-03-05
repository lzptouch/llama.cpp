#pragma once

#include "llama-batch.h"
#include "llama-graph.h"
#include "llama-kv-cells.h"
#include "llama-memory.h"

#include <unordered_map>
#include <vector>

// 类: llama_cparams
// 描述: llama_cparams类提供相关功能
// 用途: 用于处理llama_cparams相关的操作
// 类: llama_cparams
// 描述: llama_cparams类提供相关功能
// 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
    // 结构体: llama_cparams
    // 描述: llama_cparams结构体提供相关功能
    // 用途: 用于处理llama_cparams相关的操作
struct llama_cparams;
// 类: llama_hparams
// 描述: llama_hparams类提供相关功能
// 用途: 用于处理llama_hparams相关的操作
// 类: llama_hparams
// 描述: llama_hparams类提供相关功能
// 用途: 用于处理llama_hparams相关的操作
    // 结构体: llama_hparams
    // 描述: llama_hparams结构体提供相关功能
    // 用途: 用于处理llama_hparams相关的操作
    // 结构体: llama_hparams
    // 描述: llama_hparams结构体提供相关功能
    // 用途: 用于处理llama_hparams相关的操作
    // 结构体: llama_hparams
    // 描述: llama_hparams结构体提供相关功能
    // 用途: 用于处理llama_hparams相关的操作
    // 结构体: llama_hparams
    // 描述: llama_hparams结构体提供相关功能
    // 用途: 用于处理llama_hparams相关的操作
struct llama_hparams;
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
struct llama_context;

//
// llama_kv_cache
//

// 类: llama_kv_cache
// 描述: llama_kv_cache类提供相关功能
// 用途: 用于处理llama_kv_cache相关的操作
// 类: llama_kv_cache
// 描述: llama_kv_cache类提供相关功能
// 用途: 用于处理llama_kv_cache相关的操作
class llama_kv_cache : public llama_memory_i {
public:
    // 类: stream_copy_info
    // 描述: stream_copy_info类提供相关功能
    // 用途: 用于处理stream_copy_info相关的操作
    // 类: stream_copy_info
    // 描述: stream_copy_info类提供相关功能
    // 用途: 用于处理stream_copy_info相关的操作
    // 结构体: stream_copy_info
    // 描述: stream_copy_info结构体提供相关功能
    // 用途: 用于处理stream_copy_info相关的操作
    // 结构体: stream_copy_info
    // 描述: stream_copy_info结构体提供相关功能
    // 用途: 用于处理stream_copy_info相关的操作
    // 结构体: stream_copy_info
    // 描述: stream_copy_info结构体提供相关功能
    // 用途: 用于处理stream_copy_info相关的操作
    // 结构体: stream_copy_info
    // 描述: stream_copy_info结构体提供相关功能
    // 用途: 用于处理stream_copy_info相关的操作
    struct stream_copy_info {
        // 函数: empty
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: empty
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        bool empty() const {
            assert(ssrc.size() == sdst.size());
            return ssrc.empty();
        }

        std::vector<uint32_t> ssrc;
        std::vector<uint32_t> sdst;
    };

    // for each ubatch, create a slot_info that contains information about where the ubatch should be inserted in the
    //   KV cells. for example, cell indices for each token, such that: token[i] -> goes to cells[idxs[i]]
    // 类: slot_info
    // 描述: slot_info类提供相关功能
    // 用途: 用于处理slot_info相关的操作
    // 类: slot_info
    // 描述: slot_info类提供相关功能
    // 用途: 用于处理slot_info相关的操作
    // 结构体: slot_info
    // 描述: slot_info结构体提供相关功能
    // 用途: 用于处理slot_info相关的操作
    // 结构体: slot_info
    // 描述: slot_info结构体提供相关功能
    // 用途: 用于处理slot_info相关的操作
    // 结构体: slot_info
    // 描述: slot_info结构体提供相关功能
    // 用途: 用于处理slot_info相关的操作
    // 结构体: slot_info
    // 描述: slot_info结构体提供相关功能
    // 用途: 用于处理slot_info相关的操作
    struct slot_info {
        // data for ggml_set_rows
        using idx_vec_t = std::vector<uint32_t>;

        // number of streams: ns = s1 - s0 + 1
        uint32_t s0;
        uint32_t s1;

        std::vector<llama_seq_id> strm; // [ns]
        std::vector<idx_vec_t>    idxs; // [ns]

        // 函数: head
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: head
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        uint32_t head() const {
            GGML_ASSERT(idxs.size() == 1);
            GGML_ASSERT(!idxs[0].empty());

            return idxs[0][0];
        }

        // 函数: resize
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: resize
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        void resize(size_t n) {
            strm.resize(n);
            idxs.resize(n);
        }

        // 函数: size
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: size
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        size_t size() const {
            GGML_ASSERT(idxs.size() == strm.size());
            GGML_ASSERT(!idxs.empty());

            return idxs[0].size();
        }

        // 函数: n_stream
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: n_stream
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        size_t n_stream() const {
            return strm.size();
        }

        // 函数: empty
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: empty
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        bool empty() const {
            return idxs.empty();
        }

        // 函数: clear
        // 描述: 清空: 清空数据或资源
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: clear
        // 描述: 清空: 清空数据或资源
        // 参数: 无参数
        // 返回: 无返回值
        void clear() {
            idxs.clear();
        }

        // check if indices are contiguous starting from head()
        // 函数: is_contiguous
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: is_contiguous
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        bool is_contiguous() const {
            if (idxs.empty() || idxs[0].empty()) {
                return true;
            }
            if (idxs.size() > 1) {
                return false;
            }
            const uint32_t h = idxs[0][0];
            for (size_t i = 0; i < idxs[0].size(); ++i) {
                if (idxs[0][i] != h + i) {
                    return false;
                }
            }
            return true;
        }
    };

    using slot_info_vec_t = std::vector<slot_info>;

    llama_kv_cache(
            const llama_model & model,
                    ggml_type   type_k,
                    ggml_type   type_v,
                         bool   v_trans,
                         bool   offload,
                         bool   unified,
                     uint32_t   kv_size,
                     uint32_t   n_seq_max,
                     uint32_t   n_pad,
                     uint32_t   n_swa,
               llama_swa_type   swa_type,
        const layer_filter_cb & filter,
        const  layer_reuse_cb & reuse);

    ~llama_kv_cache() = default;

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
    // llama_kv_cache specific API
    //

    // 函数: get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_size
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_size()     const;
    // 函数: get_n_stream
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_stream
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_stream() const;

    // 函数: get_has_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_has_shift
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_has_shift() const;

    //
    // graph_build API
    //

    // 函数: get_n_kv
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_kv
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_kv(const slot_info & sinfo) const;

    // get views of the current state of the cache
    // 函数: get_k
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_k
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_k(ggml_context * ctx, int32_t il, uint32_t n_kv, const slot_info & sinfo) const;
    // 函数: get_v
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_v
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_v(ggml_context * ctx, int32_t il, uint32_t n_kv, const slot_info & sinfo) const;

    // store k_cur and v_cur in the cache based on the provided head location
    // 函数: cpy_k
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cpy_k
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * cpy_k(ggml_context * ctx, ggml_tensor * k_cur, ggml_tensor * k_idxs, int32_t il, const slot_info & sinfo) const;
    // 函数: cpy_v
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cpy_v
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * cpy_v(ggml_context * ctx, ggml_tensor * v_cur, ggml_tensor * v_idxs, int32_t il, const slot_info & sinfo) const;

    //
    // preparation API
    //

    // find places for the provided ubatches in the cache, returns the slot infos
    // return empty vector on failure
    // 函数: prepare
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: prepare
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    slot_info_vec_t prepare(const std::vector<llama_ubatch> & ubatches);

    // 函数: update
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: update
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    bool update(llama_context * lctx, bool do_shift, const stream_copy_info & sc_info);

    // find a slot of kv cells that can hold the ubatch
    // if cont == true, then the slot must be continuous
    // return empty slot_info on failure
    // 函数: find_slot
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: find_slot
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    slot_info find_slot(const llama_ubatch & ubatch, bool cont) const;

    // emplace the ubatch context into slot: [sinfo.idxs[0...ubatch.n_tokens - 1]]
    // 函数: apply_ubatch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: apply_ubatch
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void apply_ubatch(const slot_info & sinfo, const llama_ubatch & ubatch);

    //
    // input API
    //

    // 函数: build_input_k_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_input_k_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * build_input_k_idxs(ggml_context * ctx, const llama_ubatch & ubatch) const;
    // 函数: build_input_v_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_input_v_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * build_input_v_idxs(ggml_context * ctx, const llama_ubatch & ubatch) const;

    // 函数: set_input_k_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_k_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_k_idxs(ggml_tensor * dst, const llama_ubatch * ubatch, const slot_info & sinfo) const;
    // 函数: set_input_v_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_v_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_v_idxs(ggml_tensor * dst, const llama_ubatch * ubatch, const slot_info & sinfo) const;

    // 函数: set_input_k_shift
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_k_shift
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_k_shift(ggml_tensor * dst) const;

    // 函数: set_input_kq_mask
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_kq_mask
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_kq_mask   (ggml_tensor * dst, const llama_ubatch * ubatch, bool causal_attn) const;
    // 函数: set_input_pos_bucket
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_pos_bucket
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_pos_bucket(ggml_tensor * dst, const llama_ubatch * ubatch) const;

private:
    const llama_model & model;
    const llama_hparams & hparams;

    // 类: kv_layer
    // 描述: kv_layer类提供相关功能
    // 用途: 用于处理kv_layer相关的操作
    // 类: kv_layer
    // 描述: kv_layer类提供相关功能
    // 用途: 用于处理kv_layer相关的操作
    // 结构体: kv_layer
    // 描述: kv_layer结构体提供相关功能
    // 用途: 用于处理kv_layer相关的操作
    // 结构体: kv_layer
    // 描述: kv_layer结构体提供相关功能
    // 用途: 用于处理kv_layer相关的操作
    // 结构体: kv_layer
    // 描述: kv_layer结构体提供相关功能
    // 用途: 用于处理kv_layer相关的操作
    // 结构体: kv_layer
    // 描述: kv_layer结构体提供相关功能
    // 用途: 用于处理kv_layer相关的操作
    struct kv_layer {
        // layer index in the model
        // note: can be different from the layer index in the KV cache
        uint32_t il;

        ggml_tensor * k;
        ggml_tensor * v;

        std::vector<ggml_tensor *> k_stream;
        std::vector<ggml_tensor *> v_stream;
    };

    bool v_trans = true;  // the value tensor is transposed

    const uint32_t n_seq_max = 1;
    const uint32_t n_stream  = 1;

    // required padding
    const uint32_t n_pad = 1;

    // SWA
    const uint32_t n_swa = 0;

    // env: LLAMA_KV_CACHE_DEBUG
    int debug = 0;

    // this is the SWA type of the cache - not to be confused with the model SWA type
    const llama_swa_type swa_type = LLAMA_SWA_TYPE_NONE;

    // ggml contexts for the KV cache along with the allocated backend buffers:
    std::vector<std::pair<ggml_context_ptr, ggml_backend_buffer_ptr>> ctxs_bufs;

    // the current index from where we start searching for a free slot in the ring buffer of KV cells (see find_slot())
    // note: this is not part of the KV state and it's only used to speed-up the find_slot() method
    std::vector<uint32_t> v_heads;

    std::vector<llama_kv_cells> v_cells;

    // maps from a sequence id to a stream id
    std::vector<uint32_t> seq_to_stream;

    // pending stream copies that will be applied during the next update
    stream_copy_info sc_info;

    std::vector<kv_layer> layers;

    // model layer id -> KV cache layer id
    std::unordered_map<int32_t, int32_t> map_layer_ids;

    // 函数: total_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: total_size
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t total_size() const;

    // 函数: size_k_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size_k_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size_k_bytes() const;
    // 函数: size_v_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: size_v_bytes
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    size_t size_v_bytes() const;

    ggml_tensor * build_rope_shift(
            const llama_cparams & cparams,
                   ggml_context * ctx,
                    ggml_tensor * cur,
                    ggml_tensor * shift,
                    ggml_tensor * factors,
                          float   freq_base,
                          float   freq_scale) const;

    ggml_cgraph * build_graph_shift(
               llm_graph_result * res,
                  llama_context * lctx) const;

    // 类: cell_ranges_t
    // 描述: cell_ranges_t类提供相关功能
    // 用途: 用于处理cell_ranges_t相关的操作
    // 类: cell_ranges_t
    // 描述: cell_ranges_t类提供相关功能
    // 用途: 用于处理cell_ranges_t相关的操作
    // 结构体: cell_ranges_t
    // 描述: cell_ranges_t结构体提供相关功能
    // 用途: 用于处理cell_ranges_t相关的操作
    // 结构体: cell_ranges_t
    // 描述: cell_ranges_t结构体提供相关功能
    // 用途: 用于处理cell_ranges_t相关的操作
    // 结构体: cell_ranges_t
    // 描述: cell_ranges_t结构体提供相关功能
    // 用途: 用于处理cell_ranges_t相关的操作
    // 结构体: cell_ranges_t
    // 描述: cell_ranges_t结构体提供相关功能
    // 用途: 用于处理cell_ranges_t相关的操作
    struct cell_ranges_t {
        uint32_t strm;

        std::vector<std::pair<uint32_t, uint32_t>> data; // ranges, from inclusive, to exclusive
    };

    // 函数: state_write_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_write_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void state_write_meta(llama_io_write_i & io, const cell_ranges_t & cr, llama_seq_id seq_id = -1) const;
    // 函数: state_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_write_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void state_write_data(llama_io_write_i & io, const cell_ranges_t & cr) const;

    // 函数: state_read_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_read_meta
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool state_read_meta(llama_io_read_i & io, uint32_t strm, uint32_t cell_count,       slot_info & sinfo, llama_seq_id dest_seq_id = -1);
    // 函数: state_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: state_read_data
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool state_read_data(llama_io_read_i & io, uint32_t strm, uint32_t cell_count, const slot_info & sinfo);
};

// 类: llama_kv_cache_context
// 描述: llama_kv_cache_context类提供相关功能
// 用途: 用于处理llama_kv_cache_context相关的操作
// 类: llama_kv_cache_context
// 描述: llama_kv_cache_context类提供相关功能
// 用途: 用于处理llama_kv_cache_context相关的操作
class llama_kv_cache_context : public llama_memory_context_i {
public:
    // some shorthands
    using slot_info_vec_t  = llama_kv_cache::slot_info_vec_t;
    using stream_copy_info = llama_kv_cache::stream_copy_info;

    // used for errors
    llama_kv_cache_context(llama_memory_status status);

    // used to create a full-cache context
    llama_kv_cache_context(
            llama_kv_cache * kv);

    // used to create an update context
    llama_kv_cache_context(
            llama_kv_cache * kv,
            llama_context * lctx,
            bool do_shift,
            stream_copy_info sc_info);

    // used to create a batch processing context from a batch
    llama_kv_cache_context(
            llama_kv_cache * kv,
            slot_info_vec_t sinfos,
            std::vector<llama_ubatch> ubatches);

    virtual ~llama_kv_cache_context();

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
    // llama_kv_cache_context specific API
    //

    // 函数: get_n_kv
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_kv
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_kv() const;

    // get views of the current state of the cache
    // 函数: get_k
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_k
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_k(ggml_context * ctx, int32_t il) const;
    // 函数: get_v
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_v
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    ggml_tensor * get_v(ggml_context * ctx, int32_t il) const;

    // store k_cur and v_cur in the cache based on the provided head location
    // note: the heads in k_cur and v_cur should be layed out contiguously in memory
    //   - k_cur  [n_embd_head_k, n_head_k, n_tokens]
    //   - k_idxs [n_tokens]
    //   - v_cur  [n_embd_head_v, n_head_v, n_tokens]
    //   - v_idxs [n_tokens] or [n_tokens*n_embd_v_gqa] depending if V cache is transposed
    // 函数: cpy_k
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cpy_k
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * cpy_k(ggml_context * ctx, ggml_tensor * k_cur, ggml_tensor * k_idxs, int32_t il) const;
    // 函数: cpy_v
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cpy_v
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * cpy_v(ggml_context * ctx, ggml_tensor * v_cur, ggml_tensor * v_idxs, int32_t il) const;

    // create destination indices for each head of the current batch for where it would be written in the KV cache
    // the indices address the global KV cache (not per stream) - this is not relevant for the user of this API, but
    //   helps understand the implementation logic of cpy_k and cpy_v
    // 函数: build_input_k_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_input_k_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * build_input_k_idxs(ggml_context * ctx, const llama_ubatch & ubatch) const;
    // 函数: build_input_v_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: build_input_v_idxs
    // 描述: 构建: 构建数据结构或对象
    // 参数: 无参数
    // 返回: 无返回值
    ggml_tensor * build_input_v_idxs(ggml_context * ctx, const llama_ubatch & ubatch) const;

    // 函数: set_input_k_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_k_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_k_idxs(ggml_tensor * dst, const llama_ubatch * ubatch) const;
    // 函数: set_input_v_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_v_idxs
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_v_idxs(ggml_tensor * dst, const llama_ubatch * ubatch) const;

    // 函数: set_input_k_shift
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_k_shift
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_k_shift   (ggml_tensor * dst) const;
    // 函数: set_input_kq_mask
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_kq_mask
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_kq_mask   (ggml_tensor * dst, const llama_ubatch * ubatch, bool causal_attn) const;
    // 函数: set_input_pos_bucket
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_input_pos_bucket
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_input_pos_bucket(ggml_tensor * dst, const llama_ubatch * ubatch) const;

private:
    llama_memory_status status;

    llama_kv_cache * kv;
    llama_context * lctx;

    //
    // update context
    //

    bool do_shift = false;

    stream_copy_info sc_info;

    //
    // batch processing context
    //

    // the index of the cur ubatch to process
    size_t i_cur = 0;

    slot_info_vec_t sinfos;

    std::vector<llama_ubatch> ubatches;

    //
    // data needed for building the compute graph for the current ubatch:
    //

    // a heuristic, to avoid attending the full cache if it is not yet utilized
    // as the cache gets filled, the benefit from this heuristic disappears
    int32_t n_kv;
};
