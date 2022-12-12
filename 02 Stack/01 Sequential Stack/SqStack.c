#include <stdlib.h>
#include <stdbool.h>
#include "SqStack.h"

/* Initialize stack S. */
void InitStack(SqStack S)
{
    S = (SqStack)malloc(sizeof(SqStack));
    S->top = -1;
}

/* Destroy stack S. */
void DestroyStack(SqStack S)
{
    free(S);
}

/* Whether stack S is empty */
bool StackEmpty(SqStack S)
{
    return S->top == -1;
}

/* Push element e onto stack S */
bool Push(SqStack S, ElemType e)
{
    if (S->top == MAXSIZE -1)
        return false;
    S->top++;
    S->data[S->top] = e;
    return true;
}

/* Pop the top element of the stack S */
bool Pop(SqStack S, ElemType * e)
{
    if (S->top == -1)
        return false;
    *e = S->data[S->top];
    S->top--;
    return true;
}

/* Get the top element of the stack S */
bool GetTop(SqStack S, ElemType * e)
{
    if (S->top == -1)
        return false;
    *e = S->data[S->top];
    return true;
}