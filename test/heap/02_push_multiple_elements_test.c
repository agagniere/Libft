#include "comparisons.h"
#include "heap_tests.h"

#include "ft_heap.h"
#include "ft_prepro/tools.h"
#include "libft.h"

int push_multiple_elements_test(void)
{
	t_heap max_heap __attribute__((cleanup(heap_free))) = HEAP_NEW(int, &spaceship(descending, int));
	t_heap min_heap __attribute__((cleanup(heap_free))) = HEAP_NEW(int, &spaceship(ascending, int));
	int    elements[] = {42, 13, 27, 19, 21, 54, 7, 23, -2, 18, -8, 10};
	const int length  = C_ARRAY_LENGTH(elements);
	int       i       = length;

	while (i-- > 0)
	{
		heap_push(&max_heap, elements + i);
		heap_push(&min_heap, elements + i);
	}
	return !(max_heap.super.size == length && min_heap.super.size == length &&
	         *(int*)HEAP_TOP(&max_heap) == 54 && *(int*)HEAP_TOP(&min_heap) == -8);
}
