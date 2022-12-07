/**
 * @file graph.h
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief This file contains interface functions for graph. Graph is basically vector
 * @changes 7.12.2022
 *
 * @note Functions do not check for NULL ptr being passed
 */

#ifndef IAL22_GRAPH_H
#define IAL22_GRAPH_H

#include "node.h"

/**
 * Init empty graph
 * @return Pointer on graph
 */
Vector *Graph_Init();

/**
 * Destroy graph
 * @param ptr Pointer on dtor function
 */
void Graph_Destroy(void *ptr);

/**
 * Add node to graph
 * @param graph Pointer on graph
 * @param node Pointer on created node
 * @return True upon succes
 */
bool Graph_Add_Node(Vector *graph, Node *node);

/**
 * Search for node in graph
 * @param graph Pointer on graph
 * @param node Pointer on node
 * @return True upon success, otherwise false
 */
bool Graph_Search_Node(Vector *graph, Node *node);

/**
 * Get node of graph
 * @param graph Pointer on created graph
 * @param index Position to be searched
 * @return
 */
Node *Graph_Get_Node(Vector *graph, int index);

/**
 * Remove node of graph
 * @param graph Pointer on graph
 * @param index Index of node to be deleted
 * @return True upon success, otherwise false
 */
bool Graph_Remove_Node(Vector *graph, int index);

/**
 * Get length of graph (amount of nodes)
 * @param graph Pointer on graph
 * @return Length of graph
 */
int Graph_Get_Size(Vector *graph);

/**
 * Delete all elements of graph
 * @param graph
 * @return True upon success, otherwise false
 */
bool Graph_Clear(Vector *graph);


#endif //IAL22_GRAPH_H
