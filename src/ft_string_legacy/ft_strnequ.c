/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:39:24 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 16:48:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

int ft_strnequ(char const* s1, char const* s2, size_t n)
{
	return (!ft_strncmp(s1, s2, n));
}
