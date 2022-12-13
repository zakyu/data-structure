#ifndef LISTS_H_
#define LISTS_H_ 1

typedef int ElemType;

enum tag
{
    data,
    sublist
};
typedef enum tag Tag;

struct node
{
    Tag tag;
    union
    {
        ElemType data;
        struct node * sublist;
    } val;
    struct node * next;
};
typedef struct node GLNode;

GLNode * CreateGL(const char * s);
// DestroyGL(&g)
int GLLength(GLNode * g);
int GLDepth(GLNode * g);
typedef void (* Operate)(ElemType * e);
void GLTraverse(GLNode * g, Operate operate);
#endif