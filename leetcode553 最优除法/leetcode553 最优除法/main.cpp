//
//  main.cpp
//  leetcode553 最优除法
//
//  Created by 陈梓玮 on 2022/2/27.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 核心思想：这个方法参考评论区耍赖，由于所给数据>=1
// 因此 第二个数开始往后的数全部加一起加个括号一定能让数据最小，也即让第一个数除以后面整个整体最大
string optimalDivision(vector<int>& nums) {
    if (nums.size() == 0)
        return string();
    string res = "";
    res += to_string(nums[0]);
    res += "/";
    res += "(";
    for(int i = 1; i < nums.size(); ++i){

        res += to_string(nums[i]);
        res += "/";
    }
    res = res.substr(res.length()-1);
    
    res += ")";
    return res;
}
// DP方法  正规方法
struct Node {
    double maxVal, minVal;
    string minStr, maxStr;
    Node() {
        this->minVal = 10000.0;
        this->maxVal = 0.0;
    }
};
string optimalDivision_2(vector<int>& nums) {
    int n = nums.size();
    vector<vector<Node>> dp(n, vector<Node>(n));

    for (int i = 0; i < n; i++) {       //初始化DP数组
        dp[i][i].minVal = nums[i];
        dp[i][i].maxVal = nums[i];
        dp[i][i].minStr = to_string(nums[i]);
        dp[i][i].maxStr = to_string(nums[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {   // [j, j+i],  i >= 1
            for (int k = j; k < j + i; k++) {
                //遍历从 j -> j+i 的所有元素的，找到最大的 maxVal / minVal即为DP[j][j+i].maxVal的结果
                if (dp[j][j + i].maxVal < dp[j][k].maxVal / dp[k + 1][j + i].minVal) {
                    dp[j][j + i].maxVal = dp[j][k].maxVal / dp[k + 1][j + i].minVal;
                    if (k + 1 == j + i) {
                        dp[j][j + i].maxStr = dp[j][k].maxStr + "/" + dp[k + 1][j + i].minStr;
                    } else {
                        dp[j][j + i].maxStr = dp[j][k].maxStr + "/(" + dp[k + 1][j + i].minStr + ")";
                    }
                }
                // 同上更新DP[j][j+i].minVal的结果
                if (dp[j][j + i].minVal > dp[j][k].minVal / dp[k + 1][j + i].maxVal) {
                    dp[j][j + i].minVal = dp[j][k].minVal / dp[k + 1][j + i].maxVal;
                    if (k + 1 == j + i) {
                        dp[j][j + i].minStr = dp[j][k].minStr + "/" + dp[k + 1][j + i].maxStr;
                    } else {
                        dp[j][j + i].minStr = dp[j][k].minStr + "/(" + dp[k + 1][j + i].maxStr + ")";
                    }
                }
            }
        }
    }
    return dp[0][n - 1].maxStr;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
