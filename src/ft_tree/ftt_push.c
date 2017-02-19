/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:55:40 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/19 16:12:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Tree::push
** -
** Pushes a new node to the tree.
** It is safe to reuse and push the same node multiple times.
** -
** _new_ is a node to be added to the tree.
*/

int		ftt_push(t_tree *self, t_node *new)
{
	t_node	*tmp;

	if (!(tmp = ft_memdup((void *)new,
		new->is_node ? self->node_size : self->leaf_size)))
		return (1);
	return (node_push(self, &self->root, tmp));
}

/*
** Node::push
** -
** Handles the recursion and node counting.
*/

int		node_push(t_tree *self, t_node **node, t_node *new)
{
	const int	ret = self->push(node, new);

	if (ret == TR_LEFT)
		return (node_push(self, &node->left, new));
	else if (ret == TR_RIGHT)
		return (node_push(self, &node->right, new));
	else if (ret == TR_BOTH)
		return (node_push(self, &node->left, new)
				|| node_push(self, &self->right, new));
	else if (ret == TR_ERROR)
		return (1);
	else if (ret == TR_DONE)
		self->count++;
	return (0);
}
