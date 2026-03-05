#pragma once

#include "ggml.h"
#include "traits.h"
#include "ggml-cpu-impl.h"
#include "ggml-impl.h"
#include "simd-mappings.h"

#define GGML_FA_TILE_Q  64
#define GGML_FA_TILE_KV 64

#ifdef __cplusplus

#include <utility>

// convenience functions/macros for use in template calls
// note: these won't be required after the 'traits' lookup table is used.
// 函数: f32_to_f16
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: f32_to_f16
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline ggml_fp16_t f32_to_f16(float x) {
    return GGML_CPU_FP32_TO_FP16(x);
}

// 函数: f16_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: f16_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline float f16_to_f32(ggml_fp16_t x) {
    return GGML_CPU_FP16_TO_FP32(x);
}

// 函数: f32_to_bf16
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: f32_to_bf16
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline ggml_bf16_t f32_to_bf16(float x) {
    return GGML_FP32_TO_BF16(x);
}

// 函数: bf16_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: bf16_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline float bf16_to_f32(ggml_bf16_t x) {
    return GGML_BF16_TO_FP32(x);
}

// 函数: i32_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: i32_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline float i32_to_f32(int32_t x) {
    return x;
}

// 函数: f32_to_i32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: f32_to_i32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline int32_t f32_to_i32(float x) {
    return x;
}

// 函数: f32_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: f32_to_f32
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline float f32_to_f32(float x) {
    return x;
}

// TODO - merge this into the traits table, after using row-based conversions
template <class T>
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
struct type_conversion_table;

template <>
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
struct type_conversion_table<ggml_fp16_t> {
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr float (*to_f32)(ggml_fp16_t) = f16_to_f32;
    // 函数: ggml_fp16_t
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ggml_fp16_t
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr ggml_fp16_t (*from_f32)(float) = f32_to_f16;
};

template <>
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
struct type_conversion_table<float> {
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr float (*to_f32)(float) = f32_to_f32;
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr float (*from_f32)(float) = f32_to_f32;
};

template <>
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
struct type_conversion_table<ggml_bf16_t> {
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr float (*to_f32)(ggml_bf16_t) = bf16_to_f32;
    // 函数: ggml_bf16_t
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ggml_bf16_t
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr ggml_bf16_t (*from_f32)(float) = f32_to_bf16;
};

template <>
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
// 类: type_conversion_table
// 描述: type_conversion_table类提供相关功能
// 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
    // 结构体: type_conversion_table
    // 描述: type_conversion_table结构体提供相关功能
    // 用途: 用于处理type_conversion_table相关的操作
struct type_conversion_table<int32_t> {
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: float
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr float (*to_f32)(int32_t) = i32_to_f32;
    // 函数: int32_t
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: int32_t
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static constexpr int32_t (*from_f32)(float) = f32_to_i32;
};

static std::pair<int64_t, int64_t> get_thread_range(const struct ggml_compute_params * params, const struct ggml_tensor * src0) {
    const int64_t ith = params->ith;
    const int64_t nth = params->nth;

    const int64_t nr  = ggml_nrows(src0);

    // rows per thread
    const int64_t dr = (nr + nth - 1)/nth;

    // row range for this thread
    const int64_t ir0 = dr*ith;
    const int64_t ir1 = MIN(ir0 + dr, nr);

    return {ir0, ir1};
}

// 类: ggml_fa_tile_config
// 描述: ggml_fa_tile_config类提供相关功能
// 用途: 用于处理ggml_fa_tile_config相关的操作
// 类: ggml_fa_tile_config
// 描述: ggml_fa_tile_config类提供相关功能
// 用途: 用于处理ggml_fa_tile_config相关的操作
    // 结构体: ggml_fa_tile_config
    // 描述: ggml_fa_tile_config结构体提供相关功能
    // 用途: 用于处理ggml_fa_tile_config相关的操作
    // 结构体: ggml_fa_tile_config
    // 描述: ggml_fa_tile_config结构体提供相关功能
    // 用途: 用于处理ggml_fa_tile_config相关的操作
    // 结构体: ggml_fa_tile_config
    // 描述: ggml_fa_tile_config结构体提供相关功能
    // 用途: 用于处理ggml_fa_tile_config相关的操作
    // 结构体: ggml_fa_tile_config
    // 描述: ggml_fa_tile_config结构体提供相关功能
    // 用途: 用于处理ggml_fa_tile_config相关的操作
struct ggml_fa_tile_config {
    static constexpr size_t Q  = GGML_FA_TILE_Q;
    static constexpr size_t KV = GGML_FA_TILE_KV;
};

#endif
