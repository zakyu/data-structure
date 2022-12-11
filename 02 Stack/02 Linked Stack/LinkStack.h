#ifndef STACK_H_
#define STACK_H_ 1
#define MAXLEN 100
typedef int ElemType;

struct node {
    ElemType data;
    struct node * next;
};
typedef struct node Node;
typedef struct node * LinkStack;

_Bool InitStack(LinkStack S);

_Bool StackEmpty(LinkStack S);

_Bool DestroyStack(LinkStack S);

int StackLength(LinkStack S);

_Bool GetTop(LinkStack S, ElemType * e);

_Bool ClearStack(LinkStack S);

_Bool Push(LinkStack S, ElemType e);

_Bool Pop(LinkStack S, ElemType * e);

#endif