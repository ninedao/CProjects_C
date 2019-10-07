//
// Created by POPO LIU on 2019-10-02.
//

#include "SqQueue.h"
int main(){
    SqQueue Q;
    QElemType e;
    InitQueue(&Q);
    EnQueue(&Q , 1);
    EnQueue(&Q , 2);
    EnQueue(&Q , 3);
    EnQueue(&Q , 4);
    EnQueue(&Q , 5);
    QueueTraverse(Q , vist);
    DeQueue(&Q , &e);
    QueueTraverse(Q , vist);
    DeQueue(&Q , &e);
    QueueTraverse(Q , vist);
    DeQueue(&Q , &e);
    QueueTraverse(Q , vist);
    EnQueue(&Q , 5);
    EnQueue(&Q , 5);
    EnQueue(&Q , 5);
    QueueTraverse(Q , vist);
    GetHeadQueue(Q , &e);
    printf("%d" , e);
}