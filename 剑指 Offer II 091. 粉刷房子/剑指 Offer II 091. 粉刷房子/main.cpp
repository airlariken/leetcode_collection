//
//  main.cpp
//  剑指 Offer II 091. 粉刷房子
//
//  Created by 陈梓玮 on 2022/7/31.
//动态规划 https://leetcode.cn/problems/JEj789/

//核心思想：n的最优解分为一定是第n个房子三种颜色（记为0,1,2）中dp数组最小的值（dp数组存储内容即前n个房子在第n个取0,1，2颜色的时候最优值）
//转移方程：第n房子取蓝色的时候（0），前一个房子必须是红色或者绿色（1or2）（必须满足约束）
//那么dp[n][0]最优值即为dp[n-1][1]+costs[n][0]和dp[n-1][2]+cost[n][0]的小值
#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<vector<int>>& costs) {
    vector<vector<int>>dp(costs.size()+1, vector<int>(3, 0));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = costs[0][0];
    dp[1][1] = costs[0][1];
    dp[1][2] = costs[0][2];
    for(int i = 0; i < costs.size(); ++i){
        dp[i+1][0] = min(costs[i][0]+dp[i][1],  costs[i][0]+dp[i][2]);
        dp[i+1][1] = min(costs[i][1]+dp[i][0],  costs[i][1]+dp[i][2]);
        dp[i+1][2] = min(costs[i][2]+dp[i][0],  costs[i][2]+dp[i][1]);
    }
    int n = costs.size();
    return min(min(dp[n][0], dp[n][1]), dp[n][2]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
