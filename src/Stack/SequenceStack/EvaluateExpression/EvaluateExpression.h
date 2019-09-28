//
// Created by POPO LIU on 2019-09-25.
//

#ifndef CPROJECTS_C_EVALUATEEXPRESSION_H
#define CPROJECTS_C_EVALUATEEXPRESSION_H
typedef char ElemType ;
typedef char Elemtype ;
#include "../SequenceStack.h"
status In(Elemtype c ){
    Elemtype a[] = {'+' , '-' , '*' , '/' , '(' , ')' , '#'};
    int j = sizeof(a) / sizeof(ElemType);
    for(int i = 0 ; i < j ; i++){
        if(c == a[i]){
            return TRUE;
        }
    }
    return FALSE;
}
Elemtype Precede(Elemtype o , Elemtype c){
    switch(c){
        case '+':
        case '-':
            if(  o == '(' || o == '#' ){
                return '<';
            }else{
                return '>';
            }
        case '*':
        case '/':
            if(o == '*' || o == '/' || o == ')'){
                return '>';
            }else{
                return '<';
            }
        case '(':
            if(o == ')'){
                printf("It's ERROR");
                exit(ERROR);
            }else{
                return '<';
            }
        case ')':
            if(o == '('){
                return '=';
            }else if(o == '#'){
                printf("It's ERROR");
                exit(ERROR);
            }else{
                return '>';
            }
        case '#':
            if(o == '#'){
                return '=';
            }else if(o == '('){
                printf("It's ERROR");
                exit(ERROR);
            }else{
                return '>';
            }
    }
}
Elemtype Operate(Elemtype a , Elemtype theta , Elemtype b){
    int m = a - 48;
    int n = b - 48;
    int z;
    switch(theta){
        case '+':
            z = m + n;
            break;
        case '-':
            z = m - n;
            break;
        case '*':
            z = m * n;
            break;
        case '/':
            z = m / n;
            break;
    }
    char r = z + 48;
    return r;
}
Elemtype GetTop_Sq(SqStack s){
    Elemtype e;
    GetTop( s , &e);
    return e;
};
/*
 *
 * The result needs to be less than 10
 *
 */
Elemtype EvaluateExpression(SqStack *OPTR, SqStack *OPND){

    InitStack(OPTR);
    push(OPTR , '#');
    InitStack(OPND);
    Elemtype c ;
    scanf(" %c",&c);
    Elemtype a , b , theta , e;
    while(c != '#' || GetTop_Sq(*OPTR) != '#'){
        if(!In(c)){
            push(OPND , c);
            scanf(" %c",&c);
        }else{
            switch (Precede(GetTop_Sq(*OPTR) , c)){
                case '>':
                    pop(OPTR , &theta);
                    pop(OPND , &b);
                    pop(OPND , &a);
                    push(OPND , Operate(a , theta , b));
                    break;
                case '=':
                    pop(OPTR, &e);
                    scanf(" %c",&c);
                    break;
                case '<':
                    push(OPTR , c);
                    scanf(" %c",&c);
                    break;
            }
        }
    }
    printf("= %c\n",GetTop_Sq(*OPND));
}
#endif //CPROJECTS_C_EVALUATEEXPRESSION_H
