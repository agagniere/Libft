/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:07:15 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/13 16:08:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memdup(void *addr, size_t len)
{
	void *ans;

	if (ans = malloc(len))
		ft_memcpy(ans, addr, len);
	return (ans);
}
