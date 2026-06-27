/*
 * @file test_runner.h
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
*/

#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H
#include <stdint.h>

#define MAX_TEST_CASES (1024U)

typedef void (*test_fn_t)(void);

typedef struct
{
    const char *name;
    test_fn_t fn;
} test_case_t;

int32_t test_reg(const test_case_t *tests);
int32_t test_run_all(void);
int32_t test_unreg();
#endif // TEST_RUNNER_H
