//
//  FightController.hpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef FightController_hpp
#define FightController_hpp


#include "HeadQuarter.hpp"
#include "City.hpp"
#include "CommonData.hpp"

class FightController {
public:
    FightController(int inital_energy,int city_count,int arrow_attacks,int decress_loyal,int stop_minutes,int *soldier_hp,int *soldier_attacks){
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
    
    void init_instance(){
        redQuarter = new Headquarter("red",CommonData::inital_total_energy);
        blueQuarter = new Headquarter("blue",CommonData::inital_total_energy);
        city_count = CommonData::count_of_city;
        cities = new City[city_count]();
    };
    
    void start_fight(){
        
    }
    
    Headquarter *redQuarter;
    Headquarter *blueQuarter;
    
    City *cities;
    int city_count;
};

#endif /* FightController_hpp */
