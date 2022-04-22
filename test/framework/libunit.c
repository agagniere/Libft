#include "libunit.h"

#include "ft_array.h"
#include "ft_prepro/color.h"
#include "ft_printf.h"

#include <sys/wait.h>

#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define IS_CHILD 0

int load_test(t_array* list, const char* name, t_fptr function)
{
	const t_test test = NEW_TEST(name, function);

	return fta_append(list, &test, 1);
}

static unsigned run_test(t_test* test)
{
	int status;

	if (fork() == IS_CHILD)
		exit(test->function());
	else
	{
		wait(&status);
		ft_printf("\t%-30s : [", test->name);
		if (status == 0)
			ft_printf("%sOK", COLOR(BOLD, GREEN));
		else if (status == SIGBUS)
			ft_printf("%sBUSE", COLOR(BOLD, RED));
		else if (status == SIGSEGV)
			ft_printf("%sSIGV", COLOR(BOLD, RED));
		else
			ft_printf("%sKO", COLOR(RED));
		ft_printf("%s]\n", COLOR(NORMAL));
	}
	return (status == 0);
}

int launch_tests(const char* name, t_array* list)
{
	void*  iterator;
	size_t success;

	success  = 0;
	iterator = ARRAY_ITERATOR(list);
	ft_printf("%s {\n", name);
	while (ARRAY_HASNEXT(list, iterator))
		success += run_test((t_test*)iterator);
	ft_printf("\t%s%lu / %lu %stests passed\n}\n\n",
	          (success == list->size ? COLOR(GREEN) : COLOR(RED)),
	          success,
	          list->size,
	          COLOR(NORMAL));
	return (success != list->size);
}
