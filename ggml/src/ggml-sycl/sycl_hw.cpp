// ============================================================================
// 文件: sycl_hw.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-sycl/sycl_hw.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "sycl_hw.hpp"

// TODO: currently not used
/*
// 函数: get_device_hw_info
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
// 函数: get_device_hw_info
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
sycl_hw_info get_device_hw_info(sycl::device *device_ptr) {
  sycl_hw_info res;
  int32_t id = device_ptr->get_info<sycl::ext::intel::info::device::device_id>();
  res.device_id = id;

  syclex::architecture arch = device_ptr->get_info<syclex::info::device::architecture>();
  res.arch = arch;

  return res;
}
*/
