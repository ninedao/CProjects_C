//
// Created by POPO LIU on 2019-09-24.
//

#include "Maze.h"
int main(){
    PosType start, end;
    MazeType maze[N][N];

    char re = 'Y';
    while(re == 'Y' || re == 'y'){
        InitMaze(maze , &start , &end);
        ShowMaze(maze);
        MazePath(maze,start,end);

        printf("review? (Y/N) : ");
        scanf("%c",&re);
    }
}