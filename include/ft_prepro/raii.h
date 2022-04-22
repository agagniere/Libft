#pragma once

#include "tools.h"

#define RAII(TYPE) TYPE __attribute__((cleanup(PP_CAT(cleanup_, TYPE))))
