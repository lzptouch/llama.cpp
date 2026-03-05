// ============================================================================
// 文件: cpu-feats.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-cpu/arch/s390/cpu-feats.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-backend-impl.h"

#if defined(__s390x__)
#include <sys/auxv.h>

// find hwcap bits in asm/elf.h
#ifndef HWCAP_VXRS_EXT2
#define HWCAP_VXRS_EXT2 (1 << 15)
#endif

#ifndef HWCAP_NNPA
#define HWCAP_NNPA (1 << 20)
#endif

// 类: s390x_features
// 描述: s390x_features类提供相关功能
// 用途: 用于处理s390x_features相关的操作
// 类: s390x_features
// 描述: s390x_features类提供相关功能
// 用途: 用于处理s390x_features相关的操作
    // 结构体: s390x_features
    // 描述: s390x_features结构体提供相关功能
    // 用途: 用于处理s390x_features相关的操作
    // 结构体: s390x_features
    // 描述: s390x_features结构体提供相关功能
    // 用途: 用于处理s390x_features相关的操作
    // 结构体: s390x_features
    // 描述: s390x_features结构体提供相关功能
    // 用途: 用于处理s390x_features相关的操作
    // 结构体: s390x_features
    // 描述: s390x_features结构体提供相关功能
    // 用途: 用于处理s390x_features相关的操作
struct s390x_features {
    bool has_vxe2 = false;
    bool has_nnpa = false;

    s390x_features() {
        uint32_t hwcap = getauxval(AT_HWCAP);
        // NOTE: use hwcap2 with DFLT for z17 and later
        // uint32_t hwcap2 = getauxval(AT_HWCAP2);

        has_vxe2 = !!(hwcap & HWCAP_VXRS_EXT2);
        has_nnpa = !!(hwcap & HWCAP_NNPA);
    }
};

// 函数: ggml_backend_cpu_s390x_score
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_cpu_s390x_score
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static int ggml_backend_cpu_s390x_score() {
    int score = 1;
    s390x_features sf;

// IBM z15 / LinuxONE 3
#ifdef GGML_USE_VXE2
    if (!sf.has_vxe2) { return 0; }
    score += 1 << 1;
#endif

// IBM z16 / LinuxONE 4 and z17 / LinuxONE 5
#ifdef GGML_USE_NNPA
    if (!sf.has_nnpa) { return 0; }
    score += 1 << 2;
#endif

    return score;
}

GGML_BACKEND_DL_SCORE_IMPL(ggml_backend_cpu_s390x_score)

#endif  // __s390x__
