//
// Created by vladimir on 11/21/22.
//
#include "node_test.h"

////// Test cases
/// Base data
const int base_edges[] = {1, 2, 3, 4, 5};
const int base_edges_count = 5;

/// Aditional Data
const int additional_edges[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const int additional_edges_count = 10;

/// Id of node
const int node_id = 0;


/**
 * Help function, add base data into node
 * @param node
 */
void Node_Add_Base_Data(Node *node) {
    for (int i = 0; i < base_edges_count; ++i) {
        Node_Add_Edge(node, (int *) &base_edges[i]);
        printf("%d ",base_edges[i]);
    }
    printf("\n");
}

void Node_Add_Additional_Data(Node *node) {
    for (int i = 0; i < base_edges_count; ++i) {
        Node_Add_Edge(node, (int *) &additional_edges[i]);
        printf("%d ",additional_edges[i]);
    }
    printf("\n");
}

TEST(Test_Node_Init, "Initialise node")
    Node_Print(test_node);
ENDTEST;

TEST(Test_Node_Set_Activity_Inactive, "Set activity to inactive")
    Node_Set_Activity(test_node,false);
    Node_Print(test_node);
ENDTEST;

TEST(Test_Node_Set_Activity_Active, "Set activity to active")
    Node_Set_Activity(test_node,true);
    Node_Print(test_node);
ENDTEST;

TEST(Test_Node_Add_Base_Edges,"Add edges into node")
    Node_Add_Base_Data(test_node);
    Node_Print(test_node);
ENDTEST;

TEST(Test_Node_Remove_Edges_Last,"Remove last 3 edges from node")
    Node_Add_Base_Data(test_node);
    printf("\n");
    Node_Print(test_node);
    for (int i = 0; i < 3; ++i)
        Node_Delete_Edge(test_node, (int*) &base_edges[4-i]);
    Node_Print(test_node);
ENDTEST;

TEST(Test_Node_Remove_Edges_First, "Remove first 3 edges from node")
    Node_Add_Base_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    for (int i = 0; i < 3; ++i)
        Node_Delete_Edge(test_node, (int*) &base_edges[i]);
    Node_Print(test_node);
ENDTEST;

TEST(Test_Node_Add_Additional_Edges,"Add base edges and onto it add aditional edges")
    Node_Add_Base_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    Node_Add_Additional_Data(test_node);
    Node_Print(test_node);
ENDTEST;

void Test_Node(){

    Node_Init_Test();

    Test_Node_Init();
    Test_Node_Set_Activity_Inactive();
    Test_Node_Set_Activity_Active();
    Test_Node_Add_Base_Edges();
    Test_Node_Remove_Edges_Last();
    Test_Node_Remove_Edges_First();
}