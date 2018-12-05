/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_private_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:58:47 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/05 16:08:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"

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
