# C-Vector-Struct

This is an implementation of a dynamic vector structure in C. 

## Features
- Dynamic resizing of vectors.
- Supports any data type.
- Easy-to-use API for initialization, insertion, and deletion.
- Special handling for string arrays.

## How to Use

### Include the Header

Include the `vector.h` header file in your project:

```c
#include "vector.h"
```
### Example of usage
```c
#include <stdio.h>

int main() {
    // Vector of strings:
    vector v;
    vec_init(&v, 5, sizeof(char)); // Initialize vector for strings
    char *strings[] = {"bla", "tra", "la", "ba", "ta", "sa"};
    char *strings2[] = {"aa", "a"};
    
    vec_push_back(&v, strings, 6); 
    vec_insert(&v, 0, strings2, 2);
    
    printf("Vector contents (strings):\n");
    print_vector(&v);
    vec_delete(&v);

    // Vector of doubles:
    vector v1;
    vec_init(&v1, 6, sizeof(double));
    vec_push_back(&v1, (double[]){1, 2, 3, 4, 

```
It is possible to add to vector temporary types, which is closest to rvalues. Strings are always added as array of pointers to strings, even if only one is added.








