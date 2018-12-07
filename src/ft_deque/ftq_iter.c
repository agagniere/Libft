/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:29:32 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 18:27:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_deque_private.h"

void		ftq_iter(t_deque *self, void (*f)())
{
	const void	*ptr = ftq_front(self) - ftq_offset(self, 1);
	const int	split = ftq_is_split(self);

	while ((ptr += ftq_offset(self, 1))
			< (split ? ftq_end(self) : ftq_back(self)))
		f(ptr);
	if (split && (ptr = ftq_begin(self) - ftq_offset(self, 1)))
		while ((ptr += ftq_offset(self, 1)) < ftq_back(self))
			f(ptr);
}

void		ftq_iter1(t_deque *self, void (*f)(), void *ext)
{
	const void	*ptr = ftq_front(self) - ftq_offset(self, 1);
	const int	split = ftq_is_split(self);

	while ((ptr += ftq_offset(self, 1))
			< (split ? ftq_end(self) : ftq_back(self)))
		f(ext, ptr);
	if (split && (ptr = ftq_begin(self) - ftq_offset(self, 1)))
		while ((ptr += ftq_offset(self, 1)) < ftq_back(self))
			f(ext, ptr);
}

void		ftq_iter2(t_deque *self, void (*f)(), void *ext1, void *ext2)
{
	const void	*ptr = ftq_front(self) - ftq_offset(self, 1);
	const int	split = ftq_is_split(self);

	while ((ptr += ftq_offset(self, 1))
			< (split ? ftq_end(self) : ftq_back(self)))
		f(ext1, ext2, ptr);
	if (split && (ptr = ftq_begin(self) - ftq_offset(self, 1)))
		while ((ptr += ftq_offset(self, 1)) < ftq_back(self))
			f(ext1, ext2, ptr);
}
