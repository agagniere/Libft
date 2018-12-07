/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftq_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:53:54 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 15:16:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

#include <stdbool.h>

void		local_aux(bool *answer, int (*cmp)(), int *element)
{
	static int *previous = NULL;

	if (previous != NULL)
		*answer &= (cmp(previous, element) > 0);
	previous = element;
}

bool		ftq_is_sorted(t_deque *self, int (*cmp)())
{
	bool	ans;

	ans = true;
	ftq_iter2(self, &local_aux, &ans, cmp);
	return (ans);
}
