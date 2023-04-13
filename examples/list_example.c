// list example file
#include <stdio.h>
#include "list_example.h"

int main() {
	list_int* ints = new(list_int);
	append(ints, 5);
	append(ints, 3);

	list_char* chars = new(list_char);
	append(chars, 'a');
	append(chars, 'c');
	insert(chars, 1, 'b');

	strings* strs = new(strings);
	append(strs, "hello");
	append(strs, "world");
	append(strs, "!");
	get(strs, 0) = "bye bye";

	for (int i = 0; i < size(ints); ++i) {
		printf("ints: %i: %i\n", i, get(ints, i));
	}
	for (int i = 0; i < size(chars); ++i) {
		printf("chars: %i: %c\n", i, get(chars, i));
	}
	for (int i = 0; i < size(strs); ++i) {
		printf("strs: %i: %s\n", i, get(strs, i));
	}
	destroy(strs);
	destroy(chars);
	destroy(ints);
}
