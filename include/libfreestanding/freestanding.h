/*
 * Copyright 2017 Mahdi Khanalizadeh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HEADER_LIBFREESTANDING_FREESTANDING_H_INCLUDED
#define HEADER_LIBFREESTANDING_FREESTANDING_H_INCLUDED

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

size_t strlen(char const* s);
bool streq(char const* s1, char const* s2);
void strrev(char* str, size_t n);
bool itoa(char* buffer, size_t len, uintmax_t i);

// From the standard library
char* strcpy(char* restrict s1, char const* restrict s2);
char* strncpy(char* restrict s1, char const* restrict s2, size_t n);
char* strcat(char* restrict s1, char const* restrict s2);
char* strncat(char* restrict s1, char const* restrict s2, size_t n);

// Mandatory
int memcmp(void const* s1, void const* s2, size_t n);
void* memset(void* s, int c, size_t n);
void* memcpy(void* restrict s1, void const* restrict s2, size_t n);
void* memmove(void* s1, void const* s2, size_t n);

#endif // !HEADER_LIBFREESTANDING_FREESTANDING_H_INCLUDED
