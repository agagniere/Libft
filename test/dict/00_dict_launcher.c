#include "dict_tests.h"
#include "libunit.h"

int dict_launcher(void)
{
	t_tests test_list __attribute__((cleanup(fta_clear))) = NEW_TESTS;

	load_test(&test_list, "push one element", &push_one_element_test);
	return (launch_tests("dict", &test_list));
}
