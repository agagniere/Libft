/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_automaton.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:59:29 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/02 18:27:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUTOMATON_H
# define FT_AUTOMATON_H

# include "ft_string.h"

typedef struct s_dfa		t_dfa;
typedef struct s_state		t_state;
typedef struct s_trans		t_trans;
typedef struct s_sstr		t_sstr;
typedef struct s_meta		t_meta;

/*
** |	----------===== SuperString =====----------
*/

struct						s_sstr
{
	t_string	str;
	t_array		meta;
};

struct						s_meta
{
	t_sh_sates		state;
	size_t			len;
};

/*
** /---------------------------------\
** |	DefiniteFiniteAutomaton	|
** |---------------------------------|
** | Array<Array<Transition>> states |
** | InputStream					in |
** |---------------------------------|
** \---------------------------------/
**
** At least supposed to be definite...
*/

struct						s_dfa
{
	t_array		states[1];
	t_string	*in;
};

/*
** For now a state is just an array of transitions,
** we'll see how well it works.
**
** struct					s_state
** {
** size_t			id; ????????
** t_array		transitions;
** };
*/

/*
** /----------------------\
** |		Transition		|
** |----------------------|
** | char		trigger |
** | Sate			target |
** | Function	sideEffect |
** |----------------------|
** \----------------------/
*/

struct						s_trans
{
	char		trigger;
	uint8_t		state;
	int			(*f)(char c, uint8_t s, size_t *i);
};

/*
** |	----------===== public: =====----------
*/

# define NEW_DFA(IS) (t_dfa){NEW_ARRAY(t_array), IS}

# define NEW_TRANS(C,S,F) (t_trans){C, S, F}

t_dfa						dfa_new(t_string *in, uint8_t size);

# define STATE_GET(A,S) ARRAY_GETT(t_array, (A)->states, S)

# define TRANS_ADD(A,S,T) fta_append(STATE_GET(A, S), T, 1)

int							dfa_new_state();

#endif
