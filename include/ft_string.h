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

#pragma once

#include "ft_array.h"

/*
** |		----------===== String =====----------
*/

/*
** Vector<char> wraper
*/
typedef t_array t_string;

typedef struct s_substr t_substr;

struct s_substr
{
	char*  str;
	size_t len;
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
#define SUBSTR(S) _SUBSTR(S, S == NULL ? 0 : ft_strlen(S))
#define _SUBSTR(S, L) (t_substr){S, L}

/*
** String::new
** -
** Failsafe constructor.
*/
#define NEW_STRING NEW_ARRAY(char)

/*
** String::toChar*
** -
** Handy function to use a String as a char*
*/
char* ft_string(t_string* str);

/*
** String::join(SubString)
** -
** Appends a SubString at the end of the given String.
*/
#define STRING_APPEND(STR, SUB) fta_append(STR, (SUB)->str, (SUB)->len)

/*
** String::insert(SubString)
*/
#define STRING_INSERT(ST, SB, I) fta_insert(ST, (void*)(SB)->str, (SB)->len, I)


/*
** String::get
** -
** Returns the address of the element at index _I_
*/
#define STRING_GET(STR, I) ARRAY_GETT(char, STR, I)

/*
** String::getChar
** -
** Returns the element of index _I_
*/
#define STRING_GETCHAR(STR, I) (*ARRAY_GETT(char, STR, I))

/*
** String::nullTerminate
** -
** to be compatible with regular string functions,
** this ensures the string has a '\0' signaling its end
** However size will not be affected.
** the post-condition is 'strlen(STR->data) <= STR->size'
*/
#define STRING_NULL_TERMINATE(STR) (fta_reserve(STR, 1) || _FTSZ(STR))

/*
** |		----------===== private: =====----------
*/

#define _FTSZ(STR) (*(char*)ARRAY_END(STR) = '\0')
