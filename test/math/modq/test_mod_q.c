/*
 * @file test_mod_q.c
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
*/
#include <stdio.h>
#include <assert.h>

#include "mod_q.h"

static void test_modq_add(void)
{
    u32 q = 17;

    assert(modq_add(3, 5, q) == 8);
    assert(modq_add(10, 10, q) == ((10 + 10) % q));
    assert(modq_add(16, 2, q) == ((16 + 2) % q));

    printf("modq_add OK\n");
}

static void test_modq_sub(void)
{
    u32 q = 17;

    assert(modq_sub(10, 3, q) == 7);
    assert(modq_sub(3, 10, q) == ((3 + q - 10 % q) % q));

    printf("modq_sub OK\n");
}

static void test_modq_mul(void)
{
    u32 q = 17;

    assert(modq_mul(3, 5, q) == 15);
    assert(modq_mul(4, 5, q) == ((4 * 5) % q));
    assert(modq_mul(16, 16, q) == ((16 * 16) % q));

    printf("modq_mul OK\n");
}

int main(void)
{
    test_modq_add();
    test_modq_sub();
    test_modq_mul();

    printf("ALL modq tests PASSED\n");
    return 0;
}