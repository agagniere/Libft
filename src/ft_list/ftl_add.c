/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:22:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/13 17:43:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ftl_add(t_node *prev, t_node *node, t_node *next)
{
	prev->next = node;
	node->prev = prev;
	node->next = next;
	next->prev = node;
}

int			ftl_push_front(t_list *l, t_node const *e)
{
	t_node *node;

	if (!(node = (t_node *)ft_memdup(e, l->type_size)))
		return (1);
	ftl_add(l, node, l->root->next);
	l->size++;
	return (0);
}

int			ftl_push_back(t_list *l, t_node const *e)
{
	t_node *node;

	if (!(node = (t_node *)ft_memdup(e, l->type_size)))
		return (1);
	ftl_add(l->root, node, l->root);
	l->size++;
	return (0);
}
