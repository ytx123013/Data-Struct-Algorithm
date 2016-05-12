//
//  HeadQuarter.hpp
//  part_04
//
//  Created by Macmini1 on 16/3/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef HeadQuarter_hpp
#define HeadQuarter_hpp

#include <string>
#include "StructDeclare.h"
#include "Soldier.hpp"



class Headquarter {
    
public:
    static int inital_HP[5];
    static char soldier_type[5][10];
    int stop_product;
    int has_enough_energy();
    int has_enough_energy_of_soldier_type(Type_Of_Soldier type);
    Type_Of_Soldier next_product_type();
    void product_next_soldier();
    void product_soldier_of_type(Type_Of_Soldier type);
    void product_soldier_cost_HP_of_type(Type_Of_Soldier soldier);
    Headquarter(string name,int total_en);
    
    
    int get_total_count_of_soldier(){
        return count_of_soldier;
    }
    int get_total_energy(){
        return total_energy;
    }
    int get_time(){
        return time;
    }
    
    friend class LogSystem;
    friend class SoldierFactor;
private:
//    char headquart_name[10];
    string headquart_name;
    int product_sequence[5];
    int total_energy;
    int count_of_soldier;    
    int count_of_each_soldier[5] = {0,0,0,0,0};
    
    int time;
    int cur_product_index;
};



#endif /* HeadQuarter_hpp */
