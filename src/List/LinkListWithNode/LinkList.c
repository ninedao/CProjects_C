//
// Created by POPO LIU on 2019-09-16.
//

#include "LinkList.h"
int main(){
    LinkList l,s,m;
    InitList(&l);
    InitList(&s);
    InitList(&m);
    MergeList_L(&l,&s,&m);
    ListTraverse(m,visit);
    ClearList(&m);
    Link p1,p2,p3,p4,p5,p6,p7,p8,p9;
    Link q;
    MakeNode(&p1,1);
    MakeNode(&p2,2);
    MakeNode(&p3,3);
    MakeNode(&p4,4);
    MakeNode(&p5,5);
    MakeNode(&p6,6);
    MakeNode(&p7,7);
    MakeNode(&p8,8);
    MakeNode(&p9,9);
    InsAfter(&l,&l.head,p1);
    InsAfter(&l,&p1,p2);
    InsAfter(&l,&p2,p3);
    InsAfter(&l,&p3,p4);
    InsAfter(&l,&p4,p5);
    InsAfter(&l,&p5,p6);
    InsFirst(p7,p8);
    InsFirst(p8,p9);
    ListTraverse(l,visit);
    Append(&l,p7);
    ListTraverse(l,visit);
    MergeList_L(&l,&s,&m);
    ListTraverse(m,visit);
    ClearList(&m);
    ListInsert(&s, 1,1);
    ListInsert(&s, 2,3);
    ListInsert(&s, 3,5);
    ListInsert(&s, 4,10);
    ListTraverse(l,visit);
    ListTraverse(s,visit);
    MergeList_L(&l,&s,&m);
    ListTraverse(m,visit);
    ClearList(&m);
}
