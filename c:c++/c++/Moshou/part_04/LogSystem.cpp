//
//  LogSystem.cpp
//  part_04
//
//  Created by Macmini1 on 16/4/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "LogSystem.hpp"
#include "CommonData.hpp"
#include <iostream>

using namespace std;

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

void LogSystem::print_soldier_character(Soldier &soldier)
{
    switch (soldier.type) {
        case Type_Of_Soldier_Wolf:
        case Type_Of_Soldier_Ninja:
        case Type_Of_Soldier_IceMan:
            break;
        case Type_Of_Soldier_Dragon:
        case Type_Of_Soldier_Lion:
            cout << soldier.get_soldier_character_info() << endl;
            break;
        default:
            break;
    }
}

void LogSystem::print_product_soldier_info(Headquarter &headquarter, Soldier &soldier)
{
/*    char *time = time_to_str(headquarter.get_time());
    int soldier_type = soldier.type;
    cout << time << " " << headquarter.headquart_name << " " << soldier.name << " " << headquarter.count_of_soldier << " born with strength " << Headquarter::inital_HP[soldier_type] << "," << headquarter.count_of_each_soldier[soldier_type] << " " << soldier.name<< " in " << headquarter.headquart_name << " headquarter"<<endl;*/
    cout << CommonData::get_event_time() << " " << headquarter.headquart_name << " " << soldier.name << " " << headquarter.count_of_each_soldier[soldier.type] << " born" << endl;
}