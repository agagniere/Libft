/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:21:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/01 15:58:24 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dyna	*ft_dyna_alloc(size_t chunck_size)
{
	t_dyna	*ans;

	if (!(ans = (t_dyna *)malloc(sizeof(t_dyna))))
		return (NULL);
	ans->chunck_size = chunck_size;
	return (ft_dyna_datainit(ans) ? NULL : ans);
}
