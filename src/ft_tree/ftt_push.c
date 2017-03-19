/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:55:40 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/19 05:41:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"
#include "libft.h"

/*
** Tree::push
** -
** Pushes a new node to the tree.
** It is safe to reuse and push the same node multiple times.
** -
** _new_ is a node to be added to the tree.
*/

int		ftt_push(t_tree *self, t_tnode *new)
{
	t_tnode	*tmp;

	if (!(tmp = ft_memdup((void *)new, self->type_size)))
		return (1);
	return (tnode_push(self, &self->root, tmp));
}

/*
** TreeNode::push
** -
** Handles the recursion and node counting.
*/

int		tnode_push(t_tree *self, t_tnode **node, t_tnode *new)
{
	const int	ret = self->push(node, new);

	if (ret == TR_LEFT)
		return (tnode_push(self, &(*node)->left, new));
	else if (ret == TR_RIGHT)
		return (tnode_push(self, &(*node)->right, new));
	else if (ret == TR_BOTH)
		return (tnode_push(self, &(*node)->left, new)
				|| tnode_push(self, &(*node)->right, new));
	else if (ret == TR_ERROR)
		return (1);
	else if (ret == TR_DONE)
		self->count++;
	return (0);
}
