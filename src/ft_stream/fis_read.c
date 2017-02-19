/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fis_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:06:00 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/19 19:52:02 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"

/*
** TODO : if read fails :/
*/

int		fis_read(t_is *self, size_t n)
{
	t_fis *const	this = self;

	fta_reserve(&this->buff, n);
	this->buff.size += read(this.fd, ARRAY_END(&this->buff), n);
	return (0);
}
