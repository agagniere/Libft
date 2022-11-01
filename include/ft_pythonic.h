#pragma once

#include "ft_pythonic_private.h"
#include "ft_prepro/tools.h"

#define in_range(VAR, ...) PP_CAT(_IN_RANGE_, ARG_COUNT(__VA_ARGS__))(VAR, __VA_ARGS__)
