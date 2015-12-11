/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 19:41:57 by sid               #+#    #+#             */
/*   Updated: 2015/12/11 12:47:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_matrix	ftm_new(size_t type_size, size_t height, size_t width)
{
	return ((t_matrix){type_size, height, width, NULL});
}

t_matrix	*ftm_alloc(size_t type_size, size_t height, size_t width)
{
	t_matrix	*ans;

	if (!(ans = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	ans->type_size = type_size;
	ans->height = height;
	ans->width = width;
	ans->data = NULL;
	return (ans);
}

int			ftm_data_init(t_matrix *m)
{
	return ((m->data = malloc(m->height * m->width * m->type_size)) == NULL);
}

t_matrix	*ftm_cpy(t_matrix *m)
{
	return (ftm_alloc(m->type_size, m->height, m->width));
}
