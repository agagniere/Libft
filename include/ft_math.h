/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:02:16 by sid               #+#    #+#             */
/*   Updated: 2015/12/10 19:47:53 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

#include <stddef.h>

typedef struct		s_matrix
{
	size_t			type_size;
	size_t			height;
	size_t			width;
	void			*data;
}					t_matrix;

#endif
