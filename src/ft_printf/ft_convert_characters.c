/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:37:44 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/04 18:04:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prepro/tools.h"
#include "ft_printf_private.h"
#include "ft_wchar.h"

#include <wchar.h>

int pf_cv_s(t_modifier* m, t_string* out, va_list ap)
{
	char* arg;
	int   ans;

	arg = va_arg(ap, char*);
	if (arg == NULL)
		arg = "(null)";
	ans = (m->precision >= 0 ? MIN(ft_strlen(arg), (size_t)m->precision) : ft_strlen(arg));
	string_append(out, &SUBSTR(arg, ans));
	return ans;
}

int pf_cv_ws(t_modifier* m, t_string* out, va_list ap)
{
	wchar_t* arg;
	size_t   len;

	arg = va_arg(ap, wchar_t*);
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
	arg = (char)va_arg(ap, int);
	string_append(out, &SUBSTR(&arg, 1));
	return 1;
}

int pf_cv_wc(t_modifier* m, t_string* out, va_list ap)
{
	wint_t arg;
	size_t ans;

	(void)m;
	arg = va_arg(ap, wint_t);
	fta_reserve(out, 4);
	ans = ft_widetoa((char*)ARRAY_END(out), arg);
	out->size += ans;
	return ((int)ans);
}
