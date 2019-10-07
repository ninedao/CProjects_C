//
// Created by POPO LIU on 2019-10-02.
//

#ifndef CPROJECTS_C_BANK_SIMULATTION_H
#define CPROJECTS_C_BANK_SIMULATTION_H
#include "../../common/common.h"


typedef struct{
    int OccurTime;
    int NType;
} Event, ElemType;
typedef struct{
    int ArriveTime;
    int Duration;
}QElemType;
#include "../../List/LinkListWithNode/LinkList.h"
#include "../LinkQueue/LinkQueue.h"

typedef LinkList EventList;

EventList ev;
Event en;
LinkQueue queue[5];
QElemType customer;
int TotalTime , CustomerNum;
int CloseTime = 100;
int cmp(Event a, Event b){
    if(a.OccurTime > b.OccurTime){
        return 1;
    }else if(a.OccurTime == b.OccurTime){
        return 0;
    }else{
        return -1;
    }
}
void OpenForDay(){
    TotalTime = 0;
    CustomerNum = 0;
    InitList(&ev);
    en.OccurTime = 0 ;
    en.NType = 0;
    OrderInsert(&ev, en, compare);
    for(int i = 1; i < 5; i++){
        InitQueue(queue+i);
    }
    printf("Bank Open!\n");
}
int Minimun(){
    int i = 1;
    for(int j = 2; j < 5; j++){
        if(QueueLength(queue[j]) < QueueLength(queue[i])){
            i = j;
        }
    }
    return i;
}
void CustomerArrived(){
    int durtime, intertime;
    ++CustomerNum;
    //srand((unsigned)time(null));
    durtime = rand() % 100 + 1;
    intertime = 1;
    ElemType e,r;
    e.OccurTime = en.OccurTime + intertime;
    if(e.OccurTime < CloseTime){
        e.NType = 0;
        OrderInsert(&ev, e, compare);
    }else{
        printf("Bank Close!\n");
    }
    int i = Minimun();
    QElemType se;
    se.ArriveTime = en.OccurTime;
    se.Duration = durtime;
    EnQueue(&queue[i], se);
    if(QueueLength(queue[i]) == 1){
        r.OccurTime = en.OccurTime + durtime;
        r.NType = i;
        OrderInsert(&ev, r, compare);

    }
    printf("The arrival time of new customers is %d , queuing in queue %d, and business processing time is %d .\n",se.ArriveTime, i, durtime);
}
void CustomerDeparture(){
    int i = en.NType;
    DeQueue(&queue[i], &customer);
    TotalTime += en.OccurTime - customer.ArriveTime;
    if(!QueueEmpty(queue[i])){
        getHeadQueue(queue[i], &customer);
        ElemType e;
        e.OccurTime = en.OccurTime +customer.Duration;
        e.NType = i;
        OrderInsert(&ev, e, compare);
    }
    printf("The departure  time of new customers is %d , queuing in queue %d, and business processing time is %d.\n",en.OccurTime, i, customer.Duration);
}
void Bank_Simulation(){
    OpenForDay();
    while(!ListEmpty(ev)){
        Link p;
        DelFirst(GetHead(ev), &p);
        ev.len --;
        en = getCurElem(p);
        if(en.NType == 0){
            CustomerArrived();
        }else{
            CustomerDeparture();
        }
    }
    printf("Bank Close!\nThe total people is %d,The average time is %f!\n",CustomerNum,(float)TotalTime*1.0/CustomerNum);

}
#endif //CPROJECTS_C_BANK_SIMULATTION_H
