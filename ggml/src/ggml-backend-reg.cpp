// ============================================================================
// 文件: ggml-backend-reg.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-backend-reg.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-backend-impl.h"
#include "ggml-backend.h"
#include "ggml-backend-dl.h"
#include "ggml-impl.h"
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>
#include <cctype>

#ifdef _WIN32
#    define WIN32_LEAN_AND_MEAN
#    ifndef NOMINMAX
#        define NOMINMAX
#    endif
#    include <windows.h>
#elif defined(__APPLE__)
#    include <mach-o/dyld.h>
#    include <dlfcn.h>
#else
#    include <dlfcn.h>
#    include <unistd.h>
#endif

// Backend registry
#ifdef GGML_USE_CPU
#include "ggml-cpu.h"
#endif

#ifdef GGML_USE_CUDA
#include "ggml-cuda.h"
#endif

#ifdef GGML_USE_METAL
#include "ggml-metal.h"
#endif

#ifdef GGML_USE_SYCL
#include "ggml-sycl.h"
#endif

#ifdef GGML_USE_VULKAN
#include "ggml-vulkan.h"
#endif

#ifdef GGML_USE_WEBGPU
#include "ggml-webgpu.h"
#endif

#ifdef GGML_USE_ZDNN
#include "ggml-zdnn.h"
#endif

#ifdef GGML_USE_OPENCL
#include "ggml-opencl.h"
#endif

#ifdef GGML_USE_HEXAGON
#include "ggml-hexagon.h"
#endif

#ifdef GGML_USE_BLAS
#include "ggml-blas.h"
#endif

#ifdef GGML_USE_RPC
#include "ggml-rpc.h"
#endif

#ifdef GGML_USE_VIRTGPU_FRONTEND
#include "ggml-virtgpu.h"
#endif

#ifdef GGML_USE_CANN
#include "ggml-cann.h"
#endif

#ifdef GGML_USE_ZENDNN
#include "ggml-zendnn.h"
#endif

namespace fs = std::filesystem;

// 函数: path_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: path_str
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static std::string path_str(const fs::path & path) {
    try {
#if defined(__cpp_lib_char8_t)
        // C++20 and later: u8string() returns std::u8string
        const std::u8string u8str = path.u8string();
        return std::string(reinterpret_cast<const char *>(u8str.data()), u8str.size());
#else
        // C++17: u8string() returns std::string
        return path.u8string();
#endif
    } catch (...) {
        return std::string();
    }
}

// 类: ggml_backend_reg_entry
// 描述: ggml_backend_reg_entry类提供相关功能
// 用途: 用于处理ggml_backend_reg_entry相关的操作
// 类: ggml_backend_reg_entry
// 描述: ggml_backend_reg_entry类提供相关功能
// 用途: 用于处理ggml_backend_reg_entry相关的操作
    // 结构体: ggml_backend_reg_entry
    // 描述: ggml_backend_reg_entry结构体提供相关功能
    // 用途: 用于处理ggml_backend_reg_entry相关的操作
    // 结构体: ggml_backend_reg_entry
    // 描述: ggml_backend_reg_entry结构体提供相关功能
    // 用途: 用于处理ggml_backend_reg_entry相关的操作
    // 结构体: ggml_backend_reg_entry
    // 描述: ggml_backend_reg_entry结构体提供相关功能
    // 用途: 用于处理ggml_backend_reg_entry相关的操作
    // 结构体: ggml_backend_reg_entry
    // 描述: ggml_backend_reg_entry结构体提供相关功能
    // 用途: 用于处理ggml_backend_reg_entry相关的操作
struct ggml_backend_reg_entry {
    ggml_backend_reg_t reg;
    dl_handle_ptr handle;
};

// 类: ggml_backend_registry
// 描述: ggml_backend_registry类提供相关功能
// 用途: 用于处理ggml_backend_registry相关的操作
// 类: ggml_backend_registry
// 描述: ggml_backend_registry类提供相关功能
// 用途: 用于处理ggml_backend_registry相关的操作
    // 结构体: ggml_backend_registry
    // 描述: ggml_backend_registry结构体提供相关功能
    // 用途: 用于处理ggml_backend_registry相关的操作
    // 结构体: ggml_backend_registry
    // 描述: ggml_backend_registry结构体提供相关功能
    // 用途: 用于处理ggml_backend_registry相关的操作
    // 结构体: ggml_backend_registry
    // 描述: ggml_backend_registry结构体提供相关功能
    // 用途: 用于处理ggml_backend_registry相关的操作
    // 结构体: ggml_backend_registry
    // 描述: ggml_backend_registry结构体提供相关功能
    // 用途: 用于处理ggml_backend_registry相关的操作
