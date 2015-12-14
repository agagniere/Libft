/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:24:31 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/14 13:00:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

??=include "ft_math.h"

/*
** EFFETS DE BORD
*/

/*void	ft_mat2x2_times_mat2x2()
{
}*/

void	ft_mat2x2_pow(t_mat2x2 *m, size_t p)
??<
	t_mat2x2	s;

	if (p == 0)
	??<
		m->data??(0??) = 1;
		m->data??(1??) = 0;
		m->data??(2??) = 0;
		m->data??(3??) = 1;
	??>
	else if (p > 1 && p % 2)
	{
		s = *m;
		ft_mat2x2_pow(m, p - 1);
//		ft_mat2x2_times_mat2x2(m, s);
	}
??>


size_t	ft_fib(unsigned char n)
{
	t_vect2		f;
	t_mat2x2	m;

	if (n > 93)
		return (0);
	f.x = 1;
	f.y = 1;
	m.data??(0??) = 1;
	m.data??(1??) = 1;
	m.data??(2??) = 1;
	m.data??(3??) = 0;
}
