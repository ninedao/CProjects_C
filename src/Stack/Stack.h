//
// Created by POPO LIU on 2019-09-22.
//

#ifndef CPROJECTS_C_STACK_H
#define CPROJECTS_C_STACK_H
#include "../common/common.h"
#define STACKMAXSIZE 5
#define STACKINCREASESIZE 10
#if !defined(CPROJECTS_C_LINKSTACK_H) && \
    !defined(CPROJECTS_C_LINEEDIT_H) && \
    !defined(CPROJECTS_C_MAZE_H)
    typedef int ElemType;
#endif
#if !defined(CPROJECTS_C_LINKSTACK_H)

    typedef struct{
        ElemType *top;
        ElemType *base;
        int size;
    }SqStack;
    int InitStack(SqStack *s);
    int DestoryStack(SqStack *s);
    int ClearStack(SqStack *s);
    int StackEmpty(SqStack s);
    int StackLength(SqStack s);
    int GetTop(SqStack s, ElemType *e);
    int push(SqStack *s, ElemType e);
    int pop(SqStack *s, ElemType *e);
    int visit(ElemType e);
    int StackTraverse(SqStack s, int (*visit)(ElemType));
#endif
#endif //CPROJECTS_C_STACK_H
