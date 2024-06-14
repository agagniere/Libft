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

#include <stddef.h> /* size_t */

/**
** @file ft_array.h
** Dynamic-size array.
** The following functions allows one to manipulate a collection of objects,
** not bothering about malloc.
** It is inspired by the C++ `std::vector<T>`
**
** In Java, one would declare such an object with :
** ```java
** Vector variable = new Vector<SomeType>();
** ArrayList variable = new ArrayList<SomeType>();
** ```
**
** In C++ it would be :
** ```cpp
** std::vector<some_type> variable();
** ```
**
** Here in C :
** ```
** t_array variable = NEW_ARRAY(t_some_type);
** ```
*/

/**
** Dynamic size array.
** The elements are stored contiguously, and the storage is handled automatically.
**/

typedef struct array
{
	void*  data;      /**< `malloc`-ed storage */
	size_t size;      /**< Number of elements currently stored */
	size_t capacity;  /**< Number of elements that could be stored without re-allocation */
	size_t type_size; /**< Size in bytes of a single element : it is the result of @c sizeof */
} t_array;

/**
** Failsafe constructor.
** No memory is allocated.
** @param T should be the type to be stored in the array.
** @return an array, correctly initialised.
*/
#define NEW_ARRAY(T)                        \
    (struct array)                          \
    {                                       \
        .data = NULL,                       \
        .size = 0,                          \
        .capacity = 0,                      \
        .type_size = sizeof(T)              \
    }

/**
** Constructor that tries a first malloc.
** @param type_size should equal to the returned value of sizeof(T)
** @return an initialized array. If its capacity is 0, the allocation failed.
*/
t_array fta_new(size_t type_size);

/**
** Adds @p datalen elements to @p self.
** Could be called "add all" like in Java.
** May fail if malloc does.
**
** @param data should be a variable of type `T*` cast to `void*`.
** @param datalen should be the number of elements stored in @p data.
** @return a status :
**  - 0 in case of success,
**  - 1 if malloc failed.
*/
int fta_append(t_array* self, void const* data, size_t datalen);

/**
** Adds @p datalen elements at index @p index to @p self.
** May fail if malloc does.
**
** @param data should be a variable of type `T*` cast to `void*`.
** @param datalen should be the number of elements stored in @p data.
** @param index is the future index of the first element of @p data.
** @return a status :
**  - 0 in case of success,
**  - 1 if malloc failed.
*/
int fta_insert(t_array* self, void const* data, size_t datalen, size_t index);

/**
** Ensure enough memory is allocated to accomodate a desired number of elements.
** When one has an estimation of the number of elements that they will add
** to the array, using @c reserve will prevent multiple re-allocations,
** and ensure the best complexity.
** This function makes sure that the array has enough room
** for @p size elements to be added.
**
** @param size is the number of elements that are planned to be added.
** @return a status :
**  - 0 in case of success,
**  - 1 if a re-alloc failed, and leaves the array as-is.
*/
int fta_reserve(t_array* self, size_t size);

/**
** Get rid of any extra memory allocated.
** Could be called "shrink to fit" as it is in C++.
** This function is meant to be called when no more
** elements are expected to be appended to the array.
** Usually there are extra bytes allocated, to ensure
** a low complexity and few system calls, but this
** functions allocates the minimum number of bytes for
** all elements to fit.
**
** @return a status :
**  - 0 if the malloc succeeded,
**  - 1 otherwise.
*/
int fta_trim(t_array* self);

/**
** Return allocated memory to the system.
** Frees the underlying data, but leaves the array usable :
** one might still call the append function, the array was only
** emptied.
*/
void fta_clear(t_array* self);

/**
** Return allocated memory to the system, with a custom function.
** Same as #fta_clear, but uses a custom function on each element before
** freeing the underlying array.
** Useful when your structures contains addresses of allocated variables
** to be freed to prevent leaks.
**
** @param del is a function that knows how to properly free a single element's
** contents from its address.
*/
void fta_clearf(t_array* self, void (*del)(void*));

