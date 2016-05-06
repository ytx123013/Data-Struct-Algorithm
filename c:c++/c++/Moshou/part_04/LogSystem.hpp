//
//  LogSystem.hpp
//  part_04
//
//  Created by Macmini1 on 16/4/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef LogSystem_hpp
#define LogSystem_hpp
#include "SubSoldier.hpp"
#include "HeadQuarter.hpp"

class LogSystem {
public:
    static void print_soldier_character(Soldier &soldier);
    static void print_product_soldier_info(Headquarter &headquarter,Soldier &soldier);
};

#endif /* LogSystem_hpp */
