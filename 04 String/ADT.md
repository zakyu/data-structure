 # 串

由零个或多个字符组成的有限序列。

## 串的抽象数据类型定义

ADT string  
{  
    数据对象： 
    D = { a<sub>i</sub>| 1≤i≤n, n≥0, a<sub>i</sub>为char类型}  
    数据关系：  
    R = {<a<sub>i</sub>,a<sub>i+1</sub>> | ai、ai+1∈D, i = 1, ...,n-1 }  
    基本操作：  
    StrAssign(&s, cstr)：将字符串常量cstr赋给串s，即生成其值等于cstr的串s。
    DestroyStr(&s)：销毁串。释放为串s分配的存储空间。  
    StrCopy(&s, t)：串复制。将串t赋给串s。  
    StrEqual(s, t)：判断串是否相等。若两个串相等则返回真；否则返回假。  
    StrLength(s)：求串长。返回串s中字符的个数。  
    Concat(s, t)：串连接。返回由两个串s和t连接在一起形成的新串。  
    SubStr(s, i, j)：求子串。返回串s中从第i（1≤i≤n）个字符开始的由连续j个字符组成的子串。  
    InsStr(s1, i, s2)：子串插入，将串s2插入到串s1的第i（1≤i≤n）个位置，并返回产生的新串。  
    DelStr(s, i, j)：子串删除。从串s中删去从第i个字符开始的长度为j的子串，并返回产生的新串。  
    RepStr(s, i, j, t)：子串替换。在串s中将第i个字符开始的j个字符构成的子串用串t替换，并返回产生的新串。  
    TraverseStr(s, operate())：遍历串。遍历串s的所有字符，并用operate处理字符。

}  
