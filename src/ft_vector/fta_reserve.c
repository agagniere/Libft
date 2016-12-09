/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_reserve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:10:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/09 16:08:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fta_reserve(t_array *self, size_t size)
{
	size_t m;

	m = self->max;
	if (m == 0)
		m = ARRAY_INIT_SIZE
	if (size + self->size > self->max)
	{
		while ()
		self->data = ft_realloc(self->data, self->size, self->size + size,
			self->type_size);
		td->max += size;
	}
	return (0);
}
