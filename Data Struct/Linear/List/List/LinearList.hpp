//
//  LinearList.hpp
//  List
//
//  Created by 阴天翔 on 16/4/5.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef LinearList_hpp
#define LinearList_hpp
#include "VirturlList.h"

template <class T>
class Node {
public:
    T data;
    Node *next;
};


template <class T>
class HeadNode {
public:
    Node<T> first_node;
};

template <class T>
class LinearList : public List<T>{
public:
    LinearList<T>(){
        head_node = new HeadNode<T>();
        
    }
private:
    HeadNode<T> *head_node;
    
};

#endif /* LinearList_hpp */
