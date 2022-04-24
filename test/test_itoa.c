#include "libunit.h"
#include "libft.h"

#include <limits.h>
#include <string.h>

#define ITOA_condition(NAME, INT) strcmp(PP_STR(INT), ft_itoa(INT)) == 0

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
