#include "dict_tests.h"

#include "ft_dict.h"

int dict_set_test(void)
{
	t_dict __attribute__((cleanup(dict_free))) dict = dict_new(1 << 5);
	t_substr                                   key = SUBSTR("First Name");
	t_substr                                   value = SUBSTR("Nikola");
	t_substr*                                  inside_key;
	t_substr*                                  inside_value;
	unsigned                                   count = 0;
	unsigned                                   i = dict.capacity;

	dict_set(&dict, &key, &value, false);
	while (i --> 0)
		if (dict.data[i].next != (void*)0xDEADBEEF)
		{
			count += 1;
			inside_key = &(dict.data[i].key);
			inside_value = &(dict.data[i].value);
		}
	return !(count == 1 && string_equals(&key, inside_key) && string_equals(&value, inside_value));
}
