/*
 * @file test_mod_q.c
 * @brief Unit tests for modular arithmetic.
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
 */

#include <assert.h>

#include "math/mod_q.h"
#include "test/test_runner/test_runner.h"

static void test_modq_add(void)
{
    const u32 q = 17U;

    assert(modq_add(3U, 5U, q) == 8U);
    assert(modq_add(10U, 10U, q) == ((10U + 10U) % q));
    assert(modq_add(16U, 2U, q) == ((16U + 2U) % q));
}

static void test_modq_sub(void)
{
    const u32 q = 17U;

    assert(modq_sub(10U, 3U, q) == 7U);
    assert(modq_sub(3U, 10U, q) == ((3U + q - (10U % q)) % q));
}

static void test_modq_mul(void)
{
    const u32 q = 17U;

    assert(modq_mul(3U, 5U, q) == 15U);
    assert(modq_mul(4U, 5U, q) == ((4U * 5U) % q));
    assert(modq_mul(16U, 16U, q) == ((16U * 16U) % q));
}

const test_case_t g_mod_q_tests[] =
{
    { "add", test_modq_add },
    { "sub", test_modq_sub },
    { "mul", test_modq_mul }
};

const test_suite_t g_mod_q_suite =
{
    .name  = "mod_q",
    .tests = g_mod_q_tests,
    .count = (uint32_t)(sizeof(g_mod_q_tests) / sizeof(g_mod_q_tests[0]))
};