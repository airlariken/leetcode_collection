//
//  main.cpp
//  leetcode1049 最后一块石头的重量 II
//
//  Created by 陈梓玮 on 2022/8/13.
//

#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
int lastStoneWeightII(vector<int>& stones) {
    int t = 0;
    for(auto it:stones) t+=it;
    float target = (float)t/2;

    vector<vector<int>>dp(stones.size()+1,vector<int>(t,0));
    cout<<target;
    float limited = fabs(stones[0] - target);
    for(int i = 1; i < dp.size(); ++i){
        dp[i][stones[i-1]] = 1;
        for(int j = 0; j < dp[0].size(); ++j){
            if(dp[i-1][j] == 1){
                dp[i][j] = 1;
                if(j + stones[i-1] < target+limited ){
                    dp[i][j+stones[i-1]]=1;
                    limited = min(fabs(j+stones[i-1]-target), limited);
                }
            }
        }
    }
    return limited*2;
}

int main(int argc, const char * argv[]) {
    vector<int> v{31,26,33,21,40};
    cout<<lastStoneWeightII(v)<<endl;
    return 0;
}
