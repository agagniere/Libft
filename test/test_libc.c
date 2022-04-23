#include "libunit.h"
#include "libft.h"

#define name(NAME, STRING) NAME
#define condition(NAME, STRING) strlen(STRING) == ft_strlen(STRING)

#define S !#$%%&()*+-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~
#define T PP_STR(S S S S) ",'\""
#define U T T T T

TEST_SECTION(strlen, name, condition,
    (basic_string, "Hello, World !"),
    (empty_string, ""),
    (short_string, "1"),
    (long_string, "   \t   \v  \n    !@#$^&*(%%)   0123456789   [0123456789] <0123456789>   \n  \0   "),
    (extra_long_string, U U U U)
)
