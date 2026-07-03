/*
 * @file test_runner.c
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
*/
#include <stdio.h>
#include "test/test_runner/test_runner.h"

#include <stdio.h>
#include <string.h>

#define MAX_SUITES    (64U)

static const test_suite_t *g_suites[MAX_SUITES];
static uint32_t g_suite_count = 0U;

void test_runner_add_suite(const test_suite_t *suite)
{
    if ((suite == NULL) || (g_suite_count >= MAX_SUITES))
    {
        return;
    }

    g_suites[g_suite_count++] = suite;
}

int test_runner_run_test(const char *suite_name,
                         const char *test_name)
{
    uint32_t i;
    uint32_t j;

    for (i = 0U; i < g_suite_count; i++)
    {
        const test_suite_t *suite = g_suites[i];

        if (strcmp(suite->name, suite_name) != 0)
        {
            continue;
        }

        for (j = 0U; j < suite->count; j++)
        {
            if (strcmp(suite->tests[j].name, test_name) == 0)
            {
                printf("[ RUN ] %s.%s\n",
                       suite->name,
                       suite->tests[j].name);

                suite->tests[j].function();

                printf("[ PASS ] %s.%s\n",
                       suite->name,
                       suite->tests[j].name);

                return 0;
            }
        }
    }

    return -1;
}

int test_runner_run_suite(const char *suite_name)
{
    uint32_t i;
    uint32_t j;

    for (i = 0U; i < g_suite_count; i++)
    {
        const test_suite_t *suite = g_suites[i];

        if (strcmp(suite->name, suite_name) != 0)
        {
            continue;
        }

        printf("\n=== %s ===\n", suite->name);

        for (j = 0U; j < suite->count; j++)
        {
            printf("[ RUN ] %s\n", suite->tests[j].name);

            suite->tests[j].function();

            printf("[ PASS ] %s\n", suite->tests[j].name);
        }

        return 0;
    }

    return -1;
}

int test_runner_run_all(void)
{
    uint32_t i;
    uint32_t j;

    for (i = 0U; i < g_suite_count; i++)
    {
        const test_suite_t *suite = g_suites[i];

        printf("\n=== %s ===\n", suite->name);

        for (j = 0U; j < suite->count; j++)
        {
            printf("[ RUN ] %s\n", suite->tests[j].name);

            suite->tests[j].function();

            printf("[ PASS ] %s\n", suite->tests[j].name);
        }
    }

    return 0;
}