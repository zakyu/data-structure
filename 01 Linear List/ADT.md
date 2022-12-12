# 线性表

线性表是具有相同特性的数据元素的一个有限序列。

## 线性表的抽象数据类型定义

ADT **List**  
{  
    **数据对象**：  
    D={ a<sub>i</sub> | 1≤i≤n, n≥0, a<sub>i</sub>为ElemType类型} // ElemType是自定义类型标识符  
    **数据关系**：  
    R={\<a<sub>i</sub>,a<sub>i+1</sub>>| a<sub>i</sub>,a<sub>i+1</sub>∈D, i = 1, 2, ..., n-1}  
    **基本操作**：  
    **InitList(&L)**：初始化线性表。构造一个空的线性表L。  
    **DestroyList(&L)**：销毁线性表。释放线性表L占用的内存空间。    
    **ListEmpty(L)**：判断线性表是否为空表。若L为空表，则返回真，否则返回假。  
    **ListLength(L)**：求线性表的长度。返回L中元素的个数。  
    **GetElem(L, i, &e)**：求线性表中某个数据元素值。用e返回L中第i（1≤i≤n）个元素的值。  
    **LocateElem(L, e, compare())**：按元素和规则查找。查找L中第一个值域跟e比较符合compare规则的元素，并返回其序号，若这样的元素不存在，则返回值为0。  
    **ListInsert(&L, i, e)**：插入数据元素。在L的第i个位置插入一个新的元素e，L的长度增1。  
    **ListDelete(&L, i, &E)**：删除数据元素。删除L的第i个元素，并用e返回其值，L的长度减1。  
    **ListTraverse(&L, operate())**：遍历线性表。遍历L的元素，并用operate处理元素。  
}  
