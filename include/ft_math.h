/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:02:16 by sid               #+#    #+#             */
/*   Updated: 2015/12/11 17:30:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stddef.h>
# include <stdlib.h>

typedef struct		s_matrix
{
	size_t			type_size;
	size_t			height;
	size_t			width;
	void			*data;
}					t_matrix;

typedef void		(*t_op)(void *, void *, void *);

/*
** ----------===== Constructors =====----------
** |
** | N.B. : When created, a matrix doesn't have a data allocated.
** |		It must be done with ftm_data_init if necessary.
** |
** > ftm_new :			Returns a matrix to be stored on the stack.
** > ftm_alloc :		Allocates a matrix with malloc.
** > ftm_cpy :			Allocates a matrix with the same dimension and type size
** |						as the parameter.
** > ftm_data_init :	Allocates the matrix' data.
*/

t_matrix			ftm_new(size_t type_size, size_t height, size_t width);
t_matrix			*ftm_alloc(size_t type_size, size_t height, size_t width);
t_matrix			*ftm_cpy(t_matrix *m);
int					ftm_data_init(t_matrix *m);

/*
** ----------===== Addition =====----------
** |
** -> the plus functions return an allocated matrix containing the result
** |	or NULL if anything goes wrong
** |
** -> the add functions store the result in the dst matrix
** |	or	-2 if the given function address is NULL
** |		-1 if the allocation fails
** |		1 if the given matrices may not be added
** |		2 if the dst matrix has wrong dimensions
** |
** | That's why you should use add functions.
** |
** |	----------==========----------
** |
** -> the standard add and plus functions require a function pointer
*/

t_matrix			*ftm_plus(t_matrix *a, t_matrix *b, t_op add);
int					ftm_add(t_matrix *dst, t_matrix *a, t_matrix *b, t_op add);

void				*ftm_get(t_matrix *m, size_t row, size_t col);
void				*ftm_begin(t_matrix *m);
void				*ftm_end(t_matrix *m);
t_matrix			*ftm_alloc(size_t type_size, size_t height, size_t width);

#endif
