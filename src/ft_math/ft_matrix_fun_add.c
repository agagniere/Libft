/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_fun_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:12:41 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/11 17:17:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#define ADDFUN(type)													\
	void        sum_##type(void *d, void *a, void *b)					\
	{																	\
		*(type *)d = *(type *)a + *(type *)b;							\
	}																	\
	void		sum_u##type(void *d, void *a, void *b)					\
	{																	\
		*(unsigned type)d = *(unsigned type *)a	+ *(unsigned type *)b;	\
	}																	\

ADDFUN(int);
ADDFUN(short);
ADDFUN(char);

void        sum_lint(void *d, void *a, void *b)
{
	*(long int *)d = *(long int *)a + *(long int *)b;
}

void		sum_ulint(void *d, void *a, void *b)
{
	*(size_t)d = *(size_t *)a	+ *(size_t *)b;
}

static t_op add_functions[] = {sum_char, sum_short, sum_int, sum_lint};
static t_op uadd_functions[] = {sum_uchar, sum_ushort, sum_uint, sum_ulint};

t_op	ftm_get_op(size_t type_size)
{
	int p = 0;
	int t = 1;

	while (type_size > t && p < 4)
	{
		p++;
		t *= 2;
	}
	if (type_size == t)
		return (add_functions[p]);
	return (NULL);
}

t_op	ftmu_get_op(size_t type_size)
{
	int p = 0;
	int t = 1;

	while (type_size > t && p < 4)
	{
		p++;
		t *= 2;
	}
	if (type_size == t)
		return (uadd_functions[p]);
	return (NULL);
}
