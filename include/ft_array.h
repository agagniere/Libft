/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/30 17:50:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

/*
** |		----------=====  Array<T>  =====----------
** The following functions allows one to manipulate a collection of objects,
** not bothering about malloc.
** It is inspired by the C++ "std::vector<T>"
** -
** In Java, one would declare such an object with :
** |	Vector variable = new Vector<SomeType>();
** |	ArrayList variable = new ArrayList<SomeType>();
** In C++ it would be :
** |	std::vector<some_type> variable();
** -
** Here in C,
** |	t_array	variable = NEW_ARRAY(t_some_type);
*/

typedef struct s_array
{
	void*  data;
	size_t size;
	size_t capacity;
	size_t type_size;
} t_array;

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
** Returns an array, correctly initialised.
*/
#define NEW_ARRAY(T)                        \
    (struct s_array)                        \
    {                                       \
        .data = NULL,                       \
        .size = 0,                          \
        .capacity = 0,                      \
        .type_size = sizeof(T)              \
    }

/*
** Array::new
** -
** Constructor that tries a first malloc.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
*/
t_array fta_new(size_t type_size);

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
t_array* fta_alloc(size_t type_size);

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
int fta_append(t_array* self, void const* data, size_t datalen);

/*
** Array::insert
** -
** Adds _datalen_ elements at index _index_ to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _datalen_ should be the number of elements stored in _data_.
** _index_ is the future index of the first element of _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/
int fta_insert(t_array* self, void const* data, size_t datalen, size_t index);

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
int fta_reserve(t_array* self, size_t size);

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
int fta_trim(t_array* self);

/*
** Array::clear
** -
** Frees the underlying data, but leaves the array usable :
** one might still call the append function, the array was only
** emptied.
*/
void fta_clear(t_array* self);

/*
** Array::clear_f
** -
** Same as Array::clear, but uses a custom function on each element before
** free the underlying array,
** useful when your structures contains addresses of allocated variables
** to be freed to prevent leaks.
** -
** _del_ is a function that knows how to properly free a single element's
** contents from its address.
*/
void fta_clearf(t_array* self, void (*del)(void*));

/*
** Array::release
** -
** If one initialised the array with fta_alloc, they are advised
** to use fta_release to free it.
** Both the underlying data and the array will be freed.
** -
** _ptr_ is the address of a pointer to an array,
** and will be set to NULL to prevent further uses attempts.
*/
void fta_release(t_array** ptr);

/*
** Array::pop_back
** -
** Removes at most _len_ elements at the end.
** -
** _len_ is the number of elements to be removed.
*/
void fta_popback(t_array* self, size_t len);

/*
** Array::pop_back w/ function
** -
** Same as pop_back, but provides a way to avoid leaks by freeing
** contents pointed by the poped elements.
** -
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single element's
** contents from its address.
*/
void fta_popbackf(t_array* self, size_t len, void (*del)(void*));

/*
** Array::pop_index
** -
** Removes at most _len_ elements starting at _index_.
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/
int fta_popindex(t_array* self, size_t index, size_t len);

/*
** Array::pop_index w/ function
** -
** Same as fta_popindex, but with a way to free cleanly the removed
** elements.
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single
** element's contents from its address.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/
int fta_popindexf(t_array* self, size_t index, size_t len, void (*del)(void*));

/*
** Array::overwrite
** -
** Replaces _self_'s contents with _other_'s.
** -
** Will fail, leaving _self_ untouched,
** if the two array's aren't compatible.
** (i.e. if the two types do not have the same lenght)
** -
** Returns a status :
** 0 upon success
** 1 otherwise.
*/
int fta_overwrite(t_array* self, const t_array* other);

/*
** Array::replace
** -
** replace a part of _self_ by _new_
** -
**       |---| <-len
** "echo $USER is cool"
**       |   \----\
** "echo john_smith is cool"
**       ^index
** -
** Returns a status
** 1 in case of failure (malloc)
** 0 otherwise.
*/
int fta_replace(t_array* self, size_t index, size_t len, t_array* new);

/*
** Array::pop_front
** -
** Might be clearer sometimes
*/
#define ARRAY_POPFRONT(A, N) fta_popindex(A, 0, N)

/*
** Array::index_check
** -
** Checks if the provided index is a valid one.
** -
** Returns a boolean :
** 0 if _I_ is greater than the number of elements
** 1 otherwise
*/
#define ARRAY_INDEX_CHECK(A, I) ((I) < (A)->size)

/*
** Array::get
** -
** Returns the address of the element of the array of index _I_
** Just be sure that such an element exists
*/
#define ARRAY_GET(A, I) (ARRAY_START(A) + ARRAY_OFFSET(A, I))

