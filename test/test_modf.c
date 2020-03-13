#include <math.h>
#include <stdbool.h>
#include "libft.h"

#define LFT 0
#define STD 1

#define _test_modf(T, NAME)                                     \
 bool test_##NAME(T f)                                          \
 {                                                              \
     T intg[2];                                                 \
     T frac[2];                                                 \
     frac[LFT] = ft_##NAME(f, intg + LFT);                      \
     frac[STD] = NAME(f, intg + STD);                           \
     if (isnan(frac[STD]) && isnan(frac[LFT]))                  \
         return true;                                           \
     return (frac[LFT] == frac[STD] && intg[LFT] == intg[STD]); \
 }

_test_modf(double, modf)
_test_modf(float, modff)
_test_modf(long double, modfl)
