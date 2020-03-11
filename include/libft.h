/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/12 20:12:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include "ft_string_legacy.h"

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

/*
** itoa_base :   NxN    ->  String
** |            (n,b)   |-> n expressed in base b
** -
** @return : An allocated null-termminated characters array.
** | If _value_ is strictly negative, the first character will be '-'.
** | If _base_ is not in [2;36], NULL is returned.
** -
** @param _value_ : the number to be expressed in base _base_
** @param _base_ : an integer that should be in range [2;36]
** -
*/

char	*ft_itoa_base(int n, int base);
char	*ft_itoa(int n);

void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_memdel(void **ap);
void	*ft_memdup(void const *addr, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_memswp(void *a, void *b, size_t size);

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
void	*ft_calloc(size_t count, size_t size);
void	ft_exit(char const *const fnc, char const *const str);
void	*ft_safe_calloc(size_t count, size_t size);

float       ft_modff(float f, float* out_intg);
double      ft_modf(double f, double* out_intg);
long double ft_modfl(long double f, long double* out_intg);

#endif
