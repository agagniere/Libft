/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 00:48:21 by sid               #+#    #+#             */
/*   Updated: 2015/12/11 17:32:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int			ftm_add(t_matrix *dst, t_matrix *a, t_matrix *b, t_op add)
{
	size_t	i;

	if (!(ftm_same_dim(a, b) && ftm_same_type(a, b)))
		return (1);
	if (!(ftm_same_dim(dst, a) && ftm_same_type(dst, a)))
		return (2);
	if (dst->data == NULL && ftm_data_init(dst))
		return (-1);
	if (add == NULL)
		return (-2);
	i = 0;
	while (i < a->width * a->height * a->type_size)
	{
		add(dst->data + i, a->data + i, b->data + i);
		i += a->type_size;
	}
	return (0);
}

t_matrix	*ftm_plus(t_matrix *a, t_matrix *b, t_op add)
{
	t_matrix *ans;

	if ((!ftm_same_dim(a, b))
		|| (!ftm_same_type(a, b))
		|| (!(ans = ftm_cpy(a)))
		|| ftm_add(ans, a, b, add))
		return (NULL);
}

int			ftmu_add_auto(t_matrix *dst, t_matrix *a, t_matrix *b)
{

	return (ftm_add(dst, a, b, ftm()));
}

t_matrix	*ftmu_plus_auto(t_matrix *a, t_matrix *b)
{
	t_matrix *ans;

	if ((!ftm_same_dim(a, b))
		|| (!ftm_same_type(a, b))
		|| (!(ans = ftm_cpy(a)))
		|| ftm_add_autou(ans, a, b))
		return (NULL);
}

int		ftm_plus_auto()
{

}
