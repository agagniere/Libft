/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_clearf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:46:25 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/31 16:39:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include <stdlib.h>

/*
** Array::clearf
** -
** Same as Array::clear, but uses a custom function on each element before
** free the underlying array,
** useful when your structures contains addresses of allocated variables
** to be freed to prevent leaks.
** -
** _del_ is a function that knows how to properly free a single element's
** contents from its address.
*/

void	fta_clearf(t_array *self, void (*del)(void *))
{
	void	*iterator;

	if (self->max > 0)
	{
		iterator = ARRAY_ITERATOR(self);
		while (ARRAY_HASNEXT(self, iterator))
			del(iterator);
		free(self->data);
		self->size = 0;
		self->max = 0;
	}
}