struct ggml_backend_registry {
    std::vector<ggml_backend_reg_entry> backends;
    std::vector<ggml_backend_dev_t> devices;

    ggml_backend_registry() {
#ifdef GGML_USE_CUDA
        register_backend(ggml_backend_cuda_reg());
#endif
#ifdef GGML_USE_METAL
        register_backend(ggml_backend_metal_reg());
#endif
#ifdef GGML_USE_SYCL
        register_backend(ggml_backend_sycl_reg());
#endif
#ifdef GGML_USE_VULKAN
    // Add runtime disable check
    if (getenv("GGML_DISABLE_VULKAN") == nullptr) {
        register_backend(ggml_backend_vk_reg());
    } else {
        GGML_LOG_DEBUG("Vulkan backend disabled by GGML_DISABLE_VULKAN environment variable\n");
    }
#endif
#ifdef GGML_USE_WEBGPU
        register_backend(ggml_backend_webgpu_reg());
#endif
#ifdef GGML_USE_ZDNN
        register_backend(ggml_backend_zdnn_reg());
#endif
#ifdef GGML_USE_VIRTGPU_FRONTEND
        register_backend(ggml_backend_virtgpu_reg());
#endif

#ifdef GGML_USE_OPENCL
        register_backend(ggml_backend_opencl_reg());
#endif
#ifdef GGML_USE_ZENDNN
        register_backend(ggml_backend_zendnn_reg());
#endif
#ifdef GGML_USE_HEXAGON
        register_backend(ggml_backend_hexagon_reg());
#endif
#ifdef GGML_USE_CANN
        register_backend(ggml_backend_cann_reg());
#endif
#ifdef GGML_USE_BLAS
        register_backend(ggml_backend_blas_reg());
#endif
#ifdef GGML_USE_RPC
        register_backend(ggml_backend_rpc_reg());
#endif
#ifdef GGML_USE_CPU
        register_backend(ggml_backend_cpu_reg());
#endif
    }

    ~ggml_backend_registry() {
        // FIXME: backends cannot be safely unloaded without a function to destroy all the backend resources,
        // since backend threads may still be running and accessing resources from the dynamic library
        for (auto & entry : backends) {
            if (entry.handle) {
                entry.handle.release(); // NOLINT
            }
        }
    }

    // 函数: register_backend
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: register_backend
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void register_backend(ggml_backend_reg_t reg, dl_handle_ptr handle = nullptr) {
        if (!reg) {
            return;
        }

#ifndef NDEBUG
        GGML_LOG_DEBUG("%s: registered backend %s (%zu devices)\n",
            __func__, ggml_backend_reg_name(reg), ggml_backend_reg_dev_count(reg));
#endif
        backends.push_back({ reg, std::move(handle) });
        for (size_t i = 0; i < ggml_backend_reg_dev_count(reg); i++) {
            register_device(ggml_backend_reg_dev_get(reg, i));
        }
    }

    // 函数: register_device
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: register_device
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void register_device(ggml_backend_dev_t device) {
#ifndef NDEBUG
        GGML_LOG_DEBUG("%s: registered device %s (%s)\n", __func__, ggml_backend_dev_name(device), ggml_backend_dev_description(device));
#endif
        devices.push_back(device);
    }

    // 函数: load_backend
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_backend
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    ggml_backend_reg_t load_backend(const fs::path & path, bool silent) {
        dl_handle_ptr handle { dl_load_library(path) };
        if (!handle) {
            if (!silent) {
                GGML_LOG_ERROR("%s: failed to load %s: %s\n", __func__, path_str(path).c_str(), dl_error());
            }
            return nullptr;
        }

        auto score_fn = (ggml_backend_score_t) dl_get_sym(handle.get(), "ggml_backend_score");
        if (score_fn && score_fn() == 0) {
            if (!silent) {
                GGML_LOG_INFO("%s: backend %s is not supported on this system\n", __func__, path_str(path).c_str());
            }
            return nullptr;
        }

        auto backend_init_fn = (ggml_backend_init_t) dl_get_sym(handle.get(), "ggml_backend_init");
        if (!backend_init_fn) {
            if (!silent) {
                GGML_LOG_ERROR("%s: failed to find ggml_backend_init in %s\n", __func__, path_str(path).c_str());
            }
            return nullptr;
        }

        ggml_backend_reg_t reg = backend_init_fn();
        if (!reg || reg->api_version != GGML_BACKEND_API_VERSION) {
            if (!silent) {
                if (!reg) {
                    GGML_LOG_ERROR("%s: failed to initialize backend from %s: ggml_backend_init returned NULL\n",
                        __func__, path_str(path).c_str());
                } else {
                    GGML_LOG_ERROR("%s: failed to initialize backend from %s: incompatible API version (backend: %d, current: %d)\n",
                        __func__, path_str(path).c_str(), reg->api_version, GGML_BACKEND_API_VERSION);
                }
            }
            return nullptr;
        }

        GGML_LOG_INFO("%s: loaded %s backend from %s\n", __func__, ggml_backend_reg_name(reg), path_str(path).c_str());

        register_backend(reg, std::move(handle));

        return reg;
    }

