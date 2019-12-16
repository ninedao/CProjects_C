//
// Created by POPO LIU on 2019-10-05.
//

#include "SString.h"
int main(){
    SString ss, bb, cc;
    char *c = "ababcababcababcababcababcababcababcababcabcacbab";
    char *b = "abcac";
    StrAssign_Sq(ss, c);
    StrAssign_Sq(cc, b);
//    StrCopy_Sq(bb, ss);
    //Concat_Sq(cc, ss, bb);
    //SubString_Sq(bb, ss,2,1);
    print(ss);
    //Replace_Sq(ss, bb, cc);
    //print(ss);
    int next[StrLength(cc) + 1], nextval[StrLength(cc) + 1];
    print(cc);
    get_next(cc, next);
    get_nextval(cc, nextval);
    for(int i = 1; i <= StrLength(cc); i++){
        printf("%d", next[i]);
    }
    printf("\n");
    for(int i = 1; i <= StrLength(cc); i++){
        printf("%d", nextval[i]);
    }
    printf("\n");
    printf("%d\n", Index_KMP(ss, cc, 1, next));
    printf("%d\n", Index_KMP(ss, cc, 1, nextval));
    printf("%d\n", Index_Sq(ss, cc, 1));
}