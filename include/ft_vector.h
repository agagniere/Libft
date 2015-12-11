/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/11 15:31:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

# define DYNA_INITIAL_SIZE 8
# define DYNA_FACTOR 2

typedef struct	s_dyna
{
	void		*data;
	size_t		chunck_count;
	size_t		chunck_max;
	size_t		chunck_size;
}				t_dyna;

t_dyna			*ft_dyna_alloc(size_t chunck_size);
int				ft_dyna_append(t_dyna *td, void *data, size_t datalen);
void			ft_dyna_dataclear(t_dyna *t);
void			ft_dyna_dataclearf(t_dyna *t, void (*del)(void *));
int				ft_dyna_datainit(t_dyna *td);
void			ft_dyna_del(t_dyna *td);
void			ft_dyna_release(t_dyna **tda);
t_dyna			ft_dyna_new(size_t chunck_size);
int				ft_dyna_trim(t_dyna *td);
int				ft_dyna_reserve(t_dyna *td, size_t size);
void			ft_dyna_popback(t_dyna *td);
void			ft_dyna_popbackf(t_dyna *td, void (*del)(void *));

void			ft_dyna_iter(t_dyna const *td, void (*f)());
void			ft_dyna_iter1(t_dyna const *td, void (*f)(), void *a);
void			ft_dyna_iter2(t_dyna const *td, void (*f)(), void *a, void *b);
void			ft_dyna_iteri(t_dyna const *td, void (*f)());
void			ft_dyna_iteri1(t_dyna const *td, void (*f)(), void *a);
void			ft_dyna_iteri2(t_dyna const *td, void (*f)(), void *a, void *b);

#endif
