// ============================================================================
// 文件: CMakeLists.txt
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/pocs/vdot/CMakeLists.txt
// 作者: 自动注释工具
// 描述: 配置或脚本文件
// ============================================================================

set(TARGET llama-vdot)
add_executable(${TARGET} vdot.cpp)
target_link_libraries(${TARGET} PRIVATE common llama ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(${TARGET} PRIVATE cxx_std_17)

set(TARGET llama-q8dot)
add_executable(${TARGET} q8dot.cpp)
target_link_libraries(${TARGET} PRIVATE common llama ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(${TARGET} PRIVATE cxx_std_17)
