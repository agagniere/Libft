#pragma once

#include "ft_prepro/tools.h"
#include "ft_prepro/overload.h"

#include <stdbool.h>

#define compare_sign(T) CAT(compare_sign_, T)
#define declare_compare_sign(T) \
    bool compare_sign(T)(T a, T b)

declare_compare_sign(int);

#define spaceship(WAY, T) CAT(spaceship_, WAY, _, T)
#define declare_spaceship(WAY, T) \
    int spaceship(WAY, T)(const T* a, const T* b)

#define declare_spaceship_bothways(T) \
    declare_spaceship(ascending, T); \
    declare_spaceship(descending, T)

declare_spaceship_bothways(int);
declare_spaceship_bothways(unsigned);
