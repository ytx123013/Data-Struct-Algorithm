//
//  BigInteger.cpp
//  BigDataOperation
//
//  Created by Macmini1 on 16/4/14.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "BigInteger.hpp"
#include "BigIntegerTool.hpp"

ostream & operator<<(ostream &o,BigInteger &integer)
{
    o << *integer.get_data_string();
    return o;
}

#pragma mark - constructor
BigInteger::BigInteger(char * c){
    data_string = new string(c);
}

BigInteger::BigInteger(string &s){
    char* c;
    unsigned long len = s.length();
    c =new char[len+1];
    for (int i = 0; i < len; i++) {
        c[i] = s[i];
    }
    c[len] = '\0';
    data_string = new string(c);
}

BigInteger::~BigInteger(){
    delete data_string;
}

#pragma mark - operator
BigInteger& BigInteger::operator+(BigInteger &other_obj){
    string *reverse_str1 = reverse_string(this->data_string);
    string *reverse_str2 = reverse_string(other_obj.get_data_string());
    char *integer_01 = (char *)(*reverse_str1).c_str();
    char *integer_02 = (char *)(*reverse_str2).c_str();
    
    char *data_plus = new char[10002];
    
    int index = 0;
    
    //是否进位
    bool is_sub  = false;
    bool is_data1_finished = false;
    bool is_data2_finished = false;
    while (1) {
        int tmp_01,tmp_02;
        
        if (!is_data1_finished && integer_01[index] != '\0') {
            tmp_01 = convert_char_to_int(integer_01[index]);
        }else{
            is_data1_finished = true;
            tmp_01 = 0;
        }
        
        if (!is_data2_finished && integer_02[index] != '\0') {
            tmp_02 = convert_char_to_int(integer_02[index]);
        }else{
            is_data2_finished = true;
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
        data_plus[index] = convert_int_to_char(tmp_sub % 10);
        
        if (is_data1_finished && is_data2_finished) {
            if (data_plus[index] == 0 + '0') {
                data_plus[index] = '\0';
            }else{
                data_plus[index+1] = '\0';
            }
            break;
        }
        index++;
    }
    
    string *sub_reverse_str = new string(data_plus);
    string *result_str = reverse_string(sub_reverse_str);
    BigInteger *plus_integer = new BigInteger(*result_str);
    delete reverse_str1;
    delete reverse_str2;
    delete sub_reverse_str;
    delete result_str;
    return *plus_integer;
}

BigInteger& BigInteger::operator-(BigInteger &other_obj){
    BigInteger *minus_integer = NULL;
    if (*(this->data_string) == *other_obj.get_data_string()) {
        char zero[2] = "0";
        minus_integer = new BigInteger(zero);
        return *minus_integer;
    }
    int max_index = get_max_integer_index(*(this->data_string), *other_obj.get_data_string());
    bool is_nagetive = false;
    char *integer_01;
    char *integer_02;
    string *reverse_str1;
    string *reverse_str2;
    if (max_index == 2) {
        is_nagetive = true;
        reverse_str2 = reverse_string(this->data_string);
        reverse_str1 = reverse_string(other_obj.get_data_string());
    }else{
        is_nagetive = false;
        reverse_str1 = reverse_string(this->data_string);
        reverse_str2 = reverse_string(other_obj.get_data_string());
    }
    integer_01 = (char *)(*reverse_str1).c_str();
    integer_02 = (char *)(*reverse_str2).c_str();
    
    char minus_data[103];
    int index = 0;
    bool is_minus = false;          //是否借位
    bool is_str1_finished = false;
    bool is_str2_finished = false;
    
    while (1) {
        int tmp_01,tmp_02;
        
        if (!is_str1_finished && integer_01[index] != '\0') {
            tmp_01 = convert_char_to_int(integer_01[index]);
        }else{
            is_str1_finished = true;
            tmp_01 = 0;
        }
        
        if (!is_str2_finished && integer_02[index] != '\0') {
            tmp_02 = convert_char_to_int(integer_02[index]);
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
            tmp_minus += 10;
        }else{
            is_minus = false;
        }
        minus_data[index] = convert_int_to_char(tmp_minus);
        
        if (is_str1_finished && is_str2_finished) {
            minus_data[index] = '\0';
            while (1) {
                index--;
                if (minus_data[index] == 0+'0') {
                    minus_data[index] = '\0';
                }else{
                    break;
                }
            }
            break;
        }
        index++;
    }
    
    if (is_nagetive) {
        minus_data[index+1] = '-';
        minus_data[index + 2] = '\0';
    }
    
    string *minus_reverse_str = new string(minus_data);
    string *minus_str = reverse_string(minus_reverse_str);
    minus_integer = new BigInteger(*minus_str);
    delete reverse_str1;
    delete reverse_str2;
    delete minus_reverse_str;
    delete minus_str;
    
    return *minus_integer;
}

BigInteger& BigInteger::operator*(BigInteger &other_obj){
    char one[2] = "1";
    BigInteger integer_1(one);
    BigInteger *integer_multi = NULL;

    unsigned long len = (*other_obj.get_data_string()).length();
    for (int i = 0;  i < len; i++) {
        int count = convert_char_to_int((*other_obj.get_data_string())[i]);
        BigInteger *integer_plus = NULL;
        BigInteger *integer_plus_pointer = NULL;
        BigInteger *integer_multi_pointer = NULL;
        if (count == 0){
            char zero[2] = "0";
            integer_plus = new BigInteger(zero);
        }else{
            while (count--) {
                if (integer_plus == NULL) {
                    string *plus_str = (this->get_data_string());
                    integer_plus = new BigInteger(*plus_str);
                    integer_plus_pointer = integer_plus;
                }else{
                    integer_plus = &((*this)+(*integer_plus));
                    delete integer_plus_pointer;
                    integer_plus_pointer = integer_plus;
                }
            }
            string_append_zero(integer_plus->data_string, (int)(len-i-1));
        }
        if (integer_multi == NULL) {
            string *plus_str = (integer_plus->get_data_string());
            integer_multi = new BigInteger(*plus_str);
            integer_multi_pointer = integer_multi;
        }else{
            integer_multi = &(*(integer_plus) + *(integer_multi));
            if (integer_multi_pointer != NULL) {
                delete integer_multi_pointer;
            }
            integer_multi_pointer = integer_multi;
        }
//        delete integer_plus_pointer;
//        delete integer_multi_pointer;
    }
    remove_zero(*integer_multi);
    BigInteger *result = new BigInteger(*(*integer_multi).get_data_string());
    return *result;
}

BigInteger& BigInteger::operator/(BigInteger &other_obj){
    unsigned long len_of_str1 = (*this->data_string).length();
    unsigned long len_of_str2 = (*other_obj.get_data_string()).length();
    BigInteger *div_integer = NULL;
    if (len_of_str1 < len_of_str2) {
        char zero[2] = "0";
        div_integer = new BigInteger(zero);
        return *div_integer;
    }else if ((len_of_str1 == len_of_str2) && (*(this->data_string) < *other_obj.get_data_string())){
        char zero[2] = "0";
        div_integer = new BigInteger(zero);
        return *div_integer;
    }else if((len_of_str2 == len_of_str1) && (*(this->data_string) == *other_obj.get_data_string())){
        char one[2] = "1";
        div_integer = new BigInteger(one);
        return *div_integer;
    }
    int index = 0;
    char reverse_of_result[102];
    
    char one[2] = "1";
    

    unsigned long differ_len_of_two_integer = len_of_str1 - len_of_str2;
    BigInteger *aa_integer = NULL;
    while (1) {
        BigInteger one_integer(one);
        bigInteger_append_zero(&one_integer, differ_len_of_two_integer);
        int tmp_result = 0;
        BigInteger *recu_minus_integer = NULL;
        BigInteger *tmp_minus_integer;
        while (1) {
            char tmp_chr[2];
            tmp_chr[0] = convert_int_to_char(tmp_result);
            tmp_chr[1] = '\0';
            BigInteger tmp_result_integer(tmp_chr);
            BigInteger tmp_multi_integer1 = tmp_result_integer * one_integer;
            BigInteger tmp_multi_integer = tmp_multi_integer1 * other_obj;
            if (aa_integer == NULL) {
                aa_integer = this;
            }
            tmp_minus_integer = &((*aa_integer)- tmp_multi_integer);
            int compare = compare_bigInteger_and_zero(*tmp_minus_integer);
            if (compare == 0) {
                reverse_of_result[index] = convert_int_to_char(tmp_result);
                recu_minus_integer = tmp_minus_integer;
//                delete &tmp_multi_integer;
//                delete &tmp_minus_integer;
                break;
            }else if(compare == -1){
                reverse_of_result[index] = convert_int_to_char(tmp_result - 1);
//                delete &tmp_multi_integer;
//                delete &tmp_minus_integer;
                break;
            }else{
                tmp_result++;
//                delete &tmp_multi_integer;
                recu_minus_integer = tmp_minus_integer;
//                delete &tmp_minus_integer;
            }
        }
        
        
        if ((int)differ_len_of_two_integer == 0) {
            reverse_of_result[index+1] = '\0';
//            delete recu_minus_integer;
            break;
        }else{
//            len_of_str1 = (*recu_minus_integer->get_data_string()).length();
            differ_len_of_two_integer--;
            aa_integer = recu_minus_integer;
//            delete recu_minus_integer;
            index++;
        }
        
    }
    if (reverse_of_result[0] == '0') {
        for (int i = 0; reverse_of_result[i] != '\0'; i++) {
            reverse_of_result[i] = reverse_of_result[i+1];
        }
    }
    
    
    div_integer = new BigInteger(reverse_of_result);
    return *div_integer;
    
    
    
}
