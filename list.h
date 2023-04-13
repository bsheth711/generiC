/*
 * A generic dynamic list for C
 * 
 * declare_list(list_int, int);
 *
 * list(int)* ints = new_list(int);
 * append(ints, 4);
 */
#include "mem.h"

#ifndef list
#define list

#define new(name) new_##name()

// defines append 'function' for lists
#define append(ls, val) \
	ls->arr[ls->size] = val; \
	ls->size++; \
	\
	if (ls->size == ls->capacity) { \
		safe_realloc(ls->arr, sizeof(ls->arr[0]) * ls->size * 2); \
		ls->capacity++; \
	}

// defines structure and type of declared list types
#define declare_list(name, type) \
	\
	typedef struct name { \
		int capacity; \
		int size; \
		type* arr; \
	} name; \
	\
	name* new(name) { \
		name* ret; \
		safe_malloc(ret, sizeof(name)); \
		safe_malloc(ret->arr, sizeof(type) * 8); \
		ret->capacity = 8; \
		ret->size = 0; \
		return ret; \
	} 

#endif
