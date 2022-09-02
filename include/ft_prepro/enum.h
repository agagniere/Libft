#pragma once

#include "tools.h"

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
    typedef enum NAME MERGE(t, NAME);                             \
    enum NAME                                                     \
    {                                                             \
        FOR(EACH(__VA_ARGS__), ADD_COMMA, ID)                     \
        MERGE(NAME, count)                                        \
    };                                                            \
    static const char* MERGE(string, from, NAME)[] =              \
    {                                                             \
        FOR(EACH(__VA_ARGS__), ADD_COMMA, PP_STR)                 \
    }
