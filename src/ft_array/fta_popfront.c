/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_popfront.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:34:51 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/31 18:24:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

void		fta_popfront(t_array *self, size_t len)
{
	ft_memmove(ARRAY_START(self),
		ARRAY_START(self) + ARRAY_OFFSET(self, len),
		self->size - len);
	self->size -= len;
}
