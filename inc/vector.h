/**
 * @file vector.h
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief This file contains declaration of ADT vector and interface functions
 *        ADT vector is basically growing and shrinking array
 * @changes 7.12.2022
 *
 *  * @note Functions do not check for NULL ptr being passed
 */

#ifndef IAL22_VECTOR_H
#define IAL22_VECTOR_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR(ARG) fprintf(stderr, "ERROR %s\n",ARG); exit(1)
#define WARNING(ARG) //fprintf(stderr, "WARNING %s\n",ARG) // Silent for project, not needed

// Typedef of vector is here so only functions Get can access values stored in vector
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
 * @param vector Vector
 * @param index Removes element on length position
 * @return true upon success otherwise false, length out-of-bounds has no effect
 */
bool Vector_RemoveElement(Vector *vector, int index);

#endif //IAL22_VECTOR_H