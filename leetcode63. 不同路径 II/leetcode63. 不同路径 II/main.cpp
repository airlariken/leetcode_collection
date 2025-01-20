//
//  main.cpp
//  leetcode63. 不同路径 II
//
//  Created by 陈梓玮 on 2022/8/5.
//https://leetcode.cn/problems/unique-paths-ii/

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>>dp(obstacleGrid.size(), vector<int>(obstacleGrid.begin()->size(),0));
    for(int i = 0; i < obstacleGrid.size(); ++i){
        if(obstacleGrid[i][0] == 0)
            dp[i][0] = 1;
        else    break;
    }
        
    for(int i = 0; i < obstacleGrid.begin()->size(); ++i){
        if(obstacleGrid[0][i] == 0)
            dp[0][i] = 1;
        else    break;
    }

    for(int i = 1; i < obstacleGrid.size(); ++i){
        for(int j = 1; j < obstacleGrid.begin()->size();++j){
            if(obstacleGrid[i][j] == 0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    // return *(--(--dp.end())->end());
    return dp[dp.size()-1][dp.begin()->size()-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
