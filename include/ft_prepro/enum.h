#pragma once

#include "tools.h"

#ifndef PP_LIBFT_ENUM_STRING_ARRAY_NAME
/**
** The name of the string array can be customized by setting this macro
** before including this header.
** The default value is `xxxx_strings`
*/
# define PP_LIBFT_ENUM_STRING_ARRAY_NAME(NAME) _MERGE(NAME, strings)
#endif

#define _ESAN(X) PP_LIBFT_ENUM_STRING_ARRAY_NAME(X)

/**
** Generate strings from an enum.
** Calling @code{.c} DECLARE_ENUM(cardinal, NORTH, EAST, SOUTH, WEST) @endcode will generate:
@code{.c}
enum cardinal
{
    NORTH,
    EAST,
    SOUTH,
    WEST,
    cardinal_count
};

static const char* cardinal_strings[] = {
    "NORTH",
    "EAST",
    "SOUTH",
    "WEST",
}
@endcode
*/
#define DECLARE_ENUM(NAME, ...)                                   \
    enum NAME                                                     \
    {                                                             \
        FOR(EACH(__VA_ARGS__), ADD_COMMA, ID)                     \
        _MERGE(NAME, count)                                       \
    };                                                            \
    static const char* _ESAN(NAME)[] =                            \
    {                                                             \
        FOR(EACH(__VA_ARGS__), ADD_COMMA, _PP_STR)                \
    }

#define PP_PAIR_ASSIGN(K, V) K = V
#define PP_PAIR_APPLY(F, P) F P
#define PP_PAIR_SET_STRING_AT_INDEX(V, I) [I] = _PP_STR(V)

#define _EMAX(N) _MERGE(N, upper_bound)

/**
 * Generate strings from an enum with custom values.
 * Only supports small positive values
@code{.c}
DECLARE_ENUM_WITH_VALUES(
    cardinal,
    (EAST,  1),
    (WEST,  2),
    (NORTH, 4),
    (SOUTH, 8)
)
@endcode
evaluates to:
@code{.c}
enum cardinal
{
	EAST  = 1,
	WEST  = 2,
	NORTH = 4,
	SOUTH = 8,
	cardinal_upper_bound
};

static const char* cardinal_strings[] =
{
	[1] "EAST",
	[2] "WEST",
	[4] "NORTH",
	[8] "SOUTH",
}
@endcode
*/
#define DECLARE_ENUM_WITH_VALUES(NAME, ...)	\
	enum NAME \
	{ \
		FOR(EACH(__VA_ARGS__), ADD_COMMA, PP_PAIR_APPLY, PP_PAIR_ASSIGN) \
		_EMAX(NAME) \
	}; \
	static const char* _ESAN(NAME)[] = \
	{ \
		FOR(EACH(__VA_ARGS__), ADD_COMMA, PP_PAIR_APPLY, PP_PAIR_SET_STRING_AT_INDEX) \
	}; \
	static inline bool _MERGE(is_valid, NAME) (unsigned value) \
	{ return value < _EMAX(NAME) && _ESAN(NAME)[value]; } \
	static inline bool _MERGE(has_next, NAME) (enum NAME* it) \
	{ while (++*it < _EMAX(NAME) && !_ESAN(NAME) [*it]); return *it < _EMAX(NAME); }
