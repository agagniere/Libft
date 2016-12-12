/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/12 21:27:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>

/*
** |		----------=====  Array<T>  =====----------
** The following functions allows one to manipulate a collection of objects,
** not bothering about malloc.
** It is inspired by the C++ "Vector<T>"
** -
** In C++ and Java, one would declare such an object with
** the template/generics syntax :
** |	Vector<SomeType> variable = new Vector<SomeType>();
** -
** Here in C, one must create a custom type, that "extends" t_array :
** |	typedef struct		s_some_type
** |	{
** |		t_array		super;	// it's a t_array
** |		type1		var1;	// with additional information
** |		. . .		. . .
** |		typen		varn;
** |	}					t_some_type;
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
** |		----------===== public: =====----------
*/

/*
** Array::new
** -
** Failsafe constructor, no memory is allocated.
** -
** _T_ should be the type to be stored in the array.
** -
** returns an array, correctly initialised.
*/

# define NEW_ARRAY(T) (t_array){NULL, 0, 0, sizeof(T)}

/*
** Array::new
** -
** Constructor that tries a first malloc.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
*/

t_array			fta_new(size_t type_size);

/*
** Array::alloc
** -
** Allocates an array and its data.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
** Returns the allocated array,
** or NULL if malloc failed.
*/

t_array			*fta_alloc(size_t type_size);

/*
** Array::apppend
** -
** Could be called "add all" like in Java.
** Adds _datalen_ elements to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _datalen_ should be the number of elements stored in _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int				fta_append(t_array *self, void *data, size_t datalen);

/*
** Array::reserve
** -
** When one has an estimation of the number of elements that they will add
** to the array, using reserve will prevent multiple re-allocations,
** and ensure the best complexity.
** Indeed this function makes sure that the array has enough room
** for _size_ elements to be added.
** -
** _size_ is the number of elements that are planned to be added.
** -
** Returns a status :
** 0 in case of success,
** 1 if a re-alloc failed, and leaves the array as-is.
*/

int				fta_reserve(t_array *self, size_t size);

/*
** Array::trim
** -
** Could be called "shrink to fit" as it is in C++.
** This function is meant to be called when no more
** elements are expected to be appended to the array.
** Usually there are extra bytes allocated, to ensure
** a low complexity and few system calls, but this
** functions allocates the minimum number of bytes for
** all elements to fit.
** -
** Returns :
** 0 if the malloc succeeded,
** 1 otherwise.
*/

int				fta_trim(t_array *self);

/*
** Array::clear
** -
** Frees the underlying data, but leaves the array usable :
** one might still call the append function, the array was only
** emptied.
*/

void			fta_clear(t_array *self);

/*
** Array::clearf
** -
** Same as Array::clear, but uses a custom function instead of free,
** useful when your structures contains addresses of allocated variables
** to be freed to prevent leaks.
** -
** _del_ is a function that knows how to properly free a single element
** from its address.
*/

void			fta_clearf(t_array *t, void (*del)(void *));

void			fta_del(t_array *td);
void			fta_release(t_array **tda);
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
** Iterator<Array>::Start
** -
** Returns the start of the array.
*/

# define ARRAY_START(A) ((A)->data)

/*
** Iterator<Array>::End
** -
** Returns the end end of the array
*/

# define ARRAY_END(A) ((A)->data + (A)->size * (A)->type_size)

/*
** Iterator<Array>::Step
** -
** Allows one to go from the address of an element to an other.
*/

# define ARRAY_STEP(A) ((A)->type_size)

/*
** |		----------===== private: =====----------
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

/*
** Array::_resize
** No subtlety, just resizes the underlying array, no matter the consequences.
** However, in case of a malloc fail, the array is left untouched.
*/

int				fta_resize(t_array *self, size_t new_size);

#endif
