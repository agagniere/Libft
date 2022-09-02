#pragma once

#include "tools.h"
#include "constraints.h"

#define Function(TYPE_RET, NAME, ...)  TYPE_RET (*NAME)(__VA_ARGS__)

#define FunctionType(TYPE_RET, ...) MERGE(function, ##__VA_ARGS__)

#define DefineFunctionType(TYPE_RET, ...) typedef TYPE_RET (*FunctionType(TYPE_RET, ##__VA_ARGS__))(__VA_ARGS__);

DefineFunctionType(int)
FOR(EACH(Number), DefineFunctionType, int)
