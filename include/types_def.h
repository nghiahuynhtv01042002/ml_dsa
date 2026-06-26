/*
 * @file types_def.h
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
 */

#ifndef TYPES_DEF_H
#define TYPES_DEF_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;

typedef int8_t    s8;
typedef int16_t   s16;
typedef int32_t   s32;
typedef int64_t   s64;

typedef u32 word_t;      
typedef u32 limb_t;

typedef enum
{
    MLDSA_OK = 0,
    MLDSA_ERR = -1
} mldsa_status_t;

typedef bool mldsa_bool_t;


#endif  // TYPES_DEF_H
