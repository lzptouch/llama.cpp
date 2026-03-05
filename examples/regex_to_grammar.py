// ============================================================================
// 文件: regex_to_grammar.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/examples/regex_to_grammar.py
// 作者: 自动注释工具
// 描述: 示例文件,包含使用示例
// ============================================================================

import json, subprocess, sys, os

assert len(sys.argv) >= 2
[_, pattern, *rest] = sys.argv

print(subprocess.check_output(
    [
        "python",
        os.path.join(
        os.path.dirname(os.path.realpath(__file__)),
        "json_schema_to_grammar.py"),
        *rest,
        "-",
        "--raw-pattern",
    ],
    text=True,
    input=json.dumps({
        "type": "string",
        "pattern": pattern,
    }, indent=2)))
