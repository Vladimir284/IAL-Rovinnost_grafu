//
// Created by vladimir on 12/1/22.
//

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
        //DEBUG("LINE22");


        //printf("Graph %s\n",(test_graph==NULL)  ? "Null" : "Not Null");
        //printf("Node 0 %s\n",(Graph_Get_Node(test_graph,0)==NULL)  ? "Null" : "Not Null");
        Node *tmp_node;
        int i = 0;

        while ((tmp_node = Graph_Get_Node(test_graph, i)) != NULL) {
            //printf("Gay\n");
            Node_Print(tmp_node);
            printf("\n");
            i++;
        }

        //printf("\n");
        //DEBUG("Line 30");


        //printf("Graph - %s\n", (test_graph == NULL) ? "Null" : "Not null");
        //printf("Array of graph - %s\n", (Graph_Get_Node(test_graph, 0) == NULL) ? "Null" : "Not null");


        // Finally, done :D
        Graph_Destroy(test_graph);

    }

    // Scanner not working
    Graph_Destroy(test_graph);
}
