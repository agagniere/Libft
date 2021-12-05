#include "comparisons.h"
#include "heap_tests.h"

#include "ft_heap.h"
#include "ft_prepro.h"
#include "libft.h"

int pop_all_elements_test(void)
{
	t_heap max_heap __attribute__((cleanup(heap_free))) = HEAP_NEW(int, &int_spaceship_descending);
	int       elements[] = {42, 13, 27, 19, -21, 54, 7, 23, -2, 18, -8, 10, 43, 72};
	const int length     = C_ARRAY_LENGTH(elements);
	int       i          = length;

	while (i-- > 0)
		heap_push(&max_heap, elements + i);
	int top = 0;
	while (heap_pop(&max_heap, &top))
		;
	return !(top == -21 && max_heap.super.size == 0);
}
