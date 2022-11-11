/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:37:44 by angagnie          #+#    #+#             */
/*   Updated: 2022/11/11 18:04:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prepro/tools.h"
#include "ft_printf_private.h"
#include "ft_wchar.h"
#include "ft_variadic.h"

#include <wchar.h>

int pf_cv_s(t_modifier* m, t_string* out, va_list ap)
{
	char*  arg;
	int    ans;
	size_t len;

	arg = ft_va_arg(ap, t_cstring);
	if (arg == NULL)
		arg = "(null)";
	len = ft_strlen(arg);
	ans = (m->precision >= 0 ? MIN(len, (size_t)m->precision) : len);
	string_append(out, &SUBSTR(arg, ans));
	return ans;
}

int pf_cv_ws(t_modifier* m, t_string* out, va_list ap)
{
	wchar_t* arg;
	size_t   len;

	arg = (wchar_t*)ft_va_arg(ap, pointer);
	if (arg == NULL)
		arg = L"(null)";
	fta_reserve(out, 4 * ft_wstrlen(arg));
	if (m->precision >= 0)
		len = ft_wstrnconv((char*)ARRAY_END(out), arg, m->precision);
	else
		len = ft_wstrconv((char*)ARRAY_END(out), arg);
	out->size += len;
	return len;
}

int pf_cv_c(t_modifier* m, t_string* out, va_list ap)
{
	char arg;

	(void)m;
	arg = ft_va_arg(ap, char);
	string_append(out, &SUBSTR(&arg, 1));
	return 1;
}

int pf_cv_wc(t_modifier* m, t_string* out, va_list ap)
{
	wint_t arg;
	size_t ans;

	(void)m;
	arg = ft_va_arg(ap, wint_t);
	fta_reserve(out, 4);
	ans = ft_widetoa((char*)ARRAY_END(out), arg);
	out->size += ans;
	return ((int)ans);
}
