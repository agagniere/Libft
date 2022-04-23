#include "libunit.h"
#include "ft_prepro/tools.h"
#include "ft_prepro/lambda.h"

#define TEST(condition) lambda(int, (){return !(condition);})
#define TEST_MACRO(macro, args, result) PP_STR(macro of ARG_COUNT args), TEST(macro args == result)

#define LOAD_TEST(F, args) load_test(&tests, F args);

#define TEST_SECTION(name, F, ...) \
    int PP_CAT(test_, name)(void) \
    { \
        t_tests tests __attribute__((cleanup(fta_clear))) = NEW_TESTS; \
        FOR(EACH(__VA_ARGS__), LOAD_TEST, F); \
        return launch_tests(PP_STR(name), &tests); \
    }

TEST_SECTION(prepro, TEST_MACRO,
    (MAX, (-42, 0, 1), 1),
    (MAX, (123, 345, 234, 346, 299), 346),
    (MAX, (-99, -123, -345, -0, -234, -346, -1), 0),
    (MIN, (-42, 0, 1), -42),
    (MIN, (42, 0, -1, 1), -1),
    (MIN, (4123, 345, 1234, 346, 9299), 345),
    (MIN, (99, 123, 345, 0, 234, 346, 1), 0)
)
