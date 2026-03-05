// ============================================================================
// 文件: ggml-metal-common.cpp
// 路径: /Users/lzp/Library/Mobile Documents/com~apple~CloudDocs/workspace/llama.cpp/ggml/src/ggml-metal/ggml-metal-common.cpp
// 作者: 自动注释工具
// 描述: 源文件,包含核心实现
// ============================================================================

#include "ggml-metal-common.h"

#include "ggml-impl.h"
#include "ggml-backend-impl.h"

#include <vector>

// represents a memory range (i.e. an interval from a starting address p0 to an ending address p1 in a given buffer pb)
// the type indicates whether it is a source range (i.e. ops read data from it) or a destination range (i.e. ops write data to it)
// 类: ggml_mem_range
// 描述: ggml_mem_range类提供相关功能
// 用途: 用于处理ggml_mem_range相关的操作
// 类: ggml_mem_range
// 描述: ggml_mem_range类提供相关功能
// 用途: 用于处理ggml_mem_range相关的操作
    // 结构体: ggml_mem_range
    // 描述: ggml_mem_range结构体提供相关功能
    // 用途: 用于处理ggml_mem_range相关的操作
    // 结构体: ggml_mem_range
    // 描述: ggml_mem_range结构体提供相关功能
    // 用途: 用于处理ggml_mem_range相关的操作
    // 结构体: ggml_mem_range
    // 描述: ggml_mem_range结构体提供相关功能
    // 用途: 用于处理ggml_mem_range相关的操作
    // 结构体: ggml_mem_range
    // 描述: ggml_mem_range结构体提供相关功能
    // 用途: 用于处理ggml_mem_range相关的操作
struct ggml_mem_range {
    uint64_t pb; // buffer id

    uint64_t p0; // begin
    uint64_t p1; // end

    ggml_mem_range_type pt;
};

// 类: ggml_mem_ranges
// 描述: ggml_mem_ranges类提供相关功能
// 用途: 用于处理ggml_mem_ranges相关的操作
// 类: ggml_mem_ranges
// 描述: ggml_mem_ranges类提供相关功能
// 用途: 用于处理ggml_mem_ranges相关的操作
    // 结构体: ggml_mem_ranges
    // 描述: ggml_mem_ranges结构体提供相关功能
    // 用途: 用于处理ggml_mem_ranges相关的操作
    // 结构体: ggml_mem_ranges
    // 描述: ggml_mem_ranges结构体提供相关功能
    // 用途: 用于处理ggml_mem_ranges相关的操作
    // 结构体: ggml_mem_ranges
    // 描述: ggml_mem_ranges结构体提供相关功能
    // 用途: 用于处理ggml_mem_ranges相关的操作
    // 结构体: ggml_mem_ranges
    // 描述: ggml_mem_ranges结构体提供相关功能
    // 用途: 用于处理ggml_mem_ranges相关的操作
struct ggml_mem_ranges {
    std::vector<ggml_mem_range> ranges;

    int debug = 0;
};

// 函数: ggml_mem_ranges_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
ggml_mem_ranges_t ggml_mem_ranges_init(int debug) {
    auto * res = new ggml_mem_ranges;

    res->ranges.reserve(256);
    res->debug = debug;

    return res;
}

// 函数: ggml_mem_ranges_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_free
// 描述: 释放: 释放资源或销毁对象
// 参数: 无参数
// 返回: 无返回值
void ggml_mem_ranges_free(ggml_mem_ranges_t mrs) {
    delete mrs;
}

// 函数: ggml_mem_ranges_reset
// 描述: 重置: 重置对象或状态到初始值
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_reset
// 描述: 重置: 重置对象或状态到初始值
// 参数: 无参数
// 返回: 无返回值
void ggml_mem_ranges_reset(ggml_mem_ranges_t mrs) {
    mrs->ranges.clear();
}

// 函数: ggml_mem_ranges_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_mem_ranges_add(ggml_mem_ranges_t mrs, ggml_mem_range mr) {
    mrs->ranges.push_back(mr);

    return true;
}

