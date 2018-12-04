/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:32:56 by angagnie          #+#    #+#             */
/*   Updated: 2018/11/23 18:44:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"
#include "libft.h"

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
	if (intent == 'B')
		self->front = ftq_begin(self);
	else if (intent == 'b')
		self->front = ftq_begin(self) + ftq_offset(self, self->capacity / 4);
	else if (intent == '2')
		self->front = ftq_begin(self) + ftq_offset(self, self->capacity / 2);
	else if (intent == 'f')
		self->front = ftq_end(self) - ftq_offset(self, self->capacity / 4);
	else if (intent == 'F')
		self->front = ftq_end(self) - ftq_offset(self, 1);
	else
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
