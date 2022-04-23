#pragma once

#include "tools.h"

#define _FOR(N, ...) PP_CAT(_FOR_, N)(__VA_ARGS__)

#define _FOR_1(A, F, ...) \
    F(__VA_ARGS__, A)

#define _FOR_2(A, B, F, ...) \
    F(__VA_ARGS__, A) F(__VA_ARGS__, B)

#define _FOR_3(A, B, C, F, ...) \
    F(__VA_ARGS__, A) F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C)

#define _FOR_4(A, B, C, D, F, ...) \
    F(__VA_ARGS__, A) F(__VA_ARGS__, B) \
    F(__VA_ARGS__, C) F(__VA_ARGS__, D)

#define _FOR_5(A, B, C, D, E, F, ...) \
    _FOR_4(A, B, C, D, F, __VA_ARGS__) F(__VA_ARGS__, E)
#define _FOR_6(A, B, C, D, E, G, F, ...) \
    _FOR_5(A, B, C, D, E, F, __VA_ARGS__) F(__VA_ARGS__, G)
#define _FOR_7(A, B, C, D, E, G, H, F, ...) \
    _FOR_6(A, B, C, D, E, G, F, __VA_ARGS__) F(__VA_ARGS__, H)
#define _FOR_8(A, B, C, D, E, G, H, I, F, ...) \
    _FOR_7(A, B, C, D, E, G, H, F, __VA_ARGS__) F(__VA_ARGS__, I)
#define _FOR_9(A, B, C, D, E, G, H, I, J, F, ...) \
    _FOR_8(A, B, C, D, E, G, H, I, F, __VA_ARGS__) F(__VA_ARGS__, J)
#define _FOR_10(A, B, C, D, E, G, H, I, J, K, F, ...) \
    _FOR_9(A, B, C, D, E, G, H, I, J, F, __VA_ARGS__) F(__VA_ARGS__, K)
#define _FOR_11(A, B, C, D, E, G, H, I, J, K, L, F, ...) \
    _FOR_10(A, B, C, D, E, G, H, I, J, K, F, __VA_ARGS__) F(__VA_ARGS__, L)
#define _FOR_12(A, B, C, D, E, G, H, I, J, K, L, M, F, ...) \
    _FOR_11(A, B, C, D, E, G, H, I, J, K, L, F, __VA_ARGS__) F(__VA_ARGS__, M)
#define _FOR_13(A, B, C, D, E, G, H, I, J, K, L, M, N, F, ...) \
    _FOR_12(A, B, C, D, E, G, H, I, J, K, L, M, F, __VA_ARGS__) F(__VA_ARGS__, N)
#define _FOR_14(A, B, C, D, E, G, H, I, J, K, L, M, N, O, F, ...) \
    _FOR_13(A, B, C, D, E, G, H, I, J, K, L, M, N, F, __VA_ARGS__) F(__VA_ARGS__, O)
#define _FOR_15(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, F, ...) \
    _FOR_14(A, B, C, D, E, G, H, I, J, K, L, M, N, O, F, __VA_ARGS__) F(__VA_ARGS__, P)
#define _FOR_16(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, F, ...) \
    _FOR_15(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, F, __VA_ARGS__) F(__VA_ARGS__, Q)
#define _FOR_17(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, R, F, ...) \
    _FOR_16(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, F, __VA_ARGS__) F(__VA_ARGS__, R)
#define _FOR_18(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, R, S, F, ...) \
    _FOR_17(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, R, F, __VA_ARGS__) F(__VA_ARGS__, S)
#define _FOR_19(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, F, ...) \
    _FOR_18(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, R, S, F, __VA_ARGS__) F(__VA_ARGS__, T)
#define _FOR_20(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, F, ...) \
    _FOR_19(A, B, C, D, E, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, F, __VA_ARGS__) F(__VA_ARGS__, U)
