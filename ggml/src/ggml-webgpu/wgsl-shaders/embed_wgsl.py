// ============================================================================
// 文件: embed_wgsl.py
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-webgpu/wgsl-shaders/embed_wgsl.py
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

import os
import re
import ast
import argparse


    # 函数: extract_block
    # 描述: extract_block函数提供相关功能
    # 参数: text, name
    # 返回: 无返回值
def extract_block(text, name):
    pattern = rf'#define\({name}\)\s*(.*?)#end\({name}\)'
    match = re.search(pattern, text, re.DOTALL)
    if not match:
        raise ValueError(f"Missing block: {name}")
    return match.group(1).strip()


    # 函数: parse_decls
    # 描述: parse_decls函数提供相关功能
    # 参数: decls_text
    # 返回: 有返回值
def parse_decls(decls_text):
    decls = {}
    for name, code in re.findall(r'#decl\((.*?)\)\s*(.*?)#enddecl\(\1\)', decls_text, re.DOTALL):
        decls[name.strip()] = code.strip()
    return decls


    # 函数: replace_repl_placeholders
    # 描述: replace_repl_placeholders函数提供相关功能
    # 参数: variant, template_map
    # 返回: 无返回值
def replace_repl_placeholders(variant, template_map):
    for repl, code in variant["REPLS"].items():
        for key, val in template_map.items():
            # Match "key" and avoid matching subsequences using by using \b
            code = re.sub(rf'\b{re.escape(str(key))}\b', str(val), code)
        variant["REPLS"][repl] = code
    return variant


    # 函数: replace_placeholders
    # 描述: replace_placeholders函数提供相关功能
    # 参数: shader_text, replacements
    # 返回: 无返回值
def replace_placeholders(shader_text, replacements):
    for key, val in replacements.items():
        # Match {{KEY}} literally, where KEY is escaped
        pattern = r'{{\s*' + re.escape(key) + r'\s*}}'
        shader_text = re.sub(pattern, str(val), shader_text)
    return shader_text


    # 函数: expand_includes
    # 描述: expand_includes函数提供相关功能
    # 参数: shader, input_dir
    # 返回: 无返回值
def expand_includes(shader, input_dir):
    """
    Replace #include "file" lines in the text with the contents of that file.
    Searches for files relative to input_dir.
    """
    include_pattern = re.compile(r'^\s*#include\s+"([^"]+)"\s*$', re.MULTILINE)

    # 函数: replacer
    # 描述: replacer函数提供相关功能
    # 参数: match
    # 返回: 无返回值
    def replacer(match):
        fname = match.group(1)
        file_path = os.path.join(input_dir, fname)
        if not os.path.exists(file_path):
            raise FileNotFoundError(f"Included file not found: {file_path}")
        with open(file_path, "r", encoding="utf-8") as f:
            included_code = f.read()
        # Recursively expand includes inside the included file
        return expand_includes(included_code, input_dir)

    return include_pattern.sub(replacer, shader)


    # 函数: chunk_shader
    # 描述: chunk_shader函数提供相关功能
    # 参数: shader_code, max_chunk_len=60000
    # 返回: 有返回值
def chunk_shader(shader_code, max_chunk_len=60000):
    """Split shader_code into safe raw-string sized chunks."""
    return [shader_code[i : i + max_chunk_len] for i in range(0, len(shader_code), max_chunk_len)]


    # 函数: raw_delim
    # 描述: raw_delim函数提供相关功能
    # 参数: shader_code
    # 返回: 无返回值
def raw_delim(shader_code):
    """Pick a raw-string delimiter that does not appear in the shader."""
    delim = "wgsl"
    while f"){delim}\"" in shader_code:
        delim += "_x"
    return delim


    # 函数: write_shader
    # 描述: write_shader函数提供相关功能
    # 参数: shader_name, shader_code, output_dir, outfile, input_dir
    # 返回: 无返回值
