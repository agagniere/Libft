/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_popback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:08:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/13 12:36:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** Array::pop_back
** -
** If the array isn't empty, its last element is removed.
*/

void	fta_popback(t_array *self)
{
	if (self->size > 0)
		self->size--;
}
