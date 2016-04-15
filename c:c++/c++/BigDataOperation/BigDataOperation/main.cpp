//
//  main.cpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include <iostream>
#include "BigInteger.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char a[101],b[101],o[2];

    
    cin.getline(a, 101);
    cin.getline(o, 2);
    cin.getline(b, 101);
    BigInteger big_int_01(a);
    BigInteger big_int_02(b);
    
    BigInteger result;
    if (o[0] == '+') {
        result = big_int_01 + big_int_02;
    }
    if (o[0] == '-') {
        result = big_int_01 - big_int_02;
    }
    if (o[0] == '*') {
        result = big_int_01 * big_int_02;
    }
    if (o[0] == '/') {
        result = big_int_01 / big_int_02;
    }
    cout << result << endl;
//    string *str = new string("Hello world");
//    cout << reverse_string(str) << endl;
    return 0;
}
