#include "comparisons.h"
#include "heap_tests.h"

#include "ft_heap.h"

int push_one_element_test(void)
{
	t_heap heap __attribute__((cleanup(heap_free))) = HEAP_NEW(unsigned, &spaceship(ascending, unsigned));
	unsigned element                                = 42;

	heap_push(&heap, &element);
	return !(heap.super.size == 1 && *(unsigned*)HEAP_TOP(&heap) == element);
}
