# C-vector-struct

This is implmenetation of vector structure in C language. To use it, include vector.h header file in your project.
How to use it:
'''
#include "vector.h"


int main() {
    //vector of strings:
    vector v;
    vec_init(&v, 5, sizeof(char)); // Initialize vector for int;
    char *strings[] = {"bla", "tra", "la", "ba", "ta", "sa"};
    char *strings2[] = {"aa", "a"};
    double nm  = 3;
    vec_push_back(&v,strings, 6); 
    vec_insert(&v, 0, strings2, 2);
    printf("Vector contents:\n");
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
'''
It is possible to add to vector temporary types, which is closest to rvalues. Strings are always added as array of pointers to strings, even if only one is added.








