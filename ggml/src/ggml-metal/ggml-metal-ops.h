#pragma once

#include "ggml-metal-device.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ggml_metal_op * ggml_metal_op_t;

ggml_metal_op_t ggml_metal_op_init(
        ggml_metal_device_t dev,
        ggml_metal_cmd_buf_t cmd_buf,
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
        struct ggml_cgraph * gf,
        int  idx_start,
        int  idx_end,
        bool use_fusion,
        bool use_concurrency,
        bool use_capture,
        int  debug_graph,
        int  debug_fusion);

// 函数: ggml_metal_op_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void ggml_metal_op_free(ggml_metal_op_t ctx);

// 函数: ggml_metal_op_n_nodes
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_n_nodes
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_n_nodes(ggml_metal_op_t ctx);

// 函数: ggml_metal_op_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_encode
// 描述: 编码: 将输入数据编码为内部表示
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_encode(ggml_metal_op_t ctx, int idx);

//
// available ops:
//

// tokens per expert
// 函数: ggml_metal_op_mul_mat_id_extra_tpe
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_mul_mat_id_extra_tpe
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_metal_op_mul_mat_id_extra_tpe(const struct ggml_tensor * op);

// id map [n_tokens, n_expert]
// 函数: ggml_metal_op_mul_mat_id_extra_ids
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_mul_mat_id_extra_ids
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_metal_op_mul_mat_id_extra_ids(const struct ggml_tensor * op);

// return true if we should use the FA vector kernel for this op
// 函数: ggml_metal_op_flash_attn_ext_use_vec
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_flash_attn_ext_use_vec
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_metal_op_flash_attn_ext_use_vec(const struct ggml_tensor * op);

// 函数: ggml_metal_op_flash_attn_ext_extra_pad
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_flash_attn_ext_extra_pad
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_metal_op_flash_attn_ext_extra_pad(const struct ggml_tensor * op);
// 函数: ggml_metal_op_flash_attn_ext_extra_blk
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_flash_attn_ext_extra_blk
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_metal_op_flash_attn_ext_extra_blk(const struct ggml_tensor * op);
// 函数: ggml_metal_op_flash_attn_ext_extra_tmp
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_flash_attn_ext_extra_tmp
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_metal_op_flash_attn_ext_extra_tmp(const struct ggml_tensor * op);

// 函数: ggml_metal_op_concat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_concat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_concat            (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_repeat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_repeat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_repeat            (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_acc
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_acc
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_acc               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_unary
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_unary
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_unary             (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_glu
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_glu
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_glu               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_sum
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_sum
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_sum               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_sum_rows
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_sum_rows
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_sum_rows          (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_cumsum
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_cumsum
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_cumsum            (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_get_rows
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_get_rows
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_get_rows          (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_set_rows
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_set_rows
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_set_rows          (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_diag
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_diag
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_diag              (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_soft_max
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_soft_max
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_soft_max          (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_ssm_conv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_ssm_conv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_ssm_conv          (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_ssm_scan
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_ssm_scan
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_ssm_scan          (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_rwkv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_rwkv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_rwkv              (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_solve_tri
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_solve_tri
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_solve_tri         (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_set
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_set
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_set               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_cpy
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_cpy
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_cpy               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_pool_1d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_pool_1d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_pool_1d           (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_pool_2d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_pool_2d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_pool_2d           (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_mul_mat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_mul_mat
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_mul_mat           (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_mul_mat_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_mul_mat_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_mul_mat_id        (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_add_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_add_id
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_add_id            (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_flash_attn_ext
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_flash_attn_ext
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_flash_attn_ext    (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_bin
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_bin
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_bin               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_l2_norm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_l2_norm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_l2_norm           (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_group_norm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_group_norm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_group_norm        (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_norm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_norm
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_norm              (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_rope
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_rope
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_rope              (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_im2col
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_im2col
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_im2col            (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_conv_2d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_conv_2d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_conv_2d           (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_conv_transpose_1d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_conv_transpose_1d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_conv_transpose_1d (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_conv_transpose_2d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_conv_transpose_2d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_conv_transpose_2d (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_upscale
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_upscale
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_upscale           (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_pad
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_pad
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_pad               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_pad_reflect_1d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_pad_reflect_1d
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_pad_reflect_1d    (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_arange
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_arange
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_arange            (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_timestep_embedding
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_timestep_embedding
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_timestep_embedding(ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_argmax
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_argmax
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_argmax            (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_argsort
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_argsort
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_argsort           (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_top_k
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_top_k
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_top_k             (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_tri
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_tri
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_tri               (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_opt_step_adamw
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_opt_step_adamw
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_opt_step_adamw    (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_opt_step_sgd
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_opt_step_sgd
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_opt_step_sgd      (ggml_metal_op_t ctx, int idx);
// 函数: ggml_metal_op_count_equal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_metal_op_count_equal
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int ggml_metal_op_count_equal       (ggml_metal_op_t ctx, int idx);

#ifdef __cplusplus
}
#endif
