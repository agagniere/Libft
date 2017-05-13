/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:07:14 by angagnie          #+#    #+#             */
/*   Updated: 2017/05/13 18:58:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"
#include <stdlib.h>

static void		node_clear(t_tnode **self, void (*f)(), size_t *i)
{
	if (*self)
	{
		if (self[0]->left)
			node_clear(&(self[0]->left), f, i);
		if (self[0]->right)
			node_clear(&(self[0]->right), f, i);
		f(*self);
		*self = NULL;
		(*i)--;
	}
}

int				ftt_clear(t_tree **self)
{
	const int		nodes = self[0]->count;

	node_clear(&(self[0]->root), &free, &(0[self]->count));
	return (nodes - self[0]->count);
}

int				ftt_clearf(t_tree **self, void (*f)())
{
	const int		nodes = self[0]->count;

	node_clear(&(self[0]->root), f, &(0[self]->count));
	return (nodes - self[0]->count);
}
