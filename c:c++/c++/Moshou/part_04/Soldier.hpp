//
//  Soldier.hpp
//  part_04
//
//  Created by Macmini1 on 16/3/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef Soldier_hpp
#define Soldier_hpp

#include "StructDeclare.h"
#include <string>
using namespace::std;

class Soldier {
public:

    int HP;
    int number;         //每种士兵种类编号
    int total_number;   //在所有士兵中的编号
    Type_Of_Soldier type;
    string name;

    //士兵类型数量
    int count_of_character;
    
    Type_Of_Character *character_types;

    
    Soldier(Type_Of_Soldier soldier_type){
        this->name = soldier_type_name[soldier_type];
        this->type = soldier_type;
    }
    
    virtual string &get_soldier_character_info() = 0;

};

#endif /* Soldier_hpp */
