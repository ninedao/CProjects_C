//
// Created by POPO LIU on 2019-09-25.
//

#include "EvaluateExpression.h"
int main(){
    SqStack OPTR ;
    DoubleSqStack OPND;
    char re = 'Y';
    printf("go on? (Y/N) : ");
    scanf(" %c",&re);
    while( re =='Y' || re == 'y') {
        EvaluateExpression(&OPTR, &OPND);
        DestoryStack(&OPTR);
        DestoryDoubleStack(&OPND);
        printf("go on? (Y/N) : ");
        scanf(" %c",&re);

    }
}