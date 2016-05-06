//
//  main.cpp
//  VirtualFuction
//
//  Created by Macmini1 on 16/4/19.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include <iostream>
#include "SubClassDeclaration.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    SubPerson *sub = new SubPerson();
    Person *per = sub;
    
    per->virtual_print();
    per->normal_print();
    
    return 0;
}
