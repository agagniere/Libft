#pragma once

#ifdef __llvm__
#pragma message("Using clang specific tricks")
typedef int (^Lambda)();
# define lambda(RetType, Body) ^ RetType Body
#else
#pragma message("Using gcc specific tricks")
typedef int (*Lambda)();
# define lambda(RetType, Body) ({ RetType __fn__ Body __fn__; })
#endif
