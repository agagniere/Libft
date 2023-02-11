/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:51:19 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/14 10:51:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ftl_init(t_list* self, size_t type_size)
{
	*self = (t_list){
		.root = { .prev = (t_node*)self, .next = (t_node*)self },
		.type_size = type_size, .size = 0
	};
}
