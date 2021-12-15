#pragma once

#include "ft_string.h"
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

struct dict
{
	t_dict_node* data;
	size_t       capacity;
};

t_dict dict_new(size_t capacity);
bool   dict_set(t_dict* self, const t_substr* key, const t_substr* value, bool overwrite);
bool   dict_get(const t_dict* self, const t_substr* key, t_substr* out_result);
bool   dict_remove(t_dict* self, const t_substr* key);
void   dict_print(const t_dict* self);
void   dict_free(t_dict* self);
