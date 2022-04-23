#pragma once

#define _ARGCNT1(...) _ARGCNT2(IGNORED, ##__VA_ARGS__, _ARGCNT4)
#define _ARGCNT2(...) _ARGCNT3(__VA_ARGS__)
#define _ARGCNT3(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,n,...) n
#define _ARGCNT4 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define _PP_STR(M) #M
#define _PP_CAT(A, B) A##B

#define _MIN1(A)         (A)
#define _MIN2(A, B)      ((A) < (B) ? (A) : (B))
#define _MIN3(A, B, C)   ((A) < (B) ? _MIN2(A, C) : _MIN2(B, C))
#define _MIN4(A, B, ...) ((A) < (B) ? _MIN3(A, __VA_ARGS__) : _MIN3(B, __VA_ARGS__))
#define _MIN5(A, B, ...) ((A) < (B) ? _MIN4(A, __VA_ARGS__) : _MIN4(B, __VA_ARGS__))
#define _MIN6(A, B, ...) ((A) < (B) ? _MIN5(A, __VA_ARGS__) : _MIN5(B, __VA_ARGS__))
#define _MIN7(A, B, ...) ((A) < (B) ? _MIN6(A, __VA_ARGS__) : _MIN6(B, __VA_ARGS__))

#define _MAX1(A)         (A)
#define _MAX2(A, B)      ((A) > (B) ? (A) : (B))
#define _MAX3(A, B, C)   ((A) > (B) ? _MAX2(A, C) : _MAX2(B, C))
#define _MAX4(A, B, ...) ((A) > (B) ? _MAX3(A, __VA_ARGS__) : _MAX3(B, __VA_ARGS__))
#define _MAX5(A, B, ...) ((A) > (B) ? _MAX4(A, __VA_ARGS__) : _MAX4(B, __VA_ARGS__))
#define _MAX6(A, B, ...) ((A) > (B) ? _MAX5(A, __VA_ARGS__) : _MAX5(B, __VA_ARGS__))
#define _MAX7(A, B, ...) ((A) > (B) ? _MAX6(A, __VA_ARGS__) : _MAX6(B, __VA_ARGS__))
