# C Vector 

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

    //vector of doubles:
    vector v1;
    vec_init(&v1, 6, sizeof(double));
    vec_push_back(&v1, &(double[]){1,2,3,4,5}, 5);
    vec_insert(&v1, 0, &(double[]){7,6},3);
    print_vector(&v1);
    vec_delete(&v1);


    return 0;
}

```
### Notes

- **Temporary Types**: It is possible to add temporary types to the vector, similar to rvalues in C++. This allows for flexible handling of various types of data during insertion.
  
- **String Handling**: Strings are always added as an array of pointers to strings, even if only one string is added.






