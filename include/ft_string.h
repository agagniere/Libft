/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:47:11 by angagnie          #+#    #+#             */
/*   Updated: 2017/01/29 12:47:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

/*
** |		----------===== String =====----------
*/

typedef struct		s_string
{
	char	*data;
	size_t	len;
}					t_string;

typedef struct		s_substr
{
	t_string	*whole;
	size_t		start;
	size_t		len;
}					t_substr;

/*
** |		----------===== public: =====----------
*/

/*
** String::new
** -
** Failsafe constructor, no memory is allocated.
** -
*/

# define NEW_STRING(S) (t_string){S, S == NULL ? 0 : ft_strlen(S)}

#endif
