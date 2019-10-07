//
// Created by POPO LIU on 2019-10-02.
//

#include "LinkQueue.h"
int main(){
    LinkQueue Q[5];
    QElemType e;
    for(int i = 1; i < 5; i++){
        InitQueue(Q+i);
    }
    EnQueue(&Q[1] , 1);
    EnQueue(&Q[1] , 2);
    EnQueue(&Q[1] , 3);
    EnQueue(&Q[1] , 4);
    EnQueue(&Q[1] , 5);
    QueueTraverse(Q[1] , vist);
    DeQueue(&Q[1] , &e);
    QueueTraverse(Q[1] , vist);
    EnQueue(&Q[1] , 1);
    QueueTraverse(Q[1] , vist);
}