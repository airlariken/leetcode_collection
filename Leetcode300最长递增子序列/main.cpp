//
// Created by 橙子味 on 2025/3/18.
// dp O(N^2)时间复杂度
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for(int i = 1; i< nums.size(); ++i){
        for(int j = 0; j < i; ++j){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[j]+1, dp[i]);
                res = max(dp[i], res);
            }
        }
    }
    return res;
}