/*
** Array::get_safe
** -
** Allows one to access the i-nth element of an array
** without bothering about neither the implementation
** nor if the index is actually valid.
** -
** _I_ is the index of the element that one wishes to access
** -
** Returns the desired element,
** or NULL if _I_ is out of range
*/
#define ARRAY_GETS(A, I) (ARRAY_INDEX_CHECK(A, I) ? ARRAY_GET(A, I) : NULL)

/*
** Array::get_typed
** -
** Same as get, but casted to a pointer of the type.
*/
#define ARRAY_GETT(T, A, I) ((T*)ARRAY_GET(A, I))

/*
** Array::get_typed_safe
** -
** Same as get_safe, but casted to a pointer of the type.
*/
#define ARRAY_GETTS(T, A, I) ((T*)ARRAY_GETS(A, I))

/*
** Array::get_element
** -
** returns the element of index _I_
*/
#define ARRAY_GETL(T, A, I) (*ARRAY_GETT(T, A, I))

/*
** Array::index_from_pointer
** -
** _P_ is an element of the array whose index is seeked
*/
#define ARRAY_IFP(A, P) ((((void*)P) - (A)->data) / (A)->type_size)

/*
** Array::iterate
** -
** The following set of functions allow one to apply a certain
** function on each of the elements of the array.
** -
** iter :	f(T*)		knows what to do with the address of an element
** iter1 :	f(A*,T*)	the same, but with an extra piece of information
** iter2 :	f(A*,B*,T*)	the same, but with two external variables passed through
**
** iteri :	f(int,T*)		knows what to do with an element and its index
** iteri1 :	f(A*,int,T*)	the same but with an extra piece of data
** iteri2 :	f(A*,B*,int,T*)	the same but with two extra pieces of data
** -
** _f_ will be called on each of the elements.
*/

void fta_iter(const t_array* self, void (*f)());
void fta_iter1(const t_array* self, void (*f)(), void* a);
void fta_iter2(const t_array* self, void (*f)(), void* a, void* b);

void fta_iteri(const t_array* self, void (*f)());
void fta_iteri1(const t_array* self, void (*f)(), void* a);
void fta_iteri2(const t_array* self, void (*f)(), void* a, void* b);

/*
** Iterator<Array>::new
** -
** Returns an iterator over an array.
*/
#define ARRAY_ITERATOR(A) (ARRAY_START(A) - ARRAY_STEP(A))

/*
** Iterator<Array>::Start
** -
** Returns the start of the array.
*/
#define ARRAY_START(A) ((A)->data)

/*
** Iterator<Array>::End
** -
** Returns the one-past-the-end iterator of the array
*/
#define ARRAY_END(A) (ARRAY_GET(A, (A)->size))

/*
** Array::First
** -
** Returns the first element of the array, or NULL if it is empty
*/
#define ARRAY_FIRST(A) (ARRAY_GETS(A, 0))

/*
** Array:Last
** -
** Returns the last element of the array, or NULL if it is empty
*/
#define ARRAY_LAST(A) (ARRAY_GETS(A, (A)->size - 1))

/*
** Iterator<Array>::Step
** -
** Allows one to go from the address of an element to the next.
*/
#define ARRAY_STEP(A) ((A)->type_size)

/*
** Iterator<Array>::offset
** -
** Allows one to go from the address of an element to another.
*/
#define ARRAY_OFFSET(A, I) ((I)*ARRAY_STEP(A))

/*
** Iterator<Array>::next
** -
** Increments the iterator, for it to point to the next element.
** -
** Returns the new value of the iterator.
*/
#define ARRAY_NEXT(A, IT) ((IT) += ARRAY_STEP(A))

/*
** Iterator<Array>::has_next
** -
** Increments the iterator, for it to point to the next element.
** -
** Returns a boolean indicating if the end of the array was reached.
*/
#define ARRAY_HASNEXT(A, IT) (ARRAY_NEXT(A, IT) < ARRAY_END(A))

/*
** Array::string
** -
** toString
** description
** -
** _f_ converts an element to a string.
** -
** Returns a string representing the given array.
*/
char* fta_string(t_array* self, char* (*f)(void*));

/*
** |		----------===== private: =====----------
*/

/*
** The initial size is the number of elements a new array will be able
** to store before allocating more memory.
*/
#define ARRAY_INITIAL_SIZE 16

/*
** When reaching its capacity, an array will re-allocate memory,
** using this factor to grow relatively to its previous size.
*/
#define ARRAY_FACTOR 2

/*
** Array::_resize
** -
** No subtlety, just resizes the underlying array, no matter the consequences.
** However, in case of a malloc fail, the array is left untouched.
*/
int fta_resize(t_array* self, size_t new_size);

/*
** Array::_swap
** -
** swaps an array segment with what follows.
** very specific function, not useful for standard cases.
** -
** "   -1415920000"
** -swap(4, 10)->
** "   -0000141592"
** -swap(0, 4)->
** "-0000141592   "
*/
void fta_swap(t_array* self, size_t before, size_t after);
