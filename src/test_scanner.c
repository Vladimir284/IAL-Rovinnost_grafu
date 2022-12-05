//
// Created by vladimir on 12/1/22.
//

#include "../inc/test_scanner.h"

void Test_Scanner() {

    // Init graph
    Vector *test_graph = Graph_Init();

    // Fill graph with data
    Scanner_Main(test_graph);

    // Print Graph
    Graph_Print(test_graph);
    printf("\n");
    for (int i = 0; i < Graph_Get_Size(test_graph); ++i) {
        Node_Print(Graph_Get_Node(test_graph, i));
        printf("\n");
    }
    printf("\n");

    // Finally, done :D
    if (test_graph != NULL)
        Graph_Destroy(test_graph);
}
