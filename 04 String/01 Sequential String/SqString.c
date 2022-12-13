#include <stdlib.h>
#include <stdbool.h>
#include "SqString.h"

/* Generate string */
void StrAssign(SqString * s, char cstr[])
{
    int i;
    for (i = 0; cstr[i]!='\0'; i++)
        s->data[i] = cstr[i];
    
    s->length = i;
}

/* Destroy string */
void DestroyStr(SqString * s)
{
    free(s);
}

/* String copy */
void StrCopy(SqString * s, const SqString * t)
{
    for (int i = 0; i < t->length; i++)
        s->data[i] = t->data[i];
    s->length = t->length;
}

/* Check if two strings are equal */
bool StrEqual(const SqString * s, const SqString * t)
{
    if (s->length != t->length) return false;
    
    for (int i = 0; i < s->length; i++)
        if (s->data[i] != t->data[i]) return false;
    
    return true;
}

/* Get string length */
int StrLength(const SqString * s)
{
    return s->length;
}

/* String connection */
SqString Concat(const SqString * s, const SqString * t)
{
    SqString str;
    str.length = s->length + t->length;
    int i;
    for (i = 0; i < s->length; i++)
        str.data[i] = s->data[i];
    for (i = 0; i < t->length; i++)
        str.data[i+s->length] = t->data[i];
    return str;
}

/* Find substring */
SqString SubStr(const SqString * s, int i, int j)
{
    SqString str;
    str.length = 0;

    if (i <= 0 || i > s->length || j < 0 || i+j-1 > s->length)
        return str;

    for (int k = i-1; k < i+j-1; k++)
        str.data[k-i+1] = s->data[k];
    str.length = j;
    
    return str;
}

/* Substring insertion */
SqString InsStr(const SqString * s, int i, const SqString * t)
{
    SqString str;
    str.length = 0;

    if (i <= 0 || i-1 > s->length)
        return str;

    for (int j = 0; j < i-1; j++)
        str.data[j] = s->data[j];
    for (int j = 0; j < t->length; j++)
        str.data[j+i-1] = t->data[j];
    str.length = s->length + t->length;
    return str;
}

/* Substring deletion */
SqString DelStr(const SqString * s, int i, int j)
{
    SqString str;
    str.length = 0;
    
    if (i <= 0 || i > s->length || i+j-1 > s->length)
        return str;
    
    for (int k = 0; k < i-1; k++)
        str.data[k] = s->data[k];
    for (int k = i+j-1; k < s->length; k++)
        str.data[k-j] = s->data[k];
    
    str.length = s->length-j;
    return str;
}

/* Substring replacement */
SqString RepStr(const SqString * s, int i, int j, const SqString * t)
{
    SqString str;
    str.length = 0;
    
    if (i <= 0 || i > s->length || i+j-1 > s->length)
        return str;

    for (int k = 0; k < i-1; k++)
        str.data[k] = s->data[k];
    for (int k = 0; k < t->length; k++)
        str.data[i+k-1] = t->data[k];
    for (int k = i+j-1; k < s->length; k++)
        str.data[k+t->length-j] = s->data[k];
    
    str.length = s->length - j + t->length;
    return str;
}

/* Iterate over the elements of the string s and process the elements with function operate */
void TraverseStr(SqString * s, Operate operate)
{
    if (s->length < 1) return;
    for (int i = 0; i < s->length; i++)
        operate(s->data[i]);
}
