//
//  main.cpp
//  leetcode96. 不同的二叉搜索树
//
//  Created by 陈梓玮 on 2022/8/5.
//https://leetcode.cn/problems/unique-binary-search-trees/

#include <iostream>
#include <vector>
using namespace std;

//动规
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <=n; ++i) {
        for(int j = 0; j < i; ++j){
            dp[i] += dp[j]*dp[i-1-j];
        }
    }
    return dp[n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
