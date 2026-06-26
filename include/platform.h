/*
 * @file platform.h
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
 */

#ifndef PLATFORM_H
#define PLATFORM_H

// Compiler detection

#if defined(__GNUC__)
    #define COMPILER_GCC     1
#elif defined(__clang__)
    #define COMPILER_CLANG   1
#elif defined(__ICCARM__)
    #define COMPILER_IAR     1
#elif defined(_MSC_VER)
    #define COMPILER_MSVC    1
#else
    #define COMPILER_UNKNOWN 1
    #warning Unknown Compiler 
#endif

//  Architecture detection

#if defined(__arm__) || defined(__ARM_ARCH)
    #define ARCH_ARM     1
#elif defined(__aarch64__)
    #define ARCH_ARM64   1
#elif defined(__x86_64__) || defined(_M_X64)
    #define ARCH_X86_64  1
#elif defined(__i386__) || defined(_M_IX86)
    #define ARCH_X86     1
#elif defined(__riscv)
    #define ARCH_RISCV   1
#else
    #define ARCH_GENERIC  1
#endif

// Endianness detection

#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
    #define LITTLE_ENDIAN 1
#elif defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
    #define BIG_ENDIAN    1
#else
    #error "Endianness not detected"
#endif

// Inline control

#if defined(__GNUC__) || defined(__clang__)
    #define INLINE static inline __attribute__((always_inline))
#else
    #define INLINE static inline
#endif

// Packing / alignment

#if defined(__GNUC__) || defined(__clang__)
    #define PACKED   __attribute__((packed))
    #define ALIGNED(x) __attribute__((aligned(x)))
#else
    #define PACKED
    #define ALIGNED(x)
#endif

// Branch prediction hints

#if defined(__GNUC__) || defined(__clang__)
    #define LIKELY(x)   __builtin_expect(!!(x), 1)
    #define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
    #define LIKELY(x)   (x)
    #define UNLIKELY(x) (x)
#endif

// Constant-time hint (crypto)

#define CT_BEGIN do {
#define CT_END   } while(0)

// disable unused warnings

#if defined(__GNUC__) || defined(__clang__)
    #define UNUSED(x) (void)(x)
#else
    #define UNUSED(x)
#endif

#endif  // PLATFORM_H
