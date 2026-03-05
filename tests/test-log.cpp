// ============================================================================
// 文件: test-log.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tests/test-log.cpp
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

#include "log.h"

#include <cstdlib>
#include <thread>

// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int main() {
    const int n_thread = 8;

    std::thread threads[n_thread];
    for (int i = 0; i < n_thread; i++) {
        threads[i] = std::thread([i]() {
            const int n_msg = 1000;

            for (int j = 0; j < n_msg; j++) {
                const int log_type = std::rand() % 4;

                switch (log_type) {
                    case 0: LOG_INF("Thread %d: %d\n", i, j); break;
                    case 1: LOG_WRN("Thread %d: %d\n", i, j); break;
                    case 2: LOG_ERR("Thread %d: %d\n", i, j); break;
                    case 3: LOG_DBG("Thread %d: %d\n", i, j); break;
                    default:
                        break;
                }

                if (rand () % 10 < 5) {
                    common_log_set_timestamps(common_log_main(), rand() % 2);
                    common_log_set_prefix    (common_log_main(), rand() % 2);
                }
            }
        });
    }

    for (int i = 0; i < n_thread; i++) {
        threads[i].join();
    }

    return 0;
}
