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
    char a[101],b[101];
    char o;
    
    cin.getline(a, 101);
    scanf("%c",&o);
    cin.getline(b, 101);
    
    BigInteger int_01(a);
    BigInteger int_02(b);
    return 0;
}
