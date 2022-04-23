#include "libunit.h"
#include "ft_prepro/tools.h"
#include "ft_prepro/lambda.h"

#define TEST(condition) lambda(int, (){return !(condition);})
#define TEST_MACRO(macro, result, ...) PP_STR(macro of ARG_COUNT(__VA_ARGS__)), TEST(macro(__VA_ARGS__) == result)

int test_prepro(void)
{
    t_tests tests __attribute__((cleanup(fta_clear))) = NEW_TESTS;

    load_test(&tests, TEST_MACRO(MAX,   1,  -42, 0, 1));
    load_test(&tests, TEST_MACRO(MAX, 346,  123, 345, 234, 346, 299));
    load_test(&tests, TEST_MACRO(MAX,   0,  -99, -123, -345, -0, -234, -346, -1));

    load_test(&tests, TEST_MACRO(MIN, -42,  -42, 0, 1));
    load_test(&tests, TEST_MACRO(MIN,  -1,  42, 0, -1, 1));
    load_test(&tests, TEST_MACRO(MIN, 345,  4123, 345, 1234, 346, 9299));
    load_test(&tests, TEST_MACRO(MIN,   0,  99, 123, 345, 0, 234, 346, 1));
    return launch_tests("prepro", &tests);
}
