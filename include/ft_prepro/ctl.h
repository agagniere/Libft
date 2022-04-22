#pragma once

#include "tools.h"
#include "private_ctl.h"

#define FOR(N, ...) _FOR(N __VA_OPT__(, __VA_ARGS__))

#define EACH(...) ARG_COUNT(__VA_ARGS__) __VA_OPT__(, __VA_ARGS__)

/* Tools */

#define ADD_COMMA_1(ARG) ARG,
#define ADD_COMMA_F(F, ...) F(__VA_ARGS__),

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

static const char* string_from_cardinal[] = {
    "NORTH",
    "EAST",
    "SOUTH",
    "WEST",
}

*/

#define DECLARE_ENUM(NAME, ...)                                   \
    typedef enum NAME PP_CAT(t_, NAME);                           \
    enum NAME                                                     \
    {                                                             \
        FOR(EACH(__VA_ARGS__), ADD_COMMA_1)                       \
        PP_CAT(NAME, _count)                                      \
    };                                                            \
    static const char* PP_CAT(string_from_, NAME)[] =             \
    {                                                             \
        FOR(EACH(__VA_ARGS__), ADD_COMMA_F, PP_STR)               \
    }
