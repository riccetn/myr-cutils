/*
 * Myr C Utils library
 *
 * Written 2015 by Rickard Närström <rickard@narstrom.se>
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
#include <unistd.h>

inline void NORETURN fatal_errno(int ec, const char *format, ...) {
	va_list ap;
	int errnum = errno;

	fprintf(stderr, "%s(%d) [FATAL] ", progname(), (int)getpid());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, ":%s (%d)\n", strerror(errnum), errnum);
	exit(ec);
}

inline void NORETURN fatal(int ec, const char *format, ...) {
	va_list ap;

	fprintf(stderr, "%s(%d) [FATAL] ", progname(), (int)getpid());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(ec);
}

inline void NORETURN bug_errno(const char *format, ...) {
	va_list ap;
	int errnum = errno;

	fprintf(stderr, "%s(%d) [BUG] ", progname(), (int)getpid());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, ":%s (%d)\n", strerror(errnum), errnum);
	abort();
}

inline void NORETURN bug(const char *format, ...) {
	va_list ap;

	fprintf(stderr, "%s(%d) [BUG] ", progname(), (int)getpid());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	abort();
}

inline void warn_errno(const char *format, ...) {
	va_list ap;
	int errnum = errno;

	fprintf(stderr, "%s(%d) [WARN] ", progname(), (int)getpid());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	fprintf(stderr, ":%s (%d)\n", strerror(errnum), errnum);
}

inline void warn(const char *format, ...) {
	va_list ap;

	fprintf(stderr, "%s(%d) [WARN] ", progname(), (int)getpid());
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
}

#endif
