// ============================================================================
// 文件: test-json-serialization.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tests/peg-parser/test-json-serialization.cpp
// 作者: 自动注释工具
// 描述: 测试文件,包含单元测试和验证
// ============================================================================

#include "tests.h"

// 函数: test_json_serialization
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: test_json_serialization
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void test_json_serialization(testing &t) {
    auto original = build_peg_parser([](common_peg_parser_builder & p) {
        return "<tool_call>" + p.json() + "</tool_call>";
    });

    auto json_serialized = original.to_json().dump();

    t.test("compare before/after", [&](testing &t) {
        auto deserialized = common_peg_arena::from_json(nlohmann::json::parse(json_serialized));

        // Test complex JSON
        std::string input = R"({"name": "test", "values": [1, 2, 3], "nested": {"a": true}})";
        common_peg_parse_context ctx1(input);
        common_peg_parse_context ctx2(input);

        auto result1 = original.parse(ctx1);
        auto result2 = deserialized.parse(ctx2);

        t.assert_equal("both_succeed", result1.success(), result2.success());
        t.assert_equal("same_end_pos", result1.end, result2.end);
    });

    t.bench("deserialize", [&]() {
        auto deserialized = common_peg_arena::from_json(nlohmann::json::parse(json_serialized));
    }, 100);
}
