#include <math.h>
#include <stdbool.h>

bool test_modf(double f)
{
    double intg[2];
    double frac[2];

    frac[0] = ft_modf(f, intg);
    frac[1] = modf(f, intg + 1);
    return (frac[0] == frac[1] && intg[0] == intg[1]);
}

bool test_modff(float f)
{
    float intg[2];
    float frac[2];

    frac[0] = ft_modff(f, intg);
    frac[1] = modff(f, intg + 1);
    return (frac[0] == frac[1] && intg[0] == intg[1]);
}

bool test_modfl(long double f)
{
    long double intg[2];
    long double frac[2];

    frac[0] = ft_modfl(f, intg);
    frac[1] = modfl(f, intg + 1);
    return (frac[0] == frac[1] && intg[0] == intg[1]);
}
