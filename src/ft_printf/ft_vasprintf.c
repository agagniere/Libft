/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/04 19:00:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_printf.h"
#include "ft_printf_private.h"
#include "ft_variadic.h"
#include "libft.h"

static const char* pf_update_value(char const* s, int* v, va_list ap)
{
	if (*s == '*')
	{
		*v = ft_va_arg(ap, int);
		return (s + 1);
	}
	*v = 0;
	while ('0' <= *s && *s <= '9')
		*v = 10 * (*v) + *s++ - '0';
	return s;
}

static void pf_set_length(char c, char* lm)
{
	if ((c == 'h' || c == 'l') && *lm == c)
		*lm = ft_toupper(c);
	else
		*lm = c;
}

static const char* pf_match(char const* s, t_modifier* m, va_list ap)
{
	int n;

	while (*s != '\0')
	{
		if (*s == '.')
			s = pf_update_value(s + 1, &(m->precision), ap) - 1;
		else if (('1' <= *s && *s <= '9') || *s == '*')
			s = pf_update_value(s, &(m->size), ap) - 1;
		else if ((n = is_in(*s, FTPF_SWITCHES)) >= 0)
			m->booleans.t[n] = 1;
		else if (is_in(*s, FTPF_LM) >= 0)
			pf_set_length(*s, &(m->length));
		else if ((m->conversion = *s))
			return (s + 1);
		s++;
	}
	return s;
}

int ft_vasprintf(char** ret, char const* format, va_list ap)
{
	t_string    string = NEW_STRING;
	t_modifier  m;
	char const* p;

	fta_reserve(&string, ft_strlen(format));
	while (*format != '\0')
	{
		m = NEW_MODIFIER;
		if (*format == '%' && (format = pf_match(format + 1, &m, ap)) && m.conversion)
			pf_convert(&m, &string, ap);
		p = format;
		while (*p != '\0' && *p != '%')
			p++;
		if (p != format)
			fta_append(&string, format, p - format);
		format = p;
	}
	string_append(&string, &SUBSTR("\0", 1));
	fta_trim(&string);
	*ret = string.data;
	return (string.size - 1);
}
