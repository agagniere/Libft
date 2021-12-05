/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_popindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:34:51 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/04 18:47:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "ft_prepro.h"
#include "libft.h"

/*
** Array::pop_index
** -
** Removes at most _len_ elements starting at _index_.
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/

int fta_popindex(t_array* self, size_t index, size_t len)
{
	const size_t n = MIN(len, self->size - index);

	if (index > self->size)
		return (1);
	ft_memmove(ARRAY_GET(self, index),
	           ARRAY_GET(self, index + n),
	           ARRAY_OFFSET(self, self->size - n - index));
	self->size -= n;
	return (0);
}

/*
** Array::pop_index w/ function
** -
** Same
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single
** element's contents from its address.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/

int fta_popindexf(t_array* self, size_t index, size_t len, void (*del)(void*))
{
	const size_t n = _MIN2(len, self->size - index);
	size_t       i;

	if (index > self->size)
		return (1);
	i = index - 1;
	while (++i < index + n)
		del(ARRAY_GET(self, i));
	ft_memmove(ARRAY_GET(self, index),
	           ARRAY_GET(self, index + n),
	           ARRAY_OFFSET(self, self->size - n - index));
	self->size -= n;
	return (0);
}
