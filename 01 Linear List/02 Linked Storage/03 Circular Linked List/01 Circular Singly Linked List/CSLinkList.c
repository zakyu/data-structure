#include <stdlib.h>
#include <stdbool.h>
#include "CSLinkList.h"

void CreateListF(LinkList L, ElemType arr[], int size)
{
    L = (LinkList *) malloc(sizeof(LinkList));
    L->next = L;

    LinkNode * newNode;
    for (int i = 0; i < size; i++)
    {
        newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->data = arr[i];
        newNode->next = L->next;
        L->next = newNode;
    }
}

void CreateListR(LinkList L, ElemType arr[], int size)
{
    L = (LinkList *) malloc(sizeof(LinkList));

    LinkNode * last = L;
    LinkNode * newNode;
    for (int i = 0; i < size; i++)
    {
        newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->data = arr[i];
        last->next = newNode;
        last = newNode;
    }
    last->next = L;
}

/* Initialize L. */
void * InitList(LinkList L)
{
    L = (LinkList *) malloc(sizeof(LinkList));
    L->next = L;
}

/* Destroy L. */
void DestroyList(LinkList L)
{
    LinkNode * temp;
    while(L)
    {
        temp = L;
        L = L->next;
        free(temp);
    }
}

/* Return whether L is empty. */
bool ListEmpty(const LinkList L)
{
    return L->next == L;
}

/* Return the length of L */
int ListLength(const LinkList L)
{
    int len = 0;
    LinkNode * temp = L;
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
bool GetElem(const LinkList L, int i, ElemType * e)
{
    LinkNode * temp = L;

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
ELEM_INFO * LocateElem(const LinkList L, ElemType e, Compare compare)
{
    ELEM_INFO * info = {-1, NULL};
    int index = 1;

    LinkNode * temp = L->next;
    while (temp != L && !compare(temp->data, e))
    {
        temp = temp->next;
        index++;
    }
    if (temp != L)
    {
        info->index = index;
        info->linkNode = temp;
    }
    return info;
}

/* Insert the element e into the i-th position of L. */
bool ListInsert(LinkList L, int i, ElemType e)
{
    int index = 0;
    LinkNode * temp = L;
    while (index < i-1 && temp != L)
    {
        index++;
        temp = temp->next;
    }
    if (temp == L) return false;

    LinkNode * newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = e;
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}

/* Delete the i-th element from L. */
bool ListDelete(LinkList L, int i, ElemType * e)
{
    int index = 0; 
    LinkNode * temp = L;
    while (index < i-1 && temp != L)
    {
        index++;
        temp = temp->next;
    }
    if (temp == L || temp->next == L) return false;

    LinkNode * target = temp->next;
    *e = target->data;
    temp->next = target->next;
    free(target);
    return true;
}

/* Iterate over the elements of L and process the elements with function operate */
void ListTraverse(LinkList L, Operate operate)
{
    LinkNode * temp = L;
    while (temp != L)
    {
        operate(&temp->data);
        temp = temp->next;
    }
}
