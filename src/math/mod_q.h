/*
 * @file mod_q.h
 * @brief Modular arithmetic operations over the finite field Z_q.
 *
 * This module provides basic modular arithmetic primitives used by
 * the ML-DSA implementation. All operands are assumed to be in the
 * range [0, q-1], where q is the modulus.
 *
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
 */

#ifndef MOD_Q_H
#define MOD_Q_H

#include "params.h"
#include "types_def.h"

/**
 * @brief Perform modular addition.
 *
 * Computes (a + b) mod q.
 *
 * @param[in] a First operand.
 * @param[in] b Second operand.
 * @param[in] q Modulus.
 *
 * @return Result of (a + b) modulo q.
 */
u32 modq_add(u32 a, u32 b, u32 q);

/**
 * @brief Perform modular subtraction.
 *
 * Computes (a - b) mod q.
 *
 * @param[in] a Minuend.
 * @param[in] b Subtrahend.
 * @param[in] q Modulus.
 *
 * @return Result of (a - b) modulo q.
 */
u32 modq_sub(u32 a, u32 b, u32 q);

/**
 * @brief Perform modular multiplication.
 *
 * Computes (a * b) mod q using a 64-bit intermediate value to
 * prevent overflow.
 *
 * @param[in] a First operand.
 * @param[in] b Second operand.
 * @param[in] q Modulus.
 *
 * @return Result of (a * b) modulo q.
 */
u32 modq_mul(u32 a, u32 b, u32 q);

/**
 * @brief Perform modular exponentiation.
 *
 * Computes (base^exp) mod q using the binary exponentiation
 * algorithm.
 *
 * @param[in] base Base value.
 * @param[in] exp Non-negative exponent.
 * @param[in] q Modulus.
 *
 * @return Result of (base^exp) modulo q.
 */
u32 modq_pow(u32 base, u32 exp, u32 q);

/**
 * @brief Compute the modular multiplicative inverse.
 *
 * Computes a^(-1) mod q using Fermat's Little Theorem:
 *
 *      a^(-1) = a^(q-2) mod q
 *
 * This function is valid only when q is prime and
 * a is non-zero modulo q.
 *
 * @param[in] a Value whose inverse is required.
 * @param[in] q Prime modulus.
 *
 * @return Modular multiplicative inverse of a.
 */
u32 modq_inv(u32 a, u32 q);

#endif /* MOD_Q_H */
