//
//  HeadQuarter.cpp
//  part_04
//
//  Created by Macmini1 on 16/3/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "HeadQuarter.hpp"

#include <iostream>
#include "LogSystem.hpp"
#include "SoldierFactor.hpp"

using namespace std;

int Headquarter::inital_HP[5] = {0,0,0,0,0};
char Headquarter::soldier_type[5][10] = {"iceman","lion","wolf","ninja","dragon"};

static char* time_to_str(int time1){
    char *time = (char *)malloc(4 * sizeof(char));
    time[3] = '\0';
    time[2] = time1%10+48;
    time1 = time1/10;
    time[1] = time1%10+48;
    time1 = time1/10;
    time[0] = time1%10+48;
    return time;
}

Headquarter::Headquarter(string name,int total_en){
    if (name == "red"){
        product_sequence[0] = (int)Type_Of_Soldier_IceMan;
        product_sequence[1] = (int)Type_Of_Soldier_Lion;
        product_sequence[2] = (int)Type_Of_Soldier_Wolf;
        product_sequence[3] = (int)Type_Of_Soldier_Ninja;
        product_sequence[4] = (int)Type_Of_Soldier_Dragon;
    }else{
        product_sequence[0] = (int)Type_Of_Soldier_Lion;
        product_sequence[1] = (int)Type_Of_Soldier_Dragon;
        product_sequence[2] = (int)Type_Of_Soldier_Ninja;
        product_sequence[3] = (int)Type_Of_Soldier_IceMan;
        product_sequence[4] = (int)Type_Of_Soldier_Wolf;
    }
    
    headquart_name = name;
    total_energy = total_en;
    time = 0;
    cur_product_index = 0;
    product_soldier_type = (Type_Of_Soldier)this->product_sequence[cur_product_index];
    stop_product = 0;
    count_of_soldier = 0;
}

//计算生产士兵后剩余的HP
void Headquarter::product_soldier_cost_HP_of_type(Type_Of_Soldier soldier)
{
    this->total_energy -= Headquarter::inital_HP[soldier];
}

void Headquarter::product_soldier_of_type(Type_Of_Soldier type){
    this->count_of_each_soldier[type]++;
    this->count_of_soldier++;
    
    //计算生产后所剩的HP
    this->product_soldier_cost_HP_of_type(type);
    

    Soldier *soldier = SoldierFactor::shared_factor().product_soldier_of_type(*this, type);
    
    LogSystem::print_product_soldier_info(*this, *soldier);
    LogSystem::print_soldier_character(*soldier);

    this->time++;
    
}

void Headquarter::product_soldier(){
//    if (stop_product == 1) {
//        return;
//    }
//    Type_Of_Soldier nextType = next_product_type();
    //product_soldier_type = next_product_type();
    if (has_enough_energy_of_soldier_type(product_soldier_type)) {
        product_soldier_of_type(product_soldier_type);
        product_soldier_type = next_product_type();
    }else{
        
    }
}

Type_Of_Soldier Headquarter::next_product_type(){
    if (cur_product_index == 4) {
        cur_product_index = 0;
    }else{
        cur_product_index++;
    }
    return (Type_Of_Soldier)this->product_sequence[cur_product_index];
}

int Headquarter::has_enough_energy_of_soldier_type(Type_Of_Soldier type){
    if (this->total_energy < Headquarter::inital_HP[type]) {
        return 0;
    }
    return 1;
}


