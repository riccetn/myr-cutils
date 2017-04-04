/*
 * Myr C Utils library
 *
 * Written 2015, 2017 by Rickard Närström <rickard@narstrom.se>
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef MYR_COMPILER_H
#define MYR_COMPILER_H

#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#if __STDC_VERSION__ >= 201112L
# include <stdnoreturn.h>
# define NORETURN noreturn
#elif defined(__GNUC__) || __has_attribute(noreturn)
# define NORETURN __attribute__((noreturn))
#else
# define NORETURN
#endif

#if defined(__GNUC__) || __has_attribute(format)
# define FORMAT(archtype, string_index, first_to_check) __attribute__((format(archtype, string_index, first_to_check)))
#else
# define FORMAT(archtype, string_index, first_to_check)
#endif

#endif
