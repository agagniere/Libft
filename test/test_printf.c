#include "libunit.h"

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_prepro/raii.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void cleanup_t_cstring(t_cstring* str) { if (*str) free(*str); }

#define PRINTF_condition(NAME, ...)										\
	({																	\
		RAII(t_cstring) pf_dst = NULL;									\
		RAII(t_cstring) ft_dst = NULL;									\
		int pf = asprintf(&pf_dst, __VA_ARGS__);						\
		int ft = ft_asprintf(&ft_dst, __VA_ARGS__);						\
		bool ans = (ft == pf) || (ft < 0 && pf < 0);					\
		if (ans && pf > 0)												\
			ans &= (strcmp(ft_dst, ft_dst) == 0);						\
		ans;															\
	})

TEST_SECTION(printf_string, extract_name, PRINTF_condition,
			 (simplest,         "1 Simple String."),
			 (simple,           "2 Stringception _%s_", "Hello World"),
			 (length,           "3 Stringception _%20s_", "Hello World"),
			 (precision,        "7 Stringception _%.20s_", "Hello World"),
			 (right,            "4 Stringception _%-20s_", "Hello World"),
			 (len_prec,         "5 Stringception _%20.5s_", "Hello World"),
			 (len_prec_right,   "6 Stringception _%-20.5s_", "Hello World"),
			 (prec_right,       "8 Stringception _%-.20s_", "Hello World"),
			 (prec_len,         "9 Stringception _%5.20s_", "Hello World"),
			 (len_zp,           "A Stringception _%20.s_", "Hello World"),
			 (non_ascii,        "W Non ASCII string _%s_ (len = %li)", "我很好！", ft_strlen("我很好！")),
			 (null,             "X NULL string _%s_", (char*)NULL),
			 (null_length,      "Y NULL string _%4s_", (char*)NULL),
			 (null_wide,        "Z NULL string _%S_", (wchar_t*)NULL),
			 (null_length_wide, "10 NULL string _%4ls_", (wchar_t*)NULL),
			 (wide_char,        "1D Wide char _%lc_", L'A'),
			 (wide_char_alt,    "1E Wide char _%C_", L'B'),
			 (simple_char,      "26 Simple char _%c_", '^'),
			 (complex_combo,    "A %character followed by a %ls %-10.3s)", 'C', L"wide string", NULL)
	)

TEST_SECTION(printf_hexa, extract_name, PRINTF_condition,
			 (pf_H_Integer, "H Integer _%#.10hx_", -61234),
			 (pf_I_Integer, "I Integer _%lX_", 0xDEADBEEFCAFE),
			 (pf_J_Pointer, "J Pointer _%p_", &pf),
			 (pf_K_Pointer, "K Pointer _%p_", (void*)1),
			 (pf_L_Pointer, "L Pointer _%20p_", (void*)&ft_printf),
			 (pf_M_Pointer, "M Pointer _%2p_", (void*)&ft_dprintf),
			 (pf_R_Combo, "R Combo _%#20.10x_", '*'),
			 (pf_V_Combo, "V Combo _%-#20.10x_", '*'),
			 (pf_11_Number, "11 Number _%#015X_", 0xDEADBEEF),
			 (pf_1B_Zero, "1B Zero %#x", 0),
			 (pf_1C_Zero, "1C Zero %#.x %#.0x", 0, 0),
			 (pf_1F_Hexa, "1F Hexa a%xb%xc%xd", 0, 55555, 1000000),
			 (pf_1G_Hexa, "1G Hexa A%XB%XC%XD", 0, 55555, 1000000),
			 (pf_1H_Octal, "1H Octal a%ob%oc%od", 0, 55555, 1000000),
			 (pf_1I_Octal, "1I Octal _%o_%#o_%0o_%0#o_%.0o_%#.0o_", 0, 0, 0, 0, 0, 0)
	)

TEST_SECTION(printf_integer, extract_name, PRINTF_condition,
			 (pf_B_Integer, "B Integer _%i_", -612345),
			 (pf_C_Integer, "C Integer _%u_", (1 << 31) + 75312),
			 (pf_D_Integer, "D Integer _%hhi_", -120),
			 (pf_E_Integer, "E Integer _%hhu_", 250),
			 (pf_F_Integer, "F Integer _%hi_", -9999),
			 (pf_G_Integer, "G Integer _%hu_", 65123),
			 (pf_N_Combo, "N Combo _%20i_", -'*'),
			 (pf_O_Combo, "O Combo _%20.10i_", -'*'),
			 (pf_P_Combo, "P Combo _%.10i_", -'*'),
			 (pf_Q_Combo, "Q Combo _%020i_", -'*'),
			 (pf_S_Combo, "S Combo _%-20i_", -'*'),
			 (pf_T_Combo, "T Combo _%-20.10i_", -'*'),
			 (pf_U_Combo, "U Combo _%-.10i_", -'*'),
			 (pf_12_Zero, "12 Zero _%+i_", 0),
			 (pf_13_Zero, "13 Zero _%0+i_", 0),
			 (pf_14_Zero, "14 Zero _%+.i_", 0),
			 (pf_15_Zero, "15 Zero _%.u_", 0),
			 (pf_16_Zero, "16 Zero _%10.0i_", 0),
			 (pf_17_Zero, "17 Zero _%10.0u_", 0),
			 (pf_18_Zero, "18 Zero _%-10.0i_", 0),
			 (pf_19_Advanced, "19 Advanced _%i_%10i_%.5i_%10.5i_%010i_%.0i_", -42, -42, -42, -42, -42, 0),
			 (pf_1A_Advanced, "1A Advanced _%u_%10u_%.5u_%10.5u_%010u_%.0u_", -42, -42, -42, -42, -42, 0),
			 (pf_1J_Wildcard, "1J Wildcard _%*s_%*s_", 5, "Hello world", 50, "Hello world"),
			 (pf_1K_Wildcard, "1K Wildcard _%.*s_%.*s_", 5, "Hello world", 50, "Hello world"),
			 (pf_1L_Wildcard, "1L Wildcard _%*.*s_%*.*s_", 5, 5, "Hello world", 50, 50, "Hello world"),
			 (pf_1M_Wildcard, "1M Wildcard _%*.*s_%*.*s_", 50, 5, "Hello world", 5, 50, "Hello world"),
			 (pf_1N_Wildcard, "1N Wildcard _%*.*s_%*.*s_", 50, -5, "Hello world", -5, 50, "Hello world"),
			 (pf_1O_Long, "1O Long integers _%li_", (1L) << 50),
			 (pf_1P_Long, "1P Long integers _%lli_", ((1L) << 60) + 12345),
			 (pf_1Q_Long, "1Q Long integers _%lu_", ((1LU) << 63) + 98765)
	)

