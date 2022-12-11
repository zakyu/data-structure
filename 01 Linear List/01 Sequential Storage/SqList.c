#include <stdlib.h>
#include <SqList.h>

/*
    Initialize SqList L.
    Return whether it is successful.
 */
_Bool * InitList(SqList * L)
{
    if (!L) return 0;
    L->elem = (ElemType *) malloc(MAXLEN*sizeof(ElemType));
    if(!L->elem) return 0;
    L->length = 0;
    return 1;
}

/*
    Destroy SqList L.
    Return whether it is successful.
 */
_Bool DestroyList(SqList * L)
{
    if (!L) return 0;
    free(L->elem); 
    return 1;
}

/*
    Clear SqList L.
    Return whether it is successful.
 */
_Bool ClearList(SqList * L)
{
    if(!L) return 0;
    L->length = 0;
    return 1;
}

/*
    Return whether SqList L is empty.
 */
_Bool ListEmpty(SqList L)
{
    return L.length == 0;
}

/*
    Return the length of SqList L
 */
int ListLength(SqList L)
{
    return L.length;
}

/*
    Get the i-th element in SqList L and return it through element e.
    Return whether the element is returned successfully.
 */
_Bool GetElem(SqList L, int i, ElemType * e)
{
    if (i < 1 || i > L.length) return 0;
    e = L.elem[i-1];
    return 1;
}

/* Find the position of element e in SqList L by the rules of the function compare */
int LocateElem(SqList L, ElemType * e, Compare compare)
{
    for (int i = 0; i < L.length; i++)
        if (compare(L, i, e)) return i+1;
    return -1;
}

/* Insert the element e into the i-th position of SqList L. */
_Bool ListInsert(SqList * L, int i, ElemType e)
{
    if (!L) return 0;
    if (L->length == MAXLEN) return 0;
    if (i<1 || i >L->length+1) return 0;

    for (int j = L->length-1; j > 0; j--)
        L->elem[j+1] = L->elem[j];
    
    L->elem[i-1] = e;
    L->length++;

    return 1;
}

/* Delete the i-th element from SqList L. */
_Bool ListDelete(SqList * L, int i)
{
    if (!L) return 0;
    if (L->length == 0) return 0;
    if (i<1 || i >L->length+1) return 0;

    for (int j = i; j < L->length-1; j++)
        L->elem[i] = L->elem[i+1];
    L->length--;

    return 1;
}
