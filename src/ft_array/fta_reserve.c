/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_reserve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:10:30 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/10 15:15:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fta_reserve(t_array *self, size_t size)
{
	const size_t	total_size = size + self->size;
	size_t			new_size;
	void			*tmp;

	if (total_size > self->max)
	{
		new_size = (self->max > 0 ? self->max : FT_ARRAY_INIT_SIZE);
		while (new_size < total_size)
			new_size *= FT_ARRAY_FACTOR;
		tmp = malloc(new_size * self->type_size);
		if (tmp == NULL)
			return (1);
		ft_memcpy(tmp, );
		free(self->data);
		self->data = tmp;
		self->max += size;
	}
	return (0);
}
