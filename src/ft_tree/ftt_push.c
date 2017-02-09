/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:55:40 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/09 22:16:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ftt_push(t_tree *self, t_node *new)
{
	t_node	*tmp;

	if (!(tmp = ft_memdup((void *)new,
		new->is_node ? self->node_size : self->leaf_size)))
		return (1);
	return (node_push(&self->root, tmp));
}

int		node_push(t_tree *self, t_node **node, t_node *new)
{
	const int ret = self->push(node, new);

	if (ret == 1)
		return (node_push(self, &node->left, new));
	else if (ret == 2)
		return (node_push(self, &node->right, new));
	else if (ret == -1)
		return (1);
	return (0);
}
