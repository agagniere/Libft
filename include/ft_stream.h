/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:37:02 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/31 21:33:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAM_H
# define FT_STREAM_H

/*
** File Input Stream
*/

typedef struct		s_fis
{
//	struct
//	{
	char		*buff;
	size_t		i;
//	}				private;
	int				fd;
}					t_fis;

#endif
