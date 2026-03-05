#pragma once

#include "common.h"
#include "preset.h"
#include "server-common.h"
#include "server-http.h"

#include <mutex>
#include <condition_variable>
#include <functional>
#include <memory>
#include <set>

/**
 * state diagram:
 *
 * UNLOADED ──► LOADING ──► LOADED
 *  ▲            │            │
 *  └───failed───┘            │
 *  ▲                         │
 *  └────────unloaded─────────┘
 */
enum server_model_status {
    // TODO: also add downloading state when the logic is added
    SERVER_MODEL_STATUS_UNLOADED,
    SERVER_MODEL_STATUS_LOADING,
    SERVER_MODEL_STATUS_LOADED
};

// 函数: server_model_status_from_string
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: server_model_status_from_string
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static server_model_status server_model_status_from_string(const std::string & status_str) {
    if (status_str == "unloaded") {
        return SERVER_MODEL_STATUS_UNLOADED;
    }
    if (status_str == "loading") {
        return SERVER_MODEL_STATUS_LOADING;
    }
    if (status_str == "loaded") {
        return SERVER_MODEL_STATUS_LOADED;
    }
    throw std::runtime_error("invalid server model status");
}

// 函数: server_model_status_to_string
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: server_model_status_to_string
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static std::string server_model_status_to_string(server_model_status status) {
    switch (status) {
        case SERVER_MODEL_STATUS_UNLOADED: return "unloaded";
        case SERVER_MODEL_STATUS_LOADING:  return "loading";
        case SERVER_MODEL_STATUS_LOADED:   return "loaded";
        default:                           return "unknown";
    }
}

// 类: server_model_meta
// 描述: server_model_meta类提供相关功能
// 用途: 用于处理server_model_meta相关的操作
// 类: server_model_meta
// 描述: server_model_meta类提供相关功能
// 用途: 用于处理server_model_meta相关的操作
    // 结构体: server_model_meta
    // 描述: server_model_meta结构体提供相关功能
    // 用途: 用于处理server_model_meta相关的操作
    // 结构体: server_model_meta
    // 描述: server_model_meta结构体提供相关功能
    // 用途: 用于处理server_model_meta相关的操作
    // 结构体: server_model_meta
    // 描述: server_model_meta结构体提供相关功能
    // 用途: 用于处理server_model_meta相关的操作
    // 结构体: server_model_meta
    // 描述: server_model_meta结构体提供相关功能
    // 用途: 用于处理server_model_meta相关的操作
    // 结构体: server_model_meta
    // 描述: server_model_meta结构体提供相关功能
    // 用途: 用于处理server_model_meta相关的操作
    // 结构体: server_model_meta
    // 描述: server_model_meta结构体提供相关功能
    // 用途: 用于处理server_model_meta相关的操作
struct server_model_meta {
    common_preset preset;
    std::string name;
    std::set<std::string> aliases; // additional names that resolve to this model
    std::set<std::string> tags;    // informational tags, not used for routing
    int port = 0;
    server_model_status status = SERVER_MODEL_STATUS_UNLOADED;
    int64_t last_used = 0; // for LRU unloading
    std::vector<std::string> args; // args passed to the model instance, will be populated by render_args()
    int exit_code = 0; // exit code of the model instance process (only valid if status == FAILED)
    int stop_timeout = 0; // seconds to wait before force-killing the model instance during shutdown

    // 函数: is_active
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_active
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_active() const {
        return status == SERVER_MODEL_STATUS_LOADED || status == SERVER_MODEL_STATUS_LOADING;
    }

    // 函数: is_failed
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_failed
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_failed() const {
        return status == SERVER_MODEL_STATUS_UNLOADED && exit_code != 0;
    }

    // 函数: update_args
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: update_args
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    void update_args(common_preset_context & ctx_presets, std::string bin_path);
};

// 类: subprocess_s
// 描述: subprocess_s类提供相关功能
// 用途: 用于处理subprocess_s相关的操作
// 类: subprocess_s
// 描述: subprocess_s类提供相关功能
// 用途: 用于处理subprocess_s相关的操作
    // 结构体: subprocess_s
    // 描述: subprocess_s结构体提供相关功能
    // 用途: 用于处理subprocess_s相关的操作
    // 结构体: subprocess_s
    // 描述: subprocess_s结构体提供相关功能
    // 用途: 用于处理subprocess_s相关的操作
    // 结构体: subprocess_s
    // 描述: subprocess_s结构体提供相关功能
    // 用途: 用于处理subprocess_s相关的操作
    // 结构体: subprocess_s
    // 描述: subprocess_s结构体提供相关功能
    // 用途: 用于处理subprocess_s相关的操作
    // 结构体: subprocess_s
    // 描述: subprocess_s结构体提供相关功能
    // 用途: 用于处理subprocess_s相关的操作
    // 结构体: subprocess_s
    // 描述: subprocess_s结构体提供相关功能
    // 用途: 用于处理subprocess_s相关的操作
struct subprocess_s;

