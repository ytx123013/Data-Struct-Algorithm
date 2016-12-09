//
//  BinaryTreeNode.cpp
//  tree
//
//  Created by aa on 16/12/7.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "BinaryTreeNode.hpp"

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T ele){
    info = ele;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T &ele,BinaryTreeNode<T> &left,BinaryTreeNode<T> &right) {
    info = ele;
    leftNode = &left;
    rightNode = &right;
}
