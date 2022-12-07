//
// Created by jakub on 6.12.22.
//
#include "../inc/algorithm.h"

bool isPlanar = true;

//stack start
typedef struct Stack_node_t{
    int data[STACK_MAX];
    int top;
    //int maxSize;
} Stack_node;

void stack_init(Stack_node *stackNode){
    stackNode->top = 0;
}

void stack_push(Stack_node *stackNode, int data){
    if(stackNode->top < STACK_MAX){
        stackNode->data[stackNode->top] = data;
        stackNode->top++;
    }
}

void stack_pop(Stack_node *stackNode){
    if(stackNode->top >0){
        stackNode->top--;
    }
}

int stack_get_top(Stack_node *stackNode){
    return stackNode->data[stackNode->top-1];
}

bool stack_is_empty(Stack_node *stackNode){
    return (stackNode->top == 0);
}

bool stack_is_full(Stack_node *stackNode){
    return (stackNode->top == STACK_MAX);
}
//stack end

int *Init(int id){
    int *pId = (int*) malloc (sizeof(int));
    *pId = id;
    return pId;
}
//set all is active can be reduced.
void set_all_is_active(Vector *graph){
    for(int i = 0; i < Graph_Get_Size(graph); i++){
        Node *node = Graph_Get_Node(graph, i);
        if(!Node_Get_Activity(node)){
            Node_Set_Activity(node, true);
        }
    }
}

void node_vs_edge(Vector *graph){
    int nodesCounter = Graph_Get_Size(graph);
    int edgesCounter = 0;
    int edgeReverseCounter = 0;
    List listNodes;
    List_Init(&listNodes);
    for(int i = 0; i < nodesCounter; i++){
        Node *node = Graph_Get_Node(graph, i);
        if(List_IsActive(&listNodes)) {
            while (listNodes.activeElement != NULL) {
                int nodeNumber = List_GetValue(&listNodes);
                int *edgeNodeNumber = Init(nodeNumber);
                if(Node_Search_Edge(node, edgeNodeNumber)){
                    edgeReverseCounter++;
                }
                List_Next(&listNodes);
                free(edgeNodeNumber);
            }
        }
        List_InsertFirst(&listNodes, i+1);
        /*NEWLINE;
        printf("line: %d", listNodes.firstElement->data);
        NEWLINE;*/
        List_First(&listNodes);
        edgesCounter += Vector_Size(Node_Get_Edges(node));
    }
    List_Dispose_line(&listNodes);

    /*NEWLINE;
    printf("edgesCounter: %d", edgesCounter);
    NEWLINE;
    NEWLINE;
    printf("edgesReverse: %d", edgeReverseCounter);
    NEWLINE;
    NEWLINE;
    printf("edges: %d", edgesCounter - edgeReverseCounter);
    NEWLINE;
    NEWLINE;
    printf("node: %d", 3*nodesCounter-6);
    NEWLINE;*/

    if((edgesCounter - edgeReverseCounter <= (3 * nodesCounter - 6))){
        return;
    }
    isPlanar =  false;
}

void loopEdge(Vector *graph){
    for(int i = 0; i < Graph_Get_Size(graph); i++) {
        Node *node = Graph_Get_Node(graph, i);
        int *selfEdge = Init(Node_Get_Id(node));
        if(Node_Search_Edge(node, selfEdge)){
            Node_Delete_Edge(node, selfEdge);
        }
        free(selfEdge);
    }

}

