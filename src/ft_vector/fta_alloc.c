/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:21:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/09 15:15:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array	*fta_alloc(size_t type_size)
{
	t_array	*ans;

	if (!(ans = (t_array *)malloc(sizeof(t_array))))
		return (NULL);
	ans->type_size = type_size;
	return (fta_datainit(ans) ? NULL : ans);
}
