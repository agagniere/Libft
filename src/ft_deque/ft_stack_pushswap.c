/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pushswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:32:49 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/05 15:47:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_stack.h"
#include "ft_deque_private.h"
#include "libft.h"

bool	stack_swap(t_stack *self)
{
	void		*penu;
	void		*last;
	void		*temp;

	if (ftq_size(self) < 2)
		return (false);
	temp = ftq_back(self);
	last = stack_peek(self);
	penu = last;
	FTQ_MOVE_BACKWARD_ONE(self, penu);
	ft_memmove(temp, last, self->type_size);
	ft_memmove(last, penu, self->type_size);
	ft_memmove(penu, temp, self->type_size);
	return (true);
}

bool	stack_rotate(t_stack *self)
{
	if (ftq_size(self) < 2)
		return (false);
	stack_pop(self, NULL);
	FTQ_PUSH_FRONT_ONE(self, ftq_back(self));
	return (true);
}

bool	stack_rotate_reverse(t_stack *self)
{
	void	*temp;

	if (ftq_size(self) < 2)
		return (false);
	temp = ftq_first(self);
	FTQ_POP_FRONT_ONE(self, NULL);
	stack_push(self, temp);
	return (true);
}
