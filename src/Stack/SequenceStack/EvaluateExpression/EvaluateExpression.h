//
// Created by POPO LIU on 2019-09-25.
//

#ifndef CPROJECTS_C_EVALUATEEXPRESSION_H
#define CPROJECTS_C_EVALUATEEXPRESSION_H
typedef char ElemType ;
typedef char Elemtype ;
#include "../SequenceStack.h"
typedef struct{
    double *top;
    double *base;
    int size;
}DoubleSqStack;
int InitDoubleStack(DoubleSqStack *s){
    s->base = (double *)malloc(STACKMAXSIZE * sizeof(double));
    if(!s->base){
        printf("InitStack ERROR!\n");
    }
    s->size = STACKMAXSIZE;
    s->top = s->base;
    printf("InitIntStack SUCCESS!\n");
    return SUCCESS;
}
int DestoryDoubleStack(DoubleSqStack *s){
    s->top = s->base = null;
    s->size = 0;
    printf("DestoryStack SUCCESS!\n");
    return SUCCESS;
};
int GetDoubleTop(DoubleSqStack s, double *e){
    if(s.base == s.top){
        printf("Stack's top is null!\n");
        return ERROR;
    }
    *e = *(s.top-1);
    return SUCCESS;
};
int pushDouble(DoubleSqStack *s, double e){
    if(s->top - s->base >= s->size){
        double * new_ptr = realloc(s->base, sizeof(double) * (s->size + STACKINCREASESIZE));
        while(!new_ptr){
            printf("Push ERROR!\n");
            exit(OVERFLOW);
        }
        s->base = new_ptr;
        s->top = s->base + s->size;
        (*s).size = (*s).size + STACKINCREASESIZE;
    }
    *(s->top) = e;
    (s->top)++ ;
    return SUCCESS;
}
int popDouble(DoubleSqStack *s, double *e){
    if(s->base == s->top){
        printf("pop ERROR!\n");
        exit(OVERFLOW);
    }
    s->top --;
    *e = *s->top;
    return SUCCESS;
}
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
double Operate(double a , Elemtype theta , double b){
    double m = a;
    double n = b;
    double z;
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
    return z;
}
Elemtype GetTop_Sq(SqStack s){
    Elemtype e;
    GetTop( s , &e);
    return e;
};
/*
 *
 * Input must be integer
 *
 */
Elemtype EvaluateExpression(SqStack *OPTR, DoubleSqStack *OPND){

    InitStack(OPTR);
    push(OPTR , '#');
    InitDoubleStack(OPND);
    Elemtype c ;
    scanf(" %c",&c);
    Elemtype theta, e;
    double a , b;
    while(c != '#' || GetTop_Sq(*OPTR) != '#'){
        if(!In(c)){
            pushDouble(OPND , c-48);
            scanf(" %c",&c);
        }else{
            switch (Precede(GetTop_Sq(*OPTR) , c)){
                case '>':
                    pop(OPTR , &theta);
                    popDouble(OPND , &b);
                    popDouble(OPND , &a);
                    pushDouble(OPND , Operate(a , theta , b));
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
    double s;
    GetDoubleTop(*OPND , &s);
    printf("=%f\n",s);
}
#endif //CPROJECTS_C_EVALUATEEXPRESSION_H
