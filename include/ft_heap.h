/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:15:27 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/11 12:19:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAP_H
# define FT_HEAP_H

# include "ft_array.h"

typedef struct s_heap
			t_heap;

struct		s_heap
{
	t_array	super;
	int		(*cmp)();
};

# define HEAP_NEW(T,F) (t_heap){NEW_ARRAY(T),F}

#endif
