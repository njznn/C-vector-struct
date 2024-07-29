#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h> 

typedef struct {
    void **data;
    int size;
    int csize;
    size_t elem_size;
} vector;

void vec_init(vector *v, int size, size_t elem_size) {
    v->size = size;
    v->csize = 0;
    v->elem_size = elem_size;
    v->data = (void **)malloc(v->size * sizeof(void *));
}

void vec_resize(vector *v, int new_size) {
    void **newdata = (void **)realloc(v->data, sizeof(void *) * new_size);
    if (newdata) {
        v->data = newdata;
        v->size = new_size;
    }
}

void vec_push_back(vector *v, void *elem, int num_elements) {
    // Resize the vector if necessary
    if (v->csize + num_elements > v->size) {
        vec_resize(v, (v->csize + num_elements) * 2);
    }

    for (int i = 0; i < num_elements; i++) {
        if (v->elem_size == sizeof(char)) {
            // Treat `elem` as either a single string or an array of strings
            char **strings = (char **)elem; // Cast `elem` to char**
            size_t len = strlen(strings[i]) + 1;

            v->data[v->csize] = malloc(len);
            if (v->data[v->csize] == NULL) {
                return;
            }

            strcpy(v->data[v->csize], strings[i]);
        } else {
            
            v->data[v->csize] = malloc(v->elem_size);
            if (v->data[v->csize] == NULL) {
                return;
            }
            memcpy(v->data[v->csize], (void *)elem + i * v->elem_size, v->elem_size);
        }
        v->csize++;
    }
}

void vec_set(vector *v, int index, void *elem) {
    if (index >= 0 && index < v->csize) {
        memcpy(v->data[index], elem, v->elem_size);
    }
}

void *vec_get(vector *v, int index) {
    if (index >= 0 && index < v->csize) {
        return v->data[index];
    }
    return NULL;
}

void vec_insert(vector *v, int index, void *elements, int count) {
    if (index < 0 || index > v->csize) {
        return; 
    }

    if (v->csize + count > v->size) {
        int new_size = v->size;
        while (new_size < v->csize + count) {
            new_size *= 2;
        }
        vec_resize(v, new_size);
    }
    //pointers usually all the same type, 8 (64 bit) or 4 (32 bit) bytes
    memmove(v->data+index + count, v->data+index, sizeof(void *) * (v->csize - index));

    for (int i = 0; i < count; i++) {
        if (v->elem_size == sizeof(char)) {
            // Treat `elem` as either a single string or an array of strings
            char **strings = (char **)elements; // Cast `elem` to char**
            size_t len = strlen(strings[i]) + 1;
            v->data[index+i] = malloc(sizeof(char)*len);
            if (v->data[index+i] == NULL) {
                return;
            }
            strcpy((char *)v->data[index+i], strings[i]);
        }
        else {
            v->data[index + i] = malloc(v->elem_size);
            if (v->data[index + i] == NULL) {
                return;
            }
            memcpy(v->data[index + i], (void *)elements + i * v->elem_size, v->elem_size);
        }
    }
    v->csize += count;
}


void vec_remove_elm(vector *v, int index) {
    if (index >= 0 && index < v->csize) {
        free(v->data[index]);
        memmove(v->data + index, v->data + index + 1, sizeof(void *) * (v->csize - index - 1));
        v->csize--;
    }
    if (v->size > 2 * v->csize) {
        vec_resize(v, v->csize);
    }
}

void vec_delete(vector *v) {
    for (int i = 0; i < v->csize; i++) {
        free(v->data[i]);
    }
    free(v->data);
    v->data = NULL;
    v->csize = 0;
    v->size = 0;
}

void vector_copy(vector *vc, vector *v) {
    vec_init(vc, v->size, v->elem_size);
    vc->csize = v->csize;
    for (int i = 0; i < v->csize; i++) {
        vc->data[i] = malloc(v->elem_size);
        memcpy(vc->data[i], v->data[i], v->elem_size);
    }
}

void print_vector(vector *v) {
    if (v->elem_size == sizeof(double))
        for (int i = 0; i < v->csize; i++) {
                printf("%f ", *(double *)(v->data[i]));
        }
    else if (v->elem_size == sizeof(float))
    {
       for (int i = 0; i < v->csize; i++) {
                printf("%f ", *(float *)(v->data[i]));
        }
    }
    else if (v->elem_size == sizeof(int))
    {
        for (int i = 0; i < v->csize; i++) {
                printf("%d ", *(int *)(v->data[i]));
        }
    }
    else if (v->elem_size == sizeof(char))
    {
        for (int i = 0; i < v->csize; i++) {
                printf("%s ", (char *)(v->data[i]));
        }
    }
    else{
        printf("type now known");
    }
    printf("\n");
}



