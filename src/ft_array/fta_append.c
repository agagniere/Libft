/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:53:40 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/12 21:07:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

/*
** Array::apppend
** -
** Could be called "add all" like in Java.
** Adds _datalen_ elements to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _datalen_ should be the number of elements stored in _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int		fta_append(t_array *self, void *data, size_t datalen)
{
	if (fta_reserve(self, datalen))
		return (1);
	ft_memcpy(self->data, data, self->type_size * datalen);
	return (0);
}
