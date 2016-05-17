/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:10:35 by angagnie          #+#    #+#             */
/*   Updated: 2016/05/17 09:17:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*const ans = malloc(count * size);

	if (ans == NULL)
		ft_putstr_fd("ERROR\tft_calloc : Malloc failed\n", 2);
	else
		ft_bzero(ans, size * count);
	return (ans);
}

void	ft_exit(char const *const fnc, char const *const str)
{
	ft_putstr_fd("ERROR\tCritical failure in function ", 2);
	ft_putstr_fd(fnc, 2);
	ft_putstr_fd(". The program will exit, reason being : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(".\n", 2);
	exit(1);
}

void	*ft_safe_calloc(size_t count, size_t size)
{
	void	*const ans = malloc(count * size);

	if (ans == NULL)
		ft_exit("ft_safe_calloc", "Out of memory (Malloc failed)");
	ft_bzero(ans, count * size);
	return (ans);
}
