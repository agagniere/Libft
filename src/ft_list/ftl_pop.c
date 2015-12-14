/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:14:38 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/14 10:54:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

static void	ftl_pop(t_node *prev, t_node *next)
{
	prev->next = next;
	next->prev = prev;
}

void	ftl_pop_back(t_list *l)
{
	t_node *last;

	last = l->root.prev->prev;
	free(l->root.prev);
	ftl_pop(last, (t_node *)l);
}

void	ftl_pop_backf(t_list *l, void (*del)())
{
	t_node *last;

	last = l->root.prev->prev;
	del(l->root.prev);
	ftl_pop(last, (t_node *)l);
}

void	ftl_pop_front(t_list *l)
{
	t_node *first;

	first = l->root.next->next;
	free(l->root.next);
	ftl_pop((t_node *)l, first);
}
