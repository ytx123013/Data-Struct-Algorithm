//
//  OSStreamOperation.cpp
//  Operation
//
//  Created by 阴天翔 on 16/4/9.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "OSStreamOperation.hpp"

ostream & operator<<(ostream & o, CStudent &s)
{
    o << s.age;
    return o;
}