//
//  BigIntegerTool.hpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/14.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef BigIntegerTool_hpp
#define BigIntegerTool_hpp

#include <string>
#include "BigInteger.hpp"

using namespace std;

string* reverse_string(string * str);
int get_max_integer_index(string &str1, string &str2);

int convert_char_to_int(char c);
char convert_int_to_char(int i);

void string_append_zero(string *str,int count);

void bigInteger_append_zero(BigInteger *big_integer,unsigned long count);
int compare_bigInteger_and_zero(BigInteger &obj);
void remove_zero(BigInteger &big_integer);

#endif /* BigIntegerTool_hpp */
