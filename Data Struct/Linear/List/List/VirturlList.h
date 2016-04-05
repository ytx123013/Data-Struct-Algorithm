//
//  VirturlList.h
//  List
//
//  Created by 阴天翔 on 16/4/5.
//  Copyright © 2016年 ytx. All rights reserved.
//

#ifndef VirturlList_h
#define VirturlList_h

template <class T>
class List {
public:
    //返回list长度
    int get_len_of_list(){
        return len_of_list;
    };
    //在末尾加入一个元素
    void append(T *element)=0;
    //在某一位置添加一个元素
    void insert_element_at_index(T *element,int index)=0;
    //删除某一位置的元素
    void remove_element_at_index(int index)=0;
private:
    int len_of_list;
    
    
};
#endif /* VirturlList_h */
