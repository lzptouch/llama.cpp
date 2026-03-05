#ifndef HTP_OPS_H
#define HTP_OPS_H

#include "htp-ctx.h"
#include "htp-msg.h"
#include "worker-pool.h"

#include <assert.h>
#include <stdint.h>

#include <hex-fastdiv.h>

// ggml-common.h must be included prior to this header

// 类: htp_spad
// 描述: htp_spad类提供相关功能
// 用途: 用于处理htp_spad相关的操作
// 类: htp_spad
// 描述: htp_spad类提供相关功能
// 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
struct htp_spad {
    uint8_t * data;
    size_t    stride;
    size_t    size;
    size_t    size_per_thread;
};

// 类: htp_ops_context
// 描述: htp_ops_context类提供相关功能
// 用途: 用于处理htp_ops_context相关的操作
// 类: htp_ops_context
// 描述: htp_ops_context类提供相关功能
// 用途: 用于处理htp_ops_context相关的操作
    // 结构体: htp_ops_context
    // 描述: htp_ops_context结构体提供相关功能
    // 用途: 用于处理htp_ops_context相关的操作
    // 结构体: htp_ops_context
    // 描述: htp_ops_context结构体提供相关功能
    // 用途: 用于处理htp_ops_context相关的操作
    // 结构体: htp_ops_context
    // 描述: htp_ops_context结构体提供相关功能
    // 用途: 用于处理htp_ops_context相关的操作
    // 结构体: htp_ops_context
    // 描述: htp_ops_context结构体提供相关功能
    // 用途: 用于处理htp_ops_context相关的操作
struct htp_ops_context {
    // 类: htp_context
    // 描述: htp_context类提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 类: htp_context
    // 描述: htp_context类提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
    // 结构体: htp_context
    // 描述: htp_context结构体提供相关功能
    // 用途: 用于处理htp_context相关的操作
    struct htp_context * ctx;

    enum htp_op op;
    int32_t     op_params[HTP_MAX_OP_PARAMS / sizeof(int32_t)];

    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    struct htp_tensor src0;
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    struct htp_tensor src1;
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    struct htp_tensor src2;
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    struct htp_tensor src3;
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    struct htp_tensor src4;
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 类: htp_tensor
    // 描述: htp_tensor类提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    // 结构体: htp_tensor
    // 描述: htp_tensor结构体提供相关功能
    // 用途: 用于处理htp_tensor相关的操作
    struct htp_tensor dst;

    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    struct htp_spad src0_spad;
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    struct htp_spad src1_spad;
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    struct htp_spad src2_spad;
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    struct htp_spad src3_spad;
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 类: htp_spad
    // 描述: htp_spad类提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    // 结构体: htp_spad
    // 描述: htp_spad结构体提供相关功能
    // 用途: 用于处理htp_spad相关的操作
    struct htp_spad dst_spad;

    worker_pool_context_t * wpool;      // worker pool
    uint32_t                n_threads;  // num threads

    uint32_t src0_nrows_per_thread;
    uint32_t src1_nrows_per_thread;

    uint32_t flags;
};

// 函数: op_matmul
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_matmul
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_matmul(struct htp_ops_context * octx);
// 函数: op_matmul_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_matmul_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_matmul_id(struct htp_ops_context * octx);
// 函数: op_binary
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_binary
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_binary(struct htp_ops_context * octx);
// 函数: op_unary
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_unary
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_unary(struct htp_ops_context * octx);
// 函数: op_sum_rows
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_sum_rows
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_sum_rows(struct htp_ops_context * octx);
// 函数: op_activations
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_activations
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_activations(struct htp_ops_context * octx);
// 函数: op_softmax
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_softmax
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_softmax(struct htp_ops_context * octx);
// 函数: op_add_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_add_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_add_id(struct htp_ops_context * octx);
// 函数: op_rope
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_rope
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_rope(struct htp_ops_context * octx);
// 函数: op_flash_attn_ext
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_flash_attn_ext
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_flash_attn_ext(struct htp_ops_context * octx);
// 函数: op_set_rows
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: op_set_rows
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
int op_set_rows(struct htp_ops_context * octx);
// 函数: op_get_rows
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: op_get_rows
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
int op_get_rows(struct htp_ops_context * octx);
// 函数: op_cpy
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_cpy
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_cpy(struct htp_ops_context * octx);
// 函数: op_argsort
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: op_argsort
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int op_argsort(struct htp_ops_context * octx);

#endif /* HTP_OPS_H */
