/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:48:26 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/19 16:24:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

typedef struct s_tree	t_tree;
typedef struct s_node	t_node;
typedef enum e_tr		t_tr;

/*
** |		----------=====  Tree<N,L>  =====----------
*/

struct					s_node
{
	t_node		*left;
	t_node		*right;
	char		is_node;
};

struct					s_tree
{
	size_t		node_size;
	size_t		leaf_size;
	size_t		count;
	t_node		*root;
	int			(*push)(t_node **, t_node *);
};

enum					e_tr
{
	TR_ERROR = -1,
	TR_DONE,
	TR_LEFT,
	TR_RIGHT,
	TR_BOTH,
	TR_NONE
};

/*
** |		----------===== public: =====----------
*/

/*
** Tree::new
** -
** Creates a new tree whose nodes are of type _A_ and leaves of type _B_.
** _A_ and _B_ can be the same type.
** -
** _A_ is the type of the nodes.
** _B_ is the type of the leaves.
** _F_ is a function that knows how to properly handle nodes, to compare them
** and take action accordingly.
*/

# define NEW_TREE(A,B,F) (t_tree){sizeof(A), sizeof(B), 0, NULL, F}

/*
** Node::new
** -
** "protected" : not useful outisde the construction of the concrete types.
*/

# define NEW_NODE(IS_NODE) (t_node){NULL, NULL, IS_NODE}

/*
** Tree::push
** -
** Pushes a new node to the tree.
** It is safe to reuse and push the same node multiple times.
** -
** _new_ is a node to be added to the tree.
*/

int						ftt_push(t_tree *self, t_node *new);

/*
** |		----------===== private: =====----------
*/

/*
** nodePush
** -
** Handles the recursion and node counting.
*/

int						node_push(t_tree *self, t_node **node, t_node *new);

#endif
