#include <stdlib.h>
#include "LinkStack.h"

_Bool InitStack(LinkStack S)
{
    S = NULL;
    return 0;
}

_Bool StackEmpty(LinkStack S)
{
    return !S;
}

_Bool DestroyStack(LinkStack S)
{
    if (!S) return 0;

    Node * temp;
    while(S)
    {
        temp = S;
        S = S->next;
        free(temp);
    }
    
    return 1;
}

int StackLength(LinkStack S)
{
    if (!S) return 0;
    int len = 0;
    Node * temp = S;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    
    return len;
}

_Bool ClearStack(LinkStack S)
{
    if (!S) return 0;

    Node * temp;
    while(S->next)
    {
        temp = S;
        S = S->next;
        free(temp);
    }
    
    return 1;
}

_Bool Push(LinkStack S, ElemType e)
{
    Node * top = (Node *) malloc(sizeof(Node));
    if (!top) return 0;
    top->data = e;
    top->next = S;
    S = top;
    return 1;
}

_Bool Pop(LinkStack S, ElemType * e)
{
    if (!S) return 0;
    Node * top = S;
    *e = top->data;
    S = top->next;
    free(top);

    return 0;
}

_Bool GetTop(LinkStack S, ElemType * e)
{
    if (!S) return 0;
    *e = S->data;
    return 1;
}