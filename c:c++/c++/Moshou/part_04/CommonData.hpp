//
//  CommonData.hpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef CommonData_hpp
#define CommonData_hpp

#include <string>
using namespace std;

class CommonData {
public:
    static int arrow_attacks;
    static int count_of_city;
    static int inital_total_energy;
    static int lion_decress_loyal;
    static int stop_minutes;
    static int soldier_inital_hp[5];
    static int soldier_attack[5];
    static int event_index;
    
    static int hour;
    static int min[10];
    static string get_event_time();
    
    static void next_event();
};

#endif /* CommonData_hpp */
