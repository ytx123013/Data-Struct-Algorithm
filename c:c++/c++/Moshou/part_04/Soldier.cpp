//
//  Soldier.cpp
//  part_04
//
//  Created by Macmini1 on 16/3/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "Soldier.hpp"
#include <stdio.h>

string &get_weapon_str_of_type(Type_Of_Weapon type){
    string *weapon_str = new string;
    switch (type) {
        case Type_Of_Weapon_Arrow:
            (*weapon_str).append("arrow");
            break;
        case Type_Of_Weapon_Bomb:
            (*weapon_str).append("bomb");
            break;
        case Type_Of_Weapon_Sword:
            (*weapon_str).append("sword");
            break;
        default:
            break;
    }
    return *weapon_str;
}

string & Soldier::get_soldier_character_info()
{
    string *str = new string;
    
    switch (this->type) {
        case Type_Of_Soldier_Dragon:
            (*str).append("It has a ");
            (*str).append(get_weapon_str_of_type(weapon_type1));
            (*str).append(",and it`s morale is ");
            char str1[10];
            sprintf(str1,"%.2f",this->moral);
            (*str).append(str1);
            break;
        case Type_Of_Soldier_Ninja:
            (*str).append("It has a ");
            (*str).append(get_weapon_str_of_type(weapon_type1));
            (*str).append(" and a ");
            (*str).append(get_weapon_str_of_type(weapon_type2));
            break;
        case Type_Of_Soldier_IceMan:
            (*str).append("It has a ");
            (*str).append(get_weapon_str_of_type(weapon_type1));
            break;
        case Type_Of_Soldier_Lion:
            (*str).append("It`s loyalty is ");
            char str2[10];
            sprintf(str2,"%d",this->loyal);
            (*str).append(str2);
            break;
        default:
            break;
    }
    return *str;
}