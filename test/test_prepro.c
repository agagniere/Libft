#include "libunit.h"
#include "ft_prepro.h"

#define TEST_CASE(NAME, NB, CONDITION)                      \
    int PP_CAT(PP_CAT(test_, NAME), PP_CAT(_, NB))(void)    \
    {                                                       \
        return !(CONDITION);                                \
    }

TEST_CASE(max, 1, MAX(-42, 0, 1) == 1);
TEST_CASE(max, 2, MAX(123, 345, 234, 346, 299) == 346);
TEST_CASE(max, 3, MAX(-123, -345, -0, -234, -346, -1) == 0);

TEST_CASE(min, 1, MIN(-42, 0, 1) == -42);
TEST_CASE(min, 2, MIN(42, 0, -1, 1) == -1);
TEST_CASE(min, 3, MIN(4123, 345, 1234, 346, 9299) == 345);
TEST_CASE(min, 4, MIN(123, 345, 0, 234, 346, 1) == 0);

int test_prepro(void)
{
    t_tests tests __attribute__((cleanup(fta_clear))) = NEW_TESTS;

    load_test(&tests, "max of 3", &test_max_1);
    load_test(&tests, "max of 5", &test_max_2);
    load_test(&tests, "max of 6", &test_max_3);

    load_test(&tests, "min of 3", &test_min_1);
    load_test(&tests, "min of 4", &test_min_2);
    load_test(&tests, "min of 5", &test_min_3);
    load_test(&tests, "min of 6", &test_min_4);
    return launch_tests("prepro", &tests);
}
