#include "ft_variadic.h"

#define FT_VARIADIC_DEFINE(IGNORED, T)   \
	T FT_VARIADIC_NAME(T)(va_list* list)  \
	{                                    \
		return va_arg(*list, T);          \
	}

#define FT_VARIADIC_PROMOTION_DEFINE(T_in, T_out) \
	T_out FT_VARIADIC_NAME(T_out)(va_list* list)   \
	{                                             \
		return (T_out)va_arg(*list, T_in);         \
	}

FOR(EACH(Unpromoted), FT_VARIADIC_DEFINE)

FOR(EACH(PromotedToInt),      FT_VARIADIC_PROMOTION_DEFINE, int)
FOR(EACH(PromotedToUnsigned), FT_VARIADIC_PROMOTION_DEFINE, unsigned)
FOR(EACH(PromotedToDouble),   FT_VARIADIC_PROMOTION_DEFINE, double)
