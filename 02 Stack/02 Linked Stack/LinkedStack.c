#include <stdlib.h>
#include <stdbool.h>
#include "LinkedStack.h"

/* Initialize stack S. */
void InitStack(LinkStack S)
{
    S = (LinkStack *) malloc(sizeof(LinkStack));
    S->next = NULL;
}

/* Destroy stack S. */
void DestroyStack(LinkStack S)
{
    LinkNode * temp;
    while (S)
    {
        temp = S;
        S = S->next;
        free(temp);
    }
}

/* Whether stack S is empty */
bool StackEmpty(LinkStack S)
{
    return S->next == NULL;
}

/* Push element e onto stack S */
bool Push(LinkStack S, ElemType e)
{
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = e;
    newNode->next = S->next;
    S->next = newNode;
}

/* Pop the top element of the stack S */
bool Pop(LinkStack S, ElemType * e)
{
    if (!S->next)
        return false;
    LinkNode * top = (LinkNode *)malloc(sizeof(LinkNode));
    top = S->next;
    *e = top->data;
    S->next = top->next;
    free(top);
    return true;
}

/* Get the top element of the stack S */
bool GetTop(LinkStack S, ElemType * e)
{
    if (!S->next)
        return false;
    *e = S->next->data;
    return true;
}