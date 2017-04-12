/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:53:52 by angagnie          #+#    #+#             */
/*   Updated: 2017/04/12 16:08:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"
#include <stdio.h>

void	node_debug(t_tnode *self, int depth, char c)
{
	if (NODE_LABEL(self) == 0x80)
		printf("%*s%c`%s`\n", depth, "", c, *(char **)(self + 1));
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
	printf("This tree has %i nodes.\n", self->count);
	node_debug(self->root, 0, 'R');
}