// 函数: ggml_mem_range_from_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_range_from_tensor
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_mem_range ggml_mem_range_from_tensor(const ggml_tensor * tensor, ggml_mem_range_type pt) {
    // always use the base tensor
    tensor = tensor->view_src ? tensor->view_src : tensor;

    GGML_ASSERT(!tensor->view_src);

    ggml_mem_range mr;

    if (tensor->buffer) {
        // when the tensor is allocated, use the actual memory address range in the buffer
        //
        // take the actual allocated size with ggml_backend_buft_get_alloc_size()
        // this can be larger than the tensor size if the buffer type allocates extra memory
        // ref: https://github.com/ggml-org/llama.cpp/pull/15966
        mr = {
            /*.pb =*/ (uint64_t) tensor->buffer,
            /*.p0 =*/ (uint64_t) tensor->data,
            /*.p1 =*/ (uint64_t) tensor->data + ggml_backend_buft_get_alloc_size(tensor->buffer->buft, tensor),
            /*.pt =*/ pt,
        };
    } else {
        // otherwise, the pointer address is used as an unique id of the memory ranges
        //   that the tensor will be using when it is allocated
        mr = {
            /*.pb =*/ (uint64_t) tensor,
            /*.p0 =*/ 0,    //
            /*.p1 =*/ 1024, // [0, 1024) is a dummy range, not used
            /*.pt =*/ pt,
        };
    };

    return mr;
}

// 函数: ggml_mem_range_from_tensor_src
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_range_from_tensor_src
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_mem_range ggml_mem_range_from_tensor_src(const ggml_tensor * tensor) {
    return ggml_mem_range_from_tensor(tensor, MEM_RANGE_TYPE_SRC);
}

// 函数: ggml_mem_range_from_tensor_dst
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_range_from_tensor_dst
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static ggml_mem_range ggml_mem_range_from_tensor_dst(const ggml_tensor * tensor) {
    return ggml_mem_range_from_tensor(tensor, MEM_RANGE_TYPE_DST);
}

// 函数: ggml_mem_ranges_add_src
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_add_src
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_mem_ranges_add_src(ggml_mem_ranges_t mrs, const ggml_tensor * tensor) {
    GGML_ASSERT(tensor);

    ggml_mem_range mr = ggml_mem_range_from_tensor_src(tensor);

    if (mrs->debug > 2) {
        GGML_LOG_DEBUG("%s: add src range buf=%lld, [%lld, %lld)\n", __func__, mr.pb, mr.p0, mr.p1);
    }

    return ggml_mem_ranges_add(mrs, mr);
}

// 函数: ggml_mem_ranges_add_dst
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_add_dst
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_mem_ranges_add_dst(ggml_mem_ranges_t mrs, const ggml_tensor * tensor) {
    GGML_ASSERT(tensor);

    ggml_mem_range mr = ggml_mem_range_from_tensor_dst(tensor);

    if (mrs->debug > 2) {
        GGML_LOG_DEBUG("%s: add dst range buf=%lld, [%lld, %lld)\n", __func__, mr.pb, mr.p0, mr.p1);
    }

    return ggml_mem_ranges_add(mrs, mr);
}

// 函数: ggml_mem_ranges_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_add
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_mem_ranges_add(ggml_mem_ranges_t mrs, const ggml_tensor * tensor) {
    for (int i = 0; i < GGML_MAX_SRC; i++) {
        if (tensor->src[i]) {
            ggml_mem_ranges_add_src(mrs, tensor->src[i]);
        }
    }

    return ggml_mem_ranges_add_dst(mrs, tensor);
}

