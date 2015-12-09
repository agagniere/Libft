/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_iteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:06:35 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/09 20:08:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_dyna_iteri(t_dyna const *td, void (*f)())
{
	void			*ptr;
	void * const	end = td->data + td->chunck_count * td->chunck_size;
	int				i;

	ptr = td->data;
	i = 0;
	while (ptr < end)
	{
		f(ptr, i++);
		ptr += td->chunck_size;
	}
}

void	ft_dyna_iteri1(t_dyna const *td, void (*f)(), void *ext)
{
	void			*ptr;
	void * const	end = td->data + td->chunck_count * td->chunck_size;
	int				i;

	ptr = td->data;
	i = 0;
	while (ptr < end)
	{
		f(ext, ptr, i++);
		ptr += td->chunck_size;
	}
}

void	ft_dyna_iteri2(t_dyna const *td, void (*f)(), void *ext1, void *ext2)
{
	void			*ptr;
	void * const	end = td->data + td->chunck_count * td->chunck_size;
	int				i;

	ptr = td->data;
	i = 0;
	while (ptr < end)
	{
		f(ext1, ext2, ptr, i++);
		ptr += td->chunck_size;
	}
}
