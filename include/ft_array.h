/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/10 15:19:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>

/*
** The following functions allows one to manipulate a collection of objects,
** not bothering about malloc.
** It is inspired by the C++ "Vector"
** -
** In C++ and Java, one would declare such an object with
** the template/generics syntax :
** |	Vector<SomeType> variable = new Vector<SomeType>();
** Here in C, one must create a custom type, that "extends" t_array :
** |typedef struct		s_some_type
** |{
** |	t_array		super;	// it's a t_array
** |	type1		var1;	// with additional information
** |	. . .		. . .
** |	typen		varn;
** |}					t_some_type;
** And then :
** |	t_array	variable = NEW_ARRAY(t_some_type);
*/

typedef struct	s_array
{
	void		*data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_array;

/*
** Failsafe constructor,
** no memory is allocated.
*/

# define NEW_ARRAY(T) (t_array){NULL, 0, 0, sizeof(T)}

/*
** Array::alloc
** -
** Allocates an array and its data.
** -
** _type_size_ should equal to the returned value of sizeof(t_some_type)
** -
** Returns the allocated array,
** or NULL if malloc failed.
*/

t_array			*fta_alloc(size_t type_size);

/*
** Array::apppend
** -
** could be called addAll like in Java
** adds _datalen_ elements to _self_
** May fail if malloc does.
** -
** _data_ should be variable of type T* casted to void *
** _datalen_ should be the number of elements stored in _data_
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed
*/

int				fta_append(t_array *self, void *data, size_t datalen);

/*
** Array::reserve
** -
** When an estimation of the number of elements that on will add to the array,
** using reserve will prevent multiple re-allocations, ensuring
** the best complexity.
** -
** -
** Returns a status :
** 0 in case of success,
** 1 if a re-alloc failed, and leaves the array as-is.
*/

int				fta_reserve(t_array *self, size_t size);

void			fta_dataclear(t_array *t);
void			fta_dataclearf(t_array *t, void (*del)(void *));
int				fta_datainit(t_array *td);
void			fta_del(t_array *td);
void			fta_release(t_array **tda);
t_array			fta_new(size_t chunck_size);
int				fta_trim(t_array *td);
void			fta_popback(t_array *td);
void			fta_popbackf(t_array *td, void (*del)(void *));
void			*fta_get(t_array *td, size_t i);

void			fta_iter(t_array const *td, void (*f)());
void			fta_iter1(t_array const *td, void (*f)(), void *a);
void			fta_iter2(t_array const *td, void (*f)(), void *a, void *b);
void			fta_iteri(t_array const *td, void (*f)());
void			fta_iteri1(t_array const *td, void (*f)(), void *a);
void			fta_iteri2(t_array const *td, void (*f)(), void *a, void *b);

/*
** |		----------===== private: =====----------
*/

/*
** Array::_resize
** No subtlety, just resizes the underlying array, no matter the consequences.
*/

/*
** The initial size is the number of elements a new array will be able
** to store before allocating more memory.
*/

# define FT_ARRAY_INITIAL_SIZE 16

/*
** When reaching its capacity, an array will re-allocate memory,
** using this factor to grow relatively to its previous size.
*/

# define FT_ARRAY_FACTOR 2

#endif
