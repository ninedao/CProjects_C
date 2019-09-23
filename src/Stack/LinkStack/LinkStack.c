//
// Created by POPO LIU on 2019-09-23.
//

#include "LinkStack.h"
int main(){
    StackTop s;
    ElemType e;
    InitStack(&s);
    Push(&s,1);
    Push(&s,2);
    Push(&s,3);
    Push(&s,4);
    Push(&s,5);
    Push(&s,6);
    Push(&s,7);
    StackTravarse(s, visit);
    Pop(&s,&e);
    StackTravarse(s, visit);
    printf("%d\n",e);
    concersion(&s);
}