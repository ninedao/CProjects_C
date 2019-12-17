//
// Created by POPO LIU on 2019-12-15.
//

#include "CrossList.h"
int main(){
    CrossList M, N;

    CreateSMatrix_OL(&M);
    CreateSMatrix_OL(&N);
    PrintSMatrix_OL(M);

    PrintSMatrix_OL(N);
    AddSMatrix_OL(&M, N);
    PrintSMatrix_OL(M);
}