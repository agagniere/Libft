#include "dict_tests.h"

#include "ft_dict.h"

int dict_push_get_test(void)
{
	t_dict __attribute__((cleanup(dict_free))) dict = dict_new(1 << 7);
	t_substr inside;
	int      success;

	dict_set(&dict, &SUBSTR("First Name"), &SUBSTR("Nikola"), false);
	dict_set(&dict, &SUBSTR("Last Name"), &SUBSTR("Tesla"), false);
	dict_set(&dict, &SUBSTR("City of Birth"), &SUBSTR("Smiljan"), false);
	dict_set(&dict, &SUBSTR("Date of Birth"), &SUBSTR("10/07/1856"), false);

	success = dict_get(&dict, &SUBSTR("First Name"), &inside) && string_equals(&inside, &SUBSTR("Nikola"));
	success = success && dict_get(&dict, &SUBSTR("Last Name"), &inside) && string_equals(&inside, &SUBSTR("Tesla"));
	success = success && dict_get(&dict, &SUBSTR("City of Birth"), &inside) && string_equals(&inside, &SUBSTR("Smiljan"));
	success = success && dict_get(&dict, &SUBSTR("Date of Birth"), &inside) && string_equals(&inside, &SUBSTR("10/07/1856"));

	return success;
}
