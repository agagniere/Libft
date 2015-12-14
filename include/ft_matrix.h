/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:41:58 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/14 12:42:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

typedef struct		s_vectf2
{
	float			x;
	float			y;
}					t_vectf2;

typedef struct		s_vecti2
{
	int				x;
	int				y;
}					t_vecti2;

typedef struct		s_vect2
{
	size_t			x;
	size_t			y;
}					t_vect2;

typedef struct		s_mat2x2
{
	size_t			data[4];
}					t_mat2x2;

#endif
