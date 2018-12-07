/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:54:39 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 15:19:39 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# ifndef ARRAY_LENGTH
#  define ARRAY_LENGTH(A) (sizeof(A) / sizeof(*(A)))
# endif

# include <stddef.h>
# include <stdbool.h>

typedef struct s_deque	t_deque;

/*
** Structure members shall not be accessed directly
*/
struct					s_deque
{
	void		*data;
	void		*front;
	void		*back;
	size_t		type_size;
	unsigned	capacity;
};

/*
** This constructor can be used if the storage is a C static array
*/
# define DEQUE_NEW(A) (t_deque){A, A, A, sizeof(*A), ARRAY_LENGTH(A)}

/*
** Returns an initialized t_deque that uses the specified storage
*/
t_deque					ftq_new(void *data,
								size_t type_size,
								unsigned capacity);
/*
** Right after creation, specify an intended usage
*/
bool					ftq_intent(t_deque *self, char intent);

void					*ftq_first(t_deque *self);
void					*ftq_last(t_deque *self);

/*
** Number of elements stored
*/
unsigned				ftq_size(t_deque *self);

/*
** Maximum number of elements that can be stored
*/
unsigned				ftq_capacity(t_deque *self);

bool					ftq_is_empty(t_deque *self);
bool					ftq_is_full(t_deque *self);

/*
** Deque::isSorted
** -
** @param : _cmp_ is a function such that
** (elem* A, elem* B) -> 0 if both elements are equal
**					-> >0 if B > A
**					-> <0 if B < A
** -
** @return_value :
** true if the stack is sorted in the ascending order
*/
bool					ftq_is_sorted(t_deque *self, int (*cmp)());

bool					ftq_push_one(t_deque *self,
									void *element,
									bool front);
bool					ftq_push_front(t_deque *self,
									void *elements,
									unsigned count);
bool					ftq_push_back(t_deque *self,
									void *elements,
									unsigned count);

bool					ftq_pop_one(t_deque *self,
									void *destination,
									bool front);
bool					ftq_pop_front(t_deque *self,
									void *destination,
									unsigned count);

/*
** Deque::toString
** -
** Returns a string representing the Dequeue
** The _f_ parameter is a function that converts a single element to char*
*/
char					*ftq_string(t_deque *self,
									char *(*f)());

/*
** Iterate functions :
** -
** Call the supplied function on each element,
** in the front-to-back order
*/
void					ftq_iter(t_deque *self, void (*f)());
void					ftq_iter1(t_deque *self, void (*f)(),
									void *ext);
void					ftq_iter2(t_deque *self, void (*f)(),
									void *ext1, void *ext2);

# define FTQ_PUSH_FRONT_ONE(Q, EL) ftq_push_one(Q, EL, true)
# define FTQ_PUSH_BACK_ONE(Q, EL) ftq_push_one(Q, EL, false)

# define FTQ_POP_FRONT_ONE(Q, DST) ftq_pop_one(Q, DST, true)
# define FTQ_POP_BACK_ONE(Q, DST) ftq_pop_one(Q, DST, false)

#endif
