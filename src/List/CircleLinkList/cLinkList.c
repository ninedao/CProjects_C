//
// Created by POPO LIU on 2019-09-14.
//

#include "cLinkList.h"
int main(){
    List s,q;
    //cLinkList s;
    InitList(&s);
    InitList(&q);
    ListInsert(&s,1 ,1);
    ListInsert(&s,1 ,2);
    ListInsert(&s,1 ,3);
    ListInsert(&s,1 ,4);
    ListInsert(&s,4 ,5);
    ListInsert(&q,1 ,6);
    ListInsert(&q,1 ,7);
    ListInsert(&q,1 ,8);
    ListInsert(&q,1 ,9);
    ListInsert(&q,4 ,10);
    MergeList(&s,&q);
    GetElem(s,7);
}