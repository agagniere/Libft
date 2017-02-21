/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fis_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:06:00 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/21 20:04:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"

/*
** TODO : if read fails :/
*/

int		fis_read(t_is *self, size_t n)
{
	t_fis *const	this = (t_fis *)self;
	int				ret;

	fta_reserve(&this->buff, n);
	ret = read(this->fd, ARRAY_END(&this->buff), n);
	if (ret == -1)
		return (1);
	this->buff.size += ret;
	return (0);
}
