#ifndef SQLIST_H_
#define SQLIST_H_ 1

#define MAXLEN 100

typedef char ElemType;

typedef struct
{
    ElemType * elem;
    int length;
} SqList;

/* Comparing element e and elements of SqList L by some rules */
typedef _Bool (* Compare)(SqList, int, ElemType*);

/* Initialize SqList L. Return whether it is successful. */
_Bool InitList(SqList * L);

/* Destroy SqList L. Return whether it is successful. */
_Bool DestroyList(SqList * L);

/* Clear SqList L. Return whether it is successful. */
_Bool ClearList(SqList * L);

/* Return whether SqList L is empty. */
_Bool ListEmpty(SqList L);

/* Return the length of SqList L */
int ListLength(SqList L);

/*
    Get the i-th element in SqList L and return it through element e.
    Return whether the element is returned successfully.
 */
_Bool GetElem(SqList L, int i, ElemType * e);

/* Find the position of element e in SqList L by the rules of the function compare */
int LocateElem(SqList L, ElemType * e, Compare compare);

/* Insert the element e into the i-th position of SqList L. */
_Bool ListInsert(SqList * L, int i, ElemType e);

/* Delete the i-th element from SqList L. */
_Bool ListDelete(SqList * L, int i, ElemType * e);
#endif