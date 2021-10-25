#include "heap_tests.h"
#include "ft_heap.h"
#include "comparisons.h"
#include "libft.h"
#include "ft_prepro.h"

int pop_one_element_test(void)
{
	t_heap max_heap __attribute__((cleanup (fta_clear))) = HEAP_NEW(int, &int_spaceship_descending);
	int elements[] = {42, 13, 27, 19, 21, 54, 7, 23, -2, 18, -8, 10};
	const int length = C_ARRAY_LENGTH(elements);
	int i = length;

	while (i --> 0)
		heap_push(&max_heap, elements + i);
	int top = 0;
	heap_pop(&max_heap, &top);
	return !(top == 54
	         && max_heap.super.size == length - 1
	         && *(int*)HEAP_TOP(&max_heap) == 42);
}
