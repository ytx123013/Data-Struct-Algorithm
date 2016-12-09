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
    int      move_count = 0;
    IceMan(Weapon *weapon,int number) : Soldier(Type_Of_Soldier_IceMan,number){
        this -> weapon = weapon;
        this -> count_of_weapon = 1;
    }
    void iceman_move(){
        if (move_count == 1) {
            move_count = 0;
            this->attacks += 20;
            iceman_hp_decrease();
        }else{
            move_count++;
        }
    }
    void iceman_hp_decrease(){
        this->HP -= 9;
        if (this->HP <= 0) {
            this->HP = 1;
        }
    }
    string &get_soldier_character_info();
};

class Lion : public Soldier {
public:
    int loyal;
    Lion(int loyal,int number) : Soldier(Type_Of_Soldier_Lion,number){
        this->loyal = loyal;
    }
    void loyal_decrease(){
        this->loyal -= CommonData::lion_decress_loyal;
    }
    int is_lion_escape(){
        if (loyal <= 0) {
            return 1;
        }else{
            return 0;
        }
    }
    void loyal_escape(){
    }
    string &get_soldier_character_info();
};

class Wolf : public Soldier {
public:
    Wolf(int number) : Soldier(Type_Of_Soldier_Wolf,number){
    }
    Weapon *weapon;
    int is_have_weapon = 0;
    int is_should_obtain_weapon(){
        if (is_have_weapon == 0) {
            return 1;
        }else{
            return 0;
        }
    }
    void obtain_weapon(Weapon *weapon){
        this->weapon = weapon;
        this->is_have_weapon = 1;
    }
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
    double moral;
    Weapon *weapon;
    Dragon(Weapon *weapon,double moral,int number):Soldier(Type_Of_Soldier_Dragon,number){
        this->moral = moral;
        this->weapon = weapon;
        this->count_of_weapon = 1;
    }
    void cheer(){
    
    }
    int is_cheer(){
        if (moral > 0.8) {
            return 1;
        }else{
            return 0;
        }
    }
    
    void moral_increase(){
        moral = moral + 0.2;
    }
    void moral_decrease(){
        moral = moral - 0.2;
    }
    string &get_soldier_character_info();
};


#endif /* SubSoldier_hpp */
