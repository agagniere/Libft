/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_clearf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:46:25 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/13 09:18:11 by angagnie         ###   ########.fr       */
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
		iterator = ARRAY_START(self);
		while (iterator < ARRAY_END(self))
		{
			del(iterator);
			iterator += ARRAY_STEP(self);
		}
		free(self->data);
		self->size = 0;
		self->max = 0;
	}
}
