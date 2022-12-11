# 栈 —— 特殊的线性表




## 栈的抽象数据类型定义

ADT Stack {  
    **数据对象**：  
    D={ a<sub>i</sub> | a<sub>i</sub>属于ElemSet, (i=1,2,...,n, n≥0)}  
    **数据关系**：  
    R={\<a<sub>i-1</sub>,a<sub>i</sub>>|a<sub>i-1</sub>,a<sub>i</sub>属于D,(i=1,2,...,n)}  
    约定a<sub>n</sub>端为栈顶，a<sub>1</sub>端为栈底。  
    **基本操作**：  
    **InitStack(&S);**  
    操作结果：构造一个空栈S。  
    **DestroyStack(&S);**  
    初始条件：栈S已存在。  
    操作结果：销毁栈S。  
    **StackEmpty(S);**  
    初始条件：栈S已存在。  
    操作结果：若栈S为空栈，则返回True；否则返回False;  
    **StackLength(S);**  
    初始条件：栈S已存在。
    操作结果：返回栈S中数据元素的个数，即栈的长度。  
    **GetTop(S, &e);**  
    初始条件：栈S已存在且非空。  
    操作结果：用e返回栈S的栈顶元素的值。  
    **ClearStack(&S);**  
    初始条件：栈S已存在。  
    操作结果：将栈S重置为空栈。  
    **Push(&S, e);**  
    初始条件：栈S已存在。  
    操作结果：插入元素e为新的栈顶元素，S的长度加1。  
    **Pop(&S, &E);**  
    初始条件：栈S已存在且非空。  
    操作结果：删除S的栈顶元素，并用e返回其值，S的长度减1。  
} ADT Stack;  
