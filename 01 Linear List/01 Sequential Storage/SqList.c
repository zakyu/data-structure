#include <stdlib.h>
#include <stdbool.h>
#include "SqList.h"

void CreateList(SqList * L, const ElemType arr[], int size)
{
    L = (SqList *) malloc(sizeof(SqList));

    for (int i = 0; i < size; i++)
        L->data[i] = arr[i];
    L->length = size;
}

/* Initialize SqList L. */
void InitList(SqList * L)
{
    L = (SqList *) malloc(sizeof(SqList));
    L->length = 0;
}

/* Destroy SqList L. */
void DestroyList(SqList * L)
{
    free(L);
}

/* Return whether SqList L is empty. */
bool ListEmpty(const SqList * L)
{
    return L->length == 0;
}

/* Return the length of SqList L */
int ListLength(const SqList * L)
{
    return L->length;
}

/*
    Get the i-th element in SqList L and return it through element e.
    Return whether the element is returned successfully.
 */
bool GetElem(const SqList * L, int i, ElemType * e)
{
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i-1];
    return true;
}

/* Find the position of element e in SqList L by the rules of the function compare */
int LocateElem(const SqList * L, ElemType e, Compare compare)
{
    for (int i = 0; i < L->length; i++)
        if (compare(L->data[i], e)) return i+1;
    return 0;
}

/* Insert the element e into the i-th position of SqList L. */
bool ListInsert(SqList * L, int i, ElemType e)
{
    if (L->length == MAXSIZE) return false;
    if (i < 1 || i > L->length+1) return false;

    for (int j = L->length; j > i; j--)
        L->data[j] = L->data[j-1];
    
    L->data[i] = e;
    L->length++;

    return true;
}

/* Delete the i-th element from SqList L and return it through element e. */
bool ListDelete(SqList * L, int i, ElemType * e)
{
    if (L->length == 0) return false;
    if (i<1 || i >L->length+1) return false;

    *e = L->data[--i];
    for (int j = i; j < L->length-1; j++)
        L->data[j] = L->data[j+1];

    L->length--;

    return true;
}


void ListTraverse(SqList * L, Operate operate)
{
    for (int i = 0; i < L->length; i++)
        operate(&L->data[i]);
}
