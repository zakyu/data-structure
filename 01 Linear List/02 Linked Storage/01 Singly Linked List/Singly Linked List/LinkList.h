#ifndef LINKLIST_H_
#define LINKLIST_H_ 1

typedef int ElemType;

struct node
{
    ElemType data;
    struct node * next;
};
typedef struct node Node;
typedef struct node * LinkList;

struct elem_info
{
    int index;
    Node * pointer;
};
typedef struct elem_info ELEM_INFO;

_Bool * InitList(LinkList L);

void Create(LinkList L, ElemType * data, int len);

void Create_R(LinkList L, ElemType * data, int len);

_Bool ListEmpty(LinkList L);

_Bool DestroyList(LinkList L);

_Bool ClearList(LinkList L);

int ListLength(LinkList L);

_Bool GetElem(LinkList L, int i, ElemType * e);

typedef _Bool (* Compare)(Node *, ElemType*);

ELEM_INFO * LocateElem(LinkList L, ElemType e, Compare compare);

_Bool ListInsert(LinkList L, int i, ElemType e);

_Bool ListDelete(LinkList L, int i, ElemType * e);

#endif
