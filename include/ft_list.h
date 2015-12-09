/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/09 16:33:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

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

#endif
