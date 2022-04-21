#pragma once

#define overload_0(x, name) \
  (void)0

#define overload_1(x, name, A)                  \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (typeof (x), A), \
    name(A) (x), \
    (void)0 \
  )

#define overload_2(x, name, A, B) \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (typeof (x), A), \
    name(A) (x), \
    __builtin_choose_expr ( \
      __builtin_types_compatible_p (typeof (x), B), \
      name(B) (x), \
      (void)0 \
    ) \
  )

#define overload_3(x, name, A, B, C) \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (typeof (x), A), \
    name(A) (x), \
    __builtin_choose_expr ( \
      __builtin_types_compatible_p (typeof (x), B), \
      name(B) (x), \
      __builtin_choose_expr ( \
        __builtin_types_compatible_p (typeof (x), C), \
        name(C) (x), \
        (void)0 \
      ) \
    ) \
  )

#define overload_4(x, name, A, B, C, D) \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (typeof (x), A), \
    name(A) (x), \
    __builtin_choose_expr ( \
      __builtin_types_compatible_p (typeof (x), B), \
      name(B) (x), \
      __builtin_choose_expr ( \
        __builtin_types_compatible_p (typeof (x), C), \
        name(C) (x), \
        __builtin_choose_expr ( \
          __builtin_types_compatible_p (typeof (x), D), \
          name(D) (x), \
          (void)0 \
        ) \
      ) \
    ) \
  )

#define overload_5(x, name, A, B, C, D, E) \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (typeof (x), A), \
    name(A) (x), \
    __builtin_choose_expr ( \
      __builtin_types_compatible_p (typeof (x), B), \
      name(B) (x), \
      __builtin_choose_expr ( \
        __builtin_types_compatible_p (typeof (x), C), \
        name(C) (x), \
        __builtin_choose_expr ( \
          __builtin_types_compatible_p (typeof (x), D), \
          name(D) (x), \
          __builtin_choose_expr ( \
            __builtin_types_compatible_p (typeof (x), E), \
            name(E) (x), \
            (void)0 \
          ) \
        ) \
      ) \
    ) \
  )

#define overload_6(x, name, A, B, C, D, E, F) \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (typeof (x), A), \
    name(A) (x), \
    __builtin_choose_expr ( \
      __builtin_types_compatible_p (typeof (x), B), \
      name(B) (x), \
      __builtin_choose_expr ( \
        __builtin_types_compatible_p (typeof (x), C), \
        name(C) (x), \
        __builtin_choose_expr ( \
          __builtin_types_compatible_p (typeof (x), D), \
          name(D) (x), \
          __builtin_choose_expr ( \
            __builtin_types_compatible_p (typeof (x), E), \
            name(E) (x), \
            __builtin_choose_expr ( \
              __builtin_types_compatible_p (typeof (x), F), \
              name(F) (x), \
              (void)0 \
            ) \
          ) \
        ) \
      ) \
    ) \
  )

#define overload_7(x, name, A, B, C, D, E, F, G) \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (typeof (x), A), \
    name(A) (x), \
    __builtin_choose_expr ( \
      __builtin_types_compatible_p (typeof (x), B), \
      name(B) (x), \
      __builtin_choose_expr ( \
        __builtin_types_compatible_p (typeof (x), C), \
        name(C) (x), \
        __builtin_choose_expr ( \
          __builtin_types_compatible_p (typeof (x), D), \
          name(D) (x), \
          __builtin_choose_expr ( \
            __builtin_types_compatible_p (typeof (x), E), \
            name(E) (x), \
            __builtin_choose_expr ( \
              __builtin_types_compatible_p (typeof (x), F), \
              name(F) (x), \
              __builtin_choose_expr ( \
                __builtin_types_compatible_p (typeof (x), G), \
                name(G) (x), \
                (void)0 \
              ) \
            ) \
          ) \
        ) \
      ) \
    ) \
  )
