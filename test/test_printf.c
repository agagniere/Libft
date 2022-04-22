#include "ft_prepro/color.h"
#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUN_TEST(SUCCESS, FMT, ...)                                                               \
	pf = asprintf(&pf_dst, FMT, ##__VA_ARGS__);                                                   \
	ft = ft_asprintf(&ft_dst, FMT, ##__VA_ARGS__);                                                \
	if (ft != pf)                                                                                 \
		ft_printf("\t%sReturn value Real(%i vs %i)Yours%s\n", COLOR(RED), pf, ft, COLOR(NORMAL)); \
	if (pf > 0 && ft > 0)                                                                         \
	{                                                                                             \
		if (ft_strcmp(ft_dst, pf_dst))                                                            \
			ft_printf("%s\t|%s| (Real) vs\n\t|%s| (Yours)\n%s",                                   \
			          COLOR(RED), pf_dst, ft_dst, COLOR(NORMAL));                                 \
		else                                                                                      \
		{                                                                                         \
			ft_printf("\t[%s%s%s]\n", COLOR(GREEN), ft_dst, COLOR(NORMAL));                       \
			SUCCESS;                                                                              \
		}                                                                                         \
	}                                                                                             \
	else if (pf == 0 && ft == 0)                                                                  \
		SUCCESS;                                                                                  \
	else if (pf < 0 && ft > 0)                                                                    \
		ft_printf("\t[%s%s%s]\n", COLOR(BLUE), ft_dst, COLOR(NORMAL));                            \
	if (pf >= 0)                                                                                  \
		free(pf_dst);                                                                             \
	if (ft >= 0)                                                                                  \
		free(ft_dst);

#define TEST(FMT, ...)                       \
	RUN_TEST(success++, FMT, ##__VA_ARGS__); \
	total++;

// Testing Undefined behavior
#define UB(FMT, ...) RUN_TEST(, FMT, __VA_ARGS__)

int test_printf()
{
	char* pf_dst;
	char* ft_dst;
	int   pf;
	int   ft;
	int   total   = 0;
	int   success = 0;

	ft_printf("printf {\n");
	TEST("1-Simple String.");
	TEST("2-Stringception _%s_", "Hello World");
	TEST("3-Stringception _%20s_", "Hello World");
	TEST("4-Stringception _%-20s_", "Hello World");
	TEST("5-Stringception _%20.5s_", "Hello World");
	TEST("6-Stringception _%-20.5s_", "Hello World");
	TEST("7-Stringception _%.20s_", "Hello World");
	TEST("8-Stringception _%-.20s_", "Hello World");
	TEST("9-Stringception _%5.20s_", "Hello World");
	TEST("A-Stringception _%20.s_", "Hello World");
	TEST("B-Integer _%i_", -612345);
	TEST("C-Integer _%u_", (1 << 31) + 75312);
	TEST("D-Integer _%hhi_", -120);
	TEST("E-Integer _%hhu_", 250);
	TEST("F-Integer _%hi_", -9999);
	TEST("G-Integer _%hu_", 65123);
	TEST("H-Integer _%#.10hx_", -61234);
	TEST("I-Integer _%lX_", 0xDEADBEEFCAFE);
	TEST("J-Pointer _%p_", &pf);
	TEST("K-Pointer _%p_", (void*)1);
	TEST("L-Pointer _%20p_", (void*)&ft);
	TEST("M-Pointer _%2p_", (void*)&ft);
	TEST("N-Combo _%20i_", -'*');
	TEST("O-Combo _%20.10i_", -'*');
	TEST("P-Combo _%.10i_", -'*');
	TEST("Q-Combo _%020i_", -'*');
	TEST("R-Combo _%#20.10x_", '*');
	TEST("S-Combo _%-20i_", -'*');
	TEST("T-Combo _%-20.10i_", -'*');
	TEST("U-Combo _%-.10i_", -'*');
	TEST("V-Combo _%-#20.10x_", '*');
	TEST("W-Non ASCII string _%s_ (len = %li)", "我很好！", ft_strlen("我很好！"));
	TEST("X-NULL string _%s_", (char*)NULL);
	TEST("Y-NULL string _%4s_", (char*)NULL);
	TEST("Z-NULL string _%S_", (wchar_t*)NULL);
	TEST("10-NULL string _%4ls_", (wchar_t*)NULL);
	TEST("11-Number _%#015X_", 0xDEADBEEF);
	TEST("12-Zero _%+i_", 0);
	TEST("13-Zero _%0+i_", 0);
	TEST("14-Zero _%+.i_", 0);
	TEST("15-Zero _%.u_", 0);
	TEST("16-Zero _%10.0i_", 0);
	TEST("17-Zero _%10.0u_", 0);
	TEST("18-Zero _%-10.0i_", 0);
	TEST("19-Advanced _%i_%10i_%.5i_%10.5i_%010i_%.0i_", -42, -42, -42, -42, -42, 0);
	TEST("1A-Advanced _%u_%10u_%.5u_%10.5u_%010u_%.0u_", -42, -42, -42, -42, -42, 0);
	TEST("1B-Zero %#x", 0);
	TEST("1C-Zero %#.x %#.0x", 0, 0);
	TEST("1D-Wide char _%lc_", L'A');
	TEST("1E-Wide char _%C_", L'B');
	TEST("1F-Hexa a%xb%xc%xd", 0, 55555, 1000000);
	TEST("1G-Hexa a%Xb%Xc%Xd", 0, 55555, 1000000);
	TEST("1H-Octal a%ob%oc%od", 0, 55555, 1000000);
	TEST("1I-Octal _%o_%#o_%0o_%0#o_%.0o_%#.0o_", 0, 0, 0, 0, 0, 0);
	TEST("1J-Wildcard _%*s_%*s_", 5, "Hello world", 50, "Hello world");
	TEST("1K-Wildcard _%.*s_%.*s_", 5, "Hello world", 50, "Hello world");
	TEST("1L-Wildcard _%*.*s_%*.*s_", 5, 5, "Hello world", 50, 50, "Hello world");
	TEST("1M-Wildcard _%*.*s_%*.*s_", 50, 5, "Hello world", 5, 50, "Hello world");
	TEST("1N-Wildcard _%*.*s_%*.*s_", 50, -5, "Hello world", -5, 50, "Hello world");
	TEST("")
	TEST("%s%s", "", "")

	int a, b, c, d, e, f;
	TEST("~ N-Flag >%n< %10.7s %.10s %5i.%.4i%% >%n< %#X%x%X%x >%n<",
	     &a, "outputs some secrets", "[REDACTED] your password", 99, 98765,
	     &b, 0xb, 0xabe, 0xc, 0xafe, &c);
	printf("\t[~ N-Flag >%n< %10.7s %.10s %5i.%.4i%% >%n< %#X%x%X%x >%n<]\n",
	       &a, "outputs some secrets", "[REDACTED] your password", 99, 98765,
	       &b, 0xb, 0xabe, 0xc, 0xafe, &c);
	printf("\t[~ N-Flag >%n< %10.7s %.10s %5i.%.4i%% >%n< %#X%x%X%x >%n<]\n",
	       &d, "outputs some secrets", "[REDACTED] your password", 99, 98765,
	       &e, 0xb, 0xabe, 0xc, 0xafe, &f);
	fflush(stdout);
	if (a != d || b != e || c != f)
		ft_printf("%s\tFail: (Real,FT) (%i,%i) (%i,%i) (%i,%i)%s\n", COLOR(RED), d, a, e, b, f, c, COLOR(NORMAL));
	else
		success++;
	total++;

	UB("20-Wide string _%ls_", L"Hello there !");
	UB("21-Wide string _%S_", L"克诺比将军");
	UB("22-Wide char _%C_", 0x20AC);
	UB("23-Wide char _%C_", L'€');
	UB("24-Overflow _%i_", (42L << 50) +  987654L);
	UB("25-Overflow _%u_", (42L << 50) +  987654L);
	UB("26-Overflow _%hi_", -987654L);
	UB("27-Overflow _%hu_", -987654L);
	UB("28-Overflow _%hhi_", -987657L);
	UB("29-Overflow _%hhu_", -987657L);
	UB("2A-Overflow _%hhhi_", -987657L);
	UB("2B-Overflow _%hhhu_", -987657L);
	UB("2C-Overflow _%hhhhi_", -987657L);
	UB("2D-Overflow _%hhhhu_", -987657L);

	TEST("%s", "The End");
	ft_printf("\t%s%i / %i%s tests passed\n}\n\n",
	          (success == total ? COLOR(GREEN, BOLD) : COLOR(RED, BOLD)),
	          success, total, COLOR(NORMAL));
	return (success != total);
}
