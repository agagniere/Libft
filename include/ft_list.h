/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:14:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/14 10:44:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
boolean add(E e)
Appends the specified element to the end of this list.

void	add(int index, E element)
Inserts the specified element at the specified position in this list.

boolean addAll(Collection<? extends E> c)
Appends all of the elements in the specified collection to the end of this list, in the order that they are returned by the specified collection's iterator.

boolean addAll(int index, Collection<? extends E> c)
Inserts all of the elements in the specified collection into this list, starting at the specified position.

void	addFirst(E e)
Inserts the specified element at the beginning of this list.

void	addLast(E e)
Appends the specified element to the end of this list.

void	clear()
Removes all of the elements from this list.

Object	clone()
Returns a shallow copy of this LinkedList.

boolean	contains(Object o)
Returns true if this list contains the specified element.

E		element()
Retrieves, but does not remove, the head (first element) of this list.

E		get(int index)
Returns the element at the specified position in this list.

E		getFirst()
Returns the first element in this list.

E		getLast()
Returns the last element in this list.

int		indexOf(Object o)
Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.

int		lastIndexOf(Object o)
Returns the index of the last occurrence of the specified element in this list, or -1 if this list does not contain the element.

List	Iterator<E>listIterator(int index)
Returns a list-iterator of the elements in this list (in proper sequence), starting at the specified position in the list.

boolean	offer(E e)
Adds the specified element as the tail (last element) of this list.

boolean	offerFirst(E e)
Inserts the specified element at the front of this list.

boolean	offerLast(E e)
Inserts the specified element at the end of this list.

E		peek()
Retrieves, but does not remove, the head (first element) of this list.

E		peekFirst()
Retrieves, but does not remove, the first element of this list, or returns null if this list is empty.

E		peekLast()
Retrieves, but does not remove, the last element of this list, or returns null if this list is empty.

E		poll()
Retrieves and removes the head (first element) of this list.

E		pollFirst()
Retrieves and removes the first element of this list, or returns null if this list is empty.

E		pollLast()
Retrieves and removes the last element of this list, or returns null if this list is empty.

E		pop()
Pops an element from the stack represented by this list.

void	push(E e)
Pushes an element onto the stack represented by this list.

E		remove()
Retrieves and removes the head (first element) of this list.

E		remove(int index)
Removes the element at the specified position in this list.

boolean	remove(Object o)
Removes the first occurrence of the specified element from this list, if it is present.

E		removeFirst()
Removes and returns the first element from this list.

boolean	removeFirstOccurrence(Object o)
Removes the first occurrence of the specified element in this list (when traversing the list from head to tail).

E		removeLast()
Removes and returns the last element from this list.

boolean	removeLastOccurrence(Object o)
Removes the last occurrence of the specified element in this list (when traversing the list from head to tail).

E		set(int index, E element)
Replaces the element at the specified position in this list with the specified element.

int		size()
Returns the number of elements in this list.
*/

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_list
{
	t_node			root;
	size_t			type_size;
	size_t			size;
}					t_list;

/*
** ----------===== Constructors =====----------
*/

void				ftl_init(t_list *l, size_t type_size);
t_list				*ftl_alloc(size_t type_size);
int					ftl_cpy(t_list *dst, t_list const *src);

/*
** ----------===== Destructors  =====----------
*/

void				ftl_del();
void				ftl_free();

/*
** ------------===== Methods  =====------------
** ----- Insert -----
*/

int					ftl_push_front(t_list *l, t_node const *e);
int					ftl_push_back(t_list *l, t_node const *e);

/*
** ----- Remove -----
*/

void    ftl_pop_back(t_list *l);
void    ftl_pop_backf(t_list *l, void (*del)());

#endif
