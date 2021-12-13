#include "dict_tests.h"

#include "ft_dict.h"

int dict_push_get_test(void)
{
	t_dict __attribute__((cleanup(dict_free))) dict = dict_new(1 << 7);

	dict_set(SUBSTR("First Name"), SUBSTR("Nikola"));
	dict_set(SUBSTR("Last Name"), SUBSTR("Tesla"));
	dict_set(SUBSTR("City of Birth"), SUBSTR("Smiljan"));
	dict_set(SUBSTR("Date of Birth"), SUBSTR("10/07/1856"));
	return ft_strequ(dict_get(SUBSTR("First Name")), "Nikola") && ft_strequ();
}
