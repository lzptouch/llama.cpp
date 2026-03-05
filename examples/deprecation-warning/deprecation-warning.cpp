// Warns users that this filename was deprecated, and provides a link for more information.

#include <cstdio>
#include <string>
#include <unordered_map>

// Main
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
    auto pos = filename.find_last_of("/\\");
    if (pos != std::string::npos) {
        filename = filename.substr(pos+1);
    }

    // Append "llama-" to the beginning of filename to get the replacemnt filename
    auto replacement_filename = "llama-" + filename;

    // The exception is if the filename is "main", then our replacement filename is "llama-cli"
    if (filename == "main") {
        replacement_filename = "llama-cli";
    }

    fprintf(stdout, "\n");
    fprintf(stdout, "WARNING: The binary '%s' is deprecated.\n", filename.c_str());
    fprintf(stdout, " Please use '%s' instead.\n", replacement_filename.c_str());
    fprintf(stdout, " See https://github.com/ggml-org/llama.cpp/tree/master/examples/deprecation-warning/README.md for more information.\n");
    fprintf(stdout, "\n");

    return EXIT_FAILURE;
}
