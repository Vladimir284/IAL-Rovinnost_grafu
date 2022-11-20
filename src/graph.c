//
// Created by vladimir on 11/19/22.
//

#include "graph.h"

/**
 * @file graph.c
 * @brief This file implements  interface functions to work with graph
 */

Vector *Graph_Init() {
    Vector *graph = Vector_Init(NULL);
    return graph;
}

bool Graph_Add_Node(Vector *graph, Node *node) {
    return Vector_PushBack(graph, node);
}

bool Graph_Search_Node(Vector *graph, Node *node){

    for (int i = 0; i < Vector_Size(graph); ++i)
        if ((Node*)Vector_GetElement(graph, i) == node)
            return true;

    return false;
}

Node *Graph_Get_Node(Vector *graph, int index){
    return Vector_GetElement(graph,index);
}

bool Graph_Remove_Node(Vector *graph, int index){
    return Vector_RemoveElement(graph, index);
}

bool Graph_Clear(Vector *graph){
    return Vector_Clear(graph);
}

void Graph_Dtor(void *ptr) {
    Vector *vector = (Vector *) ptr;
    Vector_Destroy(vector);
}
