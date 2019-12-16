//
// Created by POPO LIU on 2019-10-07.
//

#include "HString.h"
int main(){
    char *a = "Miss Zhang is little pigpig", *b = "i";
    HString s , p , c;
    StrAssign_H(&s, a);
    StrAssign_H(&c, b);
    StrCopy_H(&p, s);
//    Concat_H(&c, s, p);
//    print(c);
//    SubString_H(&c, s, 5 , 6);
//    print(c);
//    print(s);
//    print(p);
//    printf("%d\n",Index_H(s, c, 1));
//    StrInsert_H(&s, 1, c);
//    print(s);
//    StrDelete_H(&s, 1, 6);
//    print(s);
    //SubString_H(&c, s, 2 , 2);
    print(s);
    print(c);
    print(p);
    Replace_H(&s, c, p);
    print(s);
}