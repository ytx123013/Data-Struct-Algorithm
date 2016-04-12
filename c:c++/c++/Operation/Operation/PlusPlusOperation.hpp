//
//  PlusPlusOperation.hpp
//  Operation
//
//  Created by 阴天翔 on 16/4/9.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef PlusPlusOperation_hpp
#define PlusPlusOperation_hpp

#include <ostream>
using namespace std;

class CDemo {
private:
    int var_int;
public:
    CDemo(int i = 0):var_int(i){}
    
    CDemo & operator++();           //前置++
    int operator++(int);        //后置++
    operator int(){return var_int;} //类型强制转换运算符重载
    friend ostream & operator<<(ostream & os,CDemo & demo);
};

ostream & operator<<(ostream & os,CDemo & demo);

#endif /* PlusPlusOperation_hpp */
