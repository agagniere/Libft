/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:23:44 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/13 20:27:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** Array::replace
** -
** replace a part of _self_ by _new_
** -
**       |---| <-len
** "echo $USER is cool"
**       |   \----\
** "echo john_smith is cool"
**       ^index
** -
** Returns a status
** 1 in case of failure (malloc)
** 0 otherwise.
*/

int fta_replace(t_array* self, size_t index, size_t len, t_array* new)
{
	return (fta_popindex(self, index, len) || fta_insert(self, new->data, new->size, index));
}
