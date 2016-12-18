//
//  main.cpp
//  tree
//
//  Created by aa on 16/11/16.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

void initTree(BinaryTree<string> &tree)
{
    /*
     *       +
     *      / \
     *     *   3
     *    / \
     *   1   -
     *      / \
     *     5   4
     *
     *
     *
     *
     *
     *
     */
    string plus = "+";
    string minus = "-";
    string multi = "*";
    string divide = "/";

    BinaryTreeNode<string> *nodePlus = new BinaryTreeNode<string>();
    nodePlus->setNodeValue(plus);

    
    BinaryTreeNode<string> *nodeMulti = new BinaryTreeNode<string>();;
    nodeMulti->setNodeValue(multi);
    
    BinaryTreeNode<string> *nodeMinus = new BinaryTreeNode<string>();;
    nodeMinus->setNodeValue(minus);
    
    
    BinaryTreeNode<string> *nodeOne = new BinaryTreeNode<string>();;
    string one = "1";
    nodeOne->setNodeValue(one);
    
    BinaryTreeNode<string> *nodeTwo = new BinaryTreeNode<string>();;
    string two = "2";
    nodeTwo->setNodeValue(two);
    
    BinaryTreeNode<string> *nodeThree = new BinaryTreeNode<string>();;
    string three = "3";
    nodeThree->setNodeValue(three);
    
    BinaryTreeNode<string> *nodeFour = new BinaryTreeNode<string>();;
    string four = "4";
    nodeFour->setNodeValue(four);
    
    BinaryTreeNode<string> *nodeFive = new BinaryTreeNode<string>();;
    string five = "5";
    nodeFive->setNodeValue(five);
    
    
    
    tree.setRootNode(nodePlus);
    
    nodePlus->setLeftChild(*nodeMulti);
    nodePlus->setRightChild(*nodeThree);
    
    nodeMulti->setLeftChild(*nodeOne);
    nodeMulti->setRightChild(*nodeMinus);
    
    nodeMinus->setLeftChild(*nodeFive);
    nodeMinus->setRightChild(*nodeFour);
    
    nodePlus->setRightChild(*nodeThree);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    BinaryTree<string> tree;
    initTree(tree);
    tree.recursionSearch();
    tree.stackSearch();
    tree.levelOrderSearch();
    return 0;
}


