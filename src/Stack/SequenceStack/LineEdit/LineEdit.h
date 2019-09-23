//
// Created by POPO LIU on 2019-09-23.
//

#ifndef CPROJECTS_C_LINEEDIT_H
#define CPROJECTS_C_LINEEDIT_H
#include "../../../common/common.h"
typedef char ElemType;
int visit(ElemType e){
    printf("%c",e);
    return SUCCESS;
}
#include "../SequenceStack.h"
int LineEdit(SqStack *s){
    ClearStack(s);
    ElemType e;
    char ch = getchar();
    int i = 0;
    while(ch != EOF){
        /*
        whli##ilr#e(s#*s)
         outcha@ putchar( *s=#++ );
         */
        while(ch != EOF && ch !='\n'){
            switch(ch){
                case '#' : pop(s , &e);
                    break;
                case '@' : ClearStack(s);
                    break;
                default : push(s , ch);
                    break;
            }
            ch = getchar();
        }
        StackTraverse(*s, visit);
        ClearStack(s);
        if(ch != EOF) {
            ch =getchar();
        }
    }
    DestoryStack(s);
}
#endif //CPROJECTS_C_LINEEDIT_H
