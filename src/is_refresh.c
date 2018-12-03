/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:32:05 by angagnie          #+#    #+#             */
/*   Updated: 2017/05/05 20:38:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"
#include <stdlib.h>

/*
** StringInputStream::refresh
** -
** returns 1 if the string has been read entirely.
*/

int		sis_refresh(t_is *self)
{
	t_sis *const	this = (t_sis *)self;

	if ((this->ptr->size == self->buff_len)
		&& (self->buff_i >= this->ptr->size))
		return (1);
	self->buff = (char const *)this->ptr->data;
	self->buff_len = this->ptr->size;
	return (0);
}

int		fis_refresh(t_is *self)
{
	t_fis *const	this = (t_fis *)self;

	if (!(self->buff || (self->buff_i = 0)
		|| (self->buff = (char const *)malloc(FIS_BUFF_SIZE))))
		return (1);
	self->buff_len = read(this->fd, FIS_BUFFER(self), FIS_BUFF_SIZE);
	return (0);
}
