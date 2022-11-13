#pragma once

/**
** @file ft_variadic.c
** Typesafe wrapper around va_arg
*/

#include "ft_prepro/constraints.h"
#include "ft_prepro/tools.h"
#include "ft_string.h"

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <wchar.h>

typedef signed char        schar;
typedef unsigned char      uchar;
typedef unsigned short     ushort;
typedef long long          llong;
typedef long unsigned      ulong;
typedef long long unsigned ullong;
typedef void*              pointer;

#define PromotedToInt      Interface(char, schar, short)
#define PromotedToUnsigned Interface(uchar, ushort)
#define PromotedToDouble   Interface(float)
#define UnpromotedSigned   Interface(int, long, llong, intmax_t, ptrdiff_t)
#define UnpromotedUnsigned Interface(unsigned, ulong, ullong, uintmax_t, size_t)
#define Unpromoted         Interface(UnpromotedSigned, UnpromotedUnsigned, t_cstring, pointer, wint_t)

#define FT_VARIADIC_TYPES  Interface(PromotedToInt, PromotedToUnsigned, PromotedToDouble, Unpromoted)

/**
** va_arg wrapper.
** Handles default argument promotion
*/
#define ft_va_arg(VA_LIST, TYPE) FT_VARIADIC_NAME(TYPE)(VA_LIST)

/** @name private */
/** @{ */

#define FT_VARIADIC_NAME(T) MERGE(ft, va, arg, T)

#define FT_VARIADIC_DECLARE(IGNORED, T)			\
	T FT_VARIADIC_NAME(T)(va_list* list);

FOR(EACH(FT_VARIADIC_TYPES), FT_VARIADIC_DECLARE)

/** @} */