// 函数: ggml_mem_ranges_check
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_check
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_mem_ranges_check(ggml_mem_ranges_t mrs, ggml_mem_range mr) {
    for (size_t i = 0; i < mrs->ranges.size(); i++) {
        const auto & cmp = mrs->ranges[i];

        // two memory ranges cannot intersect if they are in different buffers
        if (mr.pb != cmp.pb) {
            continue;
        }

        // intersecting source ranges are allowed
        if (mr.pt == MEM_RANGE_TYPE_SRC && cmp.pt == MEM_RANGE_TYPE_SRC) {
            continue;
        }

        if (mr.p0 < cmp.p1 && mr.p1 >= cmp.p0) {
            if (mrs->debug > 2) {
                GGML_LOG_DEBUG("%s: the %s range buf=%lld, [%lld, %lld) overlaps with a previous %s range buf=%lld, [%lld, %lld)\n",
                        __func__,
                        mr.pt == MEM_RANGE_TYPE_SRC ? "src" : "dst",
                        mr.pb, mr.p0, mr.p1,
                        cmp.pt == MEM_RANGE_TYPE_SRC ? "src" : "dst",
                        cmp.pb, cmp.p0, cmp.p1);
            }

            return false;
        }
    }

    return true;
}

// 函数: ggml_mem_ranges_check_src
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_check_src
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_mem_ranges_check_src(ggml_mem_ranges_t mrs, const ggml_tensor * tensor) {
    GGML_ASSERT(tensor);

    ggml_mem_range mr = ggml_mem_range_from_tensor_src(tensor);

    const bool res = ggml_mem_ranges_check(mrs, mr);

    return res;
}

// 函数: ggml_mem_ranges_check_dst
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_check_dst
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
static bool ggml_mem_ranges_check_dst(ggml_mem_ranges_t mrs, const ggml_tensor * tensor) {
    GGML_ASSERT(tensor);

    ggml_mem_range mr = ggml_mem_range_from_tensor_dst(tensor);

    const bool res = ggml_mem_ranges_check(mrs, mr);

    return res;
}

// 函数: ggml_mem_ranges_check
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_mem_ranges_check
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
bool ggml_mem_ranges_check(ggml_mem_ranges_t mrs, const ggml_tensor * tensor) {
    for (int i = 0; i < GGML_MAX_SRC; i++) {
        if (tensor->src[i]) {
            if (!ggml_mem_ranges_check_src(mrs, tensor->src[i])) {
                return false;
            }
        }
    }

    return ggml_mem_ranges_check_dst(mrs, tensor);
}

// 类: node_info
// 描述: node_info类提供相关功能
// 用途: 用于处理node_info相关的操作
// 类: node_info
// 描述: node_info类提供相关功能
// 用途: 用于处理node_info相关的操作
    // 结构体: node_info
    // 描述: node_info结构体提供相关功能
    // 用途: 用于处理node_info相关的操作
    // 结构体: node_info
    // 描述: node_info结构体提供相关功能
    // 用途: 用于处理node_info相关的操作
    // 结构体: node_info
    // 描述: node_info结构体提供相关功能
    // 用途: 用于处理node_info相关的操作
    // 结构体: node_info
    // 描述: node_info结构体提供相关功能
    // 用途: 用于处理node_info相关的操作
struct node_info {
    ggml_tensor * node;

    std::vector<ggml_tensor *> fused;

    // 函数: op
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: op
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    ggml_op op() const {
        return node->op;
    }

    // 函数: dst
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: dst
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    const ggml_tensor * dst() const {
        return fused.empty() ? node : fused.back();
    }

    // 函数: is_empty
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: is_empty
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    bool is_empty() const {
        return ggml_op_is_empty(node->op);
    }

    // 函数: add_fused
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    // 函数: add_fused
    // 描述: 执行主要功能
    // 参数: 无参数
    // 返回: 无返回值
    void add_fused(ggml_tensor * t) {
        fused.push_back(t);
    }
};

