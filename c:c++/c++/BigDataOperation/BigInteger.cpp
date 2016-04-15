//
//  BigInteger.cpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/12.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "BigInteger.hpp"

//获取倒序字符串
static char* reverse_string(string * str){
    char *re = new char[101];
//    string s((*str).rbegin(),(*str).rend());
    string s;
    unsigned long len = s.length();
    int i;
    for (i = 0; i < len; i++) {
        re[i] = s[i];
    }
    re[i] = '\0';
    return re;
}

static int get_max_integer_index(string &str1, string &str2){
    unsigned long len_1 = str1.length();
    unsigned long len_2 = str2.length();
    if (len_1 != len_2) {
        if (len_1 > len_2) {
            return 1;
        }else{
            return 2;
        }
    }
    if (str1 > str2) {
        return 1;
    }else if(str1 < str2){
        return 2;
    }else{
        return 1;
    }
}

static int convert_char_to_int(char c){
    return c - '0';
}

static char convert_int_to_char(int i){
    return i + '0';
}

static string * string_append_zero(string *str,int count){
    string *new_str = &(*str).append(count, '0');
    return new_str;
}

BigInteger::BigInteger(char * c){
    str = new string(c);
}

BigInteger::BigInteger(string s){
    char* c;
    unsigned long len = s.length();
    c =new char[len+1];
    for (int i = 0; i < len; i++) {
        c[i] = s[i];
    }
    c[len] = '\0';
//    strcpy(c,s.c_str());
    str = new string(c);
}

BigInteger::~BigInteger(){
    delete str;
}

string * BigInteger::operator+(BigInteger &other_interger)
{
    char *big_data_01 = reverse_string(this->str);
    char *big_data_02 = reverse_string(other_interger.get_data_string());
    
    char *plus_data = new char[10002];
    
    int index = 0;
    //是否进位
    bool is_sub = false;
    bool is_str1_finished = false;
    bool is_str2_finished = false;
    while (1) {
        int tmp_01,tmp_02;
        
        if (!is_str1_finished && big_data_01[index] != '\0') {
            tmp_01 = convert_char_to_int(big_data_01[index]);
        }else{
            is_str1_finished = true;
            tmp_01 = 0;
        }
        
        if (!is_str2_finished && big_data_02[index] != '\0') {
            tmp_02 = convert_char_to_int(big_data_02[index]);
        }else{
            is_str2_finished = true;
            tmp_02 = 0;
        }
        

        int tmp_sub = tmp_01 + tmp_02;
        if (is_sub) {
            tmp_sub++;
        }
        if (tmp_sub > 9) {
            is_sub = true;
        }else{
            is_sub = false;
        }
        plus_data[index] = convert_int_to_char(tmp_sub % 10);
        
        if (is_str1_finished && is_str2_finished) {
            if (plus_data[index] == 0 + '0') {
                plus_data[index] = '\0';
            }else{
                plus_data[index+1] = '\0';
            }
            break;
        }
        index++;
    }
    
    delete big_data_01;
    delete big_data_02;
    
    string *sub_reverse_str = new string(plus_data);
    char *sub_str_ = reverse_string(sub_reverse_str);
    delete sub_reverse_str;
    string *sub_str = new string(sub_str_);
    delete sub_str_;
    cout << "subn ; " << (*sub_str) <<endl;
    return sub_str;
}

string * BigInteger::operator-(BigInteger &other_interger){
    int max_index = get_max_integer_index(*(this->str),*other_interger.get_data_string());
    bool is_nagetive = false;
    char *big_data_01;
    char *big_data_02;
    if (max_index == 1) {
        big_data_01 = reverse_string(this->str);
        big_data_02 = reverse_string(other_interger.get_data_string());
    }else{
        is_nagetive = true;
        big_data_01 = reverse_string(other_interger.get_data_string());
        big_data_02 = reverse_string(this->str);
    }
    
    char *minus_data = new char[103];
    int index = 0;
    //是否借位
    bool is_minus = false;
    bool is_str1_finished = false;
    bool is_str2_finished = false;
    while (true) {
        int tmp_01,tmp_02;
        
        if (!is_str1_finished && big_data_01[index] != '\0') {
            tmp_01 = convert_char_to_int(big_data_01[index]);
        }else{
            is_str1_finished = true;
            tmp_01 = 0;
        }
        
        if (!is_str2_finished && big_data_02[index] != '\0') {
            tmp_02 = convert_char_to_int(big_data_02[index]);
        }else{
            is_str2_finished = true;
            tmp_02 = 0;
        }
        
        int tmp_minus = tmp_01 - tmp_02;
        if (is_minus) {
            tmp_minus--;
        }
        if (tmp_minus < 0) {
            is_minus = true;
            tmp_minus = 10 + tmp_minus;
        }else{
            is_minus = false;
        }
        minus_data[index] = convert_int_to_char(tmp_minus);
        
        if (is_str1_finished && is_str2_finished) {
            minus_data[index] = '\0';
            while (true) {
                index--;
                if (minus_data[index] == 0 + '0') {
                    minus_data[index] = '\0';
                    if (index == 0) {
                        minus_data[0] = '0';
                        minus_data[1] = '\0';

                        break;
                    }
                }else{
                    index++;
                    break;
                }
            }
            break;
        }
        index++;
    }
    
    if (is_nagetive && index != 0) {
        minus_data[index] = '-';
        minus_data[index + 1] = '\0';
    }
    
    delete big_data_01;
    delete big_data_02;
    

    string *min_reverse_str = new string(minus_data);
    char *min_str_ = reverse_string(min_reverse_str);
    delete min_reverse_str;
    string *min_str = new string(min_str_);
    delete min_str_;
    return min_str;
}



