/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:16:18 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/02 16:07:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

#define FUCK ((*buff = (w & 0x7f)), 1)

size_t		ft_wstrlen(const wchar_t *wstr)
{
	const wchar_t	*ptr = wstr;

	while (*ptr)
		ptr++;
	return (ptr - wstr);
}

size_t		ft_widetoa(char *buff, wint_t w)
{
	if (w < 0x80)
		return (FUCK);
	else if (w < 0x800)
	{
		*(buff++) = ((w >> 6) & 0x1F) | 0xC0;
		*buff = ((w >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else if (w < 0x10000)
	{
		*(buff++) = ((w >> 12) & 0xF) | 0xE0;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*buff = ((w >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (w < 0x110000)
	{
		*(buff++) = ((w >> 18) & 0x7) | 0xF0;
		*(buff++) = ((w >> 12) & 0x3F) | 0x80;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*buff = ((w >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}

size_t		ft_wstrconv(char *buff, const wchar_t *wstr)
{
	size_t	ans;

	ans = 0;
	while (*wstr != 0)
		ans += ft_widetoa(buff + ans, (wint_t)*(wstr++));
	return (ans);
}

size_t		ft_wstrnconv(char *buff, const wchar_t *wstr, size_t n)
{
	size_t	ans;
	size_t	tmp;

	ans = 0;
	tmp = 0;
	while (*wstr != 0)
	{
		tmp = ft_widetoa(buff + ans, (wint_t)*(wstr++));
		if (ans + tmp > n)
			break ;
		ans += tmp;
	}
	return (ans);
}
