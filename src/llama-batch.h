#pragma once

#include "llama.h"

#include "llama-cparams.h"

#include <array>
#include <vector>
#include <set>
#include <bitset>
#include <memory>
#include <unordered_map>

// keep this struct lightweight
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
struct llama_ubatch {
    // 函数: equal_seqs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: equal_seqs
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool equal_seqs() const {
        return b_equal_seqs != 0;
    }

    // typical for M-RoPE cases:
    //   0 - sequantial position of the tokens/embeddings in the sequence
    //   1 - y position in the image
    //   2 - x position in the image
    //   3 - other
    // 函数: is_pos_2d
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_pos_2d
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_pos_2d() const {
        // TODO @ngxson : we may need to check for model arch when more models use >1 positions
        return n_pos >= 3;
    }

    uint32_t b_equal_seqs; // note: this is a boolean, but we use an int32_t for alignment
                           //       otherwise address sanitizer complains
    // TODO: whole_seqs for embeddings?

    uint32_t n_tokens;     // total tokens (n_seq_tokens * n_seqs)
    uint32_t n_seq_tokens; // tokens per sequence set
    uint32_t n_seqs;       // sequence sets in the ubatch
    uint32_t n_seqs_unq;   // unique sequence ids in the ubatch
    uint32_t n_pos;        // number of position inputs for each token/embedding

    // seq_id_unq: unique sequence ids in the ubatch
    // seq_idx:    indices of the unique sequence ids in the ubatch in [0, n_seqs_unq)
    //             used for extracting sequence pooled embeddings

    //                          // size               | idx | val
    llama_token  *  token;      // [n_tokens]         | i   | id, token
    float        *  embd;       // [n_embd, n_tokens] | i   | embd
    llama_pos    *  pos;        // [n_tokens*n_pos]   | i   | pos
    int32_t      *  n_seq_id;   // [n_tokens]         | i   | -
    llama_seq_id ** seq_id;     // [n_tokens]         | s   | s0, s1, seq_id
    llama_seq_id *  seq_id_unq; // [n_seqs_unq]       | s   | seq_id
    int32_t      *  seq_idx;    // [LLAMA_MAX_SEQ]    | -   | seq_idx
    int8_t       *  output;     // [n_tokens]         | i   | -

    // 类: data_t
    // 描述: data_t类提供相关功能
    // 用途: 用于处理data_t相关的操作
    // 类: data_t
    // 描述: data_t类提供相关功能
    // 用途: 用于处理data_t相关的操作
    // 结构体: data_t
    // 描述: data_t结构体提供相关功能
    // 用途: 用于处理data_t相关的操作
    // 结构体: data_t
    // 描述: data_t结构体提供相关功能
    // 用途: 用于处理data_t相关的操作
    // 结构体: data_t
    // 描述: data_t结构体提供相关功能
    // 用途: 用于处理data_t相关的操作
    // 结构体: data_t
    // 描述: data_t结构体提供相关功能
    // 用途: 用于处理data_t相关的操作
    struct data_t {
        std::vector<llama_token>    token;
        std::vector<float>          embd;
        std::vector<llama_pos>      pos;
        std::vector<int32_t>        n_seq_id;
        std::vector<llama_seq_id *> seq_id;      // these point into the seq_id_data below
        std::vector<llama_seq_id>   seq_id_unq;
        std::vector<int32_t>        seq_idx;
        std::vector<int8_t>         output;

        std::vector<llama_seq_id> seq_id_data;
    };

    // the llama_ubatch pointers above point to this data if set. otherwise - point to external non-owning data
    std::shared_ptr<data_t> data;
};

// a helper for sanitizing, fulfilling and splitting a batch
// 类: llama_batch_allocr
// 描述: llama_batch_allocr类提供相关功能
// 用途: 用于处理llama_batch_allocr相关的操作
// 类: llama_batch_allocr
// 描述: llama_batch_allocr类提供相关功能
// 用途: 用于处理llama_batch_allocr相关的操作
class llama_batch_allocr {
public:
    llama_batch_allocr(uint32_t n_pos_per_embd);

    // sanitize and auto-gen missing data in the input batch
    // memory is optional. if provided will be used to check for sequence continuity and to determine the positions
    bool init(
            const llama_batch & batch_inp,
            const llama_vocab & vocab,
            const llama_memory_i * memory,
            uint32_t n_embd,
            uint32_t n_seq_max,
            bool output_all);

