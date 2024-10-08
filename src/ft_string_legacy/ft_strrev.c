/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:37:27 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/27 18:26:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

void ft_strrev(char* start, char* end)
{
	char tmp;

	while (start < --end)
	{
		tmp      = *start;
		*start++ = *end;
		*end     = tmp;
	}
}
