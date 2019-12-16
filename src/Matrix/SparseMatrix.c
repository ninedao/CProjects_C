//
// Created by POPO LIU on 2019-11-28.
//

#include "SparseMatrix.h"
int main(){
    /*TSMatrix M,T,Q;
    CreateSMatrix(&M);
    CreateSMatrix(&T);
    MultSMatrix(M, T, &Q);
    PrintSMatrix(M);
    PrintSMatrix(T);
    PrintSMatrix(Q);*/
    RLSMatrix M,T,Q;
    RLSCreateSMatrix(&M);
    RLSCreateSMatrix(&T);
    FASTMultSMatrix(M, T, &Q);
    RLSPrintSMatrix(M);
    RLSPrintSMatrix(T);
    RLSPrintSMatrix(Q);
//    PrintSMatrix(M);
//    CopySMatrix(M, &T);
//    T.data[2].e = 7;
//    PrintSMatrix(T);
//    PrintSMatrix(M);
//    TransposeSMatrix(T, &Q);
//    PrintSMatrix(Q);
//    FastTransposeSMatrix(T, &Q);
//    PrintSMatrix(Q);
}