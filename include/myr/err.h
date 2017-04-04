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
#ifndef MYR_ERR_H
#define MYR_ERR_H
/**
 * \file myr/err.h
 */

#include "compiler.h"

/**
 * \fn void NORETURN fatal(int ec, const char *format, ...)
 * \brief Print a error message and exit.
 *
 * Prints an error message to \c stderr and exit. The error message
 * printed will include the message specefied.
 *
 * \param ec exit code
 * \param format printf-style format string
 * \param ... parameters for format string
 */
inline void NORETURN fatal(int ec, const char *format, ...) FORMAT(printf, 2, 3);

/**
 * \fn void NORETURN fatal_errno(int ec, const char *format, ...)
 * \brief Print a error message and exit.
 *
 * Prints an error message to \c stderr and exit. The error message
 * printed will include the message specefied and a message indicating the current
 * \c errno.
 *
 * \param ec exit code
 * \param format printf-style format string
 * \param ... parameters for format string
 */
inline void NORETURN fatal_errno(int ec, const char *format, ...) FORMAT(printf, 2, 3);

/**
 * \fn void NORETURN bug(const char *format, ...)
 * \brief Print a error message and core dump.
 *
 * Prints an error message to \c stderr and core dump. The error
 * message will include the message specefied.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 */
inline void NORETURN bug(const char *format, ...) FORMAT(printf, 1, 2);

/**
 * \fn void NORETURN bug_errno(const char *format, ...)
 * \brief Print a error message and core dump.
 *
 * Prints an error message to \c stderr and core dump. The error
 * message will include the message specefied and a message indicateg the current
 * \c errno.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 */
inline void NORETURN bug_errno(const char *format, ...) FORMAT(printf, 1, 2);

/**
 * \fn void warn(const char *format, ...)
 * \brief Print a error message.
 *
 * Prints an error message to \c stderr. The error
 * message will include the message specefied.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 */
inline void warn(const char *format, ...) FORMAT(printf, 1, 2);

/**
 * \fn void warn_errno(const char *format, ...)
 * \brief Print a error message.
 *
 * Prints an error message to \c stderr. The error message will
 * include the message specefied and a message indicateg the current
 * \c errno.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 */
inline void warn_errno(const char *format, ...) FORMAT(printf, 1, 2);

#ifndef MYR_NO_INLINE_INCLUDE
# include "inline/err.h"
#endif

#undef INLINE

#endif
