/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_private.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:58:47 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/05 16:09:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"

/*
** Is data spread on two discontinuous memory slots
*/

bool		ftq_is_split(t_deque *self)
{
	return (self->back < self->front);
}

/*
** Size in memory of _count_ elements
*/

size_t		ftq_offset(t_deque *self, unsigned count)
{
	return (self->type_size * count);
}

/*
** Number of elements in the range delimited by those two elements
** (upper bound excluded)
*/

unsigned	ftq_distance(t_deque *self, void *elem1, void *elem2)
{
	return ((elem1 < elem2 ? elem2 - elem1 : elem1 - elem2) / self->type_size);
}

/*
** Number of elements between front and back
*/

unsigned	ftq_interior(t_deque *self)
{
	return (ftq_distance(self, self->front, self->back));
}

/*
** Number of elements surrounding front and back
*/

unsigned	ftq_exterior(t_deque *self)
{
	return (self->capacity - ftq_interior(self));
}
