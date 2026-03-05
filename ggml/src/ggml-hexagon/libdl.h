#pragma once

#ifdef _WIN32
#   define WIN32_LEAN_AND_MEAN
#   ifndef NOMINMAX
#       define NOMINMAX
#   endif
#   include <windows.h>
#   include <winevt.h>
#else
#    include <dlfcn.h>
#    include <unistd.h>
#endif
#include <filesystem>

namespace fs = std::filesystem;

#ifdef _WIN32

using dl_handle = std::remove_pointer_t<HMODULE>;

// 类: dl_handle_deleter
// 描述: dl_handle_deleter类提供相关功能
// 用途: 用于处理dl_handle_deleter相关的操作
// 类: dl_handle_deleter
// 描述: dl_handle_deleter类提供相关功能
// 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
struct dl_handle_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(HMODULE handle) {
        FreeLibrary(handle);
    }
};

// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
static inline dl_handle * dl_load_library(const fs::path & path) {
    // suppress error dialogs for missing DLLs
    DWORD old_mode = SetErrorMode(SEM_FAILCRITICALERRORS);
    SetErrorMode(old_mode | SEM_FAILCRITICALERRORS);

    HMODULE handle = LoadLibraryW(path.wstring().c_str());

    SetErrorMode(old_mode);

    return handle;
}

// 函数: dl_get_sym
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_get_sym
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static inline void * dl_get_sym(dl_handle * handle, const char * name) {
    DWORD old_mode = SetErrorMode(SEM_FAILCRITICALERRORS);
    SetErrorMode(old_mode | SEM_FAILCRITICALERRORS);

    void * p = (void *) GetProcAddress(handle, name);

    SetErrorMode(old_mode);

    return p;
}

// 函数: dl_error
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_error
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline const char * dl_error() {
    return "";
}

#else

using dl_handle = void;

// 类: dl_handle_deleter
// 描述: dl_handle_deleter类提供相关功能
// 用途: 用于处理dl_handle_deleter相关的操作
// 类: dl_handle_deleter
// 描述: dl_handle_deleter类提供相关功能
// 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
    // 结构体: dl_handle_deleter
    // 描述: dl_handle_deleter结构体提供相关功能
    // 用途: 用于处理dl_handle_deleter相关的操作
struct dl_handle_deleter {
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: operator
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void operator()(void * handle) {
        dlclose(handle);
    }
};

// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
static inline dl_handle * dl_load_library(const fs::path & path) {
    dl_handle * handle = dlopen(path.string().c_str(), RTLD_NOW | RTLD_LOCAL);
    return handle;
}

// 函数: dl_get_sym
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_get_sym
// 描述: 获取: 获取某个属性、值或资源
// 参数: 无参数
// 返回: 无返回值
static inline void * dl_get_sym(dl_handle * handle, const char * name) {
    return dlsym(handle, name);
}

// 函数: dl_error
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_error
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static inline const char * dl_error() {
    const char *rslt = dlerror();
    return rslt != nullptr ? rslt : "";
}

#endif
