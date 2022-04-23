#include "libunit.h"
#include "ft_prepro/tools.h"
#include "ft_prepro/ctl.h"

#define CREATE_FUNCTION(get_name, write_condition, args) \
    int get_name args (void) \
    { return !( write_condition args ); }

#define LOAD_TEST(get_name, args) load_test(&tests, PP_STR(get_name args), get_name args ());

#define TEST_SECTION(name, get_name, write_condition, ...) \
    FOR(EACH(__VA_ARGS__), CREATE_FUNCTION, get_name, write_condition) \
    int PP_CAT(test_, name)(void) \
    { \
        t_tests tests __attribute__((cleanup(fta_clear))) = NEW_TESTS; \
        FOR(EACH(__VA_ARGS__), LOAD_TEST, get_name) \
        return launch_tests(PP_STR(name), &tests); \
    }

#define GEN_NAME(macro, args, result) PP_CAT(macro, ARG_COUNT args)
#define GEN_COND(macro, args, result) macro args == result

TEST_SECTION(prepro, GEN_NAME, GEN_COND,
    (MAX, (-42, 0, 1), 1),
    (MAX, (123, 345, 234, 346, 299), 346),
    (MAX, (-99, -123, -345, -0, -234, -346, -1), 0),
    (MIN, (-42, 0, 1), -42),
    (MIN, (42, 0, -1, 1), -1),
    (MIN, (4123, 345, 1234, 346, 9299), 345),
    (MIN, (99, 123, 345, 0, 234, 346, 1), 0)
)
