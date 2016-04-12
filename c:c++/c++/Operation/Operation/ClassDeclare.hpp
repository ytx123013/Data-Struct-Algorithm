//
//  ClassDeclare.hpp
//  Operation
//
//  Created by 阴天翔 on 16/4/4.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef ClassDeclare_hpp
#define ClassDeclare_hpp

#include <iostream>
using namespace std;

struct CLocation {
    double longtitude;
    double latitude;
};

#include <stdio.h>
class Location {
public:
    Location(double lon,double lai){
        longtitude = lon;
        latitude = lai;
    }
    Location(){
        
    }
    Location* operator=(struct CLocation loc){
        printf("operator =\n");
        printf("long : %f, la : %f\n",loc.longtitude,loc.latitude);
        Location *loc1 = new Location(loc.longtitude,loc.latitude);
        return loc1;
    }
    double longtitude;
    double latitude;
};

Location operator+(Location &a,Location &b);

class Complex {
private:
    double real;
    double image;
public:
    Complex(){
    }
    Complex(double r,double i){
        real = r;
        image = i;
    }
    Complex operator+(Complex &c){
        return Complex(real+c.real,image+c.image);
    }
    //声明友元函数 使其可以访问私有成员变量
    friend void print_complex(Complex &c);
    friend ostream & operator<<(ostream & o,Complex & c);
    friend istream & operator>>(istream & i,Complex & c);
};

void print_complex(Complex &c);
ostream & operator<<(ostream & o,Complex & c);
istream & operator>>(istream & i,Complex & c);

#endif /* ClassDeclare_hpp */
