//
//  BigInteger.hpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef BigInteger_hpp
#define BigInteger_hpp
#include <iostream>
#include <string>
using namespace std;
class BigInteger {
private:
    string *str;
public:
    BigInteger(){};
    BigInteger(char *);
    BigInteger(string);
    ~BigInteger();
    
    string * get_data_string(){
        return str;
    }
    
    string * operator+(BigInteger &other_interger);
    string * operator-(BigInteger &other_interger);
    string * operator*(BigInteger &other_interger);
    string * operator/(BigInteger &other_interger);
};

#endif /* BigInteger_hpp */
