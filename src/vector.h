//
// Created by vladimir on 11/19/22.
//

#ifndef IAL22_VECTOR_H
#define IAL22_VECTOR_H

/**
 * @file vector.h
 * @brief This file contains declaration of ADT vector and interface functions
 *        ADT vector is basically growing and shrinking array
 * @note Functions do not check for NULL ptr being passed
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR(ARG) fprintf(stderr, "ERROR %s\n",ARG)
#define WARNING(ARG) //fprintf(stderr, "WARNING %s\n",ARG) Silent for now, not needed TODO Ask Rasto

// Typedef of vector is here so only functions Get can acces values stored in vector
typedef struct Vector_t Vector;

/**
 * @brief Creates Empty Vector
 * @param dtor Destructor for element
 * @return Vector pointer
 */
Vector *Vector_Init(void (*VectorElementDtor)(void*));

/**
 * @brief Clears and destroys Vector
 * @param vector Vector
 */
void Vector_Destroy(Vector *vector);

/**
 * @brief Clears Vector
 * @param vector Vector
 * @return true upon success otherwise false
 */
bool Vector_Clear(Vector *vector);

/**
 * @brief Adds data to the end of Vector
 * @param vector Vector
 * @param data Data to be added
 */
bool Vector_PushBack(Vector *vector, void* data);

/**
 * @brief Destroys last element, on empty nothing
 * @param vector Vector
 * @return true upon success, otherwise false @note PopBack upon empty Vector is success too
 */
bool Vector_PopBack(Vector *vector);

/**
 * @param vector Vector
 * @return Last data in vector
 */
void *Vector_Back(Vector *vector);

/**
 * @param vector Vector
 * @return true if empty otherwise false
 */
bool Vector_IsEmpty(Vector *vector);

/**
 * @param vector Vector
 * @return Size of vector
 */
int Vector_Size(Vector *vector);

/**
 * @param vector Vector
 * @param index Index of wanted element
 * @return Element at certain index, NULL if out-of-bounds
 */
void* Vector_GetElement(Vector *vector, int index);

/**
 * @brief Inserts Element at specified length
 * @param vector Vector
 * @param index Where to add new data
 * @param data Data
 * @return True upon success otherwise false
 */
bool Vector_InsertElement(Vector *vector, int index, void* data);

/**
 * @param vector Vector
 * @param index Removes element on length position
 * @return true upon success otherwise false, length out-of-bounds has no effect
 */
bool Vector_RemoveElement(Vector *vector, int index);

#endif //IAL22_VECTOR_H