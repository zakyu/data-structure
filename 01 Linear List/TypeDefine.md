# 线性表的类型定义

ADT List {  
    **数据对象**：D={ a<sub>i</sub> | a<sub>i</sub>属于ElemSet, (i=1,2,...,n, n≥0)}  
    **数据关系**：R={\<a<sub>i-1</sub>,a<sub>i</sub>>|a<sub>i-1</sub>,a<sub>i</sub>属于D,(i=1,2,...,n)}  
    **基本操作**：  
    **InitList(&L);**  
    操作结果：构造一个空的线性表L。  
    **DestroyList(&L);**  
    初始条件：线性表L存在。  
    操作结果：销毁线性表L。  
    **ClearList(&L);**  
    初始条件：线性表L存在。  
    操作结果：将线性表L重置为空表。  
    **ListEmpty(L);**  
    初始条件：线性表L存在。    
    操作结果：若线性表L为空表，则返回True；否则返回False;  
    **ListLength(L);**  
    初始条件：线性表L存在。
    操作结果：返回线性表L中数据元素的个数。  
    **GetElem(L, i, &e);**  
    初始条件：线性表L存在，1≤i≤ListLength(L)。  
    操作结果：用e返回线性表中L中第i个数据元素的值。    
    **LocateElem(L, e, compare());**  
    初始条件：线性表L存在，compare()是数据元素判定函数。  
    操作结果：返回L中第1个与e满足compare()的数据元素的位序。若不存在则返回0。  
    **PriorElem(L, cur_e, &pre_e);**  
    初始条件：线性表L存在。  
    操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败；pre_e无意义。  
    **NextElem(L, cur_e, &next_e);**  
    初始条件：线性表L存在。  
    操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败；next_e无意义。  
    **ListInsert(&L, i, e);**  
    初始条件：线性表L存在，1≤i≤ListLength(L)+1。  
    操作结果：在L的第i个位置之前插入新的数据元素e，L的长度加1。   
    **ListDelete(&L, i);**  
    初始条件：线性表L存在，1≤i≤ListLength(L)。  
    操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1。  
    **ListTraverse(&L, visited());**  
    初始条件：线性表L存在。  
    操作结果：依次对线性表中每个元素调用visited()。  
} ADT List;  
