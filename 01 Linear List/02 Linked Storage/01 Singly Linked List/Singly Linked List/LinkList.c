#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

_Bool * InitList(LinkList L)
{
    if (!L) return 0;
    L = (LinkList *) malloc(sizeof(Node));
    L->next = NULL;
    return 1;
}

void Create(LinkList L, ElemType * data, int len)
{
    L = (Node *) malloc(sizeof(Node));
    L->next = NULL;
    int i = len-1;
    while(i >= 0)
    {
        Node * new = (Node *) malloc(sizeof(Node));
        new->data = data[i--];
        new->next = L->next;
        L->next = new;
    }
}

void Create_R(LinkList L, ElemType * data, int len)
{
    L = (Node *) malloc(sizeof(Node));
    L->next = NULL;
    Node * last = L;
    int i = 0;
    while (i < len)
    {
        Node * new = (Node *) malloc(sizeof(Node));
        new->next = NULL;
        new->data = data[i++];
        last->next = new;
        last = new;
    }
}

_Bool ListEmpty(LinkList L)
{
    if (!L) return 0;
    return L->next == NULL;
}

_Bool DestroyList(LinkList L)
{
    if (!L) return 0;
    Node * temp;
    while(L)
    {
        temp = L;
        L = L->next;
        free(temp);
    }
    return 1;
}

_Bool ClearList(LinkList L)
{
    if (!L) return 0;
    Node * next = L->next;
    Node * temp;
    while(next)
    {
        temp = next;
        next = next->next;
        free(temp);
    }
    L->next = NULL;
    return 1;
}

int ListLength(LinkList L)
{
    if(!L) return -1;
    if(!L->next) return 0;
    int len = 1;
    Node * temp = L->next->next;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

_Bool GetElem(LinkList L, int i, ElemType * e)
{
    if (!L) return 0;
    if (i < 1) return 0;
    Node * temp = L->next;
    int index = 1;
    while (temp && index < i)
    {
        temp->next;
        index ++;
    }
    if (i != index) return 0;
    *e = temp->data;
    return 1;
}

ELEM_INFO * LocateElem(LinkList L, ElemType e, Compare compare)
{
    if (!L) return NULL;
    ELEM_INFO * info = {-1, NULL};
    Node * temp = L->next;
    int index = 1;
    while (temp && !compare(temp->data, e))
    {
        temp = temp->next;
        index++;
    }
    if (temp)
    {
        info->index = index;
        info->pointer = temp;
    }
    return info;
}

_Bool ListInsert(LinkList L, int i, ElemType e)
{
    if (!L) return 0;
    int index = 1;
    Node * temp = L->next;
    while (temp && index < i-1)
    {
        temp = temp->next; 
        index++;
    }
    if (!temp || index > i-1) return 0;

    Node * new = (Node *) malloc(sizeof(Node));
    new->data = e;
    new->next = temp->next;
    temp->next = new;
    return 1;
}

_Bool ListDelete(LinkList L, int i, ElemType * e)
{
    if (!L) return 0;
    int index = 1; 
    Node * temp = L->next;
    while (temp && index < i-1)
    {
        temp = temp->next; 
        index++;
    }
    if (!temp || index > i-1) return 0;

    Node * target = temp->next;
    *e = target->data;
    temp->next = target->next;
    free(target);
    return 1;
}