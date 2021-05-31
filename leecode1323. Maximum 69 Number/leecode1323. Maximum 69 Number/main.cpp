//
//  main.cpp
//  leecode1323. Maximum 69 Number
//
//  Created by 陈梓玮 on 2020/1/31.
//  Copyright © 2020 陈梓玮. All rights reserved.
//Given a positive integer num consisting only of digits 6 and 9.
//Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
//Exaple：Input: num = 9669
//Output: 9969
//Explanation:
//Changing the first digit results in 6669.
//Changing the second digit results in 9969.
//Changing the third digit results in 9699.
//Changing the fourth digit results in 9666.
//The maximum number is 9969.
#include <iostream>
using namespace std;
int  num = 9669;
int main(int argc, const char * argv[])
{
    std::ios::sync_with_stdio(false);

    int a[5];
    for (int i = 3 ; i>=0; --i)
    {
        a[i] = num%10;
        num=num/10;
    }
    for (int i = 0; i<4; ++i)
    {
        if(a[i]==6)
        {
            a[i]=9;
            break;
        }
    }
    int sum = 0;
    for (int i = 0 ; i<4; ++i)
        sum = sum * 10 + a[i];
    cout<<sum;

}
