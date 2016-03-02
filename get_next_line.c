/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:32:24 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/02 22:18:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_fdsave
{
	t_node	this;
	int		fd;
	char	*data;
}				t_fdsave;

t_fdsave	*get_saved_data(t_list *const save, int const fd)
{
	t_node *tmp;

	tmp = (t_node *)save;
	while ((tmp = tmp->next) != (t_node *)save)
	{
		if (((t_fdsave *)tmp)->fd == fd)
			return ((t_fdsave *)tmp);
	}
	return (NULL);
}

int		get_next_line(int const fd, char **line)
{
	static t_list	save = (t_list){{0, 0}, 0, 0};
	t_fdsave		past;

	if (save.type_size == 0)
		ftl_init(&save, sizeof(t_fdsave));
	past = *get_saved_data(&save, fd);
	return (0);
}

int		main(int ac, char **av)
{
	char *line;

	get_next_line(0, &line);
	return (0);
}
