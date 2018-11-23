/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:54:48 by angagnie          #+#    #+#             */
/*   Updated: 2018/11/23 13:54:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_PRIVATE_H
# define FT_DEQUE_PRIVATE_H

/*
** Is data spread on two discontinuous memory slots
*/
bool				ftq_is_split(t_deque *self);

/*
** Pointer to the first element
*/
void				*ftq_front(t_deque *self);

/*
** Pointer to the would-be next-after-the-last element
*/
void				*ftq_back(t_deque *self);

/*
** Pointer to the start of the underlying storage
*/
void				*ftq_begin(t_deque *self);

/*
** Pointer one-past-the-end of the underlying storage
*/
void				*ftq_end(t_deque *self);

/*
** Size in memory of _count_ elements
*/
size_t				ftq_offset(t_deque *self, unsigned count);

/*
** Number of elements in the range delimited by those two elements
** (upper bound excluded)
*/
unsigned			ftq_distance(t_deque *self, void *elem1, void *elem2);
/*
** Number of elements between front and back
*/
unsigned			ftq_interior(t_deque *self);

/*
** Number of elements surrounding front and back
*/
unsigned			ftq_exterior(t_deque *self);

/*
** Returns -1 if out of bound, -2 if outside storage
*/
int					ftq_index(t_deque *self, void *element);

/*
** Move the specified pointer to the next/previous element
*/
void				ftq_move_one(t_deque *self, void **pointer, bool forward);

# define FTQ_MOVE_FORWARD_ONE(Q, PTR) ftq_move_one(Q, &PTR, true)
# define FTQ_MOVE_BACKWARD_ONE(Q, PTR) ftq_move_one(Q, &PTR, false)

#endif
