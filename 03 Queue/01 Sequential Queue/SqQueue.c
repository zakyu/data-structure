#include <stdlib.h>
#include <stdbool.h>
#include "SqQueue.h"

/* Initialize queue Q */
void InitQueue(SqQueue * Q)
{
    Q = (SqQueue *) malloc(sizeof(SqQueue));
    Q->front = Q->rear = -1;
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
    if (Q->rear == MAXSIZE-1)
        return false;
    Q->rear++;
    Q->data[Q->rear] = e;
    return true;
}

/* Dequeue an element from the queue Q */
bool deQueue(SqQueue * Q, ElemType * e)
{
    if (Q->front == Q->rear)
        return false;
    Q->front++;
    *e = Q->data[Q->front];
    return true;
}