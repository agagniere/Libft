/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:47:11 by angagnie          #+#    #+#             */
/*   Updated: 2017/04/26 16:42:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "ft_array.h"
# include "ft_string_legacy.h"

/*
** |		----------===== String =====----------
*/

/*
** Vector<char> wraper
*/

typedef t_array			t_string;

typedef struct s_substr	t_substr;

struct					s_substr
{
	char		*str;
	size_t		len;
};

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
** String::toChar*
** -
** Handy function to use a String as a char*
*/

char					*ft_string(t_string *str);

/*
** String::join(char*)
** -
** Appends a char* at the end of the given String.
*/

# define STR_JOIN_CS(S,CS,L) (fta_append(S, CS, L))

/*
** String::join(SubString)
** -
** Appends a SubString at the end of the given String.
*/

# define STR_JOIN(STR,SUB) fta_append(STR, (SUB)->str, (SUB)->len)

/*
** String::insert(SubString)
*/

# define STR_INSERT(ST,SB,I) fta_insert(ST, (void *)(SB)->str, (SB)->len, I)

/*
** String::insert(char*)
** -
** _S_ the String where data is inserted.
** _CS_ a char* where the data is.
** _L_ the number of char _CS_ is long.
** _I_ the index where the data is to be inserted.
*/

# define STR_INSERT_CS(S,CS,L,I) (fta_insert(S, (void *)CS, L, I))

/*
** String::get
** -
** Returns the address of the element at index _I_
*/

# define STR_GET(STR,I) ARRAY_GETT(char, STR, I)

/*
** String::getChar
** -
** Returns the element of index _I_
*/

# define STR_GETCHAR(STR,I) (*ARRAY_GETT(char, STR, I))

/*
** String::nullTerminate
** -
** to be compatible with regular string functions,
** this ensures the string has a '\0' signaling its end
** However size will not be affected.
** the post-condition is 'strlen(STR->data) <= STR->size'
*/

# define STR_NULL_TERMINATE(STR) (fta_reserve(STR, 1) || FTSZ(STR))

/*
** String::cleanRest
** -
** sets the rest of the currently allocated array to 0.
** So if only appends are performed, there's no need to call FTSZ.
** However if max = size the string isn't null-terminated, hence
** the nullTerminate function.
*/

# define STR_CLEAN_REST(STR) ft_bzero(ARRAY_END(S), (S)->max - (S)->size)

/*
** Tools for manipulating characters
*/

# define UPPER_CASE(C) (C & ~(1 << 5))
# define LOWER_CASE(C) (C | (1 << 5))
# define TOGGLE_CASE(C) (C ^ (1 << 5))

# define IS_LOWER(C) ('a' <= C && C <= 'z')
# define IS_UPPER(C) ('A' <= C && C <= 'Z')
# define IS_ALPHA(C) (IS_LOWER(C) || IS_UPPER(C))
# define IS_DIGIT(C) ('0' <= C && C <= '9')
# define IS_ALNUM(C) (IS_ALPHA(C) || IS_DIGIT(C))
# define IS_BLANK(C) (C == ' ' || C == '\t')
# define IS_SPACE(C) (IS_BLANK(C) || C == '\v' || C == '\r')

/*
** |		----------===== private: =====----------
*/

# define FTSZ(STR) (*(char *)ARRAY_END(STR) = '\0')

#endif
