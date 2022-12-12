#ifndef SQQUEUE_H_
#define SQQUEUE_H_ 1

#define MAXLEN 100

typedef int ElemType;

struct queue
{
    ElemType * base;
    int front;
    int rear;
};
typedef struct queue SqQueue;

_Bool InitQueue(SqQueue * Q)
{

}


#endif
