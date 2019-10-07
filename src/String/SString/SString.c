//
// Created by POPO LIU on 2019-10-05.
//

#include "SString.h"
int main(){
    SString ss, bb, cc;
    char *c = "Miss Zhang is little pigpig";
    char *b = "Zhang";
    StrAssign_Sq(ss, c);
    StrAssign_Sq(cc, b);
//    StrCopy_Sq(bb, ss);
    //Concat_Sq(cc, ss, bb);
    SubString_Sq(bb, ss,2,1);
    print(ss);
    Replace_Sq(ss, bb, cc);
    print(ss);

}