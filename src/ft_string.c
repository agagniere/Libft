/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 02:55:15 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/13 17:27:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** String::toChar*
** -
** Handy function to use a String as a char*
*/

char	*ft_string(t_string *str)
{
	STR_NULL_TERMINATE(str);
	return ((char *)str->data);
}
