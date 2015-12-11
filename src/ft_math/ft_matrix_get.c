/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 00:43:34 by sid               #+#    #+#             */
/*   Updated: 2015/12/11 01:45:07 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

void	*ftm_get(t_matrix *m, size_t row, size_t col)
{
	return (m->data + (row * m->width + col) * m->type_size);
}

void	*ftm_begin(t_matrix *m)
{
	return (m->data);
}

void	*ftm_end(t_matrix *m)
{
	return (m->data + m->height * m->width * m->type_size);
}
