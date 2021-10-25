#include "heap_tests.h"
#include "ft_heap.h"
#include "comparisons.h"

int push_one_element_test(void)
{
	t_heap heap __attribute__((cleanup (fta_clear))) = HEAP_NEW(unsigned, &unsigned_spaceship_ascending);
	unsigned element = 42;

	heap_push(&heap, &element);
	return !(heap.super.size == 1 && *(unsigned*)HEAP_TOP(&heap) == element);
}
