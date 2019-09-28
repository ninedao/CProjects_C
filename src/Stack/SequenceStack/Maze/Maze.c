//
// Created by POPO LIU on 2019-09-24.
//

#include "Maze.h"
int main(){
    PosType start, end;
    MazeType maze[N][N];
    SqStack s;
    InitStack(&s);
    char re = 'Y';
    printf("go on? (Y/N) : ");
    scanf(" %c",&re);
    while( re =='Y' || re == 'y'){
        InitMaze(maze , &start , &end);
        ShowMaze(maze);
        ClearStack(&s);
        MazePath(&s,maze,start,end);
        printf("review? (Y/N) : ");
        scanf(" %c",&re);
    }
}