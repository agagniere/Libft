/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 02:55:15 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/13 17:27:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"

#include <stdarg.h>
#include <stdlib.h>

/*
** String::toChar*
** -
** Handy function to use a String as a char*
*/

char* cstring(t_string* str)
{
	STRING_NULL_TERMINATE(str);
	return ((char*)str->data);
}

/**
** Append a string formed in a similar manner as printf.
*/
int string_append_format(t_string* self, const char* format, ...)
{
	va_list  arguments;
	t_substr buffer;

	va_start(arguments, format);
	buffer.length = ft_vasprintf(&buffer.string, format, arguments);
	va_end(arguments);
	string_append(self, &buffer);
	free(buffer.string);
	return buffer.length;
}
