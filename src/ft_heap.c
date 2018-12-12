/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:09:08 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/12 20:16:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_heap.h"

#include <stdbool.h>

bool	heap_push(t_heap *self, void *element)
{
	t_array *const	super = self;
	unsigned		index;

	index = super->size;
	fta_append(super, element, 1);
	while (index > 0 && self->cmp(ARRAY_GET(super, index), element) > 0)
	{
		;
	}
}

void	heap_pop(t_heap *self, void *out_element)
{
	t_array *const	super = self;
	unsigned		index;
	const size_t	one = super->type_size;

	ft_memcpy(out_element, ARRAY_START(super), one);
	ft_memcpy(super->data, ARRAY_END(super) - one, one);
	fta_popback(super, 1);
	index = 0;
	while ((index = 2 * index + 1) < super->size)
	{
		if (index + 1 < super->size
			&& self->cmp(ARRAY_GET(super, index + 1),
						 ARRAY_GET(super, index)) > 0)
			index++;
		if (self->cmp(ARRAY_GET(super, index),
					  ARRAY_GET(super, (index - 1) / 2)) > 0)
			ft_memswp(ARRAY_GET(super, index),
					  ARRAY_GET(super, (index - 1) / 2));
		else
			break ;
	}
}
