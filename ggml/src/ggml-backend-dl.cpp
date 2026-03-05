// ============================================================================
// 文件: ggml-backend-dl.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-backend-dl.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-backend-dl.h"

#ifdef _WIN32

// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
dl_handle * dl_load_library(const fs::path & path) {
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
void * dl_get_sym(dl_handle * handle, const char * name) {
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
const char * dl_error() {
    return "";
}

#else

// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
// 函数: dl_load_library
// 描述: 加载: 从文件或内存加载数据
// 参数: 无参数
// 返回: 无返回值
dl_handle * dl_load_library(const fs::path & path) {
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
void * dl_get_sym(dl_handle * handle, const char * name) {
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
const char * dl_error() {
    const char *rslt = dlerror();
    return rslt != nullptr ? rslt : "";
}

#endif
