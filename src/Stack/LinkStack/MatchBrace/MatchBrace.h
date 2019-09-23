//
// Created by POPO LIU on 2019-09-23.
//

#ifndef CPROJECTS_C_MATCHBRACE_H
#define CPROJECTS_C_MATCHBRACE_H

#include "../../../common/common.h"
typedef char ElemType;
int visit(ElemType e){
    printf("%c ",e);
    return SUCCESS;
}
#include "../LinkStack.h"
int match(char x, char y){
    if(x == '[' && y == ']'){
        return TRUE;
    }else if(x == '(' && y == ')'){
        return TRUE;
    }else if(x == '{' && y == '}'){
        return TRUE;
    }else{
        return FALSE;
    }
}
int MatchBrace(StackTop *s){
    ClearStack(s);
    char p,e;
    int i;
    scanf("%d", &i);
    if(i%2 == 1 || i <= 0){
        printf("MatchBrace ERROE!\n");
        exit(ERROR);
    }
    for(int j = 0; j < i ; j++){
        scanf(" %c",&e);
        GetTop(*s,&p);
        if(match(p,e)){
            Pop(s , &e);
            StackTravarse(*s, visit);
        }else{
            Push(s , e);
            StackTravarse(*s, visit);
        }
    }
    if(!StackEmpty(*s)){
        printf("Match Fail!\n");
        return FAIL;
    }else{
        printf("Match SUCCESS!\n");
        return SUCCESS;
    }
}
#endif //CPROJECTS_C_MATCHBRACE_H
