/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:05:05 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 17:45:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "ft_string.h"

#include <stdlib.h>

void		append_element(t_string *string, char *(*f)(), void *element)
{
	char *const		elem_str = f(element);

	fta_append(string, elem_str, ft_strlen(elem_str));
	free(elem_str);
	fta_append(string, ", ", 2);
}

/*
** Deque::toString
** -
** Returns a string representing the Dequeue
** The _f_ parameter is a function that converts a single element to char*
*/

char		*ftq_string(t_deque *self, char *(*f)())
{
	t_string	ans;

	ans = NEW_STRING;
	fta_reserve(&ans, ftq_size(self) * 3);
	fta_append(&ans, "[", 1);
	ftq_iter2(self, &append_element, &ans, f);
	if (!ftq_is_empty(self))
		fta_popback(&ans, 2);
	fta_append(&ans, "]", 2);
	return ((char*)ans.data);
}
