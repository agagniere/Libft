/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:59:29 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/21 20:00:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUTOMATON_H
# define FT_AUTOMATON_H

typedef struct s_dfa	t_dfa;
typedef struct s_state	t_state;

struct					s_dfa
{
	t_array		states;
	t_is		in;
	t_string	output;
};



#endif
