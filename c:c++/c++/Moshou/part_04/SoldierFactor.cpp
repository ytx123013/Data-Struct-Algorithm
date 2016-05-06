//
//  SoldierFactor.cpp
//  part_04
//
//  Created by Macmini1 on 16/4/26.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "SoldierFactor.hpp"

SoldierFactor* SoldierFactor::sharedFactor = NULL;

SoldierFactor::SoldierFactor(){
    
}

SoldierFactor & SoldierFactor::shared_factor(){
    if (sharedFactor == NULL) {
        sharedFactor = new SoldierFactor();
    }
    return *sharedFactor;
}

#pragma mark - character product
Type_Of_Weapon get_weapon_type(int total_count){
    return static_cast<Type_Of_Weapon>(total_count%Type_Of_Weapon_Total_Count);
}

Type_Of_Weapon get_dragon_weapon_type(int total_soldier_count){
    return get_weapon_type(total_soldier_count);
}

Type_Of_Weapon get_Ninja_weapon1_type(int total_soldier_count){
    return get_weapon_type(total_soldier_count);
}

Type_Of_Weapon get_Ninja_weapon2_type(int total_soldier_count){
    return get_weapon_type(total_soldier_count+1);
}

Type_Of_Weapon get_IceMan_weapon_type(int total_soldier_count){
    return get_weapon_type(total_soldier_count);
}

float get_dragon_moral(int headquarter_HP,int dragon_need_HP){
    return ((double)headquarter_HP/(double)dragon_need_HP);
}

int get_Lion_loyal(int total_energy){
    return total_energy;
}


#pragma mark - 
Soldier * SoldierFactor::product_soldier_of_type(Headquarter &quarter, Type_Of_Soldier soldier_type)
{
    Soldier *product_soldier = NULL;
    int total_soldier = quarter.get_total_count_of_soldier();
    int total_energy = quarter.get_total_energy();
    switch (soldier_type) {
        case Type_Of_Soldier_Dragon:
            product_soldier = new Dragon(get_dragon_weapon_type(total_soldier),get_dragon_moral(total_energy, Headquarter::inital_HP[soldier_type]));
            break;
        
        case Type_Of_Soldier_Ninja:
            product_soldier = new Ninja(get_Ninja_weapon1_type(total_soldier),get_Ninja_weapon2_type(total_soldier));
            break;
        
        case Type_Of_Soldier_Lion:
            product_soldier = new Lion(get_Lion_loyal(total_energy));
            break;
            
        case Type_Of_Soldier_IceMan:
            product_soldier = new IceMan(get_IceMan_weapon_type(total_soldier));
            break;
            
        case Type_Of_Soldier_Wolf:
            product_soldier = new Wolf();
            break;
        default:
            break;
    }
    return product_soldier;
}