# generiC
## Overall Goal
Implement a library of generic classes in C.
## Key Requirements
### Preserve Simplicity
- Picking up and using this library should be quick and easy.
	- A user shouldn't have to interact with an underlying data structure at all.
- Try to avoid overly long and unintuitive function/macro names.
- Keep the syntax of using the library uniform.
	- Eg. The append call to any list should be the exact same.
	- This means extensive use of macros to allow using the exact same calls between all generics of a specific type.
	- Unfortunately, this can lead to larger syntax error messages.
### Documentation
- Document all functions/macros and provide examples in code. 
## Done
- list.h: A dynamic generic list
	- dependencies: errors.h mem.h
## In Progress
- tree.h: A generic tree
## How to compile
#### Step 1:
Copy the desired generic and all of its dependencies to your project folder.
#### Step 2:
Include the generic file in a header file. Additionally, declare generic variable types for each generic type you will be using in that header file. Finally, include the header file wherever you use that generic definition.
Example Header File:

	#include "list.h"

	declare_list(list_int, int);

See examples/list\_example.h
#### Step 3:
Compile as usual.
## Using generics
### list calls (list.h)
#### new(type)
Returns a pointer to a new list of type, which must be defined by a declaration in your header file.

	list\_int* integers = new(list\_int);

#### append(ls, val)
Appends val to the list pointed to by ls. 

	// assuming declare_list(list\_double, double); is in the header file

	list\_double* doubles = new(list\_double);
	append(doubles, 2.0);
	append(doubles, 5.0);

#### get(ls, idx)
Semantically equivalent to the idea of ls\[idx\] (array access). Therefore, it can be used both to retrieve values from the list and set them. Gets value in the list pointed to ls at the index idx.

	get(doubles, 0) = 6.9;
	if (get(doubles, 1) != 5.0) {
		//...
	}

#### remove(ls, idx)
Removes the element at the index idx from the list pointed to by ls. 


	// doubles: [1.9, 25.0, 1.0]
	remove(doubles, 0);
	// doubles: [25.0, 1.0]
	remove(doubles, 1);
	// doubles: [25.0]

#### size(ls)
Returns the size (number of elements) of the list pointed to by ls.

	// assume doubles is a list
	
	for (int i = 0; i < size(doubles); ++i) {
		get(doubles, i) += 1.1;
	}

#### insert(ls, idx, val)
Inserts val at the index idx in the list pointed to by ls.

	// doubles: [1.0, 10.0, 0.0]
	insert(doubles, 0, 5.0);
	// doubles: [5.0, 1.0, 10.0, 0.0]
	insert(doubles, 2, 3.0);	
	// doubles: [5.0, 1.0, 3.0, 10.0, 0.0]

#### destroy(ls)
Frees the memory used by the list pointed to by ls. IMPORTANT: You are still responsible for freeing any additional memory you allocate; destroy(ls) only frees memory that was allocated by the constructor and append calls.

	// assuming declare_list(strings, char*); is in the header file
	strings* strs = new(strings);
	char* s = malloc(sizeof(char) * 10);
	append(strs, s);
	s = NULL;
 
	// Bad
	destroy(strs);
	// Now the reference to space allocated for s is lost ie: memory leak
 
	// Good
	free(get(strs, 0));
	destroy(strs);
