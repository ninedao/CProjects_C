//
// Created by POPO LIU on 2019-09-20.
//
#include "../../common/common.h"
#ifndef CPROJECTS_C_POLYNOMIALLIST_H
#define CPROJECTS_C_POLYNOMIALLIST_H
typedef struct{
    float coef;
    int expn;
}term, ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}*Link, *Position;
typedef struct{
    Link head,tail;
    int len;
}LinkList;
typedef LinkList polynomail;
int MakeNode(Link *p,ElemType e){
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
int SetCurElem(Link *p, ElemType e){
    (*p)->data = e;
    printf("SetCurElem SUCCESS!\n");
    return SUCCESS;
}
ElemType getCurElem(Link p){
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
int compare(ElemType i, ElemType j){
    int k = i.expn - j.expn;
    if(k > 0){
        return 1;
    }else if(k == 0){
        return 0;
    }else{
        return -1;
    }
}
int LocateElem(LinkList l, ElemType e,Position  *p, int (*compare)(ElemType, ElemType) ){
    Link q,r,s = l.head;
    while(s->next){
        int i = (*compare)(s->next->data,e);
        if(i == 1){
            if(!q){
                q = s;
            }
        }else if(i == 0){
            *p = s->next;
            break;
        }
    }
    if(!p){
        *p = q;
        return FALSE;
    }else{
        return TRUE;
    }
}
int visit(ElemType e,int i){
    if(e.coef > 0){
        if(i != 0) {
            printf("+ ");
        }
        printf("%.2fx^%d ",e.coef,e.expn);
    }else{
        printf("- ");
        printf("%.2fx^%d ",-e.coef,e.expn);
    }
    //printf("%.2fx^%d ",e.coef,e.expn);
    return SUCCESS;
}
int ListTraverse(LinkList l, int (*visit)(ElemType,int)){
    Link p = l.head;
    printf("f(x) = ");
    for(int i = 0; i < l.len ; i++){
        p = p->next;
        (*visit)(p->data,i);
    }
    printf("\n");
}
int ListInsert(LinkList *l, int i,ElemType e){
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
void CreatePolyn(polynomail *p, int m){

    Link r = p->head;
    Link q;
    ElemType e;
    for(int i = 0; i < m ; i++){
        q = (Link )malloc(sizeof(Link));
        if(!q){
            printf("CreatePolyn ERROR2!\n");
            exit(OVERFLOW);
        }
        //e = (ElemType )malloc(sizeof(ElemType));

        scanf("%f %d",&(e.coef),&(e.expn));
        q->data = e;
        q->next =null;
        r->next = q;
        r = r->next;
        p->tail = q;
    }
    p->len = m;
    printf("CreatePolyn SUCCESS!\n");
}
void DestoryPolyn(polynomail *p){
    DestoryList(p);
}
int PolynLength(polynomail p){
    printf("polynomail's length is %d",p.len);
}
void AddPolyn(polynomail *La , polynomail *Lb){
    Link ha = La->head , hb = Lb->head;
    Link a = La->head->next , b = Lb->head->next;
    float sum;
    while(a && b){
        switch (compare(a->data,b->data)){
            case 1 :
                DelFirst(hb , &b);
                InsFirst(ha , b);
                b = NextPos(*Lb , hb);
                a = NextPos(*La , ha);
                La->len ++;
                break;
            case 0 :
                sum = a->data.coef + b->data.coef;
                if(0.0 != sum){
                    a->data.coef = sum;
                    ha = a;
                }else{
                    DelFirst(ha , &a);
                    FreeNode(&a);
                    La->len -=1;
                }
                DelFirst(hb , &b);
                FreeNode(&b);
                a = NextPos(*La , ha);
                b = NextPos(*Lb , hb);
                break;
            case -1 :
                ha = a;
                a = NextPos(*La,a);
                break;
        }
    }
    if(b){
        Append(La,b);
    }
    DestoryList(Lb);
    printf("AddPolyn SUCCESS!\n");
    ListTraverse(*La,visit);
}
void SubstractPolyn(polynomail *La , polynomail *Lb){
    Link p = Lb->head->next;
    while(p){
        p->data.coef = -p->data.coef;
        p = p->next;
    }
    AddPolyn(La,Lb);
}
void MultiplyPolyn(polynomail *la , polynomail *lb){
    polynomail c , tem;
    InitList(&c);
    Link ha,a,b,s;
    int lena = la->len , lenb = lb->len;
    ha = la->head;
    ElemType e;
    for(int i = 1 ; i <= lena ; i++){
        InitList(&tem);
        a = ha->next;
        DelFirst(ha,&a);
        la->len --;
        b = lb->head->next;
        for(int j = 1 ; j <= lenb ; j++){
            e.expn = a->data.expn + b->data.expn;
            e.coef = a->data.coef * b->data.coef;
            MakeNode(&s,e);
            Append(&tem , s);
            b = b->next;
        }
        AddPolyn(&c,&tem);
    }
    if(la->len == 0){
        la->tail = la->head;
    }
    AddPolyn(la,&c);
    DestoryList(lb);
}
#endif //CPROJECTS_C_POLYNOMIALLIST_H
