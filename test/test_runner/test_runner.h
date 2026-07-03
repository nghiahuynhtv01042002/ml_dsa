/*
 * @file test_runner.h
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
*/

#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H
#include <stdint.h>

typedef void (*test_fn_t)(void);

typedef struct
{
    const char *name;
    test_fn_t function;
} test_case_t;

typedef struct
{
    const char *name;
    const test_case_t *tests;
    uint32_t count;
} test_suite_t;

void test_runner_add_suite(const test_suite_t *suite);

int test_runner_run_all(void);
int test_runner_run_suite(const char *suite_name);
int test_runner_run_test(const char *suite_name,
                         const char *test_name);
#endif // TEST_RUNNER_H
