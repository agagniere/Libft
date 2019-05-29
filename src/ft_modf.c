/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agagniere <antoine.gagniere@amadeus.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:18:57 by agagniere         #+#    #+#             */
/*   Updated: 2019/05/28 11:43:29 by agagniere        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

/*
** -----===== Custom Types =====-----
*/
typedef union _my_double  my_double;
typedef union _my_float   my_float;

union _my_double
{
    double  data;
    struct
    {
        uint64_t significand:52;
        uint64_t exponent:11;
        uint64_t sign:1;
    }       fields;
};

union _my_float
{
    float   data;
    struct
    {
        uint32_t significand:23;
        uint32_t exponent:8;
        uint32_t sign:1;
    }       fields;
};

/*
** -----===== modf implementation =====-----
** If the number's magnitude is greater than 1
** and small enough so that it has a fractional part,
** we can separate the integral part.
** -
** To do so we select the digits before decimal with a mask
** -
** f == f is false when f is NaN
*/
#define _ft_modf(FRAC, INT, OUT, POW_MID, BIT_LEN)                      \
    int power = INT.fields.exponent - POW_MID;                          \
    if ((FRAC == FRAC)                                                  \
        && (power < BIT_LEN || (FRAC = 0))                              \
        && (power >= 0 || (INT.data = 0)))                              \
    {                                                                   \
        INT.fields.significand &= ~0UL << (BIT_LEN - power);            \
        FRAC -= INT.data;                                               \
    }                                                                   \
    if (OUT != NULL)                                                    \
        *OUT = INT.data;

double ft_modf(double input, double* out_integral)
{
    my_double intg = (my_double){input};
    _ft_modf(input, intg, out_integral, 1023, 52);
    return (input);
}
float ft_modff(float input, float* out_integral)
{
    my_float intg = (my_float){input};
    _ft_modf(input, intg, out_integral, 127, 23);
    return (input);
}
long double ft_modfl(long double input, long double* out_integral)
{
    my_double intg = (my_double){input};
    _ft_modf(input, intg, out_integral, 1023, 52);
    return (input);
}

#ifdef UNIT_TEST

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* Debug functions */
void display_double(const double* f)
{
    const my_double* x = (my_double*)f;
    printf("(-1)^%u * 2^%-5i * %lx * 2^-52 = %+.12lf\n",
           x->fields.sign, (x->fields.exponent - 1023), (x->fields.significand + (1UL << 52)), x->data);
}
void display_float(const float* f)
{
    const my_float* x = (my_float*)f;
    printf("(-1)^%u * 2^%-4i * %x * 2^-23 = %+f\n",
           x->fields.sign, (x->fields.exponent - 127), (x->fields.significand + (1U << 23)), x->data);
}

/* Test functions */
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

int  main(int ac, char** av)
{
    while (ac --> 1)
    {
        double f = atof(av[ac]);
        bool   is_success = test_modff(f);
        printf("%+20lf : [%s]\n", f, is_success ? "OK" : "no");
    }
    return (0);
}

#endif /* UNIT_TEST */
