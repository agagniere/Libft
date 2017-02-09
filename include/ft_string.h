/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:47:11 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/09 15:24:52 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "ft_array.h"

/*
** |		----------===== String =====----------
*/

/*
** Vector<char> wraper
*/

typedef t_array		t_string;

typedef struct		s_substr
{
	size_t		index;
	size_t		len;
}					t_substr;

/*
** |		----------===== public: =====----------
*/

/*
** SubString::new
** -
** Failsafe constructor, no memory is allocated.
** # define NEW_SUB(S) (t_substr){S, S == NULL ? 0 : ft_strlen(S)}
*/

/*
** String::new
** -
** Failsafe constructor.
*/

# define NEW_STRING NEW_ARRAY(char)

/*
** String::join(char*)
** -
** Appends a char* at the end of the given String.
*/

# define STR_JOIN_CS(STR,CS) fta_append(STR, CS, ft_strlen(CS))

/*
** String::join(SubString)
** -
** Appends a SubString at the end of the given String.
*/

# define STR_JOIN_SUB(STR,SUB) fta_append(STR, SUB->str, SUB->len)

#endif
