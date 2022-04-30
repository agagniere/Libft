#pragma once

#include "tools.h"

#define RAII(TYPE) TYPE __attribute__((cleanup(MERGE(cleanup, TYPE))))
