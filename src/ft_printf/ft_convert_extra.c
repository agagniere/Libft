/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:41:29 by angagnie          #+#    #+#             */
/*   Updated: 2017/09/22 21:56:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int pf_cv_n(t_modifier* m, t_string* out, va_list ap)
{
	int* arg;

	arg          = va_arg(ap, void*);
	m->size      = 0;
	m->precision = -1;
	if (m->length == 'H')
		*(char*)arg = (char)out->size;
	else if (m->length == 'h')
		*(short*)arg = (short)out->size;
	else if (m->length == 'l' || m->length == 'z')
		*(long*)arg = (long)out->size;
	else if (m->length == 'L')
		*(long long*)arg = (long long)out->size;
	else if (m->length == 'j')
		*(intmax_t*)arg = (intmax_t)out->size;
	else
		*(int*)arg = (int)out->size;
	return (0);
}