    const llama_batch & get_batch() const;

    // 函数: get_n_tokens
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_tokens
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_tokens()  const;
    // 函数: get_n_outputs
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_outputs
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_outputs() const;
    // 函数: get_n_used
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_n_used
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    uint32_t get_n_used()    const;

    // the array of output indices in the order they were encountered during the ubatch splitting
    std::vector<int32_t> & get_out_ids();

    // min/max positions of each sequence in the current ubatch
    // 函数: seq_pos_min
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_pos_min
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_pos seq_pos_min(llama_seq_id seq_id) const;
    // 函数: seq_pos_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: seq_pos_max
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_pos seq_pos_max(llama_seq_id seq_id) const;

    // call once before splitting the batch to reset the internal state
    // 函数: split_reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: split_reset
    // 描述: 重置: 重置对象或状态到初始值
    // 参数: 无参数
    // 返回: 无返回值
    void split_reset();

    // simple split, unknown number of sequence sets of unequal lengths
    // 函数: split_simple
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: split_simple
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_ubatch split_simple(uint32_t n_ubatch);

    // make ubatches of equal-length sequences sets
    // if sequential == true, the tokens in the ubatch will have increasing sequential sequence ids
    // 函数: split_equal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: split_equal
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_ubatch split_equal(uint32_t n_ubatch, bool sequential);

    // sequence-set-wise split - each ubatch contains a single sequence-set
    // 函数: split_seq
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: split_seq
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_ubatch split_seq(uint32_t n_ubatch);

    // a helper method for creating a well-defined ubatch of tokens
    // TODO: support embeddings if needed in the future
    // 函数: ubatch_reserve
    // 描述: 预留: 预留资源或空间
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ubatch_reserve
    // 描述: 预留: 预留资源或空间
    // 参数: 无参数
    // 返回: 无返回值
    llama_ubatch ubatch_reserve(uint32_t n_seq_tokens, uint32_t n_seqs);

private:
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: clear
    // 描述: 清空: 清空数据或资源
    // 参数: 无参数
    // 返回: 无返回值
    void clear();

    // create the next ubatch based on the provided batch indices (idxs) and the number of sequence sets (n_seqs)
    // return llama_ubatch.n_tokens == 0 if the entire batch was consumed
    // 函数: ubatch_add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ubatch_add
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    llama_ubatch ubatch_add(const std::vector<int32_t> & idxs, uint32_t n_seqs, bool equal_seqs);

    // for debugging, start with LLAMA_BATCH_DEBUG=2
    // 函数: ubatch_print
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ubatch_print
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void ubatch_print(const llama_ubatch & ubatch, int debug);

    llama_batch batch;

    // only for debugging purposes
    const llama_vocab * vocab;

    // TODO: this is more of a temporary solution until we have a better way to handle multiple positions per token/embd
    //       ref: https://github.com/ggml-org/llama.cpp/issues/13694#issuecomment-2983871762
    const uint32_t n_pos_per_embd;

    uint32_t n_embd;
    uint32_t n_seq_max;
    uint32_t n_outputs;

    std::array<llama_seq_id, 1> seq_id_0 = {{ 0 }}; // default sequence id

    std::vector<llama_pos>      pos;
    std::vector<int32_t>        n_seq_id;
    std::vector<llama_seq_id *> seq_id;
    std::vector<llama_seq_id>   seq_id_unq;
    std::vector<int32_t>        seq_idx;
    std::vector<int8_t>         output;

    using pos_set_t = std::set<llama_pos>;
    using seq_cpl_t = std::vector<bool>;

    // helper flag to quickly determine if there are any coupled sequences in the batch
    bool has_cpl = false;

    std::vector<pos_set_t> seq_pos; // seq_pos[s]: the set of positions in sequence s
    std::vector<seq_cpl_t> seq_cpl; // seq_cpl[s0][s1]: if sequence s0 is coupled to sequence s1

    using idx_vec_t = std::vector<int32_t>;
    using seq_set_t = std::bitset<LLAMA_MAX_SEQ>;

    std::vector<seq_set_t> seq_set; // seq_set[i]: the sequence set of token i

    std::unordered_map<seq_set_t, idx_vec_t> seq_set_map; // the indices at which the sequence set appears

    // batch indices of the output
    std::vector<int32_t> out_ids;

    uint32_t n_used;

    // used[i] indicates if token i has already been used in a previous ubatch
    std::vector<bool> used;

    int debug;
};
