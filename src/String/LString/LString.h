//
// Created by POPO LIU on 2019-10-08.
//

#ifndef CPROJECTS_C_LSTRING_H
#define CPROJECTS_C_LSTRING_H
#define CHUNKSIZE 4
#include "../../common/common.h"
typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;
typedef struct{
    Chunk *head, *tail;
    int curlen;
}LString;
status InitLString(LString *l){
    l->curlen = 0;
    l->head = l->tail = null;
    return SUCCESS;
}
void StrPrint(LString l){
    int i = 0;
    Chunk *p = l.head;
    while(i < l.curlen){
        for(int j = 0 ; j < CHUNKSIZE ; j++) {
            if (p->ch[j]) {
                printf("%c", p->ch[j]);
                i++;
            }
        }
        p = p->next;
    }
    printf("\n");
}
status StrAssign_L(LString *l, char *chars){
    int i, j, k, m;
    Chunk *p, *q;
    i = strlen(chars);
    if(!i){
        printf("AtrAssign_L ERROR");
        return ERROR;
    }
    l->curlen=i;
    j = i / CHUNKSIZE;
    if(i % CHUNKSIZE){
        j++;
    }
    for(k = 1 ; k <= j ; k++){
        p = (Chunk *)malloc(sizeof(Chunk));
        if(!p){
            printf("AtrAssign_L ERROR");
            return ERROR;
        }
        p->next = null;
        if(k == 1){
            l->head = l->tail = p;
        }else{
            l->tail->next = p;
            l->tail = p;
        }
        for(m = 0 ; m < CHUNKSIZE && m + (k-1) * CHUNKSIZE < i; m++){
            l->tail->ch[m] = chars[m + (k-1) * CHUNKSIZE];
        }
    }
    while(m < CHUNKSIZE){
        l->tail->ch[m]='\0';
        m++;
    }
    return OK;
}
status StrCopy_L(LString *l, LString s){
    Chunk *p = l->head,*q = s.head;
    InitLString(l);
    for(; q; q = q->next){
        Chunk *r = (Chunk *)malloc(sizeof(Chunk));
        if(!r){
            printf("StrCopy_L ERROR");
            return ERROR;
        }
        if(q == s.head){
            l->head = l->tail = r;
        }else{
            l->tail->next = r;
            l->tail = r;
        }
        for(int i = 0; i < CHUNKSIZE ; i++){
            r->ch[i] = q->ch[i];
        }
    }
    l->curlen = s.curlen;
    return SUCCESS;
}
status StrEmpty_L(LString s){
    if(s.head == null && s.tail == null && s.curlen == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}
int StrCompare_L(LString s, LString l){
    int i = s.curlen, j = l.curlen;
    Chunk *p = s.head;
    Chunk *q = l.head;
    while(p && q){
        for(int k = 0 ; k < CHUNKSIZE ; k++){
            if(p->ch[k] != q->ch[k]){
                return p->ch[k] - q->ch[k];
            }
        }
        q = q->next;
        p = p->next;
    }
    return i - j;
}
int StrLength_L(LString s){
    return s.curlen;
}
status ClearString(LString s){
    Chunk *p,*q;
    p = s.head;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    s.curlen = 0;
    s.head = s.tail = null;
    s.curlen = 0;
    return SUCCESS;
}
status StrConcat(LString *t, LString s, LString l){
    int i = 0, j = 0, k = 0;
    InitLString(t);
    Chunk *p = s.head, *q = l.head, *r = t->head;
    while(p || q){
        if(!r){
            r = (Chunk *)malloc(sizeof(Chunk));
            if(!r){
                exit(OVERFLOW);
            }
            r->next = null;
            if(!t->head){
                t->head = t->tail = r;
            }else{
                t->tail->next = r;
                t->tail = r;
            }
        }
        if(p){
            while(p && p->ch[j]){
                r->ch[i] = p->ch[j];
                i = (i + 1) % CHUNKSIZE;
                j = (j + 1) % CHUNKSIZE;
                if(!j || !p->ch[j]){
                    p = p->next;
                }
                if(!i){
                    r = r->next;
                    break;
                }
            }
        }else{
            while(q && q->ch[k]){
                r->ch[i] = q->ch[k];
                i = (i + 1) % CHUNKSIZE;
                k = (k + 1) % CHUNKSIZE;
                if(!k || !q->ch[k]){
                    q = q->next;
                }
                if(!i){
                    r = r->next;
                    break;
                }
            }
        }
    }
    t->curlen = s.curlen + l.curlen;
    int count = (t->curlen - 1) % CHUNKSIZE +1;
    while(count < CHUNKSIZE){
        t->tail->ch[count] = '\0';
        count++;
    }
    return SUCCESS;
}
status SubString_L(LString *t, LString s , int pos, int len){
    if(StrEmpty_L(s)){
        return ERROR;
    }
    if(pos < 1 || len < 0 || pos > s.curlen || pos + len - 1 > s.curlen){
        return ERROR;
    }
    InitLString(t);
    Chunk *p = s.head;
    Chunk *r = t->head;
    for(int m = 1; pos > m * CHUNKSIZE; p = p->next);
    int i = 0, j = 0 ;
    int k = (pos - 1) % CHUNKSIZE ;
    while(i < len){
        if(!r){
            r = (Chunk *)malloc(sizeof(Chunk));
            if(!r){
                exit(OVERFLOW);
            }
            r->next = null;
            if(!t->head){
                t->head = t->tail = r;
            }else{
                t->tail->next = r;
                t->tail = r;
            }
        }
        while(i < len){
            r->ch[j] = p->ch[k];
            j = (j + 1) % CHUNKSIZE;
            k = (k + 1) % CHUNKSIZE;
            i++;
            if(!k){
                p = p->next;
            }
            if(!j){
                r = r->next;
                break;
            }
        }
    }
    t->curlen = len;
    int count = (t->curlen - 1) % CHUNKSIZE + 1;
    while(count < CHUNKSIZE){
        t->tail->ch[count] = '\0';
        count ++;
    }
    return SUCCESS;
}
#endif //CPROJECTS_C_LSTRING_H
