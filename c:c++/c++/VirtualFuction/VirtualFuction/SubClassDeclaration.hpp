//
//  SubClassDeclaration.hpp
//  VirtualFuction
//
//  Created by Macmini1 on 16/4/19.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef SubClassDeclaration_hpp
#define SubClassDeclaration_hpp
#include <iostream>
using namespace std;

class Person {
public:
    virtual void virtual_print(){
        cout << "Person virtual" << endl;
    }
    void normal_print(){
        cout << "Person normal" << endl;
    }
};

class SubPerson : public Person {
public:
    virtual void virtual_print(){
        cout << "SubPerson virtual" << endl;
    }
    void normal_print(){
        cout << "SubPerson normal" << endl;
    }
};

#endif /* SubClassDeclaration_hpp */
