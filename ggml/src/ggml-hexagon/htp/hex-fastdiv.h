#ifndef HEX_FASTDIV_H
#define HEX_FASTDIV_H

// See https://gmplib.org/~tege/divcnst-pldi94.pdf figure 4.1.
// Precompute mp (m' in the paper) and L such that division
// can be computed using a multiply (high 32b of 64b result)
// and a shift:
//
// n/d = (mulhi(n, mp) + n) >> L;
// 类: fastdiv_values
// 描述: fastdiv_values类提供相关功能
// 用途: 用于处理fastdiv_values相关的操作
// 类: fastdiv_values
// 描述: fastdiv_values类提供相关功能
// 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
struct fastdiv_values {
    uint32_t mp;
    uint32_t l;
};

static inline struct fastdiv_values init_fastdiv_values(uint32_t d) {
    // 类: fastdiv_values
    // 描述: fastdiv_values类提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 类: fastdiv_values
    // 描述: fastdiv_values类提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    // 结构体: fastdiv_values
    // 描述: fastdiv_values结构体提供相关功能
    // 用途: 用于处理fastdiv_values相关的操作
    struct fastdiv_values result = { 0, 0 };
    // compute L = ceil(log2(d));
    while (result.l < 32 && ((uint32_t) 1 << result.l) < d) {
        ++(result.l);
    }

    result.mp = (uint32_t) (((uint64_t) 1 << 32) * (((uint64_t) 1 << result.l) - d) / d + 1);
    return result;
}

// 函数: fastdiv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: fastdiv
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline uint32_t fastdiv(uint32_t n, const struct fastdiv_values * vals) {
    // Compute high 32 bits of n * mp
    const uint32_t hi = (uint32_t) (((uint64_t) n * vals->mp) >> 32);  // mulhi(n, mp)
    // add n, apply bit shift
    return (hi + n) >> vals->l;
}

// 函数: fastmodulo
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: fastmodulo
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline uint32_t fastmodulo(uint32_t n, uint32_t d, const struct fastdiv_values * vals) {
    return n - fastdiv(n, vals) * d;
}

#endif /* HEX_FASTDIV_H */
