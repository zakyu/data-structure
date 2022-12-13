#ifndef LINKSTRING_H_
#define LINKSTRING_H_ 1

#define MAXSIZE 100

struct node
{
    char data;
    struct node * next;
};
typedef struct node LinkNode;
typedef struct node * LinkString;


/* Generate string */
void StrAssign(LinkString s, char cstr[]);

/* Destroy string */
void DestroyStr(LinkString s);

/* String copy */
void StrCopy(LinkString s, const LinkString t);

/* Check if two strings are equal */
bool StrEqual(const LinkString s, const LinkString t);

/* Get string length */
int StrLength(const LinkString s);

/* String connection */
LinkString Concat(const LinkString s, const LinkString t);

/* Find substring */
LinkString SubStr(const LinkString s, int i, int j);

/* Substring insertion */
LinkString InsStr(const LinkString s, int i, const LinkString t);

/* Substring deletion */
LinkString DelStr(const LinkString s, int i, int j);

/* Substring replacement */
LinkString RepStr(const LinkString s, int i, int j, const LinkString t);

/* Process element e */
typedef void (*Operate)(char * e);

/* Iterate over the elements of the string s and process the elements with function operate */
void TraverseStr(LinkString s, Operate operate);

#endif