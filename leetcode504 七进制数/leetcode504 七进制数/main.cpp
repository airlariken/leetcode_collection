//
//  main.cpp
//  leetcode504 七进制数
//
//  Created by 陈梓玮 on 2022/3/7.
//

#include <iostream>
#include <string>
using namespace std;

string convertToBase7(int num) {
    if(num ==0)
        return string("0");
    string res;
    bool is_positive = true;
    if(num < 0) {
        num = -1*num;
        is_positive = false;
    }
    while(num != 0){
        res += to_string(num%7);
        num /= 7;
    }
    if (is_positive == false)
        res+="-";
    reverse(res.begin(), res.end());

    return res;
}

int main(int argc, const char * argv[]) {
    
    int num = -7;
    convertToBase7(num);
    return 0;
}
