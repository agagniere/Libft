#include "comparisons.h"

#define define_compare_sign(T) \
	declare_compare_sign(T) \
	{ return (a > 0 && b > 0) || (a < 0 && b < 0) || (a == 0 && b == 0); }

define_compare_sign(int)

#define ascending(A, B) (A == B ? 0 : A > B ? 1 : -1)
#define descending(A, B) ascending(B, A)

#define define_spaceship(WAY, T) \
	declare_spaceship(WAY, T) \
	{ return  WAY(*a, *b); }

#define define_spaceship_bothways(T) \
	define_spaceship(ascending, T) \
	define_spaceship(descending, T)

define_spaceship_bothways(int)
define_spaceship_bothways(unsigned)
