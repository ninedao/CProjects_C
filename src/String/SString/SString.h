//
// Created by POPO LIU on 2019-10-05.
//

#ifndef CPROJECTS_C_SSTRING_H
#define CPROJECTS_C_SSTRING_H

#include "../../common/common.h"
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN + 1];
void print(SString ss){
    for(int i = 1 ; i <= ss[0] ; i++){
        printf("%c" , ss[i]);
    }
    printf("\n");
}
status StrAssign_Sq(SString ss, const char *chars){
    unsigned int len = strlen(chars);
    if(len > MAXSTRLEN){
        printf("StrAssign_Sq ERROR!\n");
        exit(OVERFLOW);
    }else{
        ss[0] = len;
        for(unsigned int i = 0 ; i <= len ; i++){
            ss[i + 1] = chars[i];
        }
        printf("StrAssign_Sq SUCCESS!\n");
        return SUCCESS;
    }
}
status StrCopy_Sq(SString a, const SString b){
    for(int i = 0 ; i <= b[0] ; i++){
        a[i] = b[i];
    }
    printf("StrCopy_Sq SUCCESS!\n");
    return SUCCESS;
}
status StrEmpty_Sq(const SString ss){
    if(ss[0] == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}
int StrCompare_Sq(SString a, SString b){
    if(a[0] == b[0]){
        for(int i = 0; i <= a[0] ; i++){
            if(a[i] != b[i]){
                return a[i] - b[i];
            }
        }
    }
    return a[0] - b[0];
}
int StrLength(SString ss){
    return ss[0];
}
status ClearString(SString ss){
    ss[0] = 0;
    return TRUE;
}
status Concat_Sq(SString c, SString a, const SString b){
    StrCopy_Sq(c,a);
    if(a[0] + b[0] < MAXSTRLEN){
        for(int i = 1 ; i <= b[0] ; i++){
            c[i + a[0]] = b[i];
        }
        c[0] = a[0] + b[0];
        return TRUE;
    }else{
        for(int i = 1 ; a[0] + i <= MAXSTRLEN ; i++){
            c[i + a[0]] = b[i];
        }
        c[0] = MAXSTRLEN;
        return FALSE;
    }
}
status SubString_Sq(SString sub, const SString s, int pos, int len){
    if(pos + len - 1 > s[0] || pos < 1 || len == 0){
        printf("SubString ERROR!\n");
        exit(OVERFLOW);
    }
    for(int i = 1 ; i <= len ; i++){
        sub[i] = s[pos + i - 1];
    }
    sub[0] = len;
    return SUCCESS;
}
int Index_Sq(SString ss, SString tt, int pos){
    if(tt[0] + pos - 1 > ss[0] || pos < 1 || !ss[0] || !tt[0]){
        printf("Index ERROR!\n");
        exit(OVERFLOW);
    }
    int i = pos;
    int j = 1;
    while(i <= ss[0] && j <= tt[0]){
        if(ss[i] == tt[j]){
            i++;
            j++;
        }else{
            i = i - (j - 1) + 1;
            j = 1;
        }
    }
    if(j > tt[0] && tt[0]){
        return i - tt[0];
    }else{
        return 0;
    }
}
status StrInsert_Sq(SString ss, int pos, SString tt){
    if(tt[0] + ss[0] > MAXSTRLEN || pos < 1 || pos > ss[0] + 1){
        printf("StrInsert_Sq ERROR!\n");
        exit(OVERFLOW);
    }
    for(int i = ss[0] ; i >= pos ; i--){
        ss[i + tt[0]] = ss[i];
    }
    for(int j = 0 ; j < tt[0] ; j++){
        ss[pos + j] = tt[j + 1];
    }
    ss[0] += tt[0];
    return SUCCESS;
}
status StrDelete_Sq(SString ss, int pos, int len){
    if(pos < 1 || len < 0 || pos + len - 1 > ss[0]){
        printf("StrDelete_Sq ERROR!\n");
        exit(OVERFLOW);
    }
    for(int i = 0 ; i <= ss[0] - pos - len ; i++){
        ss[pos + i] = ss[pos + len + i];
    }
    ss[0] -= len;
    return SUCCESS;
}
status Replace_Sq(SString ss, SString tt, SString vv){
    if(tt[0] > ss[0] || !ss[0] || !tt[0] || !vv[0]){
        printf("Replace_Sq ERROR!\n");
        exit(OVERFLOW);
    }
    int i = Index_Sq(ss, tt, 1);
    while(ss[0] - tt[0] + vv[0] <= MAXSTRLEN && i){
        StrDelete_Sq(ss, i, tt[0]);
        StrInsert_Sq(ss, i, vv);
        i += vv[0];
        i = Index_Sq(ss, tt, i);
    }
    if(i == 0){
        return SUCCESS;
    }else{
        printf("Replace_Sq ERROR!\n");
        exit(OVERFLOW);
    }
}
#endif //CPROJECTS_C_SSTRING_H