//homomorfismus -> deactivate Node and delete edge from other Nodes
void delete_if_two_edge(Vector *graph){
    for(int i = 0; i < Graph_Get_Size(graph); i++){
        Node *node = Graph_Get_Node(graph, i);
        //if Node is active
        if(Node_Get_Activity(node)){
            //if have only two edge
            if(Vector_Size(Node_Get_Edges(node)) == 2){
                //TODO smazat
                //printf("Node ID:%d\n", Node_Get_Id(node));
                Node_Set_Activity(node, false);
                int *right = Node_Get_Edge(node, 0);                    //right edge to node
                int *left = Node_Get_Edge(node, 1);                     //left edge to node
                //TODO smazat
                /*printf("rightedge ID:%d\n", *right);
                printf("leftedge ID:%d\n", *left);*/
                Node *rightNode = Graph_Get_Node(graph, *right-1);         //right node
                Node *leftNode = Graph_Get_Node(graph, *left-1);           //left node

                //TODO smazat
                //printf("right ID:%d\n", Node_Get_Id(rightNode));
                //printf("left ID:%d\n", Node_Get_Id(leftNode));
                //if right node have left edge -> dont work
                if(!Node_Search_Edge(rightNode, left)){
                    Node_Add_Edge(rightNode, left);
                    Node_Add_Edge(leftNode, right);
                }
                //erase old edge
                int *oldNodeEdge = Init(Node_Get_Id(node));                 //alloc tmp edge
                Node_Delete_Edge(rightNode, oldNodeEdge);
                Node_Delete_Edge(leftNode, oldNodeEdge);
                free(oldNodeEdge);
            }
        }
    }
}

bool k_five(Vector *graph, Stack_node *stackNode){
    int cntEdges = 0;
    for(int i = 0; i < Graph_Get_Size(graph); i++){
        Node *node = Graph_Get_Node(graph ,i);
        if(Node_Get_Activity(node)){
            cntEdges += Vector_Size(Node_Get_Edges(node));
        }
    }

    NEWLINE;
    printf("Number of edges: %d", cntEdges);
    NEWLINE;

    if(cntEdges == 20){
        return true;
    }
    return false;
}

void delete_edge_from_nodes(Vector *graph, Stack_node *stackNode){
    Node *node, *nodeFromStack;
    nodeFromStack = Graph_Get_Node(graph, stack_get_top(stackNode));
    int deleteEdge = Node_Get_Id(nodeFromStack);
    for(int i = 0; i < Graph_Get_Size(graph);i++){
        node = Graph_Get_Node(graph,i);
        if(Node_Get_Activity(node)){
            //printf("DELETE");
            /*NEWLINE;
            Node_Print(node);
            NEWLINE;*/
            Node_Delete_Edge(node , &deleteEdge);
            /*NEWLINE;
            Node_Print(node);
            NEWLINE;*/
        }
    }

}

void add_edge_from_stack(Vector *graph, Stack_node *stackNode){
    int indexFromStack = stack_get_top(stackNode);
    Node *nodeFromStack = Graph_Get_Node(graph, indexFromStack);
    Node *node;
    int *edge = Init(Node_Get_Id(nodeFromStack));
    int element;
    //printf("edge: %d\n", *edge);
    for(int i = 0; i < Vector_Size(Node_Get_Edges(nodeFromStack)); i++){
        element = *((int *) Vector_GetElement(Node_Get_Edges(nodeFromStack), i));
        //printf("vector: %d\n", element);
        for(int j = 0; j < Graph_Get_Size(graph); j++){
            node = Graph_Get_Node(graph, j);
            if(Node_Get_Id(node) == element){
                //printf("ADD");
                /*NEWLINE;
                Node_Print(node);
                NEWLINE;*/
                if(!Node_Search_Edge(node, edge)) {
                    Node_Add_Edge(node, edge);
                }
                /*NEWLINE;
                Node_Print(node);
                NEWLINE;*/
            }
        }
    }
    Node_Set_Activity(nodeFromStack, true);
    //printf("ID node %d\n", Node_Get_Id(nodeFromStack));
    //printf("size Vector %d\n", *((int *) Vector_GetElement(Node_Get_Edges(nodeFromStack), 1)));
}

