//
// Created by POPO LIU on 2019-09-15.
//
#include "../../common/common.h"
#ifndef CPROJECTS_C_DULLINKLIST_H
#define CPROJECTS_C_DULLINKLIST_H
typedef struct DulNode{
    int data;
    struct DulNode *prior;
    struct DulNode *next;
}DuLNode, *DulLinkList;
int InitList(DulLinkList *d){
    *d = (DulLinkList )malloc(sizeof(DulLinkList));
    if(!d){
        printf("InitList ERROR!\n");
        return ERROR;
    }else{
        (*d)->next = null;
        (*d)->prior = null;
        printf("InitList SUCCESS!\n");
        return OK;
    }
}
DulLinkList MakeNode(){
    DulLinkList r = (DulLinkList )malloc(sizeof(DulLinkList));
    r->next = null;
    r->prior = null;
    return r;
}
int Destory(DulLinkList *d){
    free(*d);
    printf("Destory SUCCESS!\n");
    return OK;
}
int ClearList(DulLinkList *d){
    (*d)->prior = null;
    (*d)->next = null;
    printf("ClearList SUCCESS!\n");
    return OK;
}
int ListEmpty(DulLinkList s){
    if(s->prior == null && s->next == null){
        printf("cLinkList s is empty!\n");
        return TRUE;
    }else{
        printf("cLinkList s is not empty!\n");
        return FALSE;
    }
}
int ListLength(DulLinkList s){
    int i = 0;
    DulLinkList p = s;
    DulLinkList q = s;
    while(p->next != null){
        i++;
        p = p->next;
    }
    while(q->prior != null){
        i++;
        q = q->prior;
    }
    printf("cLinkList s's length is %d\n",i);
    return i;
}
int GetElem(DulLinkList s,int i){
    int j = 0;
    DulLinkList p = s->next;
    while(p != null && j < i){
        j++;
        p = p->next;
    }
    if(i == j && p !=null){
        printf("DulLinkList s is %d in the %d place",p->data,i);
    }else{
        printf("DulLinkList s can't get data in the %d place\n",i);
        return ERROR;
    }
}
int visit(int e){
    printf("%d ",e);
    return SUCCESS;
}
void ListTraverse(DulLinkList s,int (*visit)(int)){
    DulLinkList p = s;
    while(p->next != null){
        p=p->next;
        visit(p->data);
    }
    printf("\n");
}
int ListInsert(DulLinkList *s, int i, int e){
    if(i<=0 || i > ListLength(*s) + 1){
        printf("ListInsert's i is ERROR\n");
        return ERROR;
    }
    DulLinkList r = MakeNode();
    if(!r){
        printf("ListInsert's init r is ERROR\n");
        return ERROR;
    }
    DulLinkList p = (*s);
    int j = 1;
    while(p->next != null && j < i ){
        (p) = (p)->next;
        j++;
    }

    if(j == i){

        r->data = e;
        r->prior = p;
        if(null != p->next) {
            p->next->prior = r;
        }
        r->next = p->next;
        p->next = r;
        printf("insert success\n");
        ListTraverse(*s,*visit);
        return SUCCESS;
    }else{
        printf("insert ERROR\n");
        return ERROR;
    }
}
#endif //CPROJECTS_C_DULLINKLIST_H
