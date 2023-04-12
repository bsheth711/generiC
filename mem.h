/*
 * A file containing generally useful memory functions.
 */
#include <stdlib.h>

#ifndef mem
#define mem

#define safe_malloc(ptr, size) malloc(size); \
	if (ptr == NULL) { \
		exit(1); \
	}

#endif
