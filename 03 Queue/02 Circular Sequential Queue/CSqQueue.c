#include <stdlib.h>
#include <stdbool.h>
#include "CSqQueue.h"

/* Initialize queue Q */
void InitQueue(SqQueue * Q)
{
    Q = (SqQueue *) malloc(sizeof(SqQueue));
    Q->front = Q->rear = 0;
}

/* Destroy queue Q */
void DestroyQueue(SqQueue * Q)
{
    free(Q);
}

/* Whether the queue Q is empty */
bool QueueEmpty(const SqQueue * Q)
{
    return Q->front == Q->rear;
}

/* Put element e into queue Q */
bool enQueue(SqQueue * Q, ElemType e)
{
    if ((Q->rear+1)%MAXSIZE == Q->front)
        return false;
    Q->rear = (Q->rear+1)%MAXSIZE;
    Q->data[Q->rear] = e;
    return true;
}

/* Dequeue an element from the queue Q */
bool deQueue(SqQueue * Q, ElemType * e)
{
    if (Q->front == Q->rear)
        return false;
    Q->front = (Q->front+1)%MAXSIZE;
    *e = Q->data[Q->front];
    return true;
}