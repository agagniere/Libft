/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:33:33 by exam              #+#    #+#             */
/*   Updated: 2015/12/08 20:37:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_putnbr_hex(unsigned n, unsigned length)
{
	char const* base = "0123456789abcdef";

	if (length > 1)
		ft_putnbr_hex(n >> 4, length - 1);
	write(1, base + (n % 16), 1);
}

static void print_numbers(const unsigned char* addr, size_t size, size_t i)
{
	int a;

	a = 0;
	while (a < 16)
	{
		if (a + i < size)
			ft_putnbr_hex(addr[i + a], 2);
		else
			write(1, "  ", 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
}

static void print_characters(const unsigned char* addr, size_t size, size_t i)
{
	int a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		if (' ' <= addr[a + i] && addr[a + i] <= '~')
			write(1, addr + a + i, 1);
		else
			write(1, ".", 1);
		a++;
	}
}

void ft_print_memory(const void* addr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		print_numbers((const unsigned char*)addr, size, i);
		print_characters((const unsigned char*)addr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
}
