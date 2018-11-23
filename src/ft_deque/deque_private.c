/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_private.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:58:47 by angagnie          #+#    #+#             */
/*   Updated: 2018/11/23 14:01:26 by angagnie         ###   ########.fr       */
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
** Pointer to the first element
*/
void		*ftq_front(t_deque *self)
{
	return (self->front);
}

/*
** Pointer to the would-be next-after-the-last element
*/
void		*ftq_back(t_deque *self)
{
	return (self->back);
}

/*
** Pointer to the start of the underlying storage
*/
void		*ftq_begin(t_deque *self)
{
	return (self->data);
}

/*
** Pointer one-past-the-end of the underlying storage
*/
void		*ftq_end(t_deque *self)
{
	return (ftq_begin(self) + ftq_offset(self, self->capacity));
}

/*
** Size in memory of _count_ elements
*/
size_t		ftq_offset(t_deque *self, unsigned count)
{
	return (self->type_size * count);
}

/*
** Number of elements in the range delimited by those two elements (upper bound excluded)
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

/*
** Returns -1 if out of bound, -2 if outside storage
*/
int			ftq_index(t_deque *self, void *element)
{
	if (element < ftq_begin(self) || ftq_end(self) <= element)
		return (-2);
	if (self->front <= element && (element < self->back || ftq_is_split(self)))
		return (ftq_distance(self, element, self->front));
	if (element < self->back && ftq_is_split(self))
		return (ftq_size(self) - ftq_distance(self, element, self->back));
	return (-1);
}

void		ftq_move_one(t_deque *self, void **pointer, bool forward)
{
	if (!forward && *pointer == ftq_begin(self))
		*pointer = ftq_end(self);
	*pointer += self->type_size * (forward ? 1 : -1);
	if (forward && *pointer == ftq_end(self))
		*pointer = ftq_begin(self);
}
