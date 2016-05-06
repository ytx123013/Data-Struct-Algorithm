//
//  SoldierFactor.hpp
//  part_04
//
//  Created by Macmini1 on 16/4/26.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef SoldierFactor_hpp
#define SoldierFactor_hpp

#include "HeadQuarter.hpp"

#include "SubSoldier.hpp"
#include "StructDeclare.h"

class SoldierFactor {
public:
    static SoldierFactor & shared_factor();
    
    //生产士兵
    Soldier * product_soldier_of_type(Headquarter &quarter, Type_Of_Soldier soldier_type);
private:
    static SoldierFactor *sharedFactor;
    SoldierFactor();
};

#endif /* SoldierFactor_hpp */
