//
// Created by POPO LIU on 2019-09-25.
//

#ifndef CPROJECTS_C_EVALUATEEXPRESSION_H
#define CPROJECTS_C_EVALUATEEXPRESSION_H
typedef char Elemtype ;
#include "../SequenceStack.h"
status In(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '#' ||  c == '(' ||  c == ')'){
        return TRUE;
    }else{
        return FALSE;
    }
}
char Precede(char o , char c){
    switch(c){
        case '+':
            if(o == '+' || o == '-' || o == ')' || o == '#'){
                return '>';
            }else{
                return '<';
            }
        case '-':
            if(o == '+' || o == '-' || o == ')' || o == '#'){
                return '>';
            }else{
                return '<';
            }
        case '*':
            if(o == '('){
                return '<';
            }else{
                return '>';
            }
        case '/':
            if(o == '('){
                return '<';
            }else{
                return '>';
            }
        case '(':
            if(o == '+' || o == '-' || o == ')'){
                return '>';
            }else{
                return '<';
            }
        case ')':
            if(o == '+' || o == '-' || o == ')'){
                return '>';
            }else{
                return '<';
            }
        case '#':
            if(o == '+' || o == '-' || o == ')'){
                return '>';
            }else{
                return '<';
            }
    }
}
#endif //CPROJECTS_C_EVALUATEEXPRESSION_H
