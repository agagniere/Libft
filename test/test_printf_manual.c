#include "libunit.h"

#include "ft_prepro/tools.h"
#include "ft_pythonic.h"
#include "ft_printf.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define _PRINTF_condition(NAME, ARGS, EXPECTED, EXPECTED_LEN)\
	({                                                       \
		int   expected_len = EXPECTED_LEN;					 \
		char* buffer       = NULL;                           \
		int   len          = ft_asprintf(&buffer, ID ARGS);  \
		bool  ans          = (len == expected_len);          \
		ans &= !!buffer;                                     \
		if (ans)                                             \
		{                                                    \
			ans &= (strcmp(buffer, EXPECTED) == 0);          \
			free(buffer);                                    \
		}                                                    \
		if (!ans) printf ARGS;								 \
		ans;                                                 \
	})

#define PRINTF_condition(NAME, ARGS, EXPECTED)						\
	_PRINTF_condition(NAME, ARGS, EXPECTED, strlen(EXPECTED))


TEST_SECTION(printf_wide, extract_name, _PRINTF_condition,
			 (char,     ("40 - Wide char '%lc'", L'A'), "40 - Wide char 'A'", 18),
			 (chinese,  ("41 - Non ASCII _%ls_", L"我很好！"), "40 - Non ASCII _我很好！_", 33)
	)


TEST_SECTION(printf_zero_int, extract_name, PRINTF_condition,
			 (simple,         ("_%i_", 0),       "_0_"),
			 (zero,           ("_%0i_", 0),      "_0_"),
			 (dot,            ("_%.i_", 0),      "__"),
			 (sign,           ("_%+i_", 0),      "_+0_"),
			 (size,           ("_%5i_", 0),      "_    0_"),
			 (precision,      ("_%.5i_", 0),     "_00000_"),
			 (zero_precision, ("_%.0i_", 0),     "__"),
			 (padding,        ("_%05i_", 0),     "_00000_"),
			 (zp_size,        ("_%5.0i_", 0),    "_     _"),
			 (zp_zero,        ("_%0.0i_", 0),    "__"),
			 (zp_sign,        ("_%+.0i_", 0),    "_+_")
	)

TEST_SECTION(printf_zero_unsigned, extract_name, PRINTF_condition,
			 (simple,         ("_%u_", 0),       "_0_"),
			 (zero,           ("_%0u_", 0),      "_0_"),
			 (dot,            ("_%.u_", 0),      "__"),
			 (sign,           ("_%+u_", 0),      "_0_"),
			 (size,           ("_%5u_", 0),      "_    0_"),
			 (precision,      ("_%.5u_", 0),     "_00000_"),
			 (zero_precision, ("_%.0u_", 0),     "__"),
			 (padding,        ("_%05u_", 0),     "_00000_"),
			 (zp_size,        ("_%5.0u_", 0),    "_     _"),
			 (zp_zero,        ("_%0.0u_", 0),    "__"),
			 (zp_sign,        ("_%+.0u_", 0),    "__")
	)

TEST_SECTION(printf_binary, extract_name, PRINTF_condition,
             (zero,      ("F0 - Binary _%b_", 0),      "F0 - Binary _0_"),
             (forty_two, ("F1 - Binary _%b_", 42),     "F1 - Binary _101010_"),
             (prefix,    ("F2 - Binary _%#b_", 9),     "F2 - Binary _b1001_"),
             (align,     ("F3 - Binary _%15b_", 753),  "F3 - Binary _     1011110001_"),
             (pad,       ("F4 - Binary _%015b_", 753), "F4 - Binary _000001011110001_")
	)
