//
//  Soldier.hpp
//  part_04
//
//  Created by Macmini1 on 16/3/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef Soldier_hpp
#define Soldier_hpp

#include "StructDeclare.h"

class Soldier {
public:
    int HP;
    int number;         //编号
    Type_Of_Soldier type;
    char name[10];
    
    Soldier(Type_Of_Soldier type,char *name1,int HP,int number){
        int i = 0;
        while (*(name1 + i) != '\0') {
            this->name[i] = *(name1 + i);
            i++;
        }
        this->name[i] = '\0';
        
        this->type = type;
        this->HP = HP;
        this->number = number;
    }
    
    char *get_soldier_info();
};

#endif /* Soldier_hpp */
