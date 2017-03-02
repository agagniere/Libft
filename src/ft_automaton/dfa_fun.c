/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:10:16 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/02 18:37:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

int		dfa_skip(char c, uint8_t s, size_t *i, t_sstr *o)
{
	(void)s;
	(void)c;
	(*i)++;
}

int		dfa_next(char c, uint8_t s, size_t *i)
{

	(*i)++;
}
