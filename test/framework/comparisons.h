#pragma once

#include <stdbool.h>

bool compare_int(int a, int b);
bool compare_float(float a, float b);
bool compare_int_sign(int a, int b);
bool compare_str(const char* a, const char* b);
int  unsigned_spaceship_ascending(const unsigned* a, const unsigned* b);
int  unsigned_spaceship_descending(const unsigned* a, const unsigned* b);
int  int_spaceship_ascending(const int* a, const int* b);
int  int_spaceship_descending(const int* a, const int* b);
