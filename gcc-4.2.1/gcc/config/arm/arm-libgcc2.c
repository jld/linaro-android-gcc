/* This file contains libgcc2 functions we want to override for the
   ARM target.  */

/* Copyright (C) 2008  Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2, or (at your option) any later
   version.

   In addition to the permissions in the GNU General Public License, the
   Free Software Foundation gives you unlimited permission to link the
   compiled version of this file into combinations with other programs,
   and to distribute those combinations without any restriction coming
   from the use of this file.  (The General Public License restrictions
   do apply in other respects; for example, they cover modification of
   the file, and distribution when not linked into a combine
   executable.)

   GCC is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.  */

#include "tconfig.h"
#include "tsystem.h"
#include "coretypes.h"
#include "tm.h"

#ifdef HAVE_GAS_HIDDEN
#define ATTRIBUTE_HIDDEN  __attribute__ ((__visibility__ ("hidden")))
#else
#define ATTRIBUTE_HIDDEN
#endif

#ifndef MIN_UNITS_PER_WORD
#define MIN_UNITS_PER_WORD UNITS_PER_WORD
#endif

#define LIBGCC2_UNITS_PER_WORD UNITS_PER_WORD

#include "libgcc2.h"
#undef int

#define __ARM_ARCH__ 3

#if defined(__ARM_ARCH_3M__) || defined(__ARM_ARCH_4__) \
	|| defined(__ARM_ARCH_4T__)
/* We use __ARM_ARCH__ set to 4 here, but in reality it's any processor with
   long multiply instructions.  That includes v3M.  */
# undef __ARM_ARCH__
# define __ARM_ARCH__ 4
#endif
	
#if defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5T__) \
	|| defined(__ARM_ARCH_5E__) || defined(__ARM_ARCH_5TE__) \
	|| defined(__ARM_ARCH_5TEJ__)
# undef __ARM_ARCH__
# define __ARM_ARCH__ 5
#endif

#if defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) \
	|| defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) \
	|| defined(__ARM_ARCH_6ZK__)
# undef __ARM_ARCH__
# define __ARM_ARCH__ 6
#endif

#ifndef __ARM_ARCH__
#error Unable to determine architecture.
#endif

/* The CLZ instruction is only available for some v5 architectures. */

#if __ARM_ARCH__ < 6 \
	&& !defined(__ARM_ARCH_5E__) && !defined(__ARM_ARCH_5TE__) \
        && !defined(__ARM_ARCH_5TEJ__)

/*  The C implementations of the clz*2 functions are only compiled for
    architectures which lack the clz instruction.  For architectures
    with the DSP extension,  we use the ones in lib1funcs.asm.  */
    
int
__clzsi2 (USItype x)
{
  Wtype ret;

  count_leading_zeros (ret, x);

  return ret;
}

int
__clzdi2 (UDItype x)
{
  const DWunion uu = {.ll = x};
  UWtype word;
  Wtype ret, add;

  if (uu.s.high)
    word = uu.s.high, add = 0;
  else
    word = uu.s.low, add = W_TYPE_SIZE;

  count_leading_zeros (ret, word);
  return ret + add;
}

#endif	/* __ARM_ARCH__ < 6  */ \
	/* && !defined(__ARM_ARCH_5E__) && !defined(__ARM_ARCH_5TE__) */ \
        /* && !defined(__ARM_ARCH_5TEJ__) */
