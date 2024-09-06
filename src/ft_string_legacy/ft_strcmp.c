/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:09:41 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/24 17:14:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

int ft_strcmp(const char* s1, const char* s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
