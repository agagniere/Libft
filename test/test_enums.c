#include "libunit.h"

#include "ft_prepro/tools.h"
#include "ft_prepro/enum.h"
#include "libft.h"

#include <stdbool.h>
#include <string.h>

DECLARE_ENUM_WITH_VALUES(
	cardinal,
	(East,  1),
	(West,  2),
	(North, 4),
	(South, 8)
);

DECLARE_ENUM_WITH_VALUES(
	weekday,
	(Monday,   0),
	(Tuesday,  1),
	(Wednesday,2),
	(Thursday, 3),
	(Friday,   4),
	(Saturday, 8),
	(Sunday,   9)
);

DECLARE_ENUM_WITH_STRINGS(
	grocery,
	(ITEM_EGG,   "Egg"),
	(ITEM_MILK,  "Milk"),
	(ITEM_BREAD, "Bread"),
	(ITEM_SOUP,  "Soup"),
	(ITEM_YEAST, "Yeast"),
	(ITEM_PASTA, "Pasta")
);

#define ENUM_STRING_condition(NAME, TYPE, EXPECTED_VALUE) \
	({ ft_strequ(PP_CAT(cstring_from_, TYPE)(NAME), EXPECTED_VALUE); })

TEST_SECTION(enum_strings, extract_name, ENUM_STRING_condition,
	(East,     cardinal, "East"),
	(West,     cardinal, "West"),
	(North,    cardinal, "North"),
	(South,    cardinal, "South"),
	(Monday,   weekday,  "Monday"),
	(Saturday, weekday,  "Saturday"),
	(Sunday,   weekday,  "Sunday")
);

TEST_SECTION(enum_custom_strings, extract_name, ENUM_STRING_condition,
	(ITEM_EGG,   grocery, "Egg"),
	(ITEM_MILK,  grocery, "Milk"),
	(ITEM_BREAD, grocery, "Bread"),
	(ITEM_SOUP,  grocery, "Soup"),
	(ITEM_YEAST, grocery, "Yeast"),
	(ITEM_PASTA, grocery, "Pasta")
);

#define ENUM_VALID_condition(NAME, TYPE, VALUE, EXPECTED) \
	({ PP_CAT(is_valid_, TYPE) (VALUE) == EXPECTED; })

TEST_SECTION(enum_validation, extract_name, ENUM_VALID_condition,
	(East,        cardinal, East,                 true),
	(South,       cardinal, South,                true),
	(upper_bound, cardinal, cardinal_upper_bound, false),
	(inbetween,   cardinal, 3,                    false),
	(negative,    weekday,  -1,                   false),
	(Monday,      weekday,  0,                    true),
	(Sunday,      weekday,  Sunday,               true)
);

#define ENUM_ITERATE_condition(NAME, TYPE, START, ...) \
	({                                              \
		enum TYPE expected[] = {__VA_ARGS__};       \
		int  length     = C_ARRAY_LENGTH(expected); \
		int  i          = 0;                        \
		bool result     = true;                     \
		enum TYPE ite   = START;                    \
		while (result && PP_CAT(has_next_, TYPE) (&ite)) \
		{                                           \
			if (i >= length || expected[i] != ite)  \
				result = false;                     \
			i++;                                    \
		}                                           \
		i == length && result;                      \
	})

TEST_SECTION(enum_iteration, extract_name, ENUM_ITERATE_condition,
	(simple, cardinal, 0, East, West, North, South),
	(weekend, weekday, Friday, Saturday, Sunday),
	(vertical, cardinal, 3, North, South),
	(negative, weekday, -1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday),
	(grocery_list, grocery, -1, ITEM_EGG, ITEM_MILK, ITEM_BREAD, ITEM_SOUP, ITEM_YEAST, ITEM_PASTA)
);

int test_enum()
{
	TEST_GROUP("enums");

	return test_enum_strings()
		|| test_enum_validation()
		|| test_enum_iteration()
		|| test_enum_custom_strings();
}
