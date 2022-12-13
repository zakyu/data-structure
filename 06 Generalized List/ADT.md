ADT GList  
{  
    数据对象：  
    D = {e<sub>i</sub> | 1≤i≤n,n≥0, e<sub>i</sub>∈AtomSet或e<sub>i</sub>∈GList,AtomSet为某个数据对象}  
    数据关系：  
    R = {<e<sub>i-1</sub>, e<sub>i</sub>> | <e<sub>i-1</sub>, e<sub>i</sub>∈D,2≤i≤n}  
    基本运算：  
    CreateGL(s)：创建广义表g，由括号表示法s创建并返回一个广义表。  
    DestroyGL(&g)：销毁广义表g，释放广义表g的存储空间。  
    GLLength(g)：求广义表g的长度。  
    GLDepth(g):求广义表g的深度。  
    GLTraverse(g)：遍历广义表g。  
}