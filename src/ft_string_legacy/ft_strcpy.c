/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:54:54 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/01 12:25:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

char* ft_strcpy(char* dst, const char* src)
{
	char* save;

	save = dst;
	while (*src != '\0')
		*(dst++) = *(src++);
	*dst = '\0';
	return (save);
}
