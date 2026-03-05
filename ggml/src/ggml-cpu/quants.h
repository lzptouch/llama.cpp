#pragma once

#define GGML_COMMON_DECL_C
#include "ggml-common.h"

#include "ggml.h"

// GGML CPU internal header

#ifdef __cplusplus
extern "C" {
#endif

// Quantization
// 函数: quantize_row_q4_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q4_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q4_0(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q4_1
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q4_1
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q4_1(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q5_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q5_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q5_0(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q5_1
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q5_1
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q5_1(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q8_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q8_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q8_0(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q8_1
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q8_1
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q8_1(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);

// 函数: quantize_row_mxfp4
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_mxfp4
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_mxfp4(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);

// 函数: quantize_row_q2_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q2_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q2_K(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q3_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q3_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q3_K(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q4_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q4_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q4_K(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q5_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q5_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q5_K(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q6_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q6_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q6_K(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_q8_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q8_K
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q8_K(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);

// 函数: quantize_row_tq1_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_tq1_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_tq1_0(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_tq2_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_tq2_0
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_tq2_0(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);

// 函数: quantize_row_iq4_nl
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_iq4_nl
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_iq4_nl (const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: quantize_row_iq4_xs
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_iq4_xs
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_iq4_xs (const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);

// Dot product
// 函数: ggml_vec_dot_q4_0_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q4_0_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q4_0_q8_0(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q4_1_q8_1
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q4_1_q8_1
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q4_1_q8_1(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q5_0_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q5_0_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q5_0_q8_0(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q5_1_q8_1
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q5_1_q8_1
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q5_1_q8_1(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q8_0_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q8_0_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q8_0_q8_0(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// 函数: ggml_vec_dot_mxfp4_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_mxfp4_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_mxfp4_q8_0(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// 函数: ggml_vec_dot_q2_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q2_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q2_K_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q3_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q3_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q3_K_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q4_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q4_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q4_K_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q5_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q5_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q5_K_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q6_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q6_K_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q6_K_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// 函数: ggml_vec_dot_tq1_0_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_tq1_0_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_tq1_0_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_tq2_0_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_tq2_0_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_tq2_0_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// 函数: ggml_vec_dot_iq2_xxs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq2_xxs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq2_xxs_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq2_xs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq2_xs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq2_xs_q8_K (int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq2_s_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq2_s_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq2_s_q8_K  (int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq3_xxs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq3_xxs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq3_xxs_q8_K(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq1_s_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq1_s_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq1_s_q8_K  (int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq1_m_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq1_m_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq1_m_q8_K  (int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq4_nl_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq4_nl_q8_0
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq4_nl_q8_0 (int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq4_xs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq4_xs_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq4_xs_q8_K (int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq3_s_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq3_s_q8_K
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq3_s_q8_K  (int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// Generic implementation
// 函数: quantize_row_q8_0_generic
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q8_0_generic
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q8_0_generic(const float * GGML_RESTRICT x, void * GGML_RESTRICT vy, int64_t k);
// 函数: quantize_row_q8_1_generic
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q8_1_generic
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q8_1_generic(const float * GGML_RESTRICT x, void * GGML_RESTRICT vy, int64_t k);
// 函数: quantize_row_q8_K_generic
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_row_q8_K_generic
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_row_q8_K_generic(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
// 函数: ggml_vec_dot_q4_0_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q4_0_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q4_0_q8_0_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q4_1_q8_1_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q4_1_q8_1_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q4_1_q8_1_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q5_0_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q5_0_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q5_0_q8_0_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q5_1_q8_1_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q5_1_q8_1_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q5_1_q8_1_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q8_0_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q8_0_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q8_0_q8_0_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// 函数: ggml_vec_dot_mxfp4_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_mxfp4_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_mxfp4_q8_0_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// 函数: ggml_vec_dot_tq1_0_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_tq1_0_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_tq1_0_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_tq2_0_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_tq2_0_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_tq2_0_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

// 函数: ggml_vec_dot_q2_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q2_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q2_K_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q3_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q3_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q3_K_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q4_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q4_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q4_K_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_q5_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q5_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q5_K_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy,  size_t by, int nrc);
// 函数: ggml_vec_dot_q6_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_q6_K_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_q6_K_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq2_xxs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq2_xxs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq2_xxs_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq2_xs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq2_xs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq2_xs_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq2_s_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq2_s_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq2_s_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq3_xxs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq3_xxs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq3_xxs_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq3_s_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq3_s_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq3_s_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq1_s_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq1_s_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq1_s_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq1_m_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq1_m_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq1_m_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq4_nl_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq4_nl_q8_0_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq4_nl_q8_0_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);
// 函数: ggml_vec_dot_iq4_xs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_vec_dot_iq4_xs_q8_K_generic
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_vec_dot_iq4_xs_q8_K_generic(int n, float * GGML_RESTRICT s, size_t bs, const void * GGML_RESTRICT vx, size_t bx, const void * GGML_RESTRICT vy, size_t by, int nrc);

#ifdef __cplusplus
}
#endif
