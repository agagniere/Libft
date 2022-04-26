#pragma once

#define _ARGCNT1(...) _ARGCNT2(IGNORED, ##__VA_ARGS__, _ARGCNT4)
#define _ARGCNT2(...) _ARGCNT3(__VA_ARGS__)
#define _ARGCNT3(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,n,...) n
#define _ARGCNT4 30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define _PP_STR(M) #M
#define _PP_CAT(A, B) A##B

#define _FOLDI(F, ...) PP_CAT(_FOLDI_, ARG_COUNT(__VA_ARGS__))(F, __VA_ARGS__)

#define _FOLDI_1(F, A) A
#define _FOLDI_2(F, A, B) F(A, B)
#define _FOLDI_3(F, A, B, C) F(A, F(B, C))
#define _FOLDI_4(F, A, B, C, D) F(F(A, B), F(C, D))
#define _FOLDI_5(F, A, B, ...) F(F(A, B), _FOLDI_3(F, __VA_ARGS__))
#define _FOLDI_6(F, A, B, C, ...) F(_FOLDI_3(F, A, B, C), _FOLDI_3(F, __VA_ARGS__))
#define _FOLDI_7(F, A, B, C, ...) F(_FOLDI_3(F, A, B, C), _FOLDI_4(F, __VA_ARGS__))
#define _FOLDI_8(F, A, B, C, D, ...) F(_FOLDI_4(F, A, B, C, D), _FOLDI_4(F, __VA_ARGS__))
#define _FOLDI_9(F, A, B, C, D, ...) F(_FOLDI_4(F, A, B, C, D), _FOLDI_5(F, __VA_ARGS__))
#define _FOLDI_10(F, A, B, C, D, E, ...) F(_FOLDI_5(F, A, B, C, D, E), _FOLDI_5(F, __VA_ARGS__))

#define _MERGE(A, B) PP_CAT(A, PP_CAT(_, B))