// 类: server_models
// 描述: server_models类提供相关功能
// 用途: 用于处理server_models相关的操作
// 类: server_models
// 描述: server_models类提供相关功能
// 用途: 用于处理server_models相关的操作
    // 结构体: server_models
    // 描述: server_models结构体提供相关功能
    // 用途: 用于处理server_models相关的操作
    // 结构体: server_models
    // 描述: server_models结构体提供相关功能
    // 用途: 用于处理server_models相关的操作
    // 结构体: server_models
    // 描述: server_models结构体提供相关功能
    // 用途: 用于处理server_models相关的操作
    // 结构体: server_models
    // 描述: server_models结构体提供相关功能
    // 用途: 用于处理server_models相关的操作
    // 结构体: server_models
    // 描述: server_models结构体提供相关功能
    // 用途: 用于处理server_models相关的操作
    // 结构体: server_models
    // 描述: server_models结构体提供相关功能
    // 用途: 用于处理server_models相关的操作
struct server_models {
private:
    // 类: instance_t
    // 描述: instance_t类提供相关功能
    // 用途: 用于处理instance_t相关的操作
    // 类: instance_t
    // 描述: instance_t类提供相关功能
    // 用途: 用于处理instance_t相关的操作
    // 结构体: instance_t
    // 描述: instance_t结构体提供相关功能
    // 用途: 用于处理instance_t相关的操作
    // 结构体: instance_t
    // 描述: instance_t结构体提供相关功能
    // 用途: 用于处理instance_t相关的操作
    // 结构体: instance_t
    // 描述: instance_t结构体提供相关功能
    // 用途: 用于处理instance_t相关的操作
    // 结构体: instance_t
    // 描述: instance_t结构体提供相关功能
    // 用途: 用于处理instance_t相关的操作
    // 结构体: instance_t
    // 描述: instance_t结构体提供相关功能
    // 用途: 用于处理instance_t相关的操作
    // 结构体: instance_t
    // 描述: instance_t结构体提供相关功能
    // 用途: 用于处理instance_t相关的操作
    struct instance_t {
        std::shared_ptr<subprocess_s> subproc; // shared between main thread and monitoring thread
        std::thread th;
        server_model_meta meta;
        FILE * stdin_file = nullptr;
    };

    std::mutex mutex;
    std::condition_variable cv;
    std::map<std::string, instance_t> mapping;

    // for stopping models
    std::condition_variable cv_stop;
    std::set<std::string> stopping_models;

    common_preset_context ctx_preset;

    common_params base_params;
    std::string bin_path;
    std::vector<std::string> base_env;
    common_preset base_preset; // base preset from llama-server CLI args

    // 函数: update_meta
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: update_meta
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    void update_meta(const std::string & name, const server_model_meta & meta);

    // unload least recently used models if the limit is reached
    // 函数: unload_lru
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: unload_lru
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void unload_lru();

    // not thread-safe, caller must hold mutex
    // 函数: add_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_model(server_model_meta && meta);

public:
    server_models(const common_params & params, int argc, char ** argv);

    // 函数: load_models
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load_models
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load_models();

    // check if a model instance exists (thread-safe)
    // 函数: has_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: has_model
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool has_model(const std::string & name);

    // return a copy of model metadata (thread-safe)
    std::optional<server_model_meta> get_meta(const std::string & name);

    // return a copy of all model metadata (thread-safe)
    std::vector<server_model_meta> get_all_meta();

    // load and unload model instances
    // these functions are thread-safe
    // 函数: load
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: load
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void load(const std::string & name);
    // 函数: unload
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: unload
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void unload(const std::string & name);
    // 函数: unload_all
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: unload_all
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void unload_all();

    // update the status of a model instance (thread-safe)
    // 函数: update_status
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: update_status
    // 描述: 更新: 更新现有数据或状态
    // 参数: 无参数
    // 返回: 无返回值
    void update_status(const std::string & name, server_model_status status, int exit_code);

    // wait until the model instance is fully loaded (thread-safe)
    // return when the model is loaded or failed to load
    // 函数: wait_until_loaded
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: wait_until_loaded
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    void wait_until_loaded(const std::string & name);

    // load the model if not loaded, otherwise do nothing (thread-safe)
    // return false if model is already loaded; return true otherwise (meta may need to be refreshed)
    // 函数: ensure_model_loaded
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: ensure_model_loaded
    // 描述: 加载: 从文件或内存加载数据
    // 参数: 无参数
    // 返回: 无返回值
    bool ensure_model_loaded(const std::string & name);

    // proxy an HTTP request to the model instance
    // 函数: proxy_request
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: proxy_request
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    server_http_res_ptr proxy_request(const server_http_req & req, const std::string & method, const std::string & name, bool update_last_used);

    // notify the router server that a model instance is ready
    // return the monitoring thread (to be joined by the caller)
    // 函数: setup_child_server
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: setup_child_server
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    static std::thread setup_child_server(const std::function<void(int)> & shutdown_handler);
};

