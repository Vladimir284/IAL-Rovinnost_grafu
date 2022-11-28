//
// Created by vladimir on 11/20/22.
//

#include "../inc/graph_test_utils.h"

void Graph_Init_Test() {
    printf("           Graph tests\n");
    printf("-----------------------------------\n\n\n");
}

void Graph_Print(Vector *graph) {
    printf("Graph size: %d\n", Vector_Size(graph));
    printf("Graph nodes: ");
    printf("[ ");
    for (int i = 0; i < Vector_Size(graph); ++i) {
        printf("%d", Node_Get_Id((Node *) Vector_GetElement(graph, i)));
        if (i != Vector_Size(graph) - 1)
            printf(", ");
    }
    printf(" ]\n");
}