//
//  ClassTemplate.hpp
//  Template
//
//  Created by aa on 16/5/20.
//  Copyright © 2016年 aa. All rights reserved.
//

#ifndef ClassTemplate_hpp
#define ClassTemplate_hpp

template <class T1,class T2>
class Pair {
public:
    T1 key;
    T2 value;
    Pair(T1 k,T2 v):key(k),value(v){};
    bool operator<(const Pair<T1,T2> &p);
};

#endif /* ClassTemplate_hpp */
