//
//  main.cpp
//  leetcode300. 最长递增子序列
//
//  Created by 陈梓玮 on 2022/8/5.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 动规
     int lengthOfLIS(vector<int>& nums) {
         int res = 1;
         vector<int> dp(nums.size(), 1);
         for(int i = 1; i < nums.size(); ++i) {
             for(int j = i - 1; j >= 0 ; --j) {
                 if(nums[j]<nums[i]){
                     dp[i] = max(dp[i], dp[j]+1);
                     res = max(res, dp[i]);
                 }
             }
         }
         return res;
     }

int main(int argc, const char * argv[]) {
  
}
