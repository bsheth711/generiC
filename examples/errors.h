#ifndef errors
#define errors

#define MEMORY_ERROR 1

#define error(msg) do { \
	fprintf(stderr, "Error: %s: in %s, on line %d\n", msg, __FILE__, __LINE__); \
	fflush(stderr); \
	exit(MEMORY_ERROR); \
} while(0)

#endif
