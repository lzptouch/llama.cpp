// ============================================================================
// 文件: test-peg-parser.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tests/test-peg-parser.cpp
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

#include <cstdlib>
#include <string>
#include <iostream>

#include "peg-parser/tests.h"

// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int main(int argc, char *argv[]) {
    testing t(std::cout);
    if (argc >= 2) {
        t.set_filter(argv[1]);
    }

    const char * verbose = getenv("LLAMA_TEST_VERBOSE");
    if (verbose) {
        t.verbose = std::string(verbose) == "1";
    }

    t.test("basic", test_basic);
    t.test("unicode", test_unicode);
    t.test("json", test_json_parser);
    t.test("gbnf", test_gbnf_generation);
    t.test("serialization", test_json_serialization);

    return t.summary();
}
