#pragma once

#include <stddef.h>

size_t fnv1a_32(char* string, size_t length);
size_t fnv1a_64(char* string, size_t length);
size_t djb2a(char* string, size_t length);
size_t djb2(char* string, size_t length);
size_t sdbm(char* string, size_t length);
