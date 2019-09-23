//
// Created by POPO LIU on 2019-09-14.
//
#include "../../common/common.h"
#ifndef CPROJECTS_C_CLINKLIST_H
#define CPROJECTS_C_CLINKLIST_H
typedef struct LNode{
    int data;
    struct LNode *next;
}LNODE,cLinkList;
typedef struct{
    cLinkList *head;
    cLinkList *tail;
    int length;
}List;
int InitList(List *s){
    s->head = (cLinkList *)malloc(sizeof(cLinkList));
    s->tail = (cLinkList *)malloc(sizeof(cLinkList));
    s->length = 0;
    if(!s){
        printf("InitList ERROR!败\n");
        return ERROR;
    }else{
        s->head->next = s->tail;
        s->tail->next = s->head;
        printf("InitList SUCCESS!\n");
        return OK;
    }
}
int Destory(List *s){
    free(s->head);
    free(s->tail);
    s = NULL;
    printf("Destory SUCCESS!\n");
    return OK;
}
int ClearList(List *s){
    s->head->next = s->tail;
    s->tail->next = s->head;
    s->length = 0;
    printf("ClearList SUCCESS!\n");
    return OK;
}
int ListEmpty(List s){
    if(s.head->next!=s.tail){
        printf("cLinkList s is not empty!\n");
        return FALSE;
    }else{
        printf("cLinkList s is empty!\n");
        return TRUE;
    }
}
int ListLength(List s){
    printf("cLinkList s's length is %d\n",s.length);
    return OK;
}
int GetElem(List s,int i){
    if(i<1 || i > s.length){
        printf("GetElem's i is ERROR\n");
        return ERROR;
    }
    cLinkList *p = s.head->next;
    int j = 1;
    while(p != s.tail && j < i){
        p = p->next;
        j++;
    }
    if(j == i && p != s.tail){
        printf("cLinkList s is %d in the %d place",p->data,i);
        return OK;
    }else{
        printf("cLinkList s can't get data in the %d place\n",i);
        return ERROR;
    }
}
int visit(int e){
    printf("%d ",e);
    return SUCCESS;
}
void ListTraverse(List s,int (*visit)(int)){
    cLinkList *p = s.head;
    while(p->next != s.tail){
        p = p->next;
        visit(p->data);
    }
    printf("\n");
}
int ListInsert(List *s, int i, int e){
    if(i<=0 || i > s->length + 1){
        printf("ListInsert's i is ERROR\n");
        return ERROR;
    }
    cLinkList *p = s->head;
    int j = 1;
    while(p != s->tail && j < i ){
        (p) = (p)->next;
        j++;
    }
    if(p != s->tail && j == i){
        cLinkList *q = (cLinkList *)malloc(sizeof(cLinkList));
        (q)->data = e;
        (q)->next = (p)->next;
        (p)->next = (q);
        s->length++;
        printf("insert success\n");
        ListTraverse(*s,*visit);
        return SUCCESS;
    }else{
        printf("insert ERROR\n");
        return ERROR;
    }
}
int MergeList(List *s,List *p){
    cLinkList *q = s->head;
    cLinkList *r = p->head;
    while(q->next != s->tail){
        q = q->next;
    }
    q->next = r->next;
    r->next = s->head;
    s->length += p->length;
    s->tail = p->tail;
    ListTraverse(*s,*visit);
}

#endif //CPROJECTS_C_CLINKLIST_H
