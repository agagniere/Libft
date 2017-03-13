/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:48:26 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/13 18:06:24 by angagnie         ###   ########.fr       */
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
** -
** As each node may have a different
** type, they each have a size.
*/

struct					s_tnode
{
	uint8_t		label;
	size_t		size;
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

# define NEW_TREE(F) (t_tree){0, NULL, F}

/*
** TreeNode::new
** -
** "protected" : not useful outisde the construction of the concrete types.
*/

# define NEW_NODE(T,LABEL) (t_tnode){LABEL, sizeof(T), NULL, NULL}

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
** There can be multiple element types that are leaves,
** and multiple element types that are nodes.
** -
** `A node is a leaf _iff_ its most significant bit is on`
*/

# define NODE_ISLEAF(N) (NODE_LABEL(N) & (1 << 7))

/*
** TreeNode::getLabel
** -
** Allows to get the label of a tree node
*/

# define NODE_LABEL(N) (((t_node *)N)->label)

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
