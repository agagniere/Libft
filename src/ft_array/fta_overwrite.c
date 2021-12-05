/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_overwrite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:06:01 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/27 19:17:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** Array::overwrite
** -
** Replaces _self_'s contents with _other_'s.
** -
** Will fail, leaving _self_ untouched,
** if the two array's aren't compatible.
** (i.e. if the two types do not have the same lenght)
** -
** Returns a status :
** 0 upon success
** 1 otherwise.
*/

int fta_overwrite(t_array* self, const t_array* other)
{
	if (self->type_size != other->type_size)
		return (1);
	self->size = 0;
	return (fta_reserve(self, other->size) ||
	        fta_append(self, other->data, other->size));
}
