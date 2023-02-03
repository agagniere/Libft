#pragma once

#include "ft_array.h"
#include "ft_prepro/tools.h"
#include "ft_prepro/functions.h"

typedef struct s_test t_test;
typedef t_array       t_tests;

struct s_test
{
	const char*   name;
	Function(int, function);
};

int load_test(t_array* list, const char* name, Function(int, function));
int launch_tests(const char* name, t_array* list);

#define CREATE_FUNCTION(NAME, GET_NAME, WRITE_CONDITION, ARGS) \
    int MERGE(NAME, GET_NAME ARGS, test) (void)                \
    { return !( WRITE_CONDITION ARGS ); }

#define LOAD_TEST(NAME, GET_NAME, ARGS) \
    load_test(&tests, PP_STR(GET_NAME ARGS), & MERGE(NAME, GET_NAME ARGS, test));

#define TEST_SECTION(NAME, GET_NAME, WRITE_CONDITION, ...)                     \
    FOR(EACH(__VA_ARGS__), CREATE_FUNCTION, NAME, GET_NAME, WRITE_CONDITION)   \
    int PP_CAT(test_, NAME)(void)                                              \
    {                                                                          \
        t_tests tests __attribute__((cleanup(fta_clear))) = NEW_ARRAY(t_test); \
        FOR(EACH(__VA_ARGS__), LOAD_TEST, NAME, GET_NAME)                      \
        return launch_tests(PP_STR(NAME), &tests);                             \
    }

#define extract_name(NAME, ...) NAME