string * BigInteger::operator*(BigInteger &other_interger){
/*    char one[2] = "1";
    BigInteger integer_1(one);
    BigInteger *integer_multi = nullptr;
    BigInteger *integer_plus = nullptr;
    string *multi_str = nullptr;
    string *plus_str = nullptr;
    unsigned long len = (*other_interger.get_data_string()).length();
    for (int i = 0; i < len; i++) {
        int count = convert_char_to_int((*other_interger.get_data_string())[i]);
        while (count--) {
            cout << "count : " << count << endl;
            if (integer_plus == nullptr) {
                plus_str = (*this) + (*this);
                cout << "plus_str : "<<*plus_str <<endl;
                integer_plus = new BigInteger(*plus_str);
            }else{
                delete plus_str;
                plus_str = *integer_plus + (*this);
                delete integer_plus;
                integer_plus = new BigInteger(*plus_str);
            }
            cout << *plus_str <<endl;
        }
        string *tmp_str = string_append_zero(plus_str, (int)(len - i - 1));
        cout << "tmp_str : " << *tmp_str << endl;
//        delete plus_str;
//        delete integer_plus;
        plus_str = nullptr;
        integer_plus = nullptr;
        if (integer_multi == nullptr) {
            integer_multi = new BigInteger(*tmp_str);
            delete tmp_str;
        }else{
            BigInteger tmp_BigInteger(*tmp_str);
            delete tmp_str;
            multi_str = *integer_multi + tmp_BigInteger;
            delete integer_multi;
            integer_multi = new BigInteger(*multi_str);
            delete multi_str;
        }
    }
/*    while (true) {
        unsigned long len = (*other_interger.get_data_string()).length();
        for (int i = 0; i < len; i++) {
            int count = convert_char_to_int((*other_interger.get_data_string())[len]);
            while (1) {
                plus_str = (*this) + (*this);
                integer_multi = new BigInteger(*plus_str);
            }
        }
        
        
        if (integer_multi == NULL) {
            plus_str = (*this) + (*this);
            integer_multi = new BigInteger(*plus_str);
        }else{
            delete plus_str;
            plus_str = *integer_multi + (*this);
            delete integer_multi;
            integer_multi = new BigInteger(*plus_str);
        }
        
        if (integer_minus == NULL) {
            minus_str = other_interger - integer_1;
            integer_minus = new BigInteger(*minus_str);
        }else{
            delete minus_str;
            minus_str = *integer_minus - integer_1;
            delete integer_minus;
            integer_minus = new BigInteger(*minus_str);
        }
        if ((*minus_str)[0] == '1' && (*minus_str)[1] == '\0') {
            delete minus_str;
            delete integer_minus;
            break;
        }
        
    }*/
//    delete integer_multi;
//    return integer_multi->get_data_string();
    return NULL;
}

string * BigInteger::operator/(BigInteger &other_interger){
    int max_index = get_max_integer_index(*(this->str), *other_interger.str);
    if (max_index == 2) {
        return new string("0");
    }
    char one[2] = "1";
    BigInteger integer_1(one);
    BigInteger *integer_div = nullptr;
    BigInteger *integer_sub = nullptr;
    string *div_str = nullptr;
    string *sub_str = nullptr;
    while (true) {
        if (integer_div == nullptr) {
            div_str = *this - other_interger;
            integer_div = new BigInteger(*div_str);
        }else{
            delete div_str;
            div_str = *integer_div - other_interger;
            delete integer_div;
            integer_div = new BigInteger(*div_str);
        }
        
        
        if (integer_sub == nullptr) {
            sub_str = new string("1");
            integer_sub = new BigInteger(*sub_str);
        }else{
            delete sub_str;
            sub_str = *integer_sub + integer_1;
            delete integer_sub;
            integer_sub = new BigInteger(*sub_str);
        }
        if ((*div_str)[0] == '0' && (*div_str)[1] == '\0') {
            delete div_str;
            delete integer_div;
            break;
        }
        if ((*div_str)[0] == '-') {
            delete div_str;
            delete integer_div;
            sub_str = *integer_sub - integer_1;
            break;
        }
    }
    delete integer_sub;
    return sub_str;
}

