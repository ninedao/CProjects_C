//
// Created by POPO LIU on 2019-09-16.
//
#include "../../common/common.h"
#ifndef CPROJECTS_C_LINKLIST_H
#define CPROJECTS_C_LINKLIST_H
typedef struct LNode{
    int data;
    struct LNode *next;
}*Link, *Position;
typedef struct{
    Link head,tail;
    int len;
}LinkList;
int MakeNode(Link *p,int e){
    (*p) = (Link )malloc(sizeof(Link));
    (*p)->data = e;
    (*p)->next = null;
    if(*p){
        printf("MakeNode SUCCESS!\n");
        return SUCCESS;
    }else{
        printf("MakeNode ERROR!\n");
        return ERROR;
    }
}
int FreeNode(Link *p){
    free(p);
    *p = NULL;
    printf("FreeNode SUCCESS!\n");
    return SUCCESS;
}
int InitList(LinkList *l){
    Link p = (Link )malloc(sizeof(Link));
    if(!p){
        exit(OVERFLOW);
    }
    p->next = null;
    (*l).head = (*l).tail = p;
    (*l).len = 0;
    printf("InitList SUCCESS!\n");
    return SUCCESS;
}
int ClearList(LinkList *l){
    Link p , q;
    p = l->head->next;
    while(p){
        q = p->next;
        FreeNode(&p);
        p = q;
    }
    l->head->next=null;
    l->tail = l->head;
    l->len = 0;
    printf("ClearList SUCCESS!\n");
    return SUCCESS;
}
int DestoryList(LinkList *l){
    ClearList(l);
    FreeNode(&(l->head));
    l->head = l->tail = null;
    free(l);
    l = null;
    printf("DestoryList SUCCESS!\n");
    return SUCCESS;
}
int InsFirst(Link h, Link s){
    s->next = h->next;
    h->next = s;
    printf("InsFirst SUCCESS!\n");
    return SUCCESS;
}
int DelFirst(Link h, Link *q){
    *q = h->next;
    if(*q){
        h->next = (*q)->next;
    }
    printf("DelFirst SUCCESS!\n");
    return SUCCESS;
}
int Append(LinkList *l,Link s){
    int count = 0;
    (*l).tail->next = s;
    while(s){
        (*l).tail = s;
        s = s->next;
        count ++;
    }
    (*l).len += count;
    printf("Append SUCCESS!\n");
    return SUCCESS;
}
int Remove(LinkList *l, Link *q){
    if(l->len<=0){
        printf("Remove ERROR(len is too short)!\n");
        return ERROR;
    }
    (*q) = (*l).tail;
    Link p = l->head;
    while(p->next != l->tail){
        p = p->next;
    }
    p->next = NULL;
    l->head = p;
    l->len--;
    printf("Remove SUCCESS!\n");
    return SUCCESS;
}
Position PriorPos(LinkList l, Link p){
    Position q;
    Position r = l.head;
    while(r->next != p){
        r = r->next;
    }
    return r;
}
int InsBefore(LinkList *l, Link *p, Link s){
    Link q = PriorPos(*l,*p);
    if(!q){
        q =(*l).head;
    }
    s->next = *p;
    q->next = s;
    l->len++;
    printf("InsBefore SUCCESS!\n");
    return SUCCESS;
}
int InsAfter(LinkList *l, Link *p, Link s){
    if(l->tail == (*p)){
        l->tail = s;
    }
    s->next = (*p)->next;
    (*p)->next = s;
    l->len++;
    printf("InsAfter SUCCESS!\n");
    return SUCCESS;
}
int SetCurElem(Link *p, int e){
    (*p)->data = e;
    printf("SetCurElem SUCCESS!\n");
    return SUCCESS;
}
int getCurElem(Link p){
    printf("getCurElem SUCCESS(%d)!\n",p->data);
    return p->data;
}
int ListEmpty(LinkList l){
    if(l.len == 0){
        printf("List is empty!\n");
        return TRUE;
    }else{
        printf("List is not empty!\n");
        return FALSE;
    }
}
int ListLength(LinkList l){
    printf("List's length is %d!\n",l.len);
    return l.len;
}
Position GetHead(LinkList l){
    printf("GetHead SUCCESS!\n");
    return l.head;
}
Position GetLast(LinkList l){
    printf("GetLast SUCCESS!\n");
    return l.tail;
}
Position NextPos(LinkList l,Link p){
    if(l.tail == p){
        return null;
    }else{
        return p->next;
    }
}
int LocatePos(LinkList l, int i, Link *p){
    if(i < 0 || i > l.len){
        printf("LocatePos ERROR!\n");
        return ERROR;
    }
    (*p) = l.head;
    for(int j = 0 ; j < i ; j++){
        (*p) = (*p)->next;
    }
    printf("LocatePos SUCCESS!\n");
    return SUCCESS;
}
int compare(int i, int j){
    if(i == j){
        return TRUE;
    }else{
        return FALSE;
    }
}
Position LocateElem(LinkList l, int e,int (*compare)(int, int) ){
    Link p = l.head;
    while(p->next){
        p = p->next;
        if((*compare)(e,p->data)){
            return p;
        }
    }
    return null;
}
int visit(int e){
    printf("%d ",e);
    return SUCCESS;
}
int ListTraverse(LinkList l, int (*visit)(int)){
    Link p = l.head;
    while(p->next){
        p = p->next;
        (*visit)(p->data);
    }
    printf("\n");
}
int ListInsert(LinkList *l, int i,int e){
    if(i <= 0 || i > l->len + 1){
        printf("ListInsert ERROR!\n");
        exit(OVERFLOW);
    }
    Link p,q;
    if(!LocatePos((*l) , i-1, &p)){
        printf("ListInsert ERROR!\n");
        exit(OVERFLOW);
    }
    if(!MakeNode(&q,e)){
        printf("ListInsert ERROR!\n");
        exit(OVERFLOW);
    }
    InsFirst(p,q);
    l->len++;
    printf("ListInsert SUCCESS!\n");
    return SUCCESS;
}
int MergeList_L(LinkList *a, LinkList *b , LinkList *c){
    Link p = (*a).head->next, q = (*b).head->next, r = (*c).head;
    Link m;
    while(p != null && q != null){

        if(p->data > q->data){
            MakeNode( &m, q->data);
            InsFirst(r,m);
            q = q->next;
        }else{
            MakeNode( &m, p->data);
            InsFirst(r,m);
            p = p->next;
        }
        r = r->next;
        c->tail = r;
    }
    if(p != null){
        Append(c,p);
        c->tail = (*a).tail;
    }
    if(q != null){
        Append(c,q);
        c->tail = (*b).tail;
    }
    c->len = a->len +b->len;
    printf("MergeList_L SUCCESS\n");
    return SUCCESS;
}
#endif //CPROJECTS_C_LINKLIST_H
