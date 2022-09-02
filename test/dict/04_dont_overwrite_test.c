#include "dict_tests.h"

#include "ft_dict.h"

int dict_set_dont_overwrite_test(void)
{
	t_dict __attribute__((cleanup(dict_free))) dict   = dict_new(1 << 4);
	t_substr                                   key    = SUBSTR("Last Name");
	t_substr                                   value1 = SUBSTR("Edison");
	t_substr                                   value2 = SUBSTR("Tesla");
    t_substr                                   inside;

	dict_set(&dict, &key, &value1, true);
	dict_set(&dict, &key, &value2, false);
    return !(dict_get(&dict, &key, &inside) && string_equals(&inside, &value1));
}
