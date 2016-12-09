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
#include "CommonData.hpp"
using namespace::std;

class Soldier {
public:

    int HP;                 //生命值
    int number;             //每种士兵种类编号
    int total_number;       //在所有士兵中的编号
    int attacks;            //攻击力
    int count_of_weapon;    //士兵拥有的武器数量
    Type_Of_Soldier type;
    int city_index;
    string name;
    
    Soldier(Type_Of_Soldier soldier_type, int number){
        this->number = number;
        this->count_of_weapon = 0;
        this->name = soldier_type_name[soldier_type];
        this->attacks = CommonData::soldier_attack[soldier_type];
        this->type = soldier_type;
    }
    
    virtual void soldier_move(){
        city_index++;
    }
    virtual string &get_soldier_character_info() = 0;

};

#endif /* Soldier_hpp */
