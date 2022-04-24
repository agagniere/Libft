#include "libunit.h"
#include "ft_prepro/tools.h"
#include "ft_math.h"

#include <math.h>
#include <float.h>
#include <stdbool.h>

#define LFT 0
#define STD 1

#define _test_modf(T, NAME)                                        \
	bool PP_CAT(test_, NAME)(T f)                                  \
	{                                                              \
		T intg[2];                                                 \
		T frac[2];                                                 \
		frac[LFT] = PP_CAT(ft_, NAME)(f, intg + LFT);              \
		frac[STD] = NAME(f, intg + STD);                           \
		if (isnan(frac[STD]) && isnan(frac[LFT]))                  \
			return true;                                           \
		return (frac[LFT] == frac[STD] && intg[LFT] == intg[STD]); \
	}

_test_modf(double, modf)
_test_modf(float, modff)
_test_modf(long double, modfl)

#define MODF_condition(NAME, X) test_modf(X)
#define MODFF_condition(NAME, X) test_modff(X)
#define MODFL_condition(NAME, X) test_modfl(X)

TEST_SECTION(modf_float, extract_name, MODFF_condition,
	(zero,      0.f),
	(one,       1.f),
	(two,       2.f),
	(forty_two, 42.f),
	(four_point_two, 4.2f),
	(pi,        3.1415926535f),
	(small,     4.7e-30f),
	(big,       7.4e30f),
	(min,       FLT_MIN),
	(true_min,  FLT_TRUE_MIN),
	(max,       FLT_MAX),
	(infinity,  INFINITY),
	(minus_infinity, -INFINITY),
	(not_a_number, NAN)
)

TEST_SECTION(modf_double, extract_name, MODF_condition,
	(zero,      0.),
	(one,       1.),
	(two,       2.),
	(forty_two, 42.),
	(four_point_two, 4.2),
	(pi,        M_PI),
	(small,     4.7e-30),
	(big,       7.4e30),
	(tiny,      3e-100),
	(huge,      9e180),
	(subnormal, 1e-320),
	(min,       DBL_MIN),
	(true_min,  DBL_TRUE_MIN),
	(max,       DBL_MAX),
	(infinity,  INFINITY),
	(minus_infinity, -INFINITY),
	(not_a_number, NAN)
)

TEST_SECTION(modf_long, extract_name, MODFL_condition,
	(zero,      0.l),
	(one,       1.l),
	(two,       2.l),
	(forty_two, 42.l),
	(four_point_two, 4.2l),
	(pi,        M_PI),
	(small,     4.7e-30l),
	(big,       7.4e30l),
	(tiny,      3e-100l),
	(huge,      9e180l),
	(minuscule, 5.456e-600l),
	(vast,      5.987e700l),
	(min,       LDBL_MIN),
	(true_min,  LDBL_TRUE_MIN),
	(max,       LDBL_MAX),
	(infinity,  INFINITY),
	(minus_infinity, -INFINITY),
	(not_a_number, NAN)
)
