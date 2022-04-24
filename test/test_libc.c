#include "libunit.h"
#include "libft.h"
#include "comparisons.h"

#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define S "!#$%%&()*+-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'\", "
#define T S S S S S S S S
#define U T T T T T T T T

#define STRLEN_condition(NAME, STRING) strlen(STRING) == ft_strlen(STRING)

TEST_SECTION(strlen, extract_name, STRLEN_condition,
    (basic, "Hello, World !"),
    (empty, ""),
    (short, "1"),
    (long,  "   \t   \v  \n    !@#$^&*(%%)   0123456789   [0123456789] <0123456789>   \n  \0   "),
    (extra_long, U)
)

#define ATOI_condition(NAME, STRING) atoi(STRING) == ft_atoi(STRING)

TEST_SECTION(atoi, extract_name, ATOI_condition,
    (basic,         "28"),
    (negative,      "-8128"),
    (negative_zero, "-0"),
    (space,         "    -496"),
    (plus_sign,     " +1729 Ramanujan Number"),
    (tab,           " \t\t 33550336 Perfect"),
    (carriage_return,"\r +877 Bell Prime"),
    (form_feed,     " \f -16127 Carol Prime"),
    (vertical_tab,  " \v 7057 Cuban Prime"),
    (two_plus_signs,"++3"),
    (invalid_first_char, "~197 Chen"),
    (leading_zeros, " +0000231"),
    (int_min,       "-2147483648"),
    (int_max,       " 2147483647"),
    (combo,       " \r\v\n +000002147483647")
)

#define STRCMP_condition(NAME, A, B) compare_int_sign(strcmp(A, B), ft_strcmp(A, B))

TEST_SECTION(strcmp, extract_name, STRCMP_condition,
    (basic_equality, "Hello, World!", "Hello, World!"),
    (basic_inequality, "string_one", "string_two"),
    (empty_s1, "", "why"),
    (empty_s2, "not", "2"),
    (empty_both, "", ""),
    (long_equality, U, U),
    (long_inequality, U, U " ")
)
