/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:53:40 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/10 15:09:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		fta_append(t_array *self, void *data, size_t datalen)
{
	fta_reserve(self, datalen);
	ft_memcpy(self->data, data, self->type_size * datalen);
	return (0);
}