    // 函数: unload_backend
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: unload_backend
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void unload_backend(ggml_backend_reg_t reg, bool silent) {
        auto it = std::find_if(backends.begin(), backends.end(),
                               [reg](const ggml_backend_reg_entry & entry) { return entry.reg == reg; });

        if (it == backends.end()) {
            if (!silent) {
                GGML_LOG_ERROR("%s: backend not found\n", __func__);
            }
            return;
        }

        if (!silent) {
            GGML_LOG_DEBUG("%s: unloading %s backend\n", __func__, ggml_backend_reg_name(reg));
        }

        // remove devices
        devices.erase(
            std::remove_if(devices.begin(), devices.end(),
                            [reg](ggml_backend_dev_t dev) { return ggml_backend_dev_backend_reg(dev) == reg; }),
            devices.end());

        // remove backend
        backends.erase(it);
    }
};

static ggml_backend_registry & get_reg() {
    static ggml_backend_registry reg;
    return reg;
}

// Internal API
// 函数: ggml_backend_register
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_register
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_register(ggml_backend_reg_t reg) {
    get_reg().register_backend(reg);
}

// 函数: ggml_backend_device_register
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_device_register
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_device_register(ggml_backend_dev_t device) {
    get_reg().register_device(device);
}

// Backend (reg) enumeration
// 函数: striequals
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: striequals
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool striequals(const char * a, const char * b) {
    for (; *a && *b; a++, b++) {
        if (std::tolower(*a) != std::tolower(*b)) {
            return false;
        }
    }
    return *a == *b;
}

// 函数: ggml_backend_reg_count
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_reg_count
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_backend_reg_count() {
    return get_reg().backends.size();
}

// 函数: ggml_backend_reg_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_reg_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_reg_t ggml_backend_reg_get(size_t index) {
    GGML_ASSERT(index < ggml_backend_reg_count());
    return get_reg().backends[index].reg;
}

// 函数: ggml_backend_reg_by_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_reg_by_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_reg_t ggml_backend_reg_by_name(const char * name) {
    for (size_t i = 0; i < ggml_backend_reg_count(); i++) {
        ggml_backend_reg_t reg = ggml_backend_reg_get(i);
        if (striequals(ggml_backend_reg_name(reg), name)) {
            return reg;
        }
    }
    return nullptr;
}

// Device enumeration
// 函数: ggml_backend_dev_count
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_dev_count
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
size_t ggml_backend_dev_count() {
    return get_reg().devices.size();
}

// 函数: ggml_backend_dev_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_dev_get
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_dev_t ggml_backend_dev_get(size_t index) {
    GGML_ASSERT(index < ggml_backend_dev_count());
    return get_reg().devices[index];
}

// 函数: ggml_backend_dev_by_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_dev_by_name
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_dev_t ggml_backend_dev_by_name(const char * name) {
    for (size_t i = 0; i < ggml_backend_dev_count(); i++) {
        ggml_backend_dev_t dev = ggml_backend_dev_get(i);
        if (striequals(ggml_backend_dev_name(dev), name)) {
            return dev;
        }
    }
    return nullptr;
}

// 函数: ggml_backend_dev_by_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_dev_by_type
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
ggml_backend_dev_t ggml_backend_dev_by_type(enum ggml_backend_dev_type type) {
    for (size_t i = 0; i < ggml_backend_dev_count(); i++) {
        ggml_backend_dev_t dev = ggml_backend_dev_get(i);
        if (ggml_backend_dev_type(dev) == type) {
            return dev;
        }
    }
    return nullptr;
}

