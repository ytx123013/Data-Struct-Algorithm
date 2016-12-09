//
//  main.cpp
//  Template
//
//  Created by aa on 16/5/19.
//  Copyright © 2016年 aa. All rights reserved.
//

#include <iostream>
#include "FuncitonTemplate.hpp"
#include "ClassTemplate.hpp"
#include <string>
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = 1,b =2;
    swap(&a, &b);
    std::cout << a << " " << b << std::endl;
    
    double x = 1.0, y = 2.0;
    swap(&x, &y);
    std::cout << x << " " << y << std::endl;
    
    int m = 1;
    double n = 2;
    print(m, n);
    
    Pair<std::string, int> student("Tom",19);
    std::cout << student.key << " " << student.value << std::endl;
    
    return 0;
}
