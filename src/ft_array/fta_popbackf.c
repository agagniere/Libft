/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_popback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:08:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/13 12:36:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** Array::pop_back_f
** -
** Same as pop_back, but provides a way to avoid leaks by freeing
** contents pointed by the poped element.
** -
** _del_ is a function that knows how to properly free a single element's
** contents from its address.
*/

void	fta_popbackf(t_array *self, void (*del)(void *))
{
	if (self->size > 0)
	{
		self->size--;
		del(ARRAY_END(self));
	}
}
