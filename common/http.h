#pragma once

#include <cpp-httplib/httplib.h>

// 类: common_http_url
// 描述: common_http_url类提供相关功能
// 用途: 用于处理common_http_url相关的操作
// 类: common_http_url
// 描述: common_http_url类提供相关功能
// 用途: 用于处理common_http_url相关的操作
    // 结构体: common_http_url
    // 描述: common_http_url结构体提供相关功能
    // 用途: 用于处理common_http_url相关的操作
    // 结构体: common_http_url
    // 描述: common_http_url结构体提供相关功能
    // 用途: 用于处理common_http_url相关的操作
    // 结构体: common_http_url
    // 描述: common_http_url结构体提供相关功能
    // 用途: 用于处理common_http_url相关的操作
    // 结构体: common_http_url
    // 描述: common_http_url结构体提供相关功能
    // 用途: 用于处理common_http_url相关的操作
struct common_http_url {
    std::string scheme;
    std::string user;
    std::string password;
    std::string host;
    std::string path;
};

// 函数: common_http_parse_url
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_http_parse_url
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static common_http_url common_http_parse_url(const std::string & url) {
    common_http_url parts;
    auto scheme_end = url.find("://");

    if (scheme_end == std::string::npos) {
        throw std::runtime_error("invalid URL: no scheme");
    }
    parts.scheme = url.substr(0, scheme_end);

    if (parts.scheme != "http" && parts.scheme != "https") {
        throw std::runtime_error("unsupported URL scheme: " + parts.scheme);
    }

    auto rest = url.substr(scheme_end + 3);
    auto at_pos = rest.find('@');

    if (at_pos != std::string::npos) {
        auto auth = rest.substr(0, at_pos);
        auto colon_pos = auth.find(':');
        if (colon_pos != std::string::npos) {
            parts.user = auth.substr(0, colon_pos);
            parts.password = auth.substr(colon_pos + 1);
        } else {
            parts.user = auth;
        }
        rest = rest.substr(at_pos + 1);
    }

    auto slash_pos = rest.find('/');

    if (slash_pos != std::string::npos) {
        parts.host = rest.substr(0, slash_pos);
        parts.path = rest.substr(slash_pos);
    } else {
        parts.host = rest;
        parts.path = "/";
    }
    return parts;
}

static std::pair<httplib::Client, common_http_url> common_http_client(const std::string & url) {
    common_http_url parts = common_http_parse_url(url);

    if (parts.host.empty()) {
        throw std::runtime_error("error: invalid URL format");
    }

#ifndef CPPHTTPLIB_OPENSSL_SUPPORT
    if (parts.scheme == "https") {
        throw std::runtime_error(
            "HTTPS is not supported. Please rebuild with one of:\n"
            "  -DLLAMA_BUILD_BORINGSSL=ON\n"
            "  -DLLAMA_BUILD_LIBRESSL=ON\n"
            "  -DLLAMA_OPENSSL=ON (default, requires OpenSSL dev files installed)"
        );
    }
#endif

    // 函数: cli
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: cli
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    httplib::Client cli(parts.scheme + "://" + parts.host);

    if (!parts.user.empty()) {
        cli.set_basic_auth(parts.user, parts.password);
    }

    cli.set_follow_location(true);

    return { std::move(cli), std::move(parts) };
}

// 函数: common_http_show_masked_url
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: common_http_show_masked_url
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static std::string common_http_show_masked_url(const common_http_url & parts) {
    return parts.scheme + "://" + (parts.user.empty() ? "" : "****:****@") + parts.host + parts.path;
}
