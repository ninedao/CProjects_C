//
// Created by POPO LIU on 2019-10-08.
//

#include "LString.h"
int main(){
    char *c="liuzhichen";
    char *b="chen";
    LString l, p, q, r;
    InitLString(&l);
    StrAssign_L(&l,c);
    InitLString(&p);
    StrAssign_L(&p,b);
    //StrCopy_L(&p,l);
    StrPrint(l);

    printf("%d\n", StrCompare_L(l, p));
    SubString_L(&r, l , 1, 6);
    StrPrint(r);
    StrPrint(p);
    StrConcat(&q, r , p);
    StrPrint(q);
}