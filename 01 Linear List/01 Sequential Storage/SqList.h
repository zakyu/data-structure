#ifndef SQLIST_H_
#define SQLIST_H_ 1
#define MAXSIZE 100

typedef char ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;

void CreateList(SqList * L, const ElemType arr[], int size);

/* Initialize L. */
void InitList(SqList * L);

/* Destroy L. */
void DestroyList(SqList * L);

/* Return whether L is empty. */
bool ListEmpty(const SqList * L);

/* Return the length of L */
int ListLength(const SqList * L);

/*
    Get the i-th element in L and return it through element e.
    Return whether the element is returned successfully.
 */
bool GetElem(const SqList * L, int i, ElemType * e);

/* Comparing element e and elements of L by some rules */
typedef bool (* Compare)(ElemType, ElemType);

/* Find the position of element e in L by the rules of the function compare */
int LocateElem(const SqList * L, ElemType e, Compare compare);

/* Insert the element e into the i-th position of L. */
bool ListInsert(SqList * L, int i, ElemType e);

/* Delete the i-th element from L. */
bool ListDelete(SqList * L, int i, ElemType * e);

/* Operate on element e */
typedef ElemType (* Operate)(ElemType * e);

/* Iterate over the elements of L and process the elements with function operate */
void ListTraverse(SqList * L, Operate operate);

#endif
