#pragma once

#include <string>
#include <vector>

// 类: common_params_model
// 描述: common_params_model类提供相关功能
// 用途: 用于处理common_params_model相关的操作
// 类: common_params_model
// 描述: common_params_model类提供相关功能
// 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
    // 结构体: common_params_model
    // 描述: common_params_model结构体提供相关功能
    // 用途: 用于处理common_params_model相关的操作
struct common_params_model;

using common_header      = std::pair<std::string, std::string>;
using common_header_list = std::vector<common_header>;

// 类: common_remote_params
// 描述: common_remote_params类提供相关功能
// 用途: 用于处理common_remote_params相关的操作
// 类: common_remote_params
// 描述: common_remote_params类提供相关功能
// 用途: 用于处理common_remote_params相关的操作
    // 结构体: common_remote_params
    // 描述: common_remote_params结构体提供相关功能
    // 用途: 用于处理common_remote_params相关的操作
    // 结构体: common_remote_params
    // 描述: common_remote_params结构体提供相关功能
    // 用途: 用于处理common_remote_params相关的操作
    // 结构体: common_remote_params
    // 描述: common_remote_params结构体提供相关功能
    // 用途: 用于处理common_remote_params相关的操作
    // 结构体: common_remote_params
    // 描述: common_remote_params结构体提供相关功能
    // 用途: 用于处理common_remote_params相关的操作
struct common_remote_params {
    common_header_list headers;
    long timeout  = 0;           // in seconds, 0 means no timeout
    long max_size = 0;           // unlimited if 0
};

// get remote file content, returns <http_code, raw_response_body>
std::pair<long, std::vector<char>> common_remote_get_content(const std::string & url, const common_remote_params & params);

// split HF repo with tag into <repo, tag>
// for example: "user/model:tag" -> <"user/model", "tag">
// if tag is not present, default to "latest"
// example: "user/model" -> <"user/model", "latest">
std::pair<std::string, std::string> common_download_split_repo_tag(const std::string & hf_repo_with_tag);

// 类: common_cached_model_info
// 描述: common_cached_model_info类提供相关功能
// 用途: 用于处理common_cached_model_info相关的操作
// 类: common_cached_model_info
// 描述: common_cached_model_info类提供相关功能
// 用途: 用于处理common_cached_model_info相关的操作
    // 结构体: common_cached_model_info
    // 描述: common_cached_model_info结构体提供相关功能
    // 用途: 用于处理common_cached_model_info相关的操作
    // 结构体: common_cached_model_info
    // 描述: common_cached_model_info结构体提供相关功能
    // 用途: 用于处理common_cached_model_info相关的操作
    // 结构体: common_cached_model_info
    // 描述: common_cached_model_info结构体提供相关功能
    // 用途: 用于处理common_cached_model_info相关的操作
    // 结构体: common_cached_model_info
    // 描述: common_cached_model_info结构体提供相关功能
    // 用途: 用于处理common_cached_model_info相关的操作
struct common_cached_model_info {
    std::string manifest_path;
    std::string user;
    std::string model;
    std::string tag;
    size_t      size = 0; // GGUF size in bytes
    // return string representation like "user/model:tag"
    // if tag is "latest", it will be omitted
    // 函数: to_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: to_string
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    std::string to_string() const {
        return user + "/" + model + (tag == "latest" ? "" : ":" + tag);
    }
};

// 类: common_hf_file_res
// 描述: common_hf_file_res类提供相关功能
// 用途: 用于处理common_hf_file_res相关的操作
// 类: common_hf_file_res
// 描述: common_hf_file_res类提供相关功能
// 用途: 用于处理common_hf_file_res相关的操作
    // 结构体: common_hf_file_res
    // 描述: common_hf_file_res结构体提供相关功能
    // 用途: 用于处理common_hf_file_res相关的操作
    // 结构体: common_hf_file_res
    // 描述: common_hf_file_res结构体提供相关功能
    // 用途: 用于处理common_hf_file_res相关的操作
    // 结构体: common_hf_file_res
    // 描述: common_hf_file_res结构体提供相关功能
    // 用途: 用于处理common_hf_file_res相关的操作
    // 结构体: common_hf_file_res
    // 描述: common_hf_file_res结构体提供相关功能
    // 用途: 用于处理common_hf_file_res相关的操作
struct common_hf_file_res {
    std::string repo; // repo name with ":tag" removed
    std::string ggufFile;
    std::string mmprojFile;
};

/**
 * Allow getting the HF file from the HF repo with tag (like ollama), for example:
 * - bartowski/Llama-3.2-3B-Instruct-GGUF:q4
 * - bartowski/Llama-3.2-3B-Instruct-GGUF:Q4_K_M
 * - bartowski/Llama-3.2-3B-Instruct-GGUF:q5_k_s
 * Tag is optional, default to "latest" (meaning it checks for Q4_K_M first, then Q4, then if not found, return the first GGUF file in repo)
 *
 * Return pair of <repo, file> (with "repo" already having tag removed)
 *
 * Note: we use the Ollama-compatible HF API, but not using the blobId. Instead, we use the special "ggufFile" field which returns the value for "hf_file". This is done to be backward-compatible with existing cache files.
 */
common_hf_file_res common_get_hf_file(
    const std::string & hf_repo_with_tag,
    const std::string & bearer_token,
    bool offline,
    const common_header_list & headers = {}
);

// returns true if download succeeded
bool common_download_model(
    const common_params_model & model,
    const std::string & bearer_token,
    bool offline,
    const common_header_list & headers = {}
);

// returns list of cached models
std::vector<common_cached_model_info> common_list_cached_models();

// download single file from url to local path
// returns status code or -1 on error
int common_download_file_single(const std::string & url,
                                const std::string & path,
                                const std::string & bearer_token,
                                bool offline,
                                const common_header_list & headers = {});

// resolve and download model from Docker registry
// return local path to downloaded model file
// 函数: common_docker_resolve_model
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_docker_resolve_model
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
std::string common_docker_resolve_model(const std::string & docker);
