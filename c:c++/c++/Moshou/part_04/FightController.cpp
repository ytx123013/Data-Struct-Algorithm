//
//  FightController.cpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "FightController.hpp"


FightController::FightController(int inital_energy,int city_count,int arrow_attacks,int decress_loyal,int stop_minutes,int *soldier_hp,int *soldier_attacks){
    CommonData::inital_total_energy = inital_energy;
    CommonData::arrow_attacks = arrow_attacks;
    CommonData::count_of_city = city_count;
    CommonData::lion_decress_loyal = decress_loyal;
    CommonData::stop_minutes = stop_minutes;
    CommonData::soldier_inital_hp[Type_Of_Soldier_Dragon] = soldier_hp[0];
    CommonData::soldier_inital_hp[Type_Of_Soldier_Ninja] = soldier_hp[1];
    CommonData::soldier_inital_hp[Type_Of_Soldier_IceMan] = soldier_hp[2];
    CommonData::soldier_inital_hp[Type_Of_Soldier_Lion] = soldier_hp[3];
    CommonData::soldier_inital_hp[Type_Of_Soldier_Wolf] = soldier_hp[4];
    CommonData::soldier_attack[Type_Of_Soldier_Dragon] = soldier_attacks[0];
    CommonData::soldier_attack[Type_Of_Soldier_Ninja] = soldier_attacks[1];
    CommonData::soldier_attack[Type_Of_Soldier_IceMan] = soldier_attacks[2];
    CommonData::soldier_attack[Type_Of_Soldier_Lion] = soldier_attacks[3];
    CommonData::soldier_attack[Type_Of_Soldier_Wolf] = soldier_attacks[4];
};

void FightController::product_soldier(){
    redQuarter->product_soldier();
    blueQuarter->product_soldier();
}

void FightController::lion_escape(){
    
}

void FightController::soldier_move(){
    
}

void FightController::city_product_energy(){
    
}

void FightController::soldier_take_city_energy(){
    
}

void FightController::arrow_shot(){
    
}

void FightController::bomb_boom(){
    
}

void FightController::soldier_fight(){
    
}

void FightController::headquarter_report_energy(){
    
}

void FightController::soldier_report_weapon_info(){
    
}
