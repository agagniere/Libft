#include "dict_tests.h"

#include "ft_dict.h"

#define INPUT                                       \
        ("First Name", "Nikola"),                   \
        ("Last Name", "Tesla"),                     \
        ("Counrty of Birth", "Austrian Empire"),    \
        ("City of Birth", "Smiljan"),               \
        ("Date of Birth", "10/07/1856")

#define _PUSH(KEY, VALUE) &SUBSTR(KEY), &SUBSTR(VALUE)
#define PUSH(DICT, PAIR) dict_set(&DICT, _PUSH PAIR, false);

#define _GET_KEY(KEY, VALUE) &SUBSTR(KEY)
#define _GET_VALUE(KEY, VALUE) &SUBSTR(VALUE)
#define GET(DICT, STORE, RESULT, PAIR) RESULT = RESULT && dict_get(&DICT, _GET_KEY PAIR, &STORE) && string_equals(&STORE, _GET_VALUE PAIR);

int dict_few_elements_test(void)
{
	t_dict __attribute__((cleanup(dict_free))) dict  = dict_new(1 << 7);
    t_substr value;
    bool result = true;

    FOR(EACH(INPUT), PUSH, dict);
    FOR(EACH(INPUT), GET, dict, value, result);
    return !result;
}
