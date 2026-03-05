// ============================================================================
// 文件: cpu-feats.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-cpu/arch/powerpc/cpu-feats.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

# include "ggml-backend-impl.h"

#if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__)

#if defined(__linux__)
#include <sys/auxv.h>
#endif

#include <string>

// 类: powerpc_features
// 描述: powerpc_features类提供相关功能
// 用途: 用于处理powerpc_features相关的操作
// 类: powerpc_features
// 描述: powerpc_features类提供相关功能
// 用途: 用于处理powerpc_features相关的操作
    // 结构体: powerpc_features
    // 描述: powerpc_features结构体提供相关功能
    // 用途: 用于处理powerpc_features相关的操作
    // 结构体: powerpc_features
    // 描述: powerpc_features结构体提供相关功能
    // 用途: 用于处理powerpc_features相关的操作
    // 结构体: powerpc_features
    // 描述: powerpc_features结构体提供相关功能
    // 用途: 用于处理powerpc_features相关的操作
    // 结构体: powerpc_features
    // 描述: powerpc_features结构体提供相关功能
    // 用途: 用于处理powerpc_features相关的操作
struct powerpc_features {
    std::string platform = "";
    int power_version    = -1;

    bool has_vsx         = false;

    powerpc_features() {
#if defined(__linux__)
        unsigned long auxval = getauxval(AT_PLATFORM);
        if (auxval) {
            platform = std::string(reinterpret_cast<const char*>(auxval));
            // TBD: Do systems exist that return this in uppercase?
            if (platform.substr(0, 5) == "power") {
                // Extractt a numeric suffix, if one exists
                int vpos = -1;
                for (int i = platform.length() - 1; i >= 0; i--) {
                    if (std::isdigit(platform[i])) {
                        vpos = i;
                    } else {
                        break;
                    }
                }
                if (vpos > -1) {
                    power_version = std::stoi(platform.substr(vpos));
                }
            }
        }
#endif
        if (power_version >= 9) {
            has_vsx = true;
        }
    }
};

// 函数: ggml_backend_cpu_powerpc_score
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_cpu_powerpc_score
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static int ggml_backend_cpu_powerpc_score() {
    int score = 1;
    powerpc_features pf;

// Platform scores
#if defined(GGML_USE_POWER7)
    if (pf.power_version < 7) { return 0; }
    score += 1<<1;
#endif
#if defined(GGML_USE_POWER8)
    if (pf.power_version < 8) { return 0; }
    score += 1<<2;
#endif
#if defined(GGML_USE_POWER9)
    if (pf.power_version < 9) { return 0; }
    score += 1<<3;
#endif
#if defined(GGML_USE_POWER10)
    if (pf.power_version < 10) { return 0; }
    score += 1<<4;
#endif
#if defined(GGML_USE_POWER11)
    if (pf.power_version < 11) { return 0; }
    score += 1<<5;
#endif

// Feature scores
#if defined(GGML_USE_VSX)
    if (!pf.has_vsx) { return 0; }
    score += 1<<6;
#endif

    return score;
}

GGML_BACKEND_DL_SCORE_IMPL(ggml_backend_cpu_powerpc_score)

#endif // defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__)
