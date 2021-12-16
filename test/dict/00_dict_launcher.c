#include "dict_tests.h"
#include "libunit.h"

int test_dict(void)
{
	t_tests test_list __attribute__((cleanup(fta_clear))) = NEW_ARRAY(t_test);

	load_test(&test_list, "Add a single element", &dict_set_test);
	return (launch_tests("dict", &test_list));
}
