/*
 * @file mod_q.c
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
 */
#include "math/mod_q.h"

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

u32 modq_pow(u32 base, u32 exp, u32 q)
{
    u32 result = 1U;

    while (exp > 0U)
    {
        if (exp & 1U)
        {
            result = modq_mul(result, base, q);
        }
        base = modq_mul(base, base, q);
        exp >>= 1U;
    }

    return result;
}
/* fermat theorem */
u32 modq_inv(u32 a, u32 q)
{
    return modq_pow(a, q - 2U, q);
}


