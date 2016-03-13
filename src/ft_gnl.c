/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:04:12 by mseinic           #+#    #+#             */
/*   Updated: 2016/03/13 16:18:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

# define BUFF_SIZE 1024

static char	*new_joined(char *str1, char *str2)
{
	char*	tmp;

	tmp = ft_strjoin(str1, str2);
	if (tmp == NULL)
		return (NULL);
	ft_strdel(&str1);
	return (tmp);
}

static int	end_file(char **s, char **line)
{
	*line = ft_strdup(*s);
	ft_strdel(&(*s));
	if (*line[0] == '\0')
	{
		ft_strdel(&(*line));
		return (0);
	}
	return (1);
}

static int	new_line(char **str, char **line)
{
	char	*next_line;
	char	*tmp;

	tmp = *str;
	next_line = ft_strchr(*str, '\n');
	if (next_line == NULL)
		return (0);
	*next_line = '\0';
	*line = ft_strdup(*str);
	*str = ft_strdup(next_line + 1);
	ft_strdel(&tmp);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*rest[256];
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || fd > 256)
		return (-1);
	if (rest[fd] && new_line(&(rest[fd]), line))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (rest[fd] == NULL)
			rest[fd] = ft_strdup(buff);
		else
			rest[fd] = new_joined(rest[fd], buff);
		if (new_line(&(rest[fd]), line) == 1)
			return (1);
	}
	if (rest[fd] != NULL && ret >= 0)
		return (end_file(&(rest[fd]), line));
	return (ret > 0 ? 1 : ret);
}
