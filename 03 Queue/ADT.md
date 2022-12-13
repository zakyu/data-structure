 # 队列

只能在表的一端进行插入运算，在表的另一端进行删除运算的线性表。（头删尾插）

## 队列的抽象数据类型定义

ADT Queue  
{  
    **数据对象**：  
    D={ a<sub>i</sub> | a<sub>i</sub>属于ElemSet, (i=1,2,...,n, n≥0)}  
    **数据关系**：  
    R={\<a<sub>i-1</sub>,a<sub>i</sub>>|a<sub>i-1</sub>,a<sub>i</sub>属于D,(i=1,2,...,n)}   
    **基本操作**：  
    **InitQueue(&Q)**:初始化队列，构造一个空队列Q。  
    **DestroyQueue(&Q)**：销毁队列。释放队列Q占用的存储空间。  
    **QueueEmpty(Q)**：判断队列是否为空。若队列Q为空，则返回真；否则返回假。  
    **enQueue(&Q, e)**：进队列。将元素e进队作为队尾元素。    
    **deQueue(&Q, &E)**：出队列。从队列Q中出队一个元素，并将其值赋给e。  
}  
