#ifndef SQSTACK_H_
#define SQSTACK_H_ 1

#define MAXSIZE 100

typedef int ElemType;

struct stack {
    ElemType data[MAXSIZE];
    int top;
};
typedef struct stack * SqStack;

/* Initialize stack S. */
void InitStack(SqStack S);

/* Destroy stack S. */
void DestroyStack(SqStack S);

/* Whether stack S is empty */
bool StackEmpty(SqStack S);

/* Push element e onto stack S */
bool Push(SqStack S, ElemType e);

/* Pop the top element of the stack S */
bool Pop(SqStack S, ElemType * e);

/* Get the top element of the stack S */
bool GetTop(SqStack S, ElemType * e);

#endif