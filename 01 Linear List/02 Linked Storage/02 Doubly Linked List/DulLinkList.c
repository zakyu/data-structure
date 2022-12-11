#include <stdlib.h>
#include "DulLinkList.h"

_Bool * InitList(DulLinkList L)
{
    if (!L) return 0;
    L = (Node *) malloc(sizeof(Node));
    L->next = NULL;
    L->next = NULL;
    return 1;
}

_Bool ListInsert(DulLinkList L, int i, ElemType e)
{
    if (!L) return 0;
    if (i < 1) return 0;

    int index = 1;
    Node * temp = L->next;
    while (temp && index < i)
    {
        temp = temp->next;
        i++;
    }
    if (!temp || index < i) return 0;
    
    Node * new = (Node *) malloc(sizeof(Node));
    new->data = e;
    new->prior = temp->prior;
    new->next = temp;
    temp->prior->next = new;
    temp->prior = new;

    return 1;
}

_Bool ListDelete(DulLinkList L, int i, ElemType * e)
{
    if (!L) return 0;
    if (i < 1) return 0;

    int index = 1;
    Node * temp = L->next;
    while (temp && index < i)
    {
        temp = temp->next;
        i++;
    }
    if (!temp || index < i) return 0;

    Node * target = (Node *) malloc(sizeof(Node));
    *e = target->data;
    target->prior->next = target->next;
    target->next->prior = target->prior;
    free(target);
    return 1;
}