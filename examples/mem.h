/*
 * A file containing generally useful memory macros
 */
#include <stdlib.h>
#include <stdio.h>
#include "errors.h"

#ifndef mem
#define mem

#define safe_malloc(ptr, size) do { \
	ptr = malloc(size); \
	if (ptr == NULL) { \
		error("mallocing"); \
	} \
} while(0)

#define safe_realloc(ptr, size) do { \
	ptr = realloc(ptr, size); \
	if (ptr == NULL) { \
		error("reallocing"); \
	} \
} while(0)

#define safe_free(ptr) do { \
	free(ptr); \
	ptr = NULL; \
} while(0)

// a macro to free all the resouces of an object
#define destroy(ptr) do { \
	for (int i = 0; ptr->__resources[i] != NULL;) { \
		safe_free(ptr->__resources[i]); \
	} \
	safe_free(ptr); \
} while (0)

#endif
