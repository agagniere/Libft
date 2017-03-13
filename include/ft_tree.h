/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:48:26 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/13 17:12:14 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_tree	t_tree;
typedef struct s_tnode	t_tnode;
typedef enum e_tr		t_tr;

/*
** |		----------=====  Tree<N>  =====----------
** -
** /-----------------------\
** | Tree<N extends Node>  |
** |-----------------------|
** | uint            count |
** | N*               root |
** |-----------------------|
** | tr       push(N**,N*) |
** \-----------------------/
*/

struct					s_tree
{
	size_t		type_size;
	size_t		count;
	t_tnode		*root;
	t_tr		(*push)(t_tnode **, t_tnode *);
};

/*
** /------------------------\
** |          Node          |
** |------------------------|
** | N*                left |
** | N*               right |
** \------------------------/
*/

struct					s_tnode
{
	uint8_t		type;
	t_tnode		*left;
	t_tnode		*right;
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
** Creates a new tree whose element are of type T.
** -
** _T_ is the type of the nodes.
** _F_ is a function that knows how to properly handle nodes, to compare them
** and take action accordingly.
*/

# define NEW_TREE(T,F) (t_tree){sizeof(T), 0, NULL, F}

/*
** TreeNode::new
** -
** "protected" : not useful outisde the construction of the concrete types.
*/

# define NEW_NODE(TYPE) (t_tnode){TYPE, NULL, NULL}

/*
** Tree::push
** -
** Pushes a new node to the tree.
** It is safe to reuse and push the same node multiple times.
** -
** _new_ is a node to be added to the tree.
*/

int						ftt_push(t_tree *self, t_tnode *new);

/*
** TreeNode::isLeaf
** -
** tells if the given node is a leaf.
** As the node's type is supposed to be a variant,
** there can be multiple subtypes that are leaves,
** and multiple subtypes that are nodes.
** So a node is a leaf _iff_ its most significant bit is on.
*/

# define NODE_ISLEAF(N) (NODE_TYPE(N) & (1 << 7))

/*
** TreeNode::getType
** -
** Allows to get the type of a tree node
*/

# define NODE_TYPE(N) (((t_node *)N)->type)

/*
** |		----------===== private: =====----------
*/

/*
** TreeNode::push
** -
** Handles the recursion and node counting.
*/

int						tnode_push(t_tree *self, t_tnode **node, t_tnode *new);

#endif
