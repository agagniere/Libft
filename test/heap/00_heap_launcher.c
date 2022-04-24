#include "heap_tests.h"
#include "libunit.h"

int test_heap(void)
{
	t_tests test_list __attribute__((cleanup(fta_clear))) = NEW_TESTS;

	load_test(&test_list, "push one element", &push_one_element_test);
	load_test(&test_list, "push multiple elements", &push_multiple_elements_test);
	load_test(&test_list, "pop one element", &pop_one_element_test);
	load_test(&test_list, "pop all elements", &pop_all_elements_test);
	return (launch_tests("heap", &test_list));
}
