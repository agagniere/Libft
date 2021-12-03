#pragma once

#include "ft_ctl_private.h"

#define NOOP(...) __VA_ARGS__

#define FOR(N, ...) _FOR(N, ##__VA_ARGS__)

#define EACH(...) ARG_COUNT(__VA_ARGS__), __VA_ARGS__

/*
Calling DECLARE_ENUM(cardinal, NORTH, EAST, SOUTH, WEST) will generate:

typedef enum cardinal t_cardinal;

enum cardinal
{
    NORTH,
    EAST,
    SOUTH,
    WEST,
    cardinal_count
};

static const char* g_cardinal_to_string[] =
{
    "NORTH",
    "EAST",
    "SOUTH",
    "WEST"
};
*/

#define DECLARE_ENUM(NAME, ...)                             \
    typedef enum NAME CAT(t_, NAME);                        \
    enum NAME                                               \
    {                                                       \
        FOR(EACH(__VA_ARGS__), NOOP)                        \
        CAT(NAME, _count)                                   \
    };                                                      \
    static const char* CAT(CAT(g_, NAME), _to_string)[] =   \
    {                                                       \
        FOR(EACH(__VA_ARGS__), TO_STR)                      \
    };
