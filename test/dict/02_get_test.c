#include "dict_tests.h"

#include "ft_dict.h"

int dict_get_test(void)
{
	t_dict __attribute__((cleanup(dict_free))) dict  = dict_new(1 << 5);
	t_substr                                   key   = SUBSTR("First Name");
	t_substr                                   value = SUBSTR("Nikola");
    t_substr                                   inside;

	dict_set(&dict, &key, &value, false);
    return !(dict_get(&dict, &key, &inside) && string_equals(&inside, &value));
}
