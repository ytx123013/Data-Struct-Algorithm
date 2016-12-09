//
//  City.hpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef City_hpp
#define City_hpp

#include "StructDeclare.h"

class City {
public:
    int      num;           //编号
    int      energy;        //城市所含生命元
    Type_Of_City_Owner   owner_type;
    static int total_count;
    
    City(){
        num = ++total_count;
        owner_type = Type_Of_City_Owner_None;
    }
    
    void energy_increase(){
        energy += 10;
    }
};

#endif /* City_hpp */