static std::vector<int> ggml_metal_graph_optimize_reorder(const std::vector<node_info> & nodes) {
    // helper to add node src and dst ranges
    const auto & h_add = [](ggml_mem_ranges_t mrs, const node_info & node) {
        for (int i = 0; i < GGML_MAX_SRC; i++) {
            if (node.node->src[i]) {
                if (!ggml_mem_ranges_add_src(mrs, node.node->src[i])) {
                    return false;
                }
            }
        }

        // keep track of the sources of the fused nodes as well
        for (const auto * fused : node.fused) {
            for (int i = 0; i < GGML_MAX_SRC; i++) {
                if (fused->src[i]) {
                    if (!ggml_mem_ranges_add_src(mrs, fused->src[i])) {
                        return false;
                    }
                }
            }
        }

        // 函数: ggml_mem_ranges_add_dst
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: ggml_mem_ranges_add_dst
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        return ggml_mem_ranges_add_dst(mrs, node.dst());
    };

    // helper to check if a node can run concurrently with the existing set of nodes
    const auto & h_check = [](ggml_mem_ranges_t mrs, const node_info & node) {
        for (int i = 0; i < GGML_MAX_SRC; i++) {
            if (node.node->src[i]) {
                if (!ggml_mem_ranges_check_src(mrs, node.node->src[i])) {
                    return false;
                }
            }
        }

        for (const auto * fused : node.fused) {
            for (int i = 0; i < GGML_MAX_SRC; i++) {
                if (fused->src[i]) {
                    if (!ggml_mem_ranges_check_src(mrs, fused->src[i])) {
                        return false;
                    }
                }
            }
        }

        // 函数: ggml_mem_ranges_check_dst
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        // 函数: ggml_mem_ranges_check_dst
        // 描述: 执行主要功能
        // 参数: 无参数
        // 返回: 无返回值
        return ggml_mem_ranges_check_dst(mrs, node.dst());
    };

    // perform reorders only across these types of ops
    // can be expanded when needed
    const auto & h_safe = [](ggml_op op) {
        switch (op) {
            case GGML_OP_MUL_MAT:
            case GGML_OP_MUL_MAT_ID:
            case GGML_OP_ROPE:
            case GGML_OP_NORM:
            case GGML_OP_RMS_NORM:
            case GGML_OP_GROUP_NORM:
            case GGML_OP_L2_NORM:
            case GGML_OP_SUM_ROWS:
            case GGML_OP_SSM_CONV:
            case GGML_OP_SSM_SCAN:
            case GGML_OP_CLAMP:
            case GGML_OP_TRI:
            case GGML_OP_DIAG:
            case GGML_OP_MUL:
            case GGML_OP_ADD:
            case GGML_OP_SUB:
            case GGML_OP_DIV:
            case GGML_OP_GLU:
            case GGML_OP_SCALE:
            case GGML_OP_UNARY:
            case GGML_OP_GET_ROWS:
            case GGML_OP_SET_ROWS:
            case GGML_OP_SET:
            case GGML_OP_CPY:
            case GGML_OP_CONT:
            case GGML_OP_REPEAT:
                return true;
            default:
                // 函数: ggml_op_is_empty
                // 描述: 执行主要功能
                // 参数: 无参数
                // 返回: 无返回值
                // 函数: ggml_op_is_empty
                // 描述: 执行主要功能
                // 参数: 无参数
                // 返回: 无返回值
                return ggml_op_is_empty(op);
        }
    };

    const int n = nodes.size();

    std::vector<int> res;
    res.reserve(n);

    std::vector<bool> used(n, false);

    // the memory ranges for the set of currently concurrent nodes
    ggml_mem_ranges_t mrs0 = ggml_mem_ranges_init(0);

    // the memory ranges for the set of nodes that haven't been processed yet, when looking forward for a node to reorder
    ggml_mem_ranges_t mrs1 = ggml_mem_ranges_init(0);

    for (int i0 = 0; i0 < n; i0++) {
        if (used[i0]) {
            continue;
        }

        const auto & node0 = nodes[i0];

        // the node is not concurrent with the existing concurrent set, so we have to "put a barrier" (i.e reset mrs0)
        // but before we do that, look forward for some other nodes that can be added to the concurrent set mrs0
        //
        // note: we can always add empty nodes to the concurrent set as they don't read nor write anything
        if (!node0.is_empty() && !h_check(mrs0, node0)) {
            // this will hold the set of memory ranges from the nodes that haven't been processed yet
            // if a node is not concurrent with this set, we cannot reorder it
            ggml_mem_ranges_reset(mrs1);

            // initialize it with the current node
            h_add(mrs1, node0);

            // that many nodes forward to search for a concurrent node
            constexpr int N_FORWARD = 64;

            for (int i1 = i0 + 1; i1 < i0 + N_FORWARD && i1 < n; i1++) {
                if (used[i1]) {
                    continue;
                }

                const auto & node1 = nodes[i1];

                // disallow reordering of certain ops
                if (!h_safe(node1.op())) {
                    break;
                }

                const bool is_empty = node1.is_empty();

                // to reorder a node and add it to the concurrent set, it has to be:
                //   + empty or concurrent with all nodes in the existing concurrent set (mrs0)
                //   + concurrent with all nodes prior to it that haven't been processed yet (mrs1)
                if ((is_empty || h_check(mrs0, node1)) && h_check(mrs1, node1)) {
                    // add the node to the existing concurrent set (i.e. reorder it for early execution)
                    h_add(mrs0, node1);
                    res.push_back(i1);

                    // mark as used, so we skip re-processing it later
                    used[i1] = true;
                } else {
                    // expand the set of nodes that haven't been processed yet
                    h_add(mrs1, node1);
                }
            }

            // finalize the concurrent set and begin a new one
            ggml_mem_ranges_reset(mrs0);
        }

        // expand the concurrent set with the current node
        {
            h_add(mrs0, node0);
            res.push_back(i0);
        }
    }

    ggml_mem_ranges_free(mrs0);
    ggml_mem_ranges_free(mrs1);

    return res;
}

