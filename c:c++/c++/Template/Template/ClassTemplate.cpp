//
//  ClassTemplate.cpp
//  Template
//
//  Created by aa on 16/5/20.
//  Copyright © 2016年 aa. All rights reserved.
//

#include "ClassTemplate.hpp"

template <class T1,class T2>
bool Pair<T1,T2>::operator<(const Pair<T1, T2> &p) {
    return key < p.key;
}