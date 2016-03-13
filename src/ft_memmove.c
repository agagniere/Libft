/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:14:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/13 11:23:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *const save = dst;

	if (dst > src)
		while (len-- > 0)
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
	else if (dst < src)
		while (len-- > 0)
			*((unsigned char *)dst++) = *((unsigned char *)src++);
	return (save);
}
