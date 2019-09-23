//
// Created by POPO LIU on 2019-09-22.
//

#include "SequenceStack.h"
int main(){
    SqStack s;
    ElemType e;
    InitStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    push(&s,6);
    push(&s,7);
    StackTraverse(s,visit);
    pop(&s,&e);
    StackTraverse(s,visit);
    DestoryStack(&s);
    //printf("%d",s.top - s.base);
}