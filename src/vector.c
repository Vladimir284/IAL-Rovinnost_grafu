//
// Created by vladimir on 11/19/22.
//

#include "vector.h"

/**
 * @file vector.c
 * @brief This file implements ADT vector and all it's interface functions
 */

#define VECTOR_INIT_SIZE 10

// Structure Vector (growing array)
struct Vector_t {
    void **array;                           // Array of elements
    void (*VectorElementDtor)(void *);      // Destructor of element
    int size;                               // Actual size of vector
    int maxSize;                            // Allocated size for array
};

Vector *Vector_Init(void (*VectorElementDtor)(void *)) {
    Vector *vector = (Vector *) malloc(sizeof(struct Vector_t));
    if (vector == NULL) {
        ERROR("Allocation failed");
        return NULL; // TODO Ask Rasto
    }
    vector->array = (void **) malloc(sizeof(void *) * VECTOR_INIT_SIZE);
    if (vector->array == NULL) {
        free(vector);
        ERROR("Allocation failed");
        return NULL; // TODO Ask Rasto
    }

    vector->maxSize = VECTOR_INIT_SIZE;
    vector->size = -1;
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

    vector->size = -1;
    vector->maxSize = VECTOR_INIT_SIZE;
    vector->array = (void **) realloc(vector->array, sizeof(void *) * VECTOR_INIT_SIZE);

    if (vector->array == NULL) {
        ERROR("Reallocation failed");
        return NULL; // TODO Ask Rasto
    }

    return true;
}

bool Vector_PushBack(Vector *vector, void *data) {
    if (Vector_Size(vector) == vector->maxSize) {
        vector->maxSize *= 2;
        vector->array = (void **) realloc(vector->array, sizeof(void *) * vector->maxSize);
        if (vector->array == NULL) {
            ERROR("Reallocation failed");
            return NULL; // TODO Ask Rasto
        }
    }

    vector->array[++(vector->size)] = data;

    return true;
}

bool Vector_PopBack(Vector *vector) {
    if (vector->VectorElementDtor != NULL)
        vector->VectorElementDtor(vector->array[vector->size]);

    vector->size--;

    if (Vector_Size(vector) < vector->maxSize / 4 &&
        vector->maxSize > 2 * VECTOR_INIT_SIZE) // to not reallocate with small vector
    {
        vector->maxSize /= 2;
        vector->array = (void **) realloc(vector->array, sizeof(void *) * vector->maxSize);
        if (vector->array == NULL) {
            ERROR("Reallocation failed");
            return NULL; // TODO Ask Rasto
        }
    }

    return true;
}

void *Vector_Back(Vector *vector) {
    return vector->size == -1 ? NULL : vector->array[vector->size];
}

bool Vector_IsEmpty(Vector *vector) {
    return vector->size == -1;
}

int Vector_Size(Vector *vector) {
    return vector->size + 1;
}

void *Vector_GetElement(Vector *vector, int index) {
    if (index < 0 || index > vector->size)
        return NULL;

    return vector->array[index];
}

bool Vector_InsertElement(Vector *vector, int index, void *data) {
    if (index < 0 || index > vector->size + 1)
        return false;

    if (Vector_Size(vector) == vector->maxSize) {
        vector->maxSize *= 2;
        vector->array = (void **) realloc(vector->array, sizeof(void *) * vector->maxSize);
        if (vector->array == NULL) {
            ERROR("Reallocation failed");
            return NULL; // TODO Ask Rasto
        }
    }

    vector->size++;

    for (int i = Vector_Size(vector) - 1; i > index; i--)
        vector->array[i] = vector->array[i - 1];

    vector->array[index] = data;

    return true;
}

bool Vector_RemoveElement(Vector *vector, int index) {
    if (index < 0 || index > vector->size)
        return true;

    if (vector->VectorElementDtor != NULL)
        vector->VectorElementDtor(vector->array[index]);

    vector->size--;

    for (int i = index; i < Vector_Size(vector); i++)
        vector->array[i] = vector->array[i + 1];

    if (Vector_Size(vector) < vector->maxSize / 4 &&
        vector->maxSize > 2 * VECTOR_INIT_SIZE) // to not reallocate with small vector
    {
        vector->maxSize /= 2;
        vector->array = (void **) realloc(vector->array, sizeof(void *) * vector->maxSize);
        if (vector->array == NULL) {
            ERROR("Reallocation failed");
            return NULL; // TODO Ask Rasto
        }
    }

    return true;
}