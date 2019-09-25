//
// Created by POPO LIU on 2019-09-24.
//

#ifndef CPROJECTS_C_MAZE_H
#define CPROJECTS_C_MAZE_H
#define N 12
#define X 4
#define SleepTime 2
typedef int MazeType;
typedef enum{
    Wall,
    Obstacle,
    Way,
    DeadLock,
    East,South,West,North
}MazeNode;
typedef struct {
    int x;
    int y;
}PosType;
typedef struct{
    int ord;
    PosType seat;
    int di;
}ElemType;
#include "../SequenceStack.h"
int InitMaze(MazeType maze[][N], PosType *start, PosType *end){
    int tem ;
    srand((unsigned)time(null));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            if(i == 0 || j == 0 || i == N-1 || j == N-1){
                maze[i][j] = Wall;
            }else{
                tem = rand()%X;
                if(!tem){
                    maze[i][j] = Obstacle;
                }else{
                    maze[i][j] = Way;
                }
            }
        }
    }
    start->x = 1;
    start->y = 0;
    end->x = N - 2;
    end->y = N - 1;
    maze[1][0] = maze[N-2][N-1] = Way;
    maze[1][1] = maze[N-2][N-2] = Way;
    printf("InitMaze SUCCESS!\n");
    return SUCCESS;
}
int PaintMaze(MazeType maze[][N]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            if(maze[i][j] == Wall ){
                printf("¨€");
            }else if(maze[i][j] == Obstacle){
                printf("¨€");
            }else if(maze[i][j] == East){
                printf("¡ú");
            }else if(maze[i][j] == South){
                printf("¡ý");
            }else if(maze[i][j] == West){
                printf("¡û");
            }else if(maze[i][j] == North){
                printf("¡ü");
            }else if(maze[i][j] == DeadLock){
                printf("¡Á");
            }else{
                printf("  ");
            }
            if(j != 0 && j % (N - 1) == 0){
                printf("\n");
            }
        }

    }
    return SUCCESS;
}
PosType NextPos(PosType seat, int di){
    switch(di){
        case North:
            seat.x--;
            break;
        case South:
            seat.x++;
            break;
        case West:
            seat.y--;
            break;
        case East:
            seat.y++;
            break;
    }
    return seat;
}
int IsCross(PosType seat){
    if(seat.x < 0 || seat.y < 0 || seat.x > N-1 || seat.y > N-1){
        return TRUE;
    }else{
        return FALSE;
    }
}
int MakeMark(PosType seat, MazeType maze[][N]){
    maze[seat.x][seat.y] = DeadLock;
}
int EqualMaze(PosType seat1, PosType seat2){
    if(seat1.x == seat2.x && seat1.y == seat2.y){
        return TRUE;
    }else{
        return FALSE;
    }
}
int Pass(PosType seat, MazeType maze[][N]){
    if(!IsCross(seat) && maze[seat.x][seat.y] == Way){
        return TRUE;
    }else{
        return FALSE;
    }
}
void FootPrint(PosType seat, MazeType maze[][N]){
    maze[seat.x][seat.y] = East;
}
void SetElemType(ElemType *e, int ord, PosType seat, int di){
    e->ord = ord;
    e->seat = seat;
    e->di = di;
}
void ShowMaze(MazeType maze[][N]){
    /*double start = time(0);
    double end = time(0);
    while(end - start <= 1){
        end = time(0);
    }
    system("CLS");*/
    PaintMaze(maze);
}
int MazePath(MazeType maze[][N], PosType start, PosType end){
    SqStack s;
    InitStack(&s);
    ElemType curElem;
    PosType curpos = start;
    int curStep = 1;
    do{
        if(Pass(curpos,maze)){
            FootPrint(curpos , maze);
            ShowMaze(maze);
            SetElemType(&curElem , curStep , curpos , East);
            push(&s , curElem);
            if(EqualMaze(curpos, end)){
                printf("Search path SUCCESS;\n");
                return TRUE;
            }
            curpos = NextPos(curpos , East);
            curStep++;
        }else{

            if(!StackEmpty(s)){
                pop(&s , &curElem);
                while(curElem.di == North && !StackEmpty(s)){
                    MakeMark(curElem.seat , maze);
                    ShowMaze(maze);
                    pop(&s , &curElem);
                }
                if(curElem.di <North){
                    ++curElem.di;
                    maze[curElem.seat.x][curElem.seat.y] = curElem.di;
                    ShowMaze(maze);
                    push(&s , curElem);
                    curpos = NextPos(curElem.seat, curElem.di);
                }
            }
        }
    }while(!StackEmpty(s));
    printf("Search path FAIL;\n");
    return FAIL;
}
#endif //CPROJECTS_C_MAZE_H
