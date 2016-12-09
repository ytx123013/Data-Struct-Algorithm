//
//  File.cpp
//  FileOperation
//
//  Created by aa on 16/5/18.
//  Copyright © 2016年 aa. All rights reserved.
//

#include "File.hpp"
using namespace std;
#include <iostream>
#include <string>

void openFile(){
    ofstream fout;
    fout.open("test.txt",ios::out);
    if (!fout) {
        cout << "File open error" << endl;
    }
}

void writeFile()
{
    ofstream fout;
    fout.open("test.txt",ios::app);
    if (!fout) {
        cout << "File open error" << endl;
    }
    long location = fout.tellp();       //取得写指针位置
    location = 0;
    fout.seekp(location);               //移动到第location个字节处
    fout.seekp(location,ios::cur);      //从当前位置数location
    fout.seekp(location,ios::end);      //从尾部数location
    fout.seekp(location,ios::beg);      //从头数location
    string aa = "heheda";
    fout.write(aa.c_str(), sizeof(strlen(aa.c_str()))-2);
    fout.close();
}
void readFile(){
    ifstream fin("test.txt",ios::in);
    long location = fin.tellg();       //取得读指针位置
    location = 10;
    fin.seekg(location);               //移动到第10个字节处
    fin.seekg(location,ios::cur);      //从当前位置数location
    fin.seekg(location,ios::end);
    fin.seekg(0,ios::beg);      //从头数0

    char s;
    while (fin.read( &s, sizeof(char))) {
        cout << s << endl;
    }
    fin.close();
}

void rwFile(){
    fstream iofile("rwtest.txt",ios::in|ios::app);
    if (!iofile) {
        cout << "error" << endl;
    }
    iofile.seekp(0, ios::beg);
    iofile.write("Mike", strlen("Mike"));
    iofile.seekp(0, ios::beg);
    char s;
    while (iofile.read(&s, sizeof(char))) {
        cout << s << endl;
    }
    iofile.close();
}