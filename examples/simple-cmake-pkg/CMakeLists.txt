// ============================================================================
// 文件: CMakeLists.txt
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/simple-cmake-pkg/CMakeLists.txt
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

cmake_minimum_required(VERSION 3.12)
project(llama-simple-cmake-pkg)

set(TARGET llama-simple-cmake-pkg)

find_package(Llama REQUIRED)

add_executable(${TARGET} ${CMAKE_CURRENT_LIST_DIR}/../simple/simple.cpp)
install(TARGETS ${TARGET} RUNTIME)
target_link_libraries(${TARGET} PRIVATE llama ggml::all ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(${TARGET} PRIVATE cxx_std_17)
