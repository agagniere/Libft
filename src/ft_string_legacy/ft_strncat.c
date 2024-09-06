/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:12:37 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 14:29:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

char* ft_strncat(char* s1, const char* s2, size_t n)
{
	char* const save = s1;

	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0' && n-- > 0)
		*s1++ = *s2++;
	*s1 = '\0';
	return (save);
}
