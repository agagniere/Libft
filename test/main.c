#include "ft_prepro/color.h"
#include "ft_prepro/tools.h"
#include "ft_printf.h"

#define TEST_LIST prepro, color, ctype, atoi, itoa, itoa_base, memcmp, memchr, bzero, strlen, strcmp, modf_float, modf_double, modf_long, heap, printf

#define DECLARE(IGNORED, NAME) \
    int PP_CAT(test_, NAME)(void);

#define CALL(SUCCESS, TOTAL, NAME) \
    SUCCESS += ! PP_CAT(test_, NAME)(); \
    TOTAL++;

FOR(EACH(TEST_LIST), DECLARE, IGNORED)

int main()
{
    unsigned success = 0;
    unsigned total = 0;

    FOR(EACH(TEST_LIST), CALL, success, total)
    ft_printf("%sResult : %u / %u functions%s\n", success == total ? COLOR(GREEN) : COLOR(RED), success, total, COLOR(NORMAL));
    return (success != total);
}
