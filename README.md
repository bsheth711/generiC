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
## How to use
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
