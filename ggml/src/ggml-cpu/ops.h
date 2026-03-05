#pragma once

#include "ggml.h"

//
// cache line
//

#if defined(__cpp_lib_hardware_interference_size)
#define CACHE_LINE_SIZE std::hardware_destructive_interference_size
#else
#if defined(__POWER9_VECTOR__)
#define CACHE_LINE_SIZE 128
#elif defined(__VXE__) || defined(__VXE2__)
#define CACHE_LINE_SIZE 256
#else
#define CACHE_LINE_SIZE 64
#endif
#endif

static const size_t CACHE_LINE_SIZE_F32 = CACHE_LINE_SIZE/sizeof(float);

// Work buffer size for im2col operations in CONV2D
#define GGML_IM2COL_WORK_SIZE (16 * 1024 * 1024)

#ifdef __cplusplus
extern "C" {
#endif

// 函数: ggml_compute_forward_dup
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_dup
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_dup(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_add
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_add
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_add(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_add_id
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_add_id
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_add_id(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_add1
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_add1
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_add1(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_acc
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_acc
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_acc(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_sum
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_sum
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_sum(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_sum_rows
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_sum_rows
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_sum_rows(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_cumsum
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_cumsum
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_cumsum(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_mean
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_mean
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_mean(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_argmax
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_argmax
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_argmax(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_count_equal
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_count_equal
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_count_equal(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_repeat
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_repeat
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_repeat(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_repeat_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_repeat_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_repeat_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_concat
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_concat
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_concat(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_silu_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_silu_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_silu_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_norm(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_rms_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_rms_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_rms_norm(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_rms_norm_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_rms_norm_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_rms_norm_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_group_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_group_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_group_norm(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_l2_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_l2_norm
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_l2_norm(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_out_prod
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_out_prod
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_out_prod(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_scale
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_scale
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_scale(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_set
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_set
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_set(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_cpy
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_cpy
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_cpy(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_cont
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_cont
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_cont(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_get_rows
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_get_rows
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_get_rows(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_get_rows_back
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_get_rows_back
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_get_rows_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_set_rows
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_set_rows
// 描述: 设置: 设置某个属性或配置
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_set_rows(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_diag
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_diag
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_diag(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_diag_mask_inf
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_diag_mask_inf
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_diag_mask_inf(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_diag_mask_zero
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_diag_mask_zero
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_diag_mask_zero(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_soft_max
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_soft_max
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_soft_max(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_soft_max_ext_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_soft_max_ext_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_soft_max_ext_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_rope
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_rope
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_rope(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_rope_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_rope_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_rope_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_clamp
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_clamp
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_clamp(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_conv_transpose_1d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_conv_transpose_1d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_conv_transpose_1d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_im2col
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_im2col
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_im2col(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_im2col_back_f32
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_im2col_back_f32
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_im2col_back_f32(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_im2col_3d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_im2col_3d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_im2col_3d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_conv_2d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_conv_2d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_conv_2d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_conv_3d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_conv_3d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_conv_3d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_conv_transpose_2d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_conv_transpose_2d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_conv_transpose_2d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_conv_2d_dw
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_conv_2d_dw
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_conv_2d_dw(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_pool_1d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_pool_1d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_pool_1d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_pool_2d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_pool_2d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_pool_2d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_pool_2d_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_pool_2d_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_pool_2d_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_upscale
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_upscale
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_upscale(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_pad
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_pad
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_pad(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_pad_reflect_1d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_pad_reflect_1d
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_pad_reflect_1d(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_roll
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_roll
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_roll(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_arange
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_arange
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_arange(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_timestep_embedding
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_timestep_embedding
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_timestep_embedding(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_argsort
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_argsort
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_argsort(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_top_k
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_top_k
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_top_k(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_leaky_relu
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_leaky_relu
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_leaky_relu(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_tri
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_tri
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_tri(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_fill
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_fill
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_fill(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_flash_attn_ext
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_flash_attn_ext
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_flash_attn_ext(const struct ggml_compute_params * params, struct ggml_tensor * dst);
void ggml_compute_forward_flash_attn_back(
        const struct ggml_compute_params * params,
        const bool masked,
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
        // 类: ggml_tensor
        // 描述: ggml_tensor类提供相关功能
        // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
    // 结构体: ggml_tensor
    // 描述: ggml_tensor结构体提供相关功能
    // 用途: 用于处理ggml_tensor相关的操作
        struct ggml_tensor * dst);
// 函数: ggml_compute_forward_ssm_conv
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_ssm_conv
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_ssm_conv(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_ssm_scan
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_ssm_scan
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_ssm_scan(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_win_part
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_win_part
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_win_part(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_win_unpart
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_win_unpart
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_win_unpart(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_unary
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_unary
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_unary(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_glu
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_glu
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_glu(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_get_rel_pos
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_get_rel_pos
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_get_rel_pos(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_add_rel_pos
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_add_rel_pos
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_add_rel_pos(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_rwkv_wkv6
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_rwkv_wkv6
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_rwkv_wkv6(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_rwkv_wkv7
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_rwkv_wkv7
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_rwkv_wkv7(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_solve_tri
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_solve_tri
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_solve_tri(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_gla
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_gla
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_gla(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_map_custom1
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_map_custom1
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_map_custom1(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_map_custom2
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_map_custom2
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_map_custom2(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_map_custom3
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_map_custom3
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_map_custom3(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_custom
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_custom
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_custom(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_cross_entropy_loss
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_cross_entropy_loss
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_cross_entropy_loss(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_cross_entropy_loss_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_cross_entropy_loss_back
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_cross_entropy_loss_back(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_opt_step_adamw
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_opt_step_adamw
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_opt_step_adamw(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_mul_mat
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_mul_mat
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_mul_mat(const struct ggml_compute_params * params, struct ggml_tensor * dst);
// 函数: ggml_compute_forward_opt_step_sgd
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_compute_forward_opt_step_sgd
// 描述: 前向传播: 执行神经网络的前向传播
// 参数: 无参数
// 返回: 无返回值
void ggml_compute_forward_opt_step_sgd(const struct ggml_compute_params * params, struct ggml_tensor * dst);
#ifdef __cplusplus
}
#endif
