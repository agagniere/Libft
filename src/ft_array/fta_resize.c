/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:08:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/10 20:20:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		fta_resize(t_array *self, size_t new_size)
{
	void	*tmp;

	tmp = malloc(new_size * self->type_size);
	if (tmp == NULL)
		return (1);
	if (self->size > new_size)
		self->size = new_size;
	ft_memcpy(tmp, self->data, self->size * self->type_size);
	free(self->data);
	self->data = tmp;
	self->max = new_size;
	return (0);
}
