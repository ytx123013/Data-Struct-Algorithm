//
//  StructDeclare.h
//  part_04
//
//  Created by Macmini1 on 16/3/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef StructDeclare_h
#define StructDeclare_h
#include <string>
using namespace std;

typedef enum{
    Type_Of_Soldier_IceMan = 0,
    Type_Of_Soldier_Lion,
    Type_Of_Soldier_Wolf,
    Type_Of_Soldier_Ninja,
    Type_Of_Soldier_Dragon,
    Type_Of_Soldier_Total_Count
} Type_Of_Soldier;

typedef enum{
    Type_Of_City_Owner_Red = 0,
    Type_Of_City_Owner_Blue,
    Type_Of_City_Owner_None
}Type_Of_City_Owner;

typedef enum{
    Type_Of_Weapon_Sword = 0,
    Type_Of_Weapon_Bomb,
    Type_Of_Weapon_Arrow,
    Type_Of_Weapon_Total_Count
} Type_Of_Weapon;

typedef enum{
    Type_Of_Character_One_Weapon = 0,
    Type_Of_Character_Two_Weapon,
    Type_Of_Character_Loyal,
    Type_Of_Character_Moral,
    Type_Of_Character_None
} Type_Of_Character;

static string soldier_type_name[Type_Of_Soldier_Total_Count] = {"iceman","lion","wolf","ninja","dragon"};


#endif /* StructDeclare_h */
