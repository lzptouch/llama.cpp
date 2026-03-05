// ============================================================================
// 文件: CMakeLists.txt
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/diffusion/CMakeLists.txt
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

set(TARGET llama-diffusion-cli)
add_executable(${TARGET} diffusion-cli.cpp)
install(TARGETS ${TARGET} RUNTIME)
target_link_libraries(${TARGET} PRIVATE llama common ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(${TARGET} PRIVATE cxx_std_17)
