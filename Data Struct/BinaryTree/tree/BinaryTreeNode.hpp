//
//  BinaryTreeNode.hpp
//  tree
//
//  Created by aa on 16/12/7.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp
#include <iostream>

template <class T>
class BinaryTreeNode {
private:
    T info;                     //二叉树节点数据域
    
    BinaryTreeNode<T>   *leftNode;
    BinaryTreeNode<T>   *rightNode;
public:
    //构造函数
    BinaryTreeNode(){};
    BinaryTreeNode(T ele){     //给数据的构造函数
        info = ele;
    }
    BinaryTreeNode(T &ele,BinaryTreeNode<T> &left,BinaryTreeNode<T> &right){                        //给定数据和左右子树
        info = ele;
        leftNode = &left;
        rightNode = &right;
    }
    
    //左右子树及数据的设置
    BinaryTreeNode<T> * getLeftChild(){
        return leftNode;
    };
    
    BinaryTreeNode<T> * getRightChild(){
        return rightNode;
    };
    
    T & getNodeValue(){
        return info;
    };
    void setLeftChild(BinaryTreeNode<T> &left){
        leftNode = &left;
    };
    void setRightChild(BinaryTreeNode<T> &right){
        rightNode = &right;
    };
    void setNodeValue(T ele){
        info = ele;
    };
    
    //节点属性判断
    bool isLeaf(){              //是否是叶子节点
        if (rightNode == nullptr && leftNode == nullptr) {
            return true;
        }else{
            return false;
        }
    };
    
    //打印
    void printNode(){
        std::cout << getNodeValue();
    }
};

#endif /* BinaryTreeNode_hpp */
