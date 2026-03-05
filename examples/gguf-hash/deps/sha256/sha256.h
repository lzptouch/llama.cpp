/* Sha256.h -- SHA-256 Hash
2010-06-11 : Igor Pavlov : Public domain */

#ifndef __CRYPTO_SHA256_H
#define __CRYPTO_SHA256_H

#include <stdlib.h>
#include <stdint.h>

#define SHA256_DIGEST_SIZE 32

typedef struct sha256_t
{
  uint32_t state[8];
  uint64_t count;
  unsigned char buffer[64];
} sha256_t;

// 函数: sha256_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
// 函数: sha256_init
// 描述: 初始化: 初始化对象、资源或环境
// 参数: 无参数
// 返回: 无返回值
void sha256_init(sha256_t *p);
// 函数: sha256_update
// 描述: 更新: 更新现有数据或状态
// 参数: 无参数
// 返回: 无返回值
// 函数: sha256_update
// 描述: 更新: 更新现有数据或状态
// 参数: 无参数
// 返回: 无返回值
void sha256_update(sha256_t *p, const unsigned char *data, size_t size);
// 函数: sha256_final
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: sha256_final
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void sha256_final(sha256_t *p, unsigned char *digest);
// 函数: sha256_hash
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
// 函数: sha256_hash
// 描述: 执行主要功能
// 参数: 无参数
// 返回: 无返回值
void sha256_hash(unsigned char *buf, const unsigned char *data, size_t size);

#endif
