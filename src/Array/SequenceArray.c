//
// Created by POPO LIU on 2019-11-25.
//

#include "SequenceArray.h"
int main(){
     Array A;
    InitArray(&A, 2, 3, 2);
    ElemType e = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2 ; j++){
            printf("setA[%d][%d]Value(%d)\n", i, j, ++e);
            Assign(&A, e, i, j);
        }
    }
    printArray(A);
    Value(A, &e, 2, 2);
    printf("%d\n",e);
}
