#pragma once

#include <atomic>
#include <functional>
#include <map>
#include <string>
#include <thread>

// 类: common_params
// 描述: common_params类提供相关功能
// 用途: 用于处理common_params相关的操作
// 类: common_params
// 描述: common_params类提供相关功能
// 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
    // 结构体: common_params
    // 描述: common_params结构体提供相关功能
    // 用途: 用于处理common_params相关的操作
struct common_params;

// generator-like API for HTTP response generation
// this object response with one of the 2 modes:
// 1) normal response: `data` contains the full response body
// 2) streaming response: each call to next(output) generates the next chunk
//    when next(output) returns false, no more data after the current chunk
//    note: some chunks can be empty, in which case no data is sent for that chunk
// 类: server_http_res
// 描述: server_http_res类提供相关功能
// 用途: 用于处理server_http_res相关的操作
// 类: server_http_res
// 描述: server_http_res类提供相关功能
// 用途: 用于处理server_http_res相关的操作
    // 结构体: server_http_res
    // 描述: server_http_res结构体提供相关功能
    // 用途: 用于处理server_http_res相关的操作
    // 结构体: server_http_res
    // 描述: server_http_res结构体提供相关功能
    // 用途: 用于处理server_http_res相关的操作
    // 结构体: server_http_res
    // 描述: server_http_res结构体提供相关功能
    // 用途: 用于处理server_http_res相关的操作
    // 结构体: server_http_res
    // 描述: server_http_res结构体提供相关功能
    // 用途: 用于处理server_http_res相关的操作
    // 结构体: server_http_res
    // 描述: server_http_res结构体提供相关功能
    // 用途: 用于处理server_http_res相关的操作
    // 结构体: server_http_res
    // 描述: server_http_res结构体提供相关功能
    // 用途: 用于处理server_http_res相关的操作
struct server_http_res {
    std::string content_type = "application/json; charset=utf-8";
    int status = 200;
    std::string data;
    std::map<std::string, std::string> headers;

    // TODO: move this to a virtual function once we have proper polymorphism support
    std::function<bool(std::string &)> next = nullptr;
    // 函数: is_stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_stream
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_stream() const {
        return next != nullptr;
    }

    virtual ~server_http_res() = default;
};

// unique pointer, used by set_chunked_content_provider
// httplib requires the stream provider to be stored in heap
using server_http_res_ptr = std::unique_ptr<server_http_res>;

// 类: server_http_req
// 描述: server_http_req类提供相关功能
// 用途: 用于处理server_http_req相关的操作
// 类: server_http_req
// 描述: server_http_req类提供相关功能
// 用途: 用于处理server_http_req相关的操作
    // 结构体: server_http_req
    // 描述: server_http_req结构体提供相关功能
    // 用途: 用于处理server_http_req相关的操作
    // 结构体: server_http_req
    // 描述: server_http_req结构体提供相关功能
    // 用途: 用于处理server_http_req相关的操作
    // 结构体: server_http_req
    // 描述: server_http_req结构体提供相关功能
    // 用途: 用于处理server_http_req相关的操作
    // 结构体: server_http_req
    // 描述: server_http_req结构体提供相关功能
    // 用途: 用于处理server_http_req相关的操作
    // 结构体: server_http_req
    // 描述: server_http_req结构体提供相关功能
    // 用途: 用于处理server_http_req相关的操作
    // 结构体: server_http_req
    // 描述: server_http_req结构体提供相关功能
    // 用途: 用于处理server_http_req相关的操作
struct server_http_req {
    std::map<std::string, std::string> params; // path_params + query_params
    std::map<std::string, std::string> headers; // reserved for future use
    std::string path;
    std::string query_string; // query parameters string (e.g. "action=save")
    std::string body;
    const std::function<bool()> & should_stop;

    // 函数: get_param
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    // 函数: get_param
    // 描述: 获取: 获取某个属性、值或资源
    // 参数: 无参数或索引参数
    // 返回: 返回请求的属性或值
    std::string get_param(const std::string & key, const std::string & def = "") const {
        auto it = params.find(key);
        if (it != params.end()) {
            return it->second;
        }
        return def;
    }
};

// 类: server_http_context
// 描述: server_http_context类提供相关功能
// 用途: 用于处理server_http_context相关的操作
// 类: server_http_context
// 描述: server_http_context类提供相关功能
// 用途: 用于处理server_http_context相关的操作
    // 结构体: server_http_context
    // 描述: server_http_context结构体提供相关功能
    // 用途: 用于处理server_http_context相关的操作
    // 结构体: server_http_context
    // 描述: server_http_context结构体提供相关功能
    // 用途: 用于处理server_http_context相关的操作
    // 结构体: server_http_context
    // 描述: server_http_context结构体提供相关功能
    // 用途: 用于处理server_http_context相关的操作
    // 结构体: server_http_context
    // 描述: server_http_context结构体提供相关功能
    // 用途: 用于处理server_http_context相关的操作
    // 结构体: server_http_context
    // 描述: server_http_context结构体提供相关功能
    // 用途: 用于处理server_http_context相关的操作
    // 结构体: server_http_context
    // 描述: server_http_context结构体提供相关功能
    // 用途: 用于处理server_http_context相关的操作
struct server_http_context {
    // 类: Impl
    // 描述: Impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    // 类: Impl
    // 描述: Impl类提供相关功能
    // 用途: 用于处理impl相关的操作
    class Impl;
    std::unique_ptr<Impl> pimpl;

    std::thread thread; // server thread
    std::atomic<bool> is_ready = false;

    std::string path_prefix;
    std::string hostname;
    int port;

    server_http_context();
    ~server_http_context();

    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    // 函数: init
    // 描述: 初始化: 初始化对象、资源或环境
    // 参数: 初始化参数
    // 返回: 成功返回0或true,失败返回错误码
    bool init(const common_params & params);
    // 函数: start
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: start
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool start();
    // 函数: stop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: stop
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void stop() const;

    // note: the handler should never throw exceptions
    using handler_t = std::function<server_http_res_ptr(const server_http_req & req)>;

    // 函数: get
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: get
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void get(const std::string & path, const handler_t & handler) const;
    // 函数: post
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: post
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void post(const std::string & path, const handler_t & handler) const;

    // for debugging
    std::string listening_address;
};