def write_shader(shader_name, shader_code, output_dir, outfile, input_dir):
    shader_code = expand_includes(shader_code, input_dir)

    if output_dir:
        wgsl_filename = os.path.join(output_dir, f"{shader_name}.wgsl")
        with open(wgsl_filename, "w", encoding="utf-8") as f_out:
            f_out.write(shader_code)

    delim = raw_delim(shader_code)
    chunks = chunk_shader(shader_code)

    if len(chunks) == 1:
        outfile.write(f'const char* wgsl_{shader_name} = R"{delim}({shader_code}){delim}";\n\n')
    else:
        for idx, chunk in enumerate(chunks):
            outfile.write(f'static const char wgsl_{shader_name}_part{idx}[] = R"{delim}({chunk}){delim}";\n\n')
        outfile.write(f'static const std::string& wgsl_{shader_name}_str() {{\n')
        outfile.write('    static const std::string s = []{\n')
        outfile.write('        std::string tmp;\n')
        outfile.write(f'        tmp.reserve({len(shader_code)});\n')
        for idx in range(len(chunks)):
            outfile.write(f'        tmp.append(wgsl_{shader_name}_part{idx});\n')
        outfile.write('        return tmp;\n')
        outfile.write('    }();\n')
        outfile.write('    return s;\n')
        outfile.write('}\n')
        outfile.write(f'const char* wgsl_{shader_name} = wgsl_{shader_name}_str().c_str();\n\n')


    # 函数: generate_variants
    # 描述: generate_variants函数提供相关功能
    # 参数: fname, input_dir, output_dir, outfile
    # 返回: 无返回值
def generate_variants(fname, input_dir, output_dir, outfile):
    shader_path = os.path.join(input_dir, fname)
    shader_base_name = fname.split(".")[0]

    with open(shader_path, "r", encoding="utf-8") as f:
        text = f.read()

    try:
        variants = ast.literal_eval(extract_block(text, "VARIANTS"))
    except ValueError:
        write_shader(shader_base_name, text, output_dir, outfile, input_dir)
    else:
        try:
            decls_map = parse_decls(extract_block(text, "DECLS"))
        except ValueError:
            decls_map = {}
        try:
            templates_map = ast.literal_eval(extract_block(text, "REPL_TEMPLATES"))
        except ValueError:
            templates_map = {}

        for fname in sorted(os.listdir(input_dir)):
            if fname.endswith(".tmpl"):
                tmpl_path = os.path.join(input_dir, fname)
                with open(tmpl_path, "r", encoding="utf-8") as f_tmpl:
                    decls = f_tmpl.read()
                    decls_map.update(parse_decls(decls))

        shader_template = extract_block(text, "SHADER")
        for variant in variants:
            if "DECLS" in variant:
                decls = variant["DECLS"]
            else:
                decls = []
            decls_code = ""
            for key in decls:
                if key not in decls_map:
                    raise ValueError(f"DECLS key '{key}' not found.")
                decls_code += decls_map[key] + "\n\n"
            final_shader = re.sub(r'\bDECLS\b', decls_code, shader_template)
            if "REPLS" in variant:
                variant = replace_repl_placeholders(variant, templates_map)
                final_shader = replace_placeholders(final_shader, variant["REPLS"])
                # second run to expand placeholders in repl_template
                final_shader = replace_placeholders(final_shader, variant["REPLS"])
            final_shader = expand_includes(final_shader, input_dir)

            if "SHADER_NAME" in variant:
                output_name = variant["SHADER_NAME"]
            elif "SHADER_SUFFIX" in variant:
                output_name = f"{shader_base_name}_" + variant["SHADER_SUFFIX"]
            elif "REPLS" in variant and "SRC0_TYPE" in variant["REPLS"] and "SRC1_TYPE" in variant["REPLS"]:
                output_name = f"{shader_base_name}_" + "_".join([variant["REPLS"]["SRC0_TYPE"], variant["REPLS"]["SRC1_TYPE"]])
            elif "REPLS" in variant and "SRC_TYPE" in variant["REPLS"] and "DST_TYPE" in variant["REPLS"]:
                output_name = f"{shader_base_name}_" + "_".join([variant["REPLS"]["SRC_TYPE"], variant["REPLS"]["DST_TYPE"]])
            elif "REPLS" in variant and "TYPE" in variant["REPLS"]:
                output_name = f"{shader_base_name}_" + variant["REPLS"]["TYPE"]
            else:
                output_name = shader_base_name
            write_shader(output_name, final_shader, output_dir, outfile, input_dir)


    # 函数: main
    # 描述: main函数提供相关功能
    # 参数: 无参数
    # 返回: 无返回值
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--input_dir", required=True)
    parser.add_argument("--output_file", required=True)
    parser.add_argument("--output_dir")
    args = parser.parse_args()

    if args.output_dir:
        os.makedirs(args.output_dir, exist_ok=True)

    with open(args.output_file, "w", encoding="utf-8") as out:
        out.write("// Auto-generated shader embedding\n")
        out.write("#include <string>\n\n")
        for fname in sorted(os.listdir(args.input_dir)):
            if fname.endswith(".wgsl"):
                generate_variants(fname, args.input_dir, args.output_dir, out)


if __name__ == "__main__":
    main()
