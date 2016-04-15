//
//  BigInteger.hpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/14.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef BigInteger_hpp
#define BigInteger_hpp

#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class BigInteger {
private:
    string *data_string;
public:
    BigInteger(){}
    BigInteger(string &s);
    BigInteger(char *c);
    ~BigInteger();
    
    string *get_data_string(){
        return data_string;
    }
    
    BigInteger& operator+(BigInteger &other_obj);
    BigInteger& operator-(BigInteger &other_obj);
    BigInteger& operator*(BigInteger &other_obj);
    BigInteger& operator/(BigInteger &other_obj);
};

ostream & operator<<(ostream &o,BigInteger &integer);

#endif /* BigInteger_hpp */
