#ifndef STACK_H_
#define STACK_H_ 1
#define MAXLEN 100
typedef int ElemType;

struct stack {
    ElemType * top;
    ElemType * base;
    int stacksize;
};
typedef struct stack * SqStack;

_Bool InitStack(SqStack S);

_Bool StackEmpty(SqStack S);

_Bool DestroyStack(SqStack S);

int StackLength(SqStack S);

_Bool GetTop(SqStack S, ElemType * e);

_Bool ClearStack(SqStack S);

_Bool Push(SqStack S, ElemType e);

_Bool Pop(SqStack S, ElemType * e);

#endif