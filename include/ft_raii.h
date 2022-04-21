#pragma once

#include "ft_prepo.h"

#define RAII(TYPE) TYPE __attribute__((cleanup(PP_CAT(CLEANUP_, TYPE))))
