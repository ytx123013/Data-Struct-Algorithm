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
#include "Weapon.hpp"
using namespace std;
class IceMan : public Soldier {
public:
    Type_Of_Weapon weapon_type;
    Weapon  *weapon;
    IceMan(Weapon *weapon,int number) : Soldier(Type_Of_Soldier_IceMan,number){
        this -> weapon = weapon;
        this -> count_of_weapon = 1;
    }

    string &get_soldier_character_info();
};

class Lion : public Soldier {
public:
    int loyal;
    Lion(int loyal,int number) : Soldier(Type_Of_Soldier_Lion,number){
        this->loyal = loyal;
    }
    string &get_soldier_character_info();
};

class Wolf : public Soldier {
public:
    Wolf(int number) : Soldier(Type_Of_Soldier_Wolf,number){
    }
    Weapon *weapon;
    string &get_soldier_character_info();
};

class Ninja : public Soldier {
public:
    Type_Of_Weapon weapon_type1;
    Type_Of_Weapon weapon_type2;
    Weapon *weapon1;
    Weapon *weapon2;
    Ninja(Weapon *weapon1,Weapon *weapon2,int number) : Soldier(Type_Of_Soldier_Ninja,number){
        this->weapon1 = weapon1;
        this->weapon2 = weapon2;
        this->count_of_weapon = 2;
    };

    string &get_soldier_character_info();
};

class Dragon : public Soldier {
public:
    Type_Of_Weapon weapon_type;
    float moral;
    Weapon *weapon;
    Dragon(Weapon *weapon,float moral,int number):Soldier(Type_Of_Soldier_Dragon,number){
        this->moral = moral;
        this->weapon = weapon;
        this->count_of_weapon = 1;
    }
    void cheer(){
    
    }
    string &get_soldier_character_info();
};


#endif /* SubSoldier_hpp */
