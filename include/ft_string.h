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
#include "ft_prepro/tools.h"
#include "libft.h"

/*
** |		----------===== String =====----------
*/

/*
** Vector<char> wrapper
*/
typedef t_array t_string;

/*
** This sub-string is meant not to own the pointed memory
** i.e. not responsible for allocating and freeing it.
** -
** A t_string* ( i.e. t_array<char>*) can be converted
** to a t_substr* as if it inherited from it.
*/
typedef struct substr t_substr;

struct substr
{
	char*  string;
	size_t length;
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
#define SUBSTR(...) CAT(SUBSTR_, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
#define SUBSTR_1(S) SUBSTR_2(S, S == NULL ? 0 : ft_strlen(S))
#define SUBSTR_2(S, L) (t_substr){.string = S, .length = (L)}

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
char* cstring(t_string* str);

/*
** String::join(String)
** -
** Appends a String or a SubString at the end of the given String.
*/
#define string_append(SELF, OTHER) fta_append(SELF, ((t_substr*)(OTHER))->string, ((t_substr*)(OTHER))->length)

/*
** String::insert(String, index)
*/
#define string_insert(SELF, OTHER, INDEX) fta_insert(SELF, ((t_substr*)(OTHER))->string, ((t_substr*)(OTHER))->length, INDEX)

/*
** String::get
** -
** Returns the address of the element at index _I_
*/
#define string_get(SELF, INDEX) ARRAY_GETT(char, SELF, INDEX)

/*
** String::getChar
** -
** Returns the element of index _I_
*/
#define string_getchar(SELF, INDEX) (*ARRAY_GETT(char, SELF, INDEX))

/*
** String::equals
** -
** return true if the two strings are equal
*/
#define string_equals(SELF, OTHER)                                  \
	(((t_substr*)(SELF))->length == ((t_substr*)(OTHER))->length && \
	 !ft_memcmp(((t_substr*)(SELF))->string, ((t_substr*)(OTHER))->string, ((t_substr*)(SELF))->length))

/*
** |		----------===== private: =====----------
*/

/*
** String::nullTerminate
** -
** to be compatible with regular string functions,
** this ensures the string has a '\0' signaling its end
** However size will not be affected.
** the post-condition is 'strlen(STR->data) <= STR->size'
*/
#define STRING_NULL_TERMINATE(SELF) (fta_reserve(SELF, 1) || _FTSZ(SELF))


#define _FTSZ(S) (*(char*)ARRAY_END(S) = '\0')
