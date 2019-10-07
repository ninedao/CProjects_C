//
// Created by POPO LIU on 2019-10-02.
//
/**
 * empty: rear = front;
 * full: front = (rear +1 )% N
 * length: (rear - front  + N) % N
 * */
#include "../../common/common.h"
#ifndef CPROJECTS_C_SQQUEUE_H
#define CPROJECTS_C_SQQUEUE_H
#define MAXQSIZE 6
#if !defined(CPROJECTS_C_BANK_SIMULATTION_H)
    typedef int QElemType;
    status vist(QElemType e){
        printf("%d ",e);
    }
#endif
typedef struct{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
status InitQueue(SqQueue *Q){
    Q->base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q->base){
        printf("InitQueue ERROR!\n");
        exit(OVERFLOW);
    }
    Q->rear = Q->front = 0;
    printf("InitQueue SUCCESS!\n");
    return SUCCESS;
}
status DestoryQueue(SqQueue *Q){
    if(Q->base){
        free(Q->base);
    }
    Q->base = null;
    Q->front = Q->rear = 0;
    printf("DestoryQueue SUCCESS!\n");
    return SUCCESS;
}
status ClearQueue(SqQueue *Q){
    Q->rear = Q->front = 0;
    printf("ClearQueue SUCCESS!\n");
    return SUCCESS;
}
status QueueEmpty(SqQueue Q){
    if(Q.front == Q.rear){
        printf("LinkQueue is empty!\n");
        return TRUE;
    }else{
        printf("LinkQueue is not empty!\n");
        return FALSE;
    }
}
int QueueLength(SqQueue Q){
    int i = (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
    printf("LinkQueue's length %d!\n", i);
    return i;
}
status GetHeadQueue(SqQueue Q, QElemType *e){
    if(Q.front == Q.rear){
        printf("LinkQueue is empty!\n");
        return ERROR;
    }
    *e = *(Q.base+Q.front);
    return SUCCESS;
}
status EnQueue(SqQueue *Q, QElemType e){
    if((Q->rear + 1) % MAXQSIZE ==  Q->front){
        printf("LinkQueue is full!\n");
        return ERROR;
    }
    *(Q->base+Q->rear) = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    printf("EnQueue SUCCESS!\n");
    return SUCCESS;
}
status DeQueue(SqQueue *Q, QElemType *e){
    if(Q->rear == Q->front){
        printf("LinkQueue is empty!\n");
        return ERROR;
    }
    e = Q->base + Q->front;
    Q->front = (Q->front + 1) % MAXQSIZE;
    printf("DeQueue SUCCESS!\n");
    return SUCCESS;
}
status QueueTraverse(SqQueue Q,status (*vist)(QElemType)){
    if(Q.rear == Q.front){
        printf("LinkQueue is empty!\n");
        return ERROR;
    }
    int i = Q.front;
    while(i != Q.rear){
        vist(*(Q.base + i));
        i = (i + 1 ) % MAXQSIZE;
    }
    printf("\n");
    return SUCCESS;
}
#endif //CPROJECTS_C_SQQUEUE_H
