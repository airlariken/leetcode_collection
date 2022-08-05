//
//  main.cpp
//  leetcode62. 不同路径
//
//  Created by 陈梓玮 on 2022/8/1.
//https://leetcode.cn/problems/unique-paths/
//这道题太简单了。。1分钟秒了

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 1; i < m; ++i)
        dp[i][0] = 1;
    for(int j = 1; j < n; ++j)
        dp[0][j] = 1;

    for(int i = 1; i < m; ++i){
        for(int j = 1 ; j < n; ++j){
            dp[i][j] = dp[i][j-1]+dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
