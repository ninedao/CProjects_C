//
// Created by POPO LIU on 2019-12-15.
//

#ifndef CPROJECTS_C_CROSSLIST_H
#define CPROJECTS_C_CROSSLIST_H

#include "../../common/common.h"

typedef  int ElemType;
typedef struct OLNode{
    int i,j;
    ElemType e;
    struct OLNode  *right, *down;
}OLNode, *OLink;
typedef struct{
    OLink *rhead, *chead;
    int rows, cols, count;
}CrossList;

status CreateSMatrix_OL(CrossList *M){
    printf("Input rows cols and counts:");
    scanf("%d %d %d", &M->rows, &M->cols, &M->count);
    M->rhead = (OLink *) malloc((M->rows + 1) * sizeof(OLink));
    if(!M->rhead){
        printf("CreateSMatrix_OL ERROR\n");
        exit(OVERFLOW);
    }
    for(int i = 0; i <= M->rows; i++){
        M->rhead[i] = NULL;
    }
    M->chead = (OLink *) malloc((M->cols + 1) * sizeof(OLink));
    if(!M->chead){
        printf("CreateSMatrix_OL ERROR\n");
        exit(OVERFLOW);
    }
    for(int i = 0; i <= M->cols; i++){
        M->chead[i] = NULL;
    }
    int x, y, e;
    for(int i = 1; i <= M->count; i++){
        printf("Input %d num:", i);
        scanf("%d %d %d", &x, &y, &e);
        OLNode *p = (OLNode *)malloc(sizeof(OLNode));
        if(!p){
            printf("CreateSMatrix_OL ERROR\n");
            exit(OVERFLOW);
        }
        p->i = x;
        p->j = y;
        p->e = e;
        if(M->rhead[x] == NULL || M->rhead[x]->j > y){
            p->right = M->rhead[x];
            M->rhead[x] = p;
        }else{
            OLNode *q;
            for(q = M->rhead[x]; q->right && q->right->j < y; q = q->right);
            p->right = q->right;
            q->right = p;
        }
        if(M->chead[y] == NULL || M->chead[y]->i > x){
            p->down = M->chead[y];
            M->chead[y] = p;
        }else{
            OLNode *q;
            for(q = M->chead[y]; q->down  && q->down->i < x; q = q->down);
            p->down = q->down;
            q->down = p;
        }
    }
    return SUCCESS;
}
status AddSMatrix_OL(CrossList *A, CrossList B){
    if(A->rows != B.rows || A->cols != B.cols){
        return ERROR;
    }
    OLNode *pa, *pb, *pre;
    OLink  *hl = (OLink *)malloc(A->cols * sizeof(OLink));
    pre = NULL;
    OLNode *p = (OLNode *) malloc(sizeof(OLNode));
    for(int j = 1; j <= A->cols; j++){
        hl[j] = A->chead[j];
    }

    for(int i = 1; i <= A->rows ; i++){

        pa = A->rhead[i];
        pb = B.rhead[i];
        while(pb != NULL) {

            if(!p) {
                OLNode *p = (OLNode *) malloc(sizeof(OLNode));
            }
            p->i = pb->i;
            p->j = pb->j;
            p->e = pb->e;
            p->right = NULL;
            p->down = NULL;

            if (pa == NULL || pa->j > pb->j) {
                if (pre == NULL) {
                    A->rhead[p->i] = p;
                } else {
                    pre->right = p;
                }
                p->right = pa;
                pre = p;
                if(!A->chead[p->j] || A->chead[p->j]->i > p->i){
                    p->down = A->chead[p->j];
                    A->chead[p->j] = p;
                }else{
                    p->down = hl[p->j]->down;
                    hl[p->j]->down = p;
                }
                hl[p->j] = p;
            } else if (pa->j < pb->j) {
                pre = pa;
                pa = pa->right;
                continue;
            } else if (pa->j == pb->j) {
                pa->e += pb->e;
                if (pa->e == 0) {
                    if(pre == NULL){
                        A->rhead[pa->i] = pa->right;
                    }else{
                        pre->right = pa->right;
                    }

                    p = pa;
                    pa = pa->right;
                    if(A->chead[p->j] == p){
                        A->chead[p->j] = hl[p->j] = p->down;
                    }else{
                        hl[p->j]->down = p->down;
                    }
                }
            }
            pb = pb->right;
        }

    }
    return SUCCESS;
}
status PrintSMatrix_OL(CrossList M){

    OLNode *p ;

    for(int i = 1; i <= M.rows ; i++){
        p = M.rhead[i];
        for(int j = 1; j <= M.cols ; j++){
            if(p && p->j == j){
                printf("%-3d", p->e);
                p = p->right;
            }else{
                printf("0  ");
            }
        }
        printf("\n");
    }
    return SUCCESS;
}
#endif //CPROJECTS_C_CROSSLIST_H
