/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:14:38 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/13 09:22:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

static void	ftl_pop(t_node *prev, t_node *next)
{
	prev->next = next;
	next->prev = prev;
}

void		ftl_pop_back(t_list *l)
{
	t_node *last;

	last = l->root.prev->prev;
	free(l->root.prev);
	ftl_pop(last, (t_node *)l);
	l->size--;
}

void		ftl_pop_backf(t_list *l, void (*del)())
{
	t_node *last;

	last = l->root.prev->prev;
	del(l->root.prev);
	ftl_pop(last, (t_node *)l);
	l->size--;
}

void		ftl_pop_front(t_list *l)
{
	t_node *first;

	first = l->root.next->next;
	free(l->root.next);
	ftl_pop((t_node *)l, first);
	l->size--;
}

void		ftl_pop_elem(t_list *const l, t_node **const e)
{
	ftl_pop(e[0]->prev, e[0]->next);
	free(*e);
	*e = NULL;
	l->size--;
}
