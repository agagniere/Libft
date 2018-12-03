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

#ifndef FT_PREPRO_H
# define FT_PREPRO_H

# include "ft_prepro_private.h"

/*
** Numbers manipulation tools
*/

# define ABS(V) ((V) < 0 ? -(V) : (V))

# define MIN(...) CAT(_MIN,ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
# define MAX(...) CAT(_MAX,ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

/*
** Miscellaneous tricks
*/

# define ARG_COUNT(...) _ARG_COUNT1(__VA_ARGS__)

# define FD_PUT(F,A) write(F, A, ft_strlen(A))
# define FT_PUT(A) FD_PUT(1, A)

# define TO_STR(M) _TO_STR(M)
# define CAT(A,B) _CAT(A,B)

# define TWICE(A) (A),(A)
# define THRICE(A) (A),(A),(A)
# define PPP __VA_ARGS__

/*
** Asserts
*/

# ifdef DISABLE_ASSERT
#  define ASSERT(B) (B)
# else
#  define ASSERT(B) (B ? 1 : FD_PUT(2, __FILE__ " @" TO_STR(__LINE__) " : " #B))
# endif

#endif
