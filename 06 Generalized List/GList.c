#include <stdlib.h>
#include "GList.h"

GLNode * CreateGL(const char * s)
{
    GLNode * g;
    char ch = *s++;
    if (ch == '\0')
        g = NULL;
    else
    {
        g = malloc(sizeof(GLNode));
        if (ch == '(')
        {
            g->tag = sublist;
            g->val.sublist = CreateGL(s);
        }
        else if (ch == ')')
            g = NULL;
        else if (ch == '#')
            g = NULL;
        else
        {
            g->tag = 0;
            g->val.data = ch;
        }
    }

    ch = *s++;
    if(g)
        if (ch == ' ')
            g->next = CreateGL(s);
        else
            g->next = NULL;
    return g;
}

int GLLength(GLNode * g)
{
    GLNode * temp = g->val.sublist;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int GLDepth(GLNode * g)
{
    if (g->tag == data)
        return 0;

    int maxDepth = 0, depth;
    GLNode * sublist = g->val.sublist;
    if (!sublist)
        return 1;

    while (sublist)
    {
        if (sublist->tag == sublist)
        {
            depth = GLDepth(sublist);
            if (depth > maxDepth)
                maxDepth = depth;
        }
        sublist->next;
    }
    return maxDepth+1;
}


void GLTraverse(GLNode * g, Operate operate)
{
    if (!g)
        return;

    if (g->tag == data)
    {
        operate(g->val.data);
        return;
    }
    
    if (g->val.sublist)
        GLTraverse(g->val.sublist, operate);
    
    if (g->next)
        GLTraverse(g->next, operate);
}
