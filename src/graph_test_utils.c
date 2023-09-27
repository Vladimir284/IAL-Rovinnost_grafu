/**
 * @file graph_test_utils.c
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Vladimir Meciar (xmecia00)
 * @brief This file implements help functions for graph_test.c
 * @changes 7.12.2022
 */

#include "../inc/graph_test_utils.h"

void Graph_Init_Test() {
    printf("           Graph tests\n");
    printf("-----------------------------------\n\n\n");
}

void Graph_Print(Vector *graph) {
    printf("Graph length: %d\n", Vector_Size(graph));
    printf("Graph nodes: ");
    printf("[ ");
    for (int i = 0; i < Vector_Size(graph); ++i) {
        printf("%d", Node_Get_Id((Node *) Vector_GetElement(graph, i)));
        if (i != Vector_Size(graph) - 1)
            printf(", ");
    }
    printf(" ]\n");
}
