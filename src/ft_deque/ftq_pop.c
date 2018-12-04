/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:32:56 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/04 19:11:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"
#include "ft_prepro.h"
#include "libft.h"

bool		ftq_pop_one(t_deque *self, void *destination, bool front)
{
	if (ftq_is_empty(self))
		return (false);
	if (!front)
		FTQ_MOVE_BACKWARD_ONE(self, self->back);
	if (destination)
		ft_memcpy(destination,
				(front ? self->front : self->back),
				ftq_offset(self, 1));
	if (front)
		FTQ_MOVE_FORWARD_ONE(self, self->front);
	return (true);
}

bool		ftq_pop_front(t_deque *self, void *destination, unsigned count)
{
	unsigned		first;

	if (ftq_size(self) < count)
		return (false);
	first = MIN(count, ftq_distance(self, ftq_end(self), self->front));
	ft_memcpy(destination, self->front, ftq_offset(self, first));
	self->front += ftq_offset(self, first);
	if (self->front == ftq_end(self))
	{
		self->front = ftq_begin(self);
		ftq_pop_front(self,
					(destination + ftq_offset(self, first)),
					count - first);
	}
	return (true);
}
