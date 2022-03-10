//
//  main.cpp
//  leetcode258 各位相加
//
//  Created by 陈梓玮 on 2022/3/3.
//

#include <iostream>
#include <vector>
using namespace std;
int addDigits(int num) {
    int res = num;
    int t_num = num;
    while(t_num >= 10){
        res = 0;
        while (t_num != 0) {
            int t = t_num % 10;
            t_num /= 10;
            res += t;
        }
        t_num = res;

    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    cout<<addDigits(10)<<endl;
    return 0;
}
