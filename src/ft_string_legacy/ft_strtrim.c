/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:37:55 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 11:09:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

#include "ft_ctype.h"

char* ft_strtrim(char const* s)
{
	int start;
	int len;
	int flen;

	start = 0;
	while (ft_isspace(s[start]))
		start++;
	len  = 0;
	flen = 0;
	while (s[start + len] != '\0')
	{
		if (!ft_isspace(s[start + len]))
			flen = len + 1;
		len++;
	}
	return (ft_strsub(s, start, flen));
}
