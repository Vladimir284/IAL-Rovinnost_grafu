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
 * @param node Pointer on node
 */
void Node_Add_Base_Data(Node *node) {
    for (int i = 0; i < base_edges_count; ++i) {
        Node_Add_Edge(node, (int *) &base_edges[i]);
        // printf("%d ",base_edges[i]); Do no need right now
    }
    //printf("\n");
}

/**
 * Help function, add additional data into node
 * @param node Pointer on node
 */
void Node_Add_Additional_Data(Node *node) {
    for (int i = 0; i < additional_edges_count; ++i) {
        Node_Add_Edge(node, (int *) &additional_edges[i]);
        // printf("%d ",additional_edges[i]); Do not need right now
    }
    //printf("\n");
}

/**
 * Help function, search edge and print output
 * @param node Pointer on node
 * @param edge Pointer on edge
 */
void Node_Print_Search_Edge(Node *node, int *edge){
    char *string = Node_Search_Edge(node,edge) ? "found" : "not found";
    printf("Edge %d ",(*edge));
    printf("%s\n",string);
}

TEST(Test_Node_Init, "Initialise node")
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Set_Activity_Inactive, "Set activity to inactive")
    Node_Set_Activity(test_node,false);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Set_Activity_Active, "Set activity to active")
    Node_Set_Activity(test_node,true);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Set_Color_Gray, "Set node color to grey")
    Node_Set_Color(test_node,grey);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Add_Base_Edges,"Add edges into node")
    Node_Add_Base_Data(test_node);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Remove_Edges_Last,"Remove last 3 edges from node")
    Node_Add_Base_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    for (int i = 0; i < 3; ++i)
        Node_Delete_Edge(test_node, (int*) &base_edges[4-i]);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Remove_Edges_First, "Remove first 3 edges from node")
    Node_Add_Base_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    for (int i = 0; i < 3; ++i)
        Node_Delete_Edge(test_node, (int*) &base_edges[i]);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Add_Additional_Edges,"Add base edges and onto it add aditional edges")
    Node_Add_Base_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    Node_Add_Additional_Data(test_node);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Remove_Additional_Edges_First, "Remove first 8 edges from node with base and additional edges")
    Node_Add_Base_Data(test_node);
    Node_Add_Additional_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    for (int i = 0; i < 5; ++i)
        Node_Delete_Edge(test_node, (int*) &base_edges[i]);
    for (int i = 0; i < 3; ++i)
        Node_Delete_Edge(test_node, (int*) &additional_edges[i]);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Remove_Additional_Edges_Last, "Remove last 8 edges from node with base and additional edges")
    Node_Add_Base_Data(test_node);
    Node_Add_Additional_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    for (int i = 0; i < 9; ++i)
        Node_Delete_Edge(test_node, (int*) &additional_edges[10-i]);
    Node_Print(test_node);
ENDTEST

TEST(Test_Node_Search_Edge_Additional_Edges,"Search every second edge in node with base and additional edges" )
    Node_Add_Base_Data(test_node);
    Node_Add_Additional_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    for (int i = 1; i < base_edges_count; i+=2)
        Node_Print_Search_Edge(test_node, (int*) &base_edges[i]);
    for (int i = 0; i < additional_edges_count; i+=2)
        Node_Print_Search_Edge(test_node, (int*) &additional_edges[i]);
ENDTEST

TEST(Test_Node_Search_Empty_Node_Additional_Edges,"Search every second edge in empty node" )
    Node_Print(test_node);
    printf("\n");
    for (int i = 1; i < base_edges_count; i+=2)
        Node_Print_Search_Edge(test_node, (int*) &base_edges[i]);
    for (int i = 0; i < additional_edges_count; i+=2)
        Node_Print_Search_Edge(test_node, (int*) &additional_edges[i]);
ENDTEST

TEST(Test_Node_Get_Edge_On_Index, "Get every single edge of node")
    Node_Add_Base_Data(test_node);
    Node_Add_Additional_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    for (int i = 1; i < base_edges_count; i+=2)
        printf("Node on index %d: %d\n",(i+1),(*Node_Get_Edge(test_node,i)));
    for (int i = 0; i < additional_edges_count; i+=2)
        printf("Node on index %d: %d\n",(i+base_edges_count+1),(*Node_Get_Edge(test_node,i+base_edges_count)));
ENDTEST

TEST(Test_Node_Empty_Get_Edge, "Get non existing edge of node")
    Node_Print(test_node);
    printf("\n");
    for (int i = 1; i < base_edges_count; i+=2){
        printf("Node on index %d: ",(i+1));
        if (Node_Get_Edge(test_node,i) == NULL)
            printf("does not exist\n");
        else
            printf("%d\n",(*Node_Get_Edge(test_node,i)));
    }
    for (int i = 0; i < additional_edges_count; i+=2){
        printf("Node on index %d: ",(i+base_edges_count+1));
        if (Node_Get_Edge(test_node,i+base_edges_count+1) == NULL)
            printf("does not exist\n");
        else
            printf("%d\n",(*Node_Get_Edge(test_node,i)));
    }
ENDTEST

TEST(Test_Clear_Additional_Node,"Clear node with base and additional data")
    Node_Add_Base_Data(test_node);
    Node_Add_Additional_Data(test_node);
    Node_Print(test_node);
    printf("\n");
    Node_Delete_All_Edges(test_node);
    Node_Print(test_node);
ENDTEST

void Test_Node(){

    Node_Init_Test();

    Test_Node_Init();
    Test_Node_Set_Activity_Inactive();
    Test_Node_Set_Activity_Active();
    Test_Node_Set_Color_Gray();
    Test_Node_Add_Base_Edges();
    Test_Node_Remove_Edges_Last();
    Test_Node_Remove_Edges_First();
    Test_Node_Remove_Additional_Edges_First();
    Test_Node_Remove_Additional_Edges_Last();
    Test_Node_Search_Edge_Additional_Edges();
    Test_Node_Search_Empty_Node_Additional_Edges();
    Test_Node_Get_Edge_On_Index();
    Test_Node_Empty_Get_Edge();
    Test_Clear_Additional_Node();

}