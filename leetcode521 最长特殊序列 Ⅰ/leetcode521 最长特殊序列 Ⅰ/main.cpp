//
//  main.cpp
//  leetcode521 最长特殊序列 Ⅰ
//
//  Created by 陈梓玮 on 2022/3/5.
//

#include <iostream>
#include <string>
using namespace std;

int findLUSlength(string a, string b) {
    if ( a.length() > b.length())
        return a.length();
    else if (a.length() < b.length())
        return b.length();
    else {
        if(strcmp(a.c_str(), b.c_str()) != 0)
            return a.length();
        return -1;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
