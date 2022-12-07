//
// Created by jakub on 6.12.22.
//

#ifndef IAL_ROVINNOST_GRAF_LIST_ALGORITHM_H
#define IAL_ROVINNOST_GRAF_LIST_ALGORITHM_H

#include "algorithm.h"

typedef struct ListElement {
    int data;
    struct ListElement *nextElement;
} *ListElementPtr;

//linked list
typedef struct {
    ListElementPtr firstElement;
    ListElementPtr activeElement;
} List;

void List_Init( List * );

void List_Dispose_line( List * );

void List_InsertFirst( List *, int );

void List_First( List * );

void List_Next( List * );

int List_GetValue( List *);

int List_IsActive( List *list );

bool List_Search(List *list, int data);





#endif //IAL_ROVINNOST_GRAF_LIST_ALGORITHM_H
