/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:32:56 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/06 19:12:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"
#include "ft_prepro.h"
#include "libft.h"

bool		ftq_push_one(t_deque *self, void *element, bool front)
{
	if (ftq_is_full(self))
		return (false);
	if (front)
		FTQ_MOVE_BACKWARD_ONE(self, self->front);
	ft_memcpy(front ? self->front : self->back, element, ftq_offset(self, 1));
	if (!front)
		FTQ_MOVE_FORWARD_ONE(self, self->back);
	return (true);
}

bool		ftq_push_front(t_deque *self, void *elements, unsigned count)
{
	if (ftq_capacity(self) < ftq_size(self) + count)
		return (false);
	while (count-- > 0)
	{
		FTQ_PUSH_FRONT_ONE(self, elements);
		elements += ftq_offset(self, 1);
	}
	return (true);
}

bool		ftq_push_back(t_deque *self, void *elements, unsigned count)
{
	unsigned		first;

	if (ftq_capacity(self) < ftq_size(self) + count)
		return (false);
	first = MIN(count, ftq_distance(self, ftq_end(self), self->back));
	ft_memcpy(self->back, elements, ftq_offset(self, first));
	self->back += ftq_offset(self, first);
	if (self->back == ftq_end(self))
	{
		self->back = ftq_begin(self);
		ftq_push_back(self, elements + ftq_offset(self, first), count - first);
	}
	return (true);
}
