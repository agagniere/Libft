/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:32:24 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/03 17:42:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_fdsave
{
	t_node	self;
	int		fd;
	char	*data;
}				t_fdsave;

static t_fdsave	*get_saved_data(t_list *const save, int const fd)
{
	t_node *tmp;

	tmp = (t_node *)save;
	while ((tmp = tmp->next) != (t_node *)save)
		if (((t_fdsave *)tmp)->fd == fd)
			return ((t_fdsave *)tmp);
	return (NULL);
}

static int		handle_past(t_list *save, t_fdsave *past, char **line)
{
	char	*nla;
	char	*const tmp = past->data;

	nla = past->data;
	while (*nla != '\n' && *nla != '\0')
		nla++;
	if (*nla == '\0')
	{
		ftl_pop_elem(save, past);
		return (tmp);
	}
	*nla = 0;
	*line = ft_strdup(past->data);
	past->data = ft_strdup(nla + 1);
	free(tmp);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	save = (t_list){{0, 0}, 0, 0};
	t_fdsave		*past;
	char			*buf;

	if (*line != NULL)
		free(*line);
	if (save.type_size == 0)
		ftl_init(&save, sizeof(t_fdsave));
	past = get_saved_data(&save, fd);
	if (past && !(buf = handle_past(&save, past, line)))
		return (1);
	;
	return (0);
}

int		main(int ac, char **av)
{
	char *line;

	get_next_line(0, &line);
	return (0);
}