// Convenience functions
// 函数: ggml_backend_init_by_name
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_init_by_name
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_backend_t ggml_backend_init_by_name(const char * name, const char * params) {
    ggml_backend_dev_t dev = ggml_backend_dev_by_name(name);
    if (!dev) {
        return nullptr;
    }
    return ggml_backend_dev_init(dev, params);
}

// 函数: ggml_backend_init_by_type
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_init_by_type
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_backend_t ggml_backend_init_by_type(enum ggml_backend_dev_type type, const char * params) {
    ggml_backend_dev_t dev = ggml_backend_dev_by_type(type);
    if (!dev) {
        return nullptr;
    }
    return ggml_backend_dev_init(dev, params);
}

// 函数: ggml_backend_init_best
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_init_best
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_backend_t ggml_backend_init_best(void) {
    ggml_backend_dev_t dev = ggml_backend_dev_by_type(GGML_BACKEND_DEVICE_TYPE_GPU);
    dev = dev ? dev : ggml_backend_dev_by_type(GGML_BACKEND_DEVICE_TYPE_IGPU);
    dev = dev ? dev : ggml_backend_dev_by_type(GGML_BACKEND_DEVICE_TYPE_CPU);
    if (!dev) {
        return nullptr;
    }
    return ggml_backend_dev_init(dev, nullptr);
}

// Dynamic loading
// 函数: ggml_backend_load
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_load
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
ggml_backend_reg_t ggml_backend_load(const char * path) {
    return get_reg().load_backend(path, false);
}

// 函数: ggml_backend_unload
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_unload
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_unload(ggml_backend_reg_t reg) {
    get_reg().unload_backend(reg, true);
}

// 函数: get_executable_path
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
// 函数: get_executable_path
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数或索引参数
// 返回: 返回请求的属性或值
static fs::path get_executable_path() {
#if defined(__APPLE__)
    // get executable path
    std::vector<char> path;
    uint32_t size;
    while (true) {
        size = path.size();
        if (_NSGetExecutablePath(path.data(), &size) == 0) {
            break;
        }
        path.resize(size);
    }
    std::string base_path(path.data(), size);
    // remove executable name
    auto last_slash = base_path.find_last_of('/');
    if (last_slash != std::string::npos) {
        base_path = base_path.substr(0, last_slash);
    }
    return base_path + "/";
#elif defined(__linux__) || defined(__FreeBSD__)
    std::string base_path = ".";
    std::vector<char> path(1024);
    while (true) {
        // get executable path
#    if defined(__linux__)
        ssize_t len = readlink("/proc/self/exe", path.data(), path.size());
#    elif defined(__FreeBSD__)
        ssize_t len = readlink("/proc/curproc/file", path.data(), path.size());
#    endif
        if (len == -1) {
            break;
        }
        if (len < (ssize_t) path.size()) {
            base_path = std::string(path.data(), len);
            // remove executable name
            auto last_slash = base_path.find_last_of('/');
            if (last_slash != std::string::npos) {
                base_path = base_path.substr(0, last_slash);
            }
            break;
        }
        path.resize(path.size() * 2);
    }

    return base_path + "/";
#elif defined(_WIN32)
    std::vector<wchar_t> path(MAX_PATH);
    DWORD len = GetModuleFileNameW(NULL, path.data(), path.size());
    if (len == 0) {
        return {};
    }
    std::wstring base_path(path.data(), len);
    // remove executable name
    auto last_slash = base_path.find_last_of('\\');
    if (last_slash != std::string::npos) {
        base_path = base_path.substr(0, last_slash);
    }
    return base_path + L"\\";
#else
    return {};
#endif
}

// 函数: backend_filename_prefix
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_filename_prefix
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static fs::path backend_filename_prefix() {
#ifdef _WIN32
    return fs::u8path("ggml-");
#else
    return fs::u8path("libggml-");
#endif
}

// 函数: backend_filename_extension
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: backend_filename_extension
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static fs::path backend_filename_extension() {
#ifdef _WIN32
    return fs::u8path(".dll");
#else
    return fs::u8path(".so");
#endif
}

