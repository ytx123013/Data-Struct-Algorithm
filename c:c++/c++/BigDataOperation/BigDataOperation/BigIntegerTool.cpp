//
//  BigIntegerTool.cpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/14.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "BigIntegerTool.hpp"

string* reverse_string(string * str){
    char re[10000];
    string s((*str).rbegin(),(*str).rend());
    unsigned long len = s.length();
    int i;
    for (i = 0; i < len; i++) {
        re[i] = s[i];
    }
    re[i] = '\0';
    string *str1 = new string(re);
    return str1;
}

int get_max_integer_index(string &str1, string &str2){
    unsigned long len_1 = str1.length();
    unsigned long len_2 = str2.length();
    if (len_1 != len_2) {
        if (len_1 > len_2) {
            return 1;
        }else{
            return 2;
        }
    }
    if (str1 > str2) {
        return 1;
    }else if(str1 < str2){
        return 2;
    }else{
        return 1;
    }
}

int convert_char_to_int(char c){
    return c - '0';
}

char convert_int_to_char(int i){
    return i + '0';
}

void string_append_zero(string *str,int count){
    (*str).append(count, '0');
}

void bigInteger_append_zero(BigInteger *big_integer,unsigned long count)
{
    string *integer_str = big_integer->get_data_string();
    string_append_zero(integer_str, (int)count);
}

int compare_bigInteger_and_zero(BigInteger &obj)
{
    int result;
    if ((*obj.get_data_string())[0] == '-' ) {
        result = -1;
    }else if((*obj.get_data_string())[0] == '0' ){
        result = 0;
    }else{
        result = 1;
    }
    return result;
    
}

void remove_zero(BigInteger &big_integer)
{
    string *str = big_integer.get_data_string();
    while (1) {
        if ((*str)[0] == '0') {
           (*str).erase(0, 1);
        }else{
            if ((*str).length() == 0) {
                (*str).append(1, '0');
            }
            break;
        }
    }
}
