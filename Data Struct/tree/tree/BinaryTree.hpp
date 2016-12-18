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
#include <stack>
#include <queue>
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
    void setRootNode(BinaryTreeNode<T> *rootNode){
        root = rootNode;
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
        cout << "recursion search : " ;
        inorderRecursion(root);
        cout << endl;
    }
    void inorderRecursion(BinaryTreeNode<T> *node){
        if (node != nullptr) {
            inorderRecursion(node->getLeftChild());
            node->printNode();
            inorderRecursion(node->getRightChild());
        }
    }
    
    void stackSearch(){                 //辅助栈
        cout << "stack search : " ;
        inorderStackSearch(root);
        cout << endl;
    }
    void inorderStackSearch(BinaryTreeNode<T> *node){
        static stack<BinaryTreeNode<T> *> aStack;
        BinaryTreeNode<T> *pointer = node;
        while (!aStack.empty() || pointer) {
            if (pointer) {
                aStack.push(pointer);
                pointer = pointer->getLeftChild();
            }else{
                pointer = aStack.top();
                pointer->printNode();
                aStack.pop();
                pointer = pointer->getRightChild();
            }
        }
    }
    
    //宽度遍历
    void levelOrderSearch(){
        cout << "Level order search: ";
        queue<BinaryTreeNode<T> *> aQueue;
        BinaryTreeNode<T> *pointer = root;
        while (1) {
            pointer->printNode();
            if (pointer->getLeftChild()) {
                aQueue.push(pointer->getLeftChild());
            }
            if (pointer->getRightChild()) {
                aQueue.push(pointer->getRightChild());
            }
            if (!aQueue.empty()) {
                pointer = aQueue.front();
                aQueue.pop();
            }else{
                break;
            }
        }
        cout << endl;
    }
};

#endif /* BinaryTree_hpp */
