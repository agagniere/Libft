/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:35:24 by angagnie          #+#    #+#             */
/*   Updated: 2018/11/23 16:21:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "ft_deque.h"

typedef t_deque		t_stack;

# define STACK_NEW(A) DEQUE_NEW(A)

bool				stack_push(t_stack *self, void *element);
bool				stack_pop(t_stack *self, void *destination);
void				*stack_peek(t_stack *self);

#endif
