/*
    gcc -c float_vector.c para dizer ao compilador 
    que este arquivo é simplesmente um arquivo de código fonte

    Irá gerar um arquivo .o 
*/ 

#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _float_vector {
    int capacity;
    int size;
    float *data;
} FloatVector;

bool _isFull(const FloatVector *vec) {
    return vec->capacity == vec->size;
}

bool _outOfBound(const FloatVector *vec, int index) {
    return index < 0 || index >= vec->size;
}



// ########################### PUBLIC ###################################


FloatVector *FVcreate(int capacity) {
    FloatVector *vec = (FloatVector *) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float *) calloc(capacity, sizeof(float));
    return vec;
}

void FVdestroy(FloatVector **vec) {
    free((*vec)->data);
    (*vec)->data = NULL;

    free(vec);
    *vec = NULL;
}

void FVappend(FloatVector *vec, float val) {

    if (_isFull(vec)) {
        fprintf(stderr, "ERROR in 'append' \n");
        fprintf(stderr, "Vector is full' \n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size++] = val;
}

void FVprint(const FloatVector *vec) {

    if (vec == NULL) {
        fprintf(stderr, "Vector is NULL!");
        exit(EXIT_FAILURE);
    }
 
    puts("");
    printf("Capacity => %d \n", vec->capacity);
    printf("Curent size => %d \n", vec->size);
    for (int i = 0; i < vec->size; i++) {
        printf("[%d] => %f \n", i, vec->data[i]);
    }

    puts("");
}

int FVsize(const FloatVector *vec) {
    return vec->size;
}

int FVcapacity(const FloatVector *vec) {
    return vec->capacity;
}

float FVat(const FloatVector *vec, int index) {
    if (_outOfBound(vec, index)) {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d] \n", index, vec->size - 1);
        exit(EXIT_FAILURE);
    }

    return vec->data[index];
}

float FVget(const FloatVector *vec, int index) {
    return vec->data[index];
}

void FVset(const FloatVector *vec, int index, float val) {
    if (_outOfBound(vec, index)) {
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d] \n", index, vec->size - 1);
        exit(EXIT_FAILURE);
    }

    vec->data[index] = val;
}