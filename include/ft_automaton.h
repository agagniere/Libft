/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_automaton.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:59:29 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/19 05:31:07 by angagnie         ###   ########.fr       */
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
typedef enum s_dfa_action	t_dfa_action;

enum						e_dfa_action
{
	DFAA_NONE,
	DFAA_SKIP,
	DFAA_NEXT,
	DFAA_ASNEXT,
	DFAA_PUSH
};

/*
** /-----------------------\
** |      SuperString      |
** |-----------------------|
** | String            str |
** | Array<Meta>      meta |
** |-----------------------|
** | int               add |
** \-----------------------/
*/

struct						s_sstr
{
	t_string	str;
	t_array		meta;
};

/*
** Not yet sure about storing index
*/

struct						s_meta
{
	size_t			index;
	size_t			len;
	t_sh_sates		state;
};

/*
** /---------------------------------\
** |	DefiniteFiniteAutomaton	     |
** |---------------------------------|
** | Array<Array<Transition>> states |
** | InputStream                  in |
** | State                   initial |
** | SuperString                 out |
** |---------------------------------|
** \---------------------------------/
**
** At least supposed to be definite...
*/

struct						s_dfa
{
	t_array		states[1];
	t_string	*in;
	t_sstr		*out;
	uint8_t		initial;
};

/*
** For now a state is just an array of transitions,
** we'll see how well it works.
**
** struct					s_state
** {
**   size_t			id;
**   t_array		transitions;
** };
*/

/*
** /--------------------------\
** |        Transition        |
** |--------------------------|
** | char             trigger |
** | Sate              target |
** | Function      sideEffect |
** |--------------------------|
** \--------------------------/
*/

struct						s_trans
{
	char			trigger;
	uint8_t			state;
	t_dfa_action	action;
};

/*
** |	----------===== public: =====----------
*/

# define NEW_DFA(IS) (t_dfa){NEW_ARRAY(t_array), IS}

# define NEW_TRANS(C,S,F) (t_trans){C, S, F}

t_dfa						dfa_new(t_string *in, uint8_t size);

# define STATE_GET(A,S) ARRAY_GETT(t_array, (A)->states, S)

# define TRANS_ADD(A,S,T) fta_append(STATE_GET(A, S), T, 1)

int							dfa_new_state(void);

#endif
