#include "libunit.h"
#include "ft_ctype.h"
#include "comparisons.h"
#include "ft_prepro/functions.h"

#include <limits.h>
#include <stdbool.h>

static bool test(Function(int, char) reference, Function(int, char) mine)
{
    unsigned char c = UCHAR_MAX;

    while (c --> 0)
        if (reference(c) != mine(c))
            return false;
    return true;
}

CTYPE_condition(NAME) test(NAME, PP_CAT(ft_, NAME))

TEST_SECTION(ctype, extract_name, CTYPE_condition,
    (isalnum),
    (isalpha),
    (isascii),
    (isblank),
    (iscntrl),
    (isdigit),
    (isgraph),
    (islower),
    (isprint),
    (ispunct),
    (isspace),
    (isupper),
    (isxdigit),
    (tolower),
    (toupper)
)
