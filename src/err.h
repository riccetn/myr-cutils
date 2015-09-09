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
#ifndef ERR_H
#define ERR_H

#include "compiler.h"

void NORETURN err(int ec, const char *format, ...) FORMAT(printf, 2, 3);
void NORETURN xerr(int ec, const char *format, ...) FORMAT(printf, 2, 3);
void warn(const char *format, ...) FORMAT(printf, 1, 2);
void xwarn(const char *format, ...) FORMAT(printf, 1, 2);

#endif
