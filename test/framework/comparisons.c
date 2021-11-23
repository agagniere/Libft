#include "comparisons.h"

#include "ft_string_legacy.h"

#include <stdbool.h>

bool compare_int(int a, int b) { return a == b; }

/*
bool compare_float(float a, float b)
{
    float absA = fabsf(a);
    float absB = fabsf(b);
    float diff = fabsa(a - b);
}
*/

bool compare_int_sign(int a, int b)
{
	return (a > 0 && b > 0) || (a < 0 && b < 0) || (a == 0 && b == 0);
}

bool compare_str(const char* a, const char* b) { return ft_strequ(a, b); }

int unsigned_spaceship_ascending(const unsigned* a, const unsigned* b)
{
	if (*a > *b)
		return 1;
	return (*a == *b ? 0 : -1);
}

int unsigned_spaceship_descending(const unsigned* a, const unsigned* b)
{
	return unsigned_spaceship_ascending(b, a);
}

int int_spaceship_ascending(const int* a, const int* b) { return (*a - *b); }

int int_spaceship_descending(const int* a, const int* b)
{
	return int_spaceship_ascending(b, a);
}
