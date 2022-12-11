#include <stdlib.h>
#include "SqStack.h"

_Bool InitStack(SqStack S)
{
    if (!S) return 0;

    S->base = (SqStack *)malloc(MAXLEN*sizeof(SqStack));
    if (!S->base) return 0;

    S->top = S->base;
    S->stacksize = MAXLEN;
    
    return 1;
}

_Bool StackEmpty(SqStack S)
{
    if (!S->base) return 0;
    return S->base == S->top;
}

int StackLength(SqStack S)
{
    if (!S->base) return 0;
    return S->top - S->base;
}

_Bool ClearStack(SqStack S)
{
    if (!S) return 0;
    if (!S->base) return 0;
    S->top = S->base;
    return 1;
}

_Bool DestroyStack(SqStack S)
{
    if (!S) return 0;
    if (!S->base) return 0;
    free(S->base);
    S->stacksize = 0;
    S->base = S->top = NULL;
    return 1;
}

_Bool Push(SqStack S, ElemType e)
{
    if (!S) return 0;
    if (!S->base) return 0;
    if (S->top-S->base == S->stacksize) return 0;

    *(S->top+1) = e;
    S->top++;

    return 1;
}

_Bool Pop(SqStack S, ElemType * e)
{
    if (!S) return 0;
    if (!S->base) return 0;
    if (S->top == S->base) return 0;
    
    *e = *S->top;
    S->top--;

    return 1;
}

_Bool GetTop(SqStack S, ElemType * e)
{
    if (!S) return 0;
    if (!S->base) return 0;

    *e = *S->top;

    return 1;
}
