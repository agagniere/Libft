#include "ft_prepro/raii.h"
#include "ft_string.h"
#include <stdlib.h>

void cleanup_t_cstring(t_cstring* str)
{
	if (*str) free(*str);
}

void cleanup_t_string(t_string* str)
{
	fta_clear(str);
}
