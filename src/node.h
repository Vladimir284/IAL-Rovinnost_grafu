//
// Created by vladimir on 11/19/22.
//

#ifndef IAL22_NODE_H
#define IAL22_NODE_H

/**
 * @file node.h
 * @brief This file contains declaration of ADT node and interface functions
 * @note Functions do not check for NULL ptr being passed
 */

#include "vector.h"

// State of being visited
typedef enum Color_t {
    white = 0,  // Was not visited
    grey = 1    // Was visited
}Color;

typedef struct Node_t Node;

/**
 * Create empty node
 * @param id Id of pointer
 * @return Pointer on created node
 */
Node* Node_Init(int id);

/**
 * Get color of node
 * @param node Pointer on node
 * @return Color of node
 */
Color Node_Get_Color(Node *node);

/**
 * Set color of node
 * @param node Pointer on node
 * @param color Color that is going to bew node set on
 */
void Node_Set_Color(Node *node, Color color);

/**
 * Get activity of node
 * @param node Pointer on node
 * @return Activity of node
 */
bool Node_Get_Activity(Node *node);

/**
 * Set activity of node
 * @param node Pointer on node
 * @param activity Activity, node is going to be set on
 */
void Node_Set_Activity(Node *node, bool activity);

/**
 * Get id of node
 * @param node Pointer on node
 * @return Id of node
 */
int Node_Get_Id(Node *node);

/**
 * Get edge of node
 * @param node Pointer on node
 * @param edge Pointer on edge to be found
 * @return Pointer on edge, Null if edge does not exist
 */
int *Node_Get_Edge(Node *node, int *edge);

/**
 * Get edges of node
 * @param node Pointer on node
 * @return Pointer on array of edges
 */
Vector *Node_Get_Edges(Node *node);

/**
 * Search specific edge in node
 * @param node Pointer on node
 * @param edge Edge we are looking for
 * @return True upon success, otherwise false
 */
bool Node_Search_Edge(Node *node, int *edge);

/**
 * Add edge to node
 * @param node Pointer on node
 * @param edge Edge to add
 * @return True upon success
 */
bool Node_Add_Edge(Node *node, int *edge);

/**
 * Delete edge of node
 * @param node Pointer on node
 * @param edge Edge to be deleted
 * @return True upon succes, otherwise 0
 */
bool Node_Delete_Edge(Node *node, int *edge);

/**
 * Delete all edges of node
 * @param node Pointer on node
 * @return True upon success, otherwise false
 */
bool Node_Delete_All_Edges(Node *node);

/**
 * Destroy node
 * @param ptr Pointer on destroy funcion (free in this case)
 */
void Node_Dtor(void* ptr);

#endif //IAL22_NODE_H