// 函数: ggml_backend_load_best
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_load_best
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
static ggml_backend_reg_t ggml_backend_load_best(const char * name, bool silent, const char * user_search_path) {
    // enumerate all the files that match [lib]ggml-name-*.[so|dll] in the search paths
    const fs::path name_path = fs::u8path(name);
    const fs::path file_prefix = backend_filename_prefix().native() + name_path.native() + fs::u8path("-").native();
    const fs::path file_extension = backend_filename_extension();

    std::vector<fs::path> search_paths;
    if (user_search_path == nullptr) {
#ifdef GGML_BACKEND_DIR
        search_paths.push_back(fs::u8path(GGML_BACKEND_DIR));
#endif
        // default search paths: executable directory, current directory
        search_paths.push_back(get_executable_path());
        search_paths.push_back(fs::current_path());
    } else {
        search_paths.push_back(fs::u8path(user_search_path));
    }

    int best_score = 0;
    fs::path best_path;
    std::error_code ec;

    for (const auto & search_path : search_paths) {
        if (!fs::exists(search_path, ec)) {
            if (ec) {
                GGML_LOG_DEBUG("%s: posix_stat(%s) failure, error-message: %s\n", __func__, path_str(search_path).c_str(), ec.message().c_str());
            } else {
                GGML_LOG_DEBUG("%s: search path %s does not exist\n", __func__, path_str(search_path).c_str());
            }
            continue;
        }
        fs::directory_iterator dir_it(search_path, fs::directory_options::skip_permission_denied);
        for (const auto & entry : dir_it) {
            if (entry.is_regular_file(ec)) {
                auto filename = entry.path().filename();
                auto ext = entry.path().extension();
                if (filename.native().find(file_prefix) == 0 && ext == file_extension) {
                    dl_handle_ptr handle { dl_load_library(entry) };
                    if (!handle && !silent) {
                        GGML_LOG_ERROR("%s: failed to load %s: %s\n", __func__, path_str(entry.path()).c_str(), dl_error());
                    }
                    if (handle) {
                        auto score_fn = (ggml_backend_score_t) dl_get_sym(handle.get(), "ggml_backend_score");
                        if (score_fn) {
                            int s = score_fn();
#ifndef NDEBUG
                            GGML_LOG_DEBUG("%s: %s score: %d\n", __func__, path_str(entry.path()).c_str(), s);
#endif
                            if (s > best_score) {
                                best_score = s;
                                best_path = entry.path();
                            }
                        } else {
                            if (!silent) {
                                GGML_LOG_INFO("%s: failed to find ggml_backend_score in %s\n", __func__, path_str(entry.path()).c_str());
                            }
                        }
                    }
                }
            }
        }
    }

    if (best_score == 0) {
        // try to load the base backend
        for (const auto & search_path : search_paths) {
            fs::path filename = backend_filename_prefix().native() + name_path.native() + backend_filename_extension().native();
            fs::path path = search_path / filename;
            if (std::error_code ec; fs::exists(path, ec)) {
                return get_reg().load_backend(path, silent);
            } else {
                if (ec) {
                    GGML_LOG_DEBUG("%s: posix_stat(%s) failure, error-message: %s\n", __func__, path_str(path).c_str(), ec.message().c_str());
                }
            }
        }
        return nullptr;
    }

    return get_reg().load_backend(best_path, silent);
}

// 函数: ggml_backend_load_all
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_load_all
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_load_all() {
    ggml_backend_load_all_from_path(nullptr);
}

// 函数: ggml_backend_load_all_from_path
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_backend_load_all_from_path
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
void ggml_backend_load_all_from_path(const char * dir_path) {
#ifdef NDEBUG
    bool silent = true;
#else
    bool silent = false;
#endif

    ggml_backend_load_best("blas", silent, dir_path);
    ggml_backend_load_best("zendnn", silent, dir_path);
    ggml_backend_load_best("cann", silent, dir_path);
    ggml_backend_load_best("cuda", silent, dir_path);
    ggml_backend_load_best("hip", silent, dir_path);
    ggml_backend_load_best("metal", silent, dir_path);
    ggml_backend_load_best("rpc", silent, dir_path);
    ggml_backend_load_best("sycl", silent, dir_path);
    ggml_backend_load_best("vulkan", silent, dir_path);
    ggml_backend_load_best("virtgpu", silent, dir_path);
    ggml_backend_load_best("opencl", silent, dir_path);
    ggml_backend_load_best("hexagon", silent, dir_path);
    ggml_backend_load_best("musa", silent, dir_path);
    ggml_backend_load_best("cpu", silent, dir_path);
    // check the environment variable GGML_BACKEND_PATH to load an out-of-tree backend
    const char * backend_path = std::getenv("GGML_BACKEND_PATH");
    if (backend_path) {
        ggml_backend_load(backend_path);
    }
}
