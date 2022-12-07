//
// Created by vladimir on 11/19/22.
//

#include "../inc/vector.h"

/**
 * @file vector.c
 * @brief This file implements ADT vector and all it's interface functions
 */

#define VECTOR_START_LENGTH 10

// Structure Vector (growing array)
struct Vector_t {
    void **array;                           // Array of elements
    void (*VectorElementDtor)(void *);      // Destructor of element
    int length;                             // Actual length of vector
    int maxLength;                          // Allocated length for array
};

Vector *Vector_Init(void (*VectorElementDtor)(void *)) {

    Vector *vector = (Vector *) malloc(sizeof(struct Vector_t));

    if (vector == NULL) {
        ERROR("Allocation failed");
    }

    vector->array = (void **) malloc(sizeof(void *) * VECTOR_START_LENGTH);
    if (vector->array == NULL) {
        free(vector);
        ERROR("Allocation failed");
    }

    vector->maxLength = VECTOR_START_LENGTH;
    vector->length = -1;
    vector->VectorElementDtor = VectorElementDtor;

    return vector;
}

void Vector_Destroy(Vector *vector) {

    Vector_Clear(vector);

    if (vector->array != NULL)
        free(vector->array);

    free(vector);
}

bool Vector_Clear(Vector *vector) {

    if (vector->VectorElementDtor == NULL)
            WARNING("Missing Dtor");
    else
        for (int i = 0; i < Vector_Size(vector); i++)
            vector->VectorElementDtor(vector->array[i]);

    vector->length = -1;
    vector->maxLength = VECTOR_START_LENGTH;
    vector->array = (void **) realloc(vector->array, sizeof(void *) * VECTOR_START_LENGTH);

    if (vector->array == NULL) {
        ERROR("Reallocation failed");
    }

    return true;
}

bool Vector_PushBack(Vector *vector, void *data) {

    if (Vector_Size(vector) == vector->maxLength) {
        vector->maxLength *= 2;
        vector->array = (void **) realloc(vector->array, sizeof(void *) * vector->maxLength);
        if (vector->array == NULL) {
            ERROR("Reallocation failed");
        }
    }

    vector->array[++(vector->length)] = data;

    return true;
}

int Vector_Size(Vector *vector) {
    return vector->length + 1;
}

void *Vector_GetElement(Vector *vector, int index) {

    if (index < 0 || index > vector->length)
        return NULL;

    return vector->array[index];
}

bool Vector_RemoveElement(Vector *vector, int index) {

    if (index < 0 || index > vector->length)
        return true;

    if (vector->VectorElementDtor != NULL)
        vector->VectorElementDtor(vector->array[index]);

    vector->length--;

    for (int i = index; i < Vector_Size(vector); i++)
        vector->array[i] = vector->array[i + 1];

    if (Vector_Size(vector) < vector->maxLength / 4 &&
        vector->maxLength > 2 * VECTOR_START_LENGTH) {
        vector->maxLength /= 2;
        vector->array = (void **) realloc(vector->array, sizeof(void *) * vector->maxLength);
        if (vector->array == NULL) {
            ERROR("Reallocation failed");
        }
    }

    return true;
}