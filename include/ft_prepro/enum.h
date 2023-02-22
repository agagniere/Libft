#pragma once

#include "tools.h"

#include <stdbool.h>

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
    static const char* _MERGE(NAME, strings)[] =                  \
    {                                                             \
        FOR(EACH(__VA_ARGS__), ADD_COMMA, _PP_STR)                \
    }

#define PP_PAIR_APPLY(F, P) F P
#define PP_PAIR_ASSIGN(K, V) K = V
#define PP_TO_STRING_CASE(K, V) case (V): return PP_STR(K);

#define _EMAX(N) _MERGE(N, upper_bound)

/**
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
enum cardinal {
  East = 1,
  West = 2,
  North = 4,
  South = 8,
  cardinal_upper_bound
};

static inline const char *cstring_from_cardinal(enum cardinal value) {
  switch (value) {
  case (1):
    return "East";
  case (2):
    return "West";
  case (4):
    return "North";
  case (8):
    return "South";
  default:
    return ((void *)0);
  }
}

static inline _Bool is_valid_cardinal(long value) {
  return value < cardinal_upper_bound &&
         cstring_from_cardinal(value) != ((void *)0);
}

static inline _Bool has_next_cardinal(enum cardinal *it) {
  ++*(long *)it;
  while (*it < cardinal_upper_bound && !is_valid_cardinal(*it))
    ++*(long *)it;
  return *it < cardinal_upper_bound;
}
@endcode
*/
#define DECLARE_ENUM_WITH_VALUES(NAME, ...)	\
	enum NAME \
	{ \
		FOR(EACH(__VA_ARGS__), ADD_COMMA, PP_PAIR_APPLY, PP_PAIR_ASSIGN) \
		_EMAX(NAME) \
	}; \
	static inline const char* _MERGE(cstring_from, NAME) (enum NAME value) \
	{ \
		switch (value) \
		{ \
		FOR(EACH(__VA_ARGS__), PP_PAIR_APPLY, PP_TO_STRING_CASE) \
		default: return NULL; \
		} \
	} \
	static inline bool _MERGE(is_valid, NAME) (long value) \
	{ return value < _EMAX(NAME) && _MERGE(cstring_from, NAME)(value) != NULL; } \
	static inline bool _MERGE(has_next, NAME) (enum NAME* it) \
	{ ++*(long*)it ; while (*it < _EMAX(NAME) && !_MERGE(is_valid, NAME)(*it)) ++*(long*)it; return *it < _EMAX(NAME); }
