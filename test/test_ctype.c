#include "libunit.h"
#include "ft_ctype.h"
#include "comparisons.h"
#include "ft_prepro/functions.h"

#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

static bool test(FunctionType(int, int) reference, FunctionType(int, int) mine)
{
    unsigned char c = 128;

    while (c --> 0)
        if (!reference(c) != !mine(c))
            return false;
    return true;
}

#define CTYPE_condition(NAME) test(NAME, MERGE(ft, NAME))

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
