#include "libunit.h"

#include "ft_array.h"
#include "ft_prepro/color.h"
#include "ft_prepro/functions.h"
#include "ft_printf.h"

#include <sys/wait.h>

#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define IS_CHILD 0

#ifdef LIBUNIT_SHORT_OUTPUT
# define IF_LONG(STR)
# define IF_SHORT(STR) STR
#else
# define IF_LONG(STR) STR
# define IF_SHORT(STR)
#endif

int load_test(t_array* list, const char* name, Function(int, function))
{
	const t_test test = (t_test){name, function};
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
#ifndef LIBUNIT_SHORT_OUTPUT
		ft_printf("\t%-30s : ", test->name);
#endif
		ft_printf("[");
		if (status == 0)
			ft_printf("%sOK", COLOR(BOLD, GREEN));
		else if (status == SIGBUS)
			ft_printf("%sBUSE", COLOR(BOLD, RED));
		else if (status == SIGSEGV)
			ft_printf("%sSIGV", COLOR(BOLD, RED));
		else
			ft_printf("%sKO", COLOR(RED));
		ft_printf("%s]" IF_LONG("\n"), COLOR(NORMAL));
	}
	return (status == 0);
}

int launch_tests(const char* name, t_array* list)
{
	void*  iterator;
	size_t success;

	success  = 0;
	iterator = ARRAY_ITERATOR(list);
	ft_printf("%s {\n" IF_SHORT("\t"), name);
	while (ARRAY_HASNEXT(list, iterator))
		success += run_test((t_test*)iterator);
	ft_printf(IF_SHORT("\n") "}" IF_LONG("\t") IF_SHORT(" ")
	          "%s%lu / %lu %stests passed\n\n",
	          (success == list->size ? COLOR(GREEN) : COLOR(RED)),
	          success,
	          list->size,
	          COLOR(NORMAL));
	return (success != list->size);
}
