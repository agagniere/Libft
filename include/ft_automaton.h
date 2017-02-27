/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_automaton.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:59:29 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/25 20:47:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUTOMATON_H
# define FT_AUTOMATON_H

# include "ft_array.h"

typedef struct s_dfa	t_dfa;
typedef struct s_state	t_state;
typedef struct s_trans	t_trans;
typedef enum e_dfa_action
						t_dfa_action;

enum					e_dfa_action
{
	DA_NONE,
	DA_SKIP,
	DA_NEXT
};

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
	t_array		states[1];
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
	uint8_t		state;
	dfa_action	action[1];
};

/*
** |	----------===== public: =====----------
*/

# define NEW_DFA(IS) (t_dfa){NEW_ARRAY(t_array), IS}

# define NEW_TRANS(C,S) (t_trans){C, S, {0, 0}}

t_dfa					dfa_new(t_is *in, uint8_t size);

# define STATE_GET(A,S) ARRAY_GETT(t_array, (A)->states, S)

# define TRANS_ADD(A,S,T) fta_append(STATE_GET(A, S), T, 1)

int						dfa_new_state();

#endif
