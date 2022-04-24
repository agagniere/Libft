#include "libunit.h"
#include <limits.h>

#define ITOA_condition(NAME, INT) strcmp(atoi(INT), ft_atoi(INT)) == 0

TEST_SECTION(itoa, extract_name, ITOA_condition,
    (zero,     0),
    (one,      1),
    (basic,    42),
    (char_min, CHAR_MIN),
    (char_max, CHAR_MAX),
    (short_min,SHRT_MIN),
    (short_max,SHRT_MAX),
    (int_min,  INT_MIN),
    (int_max,  INT_MAX),
    (many_zeros, 1000000000)
)
