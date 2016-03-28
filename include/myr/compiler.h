/*
 * Myr C Utils library
 *
 * Written 2015 by Rickard Närström <rickard@narstrom.se>
 *
 * To the extent possible under law, the author(s) have dedicated all copyright
 * and related and neighboring rights to this software to the public domain worldwide.
 * This software is distributed without any warranty.
 *
 * You should have received a copy of the CC0 Public Domain Dedication along
 * with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */
#ifndef MYR_COMPILER_H
#define MYR_COMPILER_H

#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#if defined(__GNUC__) || __has_attribute(noreturn)
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
