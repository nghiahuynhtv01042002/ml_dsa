/*
 * @file mod_q.h
 * @brief 
 * @author Nghia Huynh AKA Txn
 * @date 2026-06-27
 */

#ifndef MOD_Q_H
#define MOD_Q_H
#include "params.h"
#include "types_def.h"
#define MOD_Q (7)
#define MOD_N (256)

u32 modq_add(u32 a, u32 b, u32 q);
u32 modq_sub(u32 a, u32 b, u32 q);
u32 modq_mul(u32 a, u32 b, u32 q);

#endif  // MOD_Q_H