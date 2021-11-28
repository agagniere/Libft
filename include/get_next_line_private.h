#pragma once

#include "ft_list.h"

#include <stddef.h>

#define FTGNL_BUFF_SIZE 2048

typedef struct s_fdsave
{
	t_node self;
	int    fd;
	size_t size;
	char*  data;
} t_fdsave;
