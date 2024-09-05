/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_integers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:37:36 by angagnie          #+#    #+#             */
/*   Updated: 2022/11/11 20:10:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_prepro/tools.h"
#include "ft_variadic.h"

/**
** pf_itoa_base appends @p n expressed in base @p base to @p out
*/

static int pf_itoa_base(t_string* out, intmax_t n, int base, bool is_unsigned, bool use_capital_hexdigits)
{
	int             ans;
	const uintmax_t un = (uintmax_t)n;
	const char* digits = (use_capital_hexdigits ? "0123456789ABCDEF" : "0123456789abcdef");

	ans = 1;
	if (is_unsigned ? (unsigned)base <= un : n <= -base || base <= n)
		ans += pf_itoa_base(out, (is_unsigned ? (intmax_t)(un / base) : n / base), base,
							is_unsigned, use_capital_hexdigits);
	fta_append(out, (void*)(digits + (is_unsigned ? (un % base) : ABS(n % base))), 1);
	return (ans);
}

static int pf_signed_integer(t_modifier* m, t_string* out, ft_va_list ap, int base, bool use_capital_hexdigits)
{
	intmax_t arg;

	if (m->length == 'H')
		arg = ft_va_arg(ap, schar);
	else if (m->length == 'h')
		arg = ft_va_arg(ap, short);
	else if (m->length == 'l' || m->length == 'z')
		arg = ft_va_arg(ap, long);
	else if (m->length == 'L')
		arg = ft_va_arg(ap, llong);
	else if (m->length == 't')
		arg = ft_va_arg(ap, ptrdiff_t);
	else if (m->length == 'j')
		arg = ft_va_arg(ap, intmax_t);
	else
		arg = ft_va_arg(ap, int);
	if (arg < 0)
		fta_append(out, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(out, "+", 1);
	else if (m->booleans.n.space)
		fta_append(out, " ", 1);
	if (arg == 0 && m->precision == 0)
		return (0);
	return pf_itoa_base(out, arg, base, false, use_capital_hexdigits);
}

static int pf_unsigned_integer(t_modifier* m, t_string* out, ft_va_list ap, int base, bool use_capital_hexdigits)
{
	uintmax_t arg;

	if (m->length == 'H')
		arg = ft_va_arg(ap, uchar);
	else if (m->length == 'h')
		arg = ft_va_arg(ap, ushort);
	else if (m->length == 'l')
		arg = ft_va_arg(ap, ulong);
	else if (m->length == 'L')
		arg = ft_va_arg(ap, ullong);
	else if (m->length == 'z')
		arg = ft_va_arg(ap, size_t);
	else if (m->length == 'j')
		arg = ft_va_arg(ap, uintmax_t);
	else
		arg = ft_va_arg(ap, unsigned);
	if (arg == 0 && m->booleans.n.alternate && (is_in(m->conversion, "xXb") >= 0))
		out->size -= 2;
	if (arg == 0 && m->precision == 0)
		return (0);
	if (arg == 0 && m->booleans.n.alternate && m->conversion == 'o')
		out->size -= 1;
	return pf_itoa_base(out, arg, base, true, use_capital_hexdigits);
}

/*
** For the d (decimal) and i (integer) conversions
*/

int pf_cv_di(t_modifier* m, t_string* out, ft_va_list ap)
{
	return pf_signed_integer(m, out, ap, 10, false);
}

/*
** For the capital X conversion
*/

int pf_cv_cx(t_modifier* m, t_string* out, ft_va_list ap)
{
	if (m->booleans.n.alternate)
		string_append(out, &SUBSTR("0X"));
	return pf_unsigned_integer(m, out, ap, 16, true);
}

int pf_cv_x(t_modifier* m, t_string* out, ft_va_list ap)
{
	if (m->booleans.n.alternate)
		string_append(out, &SUBSTR("0x"));
	return pf_unsigned_integer(m, out, ap, 16, false);
}

int pf_cv_o(t_modifier* m, t_string* out, ft_va_list ap)
{
	if (m->booleans.n.alternate)
		string_append(out, &SUBSTR("0"));
	return pf_unsigned_integer(m, out, ap, 8, false);
}

int pf_cv_u(t_modifier* m, t_string* out, ft_va_list ap)
{
	return pf_unsigned_integer(m, out, ap, 10, false);
}

int pf_cv_b(t_modifier* m, t_string* out, ft_va_list ap)
{
	if (m->booleans.n.alternate)
		string_append(out, &SUBSTR("0b"));
	return pf_unsigned_integer(m, out, ap, 2, false);
}

int pf_cv_p(t_modifier* m, t_string* out, ft_va_list ap)
{
	(void)m;
	string_append(out, &SUBSTR("0x"));
	m->length = 'L';
	return pf_unsigned_integer(m, out, ap, 16, false);
}
