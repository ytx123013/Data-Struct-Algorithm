//
//  MutableArray.hpp
//  Operation
//
//  Created by Macmini1 on 16/4/7.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef MutableArray_hpp
#define MutableArray_hpp

#include <stdio.h>
//可变整型数组
class CArray {
private:
    //数组长度
    int size;
    //数组指针
    int *array_ptr;
    
public:
    CArray();
    CArray(int size);
    CArray(CArray &array);
    ~CArray();
    //往数组最后面添加数据
    void append(int i);
    
    //取数组长度
    int get_length();
    
    CArray & operator=(const CArray &);
    int & operator[](int index);
    
};

#endif /* MutableArray_hpp */
