/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:50:34 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/09 20:04:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_dyna_iter(t_dyna const *td, void (*f)())
{
	void			*ptr;
	void * const	end = td->data + td->chunck_count * td->chunck_size;

	ptr = td->data;
	while (ptr < end)
	{
		f(ptr);
		ptr += td->chunck_size;
	}
}

void	ft_dyna_iter1(t_dyna const *td, void (*f)(), void *ext)
{
	void			*ptr;
	void * const	end = td->data + td->chunck_count * td->chunck_size;

	ptr = td->data;
	while (ptr < end)
	{
		f(ext, ptr);
		ptr += td->chunck_size;
	}
}

void	ft_dyna_iter2(t_dyna const *td, void (*f)(), void *ext1, void *ext2)
{
	void			*ptr;
	void * const	end = td->data + td->chunck_count * td->chunck_size;

	ptr = td->data;
	while (ptr < end)
	{
		f(ext1, ext2, ptr);
		ptr += td->chunck_size;
	}
}
