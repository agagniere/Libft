#pragma once

#include "ft_prepro.h"

#define _FOR(N, ...) CAT(_FOR_, N)(__VA_ARGS__)

#define _FOR_1(A, F, ...) F(A, ##__VA_ARGS__),

#define _FOR_2(A, B, F, ...) \
      F(A, ##__VA_ARGS__),   \
      F(B, ##__VA_ARGS__),

#define _FOR_3(A, B, C, F, ...) \
      F(A, ##__VA_ARGS__),   \
      F(B, ##__VA_ARGS__),   \
      F(C, ##__VA_ARGS__),

#define _FOR_4(A, B, C, D, F, ...) \
      F(A, ##__VA_ARGS__),   \
      F(B, ##__VA_ARGS__),   \
      F(C, ##__VA_ARGS__),   \
      F(D, ##__VA_ARGS__),

#define _FOR_5(A, B, C, D, E, F, ...)                              \
    F(A, ##__VA_ARGS__), F(B, ##__VA_ARGS__), F(C, ##__VA_ARGS__), \
    F(D, ##__VA_ARGS__), F(E, ##__VA_ARGS__),

#define _FOR_6(A, B, C, D, E, G, F, ...)                           \
    F(A, ##__VA_ARGS__), F(B, ##__VA_ARGS__), F(C, ##__VA_ARGS__), \
    F(D, ##__VA_ARGS__), F(E, ##__VA_ARGS__), F(G, ##__VA_ARGS__),

#define _FOR_7(A, B, C, D, E, G, H, F, ...)                        \
    F(A, ##__VA_ARGS__), F(B, ##__VA_ARGS__), F(C, ##__VA_ARGS__), \
    F(D, ##__VA_ARGS__), F(E, ##__VA_ARGS__), F(G, ##__VA_ARGS__), \
    F(H, ##__VA_ARGS__),

#define _FOR_8(A, B, C, D, E, G, H, I, F, ...)                     \
    F(A, ##__VA_ARGS__), F(B, ##__VA_ARGS__), F(C, ##__VA_ARGS__), \
    F(D, ##__VA_ARGS__), F(E, ##__VA_ARGS__), F(G, ##__VA_ARGS__), \
    F(H, ##__VA_ARGS__), F(I, ##__VA_ARGS__),

#define _FOR_9(A, B, C, D, E, G, H, I, J, F, ...)                  \
    F(A, ##__VA_ARGS__), F(B, ##__VA_ARGS__), F(C, ##__VA_ARGS__), \
    F(D, ##__VA_ARGS__), F(E, ##__VA_ARGS__), F(G, ##__VA_ARGS__), \
    F(H, ##__VA_ARGS__), F(I, ##__VA_ARGS__), F(J, ##__VA_ARGS__),

#define _FOR_10(A, B, C, D, E, G, H, I, J, K, F, ...)              \
    F(A, ##__VA_ARGS__), F(B, ##__VA_ARGS__), F(C, ##__VA_ARGS__), \
    F(D, ##__VA_ARGS__), F(E, ##__VA_ARGS__), F(G, ##__VA_ARGS__), \
    F(H, ##__VA_ARGS__), F(I, ##__VA_ARGS__), F(J, ##__VA_ARGS__), \
    F(K, ##__VA_ARGS__),
