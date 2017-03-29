/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:53:52 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/29 05:36:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"
#include <stdio.h>

void	node_debug(t_tnode *self, int depth)
{
	printf("%.*s(%p, %#x) --- %p, %p\n", depth, " ", (void *)self, self->label, self->left, self->right);
	if (self->left)
		node_debug(self->left, depth + 1);
	if (self->left)
		node_debug(self->left, depth + 1);
}

void	ftt_debug(t_tree *self)
{
	printf("This tree has %i nodes.\n", self->count);
	node_debug(self->root, 0);
}
