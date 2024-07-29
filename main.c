#include "vector.h"


int main() {
    vector v;
    vec_init(&v, 5, sizeof(char)); // Initialize vector for int

    char *strings[] = {"bla", "tra", "la", "ba", "ta", "sa"};
    char *strings2[] = {"aa", "a"};
    double nm  = 3;
    vec_push_back(&v,strings, 6);
    printf("Address of num: %p\n", (char *)v.data[0]);
    //printf("Address of num: %p\n", (double *)v.data[0]);
    vec_insert(&v, 0, strings2, 2);
    printf("Address of num: %p\n", (char *)v.data[0]);
    //printf("Address of num: %p\n", (char *)strings);
    //printf("Address of num: %p\n", (double *)&v.data[0]);
    // Print the vector
    printf("Vector contents:\n");
    print_vector(&v);
    //vec_delete(&v);

    vector v1;
    vec_init(&v1, 6, sizeof(double));
    vec_push_back(&v1, &(double[]){1,2,3,4,5}, 5);
    vec_insert(&v1, 0, &(double[]){7,6},3);
    print_vector(&v1);


    return 0;
}
