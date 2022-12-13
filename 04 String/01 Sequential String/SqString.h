#ifndef SQSTRING_H_
#define SQSTRING_H_ 1

#define MAXSIZE 100

typedef struct
{
    char data[MAXSIZE];
    int length;
}SqString;

/* Generate string */
void StrAssign(SqString * s, char cstr[]);

/* Destroy string */
void DestroyStr(SqString * s);

/* String copy */
void StrCopy(SqString * s, const SqString * t);

/* Check if two strings are equal */
bool StrEqual(const SqString * s, const SqString * t);

/* Get string length */
int StrLength(const SqString * s);

/* String connection */
SqString Concat(const SqString * s, const SqString * t);

/* Find substring */
SqString SubStr(const SqString * s, int i, int j);

/* Substring insertion */
SqString InsStr(const SqString * s, int i, const SqString * t);

/* Substring deletion */
SqString DelStr(const SqString * s, int i, int j);

/* Substring replacement */
SqString RepStr(const SqString * s, int i, int j, const SqString * t);

/* Process element e */
typedef void (*Operate)(char * e);

/* Iterate over the elements of the string s and process the elements with function operate */
void TraverseStr(SqString * s, Operate operate);

#endif