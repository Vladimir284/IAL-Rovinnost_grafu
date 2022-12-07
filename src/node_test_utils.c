/**
 * @file node_test_utils.c
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief This file implements help functions for node_test.c
 * @changes 7.12.2022
 */

#include "../inc/node_test_utils.h"

void Node_Init_Test() {
    printf("           Node tests\n");
    printf("----------------------------------\n\n\n");
}

void Node_Print_Edges(Node *node) {
    printf("Node edges length: %d\n", Vector_Size(Node_Get_Edges(node)));
    printf("Node Edges: ");
    printf("[ ");
    for (int i = 0; i < Vector_Size(Node_Get_Edges(node)); ++i) {
        printf("%d", Node_Get_Id((Node *) Vector_GetElement(Node_Get_Edges(node), i)));
        if (i != Vector_Size(Node_Get_Edges(node)) - 1)
            printf(", ");
    }
    printf(" ]\n");
}

void Node_Print_Flags(Node *node) {
    printf("Node activity: %d\n", Node_Get_Activity(node));
    printf("Node color: %s\n", ((Node_Get_Color(node) ==  0) ? "White" : "Grey"));
}

void Node_Print(Node *node){
    printf("Node id: %d\n", Node_Get_Id(node));
    Node_Print_Edges(node);
    Node_Print_Flags(node);
}