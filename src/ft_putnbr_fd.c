/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:54:23 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 09:51:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void ft_putnbr_fd(int n, int fd)
{
	char* str = ft_itoa_base(n, 10);
	ft_putstr_fd(str, fd);
	free(str);
}
