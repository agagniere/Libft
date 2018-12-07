/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:09:32 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 18:07:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "ft_string.h"

#include <stdlib.h>

#define STRING_APPEND(A,S) fta_append(A, S, ft_strlen(S))

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

char	*fta_string(t_array *self, char *(*f)(void *))
{
	t_string	ans[1];
	void		*iterator;
	char		*tmp;

	*ans = NEW_STRING;
	fta_reserve(ans, self->size * 3);
	STRING_APPEND(ans, "[");
	iterator = ARRAY_ITERATOR(self);
	while (ARRAY_HASNEXT(self, iterator))
	{
		tmp = f(iterator);
		STRING_APPEND(ans, tmp);
		free(tmp);
		STRING_APPEND(ans, ", ");
	}
	if (self->size > 0)
		fta_popback(ans, 2);
	fta_append(ans, "]", 2);
	return ((char *)ans->data);
}
