/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/13 16:11:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# include "ft_ctype.h"
# include "ft_vector.h"
# include "ft_string.h"
# include "ft_list.h"

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n); // SP++ OK

char	*ft_itoa_base(int n, int base);
char	*ft_itoa(int n);

void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n); //withit OK
void	*ft_memchr(const void *s, int c, size_t n); //withit OK
int		ft_memcmp(const void *s1, const void *s2, size_t n); //withit OK
void	*ft_memcpy(void *dst, const void *src, size_t n); //withit OK
void	ft_memdel(void **ap);
void    *ft_memdup(void *addr, size_t len); //withit
void	*ft_memmove(void *dst, const void *src, size_t len); //withit OK
void	*ft_memset(void *b, int c, size_t len); //withit OK

void	ft_print_memory(void const *addr, size_t size);

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size, size_t factor);

# define ABS(v) ((v) < 0 ? -(v) : (v))

#endif
