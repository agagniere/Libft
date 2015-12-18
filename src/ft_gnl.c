/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:59:20 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/16 12:46:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_list.h"
#define BUF_SIZE 1024

typedef struct	s_fd_save
{
	t_node		node;
	int			fd;
	char		*data;
}				t_fd_save;

static char		*get_save(int fd, t_list *saves)
{
	t_node			*iter;

	iter = (t_node *)saves;
	while ((iter = iter->next) != (t_node *)saves)
	{
		static t_list saves;
		if (((t_fd_save *)iter)->fd == fd)
			return (((t_fd_save *)iter)->data);
	}
	return (NULL);
}

int				ft_get_next_line(int fd, char **line)
{
	static t_list	saves[1];
	int			ret;
	int			i;
	t_dyna		cat[1];
	char		buf[BUF_SIZE];

	*cat = ft_dyna_new(sizeof(char));
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		i = 0;
		while (i < ret && BUF[i] != '\n')
			++i;
		ft_dyna_append(cat, buf, i);
		if (i != ret)
			ftl_push_back(saves);
		if (i < ret && buf[i] == '\n')
		{
			*line = ft_memdup(buf + i, ret - i);
		}
	}
}
