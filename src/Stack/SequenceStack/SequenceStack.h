//
// Created by POPO LIU on 2019-09-22.
//
#include "../Stack.h"
#ifndef CPROJECTS_C_SEQUENCESTACK_H
#define CPROJECTS_C_SEQUENCESTACK_H
#if !defined(CPROJECTS_C_LINEEDIT_H)
int visit(ElemType e){
    printf("%d ", e);
}
#endif
int InitStack(SqStack *s){
    s->base = (ElemType *)malloc(sizeof(ElemType));
    if(!s->base){
        printf("InitStack ERROR!\n");
    }
    s->size = STACKMAXSIZE;
    s->top = s->base;
    printf("InitStack SUCCESS!\n");
    return SUCCESS;
}
int DestoryStack(SqStack *s){
    s->top = s->base = null;
    s->size = 0;
    printf("DestoryStack SUCCESS!\n");
    return SUCCESS;
};
int ClearStack(SqStack *s){
    s->top = s->base;
    printf("ClearStack SUCCESS!\n");
    return SUCCESS;
};
int StackEmpty(SqStack s){
    if(s.base == s.top){
        printf("Stack is empty!\n");
        return TRUE;
    }else{
        printf("Stack is not empty!\n");
        return FALSE;
    }
}
int StackLength(SqStack s){
    printf("Stack's length is %d!\n",s.top - s.base);
    return s.top - s.base;
}
int GetTop(SqStack s, ElemType *e){
    if(s.base == s.top){
        printf("Stack's top is null!\n");
        return ERROR;
    }
    e = s.top-1;
    return SUCCESS;
};
int push(SqStack *s, ElemType e){
    if(s->top - s->base >= s->size){
        //s->base = (ElemType *)realloc(s->base,((s->size + STACKINCREASESIZE) * sizeof(ElemType)));
        /*if(!s->base){
            printf("Push ERROR!\n");
            exit(OVERFLOW);
        }*/
        //s->top = s->base + s->size;
        s->size = s->size + STACKINCREASESIZE;
    }
    *(s->top) = e;
    s->top ++;
    return SUCCESS;
}
int pop(SqStack *s, ElemType *e){
    if(s->top == s->base){
        printf("pop ERROR!\n");
        exit(OVERFLOW);
    }
    s->top --;
    *e = *(s->top);
    return SUCCESS;
}

int StackTraverse(SqStack s, int (*visit)(ElemType)){
    ElemType *p = s.base;
    while(p != s.top){
        (*visit)(*p);
        p++;
    }
    printf("\n");
}

#endif //CPROJECTS_C_SEQUENCESTACK_H
