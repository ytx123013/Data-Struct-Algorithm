//
//  main.cpp
//  part_04
//
//  Created by Macmini1 on 16/3/29.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include "HeadQuarter.hpp"

using namespace std;

int get_string_length(char *str){
    int len = 0;
    while(*str != '\0'){
        str++;
        len++;
    }
    return len;
}

int convert_str_to_int(char *str){
    int len = get_string_length(str);
    int sum = 0;
    for (int i = 0; i < len; ++i)
    {
        int tmp_num = *(str+i) - '0';
        sum = sum * 10 + tmp_num;
    }
    return sum;
}

static int index_of_case = 1;

int main(int argc, const char * argv[]) {
    int count_of_case = 0;
    scanf("%d",&count_of_case);
    char total_energy[1024];
    char aaa[100];
    int index_of_case = 1;
    char red_name[4] = "red";
    char blue_name[5] = "blue";
    for (int i = 0; i < 2*count_of_case; i++) {
        if (i % 2 == 0) {
            cin >> total_energy;
        }
        if (i % 2 == 1) {
            Headquarter *red = new Headquarter(red_name,convert_str_to_int(total_energy));
            Headquarter *blue = new Headquarter(blue_name,convert_str_to_int(total_energy));
            cin >> aaa;
            Headquarter::inital_HP[Type_Of_Soldier_Dragon] = convert_str_to_int(aaa);
            cin >> aaa;
            Headquarter::inital_HP[Type_Of_Soldier_Ninja] = convert_str_to_int(aaa);
            cin >> aaa;
            Headquarter::inital_HP[Type_Of_Soldier_IceMan] = convert_str_to_int(aaa);
            cin >> aaa;
            Headquarter::inital_HP[Type_Of_Soldier_Lion] = convert_str_to_int(aaa);
            cin >> aaa;
            Headquarter::inital_HP[Type_Of_Soldier_Wolf] = convert_str_to_int(aaa);


            cout << "Case:" << index_of_case << endl;
            while (1) {
                if (red->stop_product && blue->stop_product) {
                    break;
                }
                red->product_next_soldier();
                blue->product_next_soldier();
            }
            index_of_case ++;
        }
    }

    
    return 0;
}
