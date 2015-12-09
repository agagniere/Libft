/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/09 13:09:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# include "ft_ctype.h"
# include "ft_vector.h"
# include "ft_string.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n); // SP++ OK

char	*ft_itoa_base(int n, int base);
char	*ft_itoa(int n);

void	ft_lstadd(t_list **alst, t_list *new_elem);
int		ft_lstequ_rec(t_list *a, t_list *b, int (*equ)(void *, void *));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel_rec(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
t_list	*ft_lstmap_rec(t_list *lst, t_list * (*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstpush(t_list **alst, t_list *new_elem);
void	ft_lstpush_rec(t_list **alst, t_list *new_elem);

void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n); //withit OK
void	*ft_memchr(const void *s, int c, size_t n); //withit OK
int		ft_memcmp(const void *s1, const void *s2, size_t n); //withit OK
void	*ft_memcpy(void *dst, const void *src, size_t n); //withit OK
void	ft_memdel(void **ap);
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
# define DYNA_INITIAL_SIZE 8
# define DYNA_FACTOR 2

#endif
