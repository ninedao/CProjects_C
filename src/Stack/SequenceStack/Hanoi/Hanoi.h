//
// Created by POPO LIU on 2019-09-30.
//

#ifndef CPROJECTS_C_HANOI_H
#define CPROJECTS_C_HANOI_H

#include "../SequenceStack.h"
static int c = 0;
static int count = 0;
static int a[8][8] ;
void move(char x , int n , char z){
    FILE *file;
    file = fopen("C:\\Users\\POPO LIU\\Desktop\\1.txt","at");
    printf("%d. Move disk %d from %c to %c\n", ++c , n , x , z);
    fprintf(file,"%d. Move disk %d from %c to %c\n", c , n , x , z);
    fclose(file);
}
status hanoi(int n , char x , char y , char z){
    if(n == 1){
        move(x , 1 , z);
    }else{
        hanoi(n-1 , x , z , y);
        move(x , n , z);
        hanoi( n - 1, y , x , z);
    }
}
status checkQueen(int row , int column){
    for(int i = 0 ; i < 8 ; i++){
        if(a[row][i] == 1){
           return FALSE;
        }
    }
    for(int i = 0 ; i < 8 ; i++){
        if(a[i][column] == 1) {
            return FALSE;
        }
    }
    for(int i = row - 1 , j = column - 1 ; i >= 0 && j >= 0 ; --i,--j){
        if(a[i][j] == 1) {
            return FALSE;
        }
    }
    for(int i = row - 1 , j = column + 1 ; i >= 0 && j < 8 ; --i,++j){
        if(a[i][j] == 1) {
            return FALSE;
        }
    }
    return TRUE;
}
status showQueens(){
    printf("NO.%d\n" , count);
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(a[i][j] == 1){
                printf("o ");
            }else{
                printf("+ ");
            }

        }
        printf("\n");
    }
}
status findQueen(int row){
    if(row >= 8){
        count ++;
        showQueens();
        return SUCCESS;
    }
    for(int column = 0 ; column < 8 ; column++){
        if(checkQueen(row,column)) {
            a[row][column] = 1;
            findQueen(row + 1);
            a[row][column] = 0;
        }
    }
}
#endif //CPROJECTS_C_HANOI_H
