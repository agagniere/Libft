#include "libunit.h"

#define name(MACRO, ARGS, RESULT) PP_CAT(MACRO, ARG_COUNT ARGS)
#define condition(MACRO, ARGS, RESULT) MACRO ARGS == RESULT

TEST_SECTION(prepro, name, condition,
    (MAX, (-42, -24), -24),
    (MAX, (-42, 0, 1), 1),
    (MAX, (123, 345, 234, 346, 299, 99), 346),
    (MAX, (-99, -123, -345, -0, -234, -346, -1), 0),
    (MIN, (-42), -42),
    (MIN, (42, 0, -1, 1), -1),
    (MIN, (4123, 345, 1234, 346, 9299), 345),
    (MIN, (99, 123, 345, 0, 234, 346, 1), 0),
    (ABS, (-42), -42)
)
