#include "libunit.h"

#include "ft_prepro/raii.h"
#include "ft_string.h"
#include "libft.h"

#include <limits.h>
#include <stdlib.h>
#include <string.h>

void cleanup_t_cstring(t_cstring* ptr) { free(*ptr); }

#define ITOA_compare(NAME, EXPECTED, INPUT) !({ RAII(t_cstring) str = NAME INPUT; strcmp(EXPECTED, str); })

#define ITOA_condition(NAME, INT) ITOA_compare(ft_itoa, PP_STR(INT), (INT))

TEST_SECTION(itoa, extract_name, ITOA_condition,
    (zero,       0),
    (one,        1),
    (basic,      42),
    (char_min,   -128),
    (char_max,   127),
    (short_min,  -32768),
    (short_max,  32767),
    (int_min,    -2147483648),
    (int_max,    2147483647),
    (many_zeros, 1000000000)
)

#define ITOABASE_condition(NAME, ARGS, RESULT) ITOA_compare(ft_itoa_base, RESULT, ARGS)

TEST_SECTION(itoa_base, extract_name, ITOABASE_condition,
    (zero_base_2,       (0, 2),         "0"),
    (zero_base_36,      (0, 36),        "0"),
    (two_base_2,        (2, 2),         "10"),
    (abc_hex,           (0xabc, 16),    "ABC"),
    (int_max_base_2,    (INT_MAX, 2),   "1111111111111111111111111111111"),
    (int_max_base_16,   (INT_MAX, 16),  "7FFFFFFF"),
    (int_max_base_13,   (INT_MAX, 13),  "282BA4AAA"),
    (int_max_base_36,   (INT_MAX, 36),  "ZIK0ZJ"),
    (int_min_base_2,    (INT_MIN, 2),   "-10000000000000000000000000000000"),
    (cool,              (591861, 36),   "COOL"),
    (lmao,              (342149, 25),   "LMAO"),
    (hijack,            (73111016, 21), "HIJACK")
)
