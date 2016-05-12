//
//  City.hpp
//  part_04
//
//  Created by Macmini1 on 16/5/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef City_hpp
#define City_hpp

#include <stdio.h>

class City {
public:
    int      num;           //编号
    int      energy;        //城市所含生命元
    static int total_count;
    
    City(){
        num = ++total_count;
    }
    
    void energy_increase(){
        
    }
};

#endif /* City_hpp */
