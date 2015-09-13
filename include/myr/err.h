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
/**
 * \file myr/err.h
 */

#include "compiler.h"

/**
 * \fn void NORETURN fatal(int ec, const char *format, ...)
 * \brief Print a error message and exit.
 *
 * Prints an error message to <code>stderr</code> and exit. The error message
 * printed will include the message specefied.
 *
 * \param ec exit code
 * \param format printf-style format string
 * \param ... parameters for format string
 * \return This function never returns
 */
void NORETURN fatal(int ec, const char *format, ...) FORMAT(printf, 2, 3);

/**
 * \fn void NORETURN fatal_errno(int ec, const char *format, ...)
 * \brief Print a error message and exit.
 *
 * Prints an error message to <code>stderr</code> and exit. The error message
 * printed will include the message specefied and a message indicating the current
 * <code>errno</code>.
 *
 * \param ec exit code
 * \param format printf-style format string
 * \param ... parameters for format string
 * \return This function never returns
 */
void NORETURN fatal_errno(int ec, const char *format, ...) FORMAT(printf, 2, 3);

/**
 * \fn void NORETURN bug(const char *format, ...)
 * \brief Print a error message and core dump.
 *
 * Prints an error message to <code>stderr</code> and core dump. The error
 * message will include the message specefied.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 * \return This function never returns
 */
void NORETURN bug(const char *format, ...) FORMAT(printf, 1, 2);

/**
 * \fn void NORETURN bug_errno(const char *format, ...)
 * \brief Print a error message and core dump.
 *
 * Prints an error message to <code>stderr</code> and core dump. The error
 * message will include the message specefied and a message indicateg the current
 * <code>errno</code>.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 * \return This function never returns
 */
void NORETURN bug_errno(const char *format, ...) FORMAT(printf, 1, 2);

/**
 * \fn void warn(const char *format, ...)
 * \brief Print a error message.
 *
 * Prints an error message to <code>stderr</code>. The error
 * message will include the message specefied.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 */
void warn(const char *format, ...) FORMAT(printf, 1, 2);

/**
 * \fn void warn_errno(const char *format, ...)
 * \brief Print a error message.
 *
 * Prints an error message to <code>stderr</code>. The error message will
 * include the message specefied and a message indicateg the current
 * <code>errno</code>.
 *
 * \param format printf-style format string
 * \param ... parameters for format string
 */
void warn_errno(const char *format, ...) FORMAT(printf, 1, 2);

#endif
