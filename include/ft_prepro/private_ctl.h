#pragma once

#include "tools.h"

#define _FOR(N, ...) PP_CAT(_FOR_, N)(__VA_ARGS__)

#define _FOR_1(A, F, ...) F(__VA_ARGS__, A)

#define _FOR_2(A, B, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B)

#define _FOR_3(A, B, C, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C)

#define _FOR_4(A, B, C, D, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D)

#define _FOR_5(A, B, C, D, E, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E)

#define _FOR_6(A, B, C, D, E, G, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G)

#define _FOR_7(A, B, C, D, E, G, H, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G) \
    F(__VA_ARGS__, H)

#define _FOR_8(A, B, C, D, E, G, H, I, F, ...)    \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G) \
    F(__VA_ARGS__, H) \
    F(__VA_ARGS__, I)

#define _FOR_9(A, B, C, D, E, G, H, I, J, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G) \
    F(__VA_ARGS__, H) \
    F(__VA_ARGS__, I) \
    F(__VA_ARGS__, J)

#define _FOR_10(A, B, C, D, E, G, H, I, J, K, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G) \
    F(__VA_ARGS__, H) \
    F(__VA_ARGS__, I) \
    F(__VA_ARGS__, J) \
    F(__VA_ARGS__, K)

#define _FOR_11(A, B, C, D, E, G, H, I, J, K, L, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G) \
    F(__VA_ARGS__, H) \
    F(__VA_ARGS__, I) \
    F(__VA_ARGS__, J) \
    F(__VA_ARGS__, K) \
    F(__VA_ARGS__, L)

#define _FOR_12(A, B, C, D, E, G, H, I, J, K, L, M, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G) \
    F(__VA_ARGS__, H) \
    F(__VA_ARGS__, I) \
    F(__VA_ARGS__, J) \
    F(__VA_ARGS__, K) \
    F(__VA_ARGS__, L) \
    F(__VA_ARGS__, M)

#define _FOR_13(A, B, C, D, E, G, H, I, J, K, L, M, N, F, ...) \
    F(__VA_ARGS__, A) \
    F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) \
    F(__VA_ARGS__, D) \
    F(__VA_ARGS__, E) \
    F(__VA_ARGS__, G) \
    F(__VA_ARGS__, H) \
    F(__VA_ARGS__, I) \
    F(__VA_ARGS__, J) \
    F(__VA_ARGS__, K) \
    F(__VA_ARGS__, L) \
    F(__VA_ARGS__, M) \
    F(__VA_ARGS__, N)
