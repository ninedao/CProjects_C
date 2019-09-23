//
// Created by POPO LIU on 2019-09-20.
//
//1 2 3 4 5 6 7 8 9 10
//-1 2 3 4 5 6 7 8 9 10
//2 -4 6 8 10 12 14 16 18 20
//1 3 5 7 9 11 13 15 17 19
/*
2.1 1 4.0 3 -3.12 5 5.3 7 2.5 9
3.4 2 -3.17 4 4.1 5 1.8 8 -2.5 9 0.5 12
*/
#include "PolynomialList.h"
int main(){
    polynomail p,q;
    InitList(&p);
    InitList(&q);
    int i = 5;
    CreatePolyn(&p,1);
    CreatePolyn(&q,5);
    ListTraverse(p,visit);
    ListTraverse(q,visit);
    //AddPolyn(&p , &q);
    //SubstractPolyn(&p , &q);
    MultiplyPolyn(&p , &q);
}
