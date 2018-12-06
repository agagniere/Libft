/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:32:56 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/06 19:11:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"

void		*ftq_first(t_deque *self)
{
	return (ftq_is_empty(self) ? NULL : self->front);
}

void		*ftq_last(t_deque *self)
{
	if (ftq_is_empty(self))
		return (NULL);
	return (((self->back == ftq_begin(self)) ? ftq_end(self) : self->back)
			- ftq_offset(self, 1));
}

/*
** Number of elements stored
*/

unsigned	ftq_size(t_deque *self)
{
	return (ftq_is_split(self) ? ftq_exterior(self) : ftq_interior(self));
}

/*
** Maximum number of elements that can be stored
*/

unsigned	ftq_capacity(t_deque *self)
{
	return (self->capacity - 1);
}
