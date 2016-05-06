//
//  SubSoldier.hpp
//  part_04
//
//  Created by Macmini1 on 16/4/21.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef SubSoldier_hpp
#define SubSoldier_hpp

#include <string>
#include "StructDeclare.h"
#include "Soldier.hpp"
using namespace std;
class IceMan : public Soldier {
public:
    Type_Of_Weapon weapon_type;
    
    IceMan(Type_Of_Weapon weapon_type) : Soldier(Type_Of_Soldier_IceMan){
        this->count_of_character = 1;
        this->character_types = new Type_Of_Character[this->count_of_character];
        this->character_types[0] = Type_Of_Character_One_Weapon;
        this->weapon_type = weapon_type;
    }
    string &get_soldier_character_info();
};

class Lion : public Soldier {
public:
    int loyal;
    Lion(int loyal) : Soldier(Type_Of_Soldier_Lion){
        this->count_of_character = 1;
        this->character_types = new Type_Of_Character[this->count_of_character];
        this->character_types[0] = Type_Of_Character_Loyal;
        this->loyal = loyal;
    }
    string &get_soldier_character_info();
};

class Wolf : public Soldier {
public:
    Wolf() : Soldier(Type_Of_Soldier_Wolf){
        this->count_of_character = 1;
        this->character_types = new Type_Of_Character[this->count_of_character];
        this->character_types[0] = Type_Of_Character_None;
    }
    string &get_soldier_character_info();
};

class Ninja : public Soldier {
public:
    Type_Of_Weapon weapon_type1;
    Type_Of_Weapon weapon_type2;
    Ninja(Type_Of_Weapon weapon1,Type_Of_Weapon weapon2) : Soldier(Type_Of_Soldier_Ninja){
        this->count_of_character = 1;
        this->character_types = new Type_Of_Character[this->count_of_character];
        this->character_types[0] = Type_Of_Character_Two_Weapon;
        this->weapon_type1 = weapon1;
        this->weapon_type2 = weapon2;
    }
    string &get_soldier_character_info();
};

class Dragon : public Soldier {
public:
    Type_Of_Weapon weapon_type;
    float moral;
    
    Dragon(Type_Of_Weapon weapon1,float moral) : Soldier(Type_Of_Soldier_Dragon){
        this->count_of_character = 2;
        this->character_types = new Type_Of_Character[this->count_of_character];
        this->character_types[0] = Type_Of_Character_One_Weapon;
        this->character_types[1] = Type_Of_Character_Moral;
        
        this->weapon_type = weapon1;
        this->moral = moral;
    }
    string &get_soldier_character_info();
};


#endif /* SubSoldier_hpp */
