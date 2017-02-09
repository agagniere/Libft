/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:48:26 by angagnie          #+#    #+#             */
/*   Updated: 2017/02/09 22:17:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_TREE_H
# define FT_TREE_H

typedef struct s_tree	t_tree;
typedef struct s_node	t_node;

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

# define NEW_TREE(A,B,F) (t_tree){sizeof(A), sizeof(B), 0, NULL, F}

# define NEW_NODE(IS_NODE) (t_node){NULL, NULL, IS_NODE}

#endif
