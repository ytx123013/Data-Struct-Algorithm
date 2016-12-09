//
//  BinaryTree.hpp
//  tree
//
//  Created by aa on 16/12/7.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include "BinaryTreeNode.hpp"
#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;         //根节点
    
public:
    //构造函数
    BinaryTree(){};
    ~BinaryTree(){};
    
    //树的根节点
    void setRootNode(BinaryTreeNode<T> &rootNode){
        root = &rootNode;
    };
    BinaryTreeNode<T> &getRootNode(){
        return *root;
    };
    
    
    //树属性判断
    bool isEmpty(){                     //是否为空树
        if (root->isLeaf()) {
            return true;
        }else{
            return false;
        }
    }
    
    //深搜遍历  中序遍历
    void recursionSearch(){             //递归搜索
        preorderRecursion(root);
    }
    void preorderRecursion(BinaryTreeNode<T> *node){
        if (node != nullptr) {
            preorderRecursion(node->getLeftChild());
            cout << node->getNodeValue() << endl;
            preorderRecursion(node->getRightChild());
        }
        

    }
};

#endif /* BinaryTree_hpp */
