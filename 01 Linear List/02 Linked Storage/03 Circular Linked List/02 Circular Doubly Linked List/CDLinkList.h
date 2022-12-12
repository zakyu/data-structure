#ifndef DULLINKLIST_H_
#define DULLINKLIST_H_ 1

typedef int ElemType;

struct node
{
    ElemType data;
    struct node * prior;
    struct node * next;
};
typedef struct node DLinkNode;
typedef struct node * DLinkList;

void CreateListF(DLinkList L, ElemType arr[], int size);

void CreateListR(DLinkList L, ElemType arr[], int size);

/* Initialize L. */
void * InitList(DLinkList L);

/* Destroy L. */
void DestroyList(DLinkList L);

/* Return whether L is empty. */
bool ListEmpty(const DLinkList L);

/* Return the length of L */
int ListLength(const DLinkList L);

/*
    Get the i-th element in L and return it through element e.
    Return whether the element is returned successfully.
 */
bool GetElem(const DLinkList L, int i, ElemType * e);

struct elem_info
{
    int index;
    DLinkNode * dLinkNode;
};
typedef struct elem_info ELEM_INFO;

/* Comparing element e and elements of L by some rules */
typedef _Bool (* Compare)(ElemType, ElemType);

/* Find the position of element e in L by the rules of the function compare */
ELEM_INFO * LocateElem(const DLinkList L, ElemType e, Compare compare);

/* Insert the element e into the i-th position of L. */
bool ListInsert(DLinkList L, int i, ElemType e);

/* Delete the i-th element from L. */
bool ListDelete(DLinkList L, int i, ElemType * e);

/* Operate on element e */
typedef ElemType (* Operate)(ElemType * e);

/* Iterate over the elements of L and process the elements with function operate */
void ListTraverse(DLinkList L, Operate operate);

#endif
