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

#include "libft.h"

void heap_push(t_heap* self, void* element)
{
	t_array* super = (t_array*)self;
	unsigned index, parent;

	index = super->size;
	fta_append(super, element, 1);
	while (index > 0)
	{
		parent = (index - 1) / 2;
		if (self->cmp(ARRAY_GET(super, parent), ARRAY_GET(super, index)) > 0)
			ft_memswp(ARRAY_GET(super, parent), ARRAY_GET(super, index), super->type_size);
		index = parent;
	}
}

bool heap_pop(t_heap* self, void* out_element)
{
	t_array*     super = (t_array*)self;
	unsigned     index, parent;
	const size_t one = super->type_size;

	if (super->size == 0)
		return false;
	if (out_element)
		ft_memcpy(out_element, ARRAY_FIRST(super), one);
	ft_memcpy(ARRAY_FIRST(super), ARRAY_LAST(super), one);
	fta_popback(super, 1);
	parent = index = 0;
	while ((index = 2 * index + 1) < super->size)
	{
		if (index + 1 < super->size && self->cmp(ARRAY_GET(super, index), ARRAY_GET(super, index + 1)) > 0)
			index++;
		if (self->cmp(ARRAY_GET(super, parent), ARRAY_GET(super, index)) > 0)
			ft_memswp(ARRAY_GET(super, parent), ARRAY_GET(super, index), one);
		else
			break;
		parent = index;
	}
	return true;
}

void heap_free(t_heap* self) { fta_clear((t_array*)self); }
