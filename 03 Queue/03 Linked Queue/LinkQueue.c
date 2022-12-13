#include <stdlib.h>
#include <stdbool.h>
#include "LinkQueue.h"

/* Initialize queue Q */
void InitQueue(LinkQueue Q)
{
    Q = (LinkQueue) malloc(sizeof(LinkQueue));
    Q->front = Q->rear = NULL;
}

/* Destroy queue Q */
void DestroyQueue(LinkQueue Q)
{
    LinkNode * temp;
    if (Q->front)
    {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
}

/* Whether the queue Q is empty */
bool QueueEmpty(const LinkQueue Q)
{
    return Q->rear == NULL;
}

/* Put element e into queue Q */
void enQueue(LinkQueue Q, ElemType e)
{
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = e;
    if (!Q->rear)
    {
        Q->front = Q->rear = newNode;
        return;
    }
    
    Q->rear->next = newNode;
    Q->rear = newNode;
}

/* Dequeue an element from the queue Q */
bool deQueue(LinkQueue Q, ElemType * e)
{
    if (!Q->rear)
        return false;
    LinkNode * temp = Q->front;
    *e = temp->data;

    if (Q->front == Q->rear)
        Q->front = Q->rear = NULL;
    else
        Q->front = Q->front->next;
    
    free(temp);
    return true;
}