/**
** Removes at most @p len elements at the end.
** @param len is the number of elements to be removed.
*/
void fta_popback(t_array* self, size_t len);

/**
** Pop back with a custom function.
** Same as #fta_popback, but provides a way to avoid leaks by freeing
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
** replace a part of _self_ by _replacement_
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
int fta_replace(t_array* self, size_t index, size_t len, t_array* replacement);

/*
** Array::pop_front
** -
** Might be clearer sometimes
*/
#define ARRAY_POPFRONT(A, N) fta_popindex(A, 0, N)

/**
** Checks if the provided index is a valid one.
** @return a boolean :
**  - 0 if @p I is greater than the number of elements
**  - 1 otherwise
*/
#define ARRAY_INDEX_CHECK(A, I) ((I) < (A)->size)

/**
** Get an element's address.
** Returns the address of the element of the array of index @p I.
** Just be sure that such an element exists
*/
#define ARRAY_GET(A, I) (ARRAY_START(A) + ARRAY_OFFSET(A, I))

/**
** Get an element's address, safely.
** Allows one to access the i-nth element of an array
** without bothering about neither the implementation
** nor if the index is actually valid.
**
** @param I is the index of the element that one wishes to access
** @return the desired element, or @c NULL if @p I is out of range
*/
#define ARRAY_GETS(A, I) (ARRAY_INDEX_CHECK(A, I) ? ARRAY_GET(A, I) : NULL)

/**
** Get an element's address, typed.
** Same as #ARRAY_GET, but cast to a pointer of the type.
** @param T the type
** @param A the array
** @param I the index
*/
#define ARRAY_GETT(T, A, I) ((T*)ARRAY_GET(A, I))

/**
** Get an element's address, safely and typed.
** Same as #ARRAY_GETS, but cast to a pointer of the type.
*/
#define ARRAY_GETTS(T, A, I) ((T*)ARRAY_GETS(A, I))

/**
** Get an element.
** @param T the type
** @param A the array
** @param I the index
** @return the element of index @p I
*/
#define ARRAY_GETL(T, A, I) (*ARRAY_GETT(T, A, I))

/**
** Index from pointer.
** @param P is the address of an element of the array whose index is seeked
*/
#define ARRAY_IFP(A, P) ((((void*)P) - (A)->data) / (A)->type_size)

/**
** @name Iterate functions
** Iterate over an array.
** The following set of functions allow one to apply a certain
** function on each of the elements of the array.
**
**  - iter :    `f(T*)`         knows what to do with the address of an element
**  - iter1 :   `f(A*,T*)`      the same, but with an extra piece of information
**  - iter2 :   `f(A*,B*,T*)`   the same, but with two external variables passed through
**
**  - iteri :   `f(int,T*)`         knows what to do with an element and its index
**  - iteri1 :  `f(A*,int,T*)`      the same but with an extra piece of data
**  - iteri2 :  `f(A*,B*,int,T*)`   the same but with two extra pieces of data
**
** @p f will be called on each of the elements.
*/
/** @{ */

void fta_iter(const t_array* self, void (*f)());
void fta_iter1(const t_array* self, void (*f)(), void* a);
void fta_iter2(const t_array* self, void (*f)(), void* a, void* b);

void fta_iteri(const t_array* self, void (*f)());
void fta_iteri1(const t_array* self, void (*f)(), void* a);
void fta_iteri2(const t_array* self, void (*f)(), void* a, void* b);

/** @} */

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
#define ARRAY_LAST(A) ((A)->size ? ARRAY_GET(A, (A)->size - 1) : NULL)

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

/**
** @name private
** Implementation specific.
** Not meant to be used outside of the implementation of the above funcions.
*/
/** @{ */

/*
** |		----------===== private: =====----------
*/

/**
** The initial size.
** It is the number of elements a new array will be able
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

/** @} */
