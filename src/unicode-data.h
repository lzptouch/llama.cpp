#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// 类: range_nfd
// 描述: range_nfd类提供相关功能
// 用途: 用于处理range_nfd相关的操作
// 类: range_nfd
// 描述: range_nfd类提供相关功能
// 用途: 用于处理range_nfd相关的操作
    // 结构体: range_nfd
    // 描述: range_nfd结构体提供相关功能
    // 用途: 用于处理range_nfd相关的操作
    // 结构体: range_nfd
    // 描述: range_nfd结构体提供相关功能
    // 用途: 用于处理range_nfd相关的操作
    // 结构体: range_nfd
    // 描述: range_nfd结构体提供相关功能
    // 用途: 用于处理range_nfd相关的操作
    // 结构体: range_nfd
    // 描述: range_nfd结构体提供相关功能
    // 用途: 用于处理range_nfd相关的操作
struct range_nfd {
    uint32_t first;
    uint32_t last;
    uint32_t nfd;
};

static const uint32_t MAX_CODEPOINTS = 0x110000;

extern const std::initializer_list<std::pair<uint32_t, uint16_t>> unicode_ranges_flags;
extern const std::unordered_set<uint32_t> unicode_set_whitespace;
extern const std::initializer_list<std::pair<uint32_t, uint32_t>> unicode_map_lowercase;
extern const std::initializer_list<std::pair<uint32_t, uint32_t>> unicode_map_uppercase;
extern const std::initializer_list<range_nfd> unicode_ranges_nfd;
