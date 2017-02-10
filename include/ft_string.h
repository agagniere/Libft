/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:47:11 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/10 02:12:41 by angagnie         ###   ########.fr       */
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
	char		*str;
	size_t		len;
}					t_substr;

/*
** |		----------===== public: =====----------
*/

/*
** SubString::new
** -
** Failsafe constructor, no memory is allocated.
** -
*/

# define NEW_SUB(S) (t_substr){S, S == NULL ? 0 : ft_strlen(S)}

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

# define STR_JOIN_CS(S,CS,L) fta_append(S, CS, L) || FTSZ(S)

/*
** String::join(SubString)
** -
** Appends a SubString at the end of the given String.
*/

# define STR_JOIN(STR,SUB) fta_append(STR, SUB->str, SUB->len)

/*
** String::insert(SubString)
*/

# define STR_INSERT(STR,SUB,I) fta_insert(STR, (void *)SUB->str, SUB->len, I)

/*
** String::insert(char*)
** -
** _S_ the String where data is inserted.
** _CS_ a char* where the data is.
** _L_ the number of char _CS_ is long.
** _I_ the index where the data is to be inserted.
*/

# define STR_INSERT_CS(S,CS,L,I) fta_insert(S, (void *)CS, L, I) || FTSZ(S)

/*
** |		----------===== private: =====----------
*/

#define FTSZ(STR) (char *)ARRAY_END(STR) = '\0'

#endif
