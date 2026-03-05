// ============================================================================
// 文件: embed_kernel.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-opencl/kernels/embed_kernel.py
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#

import sys
import logging
logger = logging.getLogger("opencl-embed-kernel")


    # 函数: main
    # 描述: main函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def main():
    logging.basicConfig(level=logging.INFO)

    if len(sys.argv) != 3:
        logger.info("Usage: python embed_kernel.py <input_file> <output_file>")
        sys.exit(1)

    ifile = open(sys.argv[1], "r")
    ofile = open(sys.argv[2], "w")

    for i in ifile:
        ofile.write('R"({})"\n'.format(i))

    ifile.close()
    ofile.close()


if __name__ == "__main__":
    main()
