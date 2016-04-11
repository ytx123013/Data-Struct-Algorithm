//
//  MutableArray.cpp
//  Operation
//
//  Created by Macmini1 on 16/4/7.
//  Copyright © 2016年 ytx. All rights reserved.
//

#include "MutableArray.hpp"
#include <string>

CArray::CArray(int size):size(size){
    if (size == 0) {
        array_ptr = NULL;
    }else{
        array_ptr = new int[size];
    }
}

CArray::CArray(CArray &array){
    if (!array.array_ptr) {
        array_ptr = NULL;
        size = 0;
        return;
    }
    array_ptr = new int[array.size];
    memcpy(array_ptr, array.array_ptr, array.size * sizeof(int));
    size = array.size;
}

CArray::~CArray(){
    if (array_ptr) {
        delete [] array_ptr;
    }
}

int & CArray::operator[](int index){
    return array_ptr[index];
}

CArray & CArray::operator=(const CArray &a){
    if (array_ptr == a.array_ptr) {
        return *this;
    }
    if (a.array_ptr == NULL) {
        if (array_ptr) {
            delete [] array_ptr;
        }
        array_ptr = NULL;
        size = 0;
        return *this;
    }
    delete [] array_ptr;
    array_ptr = new int[a.size];
    memcpy(array_ptr, a.array_ptr, a.size * sizeof(int));
    size = a.size;
    return *this;
}

void CArray::append(int i){
    if (array_ptr) {
        int *tmpPtr = new int[size+1];
        memcpy(tmpPtr, array_ptr, size * sizeof(int));
        delete [] array_ptr;
        array_ptr = tmpPtr;
    }else{
        array_ptr = new int[1];
    }
    array_ptr[size++] = i;
}
