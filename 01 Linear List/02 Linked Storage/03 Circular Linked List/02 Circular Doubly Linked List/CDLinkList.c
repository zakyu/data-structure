#include <stdlib.h>
#include <stdbool.h>
#include "CDLinkList.h"

void CreateListF(DLinkList L, ElemType arr[], int size)
{
    L = (DLinkList) malloc(sizeof(DLinkList));
    L->prior = L->next = L;

    DLinkNode * newNode;
    for (int i = 0; i < size; i++)
    {
        newNode = (DLinkNode *) malloc(sizeof(DLinkNode));
        newNode->data = arr[i];
        if (L->next)
            L->next->prior = newNode;
        newNode->next = L->next;
        newNode->prior = L;
        L->next = newNode;
    }
}

void CreateListR(DLinkList L, ElemType arr[], int size)
{
    L = (DLinkList) malloc(sizeof(DLinkList));
    
    DLinkNode * lastNode = L;
    DLinkNode * newNode;
    for (int i = 0; i < size; i++)
    {
        newNode = (DLinkNode *) malloc(sizeof(DLinkNode));
        newNode->data = arr[i];
        
        lastNode->next = newNode;
        newNode->prior = lastNode;
        lastNode = newNode;
    }
    lastNode->next = L;
}

/* Initialize L. */
void * InitList(DLinkList L)
{
    L = (DLinkList *) malloc(sizeof(DLinkList));
    L->prior = L;
    L->next = L;
}

/* Destroy L. */
void DestroyList(DLinkList L)
{
    DLinkList * temp;
    while(L)
    {
        temp = L;
        L = L->next;
        free(temp);
    }
}

/* Return whether L is empty. */
bool ListEmpty(const DLinkList L)
{
    return L->next == L;
}

/* Return the length of L */
int ListLength(const DLinkList L)
{
    int len = 0;
    DLinkNode * temp = L;
    while (temp->next != L)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

/*
    Get the i-th element in L and return it through element e.
    Return whether the element is returned successfully.
 */
bool GetElem(const DLinkList L, int i, ElemType * e)
{
    DLinkNode * temp = L;

    int index = 0;
    while (index < i && temp != L)
    {
        index ++;
        temp = temp->next;
    }

    if (temp == L) return false;

    *e = temp->data;
    return true;   
}

/* Find the position of element e in L by the rules of the function compare */
ELEM_INFO * LocateElem(const DLinkList L, ElemType e, Compare compare)
{
    ELEM_INFO * info = {-1, NULL};
    int index = 1;

    DLinkNode * temp = L->next;
    while (temp != L && !compare(temp->data, e))
    {
        temp = temp->next;
        index++;
    }
    if (temp != L)
    {
        info->index = index;
        info->dLinkNode = temp;
    }
    return info; 
}

/* Insert the element e into the i-th position of L. */
bool ListInsert(DLinkList L, int i, ElemType e)
{
    int index = 0;
    DLinkNode * temp = L;
    while (index < i && temp != L)
    {
        index++;
        temp = temp->next;
    }
    if (temp == L) return 0;
    
    DLinkNode * newNode = (DLinkNode *) malloc(sizeof(DLinkNode));
    newNode->data = e;
    if (temp->next != L)
        temp->next->prior = newNode;
    newNode->next = temp->next;
    newNode->prior = temp;
    temp->next = newNode;
    return true;
}

/* Delete the i-th element from L. */
bool ListDelete(DLinkList L, int i, ElemType * e)
{
    int index = 0;
    DLinkNode * temp = L;
    while (index < i && temp != L)
    {
        index++;
        temp = temp->next;
    }
    if (temp == L || temp->next == L) return false;

    DLinkNode * target = temp->next;
    *e = target->data;
    if (target->next != L)
        target->next->prior = temp;
    temp->next = target->next;
    free(target);
    return true;
}

/* Iterate over the elements of L and process the elements with function operate */
void ListTraverse(DLinkList L, Operate operate)
{
    DLinkNode * temp = L;
    while (temp != L)
    {
        operate(&temp->data);
        temp = temp->next;
    }
}
