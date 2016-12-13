/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:50:34 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/13 14:18:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void	fta_iter(const t_array *self, void (*f)())
{
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	while (ARRAY_HASNEXT(self, iterator))
		f(iterator);
}

void	fta_iter1(const t_array *self, void (*f)(), void *ext)
{
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	while (ARRAY_HASNEXT(self, iterator))
		f(ext, iterator);
}

void	fta_iter2(const t_array *self, void (*f)(), void *ext1, void *ext2)
{
	void		*iterator;

	iterator = ARRAY_ITERATOR(self);
	while (ARRAY_HASNEXT(self, iterator))
		f(ext1, ext2, iterator);
}
