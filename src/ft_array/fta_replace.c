/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fta_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:23:44 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/06 20:09:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** "echo $USER is cool"
** "     |   \----\"
** "echo john_smith is cool"
*/

int		fta_replace(t_array *self, size_t index, size_t len, t_array *new)
{
	return (fta_popindex(self, index, len)
		|| fta_insert(self, new->data, new->size, index));
}
