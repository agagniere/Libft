#include "dict_tests.h"

#include "ft_dict.h"

int dict_set_test(void)
{
	t_dict __attribute__((cleanup(dict_free))) dict = dict_new(1 << 5);
	t_substr                                   key = SUBSTR("First Name");
	t_substr                                   value = SUBSTR("Nikola");

	ft_printf("Before :\n");
	dict_print(&dict);

	dict_set(&dict, &key, &value, false);
	ft_printf("After :\n");
	dict_print(&dict);

	unsigned i = dict.capacity;
	unsigned count = 0;
	t_substr *inside_key, *inside_value;

	while (i --> 0)
		if (dict.data[i].next != 0xDEADBEEF)
		{
			count += 1;
			inside_key = &(dict.data[i].key);
			inside_value = &(dict.data[i].value);
		}
	return !(count == 1 && string_equals(&key, inside_key) && string_equals(&value, inside_value));
}
