//
//  CommonData.cpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "CommonData.hpp"

int CommonData::arrow_attacks = 0;
int CommonData::count_of_city = 0;
int CommonData::inital_total_energy = 0;
int CommonData::lion_decress_loyal = 0;
int CommonData::stop_minutes = 0;
int CommonData::soldier_inital_hp[5] = {0,0,0,0,0};
int CommonData::soldier_attack[5] = {0,0,0,0,0};
int CommonData::event_index;

int CommonData::hour = 0;
int CommonData::min[10] = {0,5,10,20,30,35,38,40,50,55};

static char* hour_to_str(int time1){
    char *time = new char[4];// (char *)malloc(4 * sizeof(char));
    time[3] = '\0';
    time[2] = time1%10+48;
    time1 = time1/10;
    time[1] = time1%10+48;
    time1 = time1/10;
    time[0] = time1%10+48;
    return time;
}

static char* min_to_str(int time1){
    char *time = new char[3];// (char *)malloc(4 * sizeof(char));
    time[2] = '\0';
    time1 = time1/10;
    time[1] = time1%10+48;
    time1 = time1/10;
    time[0] = time1%10+48;
    return time;
}

string CommonData::get_event_time(){
    string time;
    time.append(hour_to_str(hour));
    time.append(":");
    time.append(min_to_str(min[event_index]));
    return time;
}

void CommonData::next_event()
{
    if (event_index == 9) {
        hour++;
        event_index = 0;
    }else{
        event_index++;
    }
}