//
//  PlusPlusOperation.cpp
//  Operation
//
//  Created by 阴天翔 on 16/4/9.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "PlusPlusOperation.hpp"

CDemo & CDemo::operator++()
{
    var_int++;
    return *this;
}

int CDemo::operator++(int i)
{
    var_int++;
    return var_int-1;
}

ostream & operator<<(ostream & os,CDemo & demo)
{
    os << demo.var_int;
    return os;
}