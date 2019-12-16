//
// Created by POPO LIU on 2019-10-07.
//
#include "../../common/common.h"
#ifndef CPROJECTS_C_HSTRING_H
#define CPROJECTS_C_HSTRING_H

#if defined(CPROJECTS_C_HSTRING_H)
    typedef struct{
        char *ch;
        int length;
    }HString;
#endif
void print(HString ss){
    for(int i = 0 ; i < ss.length ; i++){
        printf("%c" , ss.ch[i]);
    }
    printf("\n");
}
status StrAssign_H(HString *ss, char *chars){
    if(ss->ch){
        free(ss->ch);
    }
    int i = 0;
    char *c = chars;
    for(; *c ; ++i , ++c);
    if(!i){
        ss->ch = null;
        ss->length = 0;
    }else{
        ss->ch = (char *)malloc(i * sizeof(char));
        if(!ss->ch){
            printf("StrAssign_Sq ERROR!\n");
            exit(OVERFLOW);
        }
        for(int j = 0; chars[j] ; j++){
            ss->ch[j] = chars[j];
        }
        ss->length = i;
    }

}
status StrCopy_H(HString *a, const HString b){
    if(a->ch){
        free(a->ch);
    }
    a->ch = (char *)malloc(b.length * sizeof(char));
    if(!a->ch){
        printf("StrCopy_Sq ERROR!\n");
        exit(OVERFLOW);
    }
    for(int i = 0 ; i < b.length ; i++){
        a->ch[i] = b.ch[i];
    }
    a->length = b.length;
    return SUCCESS;
}
status StrEmpty_H(const HString ss){
    if(ss.length == 0 && ss.ch == NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}
int StrCompare_H(HString a, HString b){
    for(int i = 0 ;i < a.length && i < b.length ; i++){
        if(a.ch[i] != b.ch[i]){
            return a.ch[i] - b.ch[i];
        }
    }
    return a.length - b.length;
}
int StrLength_H(HString ss){
    return ss.length;
}
status ClearString_H(HString *ss){
    if(ss->ch){
        free(ss->ch);
        ss->ch = null;
    }
    ss->length = 0;
    return SUCCESS;
}
status Concat_H(HString *c, HString a, const HString b){
    if(c->ch){
        free(c->ch);
    }
    c->length = a.length + b.length;
    c->ch = (char *)malloc(c->length * sizeof(char));
    for(int i = 0 ; i < a.length; i++){
        c->ch[i] = a.ch[i];
    }
    for(int i = 0 ; i < b.length; i++){
        c->ch[a.length + i] = b.ch[i];
    }
    return SUCCESS;
}
status SubString_H(HString *sub, const HString s, int pos, int len){
    if(pos < 1 || len < 0 || s.length < pos + len -1){
        printf("SubString_H ERROR!\n");
        exit(OVERFLOW);
    }
    if(sub->ch){
        free(sub->ch);
    }
    if(!len){
        sub->length = 0;
        sub->ch = null;
    }else {
        sub->ch = (char *)malloc(len * sizeof(char));
        if(!sub->ch){
            printf("SubString_H ERROR!\n");
            exit(OVERFLOW);
        }
        sub->length = len;
        for (int i = 0; i < len; i++) {
            sub->ch[i] = s.ch[pos + i - 1];
        }
    }
    return SUCCESS;
}
void InitHString(HString s){
    s.length = 0;
    s.ch = null;
}
int Index_H(HString ss, HString tt, int pos){
    if(pos + tt.length - 1 > ss.length || pos < 1){
        printf("Index_H ERROR!\n");
        return ERROR;
    }
    int m, n, i;
    HString sub;
    n = StrLength_H(ss);
    m = StrLength_H(tt);
    i = pos;
    while(i <= n - m + 1){
        SubString_H(&sub, ss, i, m);
        if(StrCompare_H(tt, sub) == 0){
            return i;
        }else{
            i++;
        }
    }
    return 0;
}
status StrInsert_H(HString *ss, int pos, HString tt){
    if(pos > ss->length + 1 || pos < 1){
        printf("StrInsert_H ERROR!\n");
        return ERROR;
    }
    if(tt.length){
        ss->ch = (char *)realloc(ss->ch, (ss->length + tt.length) * sizeof(char));
        for(int i = ss->length - 1 ; i >= pos-1 ; i-- ){
            ss->ch[i + tt.length] = ss->ch[i];
        }
        for(int i = 0 ; i < tt.length ; i++){
            ss->ch[pos + i - 1] = tt.ch[i];
        }
        ss->length = ss->length + tt.length;
    }
    return OK;
}
status StrDelete_H(HString *ss, int pos, int len){
    if(pos < 1 || pos + len - 1> ss->length || len < 0){
        printf("StrDelete_H ERROR!\n");
        return ERROR;
    }
    for(int i = 0 ; i <= ss->length - pos + 1 - len ; i++){
        ss->ch[i + pos - 1] = ss->ch[i + pos + len - 1];
    }
    ss->length -= len;
    ss->ch = (char *)realloc(ss->ch, ss->length * sizeof(char));
    return SUCCESS;
}
status Replace_H(HString *ss, HString tt, HString vv){
    if(ss->length < tt.length || StrEmpty_H(tt)){
        printf("Replace_H ERROR!\n");
        return ERROR;
    }
    int i = Index_H(*ss, tt, 1);
    while(i != 0){
        StrDelete_H(ss, i, StrLength_H(tt));
        StrInsert_H(ss, i, vv);
        i += StrLength_H(vv);
        i = Index_H(*ss, tt, i);
    }
    return SUCCESS;
}
#endif //CPROJECTS_C_HSTRING_H
