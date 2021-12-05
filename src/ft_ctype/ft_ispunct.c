/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:03:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/27 15:33:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_ispunct(int c)
{
	return ((' ' < c && c < '0') || ('9' < c && c < 'A') ||
	        ('Z' < c && c < 'a') || ('z' < c && c <= '~'));
}
