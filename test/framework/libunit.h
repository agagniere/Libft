#pragma once

#include "ft_array.h"

typedef int                (*func)(void);

struct test
{
	const char* description;
	func        function;
};

struct test_section
{
	const char* name;
    t_array     tests;
};
