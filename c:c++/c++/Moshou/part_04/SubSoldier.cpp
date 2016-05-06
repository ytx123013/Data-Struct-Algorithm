//
//  SubSoldier.cpp
//  part_04
//
//  Created by Macmini1 on 16/4/21.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "SubSoldier.hpp"

static string &get_weapon_str_of_type(Type_Of_Weapon type){
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

string & IceMan::get_soldier_character_info()
{
    string *str = new string;
    (*str).append("It has a ");
    (*str).append(get_weapon_str_of_type(weapon_type));
    return *str;
}

string & Lion::get_soldier_character_info()
{
    string *str = new string;
    (*str).append("It's loyalty is ");
    char str2[10];
    sprintf(str2,"%d",this->loyal);
    (*str).append(str2);
    return *str;
}

string & Ninja::get_soldier_character_info()
{
    string *str = new string;
    (*str).append("It has a ");
    (*str).append(get_weapon_str_of_type(weapon_type1));
    (*str).append(" and a ");
    (*str).append(get_weapon_str_of_type(weapon_type2));
    return *str;
}

string & Dragon::get_soldier_character_info()
{
    string *str = new string;
    (*str).append("It has a ");
    (*str).append(get_weapon_str_of_type(weapon_type));
    (*str).append(",and it's morale is ");
    char str1[10];
    sprintf(str1,"%.2f",moral);
    (*str).append(str1);
    return *str;
}

string &Wolf::get_soldier_character_info()
{
    string *str = new string;
    return *str;
}
