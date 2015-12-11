/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_compare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 01:11:02 by sid               #+#    #+#             */
/*   Updated: 2015/12/11 01:26:27 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int		ftm_same_dim(t_matrix *a, t_matrix *b)
{
	return ((a->height == b->height) && (a->width == b->width));
}

int		ftm_same_type(t_matrix *a, t_matrix *b)
{
	return (a->type_size == b->type_size);
}
