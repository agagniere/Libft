/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:32:05 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/15 10:06:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"

/*
** StringInputStream::refresh
** -
** returns FALSE if the string has been read entirely.
*/

int		sis_refresh(t_is *self)
{
	t_sis *const	this = (t_sis *)self;

	if (self->buff_i >= this->ptr->size)
		return (0);
	self->buff = this->ptr->data;
	self->buff_len = this->ptr->size;
	return (1);
}

int		fis_refresh(t_is *self)
{
	t_fis *const	this = (t_fis *)self;

	if (!self->buff
		&& !(FIS_BUFFER(self) = malloc(FIS_BUFF_SIZE * sizeof(char))))
		return (0);
	self->buff_len = read(fd, FIS_BUFFER(self), FIS_BUFF_SIZE);
	return (1);
}
