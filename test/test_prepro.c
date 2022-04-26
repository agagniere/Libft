#include "libunit.h"
#include "ft_prepro/color.h"
#include <string.h>

#define PREPRO_name(MACRO, ARGS, ...) MERGE(macro, MACRO, with, ARG_COUNT ARGS, args)
#define PREPRO_condition(MACRO, ARGS, RESULT) MACRO ARGS == RESULT

TEST_SECTION(prepro, PREPRO_name, PREPRO_condition,
    (MAX, (-42, -24), -24),
    (MAX, (-42, 0, 1), 1),
    (MAX, (123, 345, 234, 346, 299, 99), 346),
    (MAX, (-99, -123, -345, -0, -234, -346, -1), 0),
    (MIN, (-42), -42),
    (MIN, (42, 0, -1, 1), -1),
    (MIN, (4123, 345, 1234, 346, 9299), 345),
    (MIN, (99, 123, 345, 0, 234, 346, 1, 999), 0),
    (ABS, (-42), 42)
)

#define COLOR_name(EXPECTED, ...) MERGE(__VA_ARGS__)
#define COLOR_condition(EXPECTED, ...) strcmp(COLOR(__VA_ARGS__), EXPECTED) == 0

TEST_SECTION(color, COLOR_name, COLOR_condition,
    ("\e[0m", DEFAULT),
    ("\e[3;34m", ITALIC, BLUE),
    ("\e[1;4;31m", BOLD, RED)
)
