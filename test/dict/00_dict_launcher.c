#include "dict_tests.h"
#include "libunit.h"

int test_dict(void)
{
	t_tests test_list __attribute__((cleanup(fta_clear))) = NEW_ARRAY(t_test);

	load_test(&test_list, "Set a single element", &dict_set_test);
	load_test(&test_list, "Get a single element", &dict_get_test);
	load_test(&test_list, "Overwrite a value", &dict_set_overwrite_test);
	load_test(&test_list, "Do not overwrite a value", &dict_set_dont_overwrite_test);
	load_test(&test_list, "Set and get a few elements", &dict_few_elements_test);
	load_test(&test_list, "Set and get with collisions", &dict_collisions_test);
	return (launch_tests("dict", &test_list));
}
