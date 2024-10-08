/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:26:25 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 14:27:39 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

void ft_striteri(char* s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	while (*s != '\0')
		f(i++, s++);
}
