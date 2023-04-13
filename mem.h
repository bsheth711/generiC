/*
 * A file containing generally useful memory functions.
 */
#include <stdlib.h>

#ifndef mem
#define mem

#define safe_malloc(ptr, size) \
	ptr = malloc(size); \
	if (ptr == NULL) { \
		exit(1); \
	}

#define safe_realloc(ptr, size) \
	ptr = realloc(ptr, size); \
	if (ptr == NULL) { \
		exit(1); \
	}

#endif
