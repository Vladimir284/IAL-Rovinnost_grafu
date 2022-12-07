/**
 * @file graph.c
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief This file implements interface functions working with graph
 * @changes 7.12.2022
 */

#include "../inc/graph.h"

Vector *Graph_Init() {
    Vector *graph = Vector_Init(Node_Destroy);
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

int Graph_Get_Size(Vector *graph){
    return Vector_Size(graph);
}

bool Graph_Clear(Vector *graph){
    return Vector_Clear(graph);
}

void Graph_Destroy(void *ptr) {
    Vector *vector = (Vector *) ptr;
    Vector_Destroy(vector);
}
