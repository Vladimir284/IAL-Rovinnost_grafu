/**
 * @file test_scanner.c
 * @project IAL Náhradní projekt - 05. Rovinnost grafu
 * @author Rastislav Mazur (xmazur09)
 * @brief This file implements test for file scanner.c
 * @changes 7.12.2022
 */

#include "../inc/test_scanner.h"

#define MAINDEBUG(PARAM) printf("%s\n",PARAM)

void Scanner_Init_Tests() {
    printf("           Scanner tests\n");
    printf("-------------------------------------\n\n\n");
}

void Test_Scanner() {

    //And the shitshow is about to begin
    Scanner_Init_Tests();

    // Init graph
    Vector *test_graph = Graph_Init();

    // Fill graph with data
    if (Scanner_Main(test_graph)) {

        // Print Graph
        Graph_Print(test_graph);
        printf("\n");


        Node *tmp_node;
        int i = 0;

        // Print all nodes
        while ((tmp_node = Graph_Get_Node(test_graph, i)) != NULL) {
            Node_Print(tmp_node);
            if (i + 1 != Graph_Get_Size(test_graph))
                printf("\n");
            i++;
        }

        // Finally, done :D
        Graph_Destroy(test_graph);
    }
}
