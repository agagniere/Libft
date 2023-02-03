#include "libunit.h"

#include "ft_prepro/tools.h"
#include "ft_pythonic.h"

#include <stdbool.h>
#include <string.h>

#define FOR_RANGE_condition(NAME, ARGS, ...)        \
    ({                                              \
        int  expected[] = {__VA_ARGS__};            \
        int  length     = C_ARRAY_LENGTH(expected); \
        int  i          = 0, v;                     \
        bool result     = true;                     \
        for (in_range(v, ID ARGS))                  \
        {                                           \
            if (i >= length || expected[i] != v)    \
                result = false;                     \
            i++;                                    \
        }                                           \
        result;                                     \
    })

TEST_SECTION(for_range, extract_name, FOR_RANGE_condition,
			 (simple,        (7),        0, 1, 2, 3, 4, 5, 6),
			 (with_begining, (3, 8),     3, 4, 5, 6, 7),
			 (with_step,     (1, 9, 2),  1, 3, 5, 7),
			 (negative_step, (9, 4, -1), 9, 8, 7, 6, 5)
)
