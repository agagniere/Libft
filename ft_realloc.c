/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:12:27 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 13:19:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size, size_t factor)
{
	void	*ans;

	ans = malloc(new_size * factor);
	if (ptr == NULL || ans == NULL)
		return (ans);
	if (new_size < old_size)
		old_size = new_size;
	ft_memcpy(ans, ptr, old_size * factor);
	free(ptr);
	return (ans);
}