TEST_SECTION(printf_limits, extract_name, PRINTF_condition,
			 (min_long_long, "1R Limits _%lli_", LLONG_MIN),
			 (min_long,      "1S Limits _%li_", LONG_MIN),
			 (min_int,       "1T Limits _%i_", INT_MIN),
			 (min_short,     "1U Limits _%hi_", SHRT_MIN),
			 (min_schar,     "1V Limits _%hhi_", SCHAR_MIN),
			 (max_schar,     "1W Limits _%hhi_", SCHAR_MAX),
			 (max_short,     "1X Limits _%hi_", SHRT_MAX),
			 (max_int,       "1Y Limits _%i_", INT_MAX),
			 (max_long,      "1Z Limits _%li_", LONG_MAX),
			 (max_long_long, "20 Limits _%lli_", LLONG_MAX),
			 (max_uchar,     "21 Limits unsigned _%hhu_", UCHAR_MAX),
			 (max_ushort,    "22 Limits unsigned _%hu_", USHRT_MAX),
			 (max_uint,      "23 Limits unsigned _%u_", UINT_MAX),
			 (max_ulong,     "24 Limits unsigned _%lu_", ULONG_MAX),
			 (max_ullong,    "25 Limits unsigned _%llu_", ULLONG_MAX)
	)

#define _PRINTF_MANUAL_condition(NAME, ARGS, EXPECTED, EXPECTED_LEN)\
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
		if (!ans) { printf("[%i]", expected_len); printf ARGS; }	\
		ans;                                                 \
	})

#define PRINTF_MANUAL_condition(NAME, ARGS, EXPECTED)						\
	_PRINTF_MANUAL_condition(NAME, ARGS, EXPECTED, strlen(EXPECTED))

/*
TEST_SECTION(printf_wide, extract_name, _PRINTF_MANUAL_condition,
			 (char,     ("40 - Wide char '%lc'", L'A'), "40 - Wide char 'A'", 18),
			 (ascii,    ("41 - Wide string \"%ls\"", L"Hello"), "41 - Wide string \"Hello\"", 24),
			 (chinese,  ("42 - Non ASCII _%ls_", L"我很好！"), "42 - Non ASCII _我很好！_", 33)
	)
*/

TEST_SECTION(printf_zero_int, extract_name, PRINTF_MANUAL_condition,
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

TEST_SECTION(printf_zero_unsigned, extract_name, PRINTF_MANUAL_condition,
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

TEST_SECTION(printf_binary, extract_name, PRINTF_MANUAL_condition,
	(zero,      ("F0 - Binary _%b_", 0),         "F0 - Binary _0_"),
	(forty_two, ("F1 - Binary _%b_", 42),        "F1 - Binary _101010_"),
	(prefix,    ("F2 - Binary _%#b_", 9),        "F2 - Binary _0b1001_"),
	(align,     ("F3 - Binary _%15b_", 753),     "F3 - Binary _     1011110001_"),
	(pad,       ("F4 - Binary _%015b_", 753),    "F4 - Binary _000001011110001_"),
	(przp,      ("F5 - Binary _%#.0b_", 943),    "F5 - Binary _0b1110101111_"),
	(zero_przp, ("F6 - Binary _%#.0b_", 0),      "F6 - Binary __"),
	(neg_pr,    ("F7 - Binary _%#hhb_", -1),     "F7 - Binary _0b11111111_"),
	(neg_pszp,  ("F8 - Binary _%# +0.hb_", -999),"F8 - Binary _0b1111110000011001_")
)

TEST_SECTION(printf_boolean, extract_name, PRINTF_MANUAL_condition,
	(yes,        ("B1 - Boolean _%B_", true),    "B1 - Boolean _true_"),
	(no,         ("B2 - Boolean _%B_",  false),  "B2 - Boolean _false_"),
	(length,     ("B3 - Boolean _%8B_", true),   "B3 - Boolean _    true_"),
	(left,       ("B4 - Boolean _%-8B_", true),  "B4 - Boolean _true    _"),
	(precisionT, ("B5 - Boolean _%.3B_", true),  "B5 - Boolean _tru_"),
	(precisionF, ("B6 - Boolean _%.3B_", false), "B6 - Boolean _fal_")
)

int test_printf()
{
	TEST_GROUP("printf");

	return test_printf_string()
		|| test_printf_integer()
		|| test_printf_hexa()
		|| test_printf_limits()
		|| test_printf_zero_int()
		|| test_printf_zero_unsigned()
		|| test_printf_binary()
		|| test_printf_boolean();
}
