#pragma once

#include "ft_array.h"

typedef int           (*t_fptr)(void);
typedef struct s_test   t_test;
typedef t_array         t_tests;

struct                  s_test
{
	const char* name;
	t_fptr      function;
};

#define NEW_TEST(NAME, FUNCTION) (t_test){NAME, FUNCTION}
#define NEW_TESTS NEW_ARRAY(t_test)

int load_test(t_array* list, const char* name, t_fptr function);
int launch_tests(const char* name, t_array* list);
