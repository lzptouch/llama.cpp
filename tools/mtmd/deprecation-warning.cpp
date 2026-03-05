// ============================================================================
// 文件: deprecation-warning.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/tools/mtmd/deprecation-warning.cpp
// 作者: 自动注释工具
// 描述: 工具文件,包含各种实用工具
// ============================================================================

#include <cstdio>
#include <string>

// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: main
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
int main(int argc, char** argv) {
    std::string filename = "main";
    if (argc >= 1) {
        filename = argv[0];
    }

    // Get only the program name from the full path
    size_t pos = filename.find_last_of("/\\");
    if (pos != std::string::npos) {
        filename = filename.substr(pos+1);
    }

    fprintf(stdout, "\n");
    fprintf(stdout, "WARNING: The binary '%s' is deprecated.\n", filename.c_str());
    fprintf(stdout, "Please use 'llama-mtmd-cli' instead.\n");
    fprintf(stdout, "\n");

    return EXIT_FAILURE;
}
