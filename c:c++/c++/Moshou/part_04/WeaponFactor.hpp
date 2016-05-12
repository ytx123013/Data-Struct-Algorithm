//
//  WeaponFactor.hpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef WeaponFactor_hpp
#define WeaponFactor_hpp

#include "CommonData.hpp"
#include "StructDeclare.h"
#include "Weapon.hpp"
#include "SubSoldier.hpp"

class WeaponFactor {
public:
    static Weapon * product_weapon_of_type(Type_Of_Weapon weapon_type,Type_Of_Soldier soldier_type){
        Weapon *weapon = NULL;
        switch (weapon_type) {
            case Type_Of_Weapon_Sword:
                weapon = new Sword(CommonData::soldier_attack[soldier_type]/5);
                break;
            case Type_Of_Weapon_Bomb:
                weapon = new Bomb();
                break;
            case Type_Of_Weapon_Arrow:
                weapon = new Arrow(CommonData::arrow_attacks);
                break;
            default:
                break;
        }
        return weapon;
    }
};

#endif /* WeaponFactor_hpp */
