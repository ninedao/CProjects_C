//
// Created by POPO LIU on 2019-09-23.
//

#ifndef CPROJECTS_C_LINKSTACK_H
#define CPROJECTS_C_LINKSTACK_H
#include "../Stack.h"
#if !defined(CPROJECTS_C_MATCHBRACE_H)
    typedef int ElemType;
    int visit(ElemType e){
        printf("%d ",e);
        return SUCCESS;
    }
#endif
typedef struct SqStack{
    ElemType data;
    struct SqStack *next;
}SqStack;

typedef struct {
    SqStack *top;
    int len;
}StackTop;

int InitStack(StackTop *s){
    s->top = (SqStack *)malloc(sizeof(SqStack));
    if(!s->top){
        printf("InitStack ERROR!\n");
        exit(OVERFLOW);
    }
    s->top->next = null;
    s->len = 0;
    printf("InitStack SUCCESS!\n");
    return SUCCESS;
}
int DestoryStack(StackTop *s){
    free(s->top);
    s->top = null;
    s->len = 0;
    printf("DestoryStack SUCCESS!\n");
    return SUCCESS;
}
int ClearStack(StackTop *s){
    s->top->next = null;
    s->len = 0;
    printf("ClearStack SUCCESS!\n");
    return SUCCESS;
}
int StackEmpty(StackTop s){
    if(s.len == 0){
        printf("Stack is empty!\n");
        return TRUE;
    }else{
        printf("Stack is not empty!\n");
        return FALSE;
    }
}
int StackLength(StackTop s){
    printf("StackTop's length is %d!\n",s.len);
    return s.len;
}
int GetTop(StackTop s, ElemType *p){
    if(s.len == 0){
        printf("StackTop is empty!\n");
        return ERROR;
    }
    *p = s.top->next->data;
    //printf("StackTop's top is %d!\n",*p);
    return SUCCESS;
}
int Pop(StackTop *s,ElemType *e){
    if(s->len <= 0){
        printf("Push ERROR!\n");
        exit(OVERFLOW);
    }
    SqStack *p = s->top->next;
    *e = p->data;
    s->top->next = p->next;
    s->len --;
    printf("Pop SUCCESS!\n");
    return SUCCESS;
}
int Push(StackTop *s,ElemType e){
    SqStack *p ;
    p = (SqStack *)malloc(sizeof(SqStack));
    if(!p){
        printf("Push ERROR!\n");
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = s->top->next;
    s->top->next = p;
    s->len ++;
    printf("Push SUCCESS!\n");
    return SUCCESS;
}

int StackTravarse(StackTop S,int (*visit)(ElemType)){
    SqStack *p = S.top->next;
    while(p){
        (*visit)(p->data);
        p = p->next;
    }
    printf("\n");
    return SUCCESS;
}
void concersion(StackTop *s){
    ClearStack(s);
    ElemType m , n , e;
    scanf("%d %d", &m ,&n);
    while(m){
        Push(s,m % n);
        m = m /n;
    }
    StackTravarse(*s , visit);
    while(s->len){
        Pop(s , &e);
        printf("%d\n",e);
    }
    printf("concersion SUCCESS!\n");
}
#endif //CPROJECTS_C_LINKSTACK_H
