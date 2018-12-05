/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:34:04 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/05 15:09:33 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

bool	stack_push(t_stack *self, void *element)
{
	return (FTQ_PUSH_BACK_ONE(self, element));
}

bool	stack_pop(t_stack *self, void *destination)
{
	return (FTQ_POP_BACK_ONE(self, destination));
}

void	*stack_peek(t_stack *self)
{
	return (ftq_last(self));
}
