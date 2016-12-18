/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:09:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/18 20:39:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#define TMP_STRING_APPEND(A,S) fta_append(A, S, ft_strlen(S))

char	*fta_string(t_array *self, char *(*f)(void *))
{
	t_array		ans[1];
	void		*iterator;
	char		*tmp;

	*ans = NEW_ARRAY(char);
	fta_reserve(self->size * 3 + 10);
	TMP_STRING_APPEND(ans, "[|");
	iterator = ARRAY_START(self);
	tmp = f(iterator);
	TMP_STRING_APPEND(ans, tmp);
	while (HAS_NEXT(self, iterator))
	{
		TMP_STRING_APPEND(ans, ", ");
		tmp = f(iterator);
		TMP_STRING_APPEND(ans, tmp);
	}
	fta_append(ans, "|]", 2);
	return ((char *)ans.data);
}

#undef TMP_STRING_APPEND
