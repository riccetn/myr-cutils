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
#include "progname.h"
#include "progname_main.h"

static const char *local_progname = "unknown_progname";

const char *progname(void) {
	return local_progname;
}

void set_progname(const char *pn) {
	local_progname = pn;
}
