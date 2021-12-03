/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepro.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:18:58 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/03 20:19:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ft_prepro_private.h"

/*
** Numbers manipulation tools
*/

#define MIN(...) VARIADIC_MACRO(_MIN, __VA_ARGS__)
#define MAX(...) VARIADIC_MACRO(_MAX, __VA_ARGS__)

#define ABS(V) MAX(V, -(V))

/*
** Miscellaneous tricks
*/

#define C_ARRAY_LENGTH(A) (sizeof(A) / sizeof(*(A)))

#define ARG_COUNT(...) _ARGCNT1(__VA_ARGS__)

#define VARIADIC_MACRO(NAME, ...) PP_CAT(NAME, ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

#define PP_STR(M) _PP_STR(M)
#define PP_CAT(A, B) _PP_CAT(A, B)
