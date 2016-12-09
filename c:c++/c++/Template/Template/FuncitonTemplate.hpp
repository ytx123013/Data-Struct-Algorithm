//
//  FuncitonTemplate.hpp
//  Template
//
//  Created by aa on 16/5/19.
//  Copyright © 2016年 aa. All rights reserved.
//

#ifndef FuncitonTemplate_hpp
#define FuncitonTemplate_hpp
#include <iostream>

template <class T>
void swap(T *a,T *b) {
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <class T1,class T2>
void print(T1 arg1,T2 arg2) {
    std::cout << arg1 << " " << arg2 << std::endl;
}
#endif /* FuncitonTemplate_hpp */
