// ============================================================================
// 文件: CMakeLists.txt
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-rpc/CMakeLists.txt
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

message(STATUS "Using RPC backend")

ggml_add_backend_library(ggml-rpc
                         ggml-rpc.cpp
                        )

if (WIN32)
    target_link_libraries(ggml-rpc PRIVATE ws2_32)
endif()
