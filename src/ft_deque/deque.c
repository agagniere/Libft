/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:32:56 by angagnie          #+#    #+#             */
/*   Updated: 2018/11/23 13:44:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "deque_private.h"

#include <string.h>

#ifndef MIN
# define MIN(A,B) (A < B ? A : B)
#endif

/*
** Returns an initialized t_deque that uses the specified storage
*/
t_deque		ftq_new(void *data, size_t type_size, unsigned capacity)
{
	return ((t_deque){data, data, data, type_size, capacity});
}

/*
** Before pushing any element, we can clarify our intentions to lower the chances of splitting data
** 'B' : will only push back
** 'b' : will mostly push back
** '2' : will push on both side
** 'f' : will mostly push front
** 'F' : will only push front
*/
bool		ftq_intent(t_deque *self, char intent)
{
	if (!ftq_is_empty(self))
		return (false);
	switch (intent)
	{
	case 'B' :
		self->front = ftq_begin(self);
		break;
	case 'b' :
		self->front = ftq_begin(self) + ftq_offset(self, self->capacity / 4);
		break;
	case '2' :
		self->front = ftq_begin(self) + ftq_offset(self, self->capacity / 2);
		break;
	case 'f' :
		self->front = ftq_end(self) - ftq_offset(self, self->capacity / 4);
		break;
	case 'F' :
		self->front = ftq_end(self) - ftq_offset(self, 1);
		break;
	default :
		return (false);
	}
	self->back = self->front;
	return (true);
}

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
unsigned	ftq_max(t_deque *self)
{
	return (self->capacity - 1);
}

bool		ftq_is_empty(t_deque *self)
{
	return (self->front == self->back);
}

bool		ftq_is_full(t_deque *self)
{
	return (ftq_size(self) == ftq_max(self));
}

bool		ftq_push_one(t_deque *self, void *element, bool front)
{
	if (ftq_is_full(self))
		return (false);
	if (front)
		ftq_move_backward_one(self, self->front);
	memcpy(front ? self->front : self->back, element, ftq_offset(self, 1));
	if (!front)
		ftq_move_forward_one(self, self->back);
	return (true);
}

bool		ftq_push_front(t_deque *self, void *elements, unsigned count)
{
	if (ftq_max(self) < ftq_size(self) + count)
		return (false);
	while (count-- > 0)
	{
		ftq_push_front_one(self, elements);
		elements += ftq_offset(self, 1);
	}
	return (true);
}

bool		ftq_push_back(t_deque *self, void *elements, unsigned count)
{
	unsigned		first;

	if (ftq_max(self) < ftq_size(self) + count)
		return (false);
	first = MIN(count, ftq_distance(self, ftq_end(self), self->back));
	memcpy(self->back, elements, ftq_offset(self, first));
	self->back += ftq_offset(self, first);
	if (self->back == ftq_end(self))
	{
		self->back = ftq_begin(self);
		ftq_push_back(self, elements + ftq_offset(self, first), count - first);
	}
	return (true);
}

bool		ftq_pop_one(t_deque *self, void *destination, bool front)
{
	if (ftq_is_empty(self))
		return (false);
	if (!front)
		ftq_move_backward_one(self, self->back);
	memcpy(destination, front ? self->front : self->back, ftq_offset(self, 1));
	if (front)
		ftq_move_forward_one(self, self->front);
	return (true);
}

bool		ftq_pop_front(t_deque *self, void *destination, unsigned count)
{
	unsigned		first;

	if (ftq_size(self) < count)
		return (false);
	first = MIN(count, ftq_distance(self, ftq_end(self), self->front));
	memcpy(destination, self->front, ftq_offset(self, first));
	self->front += ftq_offset(self, first);
	if (self->front == ftq_end(self))
	{
		self->front = ftq_begin(self);
		ftq_pop_front(self, destination + ftq_offset(self, first), count - first);
	}
	return (true);
}
