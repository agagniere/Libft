/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automaton.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:59:29 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/22 21:17:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUTOMATON_H
# define FT_AUTOMATON_H

# include "ft_array.h"

typedef struct s_dfa	t_dfa;
typedef struct s_state	t_state;
typedef struct s_trans	t_trans;

/*
** /---------------------------------\
** |     DefiniteFiniteAutomaton     |
** |---------------------------------|
** | Array<Array<Transition>> states |
** | InputStream                  in |
** |---------------------------------|
** \---------------------------------/
**
** At least supposed to be definite...
*/

struct					s_dfa
{
	t_array		states;
	t_is		*in;
};

/*
** For now a state is just an array of transitions,
** we'll see how well it works.
**
** struct					s_state
** {
** size_t			id;
** t_array		transitions;
** };
*/

struct					s_trans
{
	char		c;
	size_t		state;
};

/*
** |	----------===== public: =====----------
*/

# define NEW_DFA(IS) (t_dfa){NEW_ARRAY(t_array), IS}

#endif
