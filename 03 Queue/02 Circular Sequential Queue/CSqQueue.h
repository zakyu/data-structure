#ifndef SQQUEUE_H_
#define SQQUEUE_H_ 1

#define MAXSIZE 100

typedef int ElemType;

struct queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};
typedef struct queue SqQueue;

/* Initialize queue Q */
void InitQueue(SqQueue * Q);

/* Destroy queue Q */
void DestroyQueue(SqQueue * Q);

/* Whether the queue Q is empty */
bool QueueEmpty(const SqQueue * Q);

/* Put element e into queue Q */
bool enQueue(SqQueue * Q, ElemType e);

/* Dequeue an element from the queue Q */
bool deQueue(SqQueue * Q, ElemType * e);

#endif
