/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fis_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 17:43:07 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/19 18:36:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"

int		fis_open(t_fis *self, char *path)
{
	return (self->fd = open(path, O_RDONLY));
}

int		fis_close(t_fis *self)
{
	return (close(self->fd));
}
