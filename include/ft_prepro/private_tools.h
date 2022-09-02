#pragma once

#define _ARGCNT1(...) _ARGCNT2(IGNORED, ##__VA_ARGS__, _ARGCNT4)
#define _ARGCNT2(...) _ARGCNT3(__VA_ARGS__)
#define _ARGCNT3(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,n,...) n
#define _ARGCNT4 30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define _PP_STR(M) #M
#define _PP_CAT(A, B) A##B
#define _MERGE(A, B) PP_CAT(A, PP_CAT(_, B))
#define _GREATER(A, B) A > B
#define _LESSER(A, B) A < B

#define _FOLDR(F, ...) PP_CAT(_FOLDR_, ARG_COUNT(__VA_ARGS__))(F, __VA_ARGS__)
#define _MINMAX(CMP, ...) PP_CAT(_MINMAX_, ARG_COUNT(__VA_ARGS__))(CMP, __VA_ARGS__)

/* MIN and MAX can be implemented with FOLD_RIGHT, but I wanted to have this balanced implementation, even if it makes no difference after compilation */
#define _MINMAX_1(CMP, A) A
#define _MINMAX_2(CMP, A, B) (CMP(A,B) ? A : B)
#define _MINMAX_3(CMP, A, B, C) (CMP(A, B) ? _MINMAX_2(CMP, A, C) : _MINMAX_2(CMP, B, C))
#define _MINMAX_4(CMP, A, B, ...) (CMP(A, B) ? _MINMAX_3(CMP, A, __VA_ARGS__) : _MINMAX_3(CMP, B, __VA_ARGS__))
#define _MINMAX_5(CMP, A, B, ...) (CMP(A, B) ? _MINMAX_4(CMP, A, __VA_ARGS__) : _MINMAX_4(CMP, B, __VA_ARGS__))
#define _MINMAX_6(CMP, A, B, ...) (CMP(A, B) ? _MINMAX_5(CMP, A, __VA_ARGS__) : _MINMAX_5(CMP, B, __VA_ARGS__))
#define _MINMAX_7(CMP, A, B, ...) (CMP(A, B) ? _MINMAX_6(CMP, A, __VA_ARGS__) : _MINMAX_6(CMP, B, __VA_ARGS__))
#define _MINMAX_8(CMP, A, B, ...) (CMP(A, B) ? _MINMAX_7(CMP, A, __VA_ARGS__) : _MINMAX_7(CMP, B, __VA_ARGS__))

#define _FOLDR_1(F, A) A
#define _FOLDR_2(F, A, B) F(A, B)
#define _FOLDR_3(F, A, B, C) F(A, F(B, C))
#define _FOLDR_4(F, A, B, C, D) F(A, F(B, F(C, D)))
#define _FOLDR_5(F, HEAD, ...) F(HEAD, _FOLDR_4(F, __VA_ARGS__))
#define _FOLDR_6(F, HEAD, ...) F(HEAD, _FOLDR_5(F, __VA_ARGS__))
#define _FOLDR_7(F, HEAD, ...) F(HEAD, _FOLDR_6(F, __VA_ARGS__))
#define _FOLDR_8(F, HEAD, ...) F(HEAD, _FOLDR_7(F, __VA_ARGS__))
#define _FOLDR_9(F, HEAD, ...) F(HEAD, _FOLDR_8(F, __VA_ARGS__))
#define _FOLDR_10(F, HEAD, ...) F(HEAD, _FOLDR_9(F, __VA_ARGS__))
#define _FOLDR_11(F, HEAD, ...) F(HEAD, _FOLDR_10(F, __VA_ARGS__))
#define _FOLDR_12(F, HEAD, ...) F(HEAD, _FOLDR_11(F, __VA_ARGS__))
#define _FOLDR_13(F, HEAD, ...) F(HEAD, _FOLDR_12(F, __VA_ARGS__))
#define _FOLDR_14(F, HEAD, ...) F(HEAD, _FOLDR_13(F, __VA_ARGS__))
#define _FOLDR_15(F, HEAD, ...) F(HEAD, _FOLDR_14(F, __VA_ARGS__))
#define _FOLDR_16(F, HEAD, ...) F(HEAD, _FOLDR_15(F, __VA_ARGS__))
