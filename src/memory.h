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
#ifndef MEMORY_H
#define MEMORY_H

#include "err.h"
#include <stdlib.h>

static inline void *xmalloc(size_t sz) {
	void *block = malloc(sz);
	if(!block)
		err(1, "xmalloc");
	return block;
}

static inline void *xcalloc(size_t nmemb, size_t sz) {
	void *block = calloc(nmemb, sz);
	if(!block)
		err(1, "xcalloc");
	return block;
}

static inline void *xrealloc(void *block, size_t sz) {
	void *nblock = realloc(block, sz);
	if(!nblock)
		err(1, "xrealloc");
	return nblock;
}

#endif
