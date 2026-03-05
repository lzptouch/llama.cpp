#pragma once

#include <cstddef>

namespace sqnbitgemm_spacemit_ime {
namespace ime1 {
size_t gemm_kernel_i8i4(size_t            blk_len,
                        const std::byte * quant_a_ptr,
                        const std::byte * quant_b_data,
                        const float *     quant_b_scale,
                        const std::byte * quant_b_zp,
                        float *           c_ptr,
                        size_t            count_m,
                        size_t            count_n,
                        size_t            count_k,
                        size_t            block_count_k,
                        size_t            ldc,
                        const float *     bias,
                        const size_t      scale_stride);

// 函数: quantize_a_row_i8
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_a_row_i8
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_a_row_i8(size_t blk_len, const float * a_ptr, size_t count_k, std::byte * quant_a_ptr);

// 函数: quantize_a_4row_i8
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
// 函数: quantize_a_4row_i8
// 描述: 量化: 对数据进行量化处理
// 参数: 无参数
// 返回: 无返回值
void quantize_a_4row_i8(size_t blk_len, const float * a_ptr, size_t count_k, std::byte * quant_a_ptr);

}  // namespace ime1
}  // namespace sqnbitgemm_spacemit_ime
