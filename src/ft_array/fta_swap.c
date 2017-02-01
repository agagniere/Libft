/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:06:01 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/31 18:20:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

void	fta_swap(t_array *self, size_t before, size_t after)
{
	char			*tmp;
	const size_t	len = after - before;
	const size_t	m = self->type_size;

	tmp = ft_safe_calloc(len, m);
	ft_memcpy(tmp, self->data + before * m, m * len);
	ft_memmove(self->data + before * m, self->data + after * m,
		(self->size - after) * m);
	ft_memcpy(self->data + (self->size - len) * m, tmp, len * m);
	free(tmp);
}
