/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/09 15:11:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>

# define ARRAY_INITIAL_SIZE 8
# define ARRAY_FACTOR 2

typedef struct	s_array
{
	void		*data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_array;

#define NEW_ARRAY(T) (t_array){NULL, 0, 0, sizeof(T)}

t_array			*fta_alloc(size_t type_size);
int				fta_append(t_array *td, void *data, size_t datalen);
void			fta_dataclear(t_array *t);
void			fta_dataclearf(t_array *t, void (*del)(void *));
int				fta_datainit(t_array *td);
void			fta_del(t_array *td);
void			fta_release(t_array **tda);
t_array			fta_new(size_t chunck_size);
int				fta_trim(t_array *td);
int				fta_reserve(t_array *td, size_t size);
void			fta_popback(t_array *td);
void			fta_popbackf(t_array *td, void (*del)(void *));
void			*fta_get(t_array *td, size_t i);

void			fta_iter(t_array const *td, void (*f)());
void			fta_iter1(t_array const *td, void (*f)(), void *a);
void			fta_iter2(t_array const *td, void (*f)(), void *a, void *b);
void			fta_iteri(t_array const *td, void (*f)());
void			fta_iteri1(t_array const *td, void (*f)(), void *a);
void			fta_iteri2(t_array const *td, void (*f)(), void *a, void *b);

#endif
