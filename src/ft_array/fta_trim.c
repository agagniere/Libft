/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:17:19 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/18 17:08:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** Array::trim
** -
** Could be called "shrink to fit" as it is in C++.
** This function is meant to be called when no more
** elements are expected to be appended to the array.
** Usually there are extra bytes allocated, to ensure
** a low complexity and few system calls, but this
** functions allocates the minimum number of bytes for
** all elements to fit.
** -
** Returns :
** 0 if the malloc succeeded,
** 1 otherwise.
*/

int		fta_trim(t_array *self)
{
	if (self->size < self->max)
		return (fta_resize(self, self->size));
	return (0);
}
