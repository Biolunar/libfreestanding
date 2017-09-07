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

#include "libfreestanding/byteorder.h"

extern uint16_t fs_u16_from_le(unsigned char data[static 2]);
extern uint32_t fs_u32_from_le(unsigned char data[static 4]);
extern uint64_t fs_u64_from_le(unsigned char data[static 8]);
extern uint16_t fs_u16_from_be(unsigned char data[static 2]);
extern uint32_t fs_u32_from_be(unsigned char data[static 4]);
extern uint64_t fs_u64_from_be(unsigned char data[static 8]);
