// ============================================================================
// 文件: cpu-feats.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-cpu/arch/riscv/cpu-feats.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-backend-impl.h"

#if defined(__riscv) && __riscv_xlen == 64
#include <asm/hwprobe.h>
#include <asm/unistd.h>
#include <unistd.h>

// 类: riscv64_features
// 描述: riscv64_features类提供相关功能
// 用途: 用于处理riscv64_features相关的操作
// 类: riscv64_features
// 描述: riscv64_features类提供相关功能
// 用途: 用于处理riscv64_features相关的操作
    // 结构体: riscv64_features
    // 描述: riscv64_features结构体提供相关功能
    // 用途: 用于处理riscv64_features相关的操作
    // 结构体: riscv64_features
    // 描述: riscv64_features结构体提供相关功能
    // 用途: 用于处理riscv64_features相关的操作
    // 结构体: riscv64_features
    // 描述: riscv64_features结构体提供相关功能
    // 用途: 用于处理riscv64_features相关的操作
    // 结构体: riscv64_features
    // 描述: riscv64_features结构体提供相关功能
    // 用途: 用于处理riscv64_features相关的操作
struct riscv64_features {
    bool has_rvv = false;

    riscv64_features() {
        // 类: riscv_hwprobe
        // 描述: riscv_hwprobe类提供相关功能
        // 用途: 用于处理riscv_hwprobe相关的操作
        // 类: riscv_hwprobe
        // 描述: riscv_hwprobe类提供相关功能
        // 用途: 用于处理riscv_hwprobe相关的操作
    // 结构体: riscv_hwprobe
    // 描述: riscv_hwprobe结构体提供相关功能
    // 用途: 用于处理riscv_hwprobe相关的操作
    // 结构体: riscv_hwprobe
    // 描述: riscv_hwprobe结构体提供相关功能
    // 用途: 用于处理riscv_hwprobe相关的操作
    // 结构体: riscv_hwprobe
    // 描述: riscv_hwprobe结构体提供相关功能
    // 用途: 用于处理riscv_hwprobe相关的操作
    // 结构体: riscv_hwprobe
    // 描述: riscv_hwprobe结构体提供相关功能
    // 用途: 用于处理riscv_hwprobe相关的操作
        struct riscv_hwprobe probe;
        probe.key = RISCV_HWPROBE_KEY_IMA_EXT_0;
        probe.value = 0;

        int ret = syscall(__NR_riscv_hwprobe, &probe, 1, 0, NULL, 0);

        if (0 == ret) {
            has_rvv = !!(probe.value & RISCV_HWPROBE_IMA_V);
        }
    }
};

// 函数: ggml_backend_cpu_riscv64_score
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_cpu_riscv64_score
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static int ggml_backend_cpu_riscv64_score() {
    int score = 1;
    riscv64_features rf;

#ifdef GGML_USE_RVV
    if (!rf.has_rvv) { return 0; }
    score += 1 << 1;
#endif

    return score;
}

GGML_BACKEND_DL_SCORE_IMPL(ggml_backend_cpu_riscv64_score)

#endif  // __riscv && __riscv_xlen == 64
