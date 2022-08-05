//
//  main.cpp
//  leetcode221. 最大正方形
//
//  Created by 陈梓玮 on 2022/8/1.
//

#include <iostream>
#include <vector>
using namespace std;


// 暴力法
    //该暴力方法超时
    // bool is_valid(int i, int j, int n, vector<vector<char>>&matrix ){
    //     for(int x = i; x < i+n; ++x){
    //         for(int y = j; y < j+n; ++y){
    //             if(x >= matrix.size() || y >= matrix[0].size())
    //                 return false;
    //             if(matrix[x][y] == '0')
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
    // 参考题解的暴力法，只需检查最后一行和一列是否满足（其实包含动态规划思想，前面的无需再次检查）
    // bool is_valid(int i, int j, int n, vector<vector<char>>&matrix ){
    //     if(i+n-1>=matrix.size()|| j+n-1>= matrix[0].size()) //边界检查
    //             return false;
    //     for(int x = i; x < i+n; ++x){
    //         if(matrix[x][j+n-1] == '0')
    //             return false;
    //     }
    //     for(int y = j; y < j+n; ++y){
    //         if(matrix[i+n-1][y] == '0')
    //             return false;
    //     }
    //     return true;
    // }
    // int maximalSquare(vector<vector<char>>& matrix) {
    //     int max = 0;
    //     for(int i = 0; i < matrix.size();++i){
    //         for(int j = 0 ; j < matrix[i].size(); ++j){
    //             int t_max = 0;
    //             while(is_valid(i, j, t_max+1, matrix)){
    //                 ++t_max;
    //             }
    //             if(max<t_max)
    //                 max = t_max;
    //         }
    //     }
    //     return max*max;
    // }

    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < dp.size(); ++i) { //初始化第一行和第一列为matrix值
            dp[i][0] = matrix[i][0]-'0';
            if(dp[i][0] == 1)
                max = 1;
        }
        for(int j = 0; j < dp[0].size(); ++j){
            dp[0][j] = matrix[0][j]-'0';
            if(dp[0][j] == 1)
                max = 1;
        }
        
        for(int i = 1; i < matrix.size();++i){
            for(int j = 1 ; j < matrix[i].size(); ++j){
                if(matrix[i][j] == '1')
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                // else
                //     dp[i][j] = std::max(std::max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                if(dp[i][j]>max)
                    max = dp[i][j];
            }
        }
        return max*max;
    }

int main(int argc, const char * argv[]) {
    vector<vector<char>> v;
    v.push_back(vector<char>{'1','1'});
    v.push_back(vector<char>{'1','1'});
    cout<<maximalSquare(v)<<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
