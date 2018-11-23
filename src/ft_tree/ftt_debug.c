/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:53:52 by angagnie          #+#    #+#             */
/*   Updated: 2018/11/23 14:04:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_tree.h"

void	node_debug(t_tnode *self, int depth, char c)
{
	if ((self->label >> 2) == 0x20)
		printf("%*s%c(\"%s\", %#x)\n",
			depth, "", c, *(char **)(self + 1), self->label);
	else
	{
		printf("%*s%c(%p, %#x) --- %p, %p\n", depth, "", c,
			(void *)self, self->label, self->left, self->right);
		if (self->left)
			node_debug(self->left, depth + 1, 'l');
		if (self->right)
			node_debug(self->right, depth + 1, 'r');
	}
}

void	ftt_debug(t_tree *self)
{
	printf("This tree has %zu nodes.\n", self->count);
	if (self->root)
		node_debug(self->root, 0, 'R');
}
