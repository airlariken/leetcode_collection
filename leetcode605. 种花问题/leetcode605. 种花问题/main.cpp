//
//  main.cpp
//  leetcode605. 种花问题
//
//  Created by 陈梓玮 on 2021/4/5.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> flowerbed;
    flowerbed.push_back(1);
    flowerbed.push_back(0);
    flowerbed.push_back(0);
    flowerbed.push_back(0);
    flowerbed.push_back(0);
    flowerbed.push_back(1);
    int n = 1;
    bool preflag = 0, nextflag = 0;
    for(int i = 0 ; i < flowerbed.size() ; ++i){
        if( i != flowerbed.size()-1 && flowerbed[i+1] == 1)
            nextflag = 1;
        else
            nextflag = 0;
        if(flowerbed[i] == 0 && preflag == 0 && nextflag == 0){
            preflag = 1;
            flowerbed[i] = 1;
            n--;
        }
        if(flowerbed[i] == 1)
            preflag = 1;
        
        else
            preflag = 0;
    }
    return n>0?0:1;
}
