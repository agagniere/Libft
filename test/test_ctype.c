#include "libunit.h"
#include "ft_ctype.h"
#include "comparisons.h"
#include "ft_prepro/functions.h"
#include "ft_printf.h"

#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

static bool test(FunctionType(int, int) reference, FunctionType(int, int) mine, const char* name)
{
    unsigned char c = 128;

    while (c --> 0)
        if (reference(c) != mine(c))
        {
            ft_dprintf(2, "Difference for function %s : %hhi '%c'\n", name, c, c);
            return false;
        }
    return true;
}

#define CTYPE_condition(NAME) test(NAME, MERGE(ft, NAME), PP_STR(NAME))

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
