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
#ifndef MYR_INLINE_ERR_H
#define MYR_INLINE_ERR_H

#ifndef MYR_ERR_H
# error "Don't include <myr/inline/err.h> directly, include <myr/err.h>"
#endif

#include "../progname.h"

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void NORETURN fatal_errno(int ec, const char *format, ...) {
	va_list ap;
	int errnum = errno;

	fprintf(stderr, "%s:", progname());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, ":%s (%d)\n", strerror(errnum), errnum);
	exit(ec);
}

inline void NORETURN fatal(int ec, const char *format, ...) {
	va_list ap;

	fprintf(stderr, "%s:", progname());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(ec);
}

inline void NORETURN bug_errno(const char *format, ...) {
	va_list ap;
	int errnum = errno;

	fprintf(stderr, "%s:", progname());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, ":%s (%d)\n", strerror(errnum), errnum);
	abort();
}

inline void NORETURN bug(const char *format, ...) {
	va_list ap;

	fprintf(stderr, "%s:", progname());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	abort();
}

inline void warn_errno(const char *format, ...) {
	va_list ap;
	int errnum = errno;

	fprintf(stderr, "%s:", progname());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, ":%s (%d)\n", strerror(errnum), errnum);
}

inline void warn(const char *format, ...) {
	va_list ap;

	fprintf(stderr, "%s:", progname());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
}

#endif
