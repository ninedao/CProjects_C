//
// Created by POPO LIU on 2019-11-24.
//
#include "../HString/HString.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "../../List/LinkListWithNode/LinkList.h"
#define MaxBookNum 1000
#define MaxKeyNum 2500
#define MaxLineLen 500
#define MaxWordNum 10
typedef status Bool;
typedef struct{
    char *item[MaxWordNum];
    int last;
}WordListType;
typedef struct{
    HString key;
    LinkList bnolist;
}IdxTermType;
typedef struct {
    IdxTermType item[MaxKeyNum + 1];
    int last;
}IdxListType;
char buf[MaxLineLen];
WordListType wdlist;
WordListType gWordList = {{"a","an","the","of","and","is","to","as","in","for"},10};
void InitIdxList(IdxListType *idxList){
    char *chars ="KeyWord        BookIndex";
    StrAssign_H(&(idxList->item[0].key), chars);
    InitList(&(idxList->item[0].bnolist));
    idxList->last = 0;
}
void GetLine(FILE *f){
   int len;
   fgets(buf, MaxLineLen, f);
   len = strlen(buf);
   buf[len - 1] ='\0';
}
void Locate(IdxListType idxlist, HString wd, Bool *b){

}
void InsertNewKey(IdxListType *idxlist, int i, HString wd){

}
status InsertBook(IdxListType *idxlist, int i, int bno){

}
void ExtractKeyWord(int *bno){
    char *title;
    FILE *fp;
    *bno = strtol(buf, &title, 10);
    strlwr(title);
    fp = tmpfile();
    fprintf(fp, "%s", title);
    fseek(fp, 0, SEEK_SET);
    for(wdlist.last = 0; wdlist.last < MaxWordNum; wdlist.last++){
        wdlist.item[wdlist.last] = (char*)malloc(MaxLineLen * sizeof(char));
        if(!wdlist.item[wdlist.last]){
            exit(OVERFLOW);
        }
        if(fscanf(fp, "%s", gWordList.item[gWordList.last])==EOF)
            break;
    }
}
void GetWord(int i, HString *wd){
    char *p = gWordList.item[i];
    StrAssign_H(wd, p);
}
status isCommonWords(HString s){
    int i, len;
    char a[s.length++];
    status flag = FALSE;
    for(int i = 0 ; i < s.length ; i++){
        a[i] = s.ch[i];
    }
    a[i] = '\0';
    for(int i = 0 ; i < gWordList.last ; i ++){
        if(!strcmpi(a[i], gWordList.item[i])){
            flag = TRUE;
            break;
        }
    }
    return flag;
}
status InsIdxList(IdxListType *idxlist, int bno){
    int i, j;
    Bool boo;
    HString wd;
    if(!gWordList.last){
        return ERROR;
    }
    for(int i = 0; i < gWordList.last ; i++){
        GetWord(i, &wd);
        //if(!)
    }
}
void PutText(FILE g, IdxListType idxlist){

}
int main(){
    FILE *f, *g;
    IdxListType idxlist;
    int BookNo;
    if(f = fopen("","r")){
        if(g = fopen("","w")){
            InitIdxList(&idxlist);
            while(!feof(f)){
                GetLine(&f);
                ExtractKeyWord(BookNo);
                InsIdxList(&idxlist, BookNo);
            }
            PutText(g,idxlist);
        }
    }
}

