//
//  OSStreamOperation.hpp
//  Operation
//
//  Created by 阴天翔 on 16/4/9.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef OSStreamOperation_hpp
#define OSStreamOperation_hpp

#include <iostream>

using namespace std;

class CStudent {
public:
    int age;
};

//cout 为ostream类
//定义全局的<<符号重载函数
ostream & operator<<(ostream & o, CStudent &s);

#endif /* OSStreamOperation_hpp */
