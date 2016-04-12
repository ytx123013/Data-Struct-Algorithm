//
//  ClassDeclare.cpp
//  Operation
//
//  Created by 阴天翔 on 16/4/4.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "ClassDeclare.hpp"


Location operator+(Location &a,Location &b){
    return Location(a.longtitude+b.longtitude,a.latitude+b.latitude);
}

void print_complex(Complex &c){
    cout << "real : " << c.real << " image : " << c.image <<endl;
}

ostream & operator<<(ostream & o,Complex & c)
{
    o << c.real << "+" << c.image << "i";
    return o;
}

istream & operator>>(istream & i,Complex & c)
{
    string s;
    //读入 a+bi
    i >> s;
    int pos = (int)s.find("+");
    string tmp_str = s.substr(0,pos);
    c.real = atof(tmp_str.c_str());
    tmp_str = s.substr(pos+1,s.length()-pos-2);
    c.image = atof(tmp_str.c_str());
    return i;
}