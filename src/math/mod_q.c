/*
 * @file mod_q.c
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
 */
#include "modq.h"

u32 modq_add(u32 a, u32 b, u32 q)
{
    u32 ret_val = 0;
    ret_val  =(u32)(a + b);
    if (ret_val >= q)
    {
        ret_val  -=q;
    }
    return ret_val;
}
u32 modq_sub (u32 a, u32 b, u32 q)
{
    u32 ret_val = 0;
    if (a >= b)
    {
        ret_val = (u32)(a - b);
    }
    else 
    {
        ret_val = (u32)(a + q) - b;
    }
    return ret_val;
}

u32 modq_mul(u32 a, u32 b, u32 q)
{
    u64 ret_val = 0;
    ret_val = (u64) a * (u64) b;
    ret_val %= (u64)q;
    return (u32)ret_val;
}