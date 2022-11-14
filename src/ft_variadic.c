#include "ft_variadic.h"

#if defined(__APPLE__) && defined(__arm64__)
# define get_list(ap) (*ap)
#elif defined(__amd64__) || defined(__x86_64__)
# define get_list(ap) (ap)
#else
# error ":("
#endif

#define FT_VARIADIC_DEFINE(IGNORED, T)	  \
	T FT_VARIADIC_NAME(T)(ft_va_list list) \
	{ \
		return va_arg(get_list(list), T); \
	}

#define FT_VARIADIC_PROMOTION_DEFINE(T_in, T_out)	  \
	T_out FT_VARIADIC_NAME(T_out)(ft_va_list list) \
	{ \
		return (T_out)va_arg(get_list(list), T_in); \
	}

FOR(EACH(Unpromoted), FT_VARIADIC_DEFINE)

FOR(EACH(PromotedToInt),      FT_VARIADIC_PROMOTION_DEFINE, int)
FOR(EACH(PromotedToUnsigned), FT_VARIADIC_PROMOTION_DEFINE, unsigned)
FOR(EACH(PromotedToDouble),   FT_VARIADIC_PROMOTION_DEFINE, double)
