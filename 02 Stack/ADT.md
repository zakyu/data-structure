# 栈 —— 特殊的线性表

一种只能在一端进行插入或删除操作的线性表。

## 栈的抽象数据类型定义

ADT Stack  
{  
    **数据对象**：  
    D={ a<sub>i</sub> | 1≤i≤n, n≥0, a<sub>i</sub>为ElemType类型} // ElemType是自定义类型标识符  
    **数据关系**：  
    R={\<a<sub>i</sub>,a<sub>i+1</sub>>| a<sub>i</sub>,a<sub>i+1</sub>∈D, i = 1, 2, ..., n-1}  
    约定a<sub>n</sub>端为栈顶，a<sub>1</sub>端为栈底。  
    **基本操作**：  
    **InitStack(&S)**：初始化栈。构造一个空栈S。  
    **DestroyStack(&S)**：销毁栈。释放栈S占用的存储空间。  
    **StackEmpty(S)**：判断栈是否为空。若栈S为空栈，则返回真；否则返回假;  
    **Push(&S, e)**：进栈。将元素e插入到栈S中作为栈顶元素。  
    **Pop(&S, &E)**：出栈。从栈S中删除栈顶元素，并将其值赋给e。  
    **GetTop(S, &e)**：取栈顶元素。返回当前的栈顶元素，并将其值赋给e。    
}
