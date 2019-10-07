//
// Created by POPO LIU on 2019-10-02.
//

#ifndef CPROJECTS_C_LINKQUEUE_H
#define CPROJECTS_C_LINKQUEUE_H

#include "../../common/common.h"
#if !defined(CPROJECTS_C_BANK_SIMULATTION_H)
    typedef int QElemType;
    status vist(QElemType e){
        printf("%d ",e);
    }
#endif
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
status InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front){
        printf("InitQueue ERROR!\n");
        //exit(OVERFLOW);
    }

    Q->front->next = null;
    printf("InitQueue SUCCESS!\n");
    return SUCCESS;
}
status DestoryQueue(LinkQueue *Q){

    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    printf("DestoryQueue SUCCESS!\n");
    return SUCCESS;
}
status ClearQueue(LinkQueue *Q){
    Q->rear = Q->front->next ;
    while(Q->rear){
        Q->front->next = Q->rear->next;
        free(Q->rear);
        Q->rear = Q->front->next ;
    }
    Q->rear = Q->front;
    printf("ClearQueue SUCCESS!\n");
    return SUCCESS;
}
status QueueEmpty(LinkQueue Q){
    if(Q.rear == Q.front){
        //printf("LinkQueue is empty!\n");
        return TRUE;
    }else{
        //printf("LinkQueue is not empty!\n");
        return FALSE;
    }
}
int QueueLength(LinkQueue Q){
    int count = 0;
    QueuePtr p = Q.front;
    while(p != Q.rear){
        count++;
        p = p->next;
    }
    //printf("LinkQueue's length %d!\n",count);
    return count;
}
status getHeadQueue(LinkQueue Q, QElemType *e){
    if(!QueueEmpty(Q)){
        QueuePtr p;
        p = Q.front->next;
        *e = p->data;
    }
    return FAIL;
}
status EnQueue(LinkQueue *Q, QElemType e){
    if(!Q){
        printf("EnQueue ERROR!\n");
        exit(OVERFLOW);
    }
    QueuePtr m = (QueuePtr)malloc(sizeof(QNode));
    if(!m){
        printf("EnQueue ERROR!\n");
        exit(OVERFLOW);
    }
    m->data = e;
    m->next = null;
    Q->rear->next = m;
    Q->rear = m;
    printf("EnQueue SUCCESS!\n");
    return SUCCESS;
}
status DeQueue(LinkQueue *Q, QElemType *e){
    if(Q->rear == Q->front){
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    (*e) = p->data;
    Q->front->next = p->next;
    if(Q->rear == p){
        Q->rear = Q->front;
    }
    free(p);
    return SUCCESS;
}
status QueueTraverse(LinkQueue Q,status (*vist)(QElemType)){
    QueuePtr p = Q.front->next;
    while(p){
        vist(p->data);
        p = p->next;
    }
    printf("\n");
}
#endif //CPROJECTS_C_LINKQUEUE_H
