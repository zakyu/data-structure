#ifndef LINKLIST_H_
#define LINKLIST_H_ 1

typedef int ElemType;

struct node
{
    ElemType data;
    struct node * next;
};
typedef struct node LinkNode;
typedef struct node * LinkList;

void CreateListF(LinkList L, ElemType arr[], int size);

void CreateListR(LinkList L, ElemType arr[], int size);

/* Initialize L. */
void * InitList(LinkList L);

/* Destroy L. */
void DestroyList(LinkList L);

/* Return whether L is empty. */
bool ListEmpty(const LinkList L);

/* Return the length of L */
int ListLength(const LinkList L);

/*
    Get the i-th element in L and return it through element e.
    Return whether the element is returned successfully.
 */
bool GetElem(const LinkList L, int i, ElemType * e);

struct elem_info
{
    int index;
    LinkNode * linkNode;
};
typedef struct elem_info ELEM_INFO;

/* Comparing element e and elements of L by some rules */
typedef _Bool (* Compare)(ElemType, ElemType);

/* Find the position of element e in L by the rules of the function compare */
ELEM_INFO * LocateElem(const LinkList L, ElemType e, Compare compare);

/* Insert the element e into the i-th position of L. */
bool ListInsert(LinkList L, int i, ElemType e);

/* Delete the i-th element from L. */
bool ListDelete(LinkList L, int i, ElemType * e);

/* Operate on element e */
typedef ElemType (* Operate)(ElemType * e);

/* Iterate over the elements of L and process the elements with function operate */
void ListTraverse(LinkList L, Operate operate);

#endif
