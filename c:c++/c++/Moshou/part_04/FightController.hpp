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
    
    Headquarter *redQuarter;
    Headquarter *blueQuarter;
    
    City *cities;
    int city_count;
    
    FightController(int inital_energy,int city_count,int arrow_attacks,int decress_loyal,int stop_minutes,int *soldier_hp,int *soldier_attacks);
    
    void init_instance(){
        redQuarter = new Headquarter("red",CommonData::inital_total_energy);
        blueQuarter = new Headquarter("blue",CommonData::inital_total_energy);
        city_count = CommonData::count_of_city;
        cities = new City[city_count]();
    };
    
    void start_fight(){
        void product_soldier();
        void lion_escape();
        void soldier_move();
        void city_product_energy();
        void soldier_take_city_energy();
        void arrow_shot();
        void bomb_boom();
        void soldier_fight();
        void headquarter_report_energy();
        void soldier_report_weapon_info();
    }
    
    
    void product_soldier();
    void lion_escape();
    void soldier_move();
    void city_product_energy();
    void soldier_take_city_energy();
    void arrow_shot();
    void bomb_boom();
    void soldier_fight();
    void headquarter_report_energy();
    void soldier_report_weapon_info();
    
    
};

#endif /* FightController_hpp */
