#include "ft_dict.h"

#include "ft_hashes.h"
#include "ft_printf.h"
#include "libft.h"

#include <stdlib.h>

#define ft_hash    fnv1a_64
#define EMPTY_NODE (void*)(0xDEADBEEF)

t_dict dict_new(size_t desired_size)
{
	t_dict ans;
	unsigned i;

	ans.data = ft_safe_calloc(desired_size, sizeof(t_dict_node));
	ans.capacity = desired_size;
	i = ans.capacity;
	while (i --> 0)
		ans.data[i].next = EMPTY_NODE;
	return ans;
}

bool dict_remove(t_dict* self, const t_substr* key)
{
	size_t       hash = ft_hash(key->string, key->length);
	t_dict_node* ptr  = self->data + (hash % self->capacity);
	t_dict_node* prev = NULL;

	if (ptr->next == EMPTY_NODE)
		return false;
	while (ptr != NULL && (ptr->hash != hash || !string_equals(&(ptr->key), key)))
	{
		prev = ptr;
		ptr  = ptr->next;
	}
	if (ptr == NULL)
		return false;
	free(ptr->key.string);
	free(ptr->value.string);
	if (prev == NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = EMPTY_NODE;
			return true;
		}
		prev = ptr;
		ptr  = ptr->next;
		ft_memcpy(prev, ptr, sizeof(t_dict_node));
	}
	else
		prev->next = ptr->next;
	free(ptr);
	return true;
}

bool dict_set(t_dict* self, const t_substr* key, const t_substr* value, bool overwrite)
{
	size_t       hash = ft_hash(key->string, key->length);
	t_dict_node* dest = self->data + (hash % self->capacity);
	t_dict_node* prev = NULL;

	if (dest->next != EMPTY_NODE)
	{
		while (dest != NULL && (dest->hash != hash || !string_equals(&(dest->key), key)))
		{
			prev = dest;
			dest = dest->next;
		}
		if (dest == NULL)
		{
			dest       = malloc(sizeof(t_dict_node));
			prev->next = dest;
		}
		else if (!overwrite)
			return false;
		else
		{
			free(dest->value.string);
			dest->value.string                = ft_memdup(value->string, value->length + 1);
			dest->value.string[value->length] = '\0';
			dest->value.length                = value->length;
			return true;
		}
	}
	dest->next                        = NULL;
	dest->hash                        = hash;
	dest->key.string                  = ft_memdup(key->string, key->length + 1);
	dest->key.string[key->length]     = '\0';
	dest->key.length                  = key->length;
	dest->value.string                = ft_memdup(value->string, value->length + 1);
	dest->value.string[value->length] = '\0';
	dest->value.length                = value->length;
	return true;
}

bool dict_get(const t_dict* self, const t_substr* key, t_substr* out_result)
{
	size_t             hash = ft_hash(key->string, key->length);
	const t_dict_node* ptr  = self->data + (hash % self->capacity);

	if (ptr->next == EMPTY_NODE)
		return false;
	while (ptr != NULL && (ptr->hash != hash || !string_equals(&(ptr->key), key)))
		ptr = ptr->next;
	if (ptr == NULL)
		return false;
	*out_result = ptr->value;
	return true;
}

void dict_print(const t_dict* self)
{
    ft_printf("{\n");
	for (unsigned i = 0; i < self->capacity; i++)
	{
		if (self->data[i].next != EMPTY_NODE)
		{
			ft_printf("\t%u : ", i);
			t_dict_node* ptr = self->data + i;
			while (ptr)
			{
				ft_printf(" -> (%.*s, %.*s)",
				       (int)ptr->key.length,
				       ptr->key.string,
				       (int)ptr->value.length,
				       ptr->value.string);
				ptr = ptr->next;
			}
			ft_printf("\n");
		}
	}
    ft_printf("}\n");
}

static void dict_node_free(t_dict_node* node)
{
	if (node->next)
		dict_node_free(node->next);
	free(node->key.string);
	free(node->value.string);
	free(node);
}

void dict_free(t_dict* self)
{
	t_dict_node* ptr = self->data + self->capacity;

	while (ptr-- > self->data)
	{
		if (ptr->next == EMPTY_NODE)
			continue;
		if (ptr->next)
			dict_node_free(ptr->next);
		free(ptr->key.string);
		free(ptr->value.string);
	}
	free(self->data);
	self->data     = NULL;
	self->capacity = 0;
}
