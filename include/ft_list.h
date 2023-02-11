/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:14:40 by angagnie          #+#    #+#             */
/*   Updated: 2023/02/11 19:58:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h> // size_t

typedef struct s_node
{
	struct s_node* next;
	struct s_node* prev;
} t_node;

typedef struct s_list
{
	t_node root;
	size_t type_size;
	size_t size;
} t_list;

/*
** ----------===== Constructors =====----------
*/

#define LIST_INIT(LIST, TYPE) ftl_init(LIST, sizeof(TYPE))
void ftl_init(t_list* list, size_t type_size);

/*
** ----------===== Destructors  =====----------
*/

void ftl_clear(t_list* self);

/*
** ------------===== Methods  =====------------
** ----- Insert -----
*/

int ftl_push_front(t_list* l, t_node const* e);
int ftl_push_back(t_list* l, t_node const* e);

/*
** ----- Remove -----
*/

void ftl_pop_back(t_list* l);
void ftl_pop_front(t_list* l);
void ftl_pop_backf(t_list* l, void (*del)());
void ftl_pop_elem(t_list* const l, t_node** const e);
