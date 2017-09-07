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

#ifndef HEADER_LIBFREESTANDING_BYTEORDER_H_INCLUDED
#define HEADER_LIBFREESTANDING_BYTEORDER_H_INCLUDED

#include <stdint.h>

inline uint16_t fs_u16_from_le(unsigned char data[const static 2])
{
	return (uint16_t)(((uint16_t)data[0] <<  0) |
	                  ((uint16_t)data[1] <<  8));
}

inline uint32_t fs_u32_from_le(unsigned char data[const static 4])
{
	return (uint32_t)(((uint32_t)data[0] <<  0) |
	                  ((uint32_t)data[1] <<  8) |
	                  ((uint32_t)data[2] << 16) |
	                  ((uint32_t)data[3] << 24));
}

inline uint64_t fs_u64_from_le(unsigned char data[const static 8])
{
	return (uint64_t)(((uint64_t)data[0] <<  0) |
	                  ((uint64_t)data[1] <<  8) |
	                  ((uint64_t)data[2] << 16) |
	                  ((uint64_t)data[3] << 24) |
	                  ((uint64_t)data[4] << 32) |
	                  ((uint64_t)data[5] << 40) |
	                  ((uint64_t)data[6] << 48) |
	                  ((uint64_t)data[7] << 56));
}

inline uint16_t fs_u16_from_be(unsigned char data[const static 2])
{
	return (uint16_t)(((uint16_t)data[1] <<  0) |
	                  ((uint16_t)data[0] <<  8));
}

inline uint32_t fs_u32_from_be(unsigned char data[const static 4])
{
	return (uint32_t)(((uint32_t)data[3] <<  0) |
	                  ((uint32_t)data[2] <<  8) |
	                  ((uint32_t)data[1] << 16) |
	                  ((uint32_t)data[0] << 24));
}

inline uint64_t fs_u64_from_be(unsigned char data[const static 8])
{
	return (uint64_t)(((uint64_t)data[7] <<  0) |
	                  ((uint64_t)data[6] <<  8) |
	                  ((uint64_t)data[5] << 16) |
	                  ((uint64_t)data[4] << 24) |
	                  ((uint64_t)data[3] << 32) |
	                  ((uint64_t)data[2] << 40) |
	                  ((uint64_t)data[1] << 48) |
	                  ((uint64_t)data[0] << 56));
}

#endif // !HEADER_LIBFREESTANDING_BYTEORDER_H_INCLUDED
