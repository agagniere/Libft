#include "comparisons.h"
#include "ft_string_legacy.h"

#include <stdbool.h>

bool compare_int(int a, int b)
{
    return a == b;
}

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
    return (a > 0  && b > 0)
        || (a < 0  && b < 0)
        || (a == 0 && b == 0);
}

bool compare_str(const char* a, const char* b)
{
    return ft_strequ(a, b);
}
