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

#include "libfreestanding/freestanding.h"

size_t strlen(char const* s)
{
	size_t ret = 0;
	while (*s++)
		++ret;
	return ret;
}

bool streq(char const* s1, char const* s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return false;
		++s1;
		++s2;
	}
	return !(*s2);
}

void strrev(char* s, size_t n)
{
	if (!n)
		return;

	size_t pos = n/2;
	--n;
	while (pos)
	{
		--pos;
		char const temp = s[pos];
		s[pos] = s[n-pos];
		s[n-pos] = temp;
		if (!pos)
			break;
	}
}

bool itoa(char* buffer, size_t len, uintmax_t i)
{
	char const nums[] = "0123456789";
	if (!buffer || !len || len == 1)
		return false;

	buffer[--len] = 0; // null termination
	size_t pos = 0;
	while (len)
	{
		buffer[pos] = nums[i % 10];
		++pos;
		--len;
		i /= 10;
		if (!i)
		{
			buffer[pos] = 0;
			strrev(buffer, pos);
			return true;
		}
	}
	return false;
}

char* strcpy(char* restrict s1, char const* restrict s2)
{
	char* const ret = s1;
	do
	{
		*s1 = *s2;
		++s1;
		++s2;
	} while (*s2);
	return ret;
}

char* strncpy(char* const restrict s1, char const* const restrict s2, size_t const n)
{
	char c = *s2;
	for (size_t i = 0; i < n; ++i)
	{
		s1[i] = c;
		if (c)
			c = s2[i];
	}
	return s1;
}

char* strcat(char* const restrict s1, char const* restrict s2)
{
	size_t i = strlen(s1);
	while (1)
	{
		s1[i] = *s2;
		if (!*s2)
			break;
		++s2;
		++i;
	}
	return s1;
}

char* strncat(char* const restrict s1, char const* restrict s2, size_t const n)
{
	size_t const len = strlen(s1);
	size_t i = len;
	for (; i < (len + n); ++i)
	{
		if (*s2)
			s1[i] = *s2;
		else
			break;
		++s2;
	}
	s1[i] = 0;
	return s1;
}

int memcmp(void const* const s1, void const* const s2, size_t const n)
{
	unsigned char const* const c1 = s1;
	unsigned char const* const c2 = s2;

	for (size_t i = 0; i < n; ++i)
	{
		if (*(c1 + i) == *(c2 + i))
			continue;
		else
			return *(c1 + i) - *(c2 + i);
	}
	return 0;
}

void* memset(void* s, int c, size_t n)
{
	char* const dest = s;
	while (n)
		dest[--n] = (char)c;
	return s;
}

void* memcpy(void* restrict s1, void const* restrict s2, size_t n)
{
	size_t pos = 0;
	while (pos < n)
	{
		((char*)s1)[pos] = ((char const*)s2)[pos];
		++pos;
	}
	return s1;
}

void* memmove(void* s1, void const* s2, size_t n)
{
	if (s1 == s2)
		return s1;
	else if (s1 < s2)
		return memcpy(s1, s2, n);

	while (n--)
		((char*)s1)[n] = ((char const*)s2)[n];
	return s1;
}
