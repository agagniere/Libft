/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitset.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:18:04 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 17:33:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITSET_H
# define FT_BITSET_H

# include <stdint.h>

typedef uint64_t		t_bitset;

# define BITSET_GET(S,V) (S[BS_INDEX(V)] & BS_MASK(V))
# define BITSET_SET(S,V) (S[BS_INDEX(V)] |= BS_MASK(V))

/*
** ----------===== private: =====----------
*/

# define BS_ONE ((t_bitset)1)

# define BS_BIT_PER_ITEM (sizeof(t_bitset) << 3)

# define BS_INDEX(V) ((V) / BS_BIT_PER_ITEM)

# define BS_BIT(V) ((V) % BS_BIT_PER_ITEM)

# define BS_MASK(V) (BS_ONE << BS_BIT(V))

#endif
