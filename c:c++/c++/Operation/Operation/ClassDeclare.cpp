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