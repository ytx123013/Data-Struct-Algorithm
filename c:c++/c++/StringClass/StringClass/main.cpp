//
//  main.cpp
//  StringClass
//
//  Created by aa on 16/5/23.
//  Copyright © 2016年 aa. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string s1 = "Hehe";
    cout << s1 <<endl;
    string *s2 = new  string(3,'x');
    cout << *s2 <<endl;
    cout << (*s2).length() << endl;
    string c1;
    c1 = 'c';
    cout << c1 << endl;
    
    string s3("aaabbb"),s4;
    s4.assign(s3,1,3);
    cout << s4 <<endl;
    
    s3[1] = 'c';
    cout << s3 << endl;
    
    s4.append(s3,1,2);
    cout << s4 << endl;
    
    string s5;
    s5 = s4.substr(1,2);
    cout << s5 << endl;
    
    int location = (int)s4.find_first_of("abc");
    cout << location << endl;
    
    s4.replace(1, 2, "hahahahaha");
    cout << s4 << endl;
    
    string s6 = "abcdefg";
    s4.insert(0, s6,3,2);
    cout << s4 <<endl;
    return 0;
}
