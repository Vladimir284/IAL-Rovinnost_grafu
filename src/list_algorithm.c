//
// Created by jakub on 6.12.22.
//
#include "../inc/list_algorithm.h"

void List_Init( List *list ) {
    list->activeElement = NULL;
    list->firstElement = NULL;
}

void List_Dispose_line( List *list ) {
    if(list->firstElement != NULL){
        while(list->firstElement->nextElement != NULL){
            ListElementPtr elemPtr;
            elemPtr = list->firstElement;
            list->firstElement = elemPtr->nextElement;
            free(elemPtr);
        }
        ListElementPtr elemPtr;
        elemPtr = list->firstElement;
        free(elemPtr);
        list->firstElement = NULL;
        list->activeElement = NULL;
    }
}

void List_InsertFirst( List *list, int data ) {
    ListElementPtr newElemPtr = (ListElementPtr) malloc(sizeof(struct ListElement));
    if (newElemPtr == NULL){
        fprintf(stderr, "ERROR: Bad allocation.\n");
        exit(-1);
    }
    newElemPtr->data = data;
    newElemPtr->nextElement = list->firstElement;
    list->firstElement = newElemPtr;
}

void List_First( List *list ) {
    if(list->firstElement != NULL) {
        list->activeElement = list->firstElement;
    }
}

int List_GetValue( List *list) {
        return list->activeElement->data;
}

void List_Next( List *list ) {
    if(list->activeElement != NULL){
        list->activeElement = list->activeElement->nextElement;
    }
}

bool List_Search(List *list, int data){
    List_First(list);
    if(list->activeElement == NULL){
        return false;
    }
    else if(list->activeElement->data == data){
        return true;
    }
}

int List_IsActive( List *list ) {
    return list->activeElement != NULL ? 1 : 0;
}