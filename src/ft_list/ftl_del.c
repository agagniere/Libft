/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 22:11:16 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/15 22:22:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

void ftl_clear(t_list* self)
{
	t_node* tmp;

	tmp = self->root.next;
	while ((tmp = tmp->next) != self->root.next)
		free(tmp->prev);
	self->size = 0;
}
