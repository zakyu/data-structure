#ifndef SQQUEUE_H_
#define SQQUEUE_H_ 1

typedef int ElemType;

struct node
{
    ElemType data;
    struct node * next;
};
typedef struct node LinkNode;

struct lNode
{
    LinkNode * front;
    LinkNode * rear;
};
typedef struct lNode * LinkQueue;

/* Initialize queue Q */
void InitQueue(LinkQueue Q);

/* Destroy queue Q */
void DestroyQueue(LinkQueue Q);

/* Whether the queue Q is empty */
bool QueueEmpty(const LinkQueue Q);

/* Put element e into queue Q */
void enQueue(LinkQueue Q, ElemType e);

/* Dequeue an element from the queue Q */
bool deQueue(LinkQueue Q, ElemType * e);

#endif