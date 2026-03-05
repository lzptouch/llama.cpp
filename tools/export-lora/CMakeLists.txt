// ============================================================================
// 文件: CMakeLists.txt
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/export-lora/CMakeLists.txt
// 作者: 自动注释工具
// 描述: 工具文件,包含各种实用工具
// ============================================================================

set(TARGET llama-export-lora)
add_executable(${TARGET} export-lora.cpp)
target_link_libraries(${TARGET} PRIVATE common llama ${CMAKE_THREAD_LIBS_INIT})
target_compile_features(${TARGET} PRIVATE cxx_std_17)

if(LLAMA_TOOLS_INSTALL)
    install(TARGETS ${TARGET} RUNTIME)
endif()
