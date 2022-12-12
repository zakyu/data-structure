#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_ 1

#define MAXSIZE 100

typedef int ElemType;

struct node {
    ElemType data;
    struct node * next;
};
typedef struct node LinkNode;
typedef struct node * LinkStack;

/* Initialize stack S. */
void InitStack(LinkStack S);

/* Destroy stack S. */
void DestroyStack(LinkStack S);

/* Whether stack S is empty */
bool StackEmpty(LinkStack S);

/* Push element e onto stack S */
bool Push(LinkStack S, ElemType e);

/* Pop the top element of the stack S */
bool Pop(LinkStack S, ElemType * e);

/* Get the top element of the stack S */
bool GetTop(LinkStack S, ElemType * e);

#endif