#pragma once

#include "ft_overload_private.h"
#include "ft_prepro.h"

#define overload(x, name, ...) PP_CAT(overload_, ARG_COUNT(__VA_ARGS__))(x, name, ##__VA_ARGS__)
