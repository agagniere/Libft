#include "libunit.h"

#include "ft_prepro/tools.h"
#include "ft_pythonic.h"
#include "ft_printf.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define PRINTF_condition(NAME, ARGS, EXPECTED)               \
	({                                                       \
		int   expected_len = strlen(EXPECTED);               \
		char* buffer       = NULL;                           \
		int   len          = ft_asprintf(&buffer, ID ARGS);  \
		bool  ans          = (len == expected_len);          \
		ans &= !!buffer;                                     \
		if (ans)                                             \
		{                                                    \
			ans &= (strcmp(buffer, EXPECTED) == 0);          \
			free(buffer);                                    \
		}                                                    \
		ans;                                                 \
	})

TEST_SECTION(printf_binary, extract_name, PRINTF_condition,
             (zero,      ("F0 - Binary _%b_", 0),      "F0 - Binary _0_"),
             (forty_two, ("F1 - Binary _%b_", 42),     "F1 - Binary _101010_"),
             (prefix,    ("F2 - Binary _%#b_", 9),     "F2 - Binary _b1001_"),
             (align,     ("F3 - Binary _%15b_", 753),  "F3 - Binary _     1011110001_"),
             (pad,       ("F4 - Binary _%015b_", 753), "F4 - Binary _000001011110001_")
)
