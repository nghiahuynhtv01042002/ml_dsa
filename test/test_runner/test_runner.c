/*
 * @file test_runner.c
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
*/
#include <stdio.h>
#include "test_runner.h"

static test_case_t *g_tests[MAX_TEST_CASES];
static uint32_t g_test_num = 0;
static uint32_t g_pass = 0;
static uint32_t g_fail = 0;

int32_t test_reg(const test_case_t *test)
{
    int32_t ret_val = 0;
    if(test == NULL || g_test_num >= MAX_TEST_CASES)
    {
        ret_val = -1;
    }
    else 
    {
        g_tests[g_test_num] = test;
        g_test_num++;
        ret_val = 1;
    }
    return ret_val;
}

int32_t test_unreg(const test_case_t *test)
{
    int32_t ret_val = -1; 

    if (test != NULL)
    {
        uint32_t i = 0U;
        uint32_t found_idx = MAX_TEST_CASES;

        
        for (i = 0U; i < g_test_num; i++)
        {
            if (g_tests[i] == test)
            {
                found_idx = i;
                ret_val = 1; 
                break;       
            }
        }

        
        if (ret_val == 1)
        {
            for (i = found_idx; i < (g_test_num - 1U); i++)
            {
                g_tests[i] = g_tests[i + 1U];
            }
            
            g_test_num--;
            g_tests[g_test_num] = NULL; 
        }
    }

    return ret_val;
}

int32_t test_run_all(void);