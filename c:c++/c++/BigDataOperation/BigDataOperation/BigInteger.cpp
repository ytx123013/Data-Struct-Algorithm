//
//  BigInteger.cpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "BigInteger.hpp"

//获取倒序字符串
static char* reverse_string(string * str){
    char re[101];
    string s((*str).rbegin(),(*str).rend());
    unsigned long len = s.length();
    for (int i = 0; i < len; i++) {
        re[i] = s[i];
    }
    return re;
    
}

BigInteger::BigInteger(char * c){
    str = new string(c);
}

BigInteger::~BigInteger(){
    delete str;
}

string * BigInteger::operator+(BigInteger other_interger)
{
    string *reverse = reverse_string(this->str);
    
    delete reverse;
}