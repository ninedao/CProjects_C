//
// Created by POPO LIU on 2019-11-28.
//

#ifndef CPROJECTS_C_SPARSEMATRIX_H
#define CPROJECTS_C_SPARSEMATRIX_H
#define MAXSIZE 10000
#define MAXRC 100
#include "../common/common.h"
typedef int ElemType;
typedef struct{
    int x,y;
     ElemType e;
}Triple;
typedef struct{
    Triple data[MAXSIZE + 1];
    int row, col, num;
}TSMatrix;
typedef struct{
    Triple data[MAXSIZE + 1];
    int rpos[MAXRC + 1];
    int row, col, num;
}RLSMatrix;
status RLSCreateSMatrix(RLSMatrix *M){
    printf("Input row:");
    scanf("%d",&(M->row));
    printf("\n");
    printf("Input col:");
    scanf("%d",&(M->col));
    printf("\n");
    printf("Input num:");
    scanf("%d",&(M->num));
    printf("\n");
    for(int i = 1 ; i <= M->num ; i++){
        printf("Input %d num:", i);
        scanf("%d %d %d", &(M->data[i].x), &(M->data[i].y), &(M->data[i].e));
        printf("\n");
    }
    int num[M->row + 1];
    for(int i = 0; i <= M->row; i++){
        num[i] = 0;
    }
    for(int i = 1; i<= M->num; i++){
        ++num[M->data[i].x];
    }
    M->rpos[1] = 1;
    for(int i = 2; i <= M->row; i++){
        M->rpos[i] = M->rpos[i - 1] + num[i - 1];
    }
    return SUCCESS;
};
status CreateSMatrix(TSMatrix *M){
    printf("Input row:");
    scanf("%d",&(M->row));
    printf("\n");
    printf("Input col:");
    scanf("%d",&(M->col));
    printf("\n");
    printf("Input num:");
    scanf("%d",&(M->num));
    printf("\n");
    for(int i = 1 ; i <= M->num ; i++){
        printf("Input %d num:", i);
        scanf("%d %d %d", &(M->data[i].x), &(M->data[i].y), &(M->data[i].e));
        printf("\n");
    }
    return SUCCESS;
};
status DestorySMatrix(TSMatrix *M){
    M->num = 0;
    M->row = 0;
    M->col = 0;
};
status PrintSMatrix(TSMatrix M){
    int k = 1;
    for(int i = 1; i <= M.row; i++){
        for(int j = 1; j <= M.col; j++){
            if(M.data[k].x == i && M.data[k].y == j && k <= M.num){
                printf("%d ", M.data[k].e);
                k++;
            }else{
                printf("0 ");
            }

        }
        printf("\n");
    }
};
status RLSPrintSMatrix(RLSMatrix M){
    int k = 1;
    for(int i = 1; i <= M.row; i++){
        for(int j = 1; j <= M.col; j++){
            if(M.data[k].x == i && M.data[k].y == j && k <= M.num){
                printf("%d ", M.data[k].e);
                k++;
            }else{
                printf("0 ");
            }

        }
        printf("\n");
    }
};
status CopySMatrix(TSMatrix M, TSMatrix *T){
    (*T) = M;
};
status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q){
    if(M.row != N.row || M.col != N.col){
        printf("Can't add!\n");
        return FAIL;
    }
    Q->row = M.row;
    Q->col = M.col;
    int m = 1, n = 1, k = 1;
    while(m <= M.num && n<= N.num){
        if(M.row < N.row){
            Q->data[k].x = M.data[m].x;
            Q->data[k].y = M.data[m].y;
            Q->data[k].e = M.data[m].e;
            m++;
        }else if(M.row > N.row){
            Q->data[k].x = N.data[n].x;
            Q->data[k].y = N.data[n].y;
            Q->data[k].e = N.data[n].e;
            n++;
        }else{
            if(M.data[m].e + N.data[n].e) {
                Q->data[k].x = M.data[m].x;
                Q->data[k].y = M.data[m].y;
                Q->data[k].e = M.data[m].e + N.data[n].e;
                m++;
                n++;
            }else{
                m++;
                n++;
                continue;
            }
        }
        Q->num ++;
        k++;
    }
    while(m <= M.num){
        Q->data[k].x = M.data[m].x;
        Q->data[k].y = M.data[m].y;
        Q->data[k].e = M.data[m].e;
        m++;
        k++;
        Q->num++;
    }
    while(n <= N.num){
        Q->data[k].x = N.data[n].x;
        Q->data[k].y = N.data[n].y;
        Q->data[k].e = N.data[n].e;
        n++;
        k++;
        Q->num++;
    }
    return SUCCESS;
};
status SubSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q){
    if(M.row != N.row || M.col != N.col){
        printf("Can't add!\n");
        return FAIL;
    }
    Q->row = M.row;
    Q->col = M.col;
    int m = 1, n = 1, k = 1;
    while(m <= M.num && n<= N.num){
        if(M.row < N.row){
            Q->data[k].x = M.data[m].x;
            Q->data[k].y = M.data[m].y;
            Q->data[k].e = M.data[m].e;
            m++;
        }else if(M.row > N.row){
            Q->data[k].x = N.data[n].x;
            Q->data[k].y = N.data[n].y;
            Q->data[k].e = -N.data[n].e;
            n++;
        }else{
            if(M.data[m].e + N.data[n].e) {
                Q->data[k].x = M.data[m].x;
                Q->data[k].y = M.data[m].y;
                Q->data[k].e = M.data[m].e - N.data[n].e;
                m++;
                n++;
            }else{
                m++;
                n++;
                continue;
            }
        }
        Q->num ++;
        k++;
    }
    while(m <= M.num){
        Q->data[k].x = M.data[m].x;
        Q->data[k].y = M.data[m].y;
        Q->data[k].e = M.data[m].e;
        m++;
        k++;
        Q->num++;
    }
    while(n <= N.num){
        Q->data[k].x = N.data[n].x;
        Q->data[k].y = N.data[n].y;
        Q->data[k].e = -N.data[n].e;
        n++;
        k++;
        Q->num++;
    }
    return SUCCESS;
};
status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q){
    if(M.col != N.row){
        printf("Can't multiply");
        return FAIL;
    }
    Q->row = M.row;
    Q->col = N.col;
    Q->num = 0;
    if(M.num*N.num){
        for(int i = 1; i <= M.row ; i++){
            for(int j = 1; j <= N.col ; j++){
                int c = 0;
                for(int k = 1; k <= M.col ; k++){
                     int c1 = 0;
                    for(int l = 1; l <= M.num ; l++){
                        if(M.data[l].x == i && M.data[l].y == k){
                            c1 = M.data[l].e;
                            break;
                        }
                    }
                    int c2 = 0;
                    for(int l =1; l <= N.num ; l++){
                        if(N.data[l].x == k && N.data[l].y == j){
                            c2 = N.data[l].e;
                            break;
                        }
                    }
                    if(c1 && c2){
                        c += c1 * c2;
                    }
                }
                if(c){
                    Q->num++;
                    Q->data[Q->num].x = i;
                    Q->data[Q->num].y = j;
                    Q->data[Q->num].e = c;
                }
            }
        }
    }
    return SUCCESS;
};
status FASTMultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q){
    if(M.col != N.row){
        printf("Can't multiply");
        return FAIL;
    }
    Q->row = M.row;
    Q->col = N.col;
    Q->num = 0;
    int ctemp[N.col + 1];
    int tp, brow, t, ccol;
    if(M.num*N.num){
        for(int i = 1; i <= M.row ; i++){
            for(int j = 1; j <= N.col; j++){
                ctemp[j] = 0;
            }
            Q->rpos[i] = Q->num + 1 ;
            if(i < M.row){
                tp = M.rpos[i + 1];
            }else{
                tp = M.num + 1;
            }
            for(int j = M.rpos[i] ; j < tp ; j++){
                brow = M.data[j].y;
                if(brow < N.row){
                    t = N.rpos[brow + 1];
                }else{
                    t = N.num;
                }
                for(int k = N.rpos[brow] ; k < t ; k++){
                    ccol = N.data[k].y;
                    ctemp[ccol] += M.data[j].e * N.data[k].e;
                }
            }
            for(ccol = 1; ccol <= Q->col; ccol++){
                if(ctemp[ccol]){
                    if(++Q->num > MAXSIZE) {
                        //printf("Multiply ERROR");
                        return ERROR;
                    }
                    Q->data[Q->num].x = i;
                    Q->data[Q->num].y = ccol;
                    Q->data[Q->num].e = ctemp[ccol];
                }
            }
        }

    }
    return SUCCESS;
};
status TransposeSMatrix(TSMatrix M,TSMatrix *T){
    T->num = M.num;
    T->col = M.col;
    T->row = M.row;
    int q= 1;
    if(T->num){
        for(int i = 1 ; i <= M.col ; i++){
            for(int j = 1 ; j <= M.num ; j++){
                if(M.data[j].y == i){
                    T->data[q].x = M.data[j].y;
                    T->data[q].y = M.data[j].x;
                    T->data[q].e = M.data[j].e;
                    q++;
                }
            }
        }
    }
    return SUCCESS;
};
status FastTransposeSMatrix(TSMatrix M, TSMatrix *T){
    T->num = M.num;
    T->col = M.col;
    T->row = M.row;
    int num[M.col];
    int cpot[M.col];
    if(T->num){
        for(int i = 1; i <= M.col ; i++){
            num[i] = 0;
        }
        for(int i = 1; i <= M.num ; i++){
            ++num[M.data[i].y];
        }
        cpot[1] = 1;
        for(int i = 2 ; i <= T->col ; i++){
            cpot[i] = cpot[i-1] + num[i - 1];
        }
        for(int i = 1; i <= M.num ; i++){
            int col = M.data[i].y;
            int j = cpot[col];
            T->data[j].x = M.data[i].y;
            T->data[j].y = M.data[i].x;
            T->data[j].e = M.data[i].e;
            ++cpot[col];
        }
    }

}
#endif //CPROJECTS_C_SPARSEMATRIX_H
