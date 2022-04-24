#pragma once

#include "ft_array.h"
#include "ft_prepro/ctl.h"

typedef struct s_test t_test;
typedef t_array       t_tests;
typedef int         (*t_func)(void);

struct s_test
{
	const char* name;
	t_func      function;
};

int load_test(t_array* list, const char* name, t_func function);
int launch_tests(const char* name, t_array* list);

#define CREATE_FUNCTION(NAME, GET_NAME, WRITE_CONDITION, ARGS) \
    int CAT(NAME, _, GET_NAME ARGS, _test) (void) \
    { return !( WRITE_CONDITION ARGS ); }

#define LOAD_TEST(NAME, GET_NAME, ARGS) load_test(&tests, PP_STR(GET_NAME ARGS), & CAT(NAME, _, GET_NAME ARGS, _test));

#define TEST_SECTION(NAME, GET_NAME, WRITE_CONDITION, ...) \
    FOR(EACH(__VA_ARGS__), CREATE_FUNCTION, NAME, GET_NAME, WRITE_CONDITION) \
    int PP_CAT(test_, NAME)(void) \
    { \
        t_tests tests __attribute__((cleanup(fta_clear))) = NEW_TESTS; \
        FOR(EACH(__VA_ARGS__), LOAD_TEST, NAME, GET_NAME) \
        return launch_tests(PP_STR(NAME), &tests); \
    }

#define extract_name(NAME, ...) NAME