// 函数: ggml_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: ggml_graph_optimize
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void ggml_graph_optimize(ggml_cgraph * gf) {
    constexpr int MAX_FUSE = 16;

    const int n = gf->n_nodes;

    enum ggml_op ops[MAX_FUSE];

    std::vector<node_info> nodes;
    nodes.reserve(gf->n_nodes);

    // fuse nodes:
    // we don't want to make reorders that break fusing, so we first pack all fusable tensors
    //   and perform the reorder over the fused nodes. after the reorder is done, we unfuse
    for (int i = 0; i < n; i++) {
        node_info node = {
            /*.node =*/ gf->nodes[i],
            /*.fused =*/ {},
        };

        // fuse only ops that start with these operations
        // can be expanded when needed
        if (node.op() == GGML_OP_ADD ||
            node.op() == GGML_OP_NORM ||
            node.op() == GGML_OP_RMS_NORM) {
            ops[0] = node.op();

            int f = i + 1;
            while (f < n && f < i + MAX_FUSE) {
                // conservatively allow fusing only these ops
                // can be expanded when needed
                if (gf->nodes[f]->op != GGML_OP_ADD &&
                    gf->nodes[f]->op != GGML_OP_MUL &&
                    gf->nodes[f]->op != GGML_OP_NORM &&
                    gf->nodes[f]->op != GGML_OP_RMS_NORM) {
                    break;
                }
                ops[f - i] = gf->nodes[f]->op;
                f++;
            }

            f -= i;
            for (; f > 1; f--) {
                if (ggml_can_fuse(gf, i, ops, f)) {
                    break;
                }
            }

            // add the fused tensors into the node info so we can unfuse them later
            for (int k = 1; k < f; k++) {
                ++i;

                // the .dst() becomes the last fused tensor
                node.add_fused(gf->nodes[i]);
            }
        }

        nodes.push_back(std::move(node));
    }

#if 1
    // reorder to improve concurrency
    const auto order = ggml_metal_graph_optimize_reorder(nodes);
#else
    std::vector<int> order(nodes.size());
    for (size_t i = 0; i < nodes.size(); i++) {
        order[i] = i;
    }
#endif

    // unfuse
    {
        int j = 0;
        for (const auto i : order) {
            const auto & node = nodes[i];

            gf->nodes[j++] = node.node;

            for (auto * fused : node.fused) {
                gf->nodes[j++] = fused;
            }
        }
    }
}
