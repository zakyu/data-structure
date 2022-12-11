#ifndef DULLINKLIST_H_
#define DULLINKLIST_H_

typedef int ElemType;

struct node
{
    ElemType data;
    struct node *prior, *next;
};
typedef struct node Node;
typedef struct node * DulLinkList;

struct elem_info
{
    int index;
    Node * pointer;
};
typedef struct elem_info ELEM_INFO;

_Bool * InitList(DulLinkList L);

void Create(DulLinkList L, ElemType * data, int len);

void Create_R(DulLinkList L, ElemType * data, int len);

_Bool ListEmpty(DulLinkList L);

_Bool DestroyList(DulLinkList L);

_Bool ClearList(DulLinkList L);

int ListLength(DulLinkList L);

_Bool GetElem(DulLinkList L, int i, ElemType * e);

typedef _Bool (* Compare)(Node *, ElemType*);

ELEM_INFO * LocateElem(DulLinkList L, ElemType e, Compare compare);

_Bool ListInsert(DulLinkList L, int i, ElemType e);

_Bool ListDelete(DulLinkList L, int i, ElemType * e);

#endif