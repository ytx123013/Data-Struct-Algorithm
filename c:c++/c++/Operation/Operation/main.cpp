//
//  main.cpp
//  Operation
//
//  Created by 阴天翔 on 16/4/4.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include <iostream>
#include "ClassDeclare.hpp"
//#include "MutableArray.cpp"
#include <stdio.h>
#include "OSStreamOperation.hpp"
#include "PlusPlusOperation.hpp"

using namespace std;

void print_location(Location &location);


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Location m(11,22);
    Location *n = new Location(33,44);
    printf("%p %p\n",&m,n);
    
    //运算符重载
    Location a(11,22),b(33,44);
    Location c = a + b;
    
    print_location(c);
    Location *d;

    struct CLocation loc;
    loc.latitude = 111;
    loc.longtitude = 222;
//    print_location(*d);
    
    
    Complex x(1,2),y(3,4);
    Complex z = x + y;
    print_complex(z);
    
    
//  可变长整型数组
    //++ operation
    CDemo cdemo(4);
    cout << (int)cdemo << endl;
    cout << cdemo++ << " " << ++cdemo << endl;
    
    //osstream
    CStudent s;
    s.age = 5;
    cout << s << " years old\n";

    
    Complex com;
    int count;
    cin >> com >> count;
    cout << com << ", " << count;
    
    
    
    
    return 0;
}

void print_location(Location &location){
    cout << "long : " << location.longtitude << " lai: " << location.latitude<<endl;
}