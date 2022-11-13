#pragma once

#include "tools.h"

#define RAII(TYPE) TYPE __attribute__((cleanup(MERGE(cleanup, TYPE))))

#define RAII_DECLARE_TYPE(T) void MERGE(cleanup, T)(T*)
