#include <stdlib.h>
#include <stdbool.h>
#include "LinkString.h"

/* Generate string */
void StrAssign(LinkString s, char cstr[])
{
    s = (LinkString) malloc(sizeof(LinkString));
    LinkNode * rear = s;
    LinkNode * newNode;
    for (int i = 0; cstr[i]!='\0'; i++)
    {
        newNode = (LinkNode *)malloc(sizeof(LinkNode));
        newNode->data = cstr[i];
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = NULL;
}

/* Destroy string */
void DestroyStr(LinkString s)
{
    LinkNode * temp;
    while (s)
    {
        temp = s;
        s = s->next;
        free(temp);
    }
}

/* String copy */
void StrCopy(LinkString target, const LinkString source)
{
    target = malloc(sizeof(LinkString));
    LinkNode * rear = target;
    LinkNode * next = source->next;
    LinkNode * newNode;
    while(next)
    {
        newNode = (LinkNode *)malloc(sizeof(LinkNode));
        newNode->data = next->data;
        rear->next = newNode;
        rear = newNode;
        next = next->next;
    }
    rear->next = NULL;
}

/* Check if two strings are equal */
bool StrEqual(const LinkString s, const LinkString t)
{
    LinkNode * sNext = s->next, * tNext = s->next;
    while (sNext && tNext && sNext->data == tNext->data)
    {
        sNext = sNext->next;
        tNext = tNext->next;
    }
    
    return !sNext && !tNext;
}

/* Get string length */
int StrLength(const LinkString s)
{
    LinkNode * temp = s->next;
    int i;
    for (i = 0; temp; i++)
        temp = temp->next;
    return i;
}

/* String connection */
LinkString Concat(const LinkString s, const LinkString t)
{
    LinkString str = malloc(sizeof(LinkString));
    LinkNode * rear = str->next;
    LinkNode * next = s->next;
    LinkNode * newNode;
    while (next)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = next->data;
        rear->next = newNode;
        rear = newNode;
        next = next->next;
    }
    next = t->next;
    while (next)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = next->data;
        rear->next = newNode;
        rear = newNode;
        next = next->next;
    }
    rear->next = NULL;
    return str;
}

/* Find substring */
LinkString SubStr(const LinkString s, int i, int j)
{
    LinkString str = malloc(sizeof(LinkString));
    str->next = NULL;
    if (i <= 0 || i > StrLength(s) || j < 0 || i+j-1 > StrLength(s))
        return str;

    LinkNode * rear = str;
    LinkNode * next = s->next;
    LinkNode * newNode;
    for (int k = 1; k < i; k++)
        next = next->next;
    for (int k = 1; k < j; k++)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = next->data;
        rear->next = newNode;
        rear = newNode;
        next = next->next;
    }
    rear->next = NULL;
    return str;
}

/* Substring insertion */
LinkString InsStr(const LinkString s, int i, const LinkString t)
{
    LinkString str = malloc(sizeof(LinkString));
    str->next = NULL;
    if (i <= 0 || i-1 > StrLength(s))
        return str;

    LinkNode * rear = str;
    LinkNode * sNext = s->next;
    LinkNode * tNext = t->next;
    LinkNode * newNode;
    for (int k = 1; k < i; k++)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = sNext->data;
        rear->next = newNode;
        rear = newNode;
        sNext = sNext->next;
    }
    while (tNext)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = tNext->data;
        rear->next = newNode;
        rear = newNode;
        tNext = tNext->next;
    }
    while (sNext)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = sNext->data;
        rear->next = newNode;
        rear = newNode;
        sNext = sNext->next;
    }
    rear->next = NULL;
    return str;
}

/* Substring deletion */
LinkString DelStr(const LinkString s, int i, int j)
{
    LinkString str = malloc(sizeof(LinkString));
    str->next = NULL;
    if (i <= 0 || i > StrLength(s) || i+j-1 > StrLength(s))
        return str;

    LinkNode * rear = str;
    LinkNode * next = s->next;
    LinkNode * newNode;
    for (int k = 1; k < i; k++)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = next->data;
        rear->next = newNode;
        rear = newNode;
        next = next->next;
    }
    for (int k = 0; k < j; k++)
        next = next->next;
    while(next)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = next->data;
        rear->next = newNode;
        rear = newNode;
        next = next->next;
    }
    rear->next = NULL;
    return str;
}

/* Substring replacement */
LinkString RepStr(const LinkString s, int i, int j, const LinkString t)
{
    LinkString str = malloc(sizeof(LinkString));
    str->next = NULL;
    if (i <= 0 || i > StrLength(s) || i+j-1 > StrLength(s))
        return str;

    LinkNode * rear = str;
    LinkNode * sNext = s->next;
    LinkNode * tNext = t->next;
    LinkNode * newNode;
    for (int k = 0; k < i-1; k++)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = sNext->data;
        rear->next = newNode;
        rear = newNode;
        sNext = sNext->next;
    }
    for (int k = 0; k < j; k++)
        sNext = sNext->next;
    while (tNext)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = tNext->data;
        rear->next = newNode;
        rear = newNode;
        tNext = tNext->next;
    }
    while(sNext)
    {
        newNode = malloc(sizeof(LinkNode));
        newNode->data = sNext->data;
        rear->next = newNode;
        rear = newNode;
        sNext = sNext->next;
    }
    rear->next = NULL;
    return str;
}

/* Iterate over the elements of the string s and process the elements with function operate */
void TraverseStr(LinkString s, Operate operate)
{
    LinkNode * next = s->next;
    while (next)
    {
        operate(next->data);
        next = next->next;
    }
}