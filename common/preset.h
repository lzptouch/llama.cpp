#pragma once

#include "common.h"
#include "arg.h"

#include <string>
#include <vector>
#include <map>
#include <set>

//
// INI preset parser and writer
//

constexpr const char * COMMON_PRESET_DEFAULT_NAME = "default";

// 类: common_preset_context
// 描述: common_preset_context类提供相关功能
// 用途: 用于处理common_preset_context相关的操作
// 类: common_preset_context
// 描述: common_preset_context类提供相关功能
// 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
struct common_preset_context;

// 类: common_preset
// 描述: common_preset类提供相关功能
// 用途: 用于处理common_preset相关的操作
// 类: common_preset
// 描述: common_preset类提供相关功能
// 用途: 用于处理common_preset相关的操作
    // 结构体: common_preset
    // 描述: common_preset结构体提供相关功能
    // 用途: 用于处理common_preset相关的操作
    // 结构体: common_preset
    // 描述: common_preset结构体提供相关功能
    // 用途: 用于处理common_preset相关的操作
    // 结构体: common_preset
    // 描述: common_preset结构体提供相关功能
    // 用途: 用于处理common_preset相关的操作
    // 结构体: common_preset
    // 描述: common_preset结构体提供相关功能
    // 用途: 用于处理common_preset相关的操作
struct common_preset {
    std::string name;

    // options are stored as common_arg to string mapping, representing CLI arg and its value
    std::map<common_arg, std::string> options;

    // convert preset to CLI argument list
    std::vector<std::string> to_args(const std::string & bin_path = "") const;

    // convert preset to INI format string
    // 函数: to_ini
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: to_ini
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string to_ini() const;

    // TODO: maybe implement to_env() if needed

    // modify preset options where argument is identified by its env variable
    // 函数: set_option
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    // 函数: set_option
    // 描述: 设置: 设置某个属性或配置
    // 参数: 设置参数和值
    // 返回: 无返回值
    void set_option(const common_preset_context & ctx, const std::string & env, const std::string & value);

    // unset option by its env variable
    // 函数: unset_option
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: unset_option
    // 描述: 设置: 设置某个属性或配置
    // 参数: 无参数
    // 返回: 无返回值
    void unset_option(const std::string & env);

    // get option value by its env variable, return false if not found
    // 函数: get_option
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_option
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    bool get_option(const std::string & env, std::string & value) const;

    // merge another preset into this one, overwriting existing options
    // 函数: merge
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: merge
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void merge(const common_preset & other);

    // apply preset options to common_params
    // 函数: apply_to_params
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: apply_to_params
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void apply_to_params(common_params & params) const;
};

// interface for multiple presets in one file
using common_presets = std::map<std::string, common_preset>;

// context for loading and editing presets
// 类: common_preset_context
// 描述: common_preset_context类提供相关功能
// 用途: 用于处理common_preset_context相关的操作
// 类: common_preset_context
// 描述: common_preset_context类提供相关功能
// 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
    // 结构体: common_preset_context
    // 描述: common_preset_context结构体提供相关功能
    // 用途: 用于处理common_preset_context相关的操作
struct common_preset_context {
    common_params default_params; // unused for now
    common_params_context ctx_params;
    std::map<std::string, common_arg> key_to_opt;

    bool filter_allowed_keys = false;
    std::set<std::string> allowed_keys;

    // if only_remote_allowed is true, only accept whitelisted keys
    common_preset_context(llama_example ex, bool only_remote_allowed = false);

    // load presets from INI file
    // 函数: load_from_ini
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_from_ini
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    common_presets load_from_ini(const std::string & path, common_preset & global) const;

    // generate presets from cached models
    // 函数: load_from_cache
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_from_cache
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    common_presets load_from_cache() const;

    // generate presets from local models directory
    // for the directory structure, see "Using multiple models" in server/README.md
    // 函数: load_from_models_dir
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_from_models_dir
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    common_presets load_from_models_dir(const std::string & models_dir) const;

    // generate one preset from CLI arguments
    // 函数: load_from_args
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_from_args
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    common_preset load_from_args(int argc, char ** argv) const;

    // cascade multiple presets if exist on both: base < added
    // if preset does not exist in base, it will be added without modification
    // 函数: cascade
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cascade
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_presets cascade(const common_presets & base, const common_presets & added) const;

    // apply presets over a base preset (same idea as CSS cascading)
    // 函数: cascade
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cascade
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    common_presets cascade(const common_preset & base, const common_presets & presets) const;
};
