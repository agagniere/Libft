#include "libunit.h"
#include "ft_prepro/tools.h"
#include "ft_prepro/lambda.h"

#define TEST(condition) lambda(int, (){return !(condition);})

int test_prepro(void)
{
    t_tests tests __attribute__((cleanup(fta_clear))) = NEW_TESTS;

    load_test(&tests, "max of 3", TEST(MAX(-42, 0, 1) == 1));
    load_test(&tests, "max of 5", TEST(MAX(123, 345, 234, 346, 299) == 346));
    load_test(&tests, "max of 6", TEST(MAX(-123, -345, -0, -234, -346, -1) == 0));

    load_test(&tests, "min of 3", TEST(MIN(-42, 0, 1) == -42));
    load_test(&tests, "min of 4", TEST(MIN(42, 0, -1, 1) == -1));
    load_test(&tests, "min of 5", TEST(MIN(4123, 345, 1234, 346, 9299) == 345));
    load_test(&tests, "min of 6", TEST(MIN(123, 345, 0, 234, 346, 1) == 0));
    return launch_tests("prepro", &tests);
}
