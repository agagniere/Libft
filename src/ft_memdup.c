/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:07:15 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/02 21:56:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(void const *addr, size_t len)
{
	void *ans;

	if ((ans = malloc(len)))
		ft_memcpy(ans, addr, len);
	return (ans);
}