// 类: server_models_routes
// 描述: server_models_routes类提供相关功能
// 用途: 用于处理server_models_routes相关的操作
// 类: server_models_routes
// 描述: server_models_routes类提供相关功能
// 用途: 用于处理server_models_routes相关的操作
    // 结构体: server_models_routes
    // 描述: server_models_routes结构体提供相关功能
    // 用途: 用于处理server_models_routes相关的操作
    // 结构体: server_models_routes
    // 描述: server_models_routes结构体提供相关功能
    // 用途: 用于处理server_models_routes相关的操作
    // 结构体: server_models_routes
    // 描述: server_models_routes结构体提供相关功能
    // 用途: 用于处理server_models_routes相关的操作
    // 结构体: server_models_routes
    // 描述: server_models_routes结构体提供相关功能
    // 用途: 用于处理server_models_routes相关的操作
    // 结构体: server_models_routes
    // 描述: server_models_routes结构体提供相关功能
    // 用途: 用于处理server_models_routes相关的操作
    // 结构体: server_models_routes
    // 描述: server_models_routes结构体提供相关功能
    // 用途: 用于处理server_models_routes相关的操作
struct server_models_routes {
    common_params params;
    json webui_settings = json::object();
    server_models models;
    server_models_routes(const common_params & params, int argc, char ** argv)
            : params(params), models(params, argc, argv) {
        if (!this->params.webui_config_json.empty()) {
            try {
                webui_settings = json::parse(this->params.webui_config_json);
            } catch (const std::exception & e) {
                LOG_ERR("%s: failed to parse webui config: %s\n", __func__, e.what());
                throw;
            }
        }
        init_routes();
    }

    // 函数: init_routes
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init_routes
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    void init_routes();
    // handlers using lambda function, so that they can capture `this` without `std::bind`
    server_http_context::handler_t get_router_props;
    server_http_context::handler_t proxy_get;
    server_http_context::handler_t proxy_post;
    server_http_context::handler_t get_router_models;
    server_http_context::handler_t post_router_models_load;
    server_http_context::handler_t post_router_models_unload;
};

/**
 * A simple HTTP proxy that forwards requests to another server
 * and relays the responses back.
 */
// 类: server_http_proxy
// 描述: server_http_proxy类提供相关功能
// 用途: 用于处理server_http_proxy相关的操作
// 类: server_http_proxy
// 描述: server_http_proxy类提供相关功能
// 用途: 用于处理server_http_proxy相关的操作
    // 结构体: server_http_proxy
    // 描述: server_http_proxy结构体提供相关功能
    // 用途: 用于处理server_http_proxy相关的操作
    // 结构体: server_http_proxy
    // 描述: server_http_proxy结构体提供相关功能
    // 用途: 用于处理server_http_proxy相关的操作
    // 结构体: server_http_proxy
    // 描述: server_http_proxy结构体提供相关功能
    // 用途: 用于处理server_http_proxy相关的操作
    // 结构体: server_http_proxy
    // 描述: server_http_proxy结构体提供相关功能
    // 用途: 用于处理server_http_proxy相关的操作
    // 结构体: server_http_proxy
    // 描述: server_http_proxy结构体提供相关功能
    // 用途: 用于处理server_http_proxy相关的操作
    // 结构体: server_http_proxy
    // 描述: server_http_proxy结构体提供相关功能
    // 用途: 用于处理server_http_proxy相关的操作
struct server_http_proxy : server_http_res {
    std::function<void()> cleanup = nullptr;
public:
    server_http_proxy(const std::string & method,
                      const std::string & host,
                      int port,
                      const std::string & path,
                      const std::map<std::string, std::string> & headers,
                      const std::string & body,
                      const std::function<bool()> should_stop,
                      int32_t timeout_read,
                      int32_t timeout_write
                      );
    ~server_http_proxy() {
        if (cleanup) {
            cleanup();
        }
    }
private:
    std::thread thread;
    // 类: msg_t
    // 描述: msg_t类提供相关功能
    // 用途: 用于处理msg_t相关的操作
    // 类: msg_t
    // 描述: msg_t类提供相关功能
    // 用途: 用于处理msg_t相关的操作
    // 结构体: msg_t
    // 描述: msg_t结构体提供相关功能
    // 用途: 用于处理msg_t相关的操作
    // 结构体: msg_t
    // 描述: msg_t结构体提供相关功能
    // 用途: 用于处理msg_t相关的操作
    // 结构体: msg_t
    // 描述: msg_t结构体提供相关功能
    // 用途: 用于处理msg_t相关的操作
    // 结构体: msg_t
    // 描述: msg_t结构体提供相关功能
    // 用途: 用于处理msg_t相关的操作
    // 结构体: msg_t
    // 描述: msg_t结构体提供相关功能
    // 用途: 用于处理msg_t相关的操作
    // 结构体: msg_t
    // 描述: msg_t结构体提供相关功能
    // 用途: 用于处理msg_t相关的操作
    struct msg_t {
        std::map<std::string, std::string> headers;
        int status = 0;
        std::string data;
        std::string content_type;
    };
};
