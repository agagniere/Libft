/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:37:02 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/19 14:44:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAM_H
# define FT_STREAM_H

typedef struct s_is		t_is;
typedef struct s_fis	t_fis;
typedef struct s_sis	t_sis;

/*
** Input Stream
*/

struct					s_is
{
	int		(*read)(size_t n);
};

/*
** File Input Stream
*/

struct					s_fis
{
	t_is		super;
	t_string	buff;
	size_t		i;
	int			fd;
};

/*
** String Input Stream
*/

struct					s_sis
{
	t_is		super;
	t_string	in;
	size_t		i;
};

#endif
