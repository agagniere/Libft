/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:35:44 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 17:38:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_legacy.h"

#include "libft.h"

char* ft_strnew(size_t size) { return ((char*)ft_memalloc(size + 1)); }
