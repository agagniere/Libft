#pragma once

#include "private_tools.h"

/*
** Fundamentals
*/

#define C_ARRAY_LENGTH(A) (sizeof(A) / sizeof(*(A)))

#define PP_STR(M)         _PP_STR(M)
#define PP_CAT(A, B)      _PP_CAT(A, B)
#define PP_MAX(A, B)      (A > B ? A : B)
#define PP_MIN(A, B)      (A < B ? A : B)

#define ARG_COUNT(...)    _ARGCNT1(__VA_ARGS__)
#define ID(ARG)           ARG
#define ADD_COMMA(F, ...) F(__VA_ARGS__),

/*
** Higher level
*/

#define EACH(...)         ARG_COUNT(__VA_ARGS__), __VA_ARGS__
#define FOR(...)          _FOR(__VA_ARGS__)

#define FOLD_INFIX(F, ...)   _FOLDI(F, __VA_ARGS__)

#define CAT(...)          FOLD_INFIX(PP_CAT, __VA_ARGS__)
#define MERGE(...)        FOLD_INFIX(_MERGE, __VA_ARGS__)

/*
** Numbers manipulation tools
*/

#define MIN(...) FOLD_INFIX(PP_MIN, __VA_ARGS__)
#define MAX(...) FOLD_INFIX(PP_MAX, __VA_ARGS__)
#define ABS(V)   MAX(V, -(V))
