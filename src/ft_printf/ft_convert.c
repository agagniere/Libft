/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/04 18:04:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_printf_private.h"
#include "libft.h"

static int pf_print(t_modifier* m, t_string* out, va_list* ap)
{
	int        i;
	char const c[]    = "diuoxXcCsSpbn";
	int      (*t[])() = {&pf_cv_di, &pf_cv_di, &pf_cv_u,
	                     &pf_cv_o, &pf_cv_x, &pf_cv_cx,
	                     &pf_cv_c, &pf_cv_wc, &pf_cv_s, &pf_cv_ws,
	                     &pf_cv_p, &pf_cv_b, &pf_cv_n};

	if (m->length == 'l' && is_in(m->conversion, "cs") >= 0)
		m->conversion = ft_toupper(m->conversion);
	if (is_in(m->conversion, "DOU") >= 0)
	{
		m->conversion = ft_tolower(m->conversion);
		m->length = 'l';
	}
	i = 0;
	while (c[i] != '\0' && m->conversion != c[i])
		i++;
	if (c[i] != '\0')
		return t[i](m, out, ap);
	string_append(out, &SUBSTR(&m->conversion, 1));
	return 1;
}

static int pf_precision(t_modifier* m, t_string* out, va_list* ap)
{
	size_t after;
	int    width;
	int    len;

	width = pf_print(m, out, ap);
	after = out->size;
	len   = width;
	if (len < m->precision && is_in(m->conversion, FTPF_NUMERIC) >= 0)
	{
		while (len < m->precision && ++len)
			string_append(out, &SUBSTR("0"));
		fta_swap(out, after - width, after);
	}
	return len;
}

void pf_convert(t_modifier* m, t_string* out, va_list* ap)
{
	size_t before;
	size_t after;
	int    width;
	int    len;

	before = out->size;
	width  = pf_precision(m, out, ap);
	after  = out->size;
	len    = after - before;
	if (len < m->size)
	{
		if (m->booleans.n.zero && m->precision == -1 && !m->booleans.n.minus)
		{
			while (len < m->size && ++len)
				string_append(out, &SUBSTR("0"));
			before = after - width;
		}
		else
			while (len < m->size && ++len)
				string_append(out, &SUBSTR(" "));
		if (!m->booleans.n.minus)
			fta_swap(out, before, after);
	}
}
