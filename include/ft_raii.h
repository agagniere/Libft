#pragma once

#include "ft_prepo.h"

#define RAII(TYPE) TYPE __attribute__((cleanup(PP_CAT(CLEANUP_, TYPE))))

#ifdef __llvm__
#pragma message("Using clang specific tricks")
typedef int (^Func)();
# define lambda(RetType, Body) ^ RetType Body
#else
#pragma message("Using gcc specific tricks")
typedef int (*Func)();
# define lambda(RetType, Body) ({ RetType __fn__ Body __fn__; })
#endif
