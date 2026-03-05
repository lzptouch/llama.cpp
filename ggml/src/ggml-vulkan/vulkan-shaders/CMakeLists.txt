// ============================================================================
// 文件: CMakeLists.txt
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-vulkan/vulkan-shaders/CMakeLists.txt
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

cmake_minimum_required(VERSION 3.19)
project("vulkan-shaders-gen" C CXX)

find_package (Threads REQUIRED)

if (GGML_VULKAN_COOPMAT_GLSLC_SUPPORT)
    add_compile_definitions(GGML_VULKAN_COOPMAT_GLSLC_SUPPORT)
    message(STATUS "Enabling coopmat glslc support")
endif()
if (GGML_VULKAN_COOPMAT2_GLSLC_SUPPORT)
    add_compile_definitions(GGML_VULKAN_COOPMAT2_GLSLC_SUPPORT)
    message(STATUS "Enabling coopmat2 glslc support")
endif()
if (GGML_VULKAN_INTEGER_DOT_GLSLC_SUPPORT)
    add_compile_definitions(GGML_VULKAN_INTEGER_DOT_GLSLC_SUPPORT)
    message(STATUS "Enabling dot glslc support")
endif()
if (GGML_VULKAN_BFLOAT16_GLSLC_SUPPORT)
    add_compile_definitions(GGML_VULKAN_BFLOAT16_GLSLC_SUPPORT)
    message(STATUS "Enabling bfloat16 glslc support")
endif()
if (GGML_VULKAN_SHADER_DEBUG_INFO)
    add_compile_definitions(GGML_VULKAN_SHADER_DEBUG_INFO)
    message(STATUS "Enabling shader debug info")
endif()

set(TARGET vulkan-shaders-gen)
add_executable(${TARGET} vulkan-shaders-gen.cpp)
install(TARGETS ${TARGET} RUNTIME)
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_link_libraries(vulkan-shaders-gen PUBLIC Threads::Threads)
