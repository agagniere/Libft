/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:41:24 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/12 21:05:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

/*
** Array::alloc
** -
** Allocates an array and its data.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
** Returns the allocated array,
** or NULL if malloc failed.
*/

t_array		fta_new(size_t type_size)
{
	t_array		ans;

	ans = (t_array){NULL, 0, 0, type_size};
	fta_reserve(&ans, 1);
	return (ans);
}
