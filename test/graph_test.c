//
// Created by vladimir on 11/21/22.
//
#include "../inc/graph_test.h"


#define VIEW_INDICES(GRAPH) \
        for (int i = 0; i < Graph_Get_Size(GRAPH); i++) \
        printf("Index:%d, NodeId:%d\n",i,Node_Get_Id(Graph_Get_Node(GRAPH,i)));

////// Test cases
/// Base data
const int base_nodes_id[] = {1, 2, 3, 4, 5};
const int base_nodes_count = 5;

/// Aditional Data
const int additional_nodes_id[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const int additional_nodes_count = 10;

/**
 * Help fuction, add base nodes to graph
 * @param graph Pointer on allocated graph
 */
void Graph_Add_Base_Nodes(Vector *graph) {
    for (int i = 0; i < base_nodes_count; ++i)
        Graph_Add_Node(graph, Node_Init(base_nodes_id[i]));
}

/**
 * Help function, add additional nodes to graph
 * @param graph Pointer on allocated graph
 */
void Graph_Add_Additional_Nodes(Vector *graph) {
    for (int i = 0; i < additional_nodes_count; ++i)
        Graph_Add_Node(graph, Node_Init(additional_nodes_id[i]));
}

/**
 * Help function, print if node is in graph
 * @param graph Pointer on graph
 * @param node  Pointer on node
 */
void Graph_Print_Search_Node(Vector *graph, Node *node) {
    char *string = Graph_Search_Node(graph, node) ? "found" : "not found";
    printf("Node %d ", (Node_Get_Id(node)));
    printf("%s\n", string);
}


TESTGRAPH(Test_Init_Graph, "Init empty graph")
    Graph_Print(test_graph);
ENDTESTGRAPH

TESTGRAPH(Test_Add_Base_Nodes, "Add base nodes to graph")
    Graph_Print(test_graph);
    Graph_Add_Base_Nodes(test_graph);
    NEWLINE;
    Graph_Print(test_graph);
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Remove_Nodes_Last, "Remove last 3 nodes from graph")
    Graph_Print(test_graph);
    NEWLINE;
    Graph_Add_Base_Nodes(test_graph);
    Graph_Print(test_graph);
    NEWLINE;
    for (int i = 0; i < 3; ++i)
        Graph_Remove_Node(test_graph, (base_nodes_count - 1 - i));
    Graph_Print(test_graph);
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Remove_Nodes_First, "Remove first 3 nodes from graph")
    Graph_Print(test_graph);
    NEWLINE;
    Graph_Add_Base_Nodes(test_graph);
    Graph_Print(test_graph);
    NEWLINE;
    for (int i = 0; i < 3; ++i)
        Graph_Remove_Node(test_graph, 0);
    Graph_Print(test_graph);
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Add_Additional_Nodes, "Add base and additional nodes to graph")
    Graph_Print(test_graph);
    NEWLINE;
    Graph_Add_Base_Nodes(test_graph);
    Graph_Add_Additional_Nodes(test_graph);
    Graph_Print(test_graph);
    NEWLINE;
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Remove_Additional_Nodes_First, "Remove first 8 nodes from graph with base and additional nodes")
    Graph_Print(test_graph);
    NEWLINE;
    Graph_Add_Base_Nodes(test_graph);
    Graph_Add_Additional_Nodes(test_graph);
    Graph_Print(test_graph);
    NEWLINE;
    for (int i = 0; i < 8; ++i)
        Graph_Remove_Node(test_graph, 0);
    Graph_Print(test_graph);
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Remove_Additional_Nodes_Last, "Remove last 8 nodes from graph with base and additional nodes")
    Graph_Print(test_graph);
    NEWLINE;
    Graph_Add_Base_Nodes(test_graph);
    Graph_Add_Additional_Nodes(test_graph);
    Graph_Print(test_graph);
    NEWLINE;
    for (int i = 0; i < 8; ++i) {
        Graph_Remove_Node(test_graph, additional_nodes_id[additional_nodes_count - 1 - i]);
    }
    Graph_Print(test_graph);
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Search_Additional_Node, "Search every second node in graph with base and additional edges")
    Graph_Print(test_graph);
    NEWLINE;
    Graph_Add_Base_Nodes(test_graph);
    Graph_Add_Additional_Nodes(test_graph);
    Graph_Print(test_graph);
    NEWLINE;
    for (int i = 1; i < base_nodes_count + additional_nodes_count; i += 2)
        Graph_Print_Search_Node(test_graph, Graph_Get_Node(test_graph, i));
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Search_Empty_Graph_Additional_Nodes, "Search every second node in empty graph")
    Graph_Print(test_graph);
    Node *node;
    NEWLINE;
    for (int i = 1; i < base_nodes_count + additional_nodes_count; i += 2) {
        node = Graph_Get_Node(test_graph, i);
        if (node == NULL)
            printf("Node %d not found\n", (i + 1));
        else
            Graph_Print_Search_Node(test_graph, node);
    }
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Get_Node_On_Index, "Get every single node of graph")
    Graph_Print(test_graph);
    Graph_Add_Base_Nodes(test_graph);
    Graph_Add_Additional_Nodes(test_graph);
    NEWLINE;
    for (int i = 0; i < base_nodes_count + additional_nodes_count; ++i)
        printf("Node on index %d: %d\n", (i + 1), Node_Get_Id(Graph_Get_Node(test_graph, i)));
ENDTESTGRAPH

TESTGRAPH(Test_Graph_Clear_Additional_Node, "Clear graph with base and additional nodes")
    Graph_Print(test_graph);
    Graph_Add_Base_Nodes(test_graph);
    Graph_Add_Additional_Nodes(test_graph);
    NEWLINE;
    Graph_Print(test_graph);
    Graph_Clear(test_graph);
    NEWLINE;
    Graph_Print(test_graph);
ENDTESTGRAPH

void Test_Graph() {

    Graph_Init_Test();

    Test_Init_Graph();
    Test_Add_Base_Nodes();
    Test_Graph_Remove_Nodes_Last();
    Test_Graph_Remove_Nodes_First();
    Test_Graph_Add_Additional_Nodes();
    Test_Graph_Remove_Additional_Nodes_First();
    Test_Graph_Remove_Additional_Nodes_Last();
    Test_Graph_Search_Additional_Node();
    Test_Graph_Search_Empty_Graph_Additional_Nodes();
    Test_Graph_Get_Node_On_Index();
    Test_Graph_Clear_Additional_Node();
}