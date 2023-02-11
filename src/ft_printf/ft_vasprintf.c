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

#include "ft_printf_private.h"

int ft_vasprintf(char** ret, char const* format, va_list ap)
{
	t_string string = NEW_STRING;

	ft_string_vprintf(&string, format, ap);
	string_append(&string, &SUBSTR("\0", 1));
	fta_trim(&string);
	*ret = string.data;
	return (string.size - 1);
}
