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

#ifndef HEADER_LIBFREESTANDING_ABS_H_INCLUDED
#define HEADER_LIBFREESTANDING_ABS_H_INCLUDED

#define FS_ABS(value) ((value) < 0 ? -(value) : (value))

inline signed char fs_abs_schar(signed char const value)
{
	return FS_ABS(value);
}

inline short fs_abs_short(short const value)
{
	return FS_ABS(value);
}

inline int fs_abs_int(int const value)
{
	return FS_ABS(value);
}

inline long fs_abs_long(long const value)
{
	return FS_ABS(value);
}

inline long long fs_abs_long_long(long long const value)
{
	return FS_ABS(value);
}

#ifdef FS_GENERIC
#define fs_abs(value) _Generic((value),                     \
                                signed char: fs_abs_schar,  \
                                short: fs_abs_short,        \
                                int: fs_abs_int,            \
                                long: fs_abs_long,          \
                                long long: fs_abs_long_long \
                               )(value)
#endif // FS_GENERIC

#endif // !HEADER_LIBFREESTANDING_ABS_H_INCLUDED