void push_recursion(Vector *graph, Stack_node *stackNode, int index, int firstActiveNode){
    //push
    stack_push(stackNode, index);
    Node *deleteNode = Graph_Get_Node(graph, index);
    Node_Set_Activity(deleteNode, false);
    delete_edge_from_nodes(graph, stackNode);

    //check active Node
    int cntActiveNodes = 0;
    for(int k = 0; k < Graph_Get_Size(graph); k++){
        Node *node = Graph_Get_Node(graph, k);
        if(Node_Get_Activity(node)){
            cntActiveNodes++;
            index = k;
        }
    }
    //recursion
    if(cntActiveNodes != 5){
        push_recursion(graph, stackNode, index, firstActiveNode);
    }


    int indexPush;
    while(stack_get_top(stackNode) != firstActiveNode){
        int indexPop = stack_get_top(stackNode);
        indexPush = 0;

        if(cntActiveNodes != 5){
            push_recursion(graph, stackNode, index, firstActiveNode);
        }


            for (int i = 0; i < Graph_Get_Size(graph); i++) {
                Node *node = Graph_Get_Node(graph, i);
                if (Node_Get_Activity(node)) {
                    if (indexPush < indexPop - 1) {
                        indexPush = i;
                    }
                }
            }

        if(k_five(graph, stackNode) || !isPlanar) {
            isPlanar = false;
            return;
        }
            add_edge_from_stack(graph, stackNode);
            stack_pop(stackNode);

            stack_push(stackNode, indexPush);
            Node *deleteSecondNode = Graph_Get_Node(graph, stack_get_top(stackNode));
            Node_Set_Activity(deleteSecondNode, false);
            delete_edge_from_nodes(graph, stackNode);

    }

    Graph_Print(graph);

    add_edge_from_stack(graph, stackNode);
    stack_pop(stackNode);

    }



void subgraph(Vector *graph, Stack_node *stackNode){
    int cntActiveNodes = 0;
    int lastActiveNode = 0;
    int firstActiveNode = Graph_Get_Size(graph);

    //setup cnt, last and first active
    for(int i = 0; i < Graph_Get_Size(graph); i++){
        Node *node = Graph_Get_Node(graph, i);
        if(Node_Get_Activity(node)){
            cntActiveNodes++;
            lastActiveNode = i;
            if (firstActiveNode > i){
                firstActiveNode = i;
            }
        }
    }

    /*NEWLINE;
    printf("cnt: %d\n", cntActiveNodes);
    NEWLINE;
    NEWLINE;
    printf("fisrtactive: %d\n", firstActiveNode);
    NEWLINE;
    NEWLINE;
    printf("lastactive: %d\n", lastActiveNode);
    NEWLINE;*/

    //first index
    int index = 0;
    for(int j = 0; j < Graph_Get_Size(graph); j++){
        Node *searchNode = Graph_Get_Node(graph, j);
        Node *lastActive = Graph_Get_Node(graph, lastActiveNode);
        if(Node_Get_Id(lastActive) == Node_Get_Id(searchNode)){
            index = j;
            break;
        }
    }

    push_recursion(graph, stackNode, index, firstActiveNode);
}

//TODO smazat
/*void pop_for_debug(Stack_node *stackNode){
    while (!stack_is_empty(stackNode)) {
        NEWLINE;
        printf("Stack: %d", stack_get_top(stackNode));
        NEWLINE;
        stack_pop(stackNode);
    }
}*/

//main function in algorithm
void algorithm(Vector *graph){
    Stack_node stackNode;
    stack_init(&stackNode);
    loopEdge(graph);
    set_all_is_active(graph);
    node_vs_edge(graph);
    if(!isPlanar){
        NEWLINE;
        printf("Graph isn't planar.");
        NEWLINE;
        //Graph_Destroy(graph);
        return;
    }
    delete_if_two_edge(graph);
    subgraph(graph, &stackNode);
    if(!isPlanar){
        NEWLINE;
        printf("Graph isn't planar.");
        NEWLINE;
        //Graph_Destroy(graph);
        return;
    }else{
        printf("Graph is planar.");
    }
    //pop_for_debug(&stackNode);

}