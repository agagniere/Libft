/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_fun_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:12:41 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/11 13:46:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#define ADDFUN(type)									\
	void        sum_##type(void *d, void *a, void *b)	\
	{													\
		*(type *)d = *(type *)a + *(type *)b;			\
	}

ADDFUN(int32_t)
ADDFUN(int)
ADDFUN(short)
ADDFUN(char)

static t_op add_functions[] = {sum_char, sum_short, sum_int, sum_};

t_op	ftm_get_op(size_t type_size)
{
	;
}
