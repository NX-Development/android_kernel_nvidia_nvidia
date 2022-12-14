/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2020 Google, Inc.
 */

/*
 * Copyright (c) 2020, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/linkage.h>
#include <linux/version.h>

.arch_extension sec

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 9, 0)
SYM_FUNC_START(trusty_smc8)
#else
ENTRY(trusty_smc8)
#endif

    /* Save stack location where r3-r7 smc arguments are stored */
    mov     r12, sp

    /* Save original r4-r7 values as caller expects these to be preserved */
    push    {r4-r7}

    /* Save return value pointer and return address */
    push    {r0, lr}

    /* arm abi shifts arguments when returning a struct, shift them back */
    mov     r0, r1
    mov     r1, r2
    mov     r2, r3

    /* Load stack based arguments */
    ldmia   r12, {r3-r7}

    smc     #0

    /* Restore return address and get return value pointer */
    pop     {r12, lr}

    /* Copy 8-register smc return value to struct smc_ret8 return value */
    stmia   r12, {r0-r7}

    /* Restore original r4-r7 values */
    pop     {r4-r7}

    /* Return */
    bx      lr

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 9, 0)
SYM_FUNC_END(trusty_smc8)
#else
ENDPROC(trusty_smc8)
#endif
