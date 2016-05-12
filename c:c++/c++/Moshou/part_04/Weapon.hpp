//
//  Weapon.hpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include "StructDeclare.h"

class Weapon {
public:
    Type_Of_Weapon      weapon_type;
};

class Sword : public Weapon {
public:
    Sword(int inital_attacks){
        this->weapon_type = Type_Of_Weapon_Sword;
        this->attacks = inital_attacks;
    }
    int attacks;
    void attack_decrease(){
        attacks = attacks * 4 / 5;
    }
    int is_sword_destory(){
        if (attacks == 0) {
            return 1;
        }else{
            return 0;
        }
    }
};

class Bomb : public Weapon{
public:
    Bomb(){
        this->weapon_type = Type_Of_Weapon_Bomb;
    }
    
};

class Arrow : public Weapon {
public:
    Arrow(int inital_attacks){
        this->weapon_type = Type_Of_Weapon_Arrow;
    }
    int attacks;
    int count_of_rest_attack = 3;
    void count_of_attack_decrease(){
        count_of_rest_attack--;
    }
    int is_arrow_destory(){
        if (count_of_rest_attack == 0) {
            return 1;
        }else{
            return 0;
        }
    }
};


#endif /* Weapon_hpp */
