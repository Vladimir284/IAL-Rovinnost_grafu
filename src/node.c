/**
 * @file node.c
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief This file implements ADT node and all it's interface functions
 * @changes 7.12.2022
 */

#include "../inc/node.h"

// Structure of node
struct Node_t {
    int id;             // Node identifier
    Vector *edges;      // Array of edges
    bool active;        // Active flag
    Color color;        // Visited flag
};

Node *Node_Init(int id) {

    Node *pNode = (Node*) malloc(sizeof(Node));
    if (pNode == NULL) {
        ERROR("Allocation failed");
    }

    pNode->id = id;
    pNode->color = white;
    pNode->active = 0;
    pNode->edges = Vector_Init(NULL);
    return pNode;
}

Color Node_Get_Color(Node *node) {
    return node->color;
}

void Node_Set_Color(Node *node, Color color) {
    node->color = color;
}

bool Node_Get_Activity(Node *node) {
    return node->active;
}

void Node_Set_Activity(Node *node, bool activity) {
    node->active = activity;
}

int Node_Get_Id(Node *node){
    return node->id;
}


Vector *Node_Get_Edges(Node *node) {
    return node->edges;
}

int *Node_Get_Edge(Node *node, int index){
    return Vector_GetElement(Node_Get_Edges(node),index);
}

bool Node_Search_Edge(Node *node, int *edge) {

    for (int i = 0; i < Vector_Size(node->edges); ++i)
        if ((int *) Vector_GetElement(Node_Get_Edges(node), i) == edge)
            return true;

    return false;
}

bool Node_Add_Edge(Node *node, int *edge) {
    return Vector_PushBack(node->edges, edge);
}

// TODO Edge can be pointer to const ? Ask Rasto
bool Node_Delete_Edge(Node *node, int *edge) {

    for (int i = 0; i < Vector_Size(node->edges); ++i)
        if ((int*)Vector_GetElement(Node_Get_Edges(node), i) == edge)
            return Vector_RemoveElement(Node_Get_Edges(node), i);

    return false;
}

bool Node_Delete_All_Edges(Node *node) {
    return Vector_Clear(Node_Get_Edges(node));
}

void Node_Destroy(void* ptr) {
    Node *node = (Node*)ptr;
    Vector_Destroy(node->edges);
}
