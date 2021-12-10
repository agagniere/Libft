#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct dict_node t_dict_node;
typedef struct dict      t_dict;

struct dict_node
{
	t_dict_node* next;
	t_substr     key;
	t_substr     value;
	size_t       hash;
};

#define EMPTY_NODE (void*)(0xDEADBEEF)

struct dict
{
	t_dict_node* data;
	size_t       capacity;
};

bool dict_add(t_dict* map, const t_substr* key, const t_substr* value);
bool dict_get(const t_dict* map, const t_substr* key, t_substr* out_result);
bool dict_remove(t_dict* map, const t_substr* key);
