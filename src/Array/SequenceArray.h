//
// Created by POPO LIU on 2019-11-25.
//
#include "../common/common.h"
#include<stdarg.h>
#ifndef CPROJECTS_C_SEQUENCEARRAY_H
#define CPROJECTS_C_SEQUENCEARRAY_H
#define MAX_ARRAY_DIM 8
typedef int  ElemType;
typedef struct{
    ElemType *base;
    int dim;
    int * bounds;
    int * constants;
}Array;
status InitArray(Array *A, int dim, ...){
  int total;
  va_list ap;
  if(dim < 1 || dim > MAX_ARRAY_DIM){
      printf("InitArray ERROR1\n");
      exit(OVERFLOW);
  }
  A->dim = dim;
  A->bounds = (int *)malloc(dim * sizeof(int));
  if(!A->bounds){
      printf("InitArray ERROR2\n");
      exit(OVERFLOW);
  }
  total = 1;
  va_start(ap,dim);
  for(int i = 0; i < dim ; i++){
      A->bounds[i] = va_arg(ap , int);
      if(A->bounds[i] < 0){
          printf("InitArray ERROR3\n");
          exit(OVERFLOW);
      }
      total *= A->bounds[i];
  }
  va_end(ap);
  A->base = (ElemType *)malloc(total * sizeof(ElemType));
  if(!A->base){
      printf("InitArray ERROR4\n");
      exit(OVERFLOW);
  }
  A->constants = (int *)malloc(dim * sizeof(int));
    if(!A->constants){
        printf("InitArray ERROR5\n");
        exit(OVERFLOW);
    }
    A->constants[dim - 1] =1;
    for(int i = dim - 2 ; i >= 0 ; --i){
        A->constants[i] = A->bounds[i + 1] *A->constants[i + 1];
    }
    return SUCCESS;
};
status DestoryArray(Array *A){
    if(!A->base)
        return ERROR;
    free(A->base);
    A->base = NULL;
    if(!A->bounds)
        return ERROR;
    free(A->bounds);
    A->bounds = NULL;
    if(!A->constants)
        return ERROR;
    free(A->constants);
    A->constants = NULL;
    A->dim = 0;
    return SUCCESS;
};
status Locate(Array A,va_list ap, int *off){
    *off = 0;
    int ind;
    for(int i = 0; i < A.dim ; i++){
        ind = va_arg(ap, int);
        if(ind < 0 || ind >= A.bounds[i]) {
            printf("Locate OVERFLOW\n");
            return OVERFLOW;
        }
        *off += A.constants[i] * ind;
    }
    return OK;
}
status Value(Array A, ElemType *e, ...){
    va_list ap;
    va_start(ap, *e);
    int result,off;
    result = Locate(A, ap, &off);
    if(result <= 0){
        return result;
    }
    *e = *(A.base + off);
    return OK;
};
status Assign(Array *A, ElemType e, ...){
    va_list ap;
    va_start(ap,e);
    int result,off;
    result = Locate(*A, ap, &off);
    if(result <= 0){
        return result;
    }
    *(A->base + off) = e;
    return OK;
};
void printArray(Array A){
    int total = 1;
    for(int i = 0 ; i < A.dim ; i++){
        total *= A.bounds[i];
    }
    for(int i = 0; i < total ; i++){
        printf("%d ", A.base[i]);
    }
    printf("\n");
}
#endif //CPROJECTS_C_SEQUENCEARRAY_H
