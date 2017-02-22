/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:37:02 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/22 14:44:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAM_H
# define FT_STREAM_H

# include "ft_string.h"

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_is		t_is;
typedef struct s_fis	t_fis;
typedef struct s_sis	t_sis;

/*
** Input Stream
*/

struct					s_is
{
	t_substr	(*read)(t_is *self, size_t n);
};

/*
** File Input Stream
*/

struct					s_fis
{
	t_is		super;
	int			fd;
	t_string	buff;
};

/*
** String Input Stream
*/

struct					s_sis
{
	t_is		super;
	size_t		i;
	t_string	*in;
};

/*
** InputStream constructors
*/

# define NEW_IS(F) (t_is){F}
# define NEW_FIS() (t_fis){{&fis_read}, -1, NEW_STRING}
# define NEW_FIS_O(S) (t_fis){{&fis_read}, open(S, O_RDONLY), NEW_STRING}
# define NEW_SIS(S) (t_sis){{&sis_read}, 0, S}

/*
** Tools
*/

# define FIS_OPEN(A,S) ((A)->fd = open(S, O_RDONLY))
# define FIS_CLOSE(A) (close((A)->fd))

# define IS_READ(IS,N) (((t_is *)(IS))->read((t_is *)(IS), N))

#endif
