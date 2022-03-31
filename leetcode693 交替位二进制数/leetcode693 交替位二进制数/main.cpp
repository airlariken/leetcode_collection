//
//  main.cpp
//  leetcode693 交替位二进制数
//
//  Created by 陈梓玮 on 2022/3/28.
//

#include <iostream>
using namespace std;

bool hasAlternatingBits(int n) {
    int cur = n&1;      // 与1进行与运算，如果以1结尾则返回1
     n = n>>1;
    while(n != 0){
        if((n&1) == cur){
            return false;
        }
        else{
            cur = !cur;
        }
        n = n>>1;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 6;
    cout<<hasAlternatingBits(n)<<endl;
    return 0;
}
