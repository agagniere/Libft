/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_private_getters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:58:47 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/05 15:55:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"

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
