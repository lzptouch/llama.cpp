// ============================================================================
// 文件: CMakeLists.txt
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/pocs/CMakeLists.txt
// 作者: 自动注释工具
// 描述: 配置或脚本文件
// ============================================================================

# dependencies

find_package(Threads REQUIRED)

# third-party

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (EMSCRIPTEN)
else()
    if (NOT GGML_BACKEND_DL)
        add_subdirectory(vdot)
    endif()
endif()
