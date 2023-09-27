//
// Created by jakub on 6.12.22.
//


#include "../inc/test_algorithm.h"

//začátek části pro smazání

void fill_graph(Vector *graph){
    Node *node;
    /*node = Node_Init(1);
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(4));
    Graph_Add_Node(graph, node);
    node = Node_Init(2);
    Node_Add_Edge(node, Init(1));
    Node_Add_Edge(node, Init(4));
    Node_Add_Edge(node, Init(3));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(6));
    Node_Add_Edge(node, Init(7));
    Graph_Add_Node(graph, node);
    node = Node_Init(3);
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(7));
    Node_Add_Edge(node, Init(8));
    Graph_Add_Node(graph, node);
    node = Node_Init(4);
    Node_Add_Edge(node, Init(1));
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(6));
    Graph_Add_Node(graph, node);
    node = Node_Init(5);
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(3));
    Node_Add_Edge(node, Init(4));
    Node_Add_Edge(node, Init(6));
    Node_Add_Edge(node, Init(7));
    Node_Add_Edge(node, Init(8));
    Graph_Add_Node(graph, node);
    node = Node_Init(6);
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(4));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(7));
    Node_Add_Edge(node, Init(8));
    Graph_Add_Node(graph, node);
    node = Node_Init(7);
    Node_Add_Edge(node, Init(3));
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(6));
    Node_Add_Edge(node, Init(8));
    //Node_Add_Edge(node, Init(9));
    //Node_Add_Edge(node, Init(10));
    Graph_Add_Node(graph, node);
    node = Node_Init(8);
    Node_Add_Edge(node, Init(6));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(7));
    //Node_Add_Edge(node, Init(9));
    //Node_Add_Edge(node, Init(10));
    Graph_Add_Node(graph, node);
    node = Node_Init(9);
    Node_Add_Edge(node, Init(7));
    Node_Add_Edge(node, Init(8));
    Node_Add_Edge(node, Init(10));
    Graph_Add_Node(graph, node);
    node = Node_Init(10);
    Node_Add_Edge(node, Init(7));
    Node_Add_Edge(node, Init(8));
    Node_Add_Edge(node, Init(9));
    Graph_Add_Node(graph, node);*/
    node = Node_Init(1);
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(3));
    Node_Add_Edge(node, Init(4));
    Graph_Add_Node(graph, node);
    node = Node_Init(2);
    Node_Add_Edge(node, Init(1));
    Node_Add_Edge(node, Init(4));
    Node_Add_Edge(node, Init(3));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(6));
    Graph_Add_Node(graph, node);
    node = Node_Init(3);
    Node_Add_Edge(node, Init(1));
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(5));
    Graph_Add_Node(graph, node);
    node = Node_Init(4);
    Node_Add_Edge(node, Init(1));
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(6));
    Graph_Add_Node(graph, node);
    node = Node_Init(5);
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(3));
    Node_Add_Edge(node, Init(4));
    Node_Add_Edge(node, Init(6));
    Graph_Add_Node(graph, node);
    node = Node_Init(6);
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(4));
    Node_Add_Edge(node, Init(5));
    Graph_Add_Node(graph, node);
    /*node = Node_Init(7);
    Node_Add_Edge(node, Init(3));
    Node_Add_Edge(node, Init(2));
    Node_Add_Edge(node, Init(5));
    Node_Add_Edge(node, Init(6));*/
    //Node_Add_Edge(node, Init(8));
    //Node_Add_Edge(node, Init(9));
    //Node_Add_Edge(node, Init(10));
    //Graph_Add_Node(graph, node);
}
//konec části pro smazání


void test_algorithm(){
    Vector *test_graph = Graph_Init();
    fill_graph(test_graph);

    //zobrazení grafu
    NEWLINE;
    printf("INPUT");
    NEWLINE;
    for(int i = 0; i < Graph_Get_Size(test_graph); i++){
        Node *node;
        node = Graph_Get_Node(test_graph, i);
        printf("%d\n", Node_Get_Id(node));
        for(int j = 0; j < Vector_Size(Node_Get_Edges(node)); j++){
            int *edge = Node_Get_Edge(node, j);
            printf("   Edge %d\n", *edge);
        }
    }

    algorithm(test_graph);

    //druhé zobrazení grafu
    NEWLINE;
    printf("OUTPUT");
    NEWLINE;
    for(int i = 0; i < Graph_Get_Size(test_graph); i++){
        Node *node;
        node = Graph_Get_Node(test_graph, i);
        if(Node_Get_Activity(node)) {
            printf("%d\n", Node_Get_Id(node));
            for (int j = 0; j < Vector_Size(Node_Get_Edges(node)); j++) {
                int *edge = Node_Get_Edge(node, j);
                printf("   Edge %d\n", *edge);
            }
        }
    }

    Graph_Destroy(test_graph);
}
