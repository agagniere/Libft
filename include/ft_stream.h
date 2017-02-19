/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:37:02 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/19 18:53:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAM_H
# define FT_STREAM_H

# include "ft_string.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct s_is		t_is;
typedef struct s_fis	t_fis;
typedef struct s_sis	t_sis;

/*
** Input Stream
*/

struct					s_is
{
	int		(*read)(t_is *self, size_t n);
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
	t_string	*in;
	size_t		i;
};

/*
** InputStream constructors
*/

# define NEW_IS(F) (t_is){F}
# define NEW_FIS() (t_fis){NEW_IS(&fis_read), NEW_STRING, 0, -1}
# define NEW_FIS_O(F,S) (t_fis){NEW_IS(F), NEW_STRING, 0, open(S)}
# define NEW_SIS(F,S) (t_fis){NEW_IS(F), S, 0}

# define IS_READ(IS,N) (((t_is *)(IS)).read((t_is *)(IS), N))

#endif
