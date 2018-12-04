/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:39:02 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/04 15:51:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int		ft_atoi(const char *str)
{
	int		ans;
	int		sign;

	while (ft_isspace(*str))
		++str;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	ans = 0;
	while (ft_isdigit(*str))
		ans = 10 * ans + sign * (*str++ - '0');
	return (ans);
}
