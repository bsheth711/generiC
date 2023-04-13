/*
 * A generic dynamic list for C
 * 
 * declare_list(list_int, int);
 *
 * list_int * ints = new(list_int);
 * append(ints, 4);
 * remove(ints, 0);
 */
#include "mem.h"

#ifndef list
#define list

#define new(name) new_##name()

/*
   defines append 'function' for lists
   @param ls The list to be appended to
   @param val The value to be appended
*/
#define append(ls, val) do { \
	ls->arr[ls->size] = val; \
	++ls->size; \
	\
	if (ls->size == ls->capacity) { \
		safe_realloc(ls->arr, sizeof(ls->arr[0]) * ls->size * 2); \
		ls->capacity = ls->capacity * 2; \
	} \
} while(0)

/* 
   defines get function for lists
   @param ls The list to be queried
   @param idx The index to be retrieved
   @returns the 
*/
#define get(ls, idx) ls->arr[idx]

/* 
   defines remove call for lists
   @param ls The list from which an element will be removed
   @param idx The index of the element to remove
*/
#define remove(ls, idx) do { \
	if (ls->size == 0) { \
		error("removing from empty list"); \
	} \
	if (idx >= ls->size) { \
		error("removing out of bounds index"); \
	} \
	for (int i = idx; i < ls->size-1; ++i) { \
		ls->arr[i] = ls->arr[i+1]; \
	} \
	--ls->size; \
} while(0)

/* 
   defines size call for lists
   @param ls The list to be queried
   @returns The the number of elements in the list
*/ 
#define size(ls) ls->size

/* 
   defines insert call for lists
   @param ls The list that will be inserted into
   @param idx The index to insert the new value into
   @param val The new value to insert

*/
#define insert(ls, idx, val) do { \
	append(ls, ls->arr[ls->size-1]); \
	typeof(val) __prev_insert = val; \
	typeof(val) __tmp_insert; \
	for (int i = idx; i < ls->size-1; ++i) { \
		__tmp_insert = ls->arr[i]; \
		ls->arr[i] = __prev_insert; \
		__prev_insert = __tmp_insert; \
	} \
} while(0)

/* 
   defines struct and constructor for a new list type
   @param name The name for the new list type
   @param type The data type for the list
*/
#define declare_list(name, type) \
	\
	typedef struct name { \
		void* __resources[2]; \
		int capacity; \
		int size; \
		type* arr; \
	} name; \
	\
	name* new(name) { \
		name* ret; \
		safe_malloc(ret, sizeof(name)); \
		safe_malloc(ret->arr, sizeof(type) * 8); \
		ret->__resources[0] = ret->arr; \
		ret->__resources[1] = NULL; \
		ret->capacity = 8; \
		ret->size = 0; \
		return ret; \
	} 

#endif
