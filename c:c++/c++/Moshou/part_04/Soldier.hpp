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
    char name[10];
    
    Type_Of_Character *character_types;
    
    //character 属性
    int count_of_weapon;
    Type_Of_Weapon weapon_type1;
    Type_Of_Weapon weapon_type2;
    double moral;
    int loyal;
    
    Soldier(Type_Of_Soldier type,char *name1,int HP,int number,int total_number){
        int i = 0;
        while (*(name1 + i) != '\0') {
            this->name[i] = *(name1 + i);
            i++;
        }
        this->name[i] = '\0';
        
        this->type = type;
        this->HP = HP;
        this->number = number;
        this->total_number = total_number;
        
        if (type == Type_Of_Soldier_Dragon) {
            character_types = new Type_Of_Character[2];
            character_types[0] = Type_Of_Character_Moral;
            character_types[1] = Type_Of_Character_One_Weapon;
            weapon_type1 = static_cast<Type_Of_Weapon>(total_number%3);
        }
        if (type == Type_Of_Soldier_Ninja) {
            character_types = new Type_Of_Character[1];
            character_types[0] = Type_Of_Character_Two_Weapon;
            count_of_weapon = 2;
            weapon_type1 = static_cast<Type_Of_Weapon>(total_number%3);
            weapon_type2 = static_cast<Type_Of_Weapon>((total_number+1)%3);
        }
        if (type == Type_Of_Soldier_IceMan) {
            character_types = new Type_Of_Character[1];
            character_types[0] = Type_Of_Character_One_Weapon;
            count_of_weapon = 1;
            weapon_type1 = static_cast<Type_Of_Weapon>(total_number%3);
        }
        if (type == Type_Of_Soldier_Lion) {
            character_types = new Type_Of_Character[1];
            character_types[0] = Type_Of_Character_Loyal;
        }
        if (type == Type_Of_Soldier_Wolf) {
            character_types = new Type_Of_Character[1];
            character_types[0] = Type_Of_Character_None;
        }
    }
    
    string &get_soldier_character_info();
};

#endif /* Soldier_hpp */
